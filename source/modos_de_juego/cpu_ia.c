#include <PA9.h>

#include "global.h"
#include "modos_de_juego/cpu_ia.h"
#include "modos_de_juego/juego.h"

// PAGfxConverter Include
#include "gfx/all_gfx.h"

u8 piezareserva_CPU;
bool reservallena_CPU, reservausada_CPU;

_POSICION_IA_ Posicion_CPU[ANCHO_PIEZAS][NUM_ROTACIONES];
PIEZA_TETRIS Almacen_CPU;
PIEZA_TETRIS Posicion_Ideal_CPU;

int superficie_, huecostotal_, huecosdebajo_;

u8 Comprobar_Superficie_CPU()
{
    acumulador = 0;

    for (auxiliar = 0;auxiliar < 16; auxiliar++) //Pieza
    {
        if (Colisiones_Actual_CPU[auxiliar] == 1)
        {
            // Si el de abajo esta vacio o esta en el borde
            if (((Colisiones_Actual_CPU[auxiliar + 4] == 0) && (auxiliar < 12)) || (auxiliar == 12))
            {
                acumulador++;
            }
        }
    }

    return acumulador;
}

u8 Comprobar_Huecos_Inferior_CPU()
{
    acumulador = 0;

    for (auxiliar = 0;auxiliar < 16; auxiliar++) //Pieza
    {
        if (Colisiones_Actual_CPU[auxiliar] == 1)
        {
            // Si el de abajo esta vacio o esta en el borde
            if (((Colisiones_Actual_CPU[auxiliar + 4] == 0) && (auxiliar < 12)) || (auxiliar > 12))
            {
                // Si está dentro del escenario a lo ancho
                if (Limitar_int(0,9,Pieza_CPU.X + (auxiliar % 4) - 1) == Pieza_CPU.X + (auxiliar % 4) - 1)
                {

                    if (Estado_Cuadricula_CPU(Pieza_CPU.X + (auxiliar % 4) - 1, Pieza_CPU.Y - (auxiliar / 4)) == 0)
                        acumulador++;

                }
            }
        }
    }

    return acumulador;
}

u8 Comprobar_Huecos_CPU()
{
    acumulador = 0;

    for (auxiliar = 0;auxiliar < 16; auxiliar++) // Pieza
    {
        if (Colisiones_Actual_CPU[auxiliar] == 1)
        {
            // Arriba
            // Si está dentro del escenario
            if (Limitar_int(0, 9, Pieza_CPU.X + (auxiliar % 4) - 1) == Pieza_CPU.X + (auxiliar % 4) - 1)
            {
                if (Limitar_int(0, 16, Pieza_CPU.Y + (auxiliar / 4) + 2) == Pieza_CPU.Y + (auxiliar / 4) + 2)
                {
                    if (Estado_Cuadricula_CPU(Pieza_CPU.X + (auxiliar % 4) - 1, Pieza_CPU.Y - (auxiliar / 4) + 2) == 0)
                        acumulador++;
                }
            }

            // Abajo
            // Si está dentro del escenario
            if (Limitar_int(0, 9, Pieza_CPU.X + (auxiliar % 4) - 1) == Pieza_CPU.X + (auxiliar % 4) - 1)
            {
                if (Limitar_int(0, 16, Pieza_CPU.Y + (auxiliar / 4)) == Pieza_CPU.Y + (auxiliar / 4))
                {
                    if (Estado_Cuadricula_CPU(Pieza_CPU.X + (auxiliar % 4) - 1, Pieza_CPU.Y - (auxiliar / 4)) == 0)
                        acumulador++;
                }
            }

            // Derecha
            // Si está dentro del escenario
            if (Limitar_int(0, 9, Pieza_CPU.X + (auxiliar % 4)) == Pieza_CPU.X + (auxiliar % 4))
            {
                if (Limitar_int(0, 16, Pieza_CPU.Y + (auxiliar / 4) + 1) == Pieza_CPU.Y + (auxiliar / 4) + 1)
                {
                    if (Estado_Cuadricula_CPU(Pieza_CPU.X + (auxiliar % 4), Pieza_CPU.Y - (auxiliar / 4) + 1) == 0)
                        acumulador++;
                }
            }

            // Izquierda
            // Si está dentro del escenario
            if (Limitar_int(0, 9, Pieza_CPU.X + (auxiliar % 4) - 2) == Pieza_CPU.X + (auxiliar % 4) - 2)
            {
                if (Limitar_int(0, 16, Pieza_CPU.Y + (auxiliar / 4) + 1) == Pieza_CPU.Y + (auxiliar / 4) + 1)
                {
                    if (Estado_Cuadricula_CPU(Pieza_CPU.X + (auxiliar % 4) - 2, Pieza_CPU.Y - (auxiliar / 4) + 1) == 0)
                        acumulador++;
                }
            }

/*
            if (Colisiones_Actual_CPU[auxiliar] == 0)
            {
                // Si está dentro del escenario a lo ancho
                if (Limitar_int(0, 9, Pieza_CPU.X + (auxiliar % 4) - 1) == Pieza_CPU.X + (auxiliar % 4) - 1)
                {
                    if (Limitar_int(0, 16, Pieza_CPU.Y + (auxiliar / 4) + 1) == Pieza_CPU.Y + (auxiliar / 4) + 1)
                    {
                        if (Estado_Cuadricula_CPU(Pieza_CPU.X + (auxiliar % 4) - 1, Pieza_CPU.Y - (auxiliar / 4) + 1) == 0)
                            cumulador++;
                    }
                }
            }
*/
        }
    }

    return acumulador;
}

