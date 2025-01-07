// SPDX-License-Identifier: GPL-3.0-only
//
// Copyright (c) 2008, 2024-2025 Antonio Niño Díaz

#include <nds.h>

void Dibujar_Numero(int numero, float RED, float GREEN, float BLUE)
{
    glBegin(GL_TRIANGLES);
    glColor3f(RED, GREEN, BLUE);

    switch (numero)
    {
        case 0:
            glVertex3v16(835, 0, 1228);
            glVertex3v16(835, 0, 2047);
            glVertex3v16(3302, 0, 1228);
            glVertex3v16(3302, 0, 2047);
            glVertex3v16(3302, 0, 1228);
            glVertex3v16(835, 0, 2047);
            glVertex3v16(3302, 0, -2048);
            glVertex3v16(3302, 0, 2047);
            glVertex3v16(4121, 0, -2048);
            glVertex3v16(4121, 0, 2047);
            glVertex3v16(4121, 0, -2048);
            glVertex3v16(3302, 0, 2047);
            glVertex3v16(835, 0, -2048);
            glVertex3v16(835, 0, -1213);
            glVertex3v16(3302, 0, -2048);
            glVertex3v16(3302, 0, -1213);
            glVertex3v16(3302, 0, -2048);
            glVertex3v16(835, 0, -1213);
            glVertex3v16(15, 0, -2048);
            glVertex3v16(15, 0, 2047);
            glVertex3v16(835, 0, -2048);
            glVertex3v16(835, 0, 2047);
            glVertex3v16(835, 0, -2048);
            glVertex3v16(15, 0, 2047);
            break;

        case 1:
            glVertex3v16(1644, 0, -2048);
            glVertex3v16(1644, 0, 2047);
            glVertex3v16(2466, 0, -2048);
            glVertex3v16(2466, 0, 2047);
            glVertex3v16(2466, 0, -2048);
            glVertex3v16(1644, 0, 2047);
            break;

        case 2:
            glVertex3v16(-52, 0, 1257);
            glVertex3v16(-52, 0, 2076);
            glVertex3v16(4043, 0, 1257);
            glVertex3v16(4043, 0, 2076);
            glVertex3v16(4043, 0, 1257);
            glVertex3v16(-52, 0, 2076);
            glVertex3v16(3233, 0, -1293);
            glVertex3v16(3233, 0, -474);
            glVertex3v16(4043, 0, -1293);
            glVertex3v16(4043, 0, -474);
            glVertex3v16(4043, 0, -1293);
            glVertex3v16(3233, 0, -474);
            glVertex3v16(-52, 0, 439);
            glVertex3v16(-52, 0, 1257);
            glVertex3v16(808, 0, 439);
            glVertex3v16(808, 0, 1257);
            glVertex3v16(808, 0, 439);
            glVertex3v16(-52, 0, 1257);
            glVertex3v16(808, 0, -409);
            glVertex3v16(808, 0, 439);
            glVertex3v16(3240, 0, -409);
            glVertex3v16(3240, 0, 439);
            glVertex3v16(3240, 0, -409);
            glVertex3v16(808, 0, 439);
            glVertex3v16(-52, 0, -2071);
            glVertex3v16(-52, 0, -1293);
            glVertex3v16(4043, 0, -2071);
            glVertex3v16(4043, 0, -1293);
            glVertex3v16(4043, 0, -2071);
            glVertex3v16(-52, 0, -1293);
            break;

        case 3:
            glVertex3v16(3298, 0, 439);
            glVertex3v16(3298, 0, 1258);
            glVertex3v16(4117, 0, 439);
            glVertex3v16(4117, 0, 1258);
            glVertex3v16(4117, 0, 439);
            glVertex3v16(3298, 0, 1258);
            glVertex3v16(835, 0, -430);
            glVertex3v16(835, 0, 439);
            glVertex3v16(3298, 0, -430);
            glVertex3v16(3298, 0, 439);
            glVertex3v16(3298, 0, -430);
            glVertex3v16(835, 0, 439);
            glVertex3v16(12, 0, -2052);
            glVertex3v16(12, 0, -1233);
            glVertex3v16(3298, 0, -2052);
            glVertex3v16(3298, 0, -1233);
            glVertex3v16(3298, 0, -2052);
            glVertex3v16(12, 0, -1233);
            glVertex3v16(12, 0, 1258);
            glVertex3v16(12, 0, 2048);
            glVertex3v16(3298, 0, 1258);
            glVertex3v16(3298, 0, 2048);
            glVertex3v16(3298, 0, 1258);
            glVertex3v16(12, 0, 2048);
            glVertex3v16(3298, 0, -1233);
            glVertex3v16(3298, 0, -474);
            glVertex3v16(4117, 0, -1233);
            glVertex3v16(4117, 0, -474);
            glVertex3v16(4117, 0, -1233);
            glVertex3v16(3298, 0, -474);
            break;

        case 4:
            glVertex3v16(12, 0, -440);
            glVertex3v16(12, 0, 378);
            glVertex3v16(3290, 0, -440);
            glVertex3v16(3290, 0, 378);
            glVertex3v16(3290, 0, -440);
            glVertex3v16(12, 0, 378);
            glVertex3v16(-12, 0, -2057);
            glVertex3v16(-12, 0, -440);
            glVertex3v16(806, 0, -2057);
            glVertex3v16(806, 0, -440);
            glVertex3v16(806, 0, -2057);
            glVertex3v16(-12, 0, -440);
            glVertex3v16(3290, 0, -2057);
            glVertex3v16(3290, 0, 2047);
            glVertex3v16(4099, 0, -2057);
            glVertex3v16(4099, 0, 2047);
            glVertex3v16(4099, 0, -2057);
            glVertex3v16(3290, 0, 2047);
            break;

        case 5:
            glVertex3v16(3230, 0, 384);
            glVertex3v16(3230, 0, 1203);
            glVertex3v16(4049, 0, 384);
            glVertex3v16(4049, 0, 1203);
            glVertex3v16(4049, 0, 384);
            glVertex3v16(3230, 0, 1203);
            glVertex3v16(775, 0, -409);
            glVertex3v16(775, 0, 384);
            glVertex3v16(3230, 0, -409);
            glVertex3v16(3230, 0, 384);
            glVertex3v16(3230, 0, -409);
            glVertex3v16(775, 0, 384);
            glVertex3v16(12, 0, 1203);
            glVertex3v16(12, 0, 2021);
            glVertex3v16(3230, 0, 1203);
            glVertex3v16(3230, 0, 2021);
            glVertex3v16(3230, 0, 1203);
            glVertex3v16(12, 0, 2021);
            glVertex3v16(12, 0, -1192);
            glVertex3v16(12, 0, 384);
            glVertex3v16(775, 0, -1192);
            glVertex3v16(775, 0, 384);
            glVertex3v16(775, 0, -1192);
            glVertex3v16(12, 0, 384);
            glVertex3v16(12, 0, -2071);
            glVertex3v16(12, 0, -1192);
            glVertex3v16(4098, 0, -2071);
            glVertex3v16(4098, 0, -1192);
            glVertex3v16(4098, 0, -2071);
            glVertex3v16(12, 0, -1192);
            break;

        case 6:
            glVertex3v16(0, 0, 406);
            glVertex3v16(0, 0, 1225);
            glVertex3v16(810, 0, 406);
            glVertex3v16(810, 0, 1225);
            glVertex3v16(810, 0, 406);
            glVertex3v16(0, 0, 1225);
            glVertex3v16(3255, 0, 406);
            glVertex3v16(3255, 0, 1225);
            glVertex3v16(4098, 0, 406);
            glVertex3v16(4098, 0, 1225);
            glVertex3v16(4098, 0, 406);
            glVertex3v16(3255, 0, 1225);
            glVertex3v16(810, 0, -2068);
            glVertex3v16(810, 0, -1249);
            glVertex3v16(4098, 0, -2068);
            glVertex3v16(4098, 0, -1249);
            glVertex3v16(4098, 0, -2068);
            glVertex3v16(810, 0, -1249);
            glVertex3v16(0, 0, 1225);
            glVertex3v16(0, 0, 2052);
            glVertex3v16(4098, 0, 1225);
            glVertex3v16(4098, 0, 2052);
            glVertex3v16(4098, 0, 1225);
            glVertex3v16(0, 0, 2052);
            glVertex3v16(0, 0, -431);
            glVertex3v16(0, 0, 406);
            glVertex3v16(4098, 0, -431);
            glVertex3v16(4098, 0, 406);
            glVertex3v16(4098, 0, -431);
            glVertex3v16(0, 0, 406);
            glVertex3v16(0, 0, -2068);
            glVertex3v16(0, 0, -431);
            glVertex3v16(810, 0, -2068);
            glVertex3v16(810, 0, -431);
            glVertex3v16(810, 0, -2068);
            glVertex3v16(0, 0, -431);
            break;

        case 7:
            glVertex3v16(3238, 0, -2048);
            glVertex3v16(3238, 0, 2047);
            glVertex3v16(4057, 0, -2048);
            glVertex3v16(4057, 0, 2047);
            glVertex3v16(4057, 0, -2048);
            glVertex3v16(3238, 0, 2047);
            glVertex3v16(-12, 0, -2048);
            glVertex3v16(-12, 0, -1249);
            glVertex3v16(3238, 0, -2048);
            glVertex3v16(3238, 0, -1249);
            glVertex3v16(3238, 0, -2048);
            glVertex3v16(-12, 0, -1249);
            break;

        case 8:
            glVertex3v16(804, 0, 1253);
            glVertex3v16(804, 0, 2072);
            glVertex3v16(3261, 0, 1253);
            glVertex3v16(3261, 0, 2072);
            glVertex3v16(3261, 0, 1253);
            glVertex3v16(804, 0, 2072);
            glVertex3v16(804, 0, -414);
            glVertex3v16(804, 0, 405);
            glVertex3v16(3261, 0, -414);
            glVertex3v16(3261, 0, 405);
            glVertex3v16(3261, 0, -414);
            glVertex3v16(804, 0, 405);
            glVertex3v16(804, 0, -2056);
            glVertex3v16(804, 0, -1237);
            glVertex3v16(3261, 0, -2056);
            glVertex3v16(3261, 0, -1237);
            glVertex3v16(3261, 0, -2056);
            glVertex3v16(804, 0, -1237);
            glVertex3v16(3261, -46, 1253);
            glVertex3v16(4126, 46, 1253);
            glVertex3v16(3261, -46, -1237);
            glVertex3v16(4126, 46, -1237);
            glVertex3v16(3261, -46, -1237);
            glVertex3v16(4126, 46, 1253);
            glVertex3v16(-29, -46, 1253);
            glVertex3v16(804, 46, 1253);
            glVertex3v16(-29, -46, -1237);
            glVertex3v16(804, 46, -1237);
            glVertex3v16(-29, -46, -1237);
            glVertex3v16(804, 46, 1253);
            break;

        case 9:
            glVertex3v16(804, 0, -2056);
            glVertex3v16(804, 0, -1237);
            glVertex3v16(3261, 0, -2056);
            glVertex3v16(3261, 0, -1237);
            glVertex3v16(3261, 0, -2056);
            glVertex3v16(804, 0, -1237);
            glVertex3v16(804, 0, -414);
            glVertex3v16(804, 0, 405);
            glVertex3v16(3261, 0, -414);
            glVertex3v16(3261, 0, 405);
            glVertex3v16(3261, 0, -414);
            glVertex3v16(804, 0, 405);
            glVertex3v16(3261, 0, 2047);
            glVertex3v16(4071, 0, 2047);
            glVertex3v16(3261, 0, -1230);
            glVertex3v16(4071, 0, -1230);
            glVertex3v16(3261, 0, -1230);
            glVertex3v16(4071, 0, 2047);
            glVertex3v16(23, 0, -1201);
            glVertex3v16(23, 0, -414);
            glVertex3v16(804, 0, -1201);
            glVertex3v16(804, 0, -414);
            glVertex3v16(804, 0, -1201);
            glVertex3v16(23, 0, -414);
            break;
    }

    glEnd();
}
