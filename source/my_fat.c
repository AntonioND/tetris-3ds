// SPDX-License-Identifier: GPL-3.0-only
//
// Copyright (c) 2008, 2024-2025 Antonio Niño Díaz

#include <PA9.h>

#include "global.h"
#include "my_fat.h"

// PAGfxConverter Include
#include "gfx/all_gfx.h"

// TODO: This file requires a lot of error checks. Everywhere.

/*

Datos que se guardan:

    typedef struct
    {
        char[10] Nombre;
        u32 Puntuacion;
        u16 Lineas;
    } __RECORD_STRUCT__;

    __RECORD_STRUCT__ Record[10];

    texture_selected;
    camera_selected;
    MASTER_SOUND;

*/

// Activa/desactiva el acceso al FAT
bool FAT_ERROR = 0;

static int Checksum(u32 datos)
{
    int checksum = 0;

    for (u8 aux_checksum = 0; aux_checksum < 32; aux_checksum++)
        checksum += (datos & (1 << aux_checksum)) >> aux_checksum;

    return checksum;
}

// + = Checksum parcial; * = Checksum completo
void Guardar_Datos(void)
{
    // wb = create/truncate & write
    FILE *CONFIG_WRITE_FILE = fopen("/Tetris_3DS/Tetris3DS_Config.dat", "wb");
    if (CONFIG_WRITE_FILE == NULL)
        return;

    fwrite(&texture_selected, 1, 1, CONFIG_WRITE_FILE);
    fwrite(&camera_selected, 1, 1, CONFIG_WRITE_FILE);
    fwrite(&MASTER_SOUND, 1, 1, CONFIG_WRITE_FILE);

    for (int i = 0; i < 10; i++)
    {
        fwrite(&Record[i].Nombre, 1, 10, CONFIG_WRITE_FILE);
        fwrite(&Record[i].Puntuacion, 4, 1, CONFIG_WRITE_FILE);
        fwrite(&Record[i].Lineas, 2, 1, CONFIG_WRITE_FILE);
    }
    fclose(CONFIG_WRITE_FILE);

    // Añadir checksum al final

    // First, read file
    FILE *CONFIG_CHECKSUM_FILE = fopen("/Tetris_3DS/Tetris3DS_Config.dat", "rb");
    if (CONFIG_CHECKSUM_FILE == NULL)
        return;

    u32 sum = 0;

    for (int i = 0; i < 163; i++)
    {
        u8 b = 0;
        fread(&b, 1, 1, CONFIG_CHECKSUM_FILE);
        sum += (u32)b;
    }
    fclose(CONFIG_CHECKSUM_FILE);

    u32 checksum = Checksum(sum);

    // Now, append checksum to it
    FILE *CONFIG_WRITE_CHECKSUM_FILE = fopen("/Tetris_3DS/Tetris3DS_Config.dat", "a");
    if (CONFIG_WRITE_CHECKSUM_FILE == NULL)
        return;

    fwrite(&checksum, 4, 1, CONFIG_WRITE_CHECKSUM_FILE);
    fclose(CONFIG_WRITE_CHECKSUM_FILE);
}

