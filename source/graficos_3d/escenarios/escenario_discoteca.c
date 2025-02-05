// SPDX-License-Identifier: GPL-3.0-only
//
// Copyright (c) 2008, 2024-2025 Antonio Niño Díaz

#include <PA9.h>

#include "global.h"
#include "music.h"
#include "my_fat.h"
#include "graficos_3d/escenarios/escenarios.h"
#include "graficos_3d/escenarios/escenario_discoteca.h"
#include "graficos_3d/funciones_texturas.h"
#include "graficos_3d/objetos/figura_luz.h"

#define TEXTURA_SUELO   1
#define TEXTURA_PAREDES 2
#define TEXTURA_ASIENTO 3
#define TEXTURA_METAL   4
#define TEXTURA_FOCO    5

typedef struct {
    float red, green, blue, ired, igreen, iblue;
} _RGB_I_;

static _RGB_I_ focoder[3];
static _RGB_I_ focoizq[3];

typedef struct {
    int rotx, rotz, tiemporestante;
} __LUZ__;

static __LUZ__ luz[5];

typedef struct {
    float X, Y, Z;
    float IncX, IncY, IncZ;
} __ROT_STRUCT__;

static __ROT_STRUCT__ Rot_Sala;

static float girar_bola;

static int value_song;

void Draw_Sujetabola(void)
{
    glBindTexture(GL_TEXTURE_2D, 0);
    glColor3f(0.2, 0.2, 0.2);

    glBegin(GL_QUADS);

        glVertex3v16(409, 18539, 0);
        glVertex3v16(126, 20587, -389);
        glVertex3v16(409, 18539, 0);
        glVertex3v16(126, 18539, -389);

        glVertex3v16(126, 18539, -389);
        glVertex3v16(-331, 20587, -240);
        glVertex3v16(126, 18539, -389);
        glVertex3v16(-331, 18539, -240);

        glVertex3v16(-331, 18539, -240);
        glVertex3v16(-331, 20587, 240);
        glVertex3v16(-331, 18539, -240);
        glVertex3v16(-331, 18539, 240);

        glVertex3v16(-331, 18539, 240);
        glVertex3v16(126, 20587, 389);
        glVertex3v16(-331, 18539, 240);
        glVertex3v16(126, 18539, 389);

        glVertex3v16(126, 18539, 389);
        glVertex3v16(409, 20587, 0);
        glVertex3v16(126, 18539, 389);
        glVertex3v16(409, 18539, 0);

    glEnd();
}

void Draw_Foco1Izq(float red, float green, float blue)
{
    glBindTexture(GL_TEXTURE_2D, texture[TEXTURA_METAL]);

    glColor3f(0.5, 0.5, 0.5);

    glBegin(GL_TRIANGLES);

        glTexCoord2f(0.5, 0);
        glVertex3v16(14449, 18630, -7244);
        glTexCoord2f(1, 1);
        glVertex3v16(10401, 16972, -5708);
        glTexCoord2f(0, 1);
        glVertex3v16(12489, 14719, -5708);

        glTexCoord2f(0.5, 0);
        glVertex3v16(14449, 18630, -7244);
        glTexCoord2f(1, 1);
        glVertex3v16(12489, 14719, -5708);
        glTexCoord2f(0, 1);
        glVertex3v16(12489, 14719, -8780);

        glTexCoord2f(0.5, 0);
        glVertex3v16(14449, 18630, -7244);
        glTexCoord2f(1, 1);
        glVertex3v16(12489, 14719, -8780);
        glTexCoord2f(0, 1);
        glVertex3v16(10401, 16972, -8780);

        glTexCoord2f(0.5, 0);
        glVertex3v16(14449, 18630, -7244);
        glTexCoord2f(1, 1);
        glVertex3v16(10401, 16972, -8780);
        glTexCoord2f(0, 1);
        glVertex3v16(10401, 16972, -5708);

    glEnd();

    glBindTexture(GL_TEXTURE_2D, texture[TEXTURA_FOCO]);

    glColor3f(red, green, blue);

    glBegin(GL_QUADS);

        glTexCoord2f(0, 0);
        glVertex3v16(10401, 16972, -8780);
        glTexCoord2f(1, 0);
        glVertex3v16(12489, 14719, -8780);
        glTexCoord2f(1, 1);
        glVertex3v16(12489, 14719, -5708);
        glTexCoord2f(0, 1);
        glVertex3v16(10401, 16972, -5708);

    glEnd();

    glBindTexture(GL_TEXTURE_2D, 0);
}

void Draw_Foco2Izq(float red, float green, float blue)
{
    glBindTexture(GL_TEXTURE_2D, texture[TEXTURA_METAL]);

    glColor3f(0.5, 0.5, 0.5);

    glBegin(GL_TRIANGLES);

        glTexCoord2f(0.5, 0);
        glVertex3v16(14449, 18630, 134);
        glTexCoord2f(1, 1);
        glVertex3v16(10401, 16972, 1670);
        glTexCoord2f(0, 1);
        glVertex3v16(12489, 14719, 1670);

        glTexCoord2f(0.5, 0);
        glVertex3v16(14449, 18630, 134);
        glTexCoord2f(1, 1);
        glVertex3v16(12489, 14719, 1670);
        glTexCoord2f(0, 1);
        glVertex3v16(12489, 14719, -1401);

        glTexCoord2f(0.5, 0);
        glVertex3v16(14449, 18630, 134);
        glTexCoord2f(1, 1);
        glVertex3v16(12489, 14719, -1401);
        glTexCoord2f(0, 1);
        glVertex3v16(10401, 16972, -1401);

        glTexCoord2f(0.5, 0);
        glVertex3v16(14449, 18630, 134);
        glTexCoord2f(1, 1);
        glVertex3v16(10401, 16972, -1401);
        glTexCoord2f(0, 1);
        glVertex3v16(10401, 16972, 1670);

    glEnd();

    glBindTexture(GL_TEXTURE_2D, texture[TEXTURA_FOCO]);

    glColor3f(red, green, blue);

    glBegin(GL_QUADS);

        glTexCoord2f(0, 0);
        glVertex3v16(10401, 16972, -1401);
        glTexCoord2f(1, 0);
        glVertex3v16(12489, 14719, -1401);
        glTexCoord2f(1, 1);
        glVertex3v16(12489, 14719, 1670);
        glTexCoord2f(0, 1);
        glVertex3v16(10401, 16972, 1670);

    glEnd();

    glBindTexture(GL_TEXTURE_2D, 0);
}

void Draw_Foco3Izq(float red, float green, float blue)
{
    glBindTexture(GL_TEXTURE_2D, texture[TEXTURA_METAL]);

    glColor3f(0.5, 0.5, 0.5);

    glBegin(GL_TRIANGLES);

        glTexCoord2f(0.5, 0);
        glVertex3v16(14449, 18630, 7228);
        glTexCoord2f(1, 1);
        glVertex3v16(10401, 16972, 8764);
        glTexCoord2f(0, 1);
        glVertex3v16(12489, 14719, 8764);

        glTexCoord2f(0.5, 0);
        glVertex3v16(14449, 18630, 7228);
        glTexCoord2f(1, 1);
        glVertex3v16(12489, 14719, 8764);
        glTexCoord2f(0, 1);
        glVertex3v16(12489, 14719, 5692);

        glTexCoord2f(0.5, 0);
        glVertex3v16(14449, 18630, 7228);
        glTexCoord2f(1, 1);
        glVertex3v16(12489, 14719, 5692);
        glTexCoord2f(0, 1);
        glVertex3v16(10401, 16972, 5692);

        glTexCoord2f(0.5, 0);
        glVertex3v16(14449, 18630, 7228);
        glTexCoord2f(1, 1);
        glVertex3v16(10401, 16972, 5692);
        glTexCoord2f(0, 1);
        glVertex3v16(10401, 16972, 8764);

    glEnd();

    glBindTexture(GL_TEXTURE_2D, texture[TEXTURA_FOCO]);
    glColor3f(red, green, blue);
    glBegin(GL_QUADS);

        glTexCoord2f(0, 0);
        glVertex3v16(10401, 16972, 5692);
        glTexCoord2f(1, 0);
        glVertex3v16(12489, 14719, 5692);
        glTexCoord2f(1, 1);
        glVertex3v16(12489, 14719, 8764);
        glTexCoord2f(0, 1);
        glVertex3v16(10401, 16972, 8764);

    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);
}

