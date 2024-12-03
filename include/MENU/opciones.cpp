
#include "menu/jukebox.h"

void Reload_Opciones_Menu()
{
    PA_ResetBgSys();
    PA_Init2D();

    PA_SetBrightness(0, -31);
    PA_SetBrightness(1, -31);

    PA_WaitForVBL();
    PA_WaitForVBL();

    My_Init_3D_No_Textures();
    Iniciar_3D_Menu();

    PA_Init16bitBg(1, 3);
    PA_Load16bitBitmap(1,options_inferior_Bitmap);

    PA_LoadSpritePal(1, 0, (void *)botones_Pal);
    PA_CreateSprite(1, 0, (void *)botones_Sprite, OBJ_SIZE_16X32, 1, 0, 160, 25);
    PA_CreateSprite(1, 1, (void *)botones_Sprite, OBJ_SIZE_16X32, 1, 0, 212, 25);
    PA_CreateSprite(1, 2, (void *)botones_Sprite, OBJ_SIZE_16X32, 1, 0, 160, 60);
    PA_CreateSprite(1, 3, (void *)botones_Sprite, OBJ_SIZE_16X32, 1, 0, 212, 60);
    PA_SetSpriteAnim(1, 1, 2);
    PA_SetSpriteAnim(1, 3, 2);

    PA_LoadSpritePal(1, 1, (void *)numeros_Pal);
    PA_CreateSprite(1, 10, (void *)numeros_Sprite, OBJ_SIZE_8X16, 1, 1, 189, 31);
    PA_CreateSprite(1, 11, (void *)numeros_Sprite, OBJ_SIZE_8X16, 1, 1, 189, 66);
    PA_SetSpriteAnim(1, 10, texture_selected);
    PA_SetSpriteAnim(1, 11, camera_selected);

    //Fade up
    for (int i = -31; i < 0; i++)
    {
        PA_SetBrightness(0, i);
        PA_SetBrightness(1, i);
        PA_WaitForVBL();
    }

    PA_SetBrightness(0, 0);
    PA_SetBrightness(1, 0);
}

void End_Opciones_Menu()
{
    PA_WaitForVBL();
    PA_WaitForVBL();
    PA_WaitForVBL();
    PA_WaitForVBL();
    PA_WaitForVBL();

    //Fade down
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
    PA_Init2D();
    PA_WaitForVBL();
    PA_WaitForVBL();
}

void Opciones_Menu()
{
    Reload_Opciones_Menu();

    READY = false;

    while (!READY)
    {
        if (Stylus.Newpress) // Tactil
        {
            if (PA_StylusInZone(12, 156, 121, 179)) // JUKEBOX
            {
                Draw16bitRectangleEx(1, 12, 156, 121, 179, PA_RGB(31, 31, 31), 4);

                End_Opciones_Menu();
                Jukebox();
                PA_Init2D();
                Reload_Opciones_Menu();
            }
            else if (PA_StylusInZone(186, 156, 243, 179)) // BACK
            {
                Draw16bitRectangleEx(1, 186, 156, 243, 179, PA_RGB(31, 31, 31), 4);

                READY = true;
            }

            // BOTONES MAS/MENOS
            if (PA_StylusInZone(160, 25, 174, 49)) // Arr/Izq
            {
                PA_SetSpriteAnim(1, 0, 1);
                if (texture_selected > 0)
                    texture_selected--;
                PA_SetSpriteAnim(1, 10, texture_selected);
            }
            else if (PA_StylusInZone(212, 25, 226, 49)) // Arr/Der
            {
                PA_SetSpriteAnim(1, 1, 3);
                if (texture_selected < 5)
                    texture_selected++;
                PA_SetSpriteAnim(1, 10, texture_selected);
            }
            else if(PA_StylusInZone(160, 60, 174, 84)) // Aba/Izq
            {
                PA_SetSpriteAnim(1, 2, 1);
                if (camera_selected > 0)
                    camera_selected--;
                PA_SetSpriteAnim(1, 11, camera_selected);
            }
            else if(PA_StylusInZone(212, 60, 226, 84)) // Aba/Der
            {
                PA_SetSpriteAnim(1, 3, 3);
                if (camera_selected < 2)
                    camera_selected++;
                PA_SetSpriteAnim(1, 11, camera_selected);
            }
        }
        if (Stylus.Released)
        {
            PA_SetSpriteAnim(1, 0, 0);
            PA_SetSpriteAnim(1, 1, 2);
            PA_SetSpriteAnim(1, 2, 0);
            PA_SetSpriteAnim(1, 3, 2);
        }

        Actualizar_3D_Menu();
        Graficos_3D_Menu();

        Menu_Song();
        PA_WaitForVBL();
    }

    End_Opciones_Menu();
    Guardar_Datos();
}
