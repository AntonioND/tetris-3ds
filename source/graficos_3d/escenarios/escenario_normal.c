// SPDX-License-Identifier: GPL-3.0-only
//
// Copyright (c) 2008, 2024-2025 Antonio Niño Díaz

#include "graficos_3d/escenarios/escenarios.h"
#include "graficos_3d/funciones_texturas.h"

void Dibujar_Escenario_Normal(void)
{
    escenario_scrolly += 0.005;
    if (escenario_scrolly > 0.5)
        escenario_scrolly -= 0.5;

    glBegin(GL_QUADS);

    glBindTexture(GL_TEXTURE_2D, texture[7]);

        glColor3f(0.6, 0.6, 0.6);
        glTexCoord2f(1, 0 + escenario_scrolly);
        glVertex3v16(1023, -1024, -1024);
        glTexCoord2f(0, 0 + escenario_scrolly);
        glVertex3v16(1024, -1024, 19456);
        glTexCoord2f(0, 0.5 + escenario_scrolly);
        glVertex3v16(1024, 29696, 19456);
        glTexCoord2f(1, 0.5 + escenario_scrolly);
        glVertex3v16(1023, 29696, -1024);

    glBindTexture(GL_TEXTURE_2D, texture[9]);

        glColor3f(0.5, 0.5, 0.5);
        glTexCoord2f(1, 1);
        glVertex3v16(1024, -1024, 19456);
        glTexCoord2f(1, 0);
        glVertex3v16(-1023, -1024, 19456);
        glTexCoord2f(0, 0);
        glVertex3v16(-1023, 29696, 19456);
        glTexCoord2f(0, 1);
        glVertex3v16(1024, 29696, 19456);

        glColor3f(0.4, 0.4, 0.4);
        glTexCoord2f(1, 1);
        glVertex3v16(1023, -1024, -1024);
        glTexCoord2f(1, 0);
        glVertex3v16(-1024, -1024, -1024);
        glTexCoord2f(0, 0);
        glVertex3v16(-1023, -1024, 19456);
        glTexCoord2f(0, 1);
        glVertex3v16(1024, -1024, 19456);

        glColor3f(0.5, 0.5, 0.5);
        glTexCoord2f(1, 1);
        glVertex3v16(-1024, -1024, -1024);
        glTexCoord2f(1, 0);
        glVertex3v16(1023, -1024, -1024);
        glTexCoord2f(0, 0);
        glVertex3v16(1023, 29696, -1024);
        glTexCoord2f(0, 1);
        glVertex3v16(-1024, 29696, -1024);


        glColor3f(0.6, 0.6, 0.6);
        glTexCoord2f(1, 1);
        glVertex3v16(-1023, -3072, -3072);
        glTexCoord2f(1, 0);
        glVertex3v16(-1024, -3072, -1024);
        glTexCoord2f(0, 0);
        glVertex3v16(-1024, 29696, -1023);
        glTexCoord2f(0, 1);
        glVertex3v16(-1023, 29696, -3071);

        glTexCoord2f(1, 1);
        glVertex3v16(-1024, -1024, -1024);
        glTexCoord2f(1, 0);
        glVertex3v16(-1024, -3072, -1024);
        glTexCoord2f(0, 0);
        glVertex3v16(-1023, -3072, 19456);
        glTexCoord2f(0, 1);
        glVertex3v16(-1023, -1024, 19456);

        glTexCoord2f(1, 1);
        glVertex3v16(-1023, -3072, 19455);
        glTexCoord2f(1, 0);
        glVertex3v16(-1024, -3072, 21503);
        glTexCoord2f(0, 0);
        glVertex3v16(-1024, 29696, 21504);
        glTexCoord2f(0, 1);
        glVertex3v16(-1023, 29696, 19456);

    glEnd();

    glBindTexture(GL_TEXTURE_2D, 0);
}
