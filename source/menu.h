#ifndef MENU_H__
#define MENU_H__

#include <nds.h>

typedef struct
{
    float x, y, z;
    float vx, vy, vz;
    float gx, gy, gz;
    u8 tipopieza;
} __ANIMACION_MENU__;

extern __ANIMACION_MENU__ Figura_Menu;

#define ACELERACION_PIEZA   0.005

typedef struct
{
    float r, g, b;
    float ir, ig, ib;
} __FONDO_MENU__;

extern __FONDO_MENU__ Fondo_Menu;

void Draw16bitRectangleEx(u8 screen, s16 x1, s16 y1, s16 x2, s16 y2, u16 color, u8 size);

void Iniciar_3D_Menu(void);
void Actualizar_3D_Menu(void);
void Graficos_3D_Menu(void);

void Menu(void);

#endif // MENU_H__
