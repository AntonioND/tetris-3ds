// SPDX-License-Identifier: GPL-3.0-only
//
// Copyright (c) 2008, 2024-2025 Antonio Niño Díaz

#include <nds.h>

#include "graficos_3d/texto/letras.h"
#include "graficos_3d/texto/numeros.h"

void Dibujar_Letra(int NUMERO, float RED, float GREEN, float BLUE)
{
    glBegin(GL_TRIANGLES);
    glColor3f(RED, GREEN, BLUE);

    switch (NUMERO)
    {
        case 0:
            // A
            glVertex3v16(3298, 0, 2079);
            glVertex3v16(4210, 0, 2079);
            glVertex3v16(3298, 0, -2049);
            glVertex3v16(4210, 0, -2049);
            glVertex3v16(3298, 0, -2049);
            glVertex3v16(4210, 0, 2079);
            glVertex3v16(3, 0, 2079);
            glVertex3v16(864, 0, 2079);
            glVertex3v16(3, 0, -2049);
            glVertex3v16(864, 0, -2049);
            glVertex3v16(3, 0, -2049);
            glVertex3v16(864, 0, 2079);
            glVertex3v16(864, 0, -2049);
            glVertex3v16(864, 0, -1240);
            glVertex3v16(3298, 0, -2049);
            glVertex3v16(3298, 0, -1240);
            glVertex3v16(3298, 0, -2049);
            glVertex3v16(864, 0, -1240);
            glVertex3v16(864, 0, 59);
            glVertex3v16(864, 0, 869);
            glVertex3v16(3298, 0, 59);
            glVertex3v16(3298, 0, 869);
            glVertex3v16(3298, 0, 59);
            glVertex3v16(864, 0, 869);
            break;

        case 1:
            // B
            glVertex3v16(3358, 0, 398);
            glVertex3v16(3358, 0, 1211);
            glVertex3v16(4143, 0, 398);
            glVertex3v16(4143, 0, 1211);
            glVertex3v16(4143, 0, 398);
            glVertex3v16(3358, 0, 1211);
            glVertex3v16(918, 0, -395);
            glVertex3v16(918, 0, 398);
            glVertex3v16(3375, 0, -395);
            glVertex3v16(3375, 0, 398);
            glVertex3v16(3375, 0, -395);
            glVertex3v16(918, 0, 398);
            glVertex3v16(3, 0, 2029);
            glVertex3v16(915, 0, 2029);
            glVertex3v16(3, 0, -2099);
            glVertex3v16(915, 0, -2099);
            glVertex3v16(3, 0, -2099);
            glVertex3v16(915, 0, 2029);
            glVertex3v16(903, 0, -2099);
            glVertex3v16(903, 0, -1306);
            glVertex3v16(3360, 0, -2099);
            glVertex3v16(3360, 0, -1306);
            glVertex3v16(3360, 0, -2099);
            glVertex3v16(903, 0, -1306);
            glVertex3v16(917, 0, 1211);
            glVertex3v16(917, 0, 2029);
            glVertex3v16(3374, 0, 1211);
            glVertex3v16(3374, 0, 2029);
            glVertex3v16(3374, 0, 1211);
            glVertex3v16(917, 0, 2029);
            glVertex3v16(3335, 0, -1252);
            glVertex3v16(3335, 0, -395);
            glVertex3v16(4145, 0, -1252);
            glVertex3v16(4145, 0, -395);
            glVertex3v16(4145, 0, -1252);
            glVertex3v16(3335, 0, -395);
            break;

        case 2:
            // C
            glVertex3v16(37, 0, -1176);
            glVertex3v16(37, 0, 1255);
            glVertex3v16(873, 0, -1176);
            glVertex3v16(873, 0, 1255);
            glVertex3v16(873, 0, -1176);
            glVertex3v16(37, 0, 1255);
            glVertex3v16(37, 0, 1255);
            glVertex3v16(37, 0, 2091);
            glVertex3v16(4191, 0, 1255);
            glVertex3v16(4191, 0, 2091);
            glVertex3v16(4191, 0, 1255);
            glVertex3v16(37, 0, 2091);
            glVertex3v16(37, 0, -2012);
            glVertex3v16(37, 0, -1176);
            glVertex3v16(4191, 0, -2012);
            glVertex3v16(4191, 0, -1176);
            glVertex3v16(4191, 0, -2012);
            glVertex3v16(37, 0, -1176);
            break;

        case 3:
            // D
            glVertex3v16(37, 0, -1226);
            glVertex3v16(37, 0, 1356);
            glVertex3v16(873, 0, -1226);
            glVertex3v16(873, 0, 1356);
            glVertex3v16(873, 0, -1226);
            glVertex3v16(37, 0, 1356);
            glVertex3v16(37, 0, 1356);
            glVertex3v16(37, 0, 2116);
            glVertex3v16(2483, 0, 1356);
            glVertex3v16(2483, 0, 2116);
            glVertex3v16(2483, 0, 1356);
            glVertex3v16(37, 0, 2116);
            glVertex3v16(2478, 0, -1226);
            glVertex3v16(2478, 0, 1356);
            glVertex3v16(3314, 0, -1226);
            glVertex3v16(3314, 0, 1356);
            glVertex3v16(3314, 0, -1226);
            glVertex3v16(2478, 0, 1356);
            glVertex3v16(37, 0, -1986);
            glVertex3v16(37, 0, -1226);
            glVertex3v16(2483, 0, -1986);
            glVertex3v16(2483, 0, -1226);
            glVertex3v16(2483, 0, -1986);
            glVertex3v16(37, 0, -1226);
            break;

        case 4:
            // E
            glVertex3v16(851, 0, -385);
            glVertex3v16(851, 0, 425);
            glVertex3v16(3331, 0, -385);
            glVertex3v16(3331, 0, 425);
            glVertex3v16(3331, 0, -385);
            glVertex3v16(851, 0, 425);
            glVertex3v16(15, 0, 1257);
            glVertex3v16(15, 0, 2169);
            glVertex3v16(4169, 0, 1257);
            glVertex3v16(4169, 0, 2169);
            glVertex3v16(4169, 0, 1257);
            glVertex3v16(15, 0, 2169);
            glVertex3v16(15, 0, -1200);
            glVertex3v16(15, 0, 1382);
            glVertex3v16(851, 0, -1200);
            glVertex3v16(851, 0, 1382);
            glVertex3v16(851, 0, -1200);
            glVertex3v16(15, 0, 1382);
            glVertex3v16(15, 0, -2036);
            glVertex3v16(15, 0, -1124);
            glVertex3v16(4169, 0, -2036);
            glVertex3v16(4169, 0, -1124);
            glVertex3v16(4169, 0, -2036);
            glVertex3v16(15, 0, -1124);
            break;

        case 5:
            // F
            glVertex3v16(40, 0, -2036);
            glVertex3v16(40, 0, -1124);
            glVertex3v16(4169, 0, -2036);
            glVertex3v16(4169, 0, -1124);
            glVertex3v16(4169, 0, -2036);
            glVertex3v16(40, 0, -1124);
            glVertex3v16(875, 0, -385);
            glVertex3v16(875, 0, 425);
            glVertex3v16(3331, 0, -385);
            glVertex3v16(3331, 0, 425);
            glVertex3v16(3331, 0, -385);
            glVertex3v16(875, 0, 425);
            glVertex3v16(40, 0, -1146);
            glVertex3v16(40, 0, 2170);
            glVertex3v16(875, 0, -1146);
            glVertex3v16(875, 0, 2170);
            glVertex3v16(875, 0, -1146);
            glVertex3v16(40, 0, 2170);
            break;

        case 6:
            // G
            glVertex3v16(50, 0, -1219);
            glVertex3v16(50, 0, 1211);
            glVertex3v16(886, 0, -1219);
            glVertex3v16(886, 0, 1211);
            glVertex3v16(886, 0, -1219);
            glVertex3v16(50, 0, 1211);
            glVertex3v16(50, 0, 1211);
            glVertex3v16(50, 0, 2047);
            glVertex3v16(4204, 0, 1211);
            glVertex3v16(4204, 0, 2047);
            glVertex3v16(4204, 0, 1211);
            glVertex3v16(50, 0, 2047);
            glVertex3v16(1680, 0, -427);
            glVertex3v16(1680, 0, 408);
            glVertex3v16(4204, 0, -427);
            glVertex3v16(4204, 0, 408);
            glVertex3v16(4204, 0, -427);
            glVertex3v16(1680, 0, 408);
            glVertex3v16(3398, 0, 408);
            glVertex3v16(3398, 0, 1211);
            glVertex3v16(4204, 0, 408);
            glVertex3v16(4204, 0, 1211);
            glVertex3v16(4204, 0, 408);
            glVertex3v16(3398, 0, 1211);
            glVertex3v16(50, 0, -2055);
            glVertex3v16(50, 0, -1219);
            glVertex3v16(4204, 0, -2055);
            glVertex3v16(4204, 0, -1219);
            glVertex3v16(4204, 0, -2055);
            glVertex3v16(50, 0, -1219);
            break;

        case 7:
            // H
            glVertex3v16(890, 0, -304);
            glVertex3v16(890, 0, 505);
            glVertex3v16(3346, 0, -304);
            glVertex3v16(3346, 0, 505);
            glVertex3v16(3346, 0, -304);
            glVertex3v16(890, 0, 505);
            glVertex3v16(-26, 0, 2079);
            glVertex3v16(885, 0, 2079);
            glVertex3v16(-26, 0, -2049);
            glVertex3v16(885, 0, -2049);
            glVertex3v16(-26, 0, -2049);
            glVertex3v16(885, 0, 2079);
            glVertex3v16(3268, 0, 2079);
            glVertex3v16(4180, 0, 2079);
            glVertex3v16(3268, 0, -2049);
            glVertex3v16(4180, 0, -2049);
            glVertex3v16(3268, 0, -2049);
            glVertex3v16(4180, 0, 2079);
            break;

        case 8:
            // I
            glVertex3v16(865, 0, 2216);
            glVertex3v16(3460, 0, 2216);
            glVertex3v16(865, 0, 1355);
            glVertex3v16(3460, 0, 1355);
            glVertex3v16(865, 0, 1355);
            glVertex3v16(3460, 0, 2216);
            glVertex3v16(1730, 0, -1204);
            glVertex3v16(1730, 0, 1355);
            glVertex3v16(2595, 0, -1204);
            glVertex3v16(2595, 0, 1355);
            glVertex3v16(2595, 0, -1204);
            glVertex3v16(1730, 0, 1355);
            glVertex3v16(865, 0, -1202);
            glVertex3v16(3460, 0, -1202);
            glVertex3v16(865, 0, -2038);
            glVertex3v16(3460, 0, -2038);
            glVertex3v16(865, 0, -2038);
            glVertex3v16(3460, 0, -1202);
            break;

        case 9:
            // J
            glVertex3v16(858, 0, 1313);
            glVertex3v16(858, 0, 2172);
            glVertex3v16(2506, 0, 1313);
            glVertex3v16(2506, 0, 2172);
            glVertex3v16(2506, 0, 1313);
            glVertex3v16(858, 0, 2172);
            glVertex3v16(0, 0, 507);
            glVertex3v16(0, 0, 1318);
            glVertex3v16(810, 0, 507);
            glVertex3v16(810, 0, 1318);
            glVertex3v16(810, 0, 507);
            glVertex3v16(0, 0, 1318);
            glVertex3v16(2540, 0, -1176);
            glVertex3v16(2540, 0, 1255);
            glVertex3v16(3376, 0, -1176);
            glVertex3v16(3376, 0, 1255);
            glVertex3v16(3376, 0, -1176);
            glVertex3v16(2540, 0, 1255);
            glVertex3v16(4, 0, -2012);
            glVertex3v16(4, 0, -1176);
            glVertex3v16(4158, 0, -2012);
            glVertex3v16(4158, 0, -1176);
            glVertex3v16(4158, 0, -2012);
            glVertex3v16(4, 0, -1176);
            break;

        case 10:
            // K
            glVertex3v16(1734, 0, -1191);
            glVertex3v16(1734, 0, -380);
            glVertex3v16(2544, 0, -1191);
            glVertex3v16(2544, 0, -380);
            glVertex3v16(2544, 0, -1191);
            glVertex3v16(1734, 0, -380);
            glVertex3v16(895, 0, -380);
            glVertex3v16(895, 0, 404);
            glVertex3v16(1705, 0, -380);
            glVertex3v16(1705, 0, 404);
            glVertex3v16(1705, 0, -380);
            glVertex3v16(895, 0, 404);
            glVertex3v16(1596, 0, 404);
            glVertex3v16(1596, 0, 1265);
            glVertex3v16(2457, 0, 404);
            glVertex3v16(2457, 0, 1265);
            glVertex3v16(2457, 0, 404);
            glVertex3v16(1596, 0, 1265);
            glVertex3v16(2426, 0, 1256);
            glVertex3v16(2426, 0, 2117);
            glVertex3v16(3288, 0, 1256);
            glVertex3v16(3288, 0, 2117);
            glVertex3v16(3288, 0, 1256);
            glVertex3v16(2426, 0, 2117);
            glVertex3v16(2562, 0, -2016);
            glVertex3v16(2562, 0, -1206);
            glVertex3v16(3372, 0, -2016);
            glVertex3v16(3372, 0, -1206);
            glVertex3v16(3372, 0, -2016);
            glVertex3v16(2562, 0, -1206);
            glVertex3v16(68, 0, -2052);
            glVertex3v16(68, 0, 2075);
            glVertex3v16(904, 0, -2052);
            glVertex3v16(904, 0, 2075);
            glVertex3v16(904, 0, -2052);
            glVertex3v16(68, 0, 2075);
            break;

        case 11:
            // L
            glVertex3v16(-40, 0, 1287);
            glVertex3v16(-40, 0, 2147);
            glVertex3v16(4150, 0, 1287);
            glVertex3v16(4150, 0, 2147);
            glVertex3v16(4150, 0, 1287);
            glVertex3v16(-40, 0, 2147);
            glVertex3v16(-40, 0, -1971);
            glVertex3v16(-40, 0, 1287);
            glVertex3v16(819, 0, -1971);
            glVertex3v16(819, 0, 1287);
            glVertex3v16(819, 0, -1971);
            glVertex3v16(-40, 0, 1287);
            break;

        case 12:
            // M
            glVertex3v16(844, 0, -1111);
            glVertex3v16(844, 0, -301);
            glVertex3v16(1655, 0, -1111);
            glVertex3v16(1655, 0, -301);
            glVertex3v16(1655, 0, -1111);
            glVertex3v16(844, 0, -301);
            glVertex3v16(1655, 0, -301);
            glVertex3v16(1655, 0, 483);
            glVertex3v16(2465, 0, -301);
            glVertex3v16(2465, 0, 483);
            glVertex3v16(2465, 0, -301);
            glVertex3v16(1655, 0, 483);
            glVertex3v16(2465, 0, -1100);
            glVertex3v16(2465, 0, -239);
            glVertex3v16(3326, 0, -1100);
            glVertex3v16(3326, 0, -239);
            glVertex3v16(3326, 0, -1100);
            glVertex3v16(2465, 0, -239);
            glVertex3v16(3326, 0, -1947);
            glVertex3v16(3326, 0, 2180);
            glVertex3v16(4187, 0, -1947);
            glVertex3v16(4187, 0, 2180);
            glVertex3v16(4187, 0, -1947);
            glVertex3v16(3326, 0, 2180);
            glVertex3v16(8, 0, -1973);
            glVertex3v16(8, 0, 2155);
            glVertex3v16(844, 0, -1973);
            glVertex3v16(844, 0, 2155);
            glVertex3v16(844, 0, -1973);
            glVertex3v16(8, 0, 2155);
            break;

        case 13:
            // N
            glVertex3v16(844, 0, -1111);
            glVertex3v16(844, 0, -301);
            glVertex3v16(1655, 0, -1111);
            glVertex3v16(1655, 0, -301);
            glVertex3v16(1655, 0, -1111);
            glVertex3v16(844, 0, -301);
            glVertex3v16(1655, 0, -301);
            glVertex3v16(1655, 0, 483);
            glVertex3v16(2465, 0, -301);
            glVertex3v16(2465, 0, 483);
            glVertex3v16(2465, 0, -301);
            glVertex3v16(1655, 0, 483);
            glVertex3v16(2465, 0, 494);
            glVertex3v16(2465, 0, 1355);
            glVertex3v16(3326, 0, 494);
            glVertex3v16(3326, 0, 1355);
            glVertex3v16(3326, 0, 494);
            glVertex3v16(2465, 0, 1355);
            glVertex3v16(3326, 0, -1947);
            glVertex3v16(3326, 0, 2180);
            glVertex3v16(4187, 0, -1947);
            glVertex3v16(4187, 0, 2180);
            glVertex3v16(4187, 0, -1947);
            glVertex3v16(3326, 0, 2180);
            glVertex3v16(8, 0, -1973);
            glVertex3v16(8, 0, 2155);
            glVertex3v16(844, 0, -1973);
            glVertex3v16(844, 0, 2155);
            glVertex3v16(844, 0, -1973);
            glVertex3v16(8, 0, 2155);
            break;

        case 14:
            // Ñ
            glVertex3v16(844, 0, -1111);
            glVertex3v16(844, 0, -301);
            glVertex3v16(1655, 0, -1111);
            glVertex3v16(1655, 0, -301);
            glVertex3v16(1655, 0, -1111);
            glVertex3v16(844, 0, -301);
            glVertex3v16(1655, 0, -301);
            glVertex3v16(1655, 0, 483);
            glVertex3v16(2465, 0, -301);
            glVertex3v16(2465, 0, 483);
            glVertex3v16(2465, 0, -301);
            glVertex3v16(1655, 0, 483);
            glVertex3v16(2465, 0, 494);
            glVertex3v16(2465, 0, 1355);
            glVertex3v16(3326, 0, 494);
            glVertex3v16(3326, 0, 1355);
            glVertex3v16(3326, 0, 494);
            glVertex3v16(2465, 0, 1355);
            glVertex3v16(4, 0, -2788);
            glVertex3v16(4132, 0, -2788);
            glVertex3v16(4, 0, -3624);
            glVertex3v16(4132, 0, -3624);
            glVertex3v16(4, 0, -3624);
            glVertex3v16(4132, 0, -2788);
            glVertex3v16(3326, 0, -1947);
            glVertex3v16(3326, 0, 2180);
            glVertex3v16(4187, 0, -1947);
            glVertex3v16(4187, 0, 2180);
            glVertex3v16(4187, 0, -1947);
            glVertex3v16(3326, 0, 2180);
            glVertex3v16(8, 0, -1973);
            glVertex3v16(8, 0, 2155);
            glVertex3v16(844, 0, -1973);
            glVertex3v16(844, 0, 2155);
            glVertex3v16(844, 0, -1973);
            glVertex3v16(8, 0, 2155);
            break;

        case 15:
            // O
            glVertex3v16(20, 0, -1162);
            glVertex3v16(20, 0, 1268);
            glVertex3v16(856, 0, -1162);
            glVertex3v16(856, 0, 1268);
            glVertex3v16(856, 0, -1162);
            glVertex3v16(20, 0, 1268);
            glVertex3v16(20, 0, 1268);
            glVertex3v16(20, 0, 2104);
            glVertex3v16(4174, 0, 1268);
            glVertex3v16(4174, 0, 2104);
            glVertex3v16(4174, 0, 1268);
            glVertex3v16(20, 0, 2104);
            glVertex3v16(3363, 0, -1162);
            glVertex3v16(3363, 0, 1268);
            glVertex3v16(4174, 0, -1162);
            glVertex3v16(4174, 0, 1268);
            glVertex3v16(4174, 0, -1162);
            glVertex3v16(3363, 0, 1268);
            glVertex3v16(20, 0, -1998);
            glVertex3v16(20, 0, -1162);
            glVertex3v16(4174, 0, -1998);
            glVertex3v16(4174, 0, -1162);
            glVertex3v16(4174, 0, -1998);
            glVertex3v16(20, 0, -1162);
            break;

        case 16:
            // P
            glVertex3v16(66, 0, -1162);
            glVertex3v16(66, 0, 2155);
            glVertex3v16(927, 0, -1162);
            glVertex3v16(927, 0, 2155);
            glVertex3v16(927, 0, -1162);
            glVertex3v16(66, 0, 2155);
            glVertex3v16(876, 0, -276);
            glVertex3v16(876, 0, 559);
            glVertex3v16(3384, 0, -276);
            glVertex3v16(3384, 0, 559);
            glVertex3v16(3384, 0, -276);
            glVertex3v16(876, 0, 559);
            glVertex3v16(3333, 0, -1162);
            glVertex3v16(3333, 0, -276);
            glVertex3v16(4169, 0, -1162);
            glVertex3v16(4169, 0, -276);
            glVertex3v16(4169, 0, -1162);
            glVertex3v16(3333, 0, -276);
            glVertex3v16(66, 0, -2023);
            glVertex3v16(66, 0, -1137);
            glVertex3v16(3358, 0, -2023);
            glVertex3v16(3358, 0, -1137);
            glVertex3v16(3358, 0, -2023);
            glVertex3v16(66, 0, -1137);
            break;

        case 17:
            // Q
            glVertex3v16(3251, 0, 1267);
            glVertex3v16(3251, 0, 2052);
            glVertex3v16(4062, 0, 1267);
            glVertex3v16(4062, 0, 2052);
            glVertex3v16(4062, 0, 1267);
            glVertex3v16(3251, 0, 2052);
            glVertex3v16(0, 0, -1185);
            glVertex3v16(0, 0, 435);
            glVertex3v16(869, 0, -1185);
            glVertex3v16(869, 0, 435);
            glVertex3v16(869, 0, -1185);
            glVertex3v16(0, 0, 435);
            glVertex3v16(2396, 0, -1170);
            glVertex3v16(2396, 0, 450);
            glVertex3v16(3251, 0, -1170);
            glVertex3v16(3251, 0, 450);
            glVertex3v16(3251, 0, -1170);
            glVertex3v16(2396, 0, 450);
            glVertex3v16(0, 0, 415);
            glVertex3v16(0, 0, 1301);
            glVertex3v16(3251, 0, 415);
            glVertex3v16(3251, 0, 1301);
            glVertex3v16(3251, 0, 415);
            glVertex3v16(0, 0, 1301);
            glVertex3v16(0, 0, -2052);
            glVertex3v16(0, 0, -1202);
            glVertex3v16(3251, 0, -2052);
            glVertex3v16(3251, 0, -1202);
            glVertex3v16(3251, 0, -2052);
            glVertex3v16(0, 0, -1202);
            break;

        case 18:
            // R
            glVertex3v16(824, 0, -289);
            glVertex3v16(824, 0, 546);
            glVertex3v16(3331, 0, -289);
            glVertex3v16(3331, 0, 546);
            glVertex3v16(3331, 0, -289);
            glVertex3v16(824, 0, 546);
            glVertex3v16(2542, 0, 507);
            glVertex3v16(2542, 0, 1318);
            glVertex3v16(3331, 0, 507);
            glVertex3v16(3331, 0, 1318);
            glVertex3v16(3331, 0, 507);
            glVertex3v16(2542, 0, 1318);
            glVertex3v16(3331, 0, -1176);
            glVertex3v16(3331, 0, -289);
            glVertex3v16(4116, 0, -1176);
            glVertex3v16(4116, 0, -289);
            glVertex3v16(4116, 0, -1176);
            glVertex3v16(3331, 0, -289);
            glVertex3v16(3331, 0, 1318);
            glVertex3v16(3331, 0, 2103);
            glVertex3v16(4163, 0, 1318);
            glVertex3v16(4163, 0, 2103);
            glVertex3v16(4163, 0, 1318);
            glVertex3v16(3331, 0, 2103);
            glVertex3v16(13, 0, -1176);
            glVertex3v16(13, 0, 2141);
            glVertex3v16(875, 0, -1176);
            glVertex3v16(875, 0, 2141);
            glVertex3v16(875, 0, -1176);
            glVertex3v16(13, 0, 2141);
            glVertex3v16(13, 0, -2037);
            glVertex3v16(13, 0, -1150);
            glVertex3v16(3331, 0, -2037);
            glVertex3v16(3331, 0, -1150);
            glVertex3v16(3331, 0, -2037);
            glVertex3v16(13, 0, -1150);
            break;

        case 19:
            // S
            glVertex3v16(3191, 0, 435);
            glVertex3v16(3191, 0, 1220);
            glVertex3v16(3977, 0, 435);
            glVertex3v16(3977, 0, 1220);
            glVertex3v16(3977, 0, 435);
            glVertex3v16(3191, 0, 1220);
            glVertex3v16(1, 0, -315);
            glVertex3v16(1, 0, 470);
            glVertex3v16(3977, 0, -315);
            glVertex3v16(3977, 0, 470);
            glVertex3v16(3977, 0, -315);
            glVertex3v16(1, 0, 470);
            glVertex3v16(1, 0, -1150);
            glVertex3v16(1, 0, -315);
            glVertex3v16(811, 0, -1150);
            glVertex3v16(811, 0, -315);
            glVertex3v16(811, 0, -1150);
            glVertex3v16(1, 0, -315);
            glVertex3v16(1, 0, 1194);
            glVertex3v16(1, 0, 2030);
            glVertex3v16(3977, 0, 1194);
            glVertex3v16(3977, 0, 2030);
            glVertex3v16(3977, 0, 1194);
            glVertex3v16(1, 0, 2030);
            glVertex3v16(1, 0, -1961);
            glVertex3v16(1, 0, -1150);
            glVertex3v16(3977, 0, -1961);
            glVertex3v16(3977, 0, -1150);
            glVertex3v16(3977, 0, -1961);
            glVertex3v16(1, 0, -1150);
            break;

        case 20:
            // T
            glVertex3v16(1742, 0, -1176);
            glVertex3v16(1742, 0, 2141);
            glVertex3v16(2603, 0, -1176);
            glVertex3v16(2603, 0, 2141);
            glVertex3v16(2603, 0, -1176);
            glVertex3v16(1742, 0, 2141);
            glVertex3v16(5, 0, -2037);
            glVertex3v16(5, 0, -1201);
            glVertex3v16(4158, 0, -2037);
            glVertex3v16(4158, 0, -1201);
            glVertex3v16(4158, 0, -2037);
            glVertex3v16(5, 0, -1201);
            break;

        case 21:
            // U
            glVertex3v16(875, 0, 2136);
            glVertex3v16(3306, 0, 2136);
            glVertex3v16(875, 0, 1300);
            glVertex3v16(3306, 0, 1300);
            glVertex3v16(875, 0, 1300);
            glVertex3v16(3306, 0, 2136);
            glVertex3v16(3306, 0, 2136);
            glVertex3v16(4142, 0, 2136);
            glVertex3v16(3306, 0, -2017);
            glVertex3v16(4142, 0, -2017);
            glVertex3v16(3306, 0, -2017);
            glVertex3v16(4142, 0, 2136);
            glVertex3v16(39, 0, 2136);
            glVertex3v16(875, 0, 2136);
            glVertex3v16(39, 0, -2017);
            glVertex3v16(875, 0, -2017);
            glVertex3v16(39, 0, -2017);
            glVertex3v16(875, 0, 2136);
            break;

        case 22:
            // V
            glVertex3v16(852, 0, -367);
            glVertex3v16(852, 0, 1253);
            glVertex3v16(1713, 0, -367);
            glVertex3v16(1713, 0, 1253);
            glVertex3v16(1713, 0, -367);
            glVertex3v16(852, 0, 1253);
            glVertex3v16(2526, 0, -367);
            glVertex3v16(2526, 0, 1253);
            glVertex3v16(3387, 0, -367);
            glVertex3v16(3387, 0, 1253);
            glVertex3v16(3387, 0, -367);
            glVertex3v16(2526, 0, 1253);
            glVertex3v16(1, 0, -1988);
            glVertex3v16(1, 0, -367);
            glVertex3v16(862, 0, -1988);
            glVertex3v16(862, 0, -367);
            glVertex3v16(862, 0, -1988);
            glVertex3v16(1, 0, -367);
            glVertex3v16(3371, 0, -1988);
            glVertex3v16(3371, 0, -367);
            glVertex3v16(4233, 0, -1988);
            glVertex3v16(4233, 0, -367);
            glVertex3v16(4233, 0, -1988);
            glVertex3v16(3371, 0, -367);
            glVertex3v16(1693, 0, 1253);
            glVertex3v16(1693, 0, 2140);
            glVertex3v16(2529, 0, 1253);
            glVertex3v16(2529, 0, 2140);
            glVertex3v16(2529, 0, 1253);
            glVertex3v16(1693, 0, 2140);
            break;

        case 23:
            // W
            glVertex3v16(2416, 0, 1278);
            glVertex3v16(2416, 0, 2088);
            glVertex3v16(3252, 0, 1278);
            glVertex3v16(3252, 0, 2088);
            glVertex3v16(3252, 0, 1278);
            glVertex3v16(2416, 0, 2088);
            glVertex3v16(1541, 0, -1114);
            glVertex3v16(1541, 0, 1291);
            glVertex3v16(2427, 0, -1114);
            glVertex3v16(2427, 0, 1291);
            glVertex3v16(2427, 0, -1114);
            glVertex3v16(1541, 0, 1291);
            glVertex3v16(3197, 0, -2072);
            glVertex3v16(3197, 0, 1270);
            glVertex3v16(4033, 0, -2072);
            glVertex3v16(4033, 0, 1270);
            glVertex3v16(4033, 0, -2072);
            glVertex3v16(3197, 0, 1270);
            glVertex3v16(804, 0, 1320);
            glVertex3v16(804, 0, 2088);
            glVertex3v16(1563, 0, 1320);
            glVertex3v16(1563, 0, 2088);
            glVertex3v16(1563, 0, 1320);
            glVertex3v16(804, 0, 2088);
            glVertex3v16(32, 0, -1997);
            glVertex3v16(32, 0, 1345);
            glVertex3v16(804, 0, -1997);
            glVertex3v16(804, 0, 1345);
            glVertex3v16(804, 0, -1997);
            glVertex3v16(32, 0, 1345);
            break;

        case 24:
            // X
            glVertex3v16(1545, 0, -407);
            glVertex3v16(1545, 0, 479);
            glVertex3v16(2380, 0, -407);
            glVertex3v16(2380, 0, 479);
            glVertex3v16(2380, 0, -407);
            glVertex3v16(1545, 0, 479);
            glVertex3v16(3208, 0, -1951);
            glVertex3v16(3208, 0, -1166);
            glVertex3v16(4018, 0, -1951);
            glVertex3v16(4018, 0, -1166);
            glVertex3v16(4018, 0, -1951);
            glVertex3v16(3208, 0, -1166);
            glVertex3v16(783, 0, 485);
            glVertex3v16(783, 0, 1295);
            glVertex3v16(1593, 0, 485);
            glVertex3v16(1593, 0, 1295);
            glVertex3v16(1593, 0, 485);
            glVertex3v16(783, 0, 1295);
            glVertex3v16(2403, 0, 485);
            glVertex3v16(2403, 0, 1295);
            glVertex3v16(3213, 0, 485);
            glVertex3v16(3213, 0, 1295);
            glVertex3v16(3213, 0, 485);
            glVertex3v16(2403, 0, 1295);
            glVertex3v16(-3, 0, -1951);
            glVertex3v16(-3, 0, -1166);
            glVertex3v16(806, 0, -1951);
            glVertex3v16(806, 0, -1166);
            glVertex3v16(806, 0, -1951);
            glVertex3v16(-3, 0, -1166);
            glVertex3v16(783, 0, -1193);
            glVertex3v16(783, 0, -382);
            glVertex3v16(1593, 0, -1193);
            glVertex3v16(1593, 0, -382);
            glVertex3v16(1593, 0, -1193);
            glVertex3v16(783, 0, -382);
            glVertex3v16(2403, 0, -1193);
            glVertex3v16(2403, 0, -382);
            glVertex3v16(3213, 0, -1193);
            glVertex3v16(3213, 0, -382);
            glVertex3v16(3213, 0, -1193);
            glVertex3v16(2403, 0, -382);
            glVertex3v16(3208, 0, 1295);
            glVertex3v16(3208, 0, 2081);
            glVertex3v16(4018, 0, 1295);
            glVertex3v16(4018, 0, 2081);
            glVertex3v16(4018, 0, 1295);
            glVertex3v16(3208, 0, 2081);
            glVertex3v16(-3, 0, 1295);
            glVertex3v16(-3, 0, 2081);
            glVertex3v16(806, 0, 1295);
            glVertex3v16(806, 0, 2081);
            glVertex3v16(806, 0, 1295);
            glVertex3v16(-3, 0, 2081);
            break;

        case 25:
            // Y
            glVertex3v16(62, 0, -2114);
            glVertex3v16(62, 0, -1253);
            glVertex3v16(923, 0, -2114);
            glVertex3v16(923, 0, -1253);
            glVertex3v16(923, 0, -2114);
            glVertex3v16(62, 0, -1253);
            glVertex3v16(2522, 0, -1198);
            glVertex3v16(2522, 0, -387);
            glVertex3v16(3332, 0, -1198);
            glVertex3v16(3332, 0, -387);
            glVertex3v16(3332, 0, -1198);
            glVertex3v16(2522, 0, -387);
            glVertex3v16(882, 0, -1288);
            glVertex3v16(882, 0, -401);
            glVertex3v16(1718, 0, -1288);
            glVertex3v16(1718, 0, -401);
            glVertex3v16(1718, 0, -1288);
            glVertex3v16(882, 0, -401);
            glVertex3v16(3332, 0, -1986);
            glVertex3v16(3332, 0, -1201);
            glVertex3v16(4143, 0, -1986);
            glVertex3v16(4143, 0, -1201);
            glVertex3v16(4143, 0, -1986);
            glVertex3v16(3332, 0, -1201);
            glVertex3v16(1705, 0, -413);
            glVertex3v16(1705, 0, 2169);
            glVertex3v16(2541, 0, -413);
            glVertex3v16(2541, 0, 2169);
            glVertex3v16(2541, 0, -413);
            glVertex3v16(1705, 0, 2169);
            break;

        case 26:
            // Z
            glVertex3v16(3330, 0, -1227);
            glVertex3v16(3330, 0, -391);
            glVertex3v16(4100, 0, -1227);
            glVertex3v16(4100, 0, -391);
            glVertex3v16(4100, 0, -1227);
            glVertex3v16(3330, 0, -391);
            glVertex3v16(823, 0, 477);
            glVertex3v16(3330, 0, 477);
            glVertex3v16(823, 0, -383);
            glVertex3v16(3330, 0, -383);
            glVertex3v16(823, 0, -383);
            glVertex3v16(3330, 0, 477);
            glVertex3v16(0, 0, 412);
            glVertex3v16(0, 0, 1197);
            glVertex3v16(823, 0, 412);
            glVertex3v16(823, 0, 1197);
            glVertex3v16(823, 0, 412);
            glVertex3v16(0, 0, 1197);
            glVertex3v16(0, 0, 1164);
            glVertex3v16(0, 0, 2000);
            glVertex3v16(4100, 0, 1164);
            glVertex3v16(4100, 0, 2000);
            glVertex3v16(4100, 0, 1164);
            glVertex3v16(0, 0, 2000);
            glVertex3v16(0, 0, -1999);
            glVertex3v16(0, 0, -1188);
            glVertex3v16(4100, 0, -1999);
            glVertex3v16(4100, 0, -1188);
            glVertex3v16(4100, 0, -1999);
            glVertex3v16(0, 0, -1188);
            break;

        case 30:
            // .
            glVertex3v16(852, 0, 381);
            glVertex3v16(852, 0, 1217);
            glVertex3v16(1662, 0, 381);
            glVertex3v16(1662, 0, 1217);
            glVertex3v16(1662, 0, 381);
            glVertex3v16(852, 0, 1217);
            break;

        case 31:
            // ,
            glVertex3v16(797, 0, 1972);
            glVertex3v16(1607, 0, 1972);
            glVertex3v16(797, 0, 351);
            glVertex3v16(1607, 0, 351);
            glVertex3v16(797, 0, 351);
            glVertex3v16(1607, 0, 1972);
            break;

        case 32:
            //¡
            glVertex3v16(820, 0, -654);
            glVertex3v16(820, 0, 1928);
            glVertex3v16(1655, 0, -654);
            glVertex3v16(1655, 0, 1928);
            glVertex3v16(1655, 0, -654);
            glVertex3v16(820, 0, 1928);
            glVertex3v16(763, 0, -2145);
            glVertex3v16(763, 0, -1360);
            glVertex3v16(1574, 0, -2145);
            glVertex3v16(1574, 0, -1360);
            glVertex3v16(1574, 0, -2145);
            glVertex3v16(763, 0, -1360);
            break;

        case 33:
            // !
            glVertex3v16(820, 0, -2192);
            glVertex3v16(820, 0, 390);
            glVertex3v16(1655, 0, -2192);
            glVertex3v16(1655, 0, 390);
            glVertex3v16(1655, 0, -2192);
            glVertex3v16(820, 0, 390);
            glVertex3v16(862, 0, 1239);
            glVertex3v16(862, 0, 2024);
            glVertex3v16(1673, 0, 1239);
            glVertex3v16(1673, 0, 2024);
            glVertex3v16(1673, 0, 1239);
            glVertex3v16(862, 0, 2024);
            break;

        case 34:
            // ¿
            glVertex3v16(827, 0, -456);
            glVertex3v16(827, 0, 354);
            glVertex3v16(1638, 0, -456);
            glVertex3v16(1638, 0, 354);
            glVertex3v16(1638, 0, -456);
            glVertex3v16(827, 0, 354);
            glVertex3v16(862, 0, -2227);
            glVertex3v16(862, 0, -1441);
            glVertex3v16(1673, 0, -2227);
            glVertex3v16(1673, 0, -1441);
            glVertex3v16(1673, 0, -2227);
            glVertex3v16(862, 0, -1441);
            glVertex3v16(2441, 0, 367);
            glVertex3v16(2441, 0, 1152);
            glVertex3v16(3251, 0, 367);
            glVertex3v16(3251, 0, 1152);
            glVertex3v16(3251, 0, 367);
            glVertex3v16(2441, 0, 1152);
            glVertex3v16(821, 0, 1158);
            glVertex3v16(821, 0, 1969);
            glVertex3v16(2442, 0, 1158);
            glVertex3v16(2442, 0, 1969);
            glVertex3v16(2442, 0, 1158);
            glVertex3v16(821, 0, 1969);
            glVertex3v16(70, 0, 353);
            glVertex3v16(70, 0, 1163);
            glVertex3v16(880, 0, 353);
            glVertex3v16(880, 0, 1163);
            glVertex3v16(880, 0, 353);
            glVertex3v16(70, 0, 1163);
            break;

        case 35:
            // ?
            glVertex3v16(1651, 0, -713);
            glVertex3v16(1651, 0, 96);
            glVertex3v16(2462, 0, -713);
            glVertex3v16(2462, 0, 96);
            glVertex3v16(2462, 0, -713);
            glVertex3v16(1651, 0, 96);
            glVertex3v16(1651, 0, 912);
            glVertex3v16(1651, 0, 1697);
            glVertex3v16(2461, 0, 912);
            glVertex3v16(2461, 0, 1697);
            glVertex3v16(2461, 0, 912);
            glVertex3v16(1651, 0, 1697);
            glVertex3v16(2441, 0, -1433);
            glVertex3v16(2441, 0, -713);
            glVertex3v16(3251, 0, -1433);
            glVertex3v16(3251, 0, -713);
            glVertex3v16(3251, 0, -1433);
            glVertex3v16(2441, 0, -713);
            glVertex3v16(821, 0, -2256);
            glVertex3v16(821, 0, -1446);
            glVertex3v16(2442, 0, -2256);
            glVertex3v16(2442, 0, -1446);
            glVertex3v16(2442, 0, -2256);
            glVertex3v16(821, 0, -1446);
            glVertex3v16(70, 0, -1446);
            glVertex3v16(70, 0, -713);
            glVertex3v16(821, 0, -1446);
            glVertex3v16(821, 0, -713);
            glVertex3v16(821, 0, -1446);
            glVertex3v16(70, 0, -713);
            break;

        case 36:
            // @
            glVertex3v16(3356, 0, -1206);
            glVertex3v16(3356, 0, 1300);
            glVertex3v16(4217, 0, -1206);
            glVertex3v16(4217, 0, 1300);
            glVertex3v16(4217, 0, -1206);
            glVertex3v16(3356, 0, 1300);
            glVertex3v16(1873, 0, -304);
            glVertex3v16(1873, 0, 1300);
            glVertex3v16(3449, 0, -304);
            glVertex3v16(3449, 0, 1300);
            glVertex3v16(3449, 0, -304);
            glVertex3v16(1873, 0, 1300);
            glVertex3v16(-16, 0, 2009);
            glVertex3v16(869, 0, 2009);
            glVertex3v16(-16, 0, -1283);
            glVertex3v16(869, 0, -1283);
            glVertex3v16(-16, 0, -1283);
            glVertex3v16(869, 0, 2009);
            glVertex3v16(803, 0, -2027);
            glVertex3v16(803, 0, -1216);
            glVertex3v16(3311, 0, -2027);
            glVertex3v16(3311, 0, -1216);
            glVertex3v16(3311, 0, -2027);
            glVertex3v16(803, 0, -1216);
            glVertex3v16(824, 0, 1997);
            glVertex3v16(824, 0, 2883);
            glVertex3v16(4117, 0, 1997);
            glVertex3v16(4117, 0, 2883);
            glVertex3v16(4117, 0, 1997);
            glVertex3v16(824, 0, 2883);
            break;

        case 37:
            // _
            glVertex3v16(-76, 0, 1287);
            glVertex3v16(-76, 0, 2147);
            glVertex3v16(4150, 0, 1287);
            glVertex3v16(4150, 0, 2147);
            glVertex3v16(4150, 0, 1287);
            glVertex3v16(-76, 0, 2147);
            break;

        case 38:
            // Tilde
            glVertex3v16(2465, 0, -4571);
            glVertex3v16(2465, 0, -3711);
            glVertex3v16(3276, 0, -4571);
            glVertex3v16(3276, 0, -3711);
            glVertex3v16(3276, 0, -4571);
            glVertex3v16(2465, 0, -3711);
            glVertex3v16(1689, 0, -3762);
            glVertex3v16(1689, 0, -2952);
            glVertex3v16(2500, 0, -3762);
            glVertex3v16(2500, 0, -2952);
            glVertex3v16(2500, 0, -3762);
            glVertex3v16(1689, 0, -2952);
            break;
    }

    glEnd();

    if (NUMERO > 99 && NUMERO < 110)
        Dibujar_Numero(NUMERO - 100, RED, GREEN, BLUE);
}