void Draw_Bola(void)
{
    glBindTexture(GL_TEXTURE_2D, 0);

    glBegin(GL_TRIANGLES);

        // 1ª vuelta
        glColor3f(0.9, 0.9, 0.9);
        glVertex3v16(0, 19034, 0);
        glVertex3v16(0, 18723, -1567);
        glVertex3v16(-599, 18723, -1448);
        glColor3f(1, 1, 1);
        glVertex3v16(0, 19034, 0);
        glVertex3v16(-599, 18723, -1448);
        glVertex3v16(-1108, 18723, -1108);
        glColor3f(0.9, 0.9, 0.9);
        glVertex3v16(0, 19034, 0);
        glVertex3v16(-1108, 18723, -1108);
        glVertex3v16(-1448, 18723, -599);
        glColor3f(1, 1, 1);
        glVertex3v16(0, 19034, 0);
        glVertex3v16(-1448, 18723, -599);
        glVertex3v16(-1567, 18723, 0);
        glColor3f(0.9, 0.9, 0.9);
        glVertex3v16(0, 19034, 0);
        glVertex3v16(-1567, 18723, 0);
        glVertex3v16(-1448, 18723, 599);
        glColor3f(1, 1, 1);
        glVertex3v16(0, 19034, 0);
        glVertex3v16(-1448, 18723, 599);
        glVertex3v16(-1108, 18723, 1108);
        glColor3f(0.9, 0.9, 0.9);
        glVertex3v16(0, 19034, 0);
        glVertex3v16(-1108, 18723, 1108);
        glVertex3v16(-599, 18723, 1448);
        glColor3f(1, 1, 1);
        glVertex3v16(0, 19034, 0);
        glVertex3v16(-599, 18723, 1448);
        glVertex3v16(0, 18723, 1567);
        glColor3f(0.9, 0.9, 0.9);
        glVertex3v16(0, 19034, 0);
        glVertex3v16(0, 18723, 1567);
        glVertex3v16(599, 18723, 1448);
        glColor3f(1, 1, 1);
        glVertex3v16(0, 19034, 0);
        glVertex3v16(599, 18723, 1448);
        glVertex3v16(1108, 18723, 1108);
        glColor3f(0.9, 0.9, 0.9);
        glVertex3v16(0, 19034, 0);
        glVertex3v16(1108, 18723, 1108);
        glVertex3v16(1448, 18723, 599);
        glColor3f(1, 1, 1);
        glVertex3v16(0, 19034, 0);
        glVertex3v16(1448, 18723, 599);
        glVertex3v16(1567, 18723, 0);
        glColor3f(0.9, 0.9, 0.9);
        glVertex3v16(0, 19034, 0);
        glVertex3v16(1567, 18723, 0);
        glVertex3v16(1448, 18723, -599);
        glColor3f(1, 1, 1);
        glVertex3v16(0, 19034, 0);
        glVertex3v16(1448, 18723, -599);
        glVertex3v16(1108, 18723, -1108);
        glColor3f(0.9, 0.9, 0.9);
        glVertex3v16(0, 19034, 0);
        glVertex3v16(1108, 18723, -1108);
        glVertex3v16(599, 18723, -1448);
        glColor3f(1, 1, 1);
        glVertex3v16(0, 19034, 0);
        glVertex3v16(599, 18723, -1448);
        glVertex3v16(0, 18723, -1567);

        // 2ª vuelta
        glColor3f(1, 1, 1);
        glVertex3v16(0, 18723, -1567);
        glVertex3v16(0, 17835, -2896);
        glVertex3v16(-1108, 17835, -2675);
        glVertex3v16(0, 18723, -1567);
        glVertex3v16(-1108, 17835, -2675);
        glVertex3v16(-599, 18723, -1448);
        glColor3f(0.9, 0.9, 0.9);
        glVertex3v16(-599, 18723, -1448);
        glVertex3v16(-1108, 17835, -2675);
        glVertex3v16(-2048, 17835, -2048);
        glVertex3v16(-599, 18723, -1448);
        glVertex3v16(-2048, 17835, -2048);
        glVertex3v16(-1108, 18723, -1108);
        glColor3f(1, 1, 1);
        glVertex3v16(-1108, 18723, -1108);
        glVertex3v16(-2048, 17835, -2048);
        glVertex3v16(-2675, 17835, -1108);
        glVertex3v16(-1108, 18723, -1108);
        glVertex3v16(-2675, 17835, -1108);
        glVertex3v16(-1448, 18723, -599);
        glColor3f(0.9, 0.9, 0.9);
        glVertex3v16(-1448, 18723, -599);
        glVertex3v16(-2675, 17835, -1108);
        glVertex3v16(-2896, 17835, 0);
        glVertex3v16(-1448, 18723, -599);
        glVertex3v16(-2896, 17835, 0);
        glVertex3v16(-1567, 18723, 0);
        glColor3f(1, 1, 1);
        glVertex3v16(-1567, 18723, 0);
        glVertex3v16(-2896, 17835, 0);
        glVertex3v16(-2675, 17835, 1108);
        glVertex3v16(-1567, 18723, 0);
        glVertex3v16(-2675, 17835, 1108);
        glVertex3v16(-1448, 18723, 599);
        glColor3f(0.9, 0.9, 0.9);
        glVertex3v16(-1448, 18723, 599);
        glVertex3v16(-2675, 17835, 1108);
        glVertex3v16(-2048, 17835, 2047);
        glVertex3v16(-1448, 18723, 599);
        glVertex3v16(-2048, 17835, 2047);
        glVertex3v16(-1108, 18723, 1108);
        glColor3f(1, 1, 1);
        glVertex3v16(-1108, 18723, 1108);
        glVertex3v16(-2048, 17835, 2047);
        glVertex3v16(-1108, 17835, 2675);
        glVertex3v16(-1108, 18723, 1108);
        glVertex3v16(-1108, 17835, 2675);
        glVertex3v16(-599, 18723, 1448);
        glColor3f(0.9, 0.9, 0.9);
        glVertex3v16(-599, 18723, 1448);
        glVertex3v16(-1108, 17835, 2675);
        glVertex3v16(0, 17835, 2896);
        glVertex3v16(-599, 18723, 1448);
        glVertex3v16(0, 17835, 2896);
        glVertex3v16(0, 18723, 1567);
        glColor3f(1, 1, 1);
        glVertex3v16(0, 18723, 1567);
        glVertex3v16(0, 17835, 2896);
        glVertex3v16(1108, 17835, 2675);
        glVertex3v16(0, 18723, 1567);
        glVertex3v16(1108, 17835, 2675);
        glVertex3v16(599, 18723, 1448);
        glColor3f(0.9, 0.9, 0.9);
        glVertex3v16(599, 18723, 1448);
        glVertex3v16(1108, 17835, 2675);
        glVertex3v16(2048, 17835, 2047);
        glVertex3v16(599, 18723, 1448);
        glVertex3v16(2048, 17835, 2047);
        glVertex3v16(1108, 18723, 1108);
        glColor3f(1, 1, 1);
        glVertex3v16(1108, 18723, 1108);
        glVertex3v16(2048, 17835, 2047);
        glVertex3v16(2675, 17835, 1108);
        glVertex3v16(1108, 18723, 1108);
        glVertex3v16(2675, 17835, 1108);
        glVertex3v16(1448, 18723, 599);
        glColor3f(0.9, 0.9, 0.9);
        glVertex3v16(1448, 18723, 599);
        glVertex3v16(2675, 17835, 1108);
        glVertex3v16(2896, 17835, 0);
        glVertex3v16(1448, 18723, 599);
        glVertex3v16(2896, 17835, 0);
        glVertex3v16(1567, 18723, 0);
        glColor3f(1, 1, 1);
        glVertex3v16(1567, 18723, 0);
        glVertex3v16(2896, 17835, 0);
        glVertex3v16(2675, 17835, -1108);
        glVertex3v16(1567, 18723, 0);
        glVertex3v16(2675, 17835, -1108);
        glVertex3v16(1448, 18723, -599);
        glColor3f(0.9, 0.9, 0.9);
        glVertex3v16(1448, 18723, -599);
        glVertex3v16(2675, 17835, -1108);
        glVertex3v16(2047, 17835, -2048);
        glVertex3v16(1448, 18723, -599);
        glVertex3v16(2047, 17835, -2048);
        glVertex3v16(1108, 18723, -1108);
        glColor3f(1, 1, 1);
        glVertex3v16(1108, 18723, -1108);
        glVertex3v16(2047, 17835, -2048);
        glVertex3v16(1108, 17835, -2675);
        glVertex3v16(1108, 18723, -1108);
        glVertex3v16(1108, 17835, -2675);
        glVertex3v16(599, 18723, -1448);
        glColor3f(0.9, 0.9, 0.9);
        glVertex3v16(599, 18723, -1448);
        glVertex3v16(1108, 17835, -2675);
        glVertex3v16(0, 17835, -2896);
        glVertex3v16(599, 18723, -1448);
        glVertex3v16(0, 17835, -2896);
        glVertex3v16(0, 18723, -1567);

        // 3ª vuelta
        glColor3f(0.9, 0.9, 0.9);
        glVertex3v16(0, 17835, -2896);
        glVertex3v16(0, 16506, -3784);
        glVertex3v16(-1448, 16506, -3496);
        glVertex3v16(0, 17835, -2896);
        glVertex3v16(-1448, 16506, -3496);
        glVertex3v16(-1108, 17835, -2675);
        glColor3f(1, 1, 1);
        glVertex3v16(-1108, 17835, -2675);
        glVertex3v16(-1448, 16506, -3496);
        glVertex3v16(-2675, 16506, -2675);
        glVertex3v16(-1108, 17835, -2675);
        glVertex3v16(-2675, 16506, -2675);
        glVertex3v16(-2048, 17835, -2048);
        glColor3f(0.9, 0.9, 0.9);
        glVertex3v16(-2048, 17835, -2048);
        glVertex3v16(-2675, 16506, -2675);
        glVertex3v16(-3496, 16506, -1448);
        glVertex3v16(-2048, 17835, -2048);
        glVertex3v16(-3496, 16506, -1448);
        glVertex3v16(-2675, 17835, -1108);
        glColor3f(1, 1, 1);
        glVertex3v16(-2675, 17835, -1108);
        glVertex3v16(-3496, 16506, -1448);
        glVertex3v16(-3784, 16506, 0);
        glVertex3v16(-2675, 17835, -1108);
        glVertex3v16(-3784, 16506, 0);
        glVertex3v16(-2896, 17835, 0);
        glColor3f(0.9, 0.9, 0.9);
        glVertex3v16(-2896, 17835, 0);
        glVertex3v16(-3784, 16506, 0);
        glVertex3v16(-3496, 16506, 1448);
        glVertex3v16(-2896, 17835, 0);
        glVertex3v16(-3496, 16506, 1448);
        glVertex3v16(-2675, 17835, 1108);
        glColor3f(1, 1, 1);
        glVertex3v16(-2675, 17835, 1108);
        glVertex3v16(-3496, 16506, 1448);
        glVertex3v16(-2675, 16506, 2675);
        glVertex3v16(-2675, 17835, 1108);
        glVertex3v16(-2675, 16506, 2675);
        glVertex3v16(-2048, 17835, 2047);
        glColor3f(0.9, 0.9, 0.9);
        glVertex3v16(-2048, 17835, 2047);
        glVertex3v16(-2675, 16506, 2675);
        glVertex3v16(-1448, 16506, 3496);
        glVertex3v16(-2048, 17835, 2047);
        glVertex3v16(-1448, 16506, 3496);
        glVertex3v16(-1108, 17835, 2675);
        glColor3f(1, 1, 1);
        glVertex3v16(-1108, 17835, 2675);
        glVertex3v16(-1448, 16506, 3496);
        glVertex3v16(0, 16506, 3784);
        glVertex3v16(-1108, 17835, 2675);
        glVertex3v16(0, 16506, 3784);
        glVertex3v16(0, 17835, 2896);
        glColor3f(0.9, 0.9, 0.9);
        glVertex3v16(0, 17835, 2896);
        glVertex3v16(0, 16506, 3784);
        glVertex3v16(1448, 16506, 3496);
        glVertex3v16(0, 17835, 2896);
        glVertex3v16(1448, 16506, 3496);
        glVertex3v16(1108, 17835, 2675);
        glColor3f(1, 1, 1);
        glVertex3v16(1108, 17835, 2675);
        glVertex3v16(1448, 16506, 3496);
        glVertex3v16(2675, 16506, 2675);
        glVertex3v16(1108, 17835, 2675);
        glVertex3v16(2675, 16506, 2675);
        glVertex3v16(2048, 17835, 2047);
        glColor3f(0.9, 0.9, 0.9);
        glVertex3v16(2048, 17835, 2047);
        glVertex3v16(2675, 16506, 2675);
        glVertex3v16(3496, 16506, 1448);
        glVertex3v16(2048, 17835, 2047);
        glVertex3v16(3496, 16506, 1448);
        glVertex3v16(2675, 17835, 1108);
        glColor3f(1, 1, 1);
        glVertex3v16(2675, 17835, 1108);
        glVertex3v16(3496, 16506, 1448);
        glVertex3v16(3784, 16506, 0);
        glVertex3v16(2675, 17835, 1108);
        glVertex3v16(3784, 16506, 0);
        glVertex3v16(2896, 17835, 0);
        glColor3f(0.9, 0.9, 0.9);
        glVertex3v16(2896, 17835, 0);
        glVertex3v16(3784, 16506, 0);
        glVertex3v16(3496, 16506, -1448);
        glVertex3v16(2896, 17835, 0);
        glVertex3v16(3496, 16506, -1448);
        glVertex3v16(2675, 17835, -1108);
        glColor3f(1, 1, 1);
        glVertex3v16(2675, 17835, -1108);
        glVertex3v16(3496, 16506, -1448);
        glVertex3v16(2675, 16506, -2675);
        glVertex3v16(2675, 17835, -1108);
        glVertex3v16(2675, 16506, -2675);
        glVertex3v16(2047, 17835, -2048);
        glColor3f(0.9, 0.9, 0.9);
        glVertex3v16(2047, 17835, -2048);
        glVertex3v16(2675, 16506, -2675);
        glVertex3v16(1448, 16506, -3496);
        glVertex3v16(2047, 17835, -2048);
        glVertex3v16(1448, 16506, -3496);
        glVertex3v16(1108, 17835, -2675);
        glColor3f(1, 1, 1);
        glVertex3v16(1108, 17835, -2675);
        glVertex3v16(1448, 16506, -3496);
        glVertex3v16(0, 16506, -3784);
        glVertex3v16(1108, 17835, -2675);
        glVertex3v16(0, 16506, -3784);
        glVertex3v16(0, 17835, -2896);

        // 4ª vuelta
        glColor3f(1, 1, 1);
        glVertex3v16(0, 16506, -3784);
        glVertex3v16(0, 14938, -4096);
        glVertex3v16(-1567, 14938, -3784);
        glVertex3v16(0, 16506, -3784);
        glVertex3v16(-1567, 14938, -3784);
        glVertex3v16(-1448, 16506, -3496);
        glColor3f(0.9, 0.9, 0.9);
        glVertex3v16(-1448, 16506, -3496);
        glVertex3v16(-1567, 14938, -3784);
        glVertex3v16(-2896, 14938, -2896);
        glVertex3v16(-1448, 16506, -3496);
        glVertex3v16(-2896, 14938, -2896);
        glVertex3v16(-2675, 16506, -2675);
        glColor3f(1, 1, 1);
        glVertex3v16(-2675, 16506, -2675);
        glVertex3v16(-2896, 14938, -2896);
        glVertex3v16(-3784, 14938, -1567);
        glVertex3v16(-2675, 16506, -2675);
        glVertex3v16(-3784, 14938, -1567);
        glVertex3v16(-3496, 16506, -1448);
        glColor3f(0.9, 0.9, 0.9);
        glVertex3v16(-3496, 16506, -1448);
        glVertex3v16(-3784, 14938, -1567);
        glVertex3v16(-4096, 14938, 0);
        glVertex3v16(-3496, 16506, -1448);
        glVertex3v16(-4096, 14938, 0);
        glVertex3v16(-3784, 16506, 0);
        glColor3f(1, 1, 1);
        glVertex3v16(-3784, 16506, 0);
        glVertex3v16(-4096, 14938, 0);
        glVertex3v16(-3784, 14938, 1567);
        glVertex3v16(-3784, 16506, 0);
        glVertex3v16(-3784, 14938, 1567);
        glVertex3v16(-3496, 16506, 1448);
        glColor3f(0.9, 0.9, 0.9);
        glVertex3v16(-3496, 16506, 1448);
        glVertex3v16(-3784, 14938, 1567);
        glVertex3v16(-2896, 14938, 2896);
        glVertex3v16(-3496, 16506, 1448);
        glVertex3v16(-2896, 14938, 2896);
        glVertex3v16(-2675, 16506, 2675);
        glColor3f(1, 1, 1);
        glVertex3v16(-2675, 16506, 2675);
        glVertex3v16(-2896, 14938, 2896);
        glVertex3v16(-1567, 14938, 3784);
        glVertex3v16(-2675, 16506, 2675);
        glVertex3v16(-1567, 14938, 3784);
        glVertex3v16(-1448, 16506, 3496);
        glColor3f(0.9, 0.9, 0.9);
        glVertex3v16(-1448, 16506, 3496);
        glVertex3v16(-1567, 14938, 3784);
        glVertex3v16(0, 14938, 4096);
        glVertex3v16(-1448, 16506, 3496);
        glVertex3v16(0, 14938, 4096);
        glVertex3v16(0, 16506, 3784);
        glColor3f(1, 1, 1);
        glVertex3v16(0, 16506, 3784);
        glVertex3v16(0, 14938, 4096);
        glVertex3v16(1567, 14938, 3784);
        glVertex3v16(0, 16506, 3784);
        glVertex3v16(1567, 14938, 3784);
        glVertex3v16(1448, 16506, 3496);
        glColor3f(0.9, 0.9, 0.9);
        glVertex3v16(1448, 16506, 3496);
        glVertex3v16(1567, 14938, 3784);
        glVertex3v16(2896, 14938, 2896);
        glVertex3v16(1448, 16506, 3496);
        glVertex3v16(2896, 14938, 2896);
        glVertex3v16(2675, 16506, 2675);
        glColor3f(1, 1, 1);
        glVertex3v16(2675, 16506, 2675);
        glVertex3v16(2896, 14938, 2896);
        glVertex3v16(3784, 14938, 1567);
        glVertex3v16(2675, 16506, 2675);
        glVertex3v16(3784, 14938, 1567);
        glVertex3v16(3496, 16506, 1448);
        glColor3f(0.9, 0.9, 0.9);
        glVertex3v16(3496, 16506, 1448);
        glVertex3v16(3784, 14938, 1567);
        glVertex3v16(4096, 14938, 0);
        glVertex3v16(3496, 16506, 1448);
        glVertex3v16(4096, 14938, 0);
        glVertex3v16(3784, 16506, 0);
        glColor3f(1, 1, 1);
        glVertex3v16(3784, 16506, 0);
        glVertex3v16(4096, 14938, 0);
        glVertex3v16(3784, 14938, -1567);
        glVertex3v16(3784, 16506, 0);
        glVertex3v16(3784, 14938, -1567);
        glVertex3v16(3496, 16506, -1448);
        glColor3f(0.9, 0.9, 0.9);
        glVertex3v16(3496, 16506, -1448);
        glVertex3v16(3784, 14938, -1567);
        glVertex3v16(2896, 14938, -2896);
        glVertex3v16(3496, 16506, -1448);
        glVertex3v16(2896, 14938, -2896);
        glVertex3v16(2675, 16506, -2675);
        glColor3f(1, 1, 1);
        glVertex3v16(2675, 16506, -2675);
        glVertex3v16(2896, 14938, -2896);
        glVertex3v16(1567, 14938, -3784);
        glVertex3v16(2675, 16506, -2675);
        glVertex3v16(1567, 14938, -3784);
        glVertex3v16(1448, 16506, -3496);
        glColor3f(0.9, 0.9, 0.9);
        glVertex3v16(1448, 16506, -3496);
        glVertex3v16(1567, 14938, -3784);
        glVertex3v16(0, 14938, -4096);
        glVertex3v16(1448, 16506, -3496);
        glVertex3v16(0, 14938, -4096);
        glVertex3v16(0, 16506, -3784);

        // 5ª vuelta
        glColor3f(0.9, 0.9, 0.9);
        glVertex3v16(0, 14938, -4096);
        glVertex3v16(0, 13371, -3784);
        glVertex3v16(-1448, 13371, -3496);
        glVertex3v16(0, 14938, -4096);
        glVertex3v16(-1448, 13371, -3496);
        glVertex3v16(-1567, 14938, -3784);
        glColor3f(1, 1, 1);
        glVertex3v16(-1567, 14938, -3784);
        glVertex3v16(-1448, 13371, -3496);
        glVertex3v16(-2675, 13371, -2675);
        glVertex3v16(-1567, 14938, -3784);
        glVertex3v16(-2675, 13371, -2675);
        glVertex3v16(-2896, 14938, -2896);
        glColor3f(0.9, 0.9, 0.9);
        glVertex3v16(-2896, 14938, -2896);
        glVertex3v16(-2675, 13371, -2675);
        glVertex3v16(-3496, 13371, -1448);
        glVertex3v16(-2896, 14938, -2896);
        glVertex3v16(-3496, 13371, -1448);
        glVertex3v16(-3784, 14938, -1567);
        glColor3f(1, 1, 1);
        glVertex3v16(-3784, 14938, -1567);
        glVertex3v16(-3496, 13371, -1448);
        glVertex3v16(-3784, 13371, 0);
        glVertex3v16(-3784, 14938, -1567);
        glVertex3v16(-3784, 13371, 0);
        glVertex3v16(-4096, 14938, 0);
        glColor3f(0.9, 0.9, 0.9);
        glVertex3v16(-4096, 14938, 0);
        glVertex3v16(-3784, 13371, 0);
        glVertex3v16(-3496, 13371, 1448);
        glVertex3v16(-4096, 14938, 0);
        glVertex3v16(-3496, 13371, 1448);
        glVertex3v16(-3784, 14938, 1567);
        glColor3f(1, 1, 1);
        glVertex3v16(-3784, 14938, 1567);
        glVertex3v16(-3496, 13371, 1448);
        glVertex3v16(-2675, 13371, 2675);
        glVertex3v16(-3784, 14938, 1567);
        glVertex3v16(-2675, 13371, 2675);
        glVertex3v16(-2896, 14938, 2896);
        glColor3f(0.9, 0.9, 0.9);
        glVertex3v16(-2896, 14938, 2896);
        glVertex3v16(-2675, 13371, 2675);
        glVertex3v16(-1448, 13371, 3496);
        glVertex3v16(-2896, 14938, 2896);
        glVertex3v16(-1448, 13371, 3496);
        glVertex3v16(-1567, 14938, 3784);
        glColor3f(1, 1, 1);
        glVertex3v16(-1567, 14938, 3784);
        glVertex3v16(-1448, 13371, 3496);
        glVertex3v16(0, 13371, 3784);
        glVertex3v16(-1567, 14938, 3784);
        glVertex3v16(0, 13371, 3784);
        glVertex3v16(0, 14938, 4096);
        glColor3f(0.9, 0.9, 0.9);
        glVertex3v16(0, 14938, 4096);
        glVertex3v16(0, 13371, 3784);
        glVertex3v16(1448, 13371, 3496);
        glVertex3v16(0, 14938, 4096);
        glVertex3v16(1448, 13371, 3496);
        glVertex3v16(1567, 14938, 3784);
        glColor3f(1, 1, 1);
        glVertex3v16(1567, 14938, 3784);
        glVertex3v16(1448, 13371, 3496);
        glVertex3v16(2675, 13371, 2675);
        glVertex3v16(1567, 14938, 3784);
        glVertex3v16(2675, 13371, 2675);
        glVertex3v16(2896, 14938, 2896);
        glColor3f(0.9, 0.9, 0.9);
        glVertex3v16(2896, 14938, 2896);
        glVertex3v16(2675, 13371, 2675);
        glVertex3v16(3496, 13371, 1448);
        glVertex3v16(2896, 14938, 2896);
        glVertex3v16(3496, 13371, 1448);
        glVertex3v16(3784, 14938, 1567);
        glColor3f(1, 1, 1);
        glVertex3v16(3784, 14938, 1567);
        glVertex3v16(3496, 13371, 1448);
        glVertex3v16(3784, 13371, 0);
        glVertex3v16(3784, 14938, 1567);
        glVertex3v16(3784, 13371, 0);
        glVertex3v16(4096, 14938, 0);
        glColor3f(0.9, 0.9, 0.9);
        glVertex3v16(4096, 14938, 0);
        glVertex3v16(3784, 13371, 0);
        glVertex3v16(3496, 13371, -1448);
        glVertex3v16(4096, 14938, 0);
        glVertex3v16(3496, 13371, -1448);
        glVertex3v16(3784, 14938, -1567);
        glColor3f(1, 1, 1);
        glVertex3v16(3784, 14938, -1567);
        glVertex3v16(3496, 13371, -1448);
        glVertex3v16(2675, 13371, -2675);
        glVertex3v16(3784, 14938, -1567);
        glVertex3v16(2675, 13371, -2675);
        glVertex3v16(2896, 14938, -2896);
        glColor3f(0.9, 0.9, 0.9);
        glVertex3v16(2896, 14938, -2896);
        glVertex3v16(2675, 13371, -2675);
        glVertex3v16(1448, 13371, -3496);
        glVertex3v16(2896, 14938, -2896);
        glVertex3v16(1448, 13371, -3496);
        glVertex3v16(1567, 14938, -3784);
        glColor3f(1, 1, 1);
        glVertex3v16(1567, 14938, -3784);
        glVertex3v16(1448, 13371, -3496);
        glVertex3v16(0, 13371, -3784);
        glVertex3v16(1567, 14938, -3784);
        glVertex3v16(0, 13371, -3784);
        glVertex3v16(0, 14938, -4096);

        // 6ª vuelta
        glColor3f(1, 1, 1);
        glVertex3v16(0, 13371, -3784);
        glVertex3v16(0, 12042, -2896);
        glVertex3v16(-1108, 12042, -2675);
        glVertex3v16(0, 13371, -3784);
        glVertex3v16(-1108, 12042, -2675);
        glVertex3v16(-1448, 13371, -3496);
        glColor3f(0.9, 0.9, 0.9);
        glVertex3v16(-1448, 13371, -3496);
        glVertex3v16(-1108, 12042, -2675);
        glVertex3v16(-2048, 12042, -2048);
        glVertex3v16(-1448, 13371, -3496);
        glVertex3v16(-2048, 12042, -2048);
        glVertex3v16(-2675, 13371, -2675);
        glColor3f(1, 1, 1);
        glVertex3v16(-2675, 13371, -2675);
        glVertex3v16(-2048, 12042, -2048);
        glVertex3v16(-2675, 12042, -1108);
        glVertex3v16(-2675, 13371, -2675);
        glVertex3v16(-2675, 12042, -1108);
        glVertex3v16(-3496, 13371, -1448);
        glColor3f(0.9, 0.9, 0.9);
        glVertex3v16(-3496, 13371, -1448);
        glVertex3v16(-2675, 12042, -1108);
        glVertex3v16(-2896, 12042, 0);
        glVertex3v16(-3496, 13371, -1448);
        glVertex3v16(-2896, 12042, 0);
        glVertex3v16(-3784, 13371, 0);
        glColor3f(1, 1, 1);
        glVertex3v16(-3784, 13371, 0);
        glVertex3v16(-2896, 12042, 0);
        glVertex3v16(-2675, 12042, 1108);
        glVertex3v16(-3784, 13371, 0);
        glVertex3v16(-2675, 12042, 1108);
        glVertex3v16(-3496, 13371, 1448);
        glColor3f(0.9, 0.9, 0.9);
        glVertex3v16(-3496, 13371, 1448);
        glVertex3v16(-2675, 12042, 1108);
        glVertex3v16(-2048, 12042, 2047);
        glVertex3v16(-3496, 13371, 1448);
        glVertex3v16(-2048, 12042, 2047);
        glVertex3v16(-2675, 13371, 2675);
        glColor3f(1, 1, 1);
        glVertex3v16(-2675, 13371, 2675);
        glVertex3v16(-2048, 12042, 2047);
        glVertex3v16(-1108, 12042, 2675);
        glVertex3v16(-2675, 13371, 2675);
        glVertex3v16(-1108, 12042, 2675);
        glVertex3v16(-1448, 13371, 3496);
        glColor3f(0.9, 0.9, 0.9);
        glVertex3v16(-1448, 13371, 3496);
        glVertex3v16(-1108, 12042, 2675);
        glVertex3v16(0, 12042, 2896);
        glVertex3v16(-1448, 13371, 3496);
        glVertex3v16(0, 12042, 2896);
        glVertex3v16(0, 13371, 3784);
        glColor3f(1, 1, 1);
        glVertex3v16(0, 13371, 3784);
        glVertex3v16(0, 12042, 2896);
        glVertex3v16(1108, 12042, 2675);
        glVertex3v16(0, 13371, 3784);
        glVertex3v16(1108, 12042, 2675);
        glVertex3v16(1448, 13371, 3496);
        glColor3f(0.9, 0.9, 0.9);
        glVertex3v16(1448, 13371, 3496);
        glVertex3v16(1108, 12042, 2675);
        glVertex3v16(2048, 12042, 2047);
        glVertex3v16(1448, 13371, 3496);
        glVertex3v16(2048, 12042, 2047);
        glVertex3v16(2675, 13371, 2675);
        glColor3f(1, 1, 1);
        glVertex3v16(2675, 13371, 2675);
        glVertex3v16(2048, 12042, 2047);
        glVertex3v16(2675, 12042, 1108);
        glVertex3v16(2675, 13371, 2675);
        glVertex3v16(2675, 12042, 1108);
        glVertex3v16(3496, 13371, 1448);
        glColor3f(0.9, 0.9, 0.9);
        glVertex3v16(3496, 13371, 1448);
        glVertex3v16(2675, 12042, 1108);
        glVertex3v16(2896, 12042, 0);
        glVertex3v16(3496, 13371, 1448);
        glVertex3v16(2896, 12042, 0);
        glVertex3v16(3784, 13371, 0);
        glColor3f(1, 1, 1);
        glVertex3v16(3784, 13371, 0);
        glVertex3v16(2896, 12042, 0);
        glVertex3v16(2675, 12042, -1108);
        glVertex3v16(3784, 13371, 0);
        glVertex3v16(2675, 12042, -1108);
        glVertex3v16(3496, 13371, -1448);
        glColor3f(0.9, 0.9, 0.9);
        glVertex3v16(3496, 13371, -1448);
        glVertex3v16(2675, 12042, -1108);
        glVertex3v16(2047, 12042, -2048);
        glVertex3v16(3496, 13371, -1448);
        glVertex3v16(2047, 12042, -2048);
        glVertex3v16(2675, 13371, -2675);
        glColor3f(1, 1, 1);
        glVertex3v16(2675, 13371, -2675);
        glVertex3v16(2047, 12042, -2048);
        glVertex3v16(1108, 12042, -2675);
        glVertex3v16(2675, 13371, -2675);
        glVertex3v16(1108, 12042, -2675);
        glVertex3v16(1448, 13371, -3496);
        glColor3f(0.9, 0.9, 0.9);
        glVertex3v16(1448, 13371, -3496);
        glVertex3v16(1108, 12042, -2675);
        glVertex3v16(0, 12042, -2896);
        glVertex3v16(1448, 13371, -3496);
        glVertex3v16(0, 12042, -2896);
        glVertex3v16(0, 13371, -3784);

        // 7ª vuelta
        glColor3f(0.9, 0.9, 0.9);
        glVertex3v16(0, 12042, -2896);
        glVertex3v16(0, 11154, -1567);
        glVertex3v16(-599, 11154, -1448);
        glVertex3v16(0, 12042, -2896);
        glVertex3v16(-599, 11154, -1448);
        glVertex3v16(-1108, 12042, -2675);
        glColor3f(1, 1, 1);
        glVertex3v16(-1108, 12042, -2675);
        glVertex3v16(-599, 11154, -1448);
        glVertex3v16(-1108, 11154, -1108);
        glVertex3v16(-1108, 12042, -2675);
        glVertex3v16(-1108, 11154, -1108);
        glVertex3v16(-2048, 12042, -2048);
        glColor3f(0.9, 0.9, 0.9);
        glVertex3v16(-2048, 12042, -2048);
        glVertex3v16(-1108, 11154, -1108);
        glVertex3v16(-1448, 11154, -599);
        glVertex3v16(-2048, 12042, -2048);
        glVertex3v16(-1448, 11154, -599);
        glVertex3v16(-2675, 12042, -1108);
        glColor3f(1, 1, 1);
        glVertex3v16(-2675, 12042, -1108);
        glVertex3v16(-1448, 11154, -599);
        glVertex3v16(-1567, 11154, 0);
        glVertex3v16(-2675, 12042, -1108);
        glVertex3v16(-1567, 11154, 0);
        glVertex3v16(-2896, 12042, 0);
        glColor3f(0.9, 0.9, 0.9);
        glVertex3v16(-2896, 12042, 0);
        glVertex3v16(-1567, 11154, 0);
        glVertex3v16(-1448, 11154, 599);
        glVertex3v16(-2896, 12042, 0);
        glVertex3v16(-1448, 11154, 599);
        glVertex3v16(-2675, 12042, 1108);
        glColor3f(1, 1, 1);
        glVertex3v16(-2675, 12042, 1108);
        glVertex3v16(-1448, 11154, 599);
        glVertex3v16(-1108, 11154, 1108);
        glVertex3v16(-2675, 12042, 1108);
        glVertex3v16(-1108, 11154, 1108);
        glVertex3v16(-2048, 12042, 2047);
        glColor3f(0.9, 0.9, 0.9);
        glVertex3v16(-2048, 12042, 2047);
        glVertex3v16(-1108, 11154, 1108);
        glVertex3v16(-599, 11154, 1448);
        glVertex3v16(-2048, 12042, 2047);
        glVertex3v16(-599, 11154, 1448);
        glVertex3v16(-1108, 12042, 2675);
        glColor3f(1, 1, 1);
        glVertex3v16(-1108, 12042, 2675);
        glVertex3v16(-599, 11154, 1448);
        glVertex3v16(0, 11154, 1567);
        glVertex3v16(-1108, 12042, 2675);
        glVertex3v16(0, 11154, 1567);
        glVertex3v16(0, 12042, 2896);
        glColor3f(0.9, 0.9, 0.9);
        glVertex3v16(0, 12042, 2896);
        glVertex3v16(0, 11154, 1567);
        glVertex3v16(599, 11154, 1448);
        glVertex3v16(0, 12042, 2896);
        glVertex3v16(599, 11154, 1448);
        glVertex3v16(1108, 12042, 2675);
        glColor3f(1, 1, 1);
        glVertex3v16(1108, 12042, 2675);
        glVertex3v16(599, 11154, 1448);
        glVertex3v16(1108, 11154, 1108);
        glVertex3v16(1108, 12042, 2675);
        glVertex3v16(1108, 11154, 1108);
        glVertex3v16(2048, 12042, 2047);
        glColor3f(0.9, 0.9, 0.9);
        glVertex3v16(2048, 12042, 2047);
        glVertex3v16(1108, 11154, 1108);
        glVertex3v16(1448, 11154, 599);
        glVertex3v16(2048, 12042, 2047);
        glVertex3v16(1448, 11154, 599);
        glVertex3v16(2675, 12042, 1108);
        glColor3f(1, 1, 1);
        glVertex3v16(2675, 12042, 1108);
        glVertex3v16(1448, 11154, 599);
        glVertex3v16(1567, 11154, 0);
        glVertex3v16(2675, 12042, 1108);
        glVertex3v16(1567, 11154, 0);
        glVertex3v16(2896, 12042, 0);
        glColor3f(0.9, 0.9, 0.9);
        glVertex3v16(2896, 12042, 0);
        glVertex3v16(1567, 11154, 0);
        glVertex3v16(1448, 11154, -599);
        glVertex3v16(2896, 12042, 0);
        glVertex3v16(1448, 11154, -599);
        glVertex3v16(2675, 12042, -1108);
        glColor3f(1, 1, 1);
        glVertex3v16(2675, 12042, -1108);
        glVertex3v16(1448, 11154, -599);
        glVertex3v16(1108, 11154, -1108);
        glVertex3v16(2675, 12042, -1108);
        glVertex3v16(1108, 11154, -1108);
        glVertex3v16(2047, 12042, -2048);
        glColor3f(0.9, 0.9, 0.9);
        glVertex3v16(2047, 12042, -2048);
        glVertex3v16(1108, 11154, -1108);
        glVertex3v16(599, 11154, -1448);
        glVertex3v16(2047, 12042, -2048);
        glVertex3v16(599, 11154, -1448);
        glVertex3v16(1108, 12042, -2675);
        glColor3f(1, 1, 1);
        glVertex3v16(1108, 12042, -2675);
        glVertex3v16(599, 11154, -1448);
        glVertex3v16(0, 11154, -1567);
        glVertex3v16(1108, 12042, -2675);
        glVertex3v16(0, 11154, -1567);
        glVertex3v16(0, 12042, -2896);

        // 8ª vuelta
        glColor3f(1, 1, 1);
        glVertex3v16(0, 10842, 0);
        glVertex3v16(-599, 11154, -1448);
        glVertex3v16(0, 11154, -1567);
        glColor3f(0.9, 0.9, 0.9);
        glVertex3v16(0, 10842, 0);
        glVertex3v16(-1108, 11154, -1108);
        glVertex3v16(-599, 11154, -1448);
        glColor3f(1, 1, 1);
        glVertex3v16(0, 10842, 0);
        glVertex3v16(-1448, 11154, -599);
        glVertex3v16(-1108, 11154, -1108);
        glColor3f(0.9, 0.9, 0.9);
        glVertex3v16(0, 10842, 0);
        glVertex3v16(-1567, 11154, 0);
        glVertex3v16(-1448, 11154, -599);
        glColor3f(1, 1, 1);
        glVertex3v16(0, 10842, 0);
        glVertex3v16(-1448, 11154, 599);
        glVertex3v16(-1567, 11154, 0);
        glColor3f(0.9, 0.9, 0.9);
        glVertex3v16(0, 10842, 0);
        glVertex3v16(-1108, 11154, 1108);
        glVertex3v16(-1448, 11154, 599);
        glColor3f(1, 1, 1);
        glVertex3v16(0, 10842, 0);
        glVertex3v16(-599, 11154, 1448);
        glVertex3v16(-1108, 11154, 1108);
        glColor3f(0.9, 0.9, 0.9);
        glVertex3v16(0, 10842, 0);
        glVertex3v16(0, 11154, 1567);
        glVertex3v16(-599, 11154, 1448);
        glColor3f(1, 1, 1);
        glVertex3v16(0, 10842, 0);
        glVertex3v16(599, 11154, 1448);
        glVertex3v16(0, 11154, 1567);
        glColor3f(0.9, 0.9, 0.9);
        glVertex3v16(0, 10842, 0);
        glVertex3v16(1108, 11154, 1108);
        glVertex3v16(599, 11154, 1448);
        glColor3f(1, 1, 1);
        glVertex3v16(0, 10842, 0);
        glVertex3v16(1448, 11154, 599);
        glVertex3v16(1108, 11154, 1108);
        glColor3f(0.9, 0.9, 0.9);
        glVertex3v16(0, 10842, 0);
        glVertex3v16(1567, 11154, 0);
        glVertex3v16(1448, 11154, 599);
        glColor3f(1, 1, 1);
        glVertex3v16(0, 10842, 0);
        glVertex3v16(1448, 11154, -599);
        glVertex3v16(1567, 11154, 0);
        glColor3f(0.9, 0.9, 0.9);
        glVertex3v16(0, 10842, 0);
        glVertex3v16(1108, 11154, -1108);
        glVertex3v16(1448, 11154, -599);
        glColor3f(1, 1, 1);
        glVertex3v16(0, 10842, 0);
        glVertex3v16(599, 11154, -1448);
        glVertex3v16(1108, 11154, -1108);
        glColor3f(0.9, 0.9, 0.9);
        glVertex3v16(0, 10842, 0);
        glVertex3v16(0, 11154, -1567);
        glVertex3v16(599, 11154, -1448);

    glEnd();
}

