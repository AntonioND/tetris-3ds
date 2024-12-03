#include <nds.h>

#include "global.h"

bool MENU_ACTIVO, JUEGO_ACTIVO, PAUSA;
u8 pausa_lista;
u8 MODO_DE_JUEGO;
int opcionmenu, submenu;
s32 puntuacion_total, /*puntuacion_record,*/ linecount, puntuacion_total_CPU, linecount_CPU;

u8 combo, combo_CPU;

__RECORD_STRUCT__ Record[10];

bool UPDATE_2D;
u8 lasttime;

bool READY;

u8 texture_selected, camera_selected, USE_SOUND, MASTER_SOUND;

float velocidad;
int framecount, velocidadcount, girarcount, velocidadcount_CPU, girarcount_CPU;

u8 Caida_rapida_CPU, jugador_ganador;

float rotarsalaX, rotarsalaY, rotarsalaZ;
float fondorojo = 10, fondoverde = 15, fondoazul = 20;
float incrementorojo = 0.2, incrementoverde = 0.15, incrementoazul = 0.1;

//char nombre_record[10], nombre_jugador[10];

int auxiliar, acumulador, auxiliar2, auxiliar3, auxiliar4;
float auxiliar_float;

int Fila_Eliminada[ALTO_PIEZAS + 2];
int Fila_Eliminada_CPU[ALTO_PIEZAS + 2];

CUBO_TETRIS Escenario_Tetris[ANCHO_PIEZAS][ALTO_PIEZAS + 2];
CUBO_TETRIS Escenario_Tetris_CPU[ANCHO_PIEZAS][ALTO_PIEZAS + 2];
PIEZA_TETRIS Pieza;
PIEZA_TETRIS Pieza_CPU;

u8 Tipo_Pieza[5]; // 0 = Actual
u8 Tipo_Pieza_CPU[5];

u8 Colisiones_Actual[16]; //Cuadrícula
u8 Colisiones_Actual_CPU[16];

_TEXT_DATA_ Text_Color;
