#include <PA9.h>

#include "global.h"
#include "modos_de_juego/juego.h"

// PAGfxConverter Include
#include "gfx/all_gfx.h"

int temp_y, temp_x, temp_giro;

#define NUMSPRITE_RESERVA 15

static u8 piezareserva;
static bool reservallena, reservausada;

#define PAD_UP      1
#define PAD_DOWN    2

static u8 stylus_usedgravity, stylus_reservausada, stylus_dblclicused;
static u8 stylus_time, stylus_piezax;

void Controles_Tactiles_Horizontal(void)
{
    stylus_piezax = Stylus.Y * 10 / 192;

    if (Stylus.Held)
        stylus_time++;
    else
        stylus_time = 0;

    if ((stylus_time % 5 == 0) && (Stylus.Held) && (Stylus.X > 63) && (Float_Abs(Stylus.Vx) < 10))
    {
        if (Pieza.X < stylus_piezax)
        {
            Pad.Newpress.Down = 1;
        }
        else if (Pieza.X > stylus_piezax)
        {
            Pad.Newpress.Up = 1;
        }
    }

    // Girar
    if ((Stylus.DblClick) && (Stylus.Uptime < 30) && (stylus_dblclicused == 0))
    {
        Pad.Newpress.A = 1;
        stylus_dblclicused = 1;
    }
    else if ((Stylus.Newpress) && (stylus_dblclicused == 1))
    {
        stylus_dblclicused = 0;
    }

    // Caer rápido
    if ((Stylus.X < 63) && (Stylus.Held))
        Pad.Held.Left = 1;

    // Caer instantaneamente
    if ((Stylus.Vx < -15) && (Stylus.X < 63) && (Stylus.Held) && (stylus_usedgravity == 0))
    {
        stylus_usedgravity = 1;
        Pad.Newpress.Right = 1;
    }
    else if (Stylus.Vx > -2)
    {
        stylus_usedgravity = 0;
    }

    // Guardar pieza en la reserva
    if ((Stylus.Vx > 15) && (Stylus.X > 191) && (Stylus.Held) && (stylus_reservausada == 0))
    {
        stylus_reservausada = 1;
        Pad.Newpress.X = 1;
    }
    else if (Stylus.Vx < 2)
    {
        stylus_reservausada = 0;
    }

    if (Stylus.Released)
    {
        Stylus.X = 128;
        Stylus.Y = 92;
    }
}

void Controles_Tactiles_Vertical(void)
{
    stylus_piezax = Stylus.X * 10 / 256;

    if (Stylus.Held)
        stylus_time++;
    else
        stylus_time = 0;

    if ((stylus_time % 5 == 0) && (Stylus.Held) && (Stylus.Y < 160) && (Float_Abs(Stylus.Vy) < 10))
    {
        if (Pieza.X < stylus_piezax)
        {
            Pad.Newpress.Right = 1;
        }
        else if (Pieza.X > stylus_piezax)
        {
            Pad.Newpress.Left = 1;
        }
    }

    // Girar
    if ((Stylus.DblClick) && (Stylus.Uptime < 30) && (stylus_dblclicused == 0))
    {
        Pad.Newpress.A = 1;
        stylus_dblclicused = 1;
    }
    else if ((Stylus.Newpress) && (stylus_dblclicused == 1))
    {
        stylus_dblclicused = 0;
    }

    // Caer rápido
    if ((Stylus.Y > 160) && (Stylus.Held))
        Pad.Held.Down = 1;

    // Caer instantaneamente
    if ((Stylus.Vy > 15) && (Stylus.Y > 160) && (Stylus.Held) && (stylus_usedgravity == 0))
    {
        stylus_usedgravity = 1;
        Pad.Newpress.Up = 1;
    }
    else if (Stylus.Vy < 2)
    {
        stylus_usedgravity = 0;
    }

    // Guardar pieza en la reserva
    if ((Stylus.Vy < -15) && (Stylus.Y < 32) && (Stylus.Held) && (stylus_reservausada == 0))
    {
        stylus_reservausada = 1;
        Pad.Newpress.X = 1;
    }
    else if (Stylus.Vy > -2)
    {
        stylus_reservausada = 0;
    }

    if (Stylus.Released)
    {
        Stylus.X = 128;
        Stylus.Y = 92;
    }
}

