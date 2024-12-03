#ifndef __HEADER1__
#define __HEADER1__

#include <PA9.h> 
#include <stdlib.h>
#include <stdio.h>
#include <nds/arm9/image.h>

// PAGfxConverter Include
//#include "../source/gfx/all_gfx.c"
#include "../source/gfx/all_gfx.h"

#include "Textura_Tetris_1_pcx.h"
#include "Textura_Tetris_2_pcx.h"
#include "Textura_Tetris_3_pcx.h"
#include "Textura_Tetris_4_pcx.h"
#include "Textura_Tetris_5_pcx.h"

#include "Textura_Escenario_1_pcx.h"
#include "Textura_Escenario_2_pcx.h"
#include "Textura_Escenario_Borde_pcx.h"

#include "Textura_Disco_Foco_pcx.h"
#include "Textura_Disco_Metal_pcx.h"
#include "Textura_Disco_Suelo_pcx.h"
#include "Textura_Disco_Pared_pcx.h"
#include "Textura_Disco_Asiento_pcx.h"

bool MENU_ACTIVO, JUEGO_ACTIVO, PAUSA;
u8 pausa_lista;
u8 MODO_DE_JUEGO;
int opcionmenu, submenu;
s32 puntuacion_total, /*puntuacion_record,*/ linecount, puntuacion_total_CPU, linecount_CPU;

u8 combo, combo_CPU;

typedef struct
	{
	char Nombre[10];
	u32 Puntuacion;
	u16 Lineas;
	} __RECORD_STRUCT__;

__RECORD_STRUCT__ Record[10];

bool UPDATE_2D;
u8 lasttime;

bool READY;

#define CAMERA_DISABLED		0
#define CAMERA_SLOW			1
#define CAMERA_QUICK		2

u8 texture_selected, camera_selected, USE_SOUND, MASTER_SOUND;

float velocidad;
int framecount, velocidadcount, girarcount, velocidadcount_CPU, girarcount_CPU;

u8 Caida_rapida_CPU, jugador_ganador;

float rotarsalaX, rotarsalaY, rotarsalaZ;
float fondorojo = 10, fondoverde = 15, fondoazul = 20;
float incrementorojo = 0.2, incrementoverde = 0.15, incrementoazul = 0.1;

//char nombre_record[10], nombre_jugador[10];

int auxiliar, acumulador, auxiliar2, auxiliar3, auxiliar4;
float auxiliar_float;

#define ANCHO_PIEZAS	10
#define ALTO_PIEZAS 	15
typedef struct
	{
	float red, green, blue;
	u8 dibujar;
	} CUBO_TETRIS;

int Fila_Eliminada[ALTO_PIEZAS + 2];
int Fila_Eliminada_CPU[ALTO_PIEZAS + 2];

typedef struct
	{
	s8 X, Y;
	u8 Rotacion;
	} PIEZA_TETRIS;
	
CUBO_TETRIS Escenario_Tetris[ANCHO_PIEZAS][ALTO_PIEZAS + 2];
CUBO_TETRIS Escenario_Tetris_CPU[ANCHO_PIEZAS][ALTO_PIEZAS + 2];
PIEZA_TETRIS Pieza;
PIEZA_TETRIS Pieza_CPU;

u8 Tipo_Pieza[5]; // 0 = Actual
u8 Tipo_Pieza_CPU[5];

u8 Colisiones_Actual[16]; //Cuadrícula
u8 Colisiones_Actual_CPU[16];

typedef struct
	{
	float red, redincrement;
	float green, greenincrement;
	float blue, blueincrement;
	} _TEXT_DATA_;

_TEXT_DATA_ Text_Color;

//Modos de juego
#define MODO_NORMAL     0
#define MODO_CONTRA_CPU 1


//Apagar la DS
void PowerOFF()
{
    systemShutDown();
}


u16 time_to_shutdown;

void PowerOFF_Countdown(u8 seconds)
{
time_to_shutdown = (seconds + 1) * 60;
PA_Init2D();
PA_ResetBgSys();
PA_InitCustomText(1, 0, custom_font); //2º = background number

while(time_to_shutdown > 0)
	{
	PA_OutputSimpleText(1,0,0,"Shutdown DS...  ");
	PA_OutputText(1,0,1,"%d seconds left.  ", time_to_shutdown/60);
	time_to_shutdown--;
	PA_WaitForVBL();
	}

PowerOFF();

PA_OutputText(1,0,2,"DS shouldn't be ON!!!");

while(1) PA_WaitForVBL();
}

// Valor absoluto para variables del tipo float
static inline float Float_Abs(float num)
{
    if (num < 0)
        return -num;
    return num;
}

static inline int Limitar_int(int min, int max, int numero)
{
    if (numero < min)
        return min;
    if (numero > max)
        return max;
    return numero;
}

static inline float Limitar_float(float min, float max, float numero)
{
    if (numero < min)
        return min;
    if (numero > max)
        return max;
    return numero;
}

#define TEXT_SMALL		0
#define TEXT_MEDIUM		1
#define TEXT_BIG		2


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


#include "keys_control.h"
#include "My_FAT.h"
#include "music.cpp"
#include "GRAFICOS_3D/GRAPHICS3D.h"
#include "cambiar_formato_nombre.h"

#include "MODOS_DE_JUEGO/JUEGO.h"

#include "Menu.cpp"

#endif


