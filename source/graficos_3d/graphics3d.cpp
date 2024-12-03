#include <nds.h>

#include "graficos_3d/funciones_texturas.h"
#include "graficos_3d/graphics3d.h"
#include "graficos_3d/objetos/3d_box.h"
#include "graficos_3d/texto/letras.h"

#include "Textura_Tetris_1_pcx.h"
#include "Textura_Tetris_2_pcx.h"
#include "Textura_Tetris_3_pcx.h"
#include "Textura_Tetris_4_pcx.h"
#include "Textura_Tetris_5_pcx.h"

#include "Textura_Escenario_1_pcx.h"
#include "Textura_Escenario_2_pcx.h"
#include "Textura_Escenario_Borde_pcx.h"

#include "Textura_Disco_Foco_pcx.h"
#include "Textura_Disco_Metal_pcx.h"
#include "Textura_Disco_Suelo_pcx.h"
#include "Textura_Disco_Pared_pcx.h"
#include "Textura_Disco_Asiento_pcx.h"

void My_Init_3D()
{
    lcdMainOnTop();
    videoSetMode(MODE_0_3D);

    vramSetBankA(VRAM_A_TEXTURE);
    vramSetBankB(VRAM_B_TEXTURE);

    glInit();

    glResetMatrixStack();

    glEnable(GL_TEXTURE_2D | GL_BLEND | GL_ANTIALIAS);
    // setup the rear plane
    glClearColor(0,0,0,31); // BG must be opaque for AA to work
    glClearPolyID(63); // BG must have a unique polygon ID for AA to work
    glClearDepth(0x7FFF);
    // this should work the same as the normal gl call
    glViewport(0,0,255,191);
    // any floating point gl call is being converted to fixed prior to being implemented
    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    gluPerspective(70, 256.0 / 192.0, 0.1, 40);

    // need to set up some material properties since DS does not have them set by default
    glMaterialf(GL_AMBIENT, RGB15(8,8,8));
    glMaterialf(GL_DIFFUSE, RGB15(8,8,8));
    glMaterialf(GL_SPECULAR, BIT(15) | RGB15(8,8,8));
    glMaterialf(GL_EMISSION, RGB15(16,16,16));

    gluLookAt(-1.0, 0.0, 0.0,  // camera possition
               0.0, 0.0, 0.0,  // look at
               0.0, 1.0, 0.0); // up

    glMatrixMode(GL_MODELVIEW);


    glResetTextures();
    LoadGLTexture_PCX_8bit((u8 *)Textura_Tetris_1_pcx, 1, TEXTURE_SIZE_32, TEXTURE_SIZE_32);
    LoadGLTexture_PCX_8bit((u8 *)Textura_Tetris_2_pcx, 2, TEXTURE_SIZE_32, TEXTURE_SIZE_32);
    LoadGLTexture_PCX_8bit((u8 *)Textura_Tetris_3_pcx, 3, TEXTURE_SIZE_32, TEXTURE_SIZE_32);
    LoadGLTexture_PCX_8bit((u8 *)Textura_Tetris_4_pcx, 4, TEXTURE_SIZE_32, TEXTURE_SIZE_32);
    LoadGLTexture_PCX_8bit((u8 *)Textura_Tetris_5_pcx, 5, TEXTURE_SIZE_32, TEXTURE_SIZE_32);

    LoadGLTexture_PCX_8bit((u8 *)Textura_Escenario_1_pcx, 7, TEXTURE_SIZE_128, TEXTURE_SIZE_256);
    LoadGLTexture_PCX_8bit((u8 *)Textura_Escenario_2_pcx, 8, TEXTURE_SIZE_128, TEXTURE_SIZE_256);
    LoadGLTexture_PCX_8bit((u8 *)Textura_Escenario_Borde_pcx, 9, TEXTURE_SIZE_128, TEXTURE_SIZE_32);
}

void My_Init_3D_No_Textures()
{
    lcdMainOnTop();
    videoSetMode(MODE_0_3D);

    glInit();

    glResetMatrixStack();

    glEnable(GL_BLEND | GL_ANTIALIAS);
    // setup the rear plane
    glClearColor(0,0,0,31); // BG must be opaque for AA to work
    glClearPolyID(63); // BG must have a unique polygon ID for AA to work
    glClearDepth(0x7FFF);
    // this should work the same as the normal gl call
    glViewport(0,0,255,191);
    // any floating point gl call is being converted to fixed prior to being implemented
    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    gluPerspective(70, 256.0 / 192.0, 0.1, 40);

    // need to set up some material properties since DS does not have them set by default
    glMaterialf(GL_AMBIENT, RGB15(8,8,8));
    glMaterialf(GL_DIFFUSE, RGB15(8,8,8));
    glMaterialf(GL_SPECULAR, BIT(15) | RGB15(8,8,8));
    glMaterialf(GL_EMISSION, RGB15(16,16,16));

    gluLookAt(-1.0, 0.0, 0.0,  // camera possition
               0.0, 0.0, 0.0,  // look at
               0.0, 1.0, 0.0); // up

    //glMatrixMode(GL_MODELVIEW);
}