int lastkeypressed, timepressed;

void Autofire_Keys_Horizontal(void)
{
    if (Pad.Held.Up)
    {
        if (lastkeypressed == PAD_UP)
        {
            timepressed++;
        }
        else
        {
            lastkeypressed = PAD_UP;
            timepressed = 0;
        }
    }
    else if (Pad.Held.Down)
    {
        if (lastkeypressed == PAD_DOWN)
        {
            timepressed++;
        }
        else
        {
            lastkeypressed = PAD_DOWN;
            timepressed = 0;
        }
    }
    else
    {
        timepressed = 0;
    }

    if ((timepressed % 5 == 0) && (timepressed > 10))
    {
        if (lastkeypressed == PAD_DOWN)
            Pad.Newpress.Down = 1;
        else if (lastkeypressed == PAD_UP)
            Pad.Newpress.Up = 1;
    }
}

void Autofire_Keys_Vertical(void)
{
    if (Pad.Held.Left)
    {
        if (lastkeypressed == PAD_UP)
        {
            timepressed++;
        }
        else
        {
            lastkeypressed = PAD_UP;
            timepressed = 0;
        }
    }
    else if (Pad.Held.Right)
    {
        if (lastkeypressed == PAD_DOWN)
        {
            timepressed++;
        }
        else
        {
            lastkeypressed = PAD_DOWN;
            timepressed = 0;
        }
    }
    else
    {
        timepressed = 0;
    }

    if ((timepressed % 5 == 0) && (timepressed > 10))
    {
        if (lastkeypressed == PAD_DOWN)
            Pad.Newpress.Right = 1;
        else if (lastkeypressed == PAD_UP)
            Pad.Newpress.Left = 1;
    }
}

void Cancelar_Animacion_Eliminar_Lineas(void)
{
    for (int i = 0; i < ALTO_PIEZAS + 2; i++)
        Fila_Eliminada[i] = 0;
}

u8 Borrar_Lineas_Completas(void)
{
    Borrar_Pieza_Actual();

    int result = 0;
    for (int linea = ALTO_PIEZAS; linea > 0; linea--)
    {
        if (Comprobar_Linea(linea - 1))
        {
            result = 1;
            Borrar_Linea(linea - 1);
        }
    }

    // Ajustar_Colisiones_Actuales();
    Dibujar_Pieza_Actual();

    return result;
}

void Borrar_Linea(u8 altura)
{
    linecount += 1;

    for (int j = 0; j < ANCHO_PIEZAS; j++)
        Escenario_Tetris[j][altura].dibujar = 0;

    // Desplazar líneas hacia abajo
    for (int j = altura; j < ALTO_PIEZAS + 2; j++)
    {
        for (int i = 0; i < ANCHO_PIEZAS; i++)
        {
            Escenario_Tetris[i][j].dibujar = Escenario_Tetris[i][Limitar_int(0, 16, j + 1)].dibujar;
            Escenario_Tetris[i][j].red = Escenario_Tetris[i][Limitar_int(0, 16, j + 1)].red;
            Escenario_Tetris[i][j].green = Escenario_Tetris[i][Limitar_int(0, 16, j + 1)].green;
            Escenario_Tetris[i][j].blue = Escenario_Tetris[i][Limitar_int(0, 16, j + 1)].blue;
        }
    }

    // Borrar última linea
    for (int j = 0; j < ANCHO_PIEZAS; j++)
        Escenario_Tetris[j][16].dibujar = 0;
}

