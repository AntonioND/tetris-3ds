// SPDX-License-Identifier: GPL-3.0-only
//
// Copyright (c) 2008, 2024-2025 Antonio Niño Díaz

#include <PA9.h>

#include "global.h"
#include "modos_de_juego/cpu_ia.h"
#include "modos_de_juego/juego.h"

// PAGfxConverter Include
#include "gfx/all_gfx.h"

#define NUMSPRITE_RESERVA_CPU   16
#define NUM_ROTACIONES          4

typedef struct {
    u8 altura;
    u8 huecosdebajo;
    u8 huecostotal;
    u8 superficie;
} _POSICION_IA_;

static u8 piezareserva_CPU;
static bool reservallena_CPU, reservausada_CPU;

static _POSICION_IA_ Posicion_CPU[ANCHO_PIEZAS][NUM_ROTACIONES];
static PIEZA_TETRIS Almacen_CPU;
static PIEZA_TETRIS Posicion_Ideal_CPU;

static int superficie_, huecostotal_, huecosdebajo_;

static u8 activarreserva;

u8 Comprobar_Superficie_CPU(void)
{
    u32 count = 0;

    for (int i = 0; i < 16; i++) // Pieza
    {
        if (Colisiones_Actual_CPU[i] == 1)
        {
            // Si el de abajo esta vacio o esta en el borde
            if (((Colisiones_Actual_CPU[i + 4] == 0) && (i < 12)) || (i == 12))
                count++;
        }
    }

    return count;
}

u8 Comprobar_Huecos_Inferior_CPU()
{
    u32 count = 0;

    for (int i = 0; i < 16; i++) // Pieza
    {
        if (Colisiones_Actual_CPU[i] == 1)
        {
            // Si el de abajo esta vacio o esta en el borde
            if (((Colisiones_Actual_CPU[i + 4] == 0) && (i < 12)) || (i > 12))
            {
                // Si está dentro del escenario a lo ancho
                if (Limitar_int(0,9,Pieza_CPU.X + (i % 4) - 1) == Pieza_CPU.X + (i % 4) - 1)
                {

                    if (Estado_Cuadricula_CPU(Pieza_CPU.X + (i % 4) - 1, Pieza_CPU.Y - (i / 4)) == 0)
                        count++;

                }
            }
        }
    }

    return count;
}

u8 Comprobar_Huecos_CPU(void)
{
    u32 count = 0;

    for (int i = 0; i < 16; i++) // Pieza
    {
        if (Colisiones_Actual_CPU[i] == 1)
        {
            // Arriba
            // Si está dentro del escenario
            if (Limitar_int(0, 9, Pieza_CPU.X + (i % 4) - 1) == Pieza_CPU.X + (i % 4) - 1)
            {
                if (Limitar_int(0, 16, Pieza_CPU.Y + (i / 4) + 2) == Pieza_CPU.Y + (i / 4) + 2)
                {
                    if (Estado_Cuadricula_CPU(Pieza_CPU.X + (i % 4) - 1, Pieza_CPU.Y - (i / 4) + 2) == 0)
                        count++;
                }
            }

            // Abajo
            // Si está dentro del escenario
            if (Limitar_int(0, 9, Pieza_CPU.X + (i % 4) - 1) == Pieza_CPU.X + (i % 4) - 1)
            {
                if (Limitar_int(0, 16, Pieza_CPU.Y + (i / 4)) == Pieza_CPU.Y + (i / 4))
                {
                    if (Estado_Cuadricula_CPU(Pieza_CPU.X + (i % 4) - 1, Pieza_CPU.Y - (i / 4)) == 0)
                        count++;
                }
            }

            // Derecha
            // Si está dentro del escenario
            if (Limitar_int(0, 9, Pieza_CPU.X + (i % 4)) == Pieza_CPU.X + (i % 4))
            {
                if (Limitar_int(0, 16, Pieza_CPU.Y + (i / 4) + 1) == Pieza_CPU.Y + (i / 4) + 1)
                {
                    if (Estado_Cuadricula_CPU(Pieza_CPU.X + (i % 4), Pieza_CPU.Y - (i / 4) + 1) == 0)
                        count++;
                }
            }

            // Izquierda
            // Si está dentro del escenario
            if (Limitar_int(0, 9, Pieza_CPU.X + (i % 4) - 2) == Pieza_CPU.X + (i % 4) - 2)
            {
                if (Limitar_int(0, 16, Pieza_CPU.Y + (i / 4) + 1) == Pieza_CPU.Y + (i / 4) + 1)
                {
                    if (Estado_Cuadricula_CPU(Pieza_CPU.X + (i % 4) - 2, Pieza_CPU.Y - (i / 4) + 1) == 0)
                        count++;
                }
            }

        /*
            if (Colisiones_Actual_CPU[i] == 0)
            {
                // Si está dentro del escenario a lo ancho
                if (Limitar_int(0, 9, Pieza_CPU.X + (i % 4) - 1) == Pieza_CPU.X + (i % 4) - 1)
                {
                    if (Limitar_int(0, 16, Pieza_CPU.Y + (i / 4) + 1) == Pieza_CPU.Y + (i / 4) + 1)
                    {
                        if (Estado_Cuadricula_CPU(Pieza_CPU.X + (i % 4) - 1, Pieza_CPU.Y - (i / 4) + 1) == 0)
                            cumulador++;
                    }
                }
            }
        */
        }
    }

    return count;
}