void Draw_Foco1Der(float red, float green, float blue)
{
    glBindTexture(GL_TEXTURE_2D, texture[TEXTURA_METAL]);

    glColor3f(0.5, 0.5, 0.5);

    glBegin(GL_TRIANGLES);

        glTexCoord2f(0.5, 0);
        glVertex3v16(-14414, 18623, -7244);
        glTexCoord2f(1, 1);
        glVertex3v16(-12435, 14721, -5708);
        glTexCoord2f(0, 1);
        glVertex3v16(-10358, 16984, -5708);

        glTexCoord2f(0.5, 0);
        glVertex3v16(-14414, 18623, -7244);
        glTexCoord2f(1, 1);
        glVertex3v16(-10358, 16984, -5708);
        glTexCoord2f(0, 1);
        glVertex3v16(-10358, 16984, -8780);

        glTexCoord2f(0.5, 0);
        glVertex3v16(-14414, 18623, -7244);
        glTexCoord2f(1, 1);
        glVertex3v16(-10358, 16984, -8780);
        glTexCoord2f(0, 1);
        glVertex3v16(-12435, 14721, -8780);

        glTexCoord2f(0.5, 0);
        glVertex3v16(-14414, 18623, -7244);
        glTexCoord2f(1, 1);
        glVertex3v16(-12435, 14721, -8780);
        glTexCoord2f(0, 1);
        glVertex3v16(-12435, 14721, -5708);

    glEnd();

    glBindTexture(GL_TEXTURE_2D, texture[TEXTURA_FOCO]);

    glColor3f(red, green, blue);

    glBegin(GL_QUADS);

        glTexCoord2f(0, 0);
        glVertex3v16(-12435, 14721, -8780);
        glTexCoord2f(1, 0);
        glVertex3v16(-10358, 16984, -8780);
        glTexCoord2f(1, 1);
        glVertex3v16(-10358, 16984, -5708);
        glTexCoord2f(0, 1);
        glVertex3v16(-12435, 14721, -5708);

    glEnd();

    glBindTexture(GL_TEXTURE_2D, 0);
}

