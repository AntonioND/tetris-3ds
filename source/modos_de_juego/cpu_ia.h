#ifndef MODOS_DE_JUEGO_CPU_IA_H__
#define MODOS_DE_JUEGO_CPU_IA_H__

#define NUMSPRITE_RESERVA_CPU 16
#define NUM_ROTACIONES		   4

typedef struct
{
    u8 altura;
    u8 huecosdebajo;
    u8 huecostotal;
    u8 superficie;
} _POSICION_IA_;

extern u8 piezareserva_CPU;
extern bool reservallena_CPU, reservausada_CPU;

extern _POSICION_IA_ Posicion_CPU[ANCHO_PIEZAS][NUM_ROTACIONES];
extern PIEZA_TETRIS Almacen_CPU;
extern PIEZA_TETRIS Posicion_Ideal_CPU;

extern int superficie_, huecostotal_, huecosdebajo_;

extern u8 activarreserva;

u8 Comprobar_Superficie_CPU();
u8 Comprobar_Huecos_Inferior_CPU();
u8 Comprobar_Huecos_CPU();
void IA_CPU();
void Mover_IA_CPU();
void Cancelar_Animacion_Eliminar_Lineas_CPU();
u8 Borrar_Lineas_Completas_CPU();
void Borrar_Linea_CPU(u8 altura);
u8 Comprobar_Lineas_Completas_CPU();
u8 Comprobar_Linea_CPU(u8 altura);
void Ajustar_Colisiones_Actuales_CPU();
u8 Estado_Cuadricula_CPU(int x, int y);
u8 Comprobar_Colisiones_Inferior_CPU();
u8 Comprobar_Colisiones_Derecha_CPU();
u8 Comprobar_Colisiones_Izquierda_CPU();
u8 Comprobar_Colisiones_Giro_CPU();
void Borrar_Pieza_Actual_CPU();
void Dibujar_Pieza_Actual_CPU();
void Iniciar_Juego_CPU();
void Nueva_Pieza_CPU();
void Reservar_Pieza_CPU();

#endif // MODOS_DE_JUEGO_CPU_IA_H__