static void Set_Position_CPU(int x, int y) // Ayuda para IA_CPU()
{
    superficie_ = Posicion_CPU[x][y].superficie;
    huecostotal_ = Posicion_CPU[x][y].huecostotal;
    huecosdebajo_ = Posicion_CPU[x][y].huecosdebajo;
    Posicion_Ideal_CPU.X = x;
    Posicion_Ideal_CPU.Y = Posicion_CPU[x][y].altura;
    Posicion_Ideal_CPU.Rotacion = y;
}

// Maravilla creada por mi XD
void IA_CPU(void)
{
    Almacen_CPU.X = Pieza_CPU.X;
    Almacen_CPU.Y = Pieza_CPU.Y;
    Almacen_CPU.Rotacion = Pieza_CPU.Rotacion;

    for (int i = 0; i < ANCHO_PIEZAS; i++)
    {
        for (int j = 0; j < NUM_ROTACIONES; j++)
        {
            Posicion_CPU[i][j].altura = 100;
            Posicion_CPU[i][j].huecosdebajo = 100;
            Posicion_CPU[i][j].huecostotal = 100;
            Posicion_CPU[i][j].superficie = 0;
        }
    }

    // Obtener datos
    for (Pieza_CPU.Rotacion = 0; Pieza_CPU.Rotacion < 4; Pieza_CPU.Rotacion++)
    {
        Ajustar_Colisiones_Actuales_CPU();

        if (!Comprobar_Colisiones_Derecha_CPU())
        {
            while (!Comprobar_Colisiones_Derecha_CPU())
                Pieza_CPU.X++; // Poner a la derecha
        }

        int counter = 0;

        while (counter < 2) // Hasta llegar a la izquierda
        {
            if (!Comprobar_Colisiones_Inferior_CPU())
            {
                while (!Comprobar_Colisiones_Inferior_CPU())
                    Pieza_CPU.Y--;
            }

            if (Pieza_CPU.Y < 15)
            {
                Posicion_CPU[Pieza_CPU.X][Pieza_CPU.Rotacion].altura = Pieza_CPU.Y;
                Posicion_CPU[Pieza_CPU.X][Pieza_CPU.Rotacion].huecosdebajo = Comprobar_Huecos_Inferior_CPU();
                Posicion_CPU[Pieza_CPU.X][Pieza_CPU.Rotacion].huecostotal = Comprobar_Huecos_CPU();
                Posicion_CPU[Pieza_CPU.X][Pieza_CPU.Rotacion].superficie = Comprobar_Superficie_CPU();
            }

            Pieza_CPU.Y = Almacen_CPU.Y;
            if (Pieza_CPU.X > 0)
                Pieza_CPU.X--;
            else
                counter = 2; //Si se sale

            if (Comprobar_Colisiones_Izquierda_CPU())
                counter++;
        }

        Pieza_CPU.Y = Almacen_CPU.Y;
    }

    // Recuperar posicion

    Pieza_CPU.Y = Almacen_CPU.Y;
    Pieza_CPU.X = Almacen_CPU.X;
    Pieza_CPU.Rotacion = Almacen_CPU.Rotacion;
    Ajustar_Colisiones_Actuales_CPU();

    Posicion_Ideal_CPU.Y = 100; //Para que cualquier posicion sea mejor.
    Posicion_Ideal_CPU.X = 100;
    Posicion_Ideal_CPU.Rotacion = 0;
    superficie_ = 0;
    huecostotal_ = 100;
    huecosdebajo_ = 100;
    /*
    int counter = 100; //Temporal, por si no va bien lo nuevo
    auxiliar3 = 100;
    */
    /*
    (Posicion_Ideal_CPU.Y >= Posicion_CPU[auxiliar].altura)
    (Posicion_CPU[auxiliar].huecosdebajo <= counter)
    (Posicion_CPU[auxiliar].huecostotal <= auxiliar3)
    */

    // Ver la mejor posicion (Mas bien lo unico decente...)
    for (int i = 0; i < ANCHO_PIEZAS; i++)
    {
        for (int j = 0; j < NUM_ROTACIONES; j++)
        {
            if (Posicion_CPU[i][j].altura < 15)
            {
                //----------------------------
                //Inicio de las comprobaciones
                //----------------------------
                switch (Tipo_Pieza_CPU[0])
                {
                    case 0: // Linea
                        if ((Posicion_Ideal_CPU.Y + 3 > Posicion_CPU[i][j].altura) &&
                            (Posicion_CPU[i][j].huecosdebajo <= huecosdebajo_))
                        {
                            if (Posicion_CPU[Pieza_CPU.X][Pieza_CPU.Rotacion].superficie > superficie_)
                            {
                                Set_Position_CPU(i, j);
                            }
                            if ((Posicion_CPU[Pieza_CPU.X][Pieza_CPU.Rotacion].superficie == superficie_) &&
                                (Posicion_CPU[i][j].huecostotal < huecostotal_))
                            {
                                Set_Position_CPU(i, j);
                            }
                        }
                        break;

                    case 1: //  L
                    case 2:
                        if (Posicion_Ideal_CPU.Y + 3 >= Posicion_CPU[i][j].altura)
                        {
                            if ((Posicion_CPU[i][j].huecosdebajo < huecosdebajo_) &&
                                (Posicion_CPU[Pieza_CPU.X][Pieza_CPU.Rotacion].superficie >= superficie_))
                            {
                                Set_Position_CPU(i, j);
                            }
                            if ((Posicion_CPU[i][j].huecosdebajo <= huecosdebajo_) &&
                                (Posicion_CPU[Pieza_CPU.X][Pieza_CPU.Rotacion].superficie > superficie_))
                            {
                                Set_Position_CPU(i, j);
                            }
                        }
                        if ((Posicion_Ideal_CPU.Y + 1 >= Posicion_CPU[i][j].altura) &&
                            (Posicion_CPU[Pieza_CPU.X][Pieza_CPU.Rotacion].superficie >= superficie_) &&
                            (Posicion_CPU[i][j].huecostotal <= huecostotal_))
                        {
                            Set_Position_CPU(i, j);
                        }
                        break;

                    case 3: //Cosa rara
                    case 4:
                        if (Posicion_CPU[i][j].huecosdebajo <= huecosdebajo_)
                        {
                            if ((Posicion_Ideal_CPU.Y + 4 >= Posicion_CPU[i][j].altura) &&
                                (Posicion_CPU[Pieza_CPU.X][Pieza_CPU.Rotacion].superficie > superficie_))
                            {
                                Set_Position_CPU(i, j);
                            }
                            if ((Posicion_Ideal_CPU.Y >= Posicion_CPU[i][j].altura) &&
                                (Posicion_CPU[i][j].huecostotal <= huecostotal_))
                            {
                                Set_Position_CPU(i, j);
                            }
                        }
                        break;

                    case 5: //  T

/*
                        if (Posicion_CPU[i][j].huecosdebajo <= huecosdebajo_)
                        {
                            if ((Posicion_CPU[Pieza_CPU.X][Pieza_CPU.Rotacion].superficie > superficie_) &&
                                (Posicion_Ideal_CPU.Y + 3 >= Posicion_CPU[i][j].altura))
                            {
                                Set_Position_CPU(i, j);
                            }
                            if ((Posicion_CPU[Pieza_CPU.X][Pieza_CPU.Rotacion].superficie == superficie_) &&
                                (Posicion_Ideal_CPU.Y == Posicion_CPU[i][j].altura) &&
                                (Posicion_CPU[i][j].huecostotal <= huecostotal_))
                            {
                                Set_Position_CPU(i, j);
                            }
                        }
*/

                        if ((Posicion_CPU[Pieza_CPU.X][Pieza_CPU.Rotacion].superficie == superficie_) &&
                            (Posicion_CPU[i][j].huecosdebajo == huecosdebajo_) &&
                            (Posicion_CPU[i][j].huecostotal < huecostotal_) &&
                            (Posicion_Ideal_CPU.Y >= Posicion_CPU[i][j].altura - 2))
                        {
                            Set_Position_CPU(i, j);
                        }
                        else if ((Posicion_CPU[Pieza_CPU.X][Pieza_CPU.Rotacion].superficie > superficie_) &&
                                 (Posicion_CPU[i][j].huecosdebajo <= huecosdebajo_) &&
                                 (Posicion_Ideal_CPU.Y >= Posicion_CPU[i][j].altura - 2))
                        {
                            Set_Position_CPU(i, j);
                        }
                        else if ((Posicion_CPU[Pieza_CPU.X][Pieza_CPU.Rotacion].superficie >= superficie_) &&
                                 (Posicion_CPU[i][j].huecosdebajo < huecosdebajo_) &&
                                 (Posicion_Ideal_CPU.Y >= Posicion_CPU[i][j].altura - 2))
                        {
                            Set_Position_CPU(i, j);
                        }
                        break;

                    case 6: // Cuadrado
                        if ((Posicion_CPU[i][j].huecosdebajo < huecosdebajo_) &&
                            (Posicion_Ideal_CPU.Y + 3 > Posicion_CPU[i][j].altura))
                        {
                            Set_Position_CPU(i, j);
                        }
                        if ((Posicion_CPU[i][j].huecosdebajo == huecosdebajo_) &&
                            (Posicion_Ideal_CPU.Y > Posicion_CPU[i][j].altura))
                        {
                            Set_Position_CPU(i, j);
                        }
                        if ((Posicion_CPU[i][j].huecosdebajo == huecosdebajo_) &&
                            (Posicion_Ideal_CPU.Y == Posicion_CPU[i][j].altura) &&
                            (Posicion_CPU[i][j].huecostotal < huecostotal_))
                        {
                            Set_Position_CPU(i, j);
                        }
                        break;
                }

            } // endif

        /*
            // Temporal, por si no va bien lo nuevo
            if ((Posicion_Ideal_CPU.Y > Posicion_CPU[i][j].altura))
            {
                if (Posicion_CPU[i][j].huecosdebajo < counter)
                {
                    auxiliar3 = Posicion_CPU[i][j].huecostotal;
                    counter = Posicion_CPU[i][j].huecosdebajo;
                    Posicion_Ideal_CPU.X = i;
                    Posicion_Ideal_CPU.Y = Posicion_CPU[i][j].altura;
                    Posicion_Ideal_CPU.Rotacion = j;
                }
                else if ((Posicion_CPU[i][j].huecosdebajo == counter) &&
                         (Posicion_CPU[i][j].huecostotal <= auxiliar3))
                {
                    auxiliar3 = Posicion_CPU[i][j].huecostotal;
                    counter = Posicion_CPU[i][j].huecosdebajo;
                    Posicion_Ideal_CPU.X = i;
                    Posicion_Ideal_CPU.Y = Posicion_CPU[i][j].altura;
                    Posicion_Ideal_CPU.Rotacion =j;
                }
            }
        */
            // ---------------------------
            // Final de las comprobaciones
            // ---------------------------
        }
    }

    //Reserva
    if ((((float)huecosdebajo_) / ((float)superficie_) >= 0.5) && (Tipo_Pieza_CPU[0] % 5 != 0) && (activarreserva == 0))
    {
        activarreserva = 20;
    }
}

