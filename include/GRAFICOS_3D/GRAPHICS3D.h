//Incluir los archivos de gráficos

#ifndef __MY_3D__
#define __MY_3D__

#include "graficos_3d/funciones_texturas.h"
#include "graficos_3d/objetos/3d_box.h"
#include "graficos_3d/objetos/figura_luz.h"
#include "graficos_3d/texto/numeros.h"
#include "graficos_3d/texto/letras.h"
#include <header.h>

void My_Init_3D();
void My_Init_3D_No_Textures();
void Load_Disco_Textures();

//Para simplificar las cosas...
void Dibujar_Caja(float R, float G, float B);

//Dibujar cuadros
void Dibujar_Tetris()
{
/*15x10 Cuadritos
	
0,0,7------0,4.5,7
  |			  |
  |			  |
  |		      |
0,0,0------0,4.5,7
*/

glBindTexture(GL_TEXTURE_2D,texture[texture_selected]);
   
for(auxiliar = 0;auxiliar < ANCHO_PIEZAS; auxiliar++)
    {
    for(auxiliar2 = 0;auxiliar2 < ALTO_PIEZAS; auxiliar2++)
        {
        if(Escenario_Tetris[auxiliar][auxiliar2].dibujar != 0)
            {
            if(Escenario_Tetris[auxiliar][auxiliar2].dibujar == 1)
                Iniciar_Transparencia(10); 
            Dibujar_Caja(Escenario_Tetris[auxiliar][auxiliar2].red,Escenario_Tetris[auxiliar][auxiliar2].green,Escenario_Tetris[auxiliar][auxiliar2].blue);
            if(Escenario_Tetris[auxiliar][auxiliar2].dibujar == 1)
                Finalizar_Transparencia(); 
            }
        glTranslatef(0.0,0.5,0.0);
        }
    glTranslatef(0.0,-7.5,0.0);
    glTranslatef(0.0,0.0,0.5);
    }
glTranslatef(0.0,0.0,-5);

glBindTexture(GL_TEXTURE_2D,texture[0]);
}

//Dibujar cuadros
void Dibujar_Tetris_CPU()
{
/*15x10 Cuadritos
	
0,0,7------0,4.5,7
  |			  |
  |			  |
  |		      |
0,0,0------0,4.5,7
*/

glBindTexture(GL_TEXTURE_2D,texture[texture_selected]);
   
for(auxiliar = 0;auxiliar < ANCHO_PIEZAS; auxiliar++)
    {
    for(auxiliar2 = 0;auxiliar2 < ALTO_PIEZAS; auxiliar2++)
        {
        if(Escenario_Tetris_CPU[auxiliar][auxiliar2].dibujar != 0)
            {
            if(Escenario_Tetris_CPU[auxiliar][auxiliar2].dibujar == 1)
                Iniciar_Transparencia(10); 
            Dibujar_Caja(Escenario_Tetris_CPU[auxiliar][auxiliar2].red,Escenario_Tetris_CPU[auxiliar][auxiliar2].green,Escenario_Tetris_CPU[auxiliar][auxiliar2].blue);
            if(Escenario_Tetris_CPU[auxiliar][auxiliar2].dibujar == 1)
                Finalizar_Transparencia(); 
            }
        glTranslatef(0.0,0.5,0.0);
        }
    glTranslatef(0.0,-7.5,0.0);
    glTranslatef(0.0,0.0,0.5);
    }
glTranslatef(0.0,0.0,-5);

glBindTexture(GL_TEXTURE_2D,texture[0]);
}




void Dibujar_Explosiones()
{
Iniciar_Transparencia(23);

glBindTexture(GL_TEXTURE_2D,texture[2]);

glTranslatef(0.0,0.0,2.25);
for(auxiliar = 0;auxiliar < ALTO_PIEZAS; auxiliar++)
	{
	if (Fila_Eliminada[auxiliar] > 0)
		{
		//Draw3D_Box(0.5, 0.5, (float)Fila_Eliminada[auxiliar] / 6,  1,1,1);
		Draw3D_Textured_Box(0.5, 0.5, (float)Fila_Eliminada[auxiliar] / 6,    1,1,1);
		//Dibujar_Explosion(Fila_Eliminada[auxiliar]);
		}
	
	glTranslatef(0.0,0.5,0.0);
	}
glTranslatef(0.0,-7.5,0.0);
glTranslatef(0.0,0.0,-2.25);

glBindTexture(GL_TEXTURE_2D,texture[0]);

Finalizar_Transparencia();   
}

