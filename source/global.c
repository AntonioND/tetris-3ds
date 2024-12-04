#include <PA9.h>

#include "global.h"

// PAGfxConverter Include
#include "gfx/all_gfx.h"

bool MENU_ACTIVO, JUEGO_ACTIVO, PAUSA;
u8 pausa_lista;
u8 MODO_DE_JUEGO;
int opcionmenu, submenu;
s32 puntuacion_total, /*puntuacion_record,*/ linecount, puntuacion_total_CPU, linecount_CPU;

u8 combo, combo_CPU;

__RECORD_STRUCT__ Record[10];

bool UPDATE_2D;
u8 lasttime;

bool READY;

u8 texture_selected, camera_selected, USE_SOUND, MASTER_SOUND;

float velocidad;
int framecount, velocidadcount, girarcount, velocidadcount_CPU, girarcount_CPU;

u8 Caida_rapida_CPU, jugador_ganador;

float rotarsalaX, rotarsalaY, rotarsalaZ;
float fondorojo = 10, fondoverde = 15, fondoazul = 20;
float incrementorojo = 0.2, incrementoverde = 0.15, incrementoazul = 0.1;

//char nombre_record[10], nombre_jugador[10];

int auxiliar, acumulador, auxiliar2, auxiliar3, auxiliar4;

int Fila_Eliminada[ALTO_PIEZAS + 2];
int Fila_Eliminada_CPU[ALTO_PIEZAS + 2];

CUBO_TETRIS Escenario_Tetris[ANCHO_PIEZAS][ALTO_PIEZAS + 2];
CUBO_TETRIS Escenario_Tetris_CPU[ANCHO_PIEZAS][ALTO_PIEZAS + 2];
PIEZA_TETRIS Pieza;
PIEZA_TETRIS Pieza_CPU;

u8 Tipo_Pieza[5]; // 0 = Actual
u8 Tipo_Pieza_CPU[5];

u8 Colisiones_Actual[16]; //Cuadrícula
u8 Colisiones_Actual_CPU[16];

_TEXT_DATA_ Text_Color;

void PowerOFF_Countdown(u8 seconds)
{
    int time_to_shutdown = (seconds + 1) * 60;
    PA_Init2D();
    PA_ResetBgSys();
    PA_InitCustomText(1, 0, custom_font); //2º = background number

    while (time_to_shutdown > 0)
    {
        PA_OutputSimpleText(1, 0, 0, "Shutdown DS...  ");
        PA_OutputText(1, 0, 1, "%d seconds left.  ", time_to_shutdown / 60);
        time_to_shutdown--;
        PA_WaitForVBL();
    }

    systemShutDown();

    PA_OutputText(1,0,2,"DS shouldn't be ON!!!");

    while (1)
        PA_WaitForVBL();
}

void Reset_Records()
{
    sprintf(Record[0].Nombre, "RECORD 1");
    Record[0].Puntuacion = 7000;
    Record[0].Lineas = 400;

    sprintf(Record[1].Nombre, "RECORD 2");
    Record[1].Puntuacion = 5000;
    Record[1].Lineas = 300;

    sprintf(Record[2].Nombre, "RECORD 3");
    Record[2].Puntuacion = 4500;
    Record[2].Lineas = 250;

    sprintf(Record[3].Nombre, "RECORD 4");
    Record[3].Puntuacion = 4000;
    Record[3].Lineas = 200;

    sprintf(Record[4].Nombre, "RECORD 5");
    Record[4].Puntuacion = 3400;
    Record[4].Lineas = 150;

    sprintf(Record[5].Nombre, "RECORD 6");
    Record[5].Puntuacion = 2500;
    Record[5].Lineas = 100;

    sprintf(Record[6].Nombre, "RECORD 7");
    Record[6].Puntuacion = 1300;
    Record[6].Lineas = 75;

    sprintf(Record[7].Nombre, "RECORD 8");
    Record[7].Puntuacion = 700;
    Record[7].Lineas = 50;

    sprintf(Record[8].Nombre, "RECORD 9");
    Record[8].Puntuacion = 400;
    Record[8].Lineas = 25;

    sprintf(Record[9].Nombre, "RECORD 10");
    Record[9].Puntuacion = 100;
    Record[9].Lineas = 10;
}