void Mover_IA_CPU(void)
{
    if (activarreserva > 0)
        activarreserva--;
    if (activarreserva == 1)
        Reservar_Pieza_CPU();

    if ((Pieza_CPU.X < Posicion_Ideal_CPU.X ) && (framecount % 3 == 0) && (!Comprobar_Colisiones_Derecha_CPU()))
    {
        Pieza_CPU.X ++;
        girarcount_CPU = 30;
    }
    if ((Pieza_CPU.X > Posicion_Ideal_CPU.X ) && (framecount % 3 == 0) && (!Comprobar_Colisiones_Izquierda_CPU()))
    {
        Pieza_CPU.X --;
        girarcount_CPU = 30;
    }

    if ((Pieza_CPU.Rotacion != Posicion_Ideal_CPU.Rotacion) && (framecount % 3 == 0))
    {
        girarcount_CPU = 30;
        switch (Comprobar_Colisiones_Giro_CPU())
        {
            case 0: // Giro normal
                Borrar_Pieza_Actual_CPU();
                Pieza_CPU.Rotacion = (Pieza_CPU.Rotacion + 1) % 4;
                break;

            case 1: // Nada
                girarcount_CPU = 0;
                break;

            case 2: // Hacia arriba
                Borrar_Pieza_Actual_CPU();
                Pieza_CPU.Rotacion = (Pieza_CPU.Rotacion + 1) % 4;
                Pieza_CPU.Y++;
                break;

            case 3: // A la derecha
                Borrar_Pieza_Actual_CPU();
                Pieza_CPU.Rotacion = (Pieza_CPU.Rotacion + 1) % 4;
                Pieza_CPU.X++;
                break;

            case 4: // A la izquierda
                Borrar_Pieza_Actual_CPU();
                Pieza_CPU.Rotacion = (Pieza_CPU.Rotacion + 1) % 4;
                Pieza_CPU.X--;
                if (Tipo_Pieza_CPU[0] == 0)
                    Pieza_CPU.X--;
                break;
        }
    }

    // Cuando este en la posicion buena
    if ((Pieza_CPU.X == Posicion_Ideal_CPU.X) && (Pieza_CPU.Rotacion == Posicion_Ideal_CPU.Rotacion))
        Caida_rapida_CPU = 1;
    else
        Caida_rapida_CPU = 0;
}