// Devuelve las líneas completas
u8 Comprobar_Lineas_Completas(void)
{
    int count = 0;

    for (int j = 0; j < ALTO_PIEZAS + 2; j++)
    {
        if (Comprobar_Linea(j) == 1)
        {
            Fila_Eliminada[j] = 30;
            count++;
        }
        else
        {
            Fila_Eliminada[j] --;
        }
    }

    return count;
}

u8 Comprobar_Linea(u8 altura)
{
    u32 sum = 0;

    for (int j = 0; j < ANCHO_PIEZAS; j++)
        sum += Estado_Cuadricula(j, altura);

    if (sum > 9)
        return 1;

    return 0;
}

void Ajustar_Colisiones_Actuales(void)
{
    for (int i = 0; i < 16; i++)
        Colisiones_Actual[i] = 0;

    switch (Tipo_Pieza[0])
    {
        case 0: // Pieza 0
            if ((Pieza.Rotacion == 0) || (Pieza.Rotacion == 2))
            {
                Colisiones_Actual[8] = 1;
                Colisiones_Actual[9] = 1;
                Colisiones_Actual[10] = 1;
                Colisiones_Actual[11] = 1;
            }
            else
            {
                Colisiones_Actual[1] = 1;
                Colisiones_Actual[5] = 1;
                Colisiones_Actual[9] = 1;
                Colisiones_Actual[13] = 1;
            }
            break;

        case 1: // Pieza 1
            if (Pieza.Rotacion == 0)
            {
                Colisiones_Actual[5] = 1;
                Colisiones_Actual[6] = 1;
                Colisiones_Actual[7] = 1;
                Colisiones_Actual[9] = 1;
            }
            else if (Pieza.Rotacion == 1)
            {
                Colisiones_Actual[1] = 1;
                Colisiones_Actual[5] = 1;
                Colisiones_Actual[9] = 1;
                Colisiones_Actual[10] = 1;
            }
            else if (Pieza.Rotacion == 2)
            {
                Colisiones_Actual[6] = 1;
                Colisiones_Actual[8] = 1;
                Colisiones_Actual[9] = 1;
                Colisiones_Actual[10] = 1;
            }
            else if (Pieza.Rotacion == 3)
            {
                Colisiones_Actual[5] = 1;
                Colisiones_Actual[6] = 1;
                Colisiones_Actual[10] = 1;
                Colisiones_Actual[14] = 1;
            }
            break;

        case 2: // Pieza 2
            if (Pieza.Rotacion == 0)
            {
                Colisiones_Actual[5] = 1;
                Colisiones_Actual[9] = 1;
                Colisiones_Actual[10] = 1;
                Colisiones_Actual[11] = 1;
            }
            else if (Pieza.Rotacion == 1)
            {
                Colisiones_Actual[2] = 1;
                Colisiones_Actual[6] = 1;
                Colisiones_Actual[9] = 1;
                Colisiones_Actual[10] = 1;
            }
            else if (Pieza.Rotacion == 2)
            {
                Colisiones_Actual[4] = 1;
                Colisiones_Actual[5] = 1;
                Colisiones_Actual[6] = 1;
                Colisiones_Actual[10] = 1;
            }
            else if(Pieza.Rotacion == 3)
            {
                Colisiones_Actual[5] = 1;
                Colisiones_Actual[6] = 1;
                Colisiones_Actual[9] = 1;
                Colisiones_Actual[13] = 1;
            }
            break;

        case 3: // Pieza 3
            if ((Pieza.Rotacion == 0) || (Pieza.Rotacion == 2))
            {
                Colisiones_Actual[4] = 1;
                Colisiones_Actual[5] = 1;
                Colisiones_Actual[9] = 1;
                Colisiones_Actual[10] = 1;
            }
            else
            {
                Colisiones_Actual[2] = 1;
                Colisiones_Actual[5] = 1;
                Colisiones_Actual[6] = 1;
                Colisiones_Actual[9] = 1;
            }
            break;

        case 4: // Pieza 4
            if ((Pieza.Rotacion == 0) || (Pieza.Rotacion == 2))
            {
                Colisiones_Actual[5] = 1;
                Colisiones_Actual[6] = 1;
                Colisiones_Actual[8] = 1;
                Colisiones_Actual[9] = 1;
            }
            else
            {
                Colisiones_Actual[1] = 1;
                Colisiones_Actual[5] = 1;
                Colisiones_Actual[6] = 1;
                Colisiones_Actual[10] = 1;
            }
            break;

        case 5: // Pieza 5
            if (Pieza.Rotacion == 0)
            {
                Colisiones_Actual[1] = 1;
                Colisiones_Actual[4] = 1;
                Colisiones_Actual[5] = 1;
                Colisiones_Actual[6] = 1;
            }
            else if (Pieza.Rotacion == 1)
            {
                Colisiones_Actual[1] = 1;
                Colisiones_Actual[4] = 1;
                Colisiones_Actual[5] = 1;
                Colisiones_Actual[9] = 1;
            }
            else if (Pieza.Rotacion == 2)
            {
                Colisiones_Actual[4] = 1;
                Colisiones_Actual[5] = 1;
                Colisiones_Actual[6] = 1;
                Colisiones_Actual[9] = 1;
            }
            else if (Pieza.Rotacion == 3)
            {
                Colisiones_Actual[1] = 1;
                Colisiones_Actual[5] = 1;
                Colisiones_Actual[6] = 1;
                Colisiones_Actual[9] = 1;
            }
            break;

        case 6: // Pieza 6
            Colisiones_Actual[5] = 1;
            Colisiones_Actual[6] = 1;
            Colisiones_Actual[9] = 1;
            Colisiones_Actual[10] = 1;
            break;
    }
}

