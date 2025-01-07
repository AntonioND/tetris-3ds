// SPDX-License-Identifier: GPL-3.0-only
//
// Copyright (c) 2008, 2024-2025 Antonio Niño Díaz

#ifndef GRAFICOS_3D_ESCENARIOS_ESCENARIO_DISCOTECA_H__
#define GRAFICOS_3D_ESCENARIOS_ESCENARIO_DISCOTECA_H__

#include <nds.h>

void Draw_Sujetabola(void);

void Draw_Foco1Izq(float red, float green, float blue);
void Draw_Foco2Izq(float red, float green, float blue);
void Draw_Foco3Izq(float red, float green, float blue);

void Draw_Bola(void);

void Draw_Foco1Der(float red, float green, float blue);
void Draw_Foco2Der(float red, float green, float blue);
void Draw_Foco3Der(float red, float green, float blue);

void Draw_Sala(void);

void Draw_AsientoDer(void);
void Draw_AsientoIzq(void);

void Dibujar_Discoteca(u8 pausa, u8 camara);

void Iniciar_Focos(void);

void Actualizar_Focos(void);

#endif // GRAFICOS_3D_ESCENARIOS_ESCENARIO_DISCOTECA_H__