int Leer_Datos(void)
{
    FILE *CONFIG_CHECK_READ_FILE = fopen("/Tetris_3DS/Tetris3DS_Config.dat", "rb"); //rb = read
    if (CONFIG_CHECK_READ_FILE == NULL)
    {
        // Default
        texture_selected = 2;
        camera_selected = 2;
        MASTER_SOUND = 64;

        Reset_Records();

        return 2;
    }

    // Comprobar archivo
    u32 sum = 0;

    for (int i = 0; i < 163; i++)
    {
        u8 b = 0;
        fread(&b, 1, 1, CONFIG_CHECK_READ_FILE);
        sum += (u32)b;
    }

    u32 checksum = 0;

    fread(&checksum, 4, 1, CONFIG_CHECK_READ_FILE);
    fclose(CONFIG_CHECK_READ_FILE);

    if (checksum == Checksum(sum)) // Si el archivo está bien
    {
        // rb = read
        FILE *CONFIG_READ_FILE = fopen ("/Tetris_3DS/Tetris3DS_Config.dat", "rb");

        fread(&texture_selected, 1, 1, CONFIG_READ_FILE);
        fread(&camera_selected, 1, 1, CONFIG_READ_FILE);
        fread(&MASTER_SOUND, 1, 1, CONFIG_READ_FILE);

        for (int i = 0; i < 10; i++)
        {
            fread(&Record[i].Nombre, 1, 10, CONFIG_READ_FILE);
            fread(&Record[i].Puntuacion, 4, 1, CONFIG_READ_FILE);
            fread(&Record[i].Lineas, 2, 1, CONFIG_READ_FILE);
        }

        fclose(CONFIG_READ_FILE);
        return 0;
    }

    // Archivo modificado / corrupto.

    // Default
    texture_selected = 2;
    camera_selected = 2;
    MASTER_SOUND = 64;

    Reset_Records();

    return 1;
}

// Comprobar FAT, de paso hace una lectura de los datos.
void Iniciar_FAT(void)
{
    PA_InitCustomText(1, 0, custom_font); // 2º = background number

    if (Pad.Held.L && Pad.Held.R) // No iniciar FAT
    {
        FAT_ERROR = true;

        PA_OutputSimpleText(1, 0, 10, "     FAT will not be accesed.");
        PA_OutputSimpleText(1, 0, 14, "          Press START");

        // Default
        texture_selected = 2;
        camera_selected = 2;
        MASTER_SOUND = 64;

        Reset_Records();

        while (!Pad.Newpress.Start)
            PA_WaitForVBL();

        PA_OutputSimpleText(1, 0, 10, "                             ");
        PA_OutputSimpleText(1, 0, 14, "                     ");
    }
    else
    {
        if (!fatInitDefault())
        {
            FAT_ERROR = true;

            PA_OutputSimpleText(1, 0, 10, "        FAT init error.");
            PA_OutputSimpleText(1, 0, 14, "          Press START");

            while (!Pad.Newpress.Start)
                PA_WaitForVBL();

            //Default
            texture_selected = 2;
            camera_selected = 2;
            MASTER_SOUND = 64;
            Reset_Records();
        }
        else
        {
            switch (Leer_Datos())
            {
                case 0:
                    // Todo correcto
                    Guardar_Datos();
                    break;

                case 1:
                    // Archivo dañado
                    texture_selected = 2;
                    camera_selected = 2;
                    MASTER_SOUND = 64;
                    Reset_Records();

                    Guardar_Datos();
                    PA_OutputSimpleText(1, 0, 10, "       Save file damaged.");
                    PA_OutputSimpleText(1, 0, 11, "   A new one will be created.");
                    PA_OutputSimpleText(1, 0, 14, "           Press START");

                    while (!Pad.Newpress.Start)
                        PA_WaitForVBL();

                    break;

                case 2:
                    // Archivo no existe
                    texture_selected = 2;
                    camera_selected = 2;
                    MASTER_SOUND = 64;
                    Reset_Records();

                    Guardar_Datos();

                    // Verificar datos que acabamos de escribir
                    if (Leer_Datos() == 2)
                    {
                        PA_OutputSimpleText(1, 0, 10, "     Can't create save file.");
                        PA_OutputSimpleText(1, 0, 14, "          Press START");

                        while (!Pad.Newpress.Start)
                            PA_WaitForVBL();
                    }
                    else
                    {
                        PA_OutputSimpleText(1, 0, 10, "       Save file created.");
                        PA_OutputSimpleText(1, 0, 14, "          Press START");

                        while (!Pad.Newpress.Start)
                            PA_WaitForVBL();
                    }
                    break;
            }
        }
    }

    PA_OutputSimpleText(1, 0, 10, "                                ");
    PA_OutputSimpleText(1, 0, 11, "                                ");
    PA_OutputSimpleText(1, 0, 14, "                                ");

    PA_ResetBgSys(); // Esto tambien desactiva la fuente personalizada
}