// Devuelve 1 si está ocupado, 0 si no. Los bordes cuentan como 1.
u8 Estado_Cuadricula(int x, int y)
{
    if ((Limitar_int(0, 9, x) != x) || (y < 0))
        return 1;
    else if (y > 16)
        return 0;
    else
        return (Limitar_int(0, 1, Escenario_Tetris[x][y].dibujar - 1));
}

u8 Comprobar_Colisiones_Inferior(void)
{
    for (int i = 0; i < 16; i++) // Pieza
    {
        if (Colisiones_Actual[i] == 1)
        {
            // Si el siguiente esta vacio y está a la abajo
            if ((Colisiones_Actual[i + 4] == 0) || (i / 4 == 3) )
            {
                if (Limitar_int(0, 9, Pieza.X + (i % 4) - 1) == Pieza.X + (i % 4) - 1)
                {
                    if (Estado_Cuadricula(Pieza.X + (i % 4) - 1, Pieza.Y - (i / 4)))
                        return 1;
                }
            }
        }
    }

    return 0;
}

u8 Comprobar_Colisiones_Derecha(void)
{
    for (int i = 0; i < 16; i++) // Pieza
    {
        if (Colisiones_Actual[i] == 1)
        {
            // Si el siguiente esta vacio y está a la derecha
            if ((Colisiones_Actual[i + 1] == 0) || (i % 4 == 3) )
            {
                //if (Limitar_int(0, 16, Pieza.Y + (i / 4) - 1) == Pieza.Y + (i / 4) - 1)
                //{
                    if (Estado_Cuadricula(Pieza.X + (i % 4), Pieza.Y - (i / 4) + 1))
                        return 1;
                //}
            }
        }
    }

    return 0;
}