void Cancelar_Animacion_Eliminar_Lineas_CPU(void)
{
    for (int i = 0; i < ALTO_PIEZAS + 2; i++)
        Fila_Eliminada_CPU[i] = 0;
}

u8 Borrar_Lineas_Completas_CPU(void)
{
    Borrar_Pieza_Actual_CPU();

    u32 result = 0;
    for (int linea = ALTO_PIEZAS; linea > 0; linea--)
    {
        if (Comprobar_Linea_CPU(linea - 1))
        {
            result = 1;
            Borrar_Linea_CPU(linea - 1);
        }
    }

    // Ajustar_Colisiones_Actuales_CPU();
    Dibujar_Pieza_Actual_CPU();

    return result;
}

void Borrar_Linea_CPU(u8 altura)
{
    linecount_CPU += 1;

    for (int i = 0; i < ANCHO_PIEZAS; i++)
        Escenario_Tetris_CPU[i][altura].dibujar = 0;

    // Desplazar líneas hacia abajo
    for (int j = altura; j < ALTO_PIEZAS + 2; j ++)
    {
        for (int i = 0; i < ANCHO_PIEZAS; i++)
        {
            Escenario_Tetris_CPU[i][j].dibujar = Escenario_Tetris_CPU[i][Limitar_int(0,16,j + 1)].dibujar;
            Escenario_Tetris_CPU[i][j].red = Escenario_Tetris_CPU[i][Limitar_int(0,16,j + 1)].red;
            Escenario_Tetris_CPU[i][j].green = Escenario_Tetris_CPU[i][Limitar_int(0,16,j + 1)].green;
            Escenario_Tetris_CPU[i][j].blue = Escenario_Tetris_CPU[i][Limitar_int(0,16,j + 1)].blue;
        }
    }

    // Borrar última linea
    for (int i = 0; i < ANCHO_PIEZAS; i++)
        Escenario_Tetris_CPU[i][16].dibujar = 0;
}

// Devuelve las líneas completas
u8 Comprobar_Lineas_Completas_CPU(void)
{
    int count = 0;
    for (int j = 0; j < ALTO_PIEZAS + 2; j++)
    {
        if (Comprobar_Linea_CPU(j) == 1)
        {
            Fila_Eliminada_CPU[j] = 30;
            count++;
        }
        else
        {
            Fila_Eliminada_CPU[j]--;
        }
    }
    return count;
}

