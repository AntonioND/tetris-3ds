#ifndef MODOS_DE_JUEGO_JUEGO_H__
#define MODOS_DE_JUEGO_JUEGO_H__

#include <nds.h>

extern float red_,green_,blue_;
extern int temp_y, temp_x, temp_giro;

#define NUMSPRITE_RESERVA 15

extern u8 piezareserva;
extern bool reservallena, reservausada;

#define PAD_UP      1
#define PAD_DOWN    2

extern u8 stylus_usedgravity, stylus_reservausada, stylus_dblclicused;
extern u8 stylus_time, stylus_piezax;

void Controles_Tactiles_Horizontal();
void Controles_Tactiles_Vertical();

extern int lastkeypressed, timepressed;

void Autofire_Keys_Horizontal();
void Autofire_Keys_Vertical();
void Cancelar_Animacion_Eliminar_Lineas();
u8 Borrar_Lineas_Completas();
void Borrar_Linea(u8 altura);
u8 Comprobar_Lineas_Completas();
u8 Comprobar_Linea(u8 altura);
void Ajustar_Colisiones_Actuales();
u8 Estado_Cuadricula(int x, int y);
u8 Comprobar_Colisiones_Inferior();
u8 Comprobar_Colisiones_Derecha();
u8 Comprobar_Colisiones_Izquierda();
u8 Comprobar_Colisiones_Giro();
void Borrar_Pieza_Actual();
void Dibujar_Pieza_Actual();
void Iniciar_Juego();
void Nueva_Pieza();
void Reservar_Pieza();

#endif // MODOS_DE_JUEGO_JUEGO_H__