static void Set_Position_CPU() // Ayuda para IA_CPU()
{
    superficie_ = Posicion_CPU[auxiliar][auxiliar2].superficie;
    huecostotal_ = Posicion_CPU[auxiliar][auxiliar2].huecostotal;
    huecosdebajo_ = Posicion_CPU[auxiliar][auxiliar2].huecosdebajo;
    Posicion_Ideal_CPU.X = auxiliar;
    Posicion_Ideal_CPU.Y = Posicion_CPU[auxiliar][auxiliar2].altura;
    Posicion_Ideal_CPU.Rotacion = auxiliar2;
}

u8 activarreserva;

// Maravilla creada por mi XD
void IA_CPU()
{
    Almacen_CPU.X = Pieza_CPU.X;
    Almacen_CPU.Y = Pieza_CPU.Y;
    Almacen_CPU.Rotacion = Pieza_CPU.Rotacion;

    for (auxiliar = 0; auxiliar < ANCHO_PIEZAS; auxiliar++)
    {
        for (auxiliar2 = 0; auxiliar2 < NUM_ROTACIONES; auxiliar2++)
        {
            Posicion_CPU[auxiliar][auxiliar2].altura = 100;
            Posicion_CPU[auxiliar][auxiliar2].huecosdebajo = 100;
            Posicion_CPU[auxiliar][auxiliar2].huecostotal = 100;
            Posicion_CPU[auxiliar][auxiliar2].superficie = 0;
        }
    }

    // Obtener datos
    for (Pieza_CPU.Rotacion = 0;Pieza_CPU.Rotacion < 4; Pieza_CPU.Rotacion++)
    {
        Ajustar_Colisiones_Actuales_CPU();

        if (!Comprobar_Colisiones_Derecha_CPU())
        {
            while (!Comprobar_Colisiones_Derecha_CPU())
                Pieza_CPU.X++; //Poner a la derecha
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

    //Recuperar posicion

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
    for (auxiliar = 0;auxiliar < ANCHO_PIEZAS; auxiliar++)
    {
        for (auxiliar2 = 0; auxiliar2 < NUM_ROTACIONES; auxiliar2++)
        {
            if (Posicion_CPU[auxiliar][auxiliar2].altura < 15)
            {
                //----------------------------
                //Inicio de las comprobaciones
                //----------------------------
                switch (Tipo_Pieza_CPU[0])
                {                   //-----
                    case 0:         //Linea
                                    //-----
                        if ((Posicion_Ideal_CPU.Y + 3 > Posicion_CPU[auxiliar][auxiliar2].altura) &&
                            (Posicion_CPU[auxiliar][auxiliar2].huecosdebajo <= huecosdebajo_))
                        {
                            if (Posicion_CPU[Pieza_CPU.X][Pieza_CPU.Rotacion].superficie > superficie_)
                            {
                                Set_Position_CPU();
                            }
                            if ((Posicion_CPU[Pieza_CPU.X][Pieza_CPU.Rotacion].superficie == superficie_) &&
                                (Posicion_CPU[auxiliar][auxiliar2].huecostotal < huecostotal_))
                            {
                                Set_Position_CPU();
                            }
                        }
                        break;
                                    //-----
                    case 1:         //  L
                    case 2:         //-----

                        if (Posicion_Ideal_CPU.Y + 3 >= Posicion_CPU[auxiliar][auxiliar2].altura)
                        {
                            if ((Posicion_CPU[auxiliar][auxiliar2].huecosdebajo < huecosdebajo_) &&
                                (Posicion_CPU[Pieza_CPU.X][Pieza_CPU.Rotacion].superficie >= superficie_))
                            {
                                Set_Position_CPU();
                            }
                            if ((Posicion_CPU[auxiliar][auxiliar2].huecosdebajo <= huecosdebajo_) &&
                                (Posicion_CPU[Pieza_CPU.X][Pieza_CPU.Rotacion].superficie > superficie_))
                            {
                                Set_Position_CPU();
                            }
                        }
                        if ((Posicion_Ideal_CPU.Y + 1 >= Posicion_CPU[auxiliar][auxiliar2].altura) &&
                            (Posicion_CPU[Pieza_CPU.X][Pieza_CPU.Rotacion].superficie >= superficie_) &&
                            (Posicion_CPU[auxiliar][auxiliar2].huecostotal <= huecostotal_))
                        {
                            Set_Position_CPU();
                        }
                        break;

                                    //---------
                    case 3:         //Cosa rara
                    case 4:         //---------
                        if (Posicion_CPU[auxiliar][auxiliar2].huecosdebajo <= huecosdebajo_)
                        {
                            if ((Posicion_Ideal_CPU.Y + 4 >= Posicion_CPU[auxiliar][auxiliar2].altura) &&
                                (Posicion_CPU[Pieza_CPU.X][Pieza_CPU.Rotacion].superficie > superficie_))
                            {
                                Set_Position_CPU();
                            }
                            if ((Posicion_Ideal_CPU.Y >= Posicion_CPU[auxiliar][auxiliar2].altura) &&
                                (Posicion_CPU[auxiliar][auxiliar2].huecostotal <= huecostotal_))
                            {
                                Set_Position_CPU();
                            }
                        }
                        break;
                                    //-----
                    case 5:         //  T
                                    //-----
/*
                        if (Posicion_CPU[auxiliar][auxiliar2].huecosdebajo <= huecosdebajo_)
                        {
                            if ((Posicion_CPU[Pieza_CPU.X][Pieza_CPU.Rotacion].superficie > superficie_) &&
                                (Posicion_Ideal_CPU.Y + 3 >= Posicion_CPU[auxiliar][auxiliar2].altura))
                            {
                                Set_Position_CPU();
                            }
                            if ((Posicion_CPU[Pieza_CPU.X][Pieza_CPU.Rotacion].superficie == superficie_) &&
                                (Posicion_Ideal_CPU.Y == Posicion_CPU[auxiliar][auxiliar2].altura) &&
                                (Posicion_CPU[auxiliar][auxiliar2].huecostotal <= huecostotal_))
                            {
                                Set_Position_CPU();
                            }
                        }
*/

                        if ((Posicion_CPU[Pieza_CPU.X][Pieza_CPU.Rotacion].superficie == superficie_) &&
                            (Posicion_CPU[auxiliar][auxiliar2].huecosdebajo == huecosdebajo_) &&
                            (Posicion_CPU[auxiliar][auxiliar2].huecostotal < huecostotal_) &&
                            (Posicion_Ideal_CPU.Y >= Posicion_CPU[auxiliar][auxiliar2].altura - 2))
                        {
                            Set_Position_CPU();
                        }
                        else if ((Posicion_CPU[Pieza_CPU.X][Pieza_CPU.Rotacion].superficie > superficie_) &&
                                 (Posicion_CPU[auxiliar][auxiliar2].huecosdebajo <= huecosdebajo_) &&
                                 (Posicion_Ideal_CPU.Y >= Posicion_CPU[auxiliar][auxiliar2].altura - 2))
                        {
                            Set_Position_CPU();
                        }
                        else if ((Posicion_CPU[Pieza_CPU.X][Pieza_CPU.Rotacion].superficie >= superficie_) &&
                                 (Posicion_CPU[auxiliar][auxiliar2].huecosdebajo < huecosdebajo_) &&
                                 (Posicion_Ideal_CPU.Y >= Posicion_CPU[auxiliar][auxiliar2].altura - 2))
                        {
                            Set_Position_CPU();
                        }
                        break;

                                    //--------
                    case 6:         //Cuadrado
                                    //--------
                        if ((Posicion_CPU[auxiliar][auxiliar2].huecosdebajo < huecosdebajo_) &&
                            (Posicion_Ideal_CPU.Y + 3 > Posicion_CPU[auxiliar][auxiliar2].altura))
                        {
                            Set_Position_CPU();
                        }
                        if ((Posicion_CPU[auxiliar][auxiliar2].huecosdebajo == huecosdebajo_) &&
                            (Posicion_Ideal_CPU.Y > Posicion_CPU[auxiliar][auxiliar2].altura))
                        {
                            Set_Position_CPU();
                        }
                        if ((Posicion_CPU[auxiliar][auxiliar2].huecosdebajo == huecosdebajo_) &&
                            (Posicion_Ideal_CPU.Y == Posicion_CPU[auxiliar][auxiliar2].altura) &&
                            (Posicion_CPU[auxiliar][auxiliar2].huecostotal < huecostotal_))
                        {
                            Set_Position_CPU();
                        }
                        break;
                }

            } // endif

        /*
            // Temporal, por si no va bien lo nuevo
            if ((Posicion_Ideal_CPU.Y > Posicion_CPU[auxiliar][auxiliar2].altura))
            {
                if (Posicion_CPU[auxiliar][auxiliar2].huecosdebajo < counter)
                {
                    auxiliar3 = Posicion_CPU[auxiliar][auxiliar2].huecostotal;
                    counter = Posicion_CPU[auxiliar][auxiliar2].huecosdebajo;
                    Posicion_Ideal_CPU.X = auxiliar;
                    Posicion_Ideal_CPU.Y = Posicion_CPU[auxiliar][auxiliar2].altura;
                    Posicion_Ideal_CPU.Rotacion = auxiliar2;
                }
                else if ((Posicion_CPU[auxiliar][auxiliar2].huecosdebajo == counter) && (Posicion_CPU[auxiliar][auxiliar2].huecostotal <= auxiliar3))
                {
                    auxiliar3 = Posicion_CPU[auxiliar][auxiliar2].huecostotal;
                    counter = Posicion_CPU[auxiliar][auxiliar2].huecosdebajo;
                    Posicion_Ideal_CPU.X = auxiliar;
                    Posicion_Ideal_CPU.Y = Posicion_CPU[auxiliar][auxiliar2].altura;
                    Posicion_Ideal_CPU.Rotacion =auxiliar2;
                }
            }
        */
            //---------------------------
            //Final de las comprobaciones
            //---------------------------
        }
    }

    //Reserva
    if ((((float)huecosdebajo_) / ((float)superficie_) >= 0.5) && (Tipo_Pieza_CPU[0] % 5 != 0) && (activarreserva == 0))
    {
        activarreserva = 20;
    }
}

void Mover_IA_CPU()
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

void Cancelar_Animacion_Eliminar_Lineas_CPU()
{
    for (auxiliar3 = 0;auxiliar3 < ALTO_PIEZAS + 2; auxiliar3++)
    {
        Fila_Eliminada_CPU[auxiliar3] = 0;
    }
}

u8 Borrar_Lineas_Completas_CPU()
{
    Borrar_Pieza_Actual_CPU();

    auxiliar3 = 0;
    for (int linea = ALTO_PIEZAS; linea > 0; linea--)
    {
        if (Comprobar_Linea_CPU(linea - 1))
        {
            auxiliar3 = 1;
            Borrar_Linea_CPU(linea - 1);
        }
    }

    // Ajustar_Colisiones_Actuales_CPU();
    Dibujar_Pieza_Actual_CPU();

    return auxiliar3;
}

void Borrar_Linea_CPU(u8 altura)
{
    linecount_CPU += 1;

    for (auxiliar2 = 0;auxiliar2 < ANCHO_PIEZAS; auxiliar2++)
    {
        Escenario_Tetris_CPU[auxiliar2][altura].dibujar = 0;
    }

    // Desplazar líneas hacia abajo
    for (auxiliar = altura; auxiliar < ALTO_PIEZAS + 2; auxiliar ++)
    {
        for (auxiliar2 = 0;auxiliar2 < ANCHO_PIEZAS; auxiliar2++)
        {
            Escenario_Tetris_CPU[auxiliar2][auxiliar].dibujar = Escenario_Tetris_CPU[auxiliar2][Limitar_int(0,16,auxiliar + 1)].dibujar;
            Escenario_Tetris_CPU[auxiliar2][auxiliar].red = Escenario_Tetris_CPU[auxiliar2][Limitar_int(0,16,auxiliar + 1)].red;
            Escenario_Tetris_CPU[auxiliar2][auxiliar].green = Escenario_Tetris_CPU[auxiliar2][Limitar_int(0,16,auxiliar + 1)].green;
            Escenario_Tetris_CPU[auxiliar2][auxiliar].blue = Escenario_Tetris_CPU[auxiliar2][Limitar_int(0,16,auxiliar + 1)].blue;
        }
    }

    // Borrar última linea
    for (auxiliar2 = 0;auxiliar2 < ANCHO_PIEZAS; auxiliar2++)
    {
        Escenario_Tetris_CPU[auxiliar2][16].dibujar = 0;
    }
}

// Devuelve las líneas completas
u8 Comprobar_Lineas_Completas_CPU()
{
    int count = 0;
    for (auxiliar3 = 0; auxiliar3 < ALTO_PIEZAS + 2; auxiliar3++)
    {
        if (Comprobar_Linea_CPU(auxiliar3) == 1)
        {
            Fila_Eliminada_CPU[auxiliar3] = 30;
            count++;
        }
        else
        {
            Fila_Eliminada_CPU[auxiliar3] --;
        }
    }
    return count;
}

u8 Comprobar_Linea_CPU(u8 altura)
{
    auxiliar2 = 0;

    for (auxiliar = 0;auxiliar < ANCHO_PIEZAS; auxiliar++)
    {
        auxiliar2 += Estado_Cuadricula_CPU(auxiliar, altura);
    }

    if (auxiliar2 > 9)
        return 1;

    return 0;
}

void Ajustar_Colisiones_Actuales_CPU()
{
    for (auxiliar = 0; auxiliar < 16; auxiliar++)
        Colisiones_Actual_CPU[auxiliar] = 0;

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

u8 Comprobar_Colisiones_Inferior_CPU()
{
    for (auxiliar = 0;auxiliar < 16; auxiliar++) //Pieza
    {
        if (Colisiones_Actual_CPU[auxiliar] == 1)
        {
            // Si el siguiente esta vacio y está a la abajo
            if ((Colisiones_Actual_CPU[auxiliar + 4] == 0) || (auxiliar / 4 == 3) )
            {
                if (Limitar_int(0, 9, Pieza_CPU.X + (auxiliar % 4) - 1) == Pieza_CPU.X + (auxiliar % 4) - 1)
                {
                    if (Estado_Cuadricula_CPU(Pieza_CPU.X + (auxiliar % 4) - 1, Pieza_CPU.Y - (auxiliar / 4)))
                        return 1;
                }
            }
        }
    }

    return 0;
}

u8 Comprobar_Colisiones_Derecha_CPU()
{
    for (auxiliar = 0;auxiliar < 16; auxiliar++) // Pieza
    {
        if (Colisiones_Actual_CPU[auxiliar] == 1)
        {
            // Si el siguiente esta vacio y está a la derecha
            if ((Colisiones_Actual_CPU[auxiliar + 1] == 0) || (auxiliar % 4 == 3) )
            {
                //if (Limitar_int(0,16,Pieza_CPU.Y + (auxiliar / 4) - 1) == Pieza_CPU.Y + (auxiliar / 4) - 1)
                //{
                    if (Estado_Cuadricula_CPU(Pieza_CPU.X + (auxiliar % 4), Pieza_CPU.Y - (auxiliar / 4) + 1))
                        return 1;
                //}
            }
        }
    }

    return 0;
}

u8 Comprobar_Colisiones_Izquierda_CPU()
{
    for (auxiliar = 0;auxiliar < 16; auxiliar++) // Pieza
    {
        if (Colisiones_Actual_CPU[auxiliar] == 1)
        {
            // Si el siguiente esta vacio y está a la derecha
            if ((Colisiones_Actual_CPU[auxiliar - 1] == 0) || (auxiliar % 4 == 0) )
            {
                //if (Limitar_int(0,16,Pieza_CPU.Y + (auxiliar / 4) - 1) == Pieza_CPU.Y + (auxiliar / 4) - 1)
                //{
                    if (Estado_Cuadricula_CPU(Pieza_CPU.X + (auxiliar % 4) - 2, Pieza_CPU.Y - (auxiliar / 4) + 1))
                        return 1;
                //}
            }
        }
    }
    return 0;
}

u8 Comprobar_Colisiones_Giro_CPU()
{
    Borrar_Pieza_Actual_CPU();

    auxiliar2 = 0;
    temp_giro = Pieza_CPU.Rotacion;
    temp_y = Pieza_CPU.Y;
    temp_x = Pieza_CPU.X;
    Pieza_CPU.Rotacion = (Pieza_CPU.Rotacion + 1) % 4;

    Ajustar_Colisiones_Actuales_CPU();

    for (auxiliar = 0;auxiliar < 16; auxiliar++) //Pieza
    {
        if (Colisiones_Actual_CPU[auxiliar] == 1)
        {
            if (Estado_Cuadricula_CPU(Pieza_CPU.X + (auxiliar % 4) - 1, Pieza_CPU.Y - (auxiliar / 4) + 1))
                auxiliar2 = 1;
        }
    }

    // Probar subiendo la pieza una posición
    if (auxiliar2 == 1)
    {
        auxiliar2 = 2;
        Pieza_CPU.Y ++;

        Ajustar_Colisiones_Actuales_CPU();

        for (auxiliar = 0;auxiliar < 16; auxiliar++) // Pieza
        {
            if (Colisiones_Actual_CPU[auxiliar] == 1)
            {
                if (Estado_Cuadricula_CPU(Pieza_CPU.X + (auxiliar % 4) - 1, Pieza_CPU.Y - (auxiliar / 4) + 1))
                    auxiliar2 = 1;
            }
        }

        Pieza_CPU.Y --;
    }

    Ajustar_Colisiones_Actuales_CPU();

    // Probar moviendo a los lados
    if (auxiliar2 == 1)
    {
        // Probar a la derecha
        if (Comprobar_Colisiones_Izquierda_CPU() == 1)
        {
            auxiliar2 = 3;
            Pieza_CPU.X++;

            Ajustar_Colisiones_Actuales_CPU();
        }
        else if (Comprobar_Colisiones_Derecha_CPU() == 1)
        {
            auxiliar2 = 4;
            Pieza_CPU.X--;
            if (Tipo_Pieza_CPU[0] == 0)
                Pieza_CPU.X --; // si es la alargada prueba una posicion mas.

            Ajustar_Colisiones_Actuales_CPU();
        }

        for (auxiliar = 0;auxiliar < 16; auxiliar++) // Pieza
        {
            if (Colisiones_Actual_CPU[auxiliar] == 1)
            {
                if (Estado_Cuadricula_CPU(Pieza_CPU.X + (auxiliar % 4) - 1, Pieza_CPU.Y - (auxiliar / 4) + 1))
                    auxiliar2 = 1;
            }
        }

        Pieza_CPU.X = temp_x;
    }

    Pieza_CPU.Rotacion = temp_giro;
    Pieza_CPU.Y = temp_y;
    Pieza_CPU.X = temp_x;

    Ajustar_Colisiones_Actuales_CPU();
    Dibujar_Pieza_Actual_CPU();

    return auxiliar2;
}

void Borrar_Pieza_Actual_CPU()
{
    temp_y = Pieza_CPU.Y;

    // Sombra
    Ajustar_Colisiones_Actuales_CPU();

    while (Comprobar_Colisiones_Inferior_CPU() == 0)
    {
        Pieza_CPU.Y--;

        Ajustar_Colisiones_Actuales_CPU();
    }

    for (auxiliar = 0;auxiliar < 16; auxiliar++) // Pieza
    {
        if (Colisiones_Actual_CPU[auxiliar] == 1)
        {
            if ((Limitar_int(0, 9,Pieza_CPU.X + (auxiliar % 4) - 1) == Pieza_CPU.X + (auxiliar % 4) - 1) && (Limitar_int(0, 16,Pieza_CPU.Y - (auxiliar / 4) + 1) == Pieza_CPU.Y - (auxiliar / 4) + 1))
            {
                Escenario_Tetris_CPU[Limitar_int(0, 9,Pieza_CPU.X + (auxiliar % 4) - 1)][Limitar_int(0, 16,Pieza_CPU.Y - (auxiliar / 4) + 1)].dibujar = 0;
            }
        }
    }

    Pieza_CPU.Y = temp_y; // Recuperar posicion

    for (auxiliar = 0;auxiliar < 16; auxiliar++) // Pieza
    {
        if (Colisiones_Actual_CPU[auxiliar] == 1)
        {
            if ((Limitar_int(0, 9,Pieza_CPU.X + (auxiliar % 4) - 1) == Pieza_CPU.X + (auxiliar % 4) - 1) && (Limitar_int(0, 16,Pieza_CPU.Y - (auxiliar / 4) + 1) == Pieza_CPU.Y - (auxiliar / 4) + 1))
            {
                Escenario_Tetris_CPU[Limitar_int(0, 9,Pieza_CPU.X + (auxiliar % 4) - 1)][Limitar_int(0, 16,Pieza_CPU.Y - (auxiliar / 4) + 1)].dibujar = 0;
            }
        }
    }
}

void Dibujar_Pieza_Actual_CPU()
{
    // Pieza actual
    switch (Tipo_Pieza_CPU[0]) // Color
    {
        case 0:
            red_ = 1;
            green_ = 1;
            blue_ = 1;
            break;
        case 1:
            red_ = 1;
            green_ = 1;
            blue_ = 0;
            break;
        case 2:
            red_ = 1;
            green_ = 0.5;
            blue_ = 0;
            break;
        case 3:
            red_ = 1;
            green_ = 0;
            blue_ = 0;
            break;
        case 4:
            red_ = 0;
            green_ = 1;
            blue_ = 0;
            break;
        case 5:
            red_ = 0;
            green_ = 0;
            blue_ = 1;
            break;
        case 6:
            red_ = 0.75;
            green_ = 0;
            blue_ = 1;
            break;
    }

    temp_y = Pieza_CPU.Y; //Guardar Posicion

    // Sombra
    while (Comprobar_Colisiones_Inferior_CPU() == 0)
    {
        Pieza_CPU.Y --;

        Ajustar_Colisiones_Actuales_CPU();
    }

    for (auxiliar = 0; auxiliar < 16; auxiliar++)
    {
        if (Colisiones_Actual_CPU[auxiliar] == 1)
        {
            if ((Limitar_int(0, 9,Pieza_CPU.X + (auxiliar % 4) - 1) == Pieza_CPU.X + (auxiliar % 4) - 1) && (Limitar_int(0, 16,Pieza_CPU.Y - (auxiliar / 4) + 1) == Pieza_CPU.Y - (auxiliar / 4) + 1))
            {
                Escenario_Tetris_CPU[Limitar_int(0, 9, Pieza_CPU.X + (auxiliar % 4) - 1)][Limitar_int(0, 16,Pieza_CPU.Y - (auxiliar / 4) + 1)].dibujar = 1;
                Escenario_Tetris_CPU[Limitar_int(0, 9, Pieza_CPU.X + (auxiliar % 4) - 1)][Limitar_int(0, 16,Pieza_CPU.Y - (auxiliar / 4) + 1)].red = red_;
                Escenario_Tetris_CPU[Limitar_int(0, 9, Pieza_CPU.X + (auxiliar % 4) - 1)][Limitar_int(0, 16,Pieza_CPU.Y - (auxiliar / 4) + 1)].green = green_;
                Escenario_Tetris_CPU[Limitar_int(0, 9, Pieza_CPU.X + (auxiliar % 4) - 1)][Limitar_int(0, 16,Pieza_CPU.Y - (auxiliar / 4) + 1)].blue = blue_;
            }
        }
    }

    Pieza_CPU.Y = temp_y; // Recuperar posicion

    for (auxiliar = 0; auxiliar < 16; auxiliar++) // Pieza
    {
        if (Colisiones_Actual_CPU[auxiliar] == 1)
        {
            if ((Limitar_int(0, 9, Pieza_CPU.X + (auxiliar % 4) - 1) == Pieza_CPU.X + (auxiliar % 4) - 1) && (Limitar_int(0, 16,Pieza_CPU.Y - (auxiliar / 4) + 1) == Pieza_CPU.Y - (auxiliar / 4) + 1))
            {
                Escenario_Tetris_CPU[Limitar_int(0, 9, Pieza_CPU.X + (auxiliar % 4) - 1)][Limitar_int(0, 16,Pieza_CPU.Y - (auxiliar / 4) + 1)].dibujar = 2;
                Escenario_Tetris_CPU[Limitar_int(0, 9, Pieza_CPU.X + (auxiliar % 4) - 1)][Limitar_int(0, 16,Pieza_CPU.Y - (auxiliar / 4) + 1)].red = red_;
                Escenario_Tetris_CPU[Limitar_int(0, 9, Pieza_CPU.X + (auxiliar % 4) - 1)][Limitar_int(0, 16,Pieza_CPU.Y - (auxiliar / 4) + 1)].green = green_;
                Escenario_Tetris_CPU[Limitar_int(0, 9, Pieza_CPU.X + (auxiliar % 4) - 1)][Limitar_int(0, 16,Pieza_CPU.Y - (auxiliar / 4) + 1)].blue = blue_;
            }
        }
    }
}

void Iniciar_Juego_CPU()
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

    for (auxiliar = 0; auxiliar < ANCHO_PIEZAS; auxiliar++)
    {
        for (auxiliar2 = 0; auxiliar2 < ALTO_PIEZAS + 2; auxiliar2++)
        {
            Escenario_Tetris_CPU[auxiliar][auxiliar2].dibujar = 0;
            Escenario_Tetris_CPU[auxiliar][auxiliar2].red = 0;
            Escenario_Tetris_CPU[auxiliar][auxiliar2].green = 0;
            Escenario_Tetris_CPU[auxiliar][auxiliar2].blue = 0;
        }
    }

    for (auxiliar = 0; auxiliar < ALTO_PIEZAS + 2; auxiliar++)
        Fila_Eliminada_CPU[auxiliar] = 0;

    // Preparar piezas
    for (auxiliar = 0;auxiliar < 5; auxiliar++)
        Tipo_Pieza_CPU[auxiliar] = PA_RandMinMax(0,6);

    Ajustar_Colisiones_Actuales_CPU();
    Dibujar_Pieza_Actual_CPU();

    for (auxiliar = 1;auxiliar <= 4; auxiliar++)
    {
        PA_CreateSprite(1, auxiliar + 50, (void*)Pieza_Sprite, OBJ_SIZE_16X32,1, 0, 234, 5 + (39 * (auxiliar - 1)));
        PA_SetSpriteAnim(1, auxiliar + 50, Tipo_Pieza_CPU[auxiliar]);
    }
}

void Nueva_Pieza_CPU()
{
    Pieza_CPU.Y = 16;
    Pieza_CPU.X = 4;
    Pieza_CPU.Rotacion = 0;

    reservausada_CPU = false;

    velocidadcount_CPU = 0;
    girarcount_CPU = 0;

    for (auxiliar = 0;auxiliar < 4; auxiliar++)
        Tipo_Pieza_CPU[auxiliar] = Tipo_Pieza_CPU[auxiliar + 1];

    Tipo_Pieza_CPU[4] = PA_RandMinMax(0, 6);

    Ajustar_Colisiones_Actuales_CPU();

    for (auxiliar = 1;auxiliar <= 4; auxiliar++)
        PA_SetSpriteAnim(1, auxiliar + 50, Tipo_Pieza_CPU[auxiliar]);
}

void Reservar_Pieza_CPU()
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

        auxiliar = piezareserva_CPU;
        piezareserva_CPU = Tipo_Pieza_CPU[0];
        Tipo_Pieza_CPU[0] = auxiliar;

        PA_SetSpriteAnim(1, NUMSPRITE_RESERVA_CPU, piezareserva_CPU);

        Pieza_CPU.Y = 16;
        Pieza_CPU.X = 4;
        Pieza_CPU.Rotacion = 0;

        velocidadcount_CPU = 0;
        girarcount_CPU = 0;

        Ajustar_Colisiones_Actuales_CPU();
    }
}
