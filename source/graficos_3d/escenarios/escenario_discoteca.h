#ifndef GRAFICOS_3D_ESCENARIOS_ESCENARIO_DISCOTECA_H__
#define GRAFICOS_3D_ESCENARIOS_ESCENARIO_DISCOTECA_H__

#include <nds.h>

#define TEXTURA_SUELO	1
#define TEXTURA_PAREDES	2
#define TEXTURA_ASIENTO	3
#define TEXTURA_METAL	4
#define TEXTURA_FOCO	5

typedef struct
{
    float red, green, blue, ired, igreen, iblue;
} _RGB_I_;

extern _RGB_I_ focoder[3];
extern _RGB_I_ focoizq[3];

typedef struct
{
    int rotx, rotz, tiemporestante;
} __LUZ__;

extern __LUZ__ luz[5];

typedef struct
{
    float X, Y, Z;
    float IncX, IncY, IncZ;
} __ROT_STRUCT__;

extern __ROT_STRUCT__ Rot_Sala;

void Draw_Sujetabola();

void Draw_Foco1Izq(float red, float green, float blue);
void Draw_Foco2Izq(float red, float green, float blue);
void Draw_Foco3Izq(float red, float green, float blue);

void Draw_Bola();

void Draw_Foco1Der(float red, float green, float blue);
void Draw_Foco2Der(float red, float green, float blue);
void Draw_Foco3Der(float red, float green, float blue);

void Draw_Sala();

void Draw_AsientoDer();
void Draw_AsientoIzq();

extern int value_song;

void Dibujar_Discoteca(u8 pausa, u8 camara);

void Iniciar_Focos();

void Actualizar_Focos();

#endif // GRAFICOS_3D_ESCENARIOS_ESCENARIO_DISCOTECA_H__