void Draw_Foco2Der(float red, float green, float blue)
{
    glBindTexture(GL_TEXTURE_2D, texture[TEXTURA_METAL]);

    glColor3f(0.5, 0.5, 0.5);

    glBegin(GL_TRIANGLES);

        glTexCoord2f(0.5, 0);
        glVertex3v16(-14414, 18623, 134);
        glTexCoord2f(1, 1);
        glVertex3v16(-12435, 14721, 1670);
        glTexCoord2f(0, 1);
        glVertex3v16(-10358, 16984, 1670);

        glTexCoord2f(0.5, 0);
        glVertex3v16(-14414, 18623, 134);
        glTexCoord2f(1, 1);
        glVertex3v16(-10358, 16984, 1670);
        glTexCoord2f(0, 1);
        glVertex3v16(-10358, 16984, -1401);

        glTexCoord2f(0.5, 0);
        glVertex3v16(-14414, 18623, 134);
        glTexCoord2f(1, 1);
        glVertex3v16(-10358, 16984, -1401);
        glTexCoord2f(0, 1);
        glVertex3v16(-12435, 14721, -1401);

        glTexCoord2f(0.5, 0);
        glVertex3v16(-14414, 18623, 134);
        glTexCoord2f(1, 1);
        glVertex3v16(-12435, 14721, -1401);
        glTexCoord2f(0, 1);
        glVertex3v16(-12435, 14721, 1670);

    glEnd();

    glBindTexture(GL_TEXTURE_2D, texture[TEXTURA_FOCO]);

    glColor3f(red, green, blue);

    glBegin(GL_QUADS);

        glTexCoord2f(0, 0);
        glVertex3v16(-12435, 14721, -1401);
        glTexCoord2f(1, 0);
        glVertex3v16(-10358, 16984, -1401);
        glTexCoord2f(1, 1);
        glVertex3v16(-10358, 16984, 1670);
        glTexCoord2f(0, 1);
        glVertex3v16(-12435, 14721, 1670);

    glEnd();

    glBindTexture(GL_TEXTURE_2D, 0);
}

