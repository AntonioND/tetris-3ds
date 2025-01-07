// SPDX-License-Identifier: GPL-3.0-only
//
// Copyright (c) 2008, 2024-2025 Antonio Niño Díaz

#ifndef MENU_H__
#define MENU_H__

#include <nds.h>

void Draw16bitRectangleEx(u8 screen, s16 x1, s16 y1, s16 x2, s16 y2, u16 color, u8 size);

void Iniciar_3D_Menu(void);
void Actualizar_3D_Menu(void);
void Graficos_3D_Menu(void);

void Menu(void);

#endif // MENU_H__
