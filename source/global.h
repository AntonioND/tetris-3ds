#ifndef GLOBAL_H__
#define GLOBAL_H__

extern bool MENU_ACTIVO, JUEGO_ACTIVO, PAUSA;
extern u8 pausa_lista;
extern u8 MODO_DE_JUEGO;
extern int opcionmenu, submenu;
extern s32 puntuacion_total, /*puntuacion_record,*/ linecount, puntuacion_total_CPU, linecount_CPU;

extern u8 combo, combo_CPU;

typedef struct
{
    char Nombre[10];
    u32 Puntuacion;
    u16 Lineas;
} __RECORD_STRUCT__;

extern __RECORD_STRUCT__ Record[10];

extern bool UPDATE_2D;
extern u8 lasttime;

extern bool READY;

#define CAMERA_DISABLED     0
#define CAMERA_SLOW         1
#define CAMERA_QUICK        2

extern u8 texture_selected, camera_selected, USE_SOUND, MASTER_SOUND;

extern float velocidad;
extern int framecount, velocidadcount, girarcount, velocidadcount_CPU, girarcount_CPU;

extern u8 Caida_rapida_CPU, jugador_ganador;

extern float rotarsalaX, rotarsalaY, rotarsalaZ;
extern float fondorojo, fondoverde, fondoazul;
extern float incrementorojo, incrementoverde, incrementoazul;

extern int auxiliar, acumulador, auxiliar2, auxiliar3;

#define ANCHO_PIEZAS    10
#define ALTO_PIEZAS     15

typedef struct
{
    float red, green, blue;
    u8 dibujar;
} CUBO_TETRIS;

extern int Fila_Eliminada[ALTO_PIEZAS + 2];
extern int Fila_Eliminada_CPU[ALTO_PIEZAS + 2];

typedef struct
{
    s8 X, Y;
    u8 Rotacion;
} PIEZA_TETRIS;

extern CUBO_TETRIS Escenario_Tetris[ANCHO_PIEZAS][ALTO_PIEZAS + 2];
extern CUBO_TETRIS Escenario_Tetris_CPU[ANCHO_PIEZAS][ALTO_PIEZAS + 2];
extern PIEZA_TETRIS Pieza;
extern PIEZA_TETRIS Pieza_CPU;

extern u8 Tipo_Pieza[5]; // 0 = Actual
extern u8 Tipo_Pieza_CPU[5];

extern u8 Colisiones_Actual[16]; //Cuadrícula
extern u8 Colisiones_Actual_CPU[16];

typedef struct
{
    float red, redincrement;
    float green, greenincrement;
    float blue, blueincrement;
} _TEXT_DATA_;

extern _TEXT_DATA_ Text_Color;

//Modos de juego
#define MODO_NORMAL     0
#define MODO_CONTRA_CPU 1

void PowerOFF_Countdown(u8 seconds);

// Valor absoluto para variables del tipo float
static inline float Float_Abs(float num)
{
    if (num < 0)
        return -num;
    return num;
}

static inline int Limitar_int(int min, int max, int numero)
{
    if (numero < min)
        return min;
    if (numero > max)
        return max;
    return numero;
}

static inline float Limitar_float(float min, float max, float numero)
{
    if (numero < min)
        return min;
    if (numero > max)
        return max;
    return numero;
}

void Reset_Records();

#endif // GLOBAL_H__
