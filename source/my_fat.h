// SPDX-License-Identifier: GPL-3.0-only
//
// Copyright (c) 2008, 2024-2025 Antonio Niño Díaz

#ifndef MY_FAT_H__
#define MY_FAT_H__

extern bool FAT_ERROR; // Activa/desactiva el acceso al FAT

void Guardar_Datos(void);

int Leer_Datos(void);

// Iniciar FAT y leer datos.
void Iniciar_FAT(void);

#endif // MY_FAT_H__