u8 Comprobar_Colisiones_Izquierda(void)
{
    for (int i = 0; i < 16; i++) // Pieza
    {
        if (Colisiones_Actual[i] == 1)
        {
            // Si el siguiente esta vacio y está a la derecha
            if ((Colisiones_Actual[i - 1] == 0) || (i % 4 == 0) )
            {
                //if (Limitar_int(0, 16, Pieza.Y + (i / 4) - 1) == Pieza.Y + (i / 4) - 1)
                //{
                    if (Estado_Cuadricula(Pieza.X + (i % 4) - 2, Pieza.Y - (i / 4) + 1))
                        return 1;
                //}
            }
        }
    }

    return 0;
}

u8 Comprobar_Colisiones_Giro(void)
{
    Borrar_Pieza_Actual();

    temp_giro = Pieza.Rotacion;
    temp_y = Pieza.Y;
    temp_x = Pieza.X;
    Pieza.Rotacion = (Pieza.Rotacion + 1) % 4;

    Ajustar_Colisiones_Actuales();

    u32 result = 0;

    for (int i = 0; i < 16; i++) // Pieza
    {
        if (Colisiones_Actual[i] == 1)
        {
            if (Estado_Cuadricula(Pieza.X + (i % 4) - 1, Pieza.Y - (i / 4) + 1))
                result = 1;
        }
    }

    // Probar subiendo la pieza una posición
    if (result == 1)
    {
        result = 2;
        Pieza.Y++;

        Ajustar_Colisiones_Actuales();

        for (int i = 0; i < 16; i++) // Pieza
        {
            if (Colisiones_Actual[i] == 1)
            {
                if (Estado_Cuadricula(Pieza.X + (i % 4) - 1, Pieza.Y - (i / 4) + 1))
                    result = 1;
            }
        }

        Pieza.Y--;
    }

    Ajustar_Colisiones_Actuales();

    // Probar moviendo a los lados
    if (result == 1)
    {
        // Probar a la derecha
        if (Comprobar_Colisiones_Izquierda() == 1)
        {
            result = 3;
            Pieza.X++;

            Ajustar_Colisiones_Actuales();
        }
        else if (Comprobar_Colisiones_Derecha() == 1)
        {
            result = 4;
            Pieza.X--;
            if (Tipo_Pieza[0] == 0)
                Pieza.X --; // si es la alargada prueba una posicion mas.

            Ajustar_Colisiones_Actuales();
        }

        for (int i = 0; i < 16; i++) // Pieza
        {
            if (Colisiones_Actual[i] == 1)
            {
                if (Estado_Cuadricula(Pieza.X + (i % 4) - 1, Pieza.Y - (i / 4) + 1))
                    result = 1;
            }
        }

        Pieza.X = temp_x;
    }

    Pieza.Rotacion = temp_giro;
    Pieza.Y = temp_y;
    Pieza.X = temp_x;

    Ajustar_Colisiones_Actuales();
    Dibujar_Pieza_Actual();

    return result;
}

void Borrar_Pieza_Actual(void)
{
    temp_y = Pieza.Y;
    // Sombra
    Ajustar_Colisiones_Actuales();

    while (Comprobar_Colisiones_Inferior() == 0)
    {
        Pieza.Y--;

        Ajustar_Colisiones_Actuales();
    }

    for (int i = 0; i < 16; i++) // Pieza
    {
        if (Colisiones_Actual[i] == 1)
        {
            if ((Limitar_int(0, 9, Pieza.X + (i % 4) - 1) == Pieza.X + (i % 4) - 1) &&
                (Limitar_int(0, 16,Pieza.Y - (i / 4) + 1) == Pieza.Y - (i / 4) + 1))
            {
                Escenario_Tetris[Limitar_int(0, 9, Pieza.X + (i % 4) - 1)]
                                [Limitar_int(0, 16,Pieza.Y - (i / 4) + 1)].dibujar = 0;
            }
        }
    }

    Pieza.Y = temp_y; // Recuperar posicion

    for (int i = 0; i < 16; i++) // Pieza
    {
        if (Colisiones_Actual[i] == 1)
        {
            if ((Limitar_int(0, 9, Pieza.X + (i % 4) - 1) == Pieza.X + (i % 4) - 1) &&
                (Limitar_int(0, 16,Pieza.Y - (i / 4) + 1) == Pieza.Y - (i / 4) + 1))
            {
                Escenario_Tetris[Limitar_int(0, 9,Pieza.X + (i % 4) - 1)]
                                [Limitar_int(0, 16,Pieza.Y - (i / 4) + 1)].dibujar = 0;
            }
        }
    }
}

