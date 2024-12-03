#ifndef __HEADER1__
#define __HEADER1__

#include <PA9.h> 
#include <stdlib.h>
#include <stdio.h>
#include <nds/arm9/image.h>

// PAGfxConverter Include
//#include "../source/gfx/all_gfx.c"
#include "../source/gfx/all_gfx.h"

#include "cambiar_formato_nombre.h"
#include "graficos_3d/graphics3d.h"
#include "keys_control.h"

#include "global.h"

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


#include "My_FAT.h"
#include "music.cpp"
#include "GRAFICOS_3D/GRAPHICS3D.h"

#include "MODOS_DE_JUEGO/JUEGO.h"

#include "Menu.cpp"

#endif