u8 Comprobar_Linea_CPU(u8 altura)
{
    u32 sum = 0;

    for (int i = 0; i < ANCHO_PIEZAS; i++)
        sum += Estado_Cuadricula_CPU(i, altura);

    if (sum > 9)
        return 1;

    return 0;
}

void Ajustar_Colisiones_Actuales_CPU(void)
{
    for (int i = 0; i < 16; i++)
        Colisiones_Actual_CPU[i] = 0;

    switch (Tipo_Pieza_CPU[0])
    {
        case 0: // Pieza 0
            if ((Pieza_CPU.Rotacion == 0) || (Pieza_CPU.Rotacion == 2))
            {
                Colisiones_Actual_CPU[8] = 1;
                Colisiones_Actual_CPU[9] = 1;
                Colisiones_Actual_CPU[10] = 1;
                Colisiones_Actual_CPU[11] = 1;
            }
            else
            {
                Colisiones_Actual_CPU[1] = 1;
                Colisiones_Actual_CPU[5] = 1;
                Colisiones_Actual_CPU[9] = 1;
                Colisiones_Actual_CPU[13] = 1;
            }
            break;

        case 1: // Pieza 1
            if (Pieza_CPU.Rotacion == 0)
            {
                Colisiones_Actual_CPU[5] = 1;
                Colisiones_Actual_CPU[6] = 1;
                Colisiones_Actual_CPU[7] = 1;
                Colisiones_Actual_CPU[9] = 1;
            }
            else if (Pieza_CPU.Rotacion == 1)
            {
                Colisiones_Actual_CPU[1] = 1;
                Colisiones_Actual_CPU[5] = 1;
                Colisiones_Actual_CPU[9] = 1;
                Colisiones_Actual_CPU[10] = 1;
            }
            else if (Pieza_CPU.Rotacion == 2)
            {
                Colisiones_Actual_CPU[6] = 1;
                Colisiones_Actual_CPU[8] = 1;
                Colisiones_Actual_CPU[9] = 1;
                Colisiones_Actual_CPU[10] = 1;
            }
            else if (Pieza_CPU.Rotacion == 3)
            {
                Colisiones_Actual_CPU[5] = 1;
                Colisiones_Actual_CPU[6] = 1;
                Colisiones_Actual_CPU[10] = 1;
                Colisiones_Actual_CPU[14] = 1;
            }
            break;

        case 2: // Pieza 2
            if (Pieza_CPU.Rotacion == 0)
            {
                Colisiones_Actual_CPU[5] = 1;
                Colisiones_Actual_CPU[9] = 1;
                Colisiones_Actual_CPU[10] = 1;
                Colisiones_Actual_CPU[11] = 1;
            }
            else if (Pieza_CPU.Rotacion == 1)
            {
                Colisiones_Actual_CPU[2] = 1;
                Colisiones_Actual_CPU[6] = 1;
                Colisiones_Actual_CPU[9] = 1;
                Colisiones_Actual_CPU[10] = 1;
            }
            else if (Pieza_CPU.Rotacion == 2)
            {
                Colisiones_Actual_CPU[4] = 1;
                Colisiones_Actual_CPU[5] = 1;
                Colisiones_Actual_CPU[6] = 1;
                Colisiones_Actual_CPU[10] = 1;
            }
            else if (Pieza_CPU.Rotacion == 3)
            {
                Colisiones_Actual_CPU[5] = 1;
                Colisiones_Actual_CPU[6] = 1;
                Colisiones_Actual_CPU[9] = 1;
                Colisiones_Actual_CPU[13] = 1;
            }
            break;

        case 3: // Pieza 3
            if ((Pieza_CPU.Rotacion == 0) || (Pieza_CPU.Rotacion == 2))
            {
                Colisiones_Actual_CPU[4] = 1;
                Colisiones_Actual_CPU[5] = 1;
                Colisiones_Actual_CPU[9] = 1;
                Colisiones_Actual_CPU[10] = 1;
            }
            else
            {
                Colisiones_Actual_CPU[2] = 1;
                Colisiones_Actual_CPU[5] = 1;
                Colisiones_Actual_CPU[6] = 1;
                Colisiones_Actual_CPU[9] = 1;
            }
            break;

        case 4: // Pieza 4
            if ((Pieza_CPU.Rotacion == 0) || (Pieza_CPU.Rotacion == 2))
            {
                Colisiones_Actual_CPU[5] = 1;
                Colisiones_Actual_CPU[6] = 1;
                Colisiones_Actual_CPU[8] = 1;
                Colisiones_Actual_CPU[9] = 1;
            }
            else
            {
                Colisiones_Actual_CPU[1] = 1;
                Colisiones_Actual_CPU[5] = 1;
                Colisiones_Actual_CPU[6] = 1;
                Colisiones_Actual_CPU[10] = 1;
            }
            break;

        case 5: // Pieza 5
            if (Pieza_CPU.Rotacion == 0)
            {
                Colisiones_Actual_CPU[1] = 1;
                Colisiones_Actual_CPU[4] = 1;
                Colisiones_Actual_CPU[5] = 1;
                Colisiones_Actual_CPU[6] = 1;
            }
            else if (Pieza_CPU.Rotacion == 1)
            {
                Colisiones_Actual_CPU[1] = 1;
                Colisiones_Actual_CPU[4] = 1;
                Colisiones_Actual_CPU[5] = 1;
                Colisiones_Actual_CPU[9] = 1;
            }
            else if (Pieza_CPU.Rotacion == 2)
            {
                Colisiones_Actual_CPU[4] = 1;
                Colisiones_Actual_CPU[5] = 1;
                Colisiones_Actual_CPU[6] = 1;
                Colisiones_Actual_CPU[9] = 1;
            }
            else if (Pieza_CPU.Rotacion == 3)
            {
                Colisiones_Actual_CPU[1] = 1;
                Colisiones_Actual_CPU[5] = 1;
                Colisiones_Actual_CPU[6] = 1;
                Colisiones_Actual_CPU[9] = 1;
            }
            break;

        case 6: // Pieza 6
            Colisiones_Actual_CPU[5] = 1;
            Colisiones_Actual_CPU[6] = 1;
            Colisiones_Actual_CPU[9] = 1;
            Colisiones_Actual_CPU[10] = 1;
            break;
    }
}