void Dibujar_Explosiones_CPU()
{
Iniciar_Transparencia(23);

glBindTexture(GL_TEXTURE_2D,texture[2]);

glTranslatef(0.0,0.0,2.25);
for(auxiliar = 0;auxiliar < ALTO_PIEZAS; auxiliar++)
	{
	if (Fila_Eliminada_CPU[auxiliar] > 0)
		{
		//Draw3D_Box(0.5, 0.5, (float)Fila_Eliminada[auxiliar] / 6,  1,1,1);
		Draw3D_Textured_Box(0.5, 0.5, (float)Fila_Eliminada_CPU[auxiliar] / 6,    1,1,1);
		//Dibujar_Explosion(Fila_Eliminada[auxiliar]);
		}
	
	glTranslatef(0.0,0.5,0.0);
	}
glTranslatef(0.0,-7.5,0.0);
glTranslatef(0.0,0.0,-2.25);

glBindTexture(GL_TEXTURE_2D,texture[0]);

Finalizar_Transparencia();   
}

//No sirve para nada... pero es chulo XD
void Piezas_Aleatorias(int altura)
{
altura = Limitar_int(0,15,altura);
for(auxiliar = 0;auxiliar < ANCHO_PIEZAS; auxiliar++)
    {
    for(auxiliar2 = 0;auxiliar2 < altura; auxiliar2++)
        {
        Escenario_Tetris[auxiliar][auxiliar2].dibujar = PA_RandMinMax(0,2);
		
		Escenario_Tetris[auxiliar][auxiliar2].red = PA_RandMinMax(0,1);
		Escenario_Tetris[auxiliar][auxiliar2].green = PA_RandMinMax(0,1);
		Escenario_Tetris[auxiliar][auxiliar2].blue = PA_RandMinMax(0,1);
		
		while((Escenario_Tetris[auxiliar][auxiliar2].red == 0) && (Escenario_Tetris[auxiliar][auxiliar2].green == 0) && (Escenario_Tetris[auxiliar][auxiliar2].blue == 0))
			{
			Escenario_Tetris[auxiliar][auxiliar2].red = PA_RandMinMax(0,1);
			Escenario_Tetris[auxiliar][auxiliar2].green = PA_RandMinMax(0,1);
			Escenario_Tetris[auxiliar][auxiliar2].blue = PA_RandMinMax(0,1);
			}
		}
	}
}

void Piezas_Aleatorias_CPU(int altura)
{
altura = Limitar_int(0,15,altura);
for(auxiliar = 0;auxiliar < ANCHO_PIEZAS; auxiliar++)
    {
    for(auxiliar2 = 0;auxiliar2 < altura; auxiliar2++)
        {
        Escenario_Tetris_CPU[auxiliar][auxiliar2].dibujar = PA_RandMinMax(0,2);
		
		Escenario_Tetris_CPU[auxiliar][auxiliar2].red = PA_RandMinMax(0,1);
		Escenario_Tetris_CPU[auxiliar][auxiliar2].green = PA_RandMinMax(0,1);
		Escenario_Tetris_CPU[auxiliar][auxiliar2].blue = PA_RandMinMax(0,1);
		
		while((Escenario_Tetris_CPU[auxiliar][auxiliar2].red == 0) && (Escenario_Tetris_CPU[auxiliar][auxiliar2].green == 0) && (Escenario_Tetris_CPU[auxiliar][auxiliar2].blue == 0))
			{
			Escenario_Tetris_CPU[auxiliar][auxiliar2].red = PA_RandMinMax(0,1);
			Escenario_Tetris_CPU[auxiliar][auxiliar2].green = PA_RandMinMax(0,1);
			Escenario_Tetris_CPU[auxiliar][auxiliar2].blue = PA_RandMinMax(0,1);
			}
		}
	}
}



void Init_3D_Text_Colors(float red, float redincrement, float green, float greenincrement, float blue, float blueincrement)
{
Text_Color.red = red;
Text_Color.redincrement = redincrement;
Text_Color.green = green;
Text_Color.greenincrement = greenincrement;
Text_Color.blue = blue;
Text_Color.blueincrement = blueincrement;
}

void Update_3D_Text_Colors()
{
Text_Color.red += Text_Color.redincrement;
if((Text_Color.red < 0.3) || (Text_Color.red > 0.9)) Text_Color.redincrement *= -1;
Text_Color.green += Text_Color.greenincrement;
if((Text_Color.green < 0.3) || (Text_Color.green > 0.9)) Text_Color.greenincrement *= -1;
Text_Color.blue += Text_Color.blueincrement;
if((Text_Color.blue < 0.3) || (Text_Color.blue > 0.9)) Text_Color.blueincrement *= -1;
}

void Escribir_3D_Char_Rotado(float tamano, u8 x_coord, u8 y_coord, int letra, float red, float green, float blue);

void Escribir_3D_Char(float tamano, u8 x_coord, u8 y_coord, int letra, float red, float green, float blue);

void Escribir_3D_Char_Moved(float tamano, float x_coord, float y_coord, u8 xdesp, u8 ydesp, int letra, float red, float green, float blue);

#endif
