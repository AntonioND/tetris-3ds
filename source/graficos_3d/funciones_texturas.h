#ifndef GRAFICOS_3D_FUNCIONES_TEXTURAS_H__
#define GRAFICOS_3D_FUNCIONES_TEXTURAS_H__

#include <nds.h>

// The first slot is currently unused
extern int texture[10];

int LoadGLTexture_PCX_8bit(u8 *adress, u8 slot, int sizex, int sizey);

void Iniciar_Transparencia(int ALPHA);

void Finalizar_Transparencia(void);

#endif // GRAFICOS_3D_FUNCIONES_TEXTURAS_H__