// Devuelve 1 si está ocupado, 0 si no. Los bordes cuentan como 1.
u8 Estado_Cuadricula_CPU(int x, int y)
{
    if ((Limitar_int(0, 9, x) != x) || (y < 0))
        return 1;
    else if (y > 16)
        return 0;
    else
        return (Limitar_int(0, 1, Escenario_Tetris_CPU[x][y].dibujar - 1));
}

u8 Comprobar_Colisiones_Inferior_CPU(void)
{
    for (int i = 0; i < 16; i++) // Pieza
    {
        if (Colisiones_Actual_CPU[i] == 1)
        {
            // Si el siguiente esta vacio y está a la abajo
            if ((Colisiones_Actual_CPU[i + 4] == 0) || (i / 4 == 3) )
            {
                if (Limitar_int(0, 9, Pieza_CPU.X + (i % 4) - 1) == Pieza_CPU.X + (i % 4) - 1)
                {
                    if (Estado_Cuadricula_CPU(Pieza_CPU.X + (i % 4) - 1, Pieza_CPU.Y - (i / 4)))
                        return 1;
                }
            }
        }
    }

    return 0;
}

u8 Comprobar_Colisiones_Derecha_CPU(void)
{
    for (int i = 0; i < 16; i++) // Pieza
    {
        if (Colisiones_Actual_CPU[i] == 1)
        {
            // Si el siguiente esta vacio y está a la derecha
            if ((Colisiones_Actual_CPU[i + 1] == 0) || (i % 4 == 3) )
            {
                //if (Limitar_int(0,16,Pieza_CPU.Y + (i / 4) - 1) == Pieza_CPU.Y + (i / 4) - 1)
                //{
                    if (Estado_Cuadricula_CPU(Pieza_CPU.X + (i % 4), Pieza_CPU.Y - (i / 4) + 1))
                        return 1;
                //}
            }
        }
    }

    return 0;
}

u8 Comprobar_Colisiones_Izquierda_CPU(void)
{
    for (int i = 0; i < 16; i++) // Pieza
    {
        if (Colisiones_Actual_CPU[i] == 1)
        {
            // Si el siguiente esta vacio y está a la derecha
            if ((Colisiones_Actual_CPU[i - 1] == 0) || (i % 4 == 0) )
            {
                //if (Limitar_int(0,16,Pieza_CPU.Y + (i / 4) - 1) == Pieza_CPU.Y + (i / 4) - 1)
                //{
                    if (Estado_Cuadricula_CPU(Pieza_CPU.X + (i % 4) - 2, Pieza_CPU.Y - (i / 4) + 1))
                        return 1;
                //}
            }
        }
    }
    return 0;
}

u8 Comprobar_Colisiones_Giro_CPU(void)
{
    Borrar_Pieza_Actual_CPU();

    temp_giro = Pieza_CPU.Rotacion;
    temp_y = Pieza_CPU.Y;
    temp_x = Pieza_CPU.X;
    Pieza_CPU.Rotacion = (Pieza_CPU.Rotacion + 1) % 4;

    Ajustar_Colisiones_Actuales_CPU();

    u32 result = 0;

    for (int i = 0; i < 16; i++) // Pieza
    {
        if (Colisiones_Actual_CPU[i] == 1)
        {
            if (Estado_Cuadricula_CPU(Pieza_CPU.X + (i % 4) - 1, Pieza_CPU.Y - (i / 4) + 1))
                result = 1;
        }
    }

    // Probar subiendo la pieza una posición
    if (result == 1)
    {
        result = 2;
        Pieza_CPU.Y ++;

        Ajustar_Colisiones_Actuales_CPU();

        for (int i = 0; i < 16; i++) // Pieza
        {
            if (Colisiones_Actual_CPU[i] == 1)
            {
                if (Estado_Cuadricula_CPU(Pieza_CPU.X + (i % 4) - 1, Pieza_CPU.Y - (i / 4) + 1))
                    result = 1;
            }
        }

        Pieza_CPU.Y --;
    }

    Ajustar_Colisiones_Actuales_CPU();

    // Probar moviendo a los lados
    if (result == 1)
    {
        // Probar a la derecha
        if (Comprobar_Colisiones_Izquierda_CPU() == 1)
        {
            result = 3;
            Pieza_CPU.X++;

            Ajustar_Colisiones_Actuales_CPU();
        }
        else if (Comprobar_Colisiones_Derecha_CPU() == 1)
        {
            result = 4;
            Pieza_CPU.X--;
            if (Tipo_Pieza_CPU[0] == 0)
                Pieza_CPU.X --; // si es la alargada prueba una posicion mas.

            Ajustar_Colisiones_Actuales_CPU();
        }

        for (int i = 0; i < 16; i++) // Pieza
        {
            if (Colisiones_Actual_CPU[i] == 1)
            {
                if (Estado_Cuadricula_CPU(Pieza_CPU.X + (i % 4) - 1, Pieza_CPU.Y - (i / 4) + 1))
                    result = 1;
            }
        }

        Pieza_CPU.X = temp_x;
    }

    Pieza_CPU.Rotacion = temp_giro;
    Pieza_CPU.Y = temp_y;
    Pieza_CPU.X = temp_x;

    Ajustar_Colisiones_Actuales_CPU();
    Dibujar_Pieza_Actual_CPU();

    return result;
}