void Dibujar_Pieza_Actual(void)
{
    float red = 0, green = 0, blue = 0;

    // Pieza actual
    switch (Tipo_Pieza[0]) // Color
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

    temp_y = Pieza.Y; // Guardar Posicion

    // Sombra
    while (Comprobar_Colisiones_Inferior() == 0)
    {
        Pieza.Y--;

        Ajustar_Colisiones_Actuales();
    }

    for (int i = 0; i < 16; i++)
    {
        if (Colisiones_Actual[i] == 1)
        {
            if ((Limitar_int(0, 9, Pieza.X + (i % 4) - 1) == Pieza.X + (i % 4) - 1) &&
                (Limitar_int(0, 16,Pieza.Y - (i / 4) + 1) == Pieza.Y - (i / 4) + 1))
            {
                Escenario_Tetris[Limitar_int(0, 9, Pieza.X + (i % 4) - 1)]
                                [Limitar_int(0, 16,Pieza.Y - (i / 4) + 1)].dibujar = 1;
                Escenario_Tetris[Limitar_int(0, 9, Pieza.X + (i % 4) - 1)]
                                [Limitar_int(0, 16,Pieza.Y - (i / 4) + 1)].red = red;
                Escenario_Tetris[Limitar_int(0, 9, Pieza.X + (i % 4) - 1)]
                                [Limitar_int(0, 16,Pieza.Y - (i / 4) + 1)].green = green;
                Escenario_Tetris[Limitar_int(0, 9, Pieza.X + (i % 4) - 1)]
                                [Limitar_int(0, 16,Pieza.Y - (i / 4) + 1)].blue = blue;
            }
        }
    }

    Pieza.Y = temp_y; // Recuperar posicion

    for (int i = 0; i < 16; i++) // Pieza
    {
        if (Colisiones_Actual[i] == 1)
        {
            if ((Limitar_int(0, 9, Pieza.X + (i % 4) - 1) == Pieza.X + (i % 4) - 1) &&
                (Limitar_int(0, 16,Pieza.Y - (i / 4) + 1) == Pieza.Y - (i / 4) + 1))
            {
                Escenario_Tetris[Limitar_int(0, 9, Pieza.X + (i % 4) - 1)]
                                [Limitar_int(0, 16,Pieza.Y - (i / 4) + 1)].dibujar = 2;
                Escenario_Tetris[Limitar_int(0, 9, Pieza.X + (i % 4) - 1)]
                                [Limitar_int(0, 16,Pieza.Y - (i / 4) + 1)].red = red;
                Escenario_Tetris[Limitar_int(0, 9, Pieza.X + (i % 4) - 1)]
                                [Limitar_int(0, 16,Pieza.Y - (i / 4) + 1)].green = green;
                Escenario_Tetris[Limitar_int(0, 9, Pieza.X + (i % 4) - 1)]
                                [Limitar_int(0, 16,Pieza.Y - (i / 4) + 1)].blue = blue;
            }
        }
    }
}

