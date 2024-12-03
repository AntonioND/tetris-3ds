#include <nds.h>

int texture[10];  //Diez slots, el primero debe quedarse vacio.

int LoadGLTexture_PCX_8bit(u8 * adress, u8 slot, int sizex, int sizey)
{
    sImage pcx;

    // load our texture
    loadPCX(adress, &pcx);
    image8to16(&pcx);

    // DS supports no filtering of anykind so no need for more than one texture
    glGenTextures(1, &texture[slot]);
    glBindTexture(0, texture[slot]);
    glTexImage2D(0, 0, GL_RGB, sizex , sizey, 0, TEXGEN_TEXCOORD, pcx.image.data8);

    imageDestroy(&pcx);

    return TRUE;
}

void Iniciar_Transparencia(int ALPHA)
{
    glPolyFmt(POLY_ALPHA(ALPHA) | POLY_CULL_BACK);
}

void Finalizar_Transparencia()
{
    glPolyFmt(POLY_ALPHA(31) | POLY_CULL_BACK);
}