void Borrar_Pieza_Actual_CPU(void)
{
    temp_y = Pieza_CPU.Y;

    // Sombra
    Ajustar_Colisiones_Actuales_CPU();

    while (Comprobar_Colisiones_Inferior_CPU() == 0)
    {
        Pieza_CPU.Y--;

        Ajustar_Colisiones_Actuales_CPU();
    }

    for (int i = 0; i < 16; i++) // Pieza
    {
        if (Colisiones_Actual_CPU[i] == 1)
        {
            if ((Limitar_int(0, 9, Pieza_CPU.X + (i % 4) - 1) == Pieza_CPU.X + (i % 4) - 1) &&
                (Limitar_int(0, 16, Pieza_CPU.Y - (i / 4) + 1) == Pieza_CPU.Y - (i / 4) + 1))
            {
                Escenario_Tetris_CPU[Limitar_int(0, 9, Pieza_CPU.X + (i % 4) - 1)]
                                    [Limitar_int(0, 16, Pieza_CPU.Y - (i / 4) + 1)].dibujar = 0;
            }
        }
    }

    Pieza_CPU.Y = temp_y; // Recuperar posicion

    for (int i = 0; i < 16; i++) // Pieza
    {
        if (Colisiones_Actual_CPU[i] == 1)
        {
            if ((Limitar_int(0, 9, Pieza_CPU.X + (i % 4) - 1) == Pieza_CPU.X + (i % 4) - 1) &&
                (Limitar_int(0, 16, Pieza_CPU.Y - (i / 4) + 1) == Pieza_CPU.Y - (i / 4) + 1))
            {
                Escenario_Tetris_CPU[Limitar_int(0, 9, Pieza_CPU.X + (i % 4) - 1)]
                                    [Limitar_int(0, 16, Pieza_CPU.Y - (i / 4) + 1)].dibujar = 0;
            }
        }
    }
}

void Dibujar_Pieza_Actual_CPU(void)
{
    float red = 0, green = 0, blue = 0;

    // Pieza actual
    switch (Tipo_Pieza_CPU[0]) // Color
    {
        case 0:
            red = 1;
            green = 1;
            blue = 1;
            break;
        case 1:
            red = 1;
            green = 1;
            blue = 0;
            break;
        case 2:
            red = 1;
            green = 0.5;
            blue = 0;
            break;
        case 3:
            red = 1;
            green = 0;
            blue = 0;
            break;
        case 4:
            red = 0;
            green = 1;
            blue = 0;
            break;
        case 5:
            red = 0;
            green = 0;
            blue = 1;
            break;
        case 6:
            red = 0.75;
            green = 0;
            blue = 1;
            break;
    }

    temp_y = Pieza_CPU.Y; //Guardar Posicion

    // Sombra
    while (Comprobar_Colisiones_Inferior_CPU() == 0)
    {
        Pieza_CPU.Y --;

        Ajustar_Colisiones_Actuales_CPU();
    }

    for (int i = 0; i < 16; i++)
    {
        if (Colisiones_Actual_CPU[i] == 1)
        {
            if ((Limitar_int(0, 9, Pieza_CPU.X + (i % 4) - 1) == Pieza_CPU.X + (i % 4) - 1) &&
                (Limitar_int(0, 16, Pieza_CPU.Y - (i / 4) + 1) == Pieza_CPU.Y - (i / 4) + 1))
            {
                Escenario_Tetris_CPU[Limitar_int(0, 9, Pieza_CPU.X + (i % 4) - 1)]
                                    [Limitar_int(0, 16, Pieza_CPU.Y - (i / 4) + 1)].dibujar = 1;
                Escenario_Tetris_CPU[Limitar_int(0, 9, Pieza_CPU.X + (i % 4) - 1)]
                                    [Limitar_int(0, 16, Pieza_CPU.Y - (i / 4) + 1)].red = red;
                Escenario_Tetris_CPU[Limitar_int(0, 9, Pieza_CPU.X + (i % 4) - 1)]
                                    [Limitar_int(0, 16, Pieza_CPU.Y - (i / 4) + 1)].green = green;
                Escenario_Tetris_CPU[Limitar_int(0, 9, Pieza_CPU.X + (i % 4) - 1)]
                                    [Limitar_int(0, 16, Pieza_CPU.Y - (i / 4) + 1)].blue = blue;
            }
        }
    }

    Pieza_CPU.Y = temp_y; // Recuperar posicion

    for (int i = 0; i < 16; i++) // Pieza
    {
        if (Colisiones_Actual_CPU[i] == 1)
        {
            if ((Limitar_int(0, 9, Pieza_CPU.X + (i % 4) - 1) == Pieza_CPU.X + (i % 4) - 1) &&
                (Limitar_int(0, 16, Pieza_CPU.Y - (i / 4) + 1) == Pieza_CPU.Y - (i / 4) + 1))
            {
                Escenario_Tetris_CPU[Limitar_int(0, 9, Pieza_CPU.X + (i % 4) - 1)]
                                    [Limitar_int(0, 16, Pieza_CPU.Y - (i / 4) + 1)].dibujar = 2;
                Escenario_Tetris_CPU[Limitar_int(0, 9, Pieza_CPU.X + (i % 4) - 1)]
                                    [Limitar_int(0, 16, Pieza_CPU.Y - (i / 4) + 1)].red = red;
                Escenario_Tetris_CPU[Limitar_int(0, 9, Pieza_CPU.X + (i % 4) - 1)]
                                    [Limitar_int(0, 16, Pieza_CPU.Y - (i / 4) + 1)].green = green;
                Escenario_Tetris_CPU[Limitar_int(0, 9, Pieza_CPU.X + (i % 4) - 1)]
                                    [Limitar_int(0, 16, Pieza_CPU.Y - (i / 4) + 1)].blue = blue;
            }
        }
    }
}

