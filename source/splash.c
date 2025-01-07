// SPDX-License-Identifier: GPL-3.0-only
//
// Copyright (c) 2008, 2024-2025 Antonio Niño Díaz

#include <PA9.h>

#include <math.h>

#include "splash_down_bmp_bin.h"
#include "splash_up_bmp_bin.h"

void Splash_Screen(void)
{
    int texture_[2];

    lcdMainOnTop();
    videoSetMode(MODE_0_3D);
    vramSetBankA(VRAM_A_TEXTURE);
    vramSetBankB(VRAM_B_TEXTURE);

    glInit();
    glEnable(GL_TEXTURE_2D | GL_ANTIALIAS | GL_BLEND);
    glClearColor(0, 0, 0, 31);
    glClearPolyID(63);
    glClearDepth(GL_MAX_DEPTH);
    glViewport(0,0, 255, 191);

    glGenTextures(2, &texture_[0]);
    glBindTexture(0, texture_[0]);
    glTexImage2D(0, 0, GL_RGB, TEXTURE_SIZE_256, TEXTURE_SIZE_128, 0, TEXGEN_TEXCOORD, splash_up_bmp_bin);
    glBindTexture(0, texture_[1]);
    glTexImage2D(0, 0, GL_RGB, TEXTURE_SIZE_256, TEXTURE_SIZE_64, 0, TEXGEN_TEXCOORD, splash_down_bmp_bin);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-6, 6, 6, -6, 0.1, 100);

    int time = 0;
    while (time != 1320)
    {
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glPolyFmt(POLY_ALPHA(31) | POLY_CULL_NONE);
        if (time < 720)
        {
            glTranslatef((float)cos((float)time) * ((720 - (float)time) / 720),
                         (float)sin((float)time) * ((720 - (float)time) / 720), 0);
            glRotateZ(time);
            time += 2;
            glScalef((float)time / 360, (float)time / 360, 1);
        }
        else if (time < 780)
        {
            glScalef(2, 2, 1);
            time++;
        }
        else if (time < 1140)
        {
            glScalef(2 - ((float)(time - 780) / 360), 2 - ((float)(time - 780) / 360), 1);
            time += 10;
        }
        else if (time < 1200)
        {
            time++;
        }
        else
        {
            time++;
            if (Pad.Newpress.Anykey || Stylus.Newpress)
                time = 1320;
        }

        glBegin(GL_QUADS);

            glColor3f(1, 1, 1);

            glBindTexture(GL_TEXTURE_2D, texture_[0]);

            glTexCoord2f(0, 1);
            glVertex3f(-6,  2, -6);
            glTexCoord2f(1, 1);
            glVertex3f( 6,  2, -6);
            glTexCoord2f(1, 0);
            glVertex3f( 6, -6, -6);
            glTexCoord2f(0, 0);
            glVertex3f(-6, -6, -6);

            glBindTexture(GL_TEXTURE_2D, texture_[1]);

            glTexCoord2f(0, 1);
            glVertex3f(-6,  6, -6);
            glTexCoord2f(1, 1);
            glVertex3f( 6,  6, -6);
            glTexCoord2f(1, 0);
            glVertex3f( 6,  2, -6);
            glTexCoord2f(0, 0);
            glVertex3f(-6,  2, -6);

        glEnd();

        glFlush(0);
        PA_WaitForVBL();
    }

    for (int a = 0; a < 32; a++)
    {
        PA_SetBrightness(0, -a);
        PA_SetBrightness(1, -a);
        PA_WaitForVBL();
        PA_WaitForVBL();
    }

    glViewport(0, 0, 0, 0);
    glFlush(0);
    glFlush(0);
    glResetMatrixStack();
    PA_Init2D();

    PA_WaitForVBL();
    PA_SetBrightness(0, 0);
    PA_SetBrightness(1, 0);
}
