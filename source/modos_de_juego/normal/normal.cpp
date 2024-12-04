#include <PA9.h>

#include "global.h"
#include "graficos_3d/graphics3d.h"
#include "graficos_3d/escenarios/escenario_normal.h"
#include "graficos_3d/texto/letras.h"
#include "keys_control.h"
#include "modos_de_juego/normal/normal.h"
#include "music.h"

// PAGfxConverter Include
#include "gfx/all_gfx.h"

// TODO Delete v
void Controles_Tactiles_Horizontal();
void Controles_Tactiles_Vertical();
void Autofire_Keys_Horizontal();
void Autofire_Keys_Vertical();
u8 Borrar_Lineas_Completas();
void Borrar_Linea(u8 altura);
void Cancelar_Animacion_Eliminar_Lineas();
void Cancelar_Animacion_Eliminar_Lineas_CPU();
u8 Comprobar_Lineas_Completas();
u8 Comprobar_Linea(u8 altura);
void Ajustar_Colisiones_Actuales();
u8 Estado_Cuadricula(int x, int y);
u8 Comprobar_Colisiones_Inferior();
u8 Comprobar_Colisiones_Derecha();
u8 Comprobar_Colisiones_Izquierda();
u8 Comprobar_Colisiones_Giro();
void Borrar_Pieza_Actual();
void Dibujar_Pieza_Actual();
void Iniciar_Juego();
void Nueva_Pieza();
void Reservar_Pieza();
// TODO Delete ^