void Iniciar_Juego_CPU(void)
{
    Pieza_CPU.Y = 16;
    Pieza_CPU.X = 4;
    Pieza_CPU.Rotacion = 0;
    puntuacion_total_CPU = 0;
    linecount_CPU = 0;
    girarcount_CPU = 0;

    Caida_rapida_CPU = 0;
    jugador_ganador = 0;
    combo_CPU = 0;
    reservallena_CPU = false;
    reservausada_CPU = false;

    velocidadcount_CPU = 0;

    for (int i = 0; i < ANCHO_PIEZAS; i++)
    {
        for (int j = 0; j < ALTO_PIEZAS + 2; j++)
        {
            Escenario_Tetris_CPU[i][j].dibujar = 0;
            Escenario_Tetris_CPU[i][j].red = 0;
            Escenario_Tetris_CPU[i][j].green = 0;
            Escenario_Tetris_CPU[i][j].blue = 0;
        }
    }

    for (int j = 0; j < ALTO_PIEZAS + 2; j++)
        Fila_Eliminada_CPU[j] = 0;

    // Preparar piezas
    for (int i = 0; i < 5; i++)
        Tipo_Pieza_CPU[i] = PA_RandMinMax(0,6);

    Ajustar_Colisiones_Actuales_CPU();
    Dibujar_Pieza_Actual_CPU();

    for (int i = 1; i <= 4; i++)
    {
        PA_CreateSprite(1, i + 50, (void *)Pieza_Sprite, OBJ_SIZE_16X32, 1, 0, 234, 5 + (39 * (i - 1)));
        PA_SetSpriteAnim(1, i + 50, Tipo_Pieza_CPU[i]);
    }
}

void Nueva_Pieza_CPU(void)
{
    Pieza_CPU.Y = 16;
    Pieza_CPU.X = 4;
    Pieza_CPU.Rotacion = 0;

    reservausada_CPU = false;

    velocidadcount_CPU = 0;
    girarcount_CPU = 0;

    for (int i = 0; i < 4; i++)
        Tipo_Pieza_CPU[i] = Tipo_Pieza_CPU[i + 1];

    Tipo_Pieza_CPU[4] = PA_RandMinMax(0, 6);

    Ajustar_Colisiones_Actuales_CPU();

    for (int i = 1; i <= 4; i++)
        PA_SetSpriteAnim(1, i + 50, Tipo_Pieza_CPU[i]);
}

void Reservar_Pieza_CPU(void)
{
    Borrar_Pieza_Actual_CPU();

    if (!reservallena_CPU)
    {
        piezareserva_CPU = Tipo_Pieza_CPU[0];

        reservallena_CPU = true;

        PA_CreateSprite(1, NUMSPRITE_RESERVA_CPU, (void*)Pieza_Sprite, OBJ_SIZE_16X32, 1, 0, 210, 28);
        PA_SetSpriteAnim(1, NUMSPRITE_RESERVA_CPU, piezareserva_CPU);

        Nueva_Pieza_CPU();
        reservausada_CPU = true;
    }
    else if (!reservausada_CPU)
    {
        reservausada_CPU = true;

        int temp = piezareserva_CPU;
        piezareserva_CPU = Tipo_Pieza_CPU[0];
        Tipo_Pieza_CPU[0] = temp;

        PA_SetSpriteAnim(1, NUMSPRITE_RESERVA_CPU, piezareserva_CPU);

        Pieza_CPU.Y = 16;
        Pieza_CPU.X = 4;
        Pieza_CPU.Rotacion = 0;

        velocidadcount_CPU = 0;
        girarcount_CPU = 0;

        Ajustar_Colisiones_Actuales_CPU();
    }
}