void Load_Disco_Textures()
{
    glResetTextures();
    LoadGLTexture_PCX_8bit((u8 *)Textura_Disco_Suelo_pcx,  1, TEXTURE_SIZE_128, TEXTURE_SIZE_128); // Suelo
    LoadGLTexture_PCX_8bit((u8 *)Textura_Disco_Pared_pcx,  2, TEXTURE_SIZE_128, TEXTURE_SIZE_128); // Pared
    LoadGLTexture_PCX_8bit((u8 *)Textura_Disco_Asiento_pcx,3, TEXTURE_SIZE_128, TEXTURE_SIZE_32); // Asiento
    LoadGLTexture_PCX_8bit((u8 *)Textura_Disco_Metal_pcx,  4, TEXTURE_SIZE_32, TEXTURE_SIZE_32); // Metal
    LoadGLTexture_PCX_8bit((u8 *)Textura_Disco_Foco_pcx,   5, TEXTURE_SIZE_32, TEXTURE_SIZE_32); // Foco
}

//Para simplificar las cosas...
void Dibujar_Caja(float R, float G, float B)
{
    Draw3D_Textured_Box(0.475, 0.475, 0.475, R, G, B);
}

void Escribir_3D_Char_Rotado(float tamano, u8 x_coord, u8 y_coord, int letra, float red, float green, float blue)
{
    glPushMatrix();

    glRotateZ(90);
    glRotateY(180);

    if(tamano == TEXT_SMALL)
    {
        glScalef(0.1, 0.1, 0.1); // 11 * 15

        glTranslatef(-6.75, 0, -8.5);

        glTranslatef(1.2 * x_coord, 0, 1.2 * y_coord);

        if ((x_coord > 10) || (y_coord > 14))
            letra = 255;
    }
    else if (tamano == TEXT_MEDIUM) // 7 * 9
    {
        glScalef(0.15, 0.15, 0.15);

        glTranslatef(-4.5, 0, -5.5);

        glTranslatef(1.25 * x_coord, 0, 1.3 * y_coord);

        if ((x_coord > 6) || (y_coord > 8))
            letra = 255;
    }
    else if (tamano == TEXT_BIG) // 4 * 5
    {
        glScalef(0.3, 0.3, 0.3);

        glTranslatef(-2.25, 0, -2.45);

        glTranslatef(1.1 * x_coord, 0, 1.2 * y_coord);

        if((x_coord > 3) || (y_coord > 4)) letra = 255;
    }

    Dibujar_Letra(letra, red, green, blue);

    glPopMatrix(1);
}

void Escribir_3D_Char(float tamano, u8 x_coord, u8 y_coord, int letra, float red, float green, float blue)
{
    glPushMatrix();

    glRotateZ(90);
    glRotateY(-90);

    if (tamano == TEXT_SMALL)
    {
        glScalef(0.1, 0.1, 0.1); // 15 * 11

        glTranslatef(-9, 0, -6.2);

        glTranslatef(1.2 * x_coord, 0, 1.2 * y_coord);

        if ((x_coord > 14) || (y_coord > 10))
            letra = 255;
    }
    else if (tamano == TEXT_MEDIUM) // 10 * 7
    {
        glScalef(0.15, 0.15, 0.15);

        glTranslatef(-6, 0, -4);

        glTranslatef(1.20 * x_coord, 0, 1.3 * y_coord);

        if((x_coord > 9) || (y_coord > 6))
            letra = 255;
    }
    else if (tamano == TEXT_BIG) // 5 * 4
    {
        glScalef (0.3, 0.3, 0.3);

        glTranslatef(-3, 0, -1.7);

        glTranslatef(1.2 * x_coord, 0, 1.1 * y_coord);

        if((x_coord > 4) || (y_coord > 3))
            letra = 255;
    }

    Dibujar_Letra(letra, red, green, blue);

    glPopMatrix(1);
}

void Escribir_3D_Char_Moved(float tamano, float x_coord, float y_coord, u8 xdesp, u8 ydesp, int letra, float red, float green, float blue)
{
    glPushMatrix();

    glRotateZ(90);
    glRotateY(-90);

    if (xdesp)
        x_coord += 0.5;
    if (ydesp)
        y_coord += 0.5;

    if (tamano == TEXT_SMALL)
    {
        glScalef(0.1, 0.1, 0.1); // 15 * 11

        glTranslatef(-9, 0, -6.2);

        glTranslatef(1.2 * x_coord, 0, 1.2 * y_coord);

        if ((x_coord > 14) || (y_coord > 10))
            letra = 255;
    }
    else if (tamano == TEXT_MEDIUM)
    {
        glScalef(0.15, 0.15, 0.15);

        glTranslatef(-6, 0, -4);

        glTranslatef(1.20 * x_coord, 0, 1.3 * y_coord);

        if ((x_coord > 9) || (y_coord > 6))
            letra = 255;
    }
    else if (tamano == TEXT_BIG)
    {
        glScalef(0.3, 0.3, 0.3);

        glTranslatef(-3, 0, -1.7);

        glTranslatef(1.2 * x_coord, 0, 1.1 * y_coord);

        if ((x_coord > 4) || (y_coord > 3))
            letra = 255;
    }

    Dibujar_Letra(letra, red, green, blue);

    glPopMatrix(1);
}

/*
void Escribir_3D_Char_Rotado_Array(float tamano, u8 x_coord, u8 y_coord, char* letra, u16 letrasmax, float red, float green, float blue)
{
    u16 letracount;
    int letraactual;

    for(letracount = 0; letracount < letrasmax; letracount++)
    {
        letraactual = Convertir_Letra(&letra + letracount);

        Escribir_3D_Char_Rotado(tamano, x_coord,y_coord, letraactual, red,green,blue);
    }
}
*/
