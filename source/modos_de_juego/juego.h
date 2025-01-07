// SPDX-License-Identifier: GPL-3.0-only
//
// Copyright (c) 2008, 2024-2025 Antonio Niño Díaz

#ifndef MODOS_DE_JUEGO_JUEGO_H__
#define MODOS_DE_JUEGO_JUEGO_H__

#include <nds.h>

extern int temp_y, temp_x, temp_giro;

void Controles_Tactiles_Horizontal(void);
void Controles_Tactiles_Vertical(void);

extern int lastkeypressed, timepressed;

void Autofire_Keys_Horizontal(void);
void Autofire_Keys_Vertical(void);
void Cancelar_Animacion_Eliminar_Lineas(void);
u8 Borrar_Lineas_Completas(void);
void Borrar_Linea(u8 altura);
u8 Comprobar_Lineas_Completas(void);
u8 Comprobar_Linea(u8 altura);
void Ajustar_Colisiones_Actuales(void);
u8 Estado_Cuadricula(int x, int y);
u8 Comprobar_Colisiones_Inferior(void);
u8 Comprobar_Colisiones_Derecha(void);
u8 Comprobar_Colisiones_Izquierda(void);
u8 Comprobar_Colisiones_Giro(void);
void Borrar_Pieza_Actual(void);
void Dibujar_Pieza_Actual(void);
void Iniciar_Juego(void);
void Nueva_Pieza(void);
void Reservar_Pieza(void);

#endif // MODOS_DE_JUEGO_JUEGO_H__