void Iniciar_Juego(void)
{
    Pieza.Y = 16;
    Pieza.X = 4;
    Pieza.Rotacion = 0;
    puntuacion_total = 0;
    linecount = 0;
    girarcount = 0;

    rotarsalaZ = 0;

    fondorojo = 10, fondoverde = 15, fondoazul = 20;
    incrementorojo = 0.2, incrementoverde = 0.15, incrementoazul = 0.1;

    piezareserva = 0;
    combo = 0;
    reservallena = false;
    reservausada = false;

    velocidad = 50;
    framecount = 0;
    velocidadcount = 0;

    for (int i = 0; i < ANCHO_PIEZAS; i++)
    {
        for (int j = 0; j < ALTO_PIEZAS + 2; j++)
        {
            Escenario_Tetris[i][j].dibujar = 0;
            Escenario_Tetris[i][j].red = 0;
            Escenario_Tetris[i][j].green = 0;
            Escenario_Tetris[i][j].blue = 0;
        }
    }

    for (int j = 0; j < ALTO_PIEZAS + 2; j++)
        Fila_Eliminada[j] = 0;

    // Preparar piezas
    for (int i = 0; i < 5; i++)
        Tipo_Pieza[i] = PA_RandMinMax(0, 6);

    Ajustar_Colisiones_Actuales();
    Dibujar_Pieza_Actual();

    switch (MODO_DE_JUEGO)
    {
        case MODO_NORMAL:
            PA_LoadSpritePal(1, 0, (void *)Pieza_Pal); // Palette name

            for (int i = 1; i <= 4; i++)
            {
                PA_CreateSprite(1, i, (void *)Pieza_Sprite, OBJ_SIZE_16X32, 1, 0, 173, 7 + (39 * (i - 1)));
                PA_SetSpriteAnim(1, i, Tipo_Pieza[i]);
            }
            break;

        case MODO_CONTRA_CPU:
            PA_LoadSpritePal(1, 0,(void *)Pieza_Pal); // Palette name

            for (int i = 1; i <= 4; i++)
            {
                PA_CreateSprite(1, i, (void *)Pieza_Sprite, OBJ_SIZE_16X32, 1, 0, 4, 5 + (39 * (i - 1)));
                PA_SetSpriteAnim(1, i, Tipo_Pieza[i]);
            }
            break;
    }
}

void Nueva_Pieza(void)
{
    Pieza.Y = 16;
    Pieza.X = 4;
    Pieza.Rotacion = 0;

    reservausada = false;

    velocidadcount = 0;
    girarcount = 0;

    for (int i = 0; i < 4; i++)
        Tipo_Pieza[i] = Tipo_Pieza[i + 1];

    Tipo_Pieza[4] = PA_RandMinMax(0,6);

    Ajustar_Colisiones_Actuales();

    for (int i = 1; i <= 4; i++)
        PA_SetSpriteAnim(1, i, Tipo_Pieza[i]);
}

void Reservar_Pieza(void)
{
    Borrar_Pieza_Actual();

    if (!reservallena)
    {
        piezareserva = Tipo_Pieza[0];

        reservallena = true;

        switch (MODO_DE_JUEGO)
        {
            case MODO_NORMAL:
                PA_CreateSprite(1, NUMSPRITE_RESERVA, (void *)Pieza_Sprite, OBJ_SIZE_16X32, 1, 0, 142, 26);
                break;

            case MODO_CONTRA_CPU:
                PA_CreateSprite(1, NUMSPRITE_RESERVA, (void *)Pieza_Sprite, OBJ_SIZE_16X32, 1, 0, 28, 28);
                break;
        }

        PA_SetSpriteAnim(1, NUMSPRITE_RESERVA, piezareserva);

        Nueva_Pieza();
        reservausada = true;
    }
    else if (!reservausada)
    {
        reservausada = true;

        int temp = piezareserva;
        piezareserva = Tipo_Pieza[0];
        Tipo_Pieza[0] = temp;

        PA_SetSpriteAnim(1, NUMSPRITE_RESERVA, piezareserva);

        Pieza.Y = 16;
        Pieza.X = 4;
        Pieza.Rotacion = 0;

        velocidadcount = 0;
        girarcount = 0;

        Ajustar_Colisiones_Actuales();
    }
}
