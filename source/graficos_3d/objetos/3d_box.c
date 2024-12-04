#include <nds.h>

void Draw3D_Box(float SIZE_X, float SIZE_Y, float SIZE_Z, float RED, float GREEN, float BLUE)
{
    SIZE_X /= 2;
    SIZE_Y /= 2;
    SIZE_Z /= 2;

    glBegin(GL_QUADS);

    glColor3f(RED,GREEN,BLUE);

        // DERECHA
        glVertex3f(-SIZE_X,  SIZE_Y, -SIZE_Z);
        glVertex3f( SIZE_X,  SIZE_Y, -SIZE_Z);
        glVertex3f( SIZE_X, -SIZE_Y, -SIZE_Z);
        glVertex3f(-SIZE_X, -SIZE_Y, -SIZE_Z);

        // IZQUIERDA
        glVertex3f(SIZE_X,   SIZE_Y,  SIZE_Z);
        glVertex3f(-SIZE_X,  SIZE_Y,  SIZE_Z);
        glVertex3f(-SIZE_X, -SIZE_Y,  SIZE_Z);
        glVertex3f(SIZE_X,  -SIZE_Y,  SIZE_Z);

    glColor3f(RED - 0.2, GREEN - 0.2, BLUE - 0.2);

        // ATRAS
        glVertex3f(-SIZE_X,  SIZE_Y,  SIZE_Z);
        glVertex3f(-SIZE_X,  SIZE_Y, -SIZE_Z);
        glVertex3f(-SIZE_X, -SIZE_Y, -SIZE_Z);
        glVertex3f(-SIZE_X, -SIZE_Y,  SIZE_Z);

        // FRENTE
        glVertex3f(SIZE_X,   SIZE_Y, -SIZE_Z);
        glVertex3f(SIZE_X,   SIZE_Y,  SIZE_Z);
        glVertex3f(SIZE_X,  -SIZE_Y,  SIZE_Z);
        glVertex3f(SIZE_X,  -SIZE_Y, -SIZE_Z);

    glColor3f(RED - 0.1 , GREEN - 0.1, BLUE - 0.1);

        // SUPERIOR
        glVertex3f(-SIZE_X,  SIZE_Y, -SIZE_Z);
        glVertex3f(-SIZE_X,  SIZE_Y,  SIZE_Z);
        glVertex3f(SIZE_X,   SIZE_Y,  SIZE_Z);
        glVertex3f(SIZE_X,   SIZE_Y, -SIZE_Z);

        // INFERIOR
        glVertex3f(-SIZE_X, -SIZE_Y,  SIZE_Z);
        glVertex3f(-SIZE_X, -SIZE_Y, -SIZE_Z);
        glVertex3f(SIZE_X,  -SIZE_Y, -SIZE_Z);
        glVertex3f(SIZE_X,  -SIZE_Y,  SIZE_Z);

    glEnd();
}

void Draw3D_Textured_Box(float SIZE_X, float SIZE_Y, float SIZE_Z, float RED, float GREEN, float BLUE)
{
    v16 SIZE_X_ = (v16)(SIZE_X * 2048);
    v16 SIZE_Y_ = (v16)(SIZE_Y * 2048);
    v16 SIZE_Z_ = (v16)(SIZE_Z * 2048);

    glBegin(GL_QUADS);

    glColor3f(RED - 0.2, GREEN - 0.2, BLUE - 0.2);

        // DERECHA
        glTexCoord2f(1,1);
        glVertex3v16(-SIZE_X_,  SIZE_Y_, -SIZE_Z_);
        glTexCoord2f(1,0);
        glVertex3v16( SIZE_X_,  SIZE_Y_, -SIZE_Z_);
        glTexCoord2f(0,0);
        glVertex3v16( SIZE_X_, -SIZE_Y_, -SIZE_Z_);
        glTexCoord2f(0,1);
        glVertex3v16(-SIZE_X_, -SIZE_Y_, -SIZE_Z_);

        // IZQUIERDA
        glTexCoord2f(1,1);
        glVertex3v16(SIZE_X_,   SIZE_Y_,  SIZE_Z_);
        glTexCoord2f(1,0);
        glVertex3v16(-SIZE_X_,  SIZE_Y_,  SIZE_Z_);
        glTexCoord2f(0,0);
        glVertex3v16(-SIZE_X_, -SIZE_Y_,  SIZE_Z_);
        glTexCoord2f(0,1);
        glVertex3v16(SIZE_X_,  -SIZE_Y_,  SIZE_Z_);

    glColor3f(RED,GREEN,BLUE);

        // ATRAS
        glTexCoord2f(1,1);
        glVertex3v16(-SIZE_X_,  SIZE_Y_,  SIZE_Z_);
        glTexCoord2f(1,0);
        glVertex3v16(-SIZE_X_,  SIZE_Y_, -SIZE_Z_);
        glTexCoord2f(0,0);
        glVertex3v16(-SIZE_X_, -SIZE_Y_, -SIZE_Z_);
        glTexCoord2f(0,1);
        glVertex3v16(-SIZE_X_, -SIZE_Y_,  SIZE_Z_);

    /*
        // FRENTE
        glTexCoord2f(1,1);
        glVertex3v16(SIZE_X_,   SIZE_Y_, -SIZE_Z);
        glTexCoord2f(1,0);
        glVertex3v16(SIZE_X_,   SIZE_Y_,  SIZE_Z);
        glTexCoord2f(0,0);
        glVertex3v16(SIZE_X_,  -SIZE_Y_,  SIZE_Z);
        glTexCoord2f(0,1);
        glVertex3f(SIZE_X,  -SIZE_Y, -SIZE_Z);

    */
    glColor3f(RED - 0.1 ,GREEN - 0.1,BLUE - 0.1);

        // SUPERIOR
        glTexCoord2f(1,1);
        glVertex3v16(-SIZE_X_,  SIZE_Y_, -SIZE_Z_);
        glTexCoord2f(1,0);
        glVertex3v16(-SIZE_X_,  SIZE_Y_,  SIZE_Z_);
        glTexCoord2f(0,0);
        glVertex3v16(SIZE_X_,   SIZE_Y_,  SIZE_Z_);
        glTexCoord2f(0,1);
        glVertex3v16(SIZE_X_,   SIZE_Y_, -SIZE_Z_);

        // INFERIOR
        glTexCoord2f(1,1);
        glVertex3v16(-SIZE_X_, -SIZE_Y_,  SIZE_Z_);
        glTexCoord2f(1,0);
        glVertex3v16(-SIZE_X_, -SIZE_Y_, -SIZE_Z_);
        glTexCoord2f(0,0);
        glVertex3v16(SIZE_X_,  -SIZE_Y_, -SIZE_Z_);
        glTexCoord2f(0,1);
        glVertex3v16(SIZE_X_,  -SIZE_Y_,  SIZE_Z_);

    glEnd();
}