void Draw_Foco3Der(float red, float green, float blue)
{
    glBindTexture(GL_TEXTURE_2D, texture[TEXTURA_METAL]);

    glColor3f(0.5, 0.5, 0.5);

    glBegin(GL_TRIANGLES);

        glTexCoord2f(0.5, 0);
        glVertex3v16(-14414, 18623, 7228);
        glTexCoord2f(1, 1);
        glVertex3v16(-12435, 14721, 8764);
        glTexCoord2f(0, 1);
        glVertex3v16(-10358, 16984, 8764);

        glTexCoord2f(0.5, 0);
        glVertex3v16(-14414, 18623, 7228);
        glTexCoord2f(1, 1);
        glVertex3v16(-10358, 16984, 8764);
        glTexCoord2f(0, 1);
        glVertex3v16(-10358, 16984, 5692);

        glTexCoord2f(0.5, 0);
        glVertex3v16(-14414, 18623, 7228);
        glTexCoord2f(1, 1);
        glVertex3v16(-10358, 16984, 5692);
        glTexCoord2f(0, 1);
        glVertex3v16(-12435, 14721, 5692);

        glTexCoord2f(0.5, 0);
        glVertex3v16(-14414, 18623, 7228);
        glTexCoord2f(1, 1);
        glVertex3v16(-12435, 14721, 5692);
        glTexCoord2f(0, 1);
        glVertex3v16(-12435, 14721, 8764);

    glEnd();

    glBindTexture(GL_TEXTURE_2D, texture[TEXTURA_FOCO]);

    glColor3f(red, green, blue);

    glBegin(GL_QUADS);

        glTexCoord2f(0, 0);
        glVertex3v16(-12435, 14721, 5692);
        glTexCoord2f(1, 0);
        glVertex3v16(-10358, 16984, 5692);
        glTexCoord2f(1, 1);
        glVertex3v16(-10358, 16984, 8764);
        glTexCoord2f(0, 1);
        glVertex3v16(-12435, 14721, 8764);

    glEnd();

    glBindTexture(GL_TEXTURE_2D, 0);
}

