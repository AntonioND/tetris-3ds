#include <PA9.h>

#include "graficos_3d/graphics3d.h"
#include "menu/creditos.h"
#include "menu.h"
#include "music.h"

// PAGfxConverter Include
#include "gfx/all_gfx.h"

static void Reload_Creditos_Menu(void)
{
    PA_ResetBgSys();
    PA_Init2D();

    PA_SetBrightness(0, -31);
    PA_SetBrightness(1, -31);

    PA_WaitForVBL();
    PA_WaitForVBL();

    My_Init_3D_No_Textures();
    Iniciar_3D_Menu();

    Actualizar_3D_Menu();
    Graficos_3D_Menu();

    PA_Init16bitBg(1, 3);
    PA_Load16bitBitmap(1, inferior_credits_Bitmap);

    // Fade up
    for (int i = -31; i < 0; i++)
    {
        PA_SetBrightness(0, i);
        PA_SetBrightness(1, i);
        PA_WaitForVBL();
    }

    PA_SetBrightness(0, 0);
    PA_SetBrightness(1, 0);
}

static void End_Creditos_Menu(void)
{
    PA_WaitForVBL();
    PA_WaitForVBL();
    PA_WaitForVBL();
    PA_WaitForVBL();
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
    PA_Init2D();
    PA_WaitForVBL();
    PA_WaitForVBL();
}

void Creditos(void)
{
    Reload_Creditos_Menu();
    while (!(Pad.Newpress.Anykey || Stylus.Newpress))
    {
        Actualizar_3D_Menu();
        Graficos_3D_Menu();

        Menu_Song();
        PA_WaitForVBL();
    }

    End_Creditos_Menu();
}
