
#include <nds.h>

void Dibujar_Luz(float RED, float GREEN, float BLUE)
{
    glBegin(GL_QUADS);

    //glScale3f(-1.0f, -1.0f, -1.0f)

    glColor3f(RED,GREEN,BLUE);

        glVertex3f(0,0,0.1);
        glVertex3f(0,0,-0.1);
        glVertex3f(0,8.0,-0.1);
        glVertex3f(0,8.0,0.1);

        glVertex3f(0,0,-0.1);
        glVertex3f(0,0,0.1);
        glVertex3f(0,8.0,0.1);
        glVertex3f(0,8.0,-0.1);

        glVertex3f(0.1,0,0);
        glVertex3f(-0.1,0,0);
        glVertex3f(-0.1,8,0);
        glVertex3f(0.1,8.0,0);

        glVertex3f(0.1,8.0,0);
        glVertex3f(-0.1,8,0);
        glVertex3f(-0.1,0,0);
        glVertex3f(0.1,0,0);

    glEnd();
}
