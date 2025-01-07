// SPDX-License-Identifier: GPL-3.0-only
//
// Copyright (c) 2008, 2024-2025 Antonio Niño Díaz

//#include "as_lib9.h" // include our own as_lib9.h before including the one in PALib!

#include <PA9.h>

#include "cambiar_formato_nombre.h"
#include "global.h"
#include "graficos_3d/escenarios/escenarios.h"
#include "graficos_3d/funciones_texturas.h"
#include "graficos_3d/graphics3d.h"
#include "graficos_3d/objetos/3d_box.h"
#include "graficos_3d/objetos/figura_luz.h"
#include "graficos_3d/texto/letras.h"
#include "graficos_3d/texto/numeros.h"
#include "keys_control.h"
#include "menu.h"
#include "modos_de_juego/contra_cpu/contra_cpu.h"
#include "modos_de_juego/cpu_ia.h"
#include "modos_de_juego/juego.h"
#include "modos_de_juego/normal/normal.h"
#include "modos_de_juego/records.h"
#include "my_fat.h"
#include "splash.h"

// PAGfxConverter Include
#include "gfx/all_gfx.h"

//printf("\n\nRam usage: Culling %s", ( held & KEY_A) ? "none" : "back faces" );

void Tetris3DSSplashScreen(void)
{
    PA_SetBrightness(0, -31);
    PA_SetBrightness(1, -31);

    PA_ResetBgSys(); // Esto tambien desactiva la fuente personalizada
    PA_Init16bitBg(1, 3);
    PA_Load16bitBitmap(1, superior_inicio_Bitmap);
    PA_EasyBgLoad(0, 3, inferior_inicio);
    for (int i = -31; i <= 0; i++)
    {
        PA_SetBrightness(0, i);
        PA_SetBrightness(1, i);
        PA_WaitForVBL(); // To slow down the fades, we wait a frame...
        PA_WaitForVBL();
    }

    while (!(Pad.Newpress.Anykey || Stylus.Newpress))
        PA_WaitForVBL();

    // Fade down
    for (int i = 0; i < 32; i++)
    {
        PA_SetBrightness(0, -i);
        PA_SetBrightness(1, -i);
        PA_WaitForVBL(); // To slow down the fades, we wait a frame...
        PA_WaitForVBL();
    }

    PA_SetBrightness(0, 0);
    PA_SetBrightness(1, 0);

    PA_ResetBgSys();
}

int main(int argc, char** argv)
{
    defaultExceptionHandler();

    PA_Init();

    // Init AS_Lib for mp3
    PA_VBLFunctionInit(AS_SoundVBL);
    if (!AS_Init(AS_MODE_MP3 | AS_MODE_SURROUND | AS_MODE_16CH))
    {
        consoleDemoInit();
        printf("Failed to initialize ASlib");
        while (1)
            PA_WaitForVBL();
    }
    AS_SetDefaultSettings(AS_PCM_8BIT, 11025, AS_SURROUND);

    // Compo splash screen
    //Splash_Screen();

    Tetris3DSSplashScreen();

    for (int i = 0; i < 30; i++)
        PA_WaitForVBL();

    Iniciar_FAT();

    AS_SetMasterVolume(MASTER_SOUND);

    PA_WaitForVBL();
    PA_WaitForVBL();
    PA_WaitForVBL();

    MENU_ACTIVO = true;
    JUEGO_ACTIVO = false;

    // INICIO DEL JUEGO

    while (1)
    {
        if (MENU_ACTIVO)
        {
            Menu();
        }
        else if (JUEGO_ACTIVO)
        {
            switch (MODO_DE_JUEGO)
            {
                case MODO_NORMAL:
                    Modo_Normal();
                    Records();
                    break;
                case MODO_CONTRA_CPU:
                    Modo_Contra_CPU();
                    break;
            }
            glResetTextures();
            MENU_ACTIVO = true;
        }

        PA_WaitForVBL();
        PA_WaitForVBL();
        PA_WaitForVBL();
    }

    return 0;
}