void Modo_Normal()
{
    PA_SetBrightness(0, -31);
    PA_SetBrightness(1, -31);

    PA_ClearTextBg (1);
    Wait_To_Stop_Song();
    PA_ResetBgSys();

    PA_WaitForVBL();
    PA_WaitForVBL();
    PA_WaitForVBL();
    PA_WaitForVBL();

    PA_Init8bitBg(1, 3);
    PA_EasyBgLoad(1, 2, inferior_juego);
    PA_SetBgPalCol(1, 1, PA_RGB(31, 0, 0));
    PA_SetBgPalCol(1, 2, PA_RGB(0, 31, 0));
    PA_SetBgPalCol(1, 3, PA_RGB(31, 31, 31));
    PA_SetBgColor(1, PA_RGB(0, 0, 0));

    My_Init_3D();

    // Fade up
    for (auxiliar = -31; auxiliar < 0; auxiliar++)
    {
        PA_SetBrightness(0, auxiliar);
        PA_SetBrightness(1, auxiliar);
        PA_WaitForVBL();
    }

    PA_SetBrightness(0, 0);
    PA_SetBrightness(1, 0);

    Iniciar_Juego();

    Init_Song_Loop();
    PA_WaitForVBL();

    UPDATE_2D = true;

    while (JUEGO_ACTIVO)
    {
        //-----
        //JUEGO
        //-----
        Custom_Newpress();

        if (PAUSA) // Para la pausa
        {
            if (pausa_lista == 0)
            {
                if (Pad.Newpress.Start)
                {
                    PAUSA = false;
                    Unpause_Song();
                    pausa_lista = 20;
                }
            }
            else
            {
                pausa_lista --;
            }

            Escribir_3D_Char_Rotado(TEXT_MEDIUM, 1, 4, CHAR_P,
                                    Text_Color.red, Text_Color.green, Text_Color.blue);
            Escribir_3D_Char_Rotado(TEXT_MEDIUM, 2, 4, CHAR_A,
                                    Text_Color.red - 0.2, Text_Color.green - 0.2, Text_Color.blue - 0.2);
            Escribir_3D_Char_Rotado(TEXT_MEDIUM, 3, 4, CHAR_U,
                                    Text_Color.red, Text_Color.green, Text_Color.blue);
            Escribir_3D_Char_Rotado(TEXT_MEDIUM, 4, 4, CHAR_S,
                                    Text_Color.red - 0.2, Text_Color.green - 0.2, Text_Color.blue - 0.2);
            Escribir_3D_Char_Rotado(TEXT_MEDIUM, 5, 4, CHAR_E,
                                    Text_Color.red, Text_Color.green, Text_Color.blue);

            Update_3D_Text_Colors();
        }
        else
        {
            // Inicio de control

            //puntuacion_total = PA_RTC.FPS;

            if (pausa_lista == 0)
            {
                if (Pad.Newpress.Start)
                {
                    Init_3D_Text_Colors(0.5,0.01, 0.6,0.02, 0.8,0.03);
                    Pause_Song();
                    PAUSA = true;
                    pausa_lista = 20;
                }
            }
            else
            {
                pausa_lista --;
            }

            Autofire_Keys_Horizontal();
            Controles_Tactiles_Horizontal();

            Borrar_Lineas_Completas();

            Ajustar_Colisiones_Actuales();
            Dibujar_Pieza_Actual();

            if (Comprobar_Colisiones_Inferior() == 0)
            {
                girarcount = 30;

                if ((Pad.Held.Left) && (framecount % 5 == 0))
                {
                    Borrar_Pieza_Actual();
                    velocidadcount = 0;
                    Pieza.Y --;
                }

                if (Pad.Newpress.Right)
                {
                    velocidadcount = 0;
                    girarcount = 0;
                    while (Comprobar_Colisiones_Inferior() == 0)
                    {
                        Borrar_Pieza_Actual();
                        Pieza.Y--;
                        Ajustar_Colisiones_Actuales();
                        Dibujar_Pieza_Actual();
                    }
                    Nueva_Pieza();
                    Ajustar_Colisiones_Actuales();
                }
            }

            Ajustar_Colisiones_Actuales();
            Dibujar_Pieza_Actual();

            if ((Pad.Newpress.Down && !Comprobar_Colisiones_Derecha()) || (Pad.Newpress.Up && !Comprobar_Colisiones_Izquierda()))
            {
                girarcount = 30;
                Borrar_Pieza_Actual();
                Pieza.X +=Pad.Newpress.Down - Pad.Newpress.Up;
            }

            Dibujar_Pieza_Actual();

            if (Pad.Newpress.X)
                Reservar_Pieza();

            if ((Pad.Newpress.A) && (Tipo_Pieza[0] != 6))
            {
                if (Comprobar_Colisiones_Inferior() == 0)
                    girarcount = 30;

                switch (Comprobar_Colisiones_Giro())
                {
                    case 0: // Giro normal
                        girarcount = 30;
                        Borrar_Pieza_Actual();
                        Pieza.Rotacion = (Pieza.Rotacion + Pad.Newpress.A) % 4;
                        break;
                    case 1: // Nada
                        if (Comprobar_Colisiones_Inferior() == 0)
                            girarcount = 0;
                        break;
                    case 2: // Hacia arriba
                        girarcount = 30;
                        Borrar_Pieza_Actual();
                        Pieza.Rotacion = (Pieza.Rotacion + Pad.Newpress.A) % 4;
                        Pieza.Y++;
                        break;
                    case 3: // A la derecha
                        girarcount = 30;
                        Borrar_Pieza_Actual();
                        Pieza.Rotacion = (Pieza.Rotacion + Pad.Newpress.A) % 4;
                        Pieza.X++;
                        break;
                    case 4: // A la izquierda
                        girarcount = 30;
                        Borrar_Pieza_Actual();
                        Pieza.Rotacion = (Pieza.Rotacion + Pad.Newpress.A) % 4;
                        Pieza.X --;
                        if (Tipo_Pieza[0] == 0)
                            Pieza.X --;
                        break;
                }
            }

            Ajustar_Colisiones_Actuales();
            Dibujar_Pieza_Actual();

            velocidad = Limitar_float(1, 40, 40 -  1.25 * ((linecount / 5) + 1) );

            velocidadcount ++;
            girarcount --;
            if (velocidadcount > velocidad)
            {
                if (Comprobar_Colisiones_Inferior() == 0)
                {
                    if (!(Pad.Held.Left))
                    {
                        Borrar_Pieza_Actual();
                        Pieza.Y--;
                        velocidadcount = 0;
                    }
                }
                else if ((girarcount < 0) && (Comprobar_Colisiones_Inferior() == 1))
                {
                    if (Pieza.Y == 16)
                        JUEGO_ACTIVO = false; // Fin del juego
                    Ajustar_Colisiones_Actuales();
                    Dibujar_Pieza_Actual();
                    Nueva_Pieza();
                }
            }

            Borrar_Pieza_Actual();

            Ajustar_Colisiones_Actuales();

            switch (Comprobar_Lineas_Completas()) // Numero de filas completas
            {
                case 1:
                    puntuacion_total += combo + 1;
                    combo = 0;
                    UPDATE_2D = true;
                    break;
                case 2:
                    puntuacion_total += 4 * (combo + 1);
                    combo +=1;
                    UPDATE_2D = true;
                    break;
                case 3:
                    puntuacion_total += 9 * (combo + 1);
                    combo +=2;
                    UPDATE_2D = true;
                    break;
                case 4:
                    puntuacion_total += 16 * (combo + 1);
                    combo +=3;
                    UPDATE_2D = true;
                    break;
            }

            Check_Song_End();

        } // Fin de control

        Dibujar_Pieza_Actual();

        switch (camera_selected)
        {
            case CAMERA_DISABLED:
                rotarsalaY = 0;
                break;
            case CAMERA_SLOW:
                if (rotarsalaY > (Pieza.X - 4.5) * -1)
                    rotarsalaY -= 0.1;
                else if (rotarsalaY < (Pieza.X - 4.5) * -1)
                    rotarsalaY += 0.1;
                break;
            case CAMERA_QUICK:
                rotarsalaY = ((Pieza.X - 4.5) * -1);
                break;
        }

        //-----------
        //Gráficos 2D
        //-----------
        Graficos_2D_Normal();

        //-----------
        //Gráficos 3D
        //-----------
        Graficos_3D_Normal();

        fondoazul += incrementoazul;
        fondoverde += incrementoverde;
        fondorojo += incrementorojo;

        if ((fondoverde > 25) || (fondoverde < 10))
            incrementoverde *= -1;
        if ((fondoazul > 25) || (fondoazul < 10))
            incrementoazul *= -1;
        if ((fondorojo > 25) || (fondorojo < 10))
            incrementorojo *= -1;

        if (linecount < 200)
        {
            glClearColor((int)(fondorojo *  Limitar_float(0,1, (float)linecount / 200)),
                         (int)(fondoverde * Limitar_float(0,1, (float)linecount / 90)),
                         (int)(fondoazul *  Limitar_float(0,1, (float)linecount / 30 )) ,31);
        }
        if (linecount > 200)
        {
            glClearColor((int)(fondorojo *  Limitar_float(0,1, (float)linecount / 200)),
                         (int)(fondoverde * Limitar_float(0,1, (500 - (float)linecount) / 300)),
                         (int)(fondoazul *  Limitar_float(0,1, (350 - (float)linecount) / 150)) ,31);
        }

        framecount++;
        framecount %= 60;
        PA_WaitForVBL();
    }
    // Fin del juego

    Stop_Song();

    Cancelar_Animacion_Eliminar_Lineas_CPU();
    Cancelar_Animacion_Eliminar_Lineas();

    JUEGO_ACTIVO = true;
    framecount = 0;
    velocidadcount = 0;
    girarcount = 0;

    Init_3D_Text_Colors(0.5,0.01, 0.3,0, 0.3,0);

    //ESPERAR
    while (JUEGO_ACTIVO)
    {
        if (velocidadcount < 17)
        {
            Piezas_Aleatorias(velocidadcount);
            if ((framecount % 6 == 0))
                velocidadcount++;
        }
        else if (girarcount == 0)
            girarcount = 1;

        if (girarcount != 0)
            girarcount++;

        if ((girarcount > 30) && (girarcount < 100))
        {
            rotarsalaZ--;
            if (girarcount > 60)
                rotarsalaZ--;
        }

        if ((Pad.Held.Anykey || Stylus.Newpress) && (girarcount > 98))
            JUEGO_ACTIVO = false;

        //-----------
        //Gráficos 2D
        //-----------
        Graficos_2D_Normal();

        //-----------
        //Gráficos 3D
        //-----------
        Graficos_3D_Normal();


        Escribir_3D_Char_Rotado(TEXT_BIG, 0, 1, CHAR_G,
                                Text_Color.red, Text_Color.green, Text_Color.blue);
        Escribir_3D_Char_Rotado(TEXT_BIG, 1, 1, CHAR_A,
                                Text_Color.red - 0.1, Text_Color.green  - 0.1, Text_Color.blue  - 0.1);
        Escribir_3D_Char_Rotado(TEXT_BIG, 2, 1, CHAR_M,
                                Text_Color.red - 0.1, Text_Color.green  - 0.1, Text_Color.blue  - 0.1);
        Escribir_3D_Char_Rotado(TEXT_BIG, 3, 1, CHAR_E,
                                Text_Color.red, Text_Color.green, Text_Color.blue);

        Escribir_3D_Char_Rotado(TEXT_BIG, 0, 3, CHAR_O,
                                Text_Color.red - 0.1, Text_Color.green  - 0.1, Text_Color.blue  - 0.1);
        Escribir_3D_Char_Rotado(TEXT_BIG, 1, 3, CHAR_V,
                                Text_Color.red, Text_Color.green, Text_Color.blue);
        Escribir_3D_Char_Rotado(TEXT_BIG, 2, 3, CHAR_E,
                                Text_Color.red, Text_Color.green, Text_Color.blue);
        Escribir_3D_Char_Rotado(TEXT_BIG, 3, 3, CHAR_R,
                                Text_Color.red - 0.1, Text_Color.green  - 0.1, Text_Color.blue  - 0.1);

        Update_3D_Text_Colors();

        if (fondorojo > 0.5)
            fondorojo -= 0.1;
        if (fondoverde > 0.5)
            fondoverde -= 0.1;
        if (fondoazul > 0.5)
            fondoazul -= 0.1;

        if (linecount < 200)
        {
            glClearColor((int)(fondorojo *  Limitar_float(0,1, (float)linecount / 200)),
                         (int)(fondoverde * Limitar_float(0,1, (float)linecount / 90)),
                         (int)(fondoazul *  Limitar_float(0,1, (float)linecount / 30 )) ,31);
        }
        if (linecount > 200)
        {
            glClearColor((int)(fondorojo *  Limitar_float(0,1, (float)linecount / 200)),
                         (int)(fondoverde * Limitar_float(0,1, (500 - (float)linecount) / 300)),
                         (int)(fondoazul *  Limitar_float(0,1, (350 - (float)linecount) / 150)) ,31);
        }

        framecount++;
        framecount %= 60;
        PA_WaitForVBL();
    }

    glFlush(0);
    glFlush(0);
    PA_WaitForVBL();
    PA_WaitForVBL();
}