void Draw_Sala(void)
{
    glBegin(GL_QUADS);

        // Techo
        glColor3f(0, 0, 0);
        glBindTexture(GL_TEXTURE_2D, 0);
        glTexCoord2f(1, 0);
        glVertex3v16(14336, 20480, 12288);
        glTexCoord2f(0, 0);
        glVertex3v16(-14336, 20480, 12288);
        glTexCoord2f(0, 1);
        glVertex3v16(-14336, 20480, -12288);
        glTexCoord2f(1, 1);
        glVertex3v16(14336, 20480, -12288);

        // -----
        // Suelo
        // -----

        glBindTexture(GL_TEXTURE_2D, texture[TEXTURA_SUELO]);
        // Abajo-derecha
        glColor3f(Limitar_float(0, 1, focoizq[0].red + focoizq[1].red / 2),
                  Limitar_float(0, 1, focoizq[0].green + focoizq[1].green / 2),
                  Limitar_float(0, 1, focoizq[0].blue + focoizq[1].blue / 2));
        glTexCoord2f(1, 1);
        glVertex3v16(-14336, 0, -12288);

        // Arriba-derecha
        glColor3f(Limitar_float(0, 1, focoizq[2].red + focoizq[1].red / 2),
                  Limitar_float(0, 1, focoizq[2].green + focoizq[1].green / 2),
                  Limitar_float(0, 1, focoizq[2].blue + focoizq[1].blue / 2));
        glTexCoord2f(1, 0);
        glVertex3v16(-14336, 0, 12288);

        // Arriba-izquierda
        glColor3f(Limitar_float(0, 1, focoder[2].red + focoder[1].red / 2),
                  Limitar_float(0, 1, focoder[2].green + focoder[1].green / 2),
                  Limitar_float(0, 1, focoder[2].blue + focoder[1].blue / 2));
        glTexCoord2f(0, 0);
        glVertex3v16(14336, 0, 12288);

        // Abajo-izquierda
        glColor3f(Limitar_float(0, 1, focoder[0].red + focoder[1].red / 2),
                  Limitar_float(0, 1, focoder[0].green + focoder[1].green / 2),
                  Limitar_float(0, 1, focoder[0].blue + focoder[1].blue / 2));
        glTexCoord2f(0, 1);
        glVertex3v16(14336, 0, -12288);

        // -------
        // Paredes
        // -------

        // Pared frente
        glBindTexture(GL_TEXTURE_2D, texture[TEXTURA_PAREDES]);
        glColor3f(Limitar_float(0, 1, focoder[2].red + focoder[1].red / 2),
                  Limitar_float(0, 1, focoder[2].green + focoder[1].green / 2),
                  Limitar_float(0, 1, focoder[2].blue + focoder[1].blue / 2));
        glTexCoord2f(1, 0);
        glVertex3v16(14336, 0, 12288);
        glColor3f(Limitar_float(0, 1, focoizq[2].red + focoizq[1].red / 2),
                  Limitar_float(0, 1, focoizq[2].green + focoizq[1].green / 2),
                  Limitar_float(0, 1, focoizq[2].blue + focoizq[1].blue / 2));
        glTexCoord2f(0, 0);
        glVertex3v16(-14336, 0, 12288);
        glColor3f(0, 0, 0);
        glTexCoord2f(0, 1);
        glVertex3v16(-14336, 20480, 12288);
        glTexCoord2f(1, 1);
        glVertex3v16(14336, 20480, 12288);

        // Pared izquierda
        glColor3f(Limitar_float(0, 1, focoder[0].red + focoder[1].red / 2),
                  Limitar_float(0, 1, focoder[0].green + focoder[1].green / 2),
                  Limitar_float(0, 1, focoder[0].blue + focoder[1].blue / 2));
        glTexCoord2f(1, 0);
        glVertex3v16(14336, 0, -12288);
        glColor3f(Limitar_float(0, 1, focoder[2].red + focoder[1].red / 2),
                  Limitar_float(0, 1, focoder[2].green + focoder[1].green / 2),
                  Limitar_float(0, 1, focoder[2].blue + focoder[1].blue / 2));
        glTexCoord2f(0, 0);
        glVertex3v16(14336, 0, 12288);
        glColor3f(0, 0, 0);
        glTexCoord2f(0, 1);
        glVertex3v16(14336, 20480, 12288);
        glTexCoord2f(1, 1);
        glVertex3v16(14336, 20480, -12288);

        // Pared derecha
        glColor3f(Limitar_float(0, 1, focoizq[2].red + focoizq[1].red / 2),
                  Limitar_float(0, 1, focoizq[2].green + focoizq[1].green / 2),
                  Limitar_float(0, 1, focoizq[2].blue + focoizq[1].blue / 2));
        glTexCoord2f(1, 0);
        glVertex3v16(-14336, 0, 12288);

        glColor3f(Limitar_float(0, 1, focoizq[0].red + focoizq[1].red / 2),
                  Limitar_float(0, 1, focoizq[0].green + focoizq[1].green / 2),
                  Limitar_float(0, 1, focoizq[0].blue + focoizq[1].blue / 2));
        glTexCoord2f(0, 0);
        glVertex3v16(-14336, 0, -12288);
        glTexCoord2f(0, 1);
        glColor3f(0, 0, 0);
        glVertex3v16(-14336, 20480, -12288);
        glTexCoord2f(1, 1);
        glVertex3v16(-14336, 20480, 12288);

    glEnd();

    glBindTexture(GL_TEXTURE_2D, 0);
}

