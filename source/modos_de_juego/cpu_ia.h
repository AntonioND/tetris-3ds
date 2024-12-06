#ifndef MODOS_DE_JUEGO_CPU_IA_H__
#define MODOS_DE_JUEGO_CPU_IA_H__

u8 Comprobar_Superficie_CPU(void);
u8 Comprobar_Huecos_Inferior_CPU(void);
u8 Comprobar_Huecos_CPU(void);
void IA_CPU(void);
void Mover_IA_CPU(void);
void Cancelar_Animacion_Eliminar_Lineas_CPU(void);
u8 Borrar_Lineas_Completas_CPU(void);
void Borrar_Linea_CPU(u8 altura);
u8 Comprobar_Lineas_Completas_CPU(void);
u8 Comprobar_Linea_CPU(u8 altura);
void Ajustar_Colisiones_Actuales_CPU(void);
u8 Estado_Cuadricula_CPU(int x, int y);
u8 Comprobar_Colisiones_Inferior_CPU(void);
u8 Comprobar_Colisiones_Derecha_CPU(void);
u8 Comprobar_Colisiones_Izquierda_CPU(void);
u8 Comprobar_Colisiones_Giro_CPU(void);
void Borrar_Pieza_Actual_CPU(void);
void Dibujar_Pieza_Actual_CPU(void);
void Iniciar_Juego_CPU(void);
void Nueva_Pieza_CPU(void);
void Reservar_Pieza_CPU(void);

#endif // MODOS_DE_JUEGO_CPU_IA_H__
