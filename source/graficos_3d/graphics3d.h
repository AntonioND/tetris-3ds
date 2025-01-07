// SPDX-License-Identifier: GPL-3.0-only
//
// Copyright (c) 2008, 2024-2025 Antonio Niño Díaz

#ifndef GRAFICOS_2D_GRAPHICS3D_H__
#define GRAFICOS_2D_GRAPHICS3D_H__

#include <nds.h>

void My_Init_3D(void);
void My_Init_3D_No_Textures(void);
void Load_Disco_Textures(void);

// Para simplificar las cosas...
void Dibujar_Caja(float R, float G, float B);

void Dibujar_Tetris(void);
void Dibujar_Tetris_CPU(void);

void Dibujar_Explosiones(void);
void Dibujar_Explosiones_CPU(void);

void Piezas_Aleatorias(int altura);
void Piezas_Aleatorias_CPU(int altura);

void Init_3D_Text_Colors(float red, float redincrement,
                         float green, float greenincrement,
                         float blue, float blueincrement);

void Update_3D_Text_Colors(void);

#define TEXT_SMALL      0
#define TEXT_MEDIUM     1
#define TEXT_BIG        2

void Escribir_3D_Char_Rotado(float tamano, u8 x_coord, u8 y_coord, int letra,
                             float red, float green, float blue);

void Escribir_3D_Char(float tamano, u8 x_coord, u8 y_coord, int letra,
                      float red, float green, float blue);

void Escribir_3D_Char_Moved(float tamano, float x_coord, float y_coord,
                            u8 xdesp, u8 ydesp, int letra,
                            float red, float green, float blue);

#endif // GRAFICOS_2D_GRAPHICS3D_H__