void Draw_AsientoDer(void)
{
    glBegin(GL_QUADS);

        // Superficie
        glBindTexture(GL_TEXTURE_2D, texture[TEXTURA_ASIENTO]);
        glColor3f(Limitar_float(0, 1, (focoizq[2].red + focoizq[1].red / 2) - 0.2),
                  Limitar_float(0, 1, (focoizq[2].green + focoizq[1].green / 2) -0.2),
                  Limitar_float(0, 1, (focoizq[2].blue + focoizq[1].blue / 2) - 0.2));
        glTexCoord2f(0, 0);
        glVertex3v16(-14484, 4722, 12269);
        glTexCoord2f(1, 0);
        glVertex3v16(-9762, 4722, 12269);
        glColor3f(Limitar_float(0, 1, (focoizq[0].red + focoizq[1].red / 2) - 0.2),
                  Limitar_float(0, 1, (focoizq[0].green + focoizq[1].green / 2) - 0.2),
                  Limitar_float(0, 1, (focoizq[0].blue + focoizq[1].blue / 2) - 0.2));
        glTexCoord2f(1, 1);
        glVertex3v16(-9762, 4722, -12390);
        glTexCoord2f(0, 1);
        glVertex3v16(-14484, 4722, -12390);

        // Lateral grande
        glBindTexture(GL_TEXTURE_2D, texture[TEXTURA_SUELO]);
        glColor3f(Limitar_float(0, 1, focoizq[2].red + focoizq[1].red / 2),
                  Limitar_float(0, 1, focoizq[2].green + focoizq[1].green / 2),
                  Limitar_float(0, 1, focoizq[2].blue + focoizq[1].blue / 2));
        glTexCoord2f(0, 0);
        glVertex3v16(-9762, 0, 12269);
        glColor3f(Limitar_float(0, 1, focoizq[0].red + focoizq[1].red / 2),
                  Limitar_float(0, 1, focoizq[0].green + focoizq[1].green / 2),
                  Limitar_float(0, 1, focoizq[0].blue + focoizq[1].blue / 2));
        glTexCoord2f(1, 0);
        glVertex3v16(-9762, 0, -12390);
        glTexCoord2f(1, 1);
        glVertex3v16(-9762, 4722, -12390);
        glColor3f(Limitar_float(0, 1, focoizq[2].red + focoizq[1].red / 2),
                  Limitar_float(0, 1, focoizq[2].green + focoizq[1].green / 2),
                  Limitar_float(0, 1, focoizq[2].blue + focoizq[1].blue / 2));
        glTexCoord2f(0, 1);
        glVertex3v16(-9762, 4722, 12269);

        // Lateral pequeño
        glColor3f(Limitar_float(0, 1, (focoizq[0].red + focoizq[1].red / 2) - 0.5),
                  Limitar_float(0, 1, (focoizq[0].green + focoizq[1].green / 2) - 0.5),
                  Limitar_float(0, 1, (focoizq[0].blue + focoizq[1].blue / 2) - 0.5));
        glTexCoord2f(0, 0);
        glVertex3v16(-9762, 0, -12390);
        glTexCoord2f(1, 0);
        glVertex3v16(-14484, 0, -12390);
        glTexCoord2f(1, 1);
        glVertex3v16(-14484, 4722, -12390);
        glTexCoord2f(0, 1);
        glVertex3v16(-9762, 4722, -12390);

    glEnd();

    glBindTexture(GL_TEXTURE_2D, 0);
}

void Draw_AsientoIzq(void)
{
    glBegin(GL_QUADS);

        // Superficie
        glBindTexture(GL_TEXTURE_2D, texture[TEXTURA_ASIENTO]);
        glColor3f(Limitar_float(0, 1, focoder[2].red + focoder[1].red / 2),
                Limitar_float(0, 1, focoder[2].green + focoder[1].green / 2),
                Limitar_float(0, 1, focoder[2].blue + focoder[1].blue / 2));
        glTexCoord2f(0, 0);
        glVertex3v16(14365, 4739, 12269);
        glColor3f(Limitar_float(0, 1, focoder[0].red + focoder[1].red / 2),
                Limitar_float(0, 1, focoder[0].green + focoder[1].green / 2),
                Limitar_float(0, 1, focoder[0].blue + focoder[1].blue / 2));
        glTexCoord2f(1, 0);
        glVertex3v16(14365, 4739, -12390);
        glTexCoord2f(1, 1);
        glVertex3v16(9642, 4739, -12390);
        glColor3f(Limitar_float(0, 1, focoder[2].red + focoder[1].red / 2),
                Limitar_float(0, 1, focoder[2].green + focoder[1].green / 2),
                Limitar_float(0, 1, focoder[2].blue + focoder[1].blue / 2));
        glTexCoord2f(0, 1);
        glVertex3v16(9642, 4739, 12269);

        // Lateral grande
        glBindTexture(GL_TEXTURE_2D, texture[TEXTURA_SUELO]);
        glColor3f(Limitar_float(0, 1, focoder[2].red + focoder[1].red / 2),
                Limitar_float(0, 1, focoder[2].green + focoder[1].green / 2),
                Limitar_float(0, 1, focoder[2].blue + focoder[1].blue / 2));
        glTexCoord2f(0, 0);
        glVertex3v16(9642, 0, 12269);
        glTexCoord2f(1, 0);
        glVertex3v16(9642, 4739, 12269);
        glTexCoord2f(1, 1);
        glColor3f(Limitar_float(0, 1, focoder[0].red + focoder[1].red / 2),
                Limitar_float(0, 1, focoder[0].green + focoder[1].green / 2),
                Limitar_float(0, 1, focoder[0].blue + focoder[1].blue / 2));
        glVertex3v16(9642, 4739, -12390);
        glTexCoord2f(0, 1);
        glVertex3v16(9642, 0, -12390);

        // Lateral pequeño
        glColor3f(Limitar_float(0, 1, (focoder[0].red + focoder[1].red / 2) - 0.5),
                Limitar_float(0, 1, (focoder[0].green + focoder[1].green / 2) - 0.5),
                Limitar_float(0, 1, (focoder[0].blue + focoder[1].blue / 2) - 0.5));
        glTexCoord2f(0, 0);
        glVertex3v16(14365, 4739, -12390);
        glTexCoord2f(1, 0);
        glVertex3v16(14365, 0, -12390);
        glTexCoord2f(1, 1);
        glVertex3v16(9642, 0, -12390);
        glTexCoord2f(0, 1);
        glVertex3v16(9642, 4739, -12390);

    glEnd();

    glBindTexture(GL_TEXTURE_2D, 0);
}

void Dibujar_Discoteca(u8 pausa, u8 camara)
{
    if (!pausa)
    {
        Actualizar_Focos();
    }

    if (camara)
    {
        // Girar sala!!! ^^
        glRotateX((int)Rot_Sala.Y);
        glRotateZ((int)Rot_Sala.Z);
    }

    Draw_Foco1Izq(focoizq[0].red, focoizq[0].green, focoizq[0].blue);
    Draw_Foco2Izq(focoizq[1].red, focoizq[1].green, focoizq[1].blue);
    Draw_Foco3Izq(focoizq[2].red, focoizq[2].green, focoizq[2].blue);

    Draw_Foco1Der(focoder[0].red, focoder[0].green, focoder[0].blue);
    Draw_Foco2Der(focoder[1].red, focoder[1].green, focoder[1].blue);
    Draw_Foco3Der(focoder[2].red, focoder[2].green, focoder[2].blue);

    Draw_AsientoIzq();
    Draw_AsientoDer();
    Draw_Sala();
    Draw_Sujetabola();

    glRotateY((int)girar_bola);
    Draw_Bola();

    glTranslatef(0, 3.65, 0);

    Iniciar_Transparencia(20);
    for (int i = 0; i < 4; i++)
    {
        if (luz[i].tiemporestante > 0)
        {
            glRotateZ((int)((luz[i].rotz * 22.5) + 11.25));
            glRotateX((int)((luz[i].rotx * 22.5) + 11.25));
            Dibujar_Luz(1, 1, 1);
            glRotateX((int)(-(luz[i].rotx * 22.5) - 11.25));
            glRotateZ((int)(-(luz[i].rotz * 22.5) - 11.25));
        }
    }
    Finalizar_Transparencia();
}

void Iniciar_Focos(void)
{
    // Velocidad de giro de la sala
    //Rot_Sala.X = 0;
    Rot_Sala.Y = 0; Rot_Sala.Z = 0;
    //Rot_Sala.IncX = 0.3;
    Rot_Sala.IncY = (float)PA_RandMinMax(2, 4)/10;
    Rot_Sala.IncZ = (float)PA_RandMinMax(2, 4)/10;

    // Focos
    for (int i = 0; i < 3; i++)
    {
        /*
        focoder[i].red = ((float)PA_RandMinMax(1, 9)) / 10;
        focoder[i].green = ((float)PA_RandMinMax(1, 9)) / 10;
        focoder[i].blue = ((float)PA_RandMinMax(1, 9)) / 10;
        */

        focoder[i].ired = ((float)PA_RandMinMax(3, 10)) / 300;
        if (PA_RandMinMax(0, 1))
            focoder[i].ired *= -1;

        focoder[i].igreen = ((float)PA_RandMinMax(3, 10)) / 300;
        if (PA_RandMinMax(0, 1))
            focoder[i].igreen *= -1;

        focoder[i].iblue = ((float)PA_RandMinMax(3, 10)) / 300;
        if (PA_RandMinMax(0, 1))
            focoder[i].iblue *= -1;

        /*
        focoizq[i].red = ((float)PA_RandMinMax(1, 9)) / 10;
        focoizq[i].green = ((float)PA_RandMinMax(1, 9)) / 10;
        focoizq[i].blue = ((float)PA_RandMinMax(1, 9)) / 10;
        */

        focoizq[i].ired = ((float)PA_RandMinMax(3, 10)) / 300;
        if (PA_RandMinMax(0, 1))
            focoizq[i].ired *= -1;

        focoizq[i].igreen = ((float)PA_RandMinMax(3, 10)) / 300;
        if (PA_RandMinMax(0, 1))
            focoizq[i].igreen *= -1;

        focoizq[i].iblue = ((float)PA_RandMinMax(3, 10)) / 300;
        if (PA_RandMinMax(0, 1))
            focoizq[i].iblue *= -1;
    }

    // Luces de la bola
    // Activar una sola luz
    luz[0].rotz = PA_RandMinMax(2, 5);
    luz[0].rotx = PA_RandMinMax(0, 15);
    luz[0].tiemporestante = PA_RandMinMax(45, 60);

    luz[1].tiemporestante = 0;
    luz[2].tiemporestante = 0;
    luz[3].tiemporestante = 0;
    luz[4].tiemporestante = 0;

    value_song = 0;
}