//Funciones de graficos
//---------------------

void Graficos_2D_Normal()
{
    if (lasttime != (u8)PA_RTC.Minutes)
        UPDATE_2D = true;

    lasttime = (u8)PA_RTC.Minutes;

    if (UPDATE_2D)
    {
        //Dibujar puntuación
        char str[50];
        snprintf(str, sizeof(str), " Score: %d  ",(int)puntuacion_total);
        PA_SmartText(1, 8,8,183,16 ,str, 1, // Color
                     4, 3, 25);

        //Dibujar lineas
        snprintf(str, sizeof(str), "Lines: %d  ",(int)linecount);
        PA_SmartText(1, 13,35,119,249 ,str, 1 /*Color*/, 3, 3, 18);

        //Dibujar nombre
        snprintf(str, sizeof(str), " Player:  %s  ",  (char*)PA_UserInfo.Name);
        PA_SmartText(1, 8,239,183,247 ,str, 2, // Color
                     3, 3, PA_UserInfo.NameLength + 11);

        //Dibujar hora
        char hora[20];
        snprintf(hora, sizeof(hora), " %02d:%02d ",(int)PA_RTC.Hour, (int)PA_RTC.Minutes);
        PA_CenterSmartText(1, 106,214,152,255 ,hora, 3 /*Color*/ , 3, 3   ); //, 12);
    }
}

void Graficos_3D_Normal()
{
    glPushMatrix();
    // not a real gl function and will likely change
    glPolyFmt(POLY_ALPHA(31) | POLY_CULL_BACK);
    // ds uses a table for shinyness..this generates a half-ass one
    glMaterialShinyness();

    glRotateX(90);

    glRotateZ(rotarsalaZ);

    glRotateY((int)rotarsalaY);

    glTranslatef(4.0, -3.5, -2.2 /*5*/); // Ajustar camara

    Dibujar_Explosiones();
    Dibujar_Escenario_Normal();
    Dibujar_Tetris();

    glPopMatrix(1);
    glFlush(0);
}