void Actualizar_Focos()
{
    if (SONG_ERROR || FAT_ERROR) // Random graphics
    {
        girar_bola+=0.3;
        if (girar_bola > 360)
            girar_bola -= 360;

        //Rot_Sala.X += (Rot_Sala.IncX * ((float)value_song / 256));
        Rot_Sala.Y += (Rot_Sala.IncY * ((float)value_song / 256));
        Rot_Sala.Z += (Rot_Sala.IncZ * ((float)value_song / 256));

        //if (Float_Abs(Rot_Sala.X) > 5)
        //    Rot_Sala.IncX *= -1;
        if ((Float_Abs(Rot_Sala.Y) > 5) || (PA_RandMinMax(0, 120) == 0))
            Rot_Sala.IncY *= -1;
        if ((Float_Abs(Rot_Sala.Z) > 5) || (PA_RandMinMax(0, 120) == 0))
            Rot_Sala.IncZ *= -1;

        for (int i = 0; i < 3; i++)
        {
            focoder[i].red += focoder[i].ired;
            focoder[i].green += focoder[i].igreen;
            focoder[i].blue += focoder[i].iblue;
            if (focoder[i].red > 1 || focoder[i].red < 0)
            {
                focoder[i].ired *= -1;
                focoder[i].red += focoder[i].ired;
            }
            if (focoder[i].green > 1 || focoder[i].green < 0)
            {
                focoder[i].igreen *= -1;
                focoder[i].green += focoder[i].igreen;
            }
            if (focoder[i].blue > 1 || focoder[i].blue < 0)
            {
                focoder[i].iblue *= -1;
                focoder[i].blue += focoder[i].iblue;
            }

            focoizq[i].red += focoizq[i].ired;
            focoizq[i].green += focoizq[i].igreen;
            focoizq[i].blue += focoizq[i].iblue;
            if (focoizq[i].red > 1 || focoizq[i].red < 0)
            {
                focoizq[i].ired *= -1;
                focoizq[i].red += focoizq[i].ired;
            }
            if (focoizq[i].green > 1 || focoizq[i].green < 0)
            {
                focoizq[i].igreen *= -1;
                focoizq[i].green += focoizq[i].igreen;
            }
            if (focoizq[i].blue > 1 || focoizq[i].blue < 0)
            {
                focoizq[i].iblue *= -1;
                focoizq[i].blue += focoizq[i].iblue;
            }
        }

        for (int i = 0; i < 5; i++)
        {
            luz[i].tiemporestante--;

            // Nueva luz
            if ((luz[i].tiemporestante < -30) && (PA_RandMinMax(0, 10) == 0))
            {
                luz[i].rotz = PA_RandMinMax(2, 5);
                luz[i].rotx = PA_RandMinMax(0, 15);
                luz[i].tiemporestante = PA_RandMinMax(45, 60);
            }
        }

        if (PA_RandMinMax(0, 60) == 0)
            value_song = PA_RandMinMax(64, 255);
    }
    else if (AS_GetMP3Status() & (MP3ST_PLAYING | MP3ST_PAUSED)) // Wave data -> Graphics 3D
    {
        girar_bola += 0.3;
        if (girar_bola > 360)
            girar_bola -= 360;

        //Rot_Sala.X += (Rot_Sala.IncX * ((float)value_song / 256));
        Rot_Sala.Y += (Rot_Sala.IncY * ((float)value_song / 256));
        Rot_Sala.Z += (Rot_Sala.IncZ * ((float)value_song / 256));

        //if (Float_Abs(Rot_Sala.X) > 5)
        //    Rot_Sala.IncX *= -1;
        if ((Float_Abs(Rot_Sala.Y) > 5) || (PA_RandMinMax(0, 120) == 0))
            Rot_Sala.IncY *= -1;
        if ((Float_Abs(Rot_Sala.Z) > 5) || (PA_RandMinMax(0, 120) == 0))
            Rot_Sala.IncZ *= -1;

        for (int i = 0; i < 3; i++)
        {
            focoder[i].red += focoder[i].ired;
            focoder[i].green += focoder[i].igreen;
            focoder[i].blue += focoder[i].iblue;

            focoizq[i].red += focoizq[i].ired;
            focoizq[i].green += focoizq[i].igreen;
            focoizq[i].blue += focoizq[i].iblue;

            if ((focoder[i].ired > 0) && (focoder[i].red > ((float)Limitar_int(0, 192,value_song)/192)))
            {
                focoder[i].ired *= -1;
                focoder[i].red += focoder[i].ired;
            }
            if ((focoder[i].ired < 0) && (focoder[i].red < 0))
            {
                focoder[i].ired *= -1;
                focoder[i].red += focoder[i].ired;
            }
            if ((focoizq[i].ired > 0) && (focoizq[i].red > ((float)Limitar_int(0, 192,value_song)/192)))
            {
                focoizq[i].ired *= -1;
                focoizq[i].red += focoizq[i].ired;
            }
            if ((focoizq[i].ired < 0) && (focoizq[i].red < 0))
            {
                focoizq[i].ired *= -1;
                focoizq[i].red += focoizq[i].ired;
            }

            if ((focoder[i].igreen > 0) && (focoder[i].green > (1 - Float_Abs((float)(value_song - 128))/192)))
            {
                focoder[i].igreen *= -1;
                focoder[i].green += focoder[i].igreen;
            }
            if ((focoder[i].igreen < 0) && (focoder[i].green < 0))
            {
                focoder[i].igreen *= -1;
                focoder[i].green += focoder[i].igreen;
            }
            if ((focoizq[i].igreen > 0) && (focoizq[i].green > (1 - Float_Abs((float)(value_song - 128))/192)))
            {
                focoizq[i].igreen *= -1;
                focoizq[i].green += focoizq[i].igreen;
            }
            if ((focoizq[i].igreen < 0) && (focoizq[i].green < 0))
            {
                focoizq[i].igreen *= -1;
                focoizq[i].green += focoizq[i].igreen;
            }

            if ((focoder[i].iblue > 0) && (focoder[i].blue > (1 - ((float)(Limitar_int(0, 192,value_song - 64))/192))))
            {
                focoder[i].iblue *= -1;
                focoder[i].blue += focoder[i].iblue;
            }
            if ((focoder[i].iblue < 0) && (focoder[i].blue < 0))
            {
                focoder[i].iblue *= -1;
                focoder[i].blue += focoder[i].iblue;
            }
            if ((focoizq[i].iblue > 0) && (focoizq[i].blue > (1 - ((float)(Limitar_int(0, 192,value_song - 64))/192))))
            {
                focoizq[i].iblue *= -1;
                focoizq[i].blue += focoizq[i].iblue;
            }
            if ((focoizq[i].iblue < 0) && (focoizq[i].blue < 0))
            {
                focoizq[i].iblue *= -1;
                focoizq[i].blue += focoizq[i].iblue;
            }
        }

        // Reducir tiempo de luz
        for (int i = 0; i < 5; i++)
        {
            luz[i].tiemporestante--;
        }

        // Si el valor de la musica lo permite, encender focos
        for (int i = 0; i < Limitar_int(1, 5, value_song / 32); i++)
        {
            // Nueva luz
            if ((luz[i].tiemporestante < -30) && (PA_RandMinMax(0, 10) == 0))
            {
                luz[i].rotz = PA_RandMinMax(2, 5);
                luz[i].rotx = PA_RandMinMax(0, 15);
                luz[i].tiemporestante = PA_RandMinMax(45, 60);
            }
        }

        value_song = Limitar_int(64, 256, (*IPC_Sound->mp3.mp3buffer + value_song) / 2);
    }
    else /*if (AS_GetMP3Status() & (MP3ST_STOPPED | MP3ST_OUT_OF_DATA))*/ // Apagar luces
    {
        if (Rot_Sala.Y > 0)
            Rot_Sala.Y = Limitar_float(0, 5,Rot_Sala.Y - Float_Abs(Rot_Sala.IncY / 5));
        if (Rot_Sala.Y < 0)
            Rot_Sala.Y = Limitar_float(-5, 0,Rot_Sala.Y + Float_Abs(Rot_Sala.IncY / 5));
        if (Rot_Sala.Z > 0)
            Rot_Sala.Z = Limitar_float(0, 5,Rot_Sala.Z - Float_Abs(Rot_Sala.IncZ / 5));
        if (Rot_Sala.Z < 0)
            Rot_Sala.Z = Limitar_float(-5, 0,Rot_Sala.Z + Float_Abs(Rot_Sala.IncZ / 5));

        for (int i = 0; i < 3; i++)
        {
            if (focoder[i].red > 0.01)
                focoder[i].red -= 0.01;
            if (focoder[i].green > 0.01)
                focoder[i].green -= 0.01;
            if (focoder[i].blue > 0.01)
                focoder[i].blue -= 0.01;
            if (focoizq[i].red > 0.01)
                focoizq[i].red -= 0.01;
            if (focoizq[i].green > 0.01)
                focoizq[i].green -= 0.01;
            if (focoizq[i].blue > 0.01)
                focoizq[i].blue -= 0.01;
        }

        value_song = 0;

        // Reducir tiempo de luz
        for (int i = 0; i < 5; i++)
        {
            luz[i].tiemporestante--;
        }
    }
}
