
#include "graficos_3d/graphics3d.h"
#include "graficos_3d/funciones_texturas.h"
#include "graficos_3d/objetos/3d_box.h"
#include "graficos_3d/objetos/figura_luz.h"
#include "graficos_3d/texto/numeros.h"
#include "graficos_3d/texto/letras.h"

#include <header.h>

void Draw16bitRectangleEx(u8 screen, s16 x1, s16 y1, s16 x2, s16 y2, u16 color, u8 size)
{
PA_Draw16bitLineEx(screen, x1,y1, x2,y1, color, size);
PA_Draw16bitLineEx(screen, x1,y1, x1,y2, color, size);
PA_Draw16bitLineEx(screen, x1,y2, x2,y2, color, size);
PA_Draw16bitLineEx(screen, x2,y1, x2,y2, color, size);
}


typedef struct
	{
	float x, y, z;
	float vx, vy, vz;
	float gx, gy, gz;
	u8 tipopieza;
	} __ANIMACION_MENU__;

__ANIMACION_MENU__ Figura_Menu;


#define ACELERACION_PIEZA   0.005

typedef struct
	{
	float r, g, b;
	float ir, ig, ib;
	} __FONDO_MENU__;

__FONDO_MENU__ Fondo_Menu;

void Iniciar_3D_Menu()
{
Fondo_Menu.r = 22; Fondo_Menu.ir = -0.1;
Fondo_Menu.g = 11; Fondo_Menu.ig = -0.1;
Fondo_Menu.b = 2; Fondo_Menu.ib = 0.1;

Figura_Menu.x = 5; Figura_Menu.y = 0; Figura_Menu.z = 0;
Figura_Menu.vx = -0.1; Figura_Menu.vy = 0.02; Figura_Menu.vz = 0.05;
if(PA_RandMinMax(0,1) == 0) Figura_Menu.vy *= -1;
if(PA_RandMinMax(0,1) == 0) Figura_Menu.vz *= -1;


Figura_Menu.tipopieza = PA_RandMinMax(0,6);
Figura_Menu.gx = 0; Figura_Menu.gy = 0; Figura_Menu.gz = 0;
}

void Actualizar_3D_Menu()
{
Fondo_Menu.r += Fondo_Menu.ir;
Fondo_Menu.g += Fondo_Menu.ig;
Fondo_Menu.b += Fondo_Menu.ib;

if(Fondo_Menu.r > 23 || Fondo_Menu.r < 1) Fondo_Menu.ir *= -1;
if(Fondo_Menu.g > 23 || Fondo_Menu.g < 1) Fondo_Menu.ig *= -1;
if(Fondo_Menu.b > 23 || Fondo_Menu.b < 1) Fondo_Menu.ib *= -1;

//Si puede volver
Figura_Menu.vx -= ACELERACION_PIEZA;
Figura_Menu.x += Figura_Menu.vx;
Figura_Menu.y += Figura_Menu.vy;
Figura_Menu.z += Figura_Menu.vz;

if(Figura_Menu.x < 1) Figura_Menu.vx = 0.3;
if(Figura_Menu.y < -1 || Figura_Menu.y > 1) Figura_Menu.vy *= -1;
if(Figura_Menu.z < -3 || Figura_Menu.z > 3) Figura_Menu.vz *= -1;

Figura_Menu.gx += 2; if(Figura_Menu.gx > 360) Figura_Menu.gx -= 360;
Figura_Menu.gy += 0.5; if(Figura_Menu.gy > 360) Figura_Menu.gy -= 360;
Figura_Menu.gz = 0;
}

void Graficos_3D_Menu();


#include "MENU/opciones.cpp"
#include "MENU/creditos.cpp"
#include "MODOS_DE_JUEGO/records.cpp"

void Reload_Menu()
{
PA_ResetBgSys();
PA_Init2D();

PA_SetBrightness(0, -31);
PA_SetBrightness(1, -31);

PA_WaitForVBL(); 
PA_WaitForVBL(); 

My_Init_3D_No_Textures();
Iniciar_3D_Menu();

PA_Init16bitBg(1, 3); 
PA_Load16bitBitmap(1,menu_inferior_Bitmap); 

//Fade up
for (auxiliar = -31; auxiliar < 0; auxiliar++) 
	{
	PA_SetBrightness(0, auxiliar);
	PA_SetBrightness(1, auxiliar);
	PA_WaitForVBL(); 
	}	

PA_SetBrightness(0, 0);
PA_SetBrightness(1, 0);
}

void End_Menu()
{
PA_WaitForVBL(); PA_WaitForVBL(); PA_WaitForVBL(); PA_WaitForVBL(); PA_WaitForVBL(); 

//Fade down
for (auxiliar = 0; auxiliar < 32; auxiliar++) 
	{
	PA_SetBrightness(0, -auxiliar);
	PA_SetBrightness(1, -auxiliar);
	PA_WaitForVBL(); // To slow down the fades, we wait a frame...
	PA_WaitForVBL(); 
	}	

PA_SetBrightness(0, 0);
PA_SetBrightness(1, 0);
PA_ResetBgSys();
PA_Init2D();
PA_WaitForVBL(); 
PA_WaitForVBL(); 
}



void Menu()
{
Reload_Menu();

Init_Menu_Song_Loop();


while (MENU_ACTIVO)
	{

	if(Stylus.Newpress) //Tactil
		{
		if(PA_StylusInZone(2,2, 154,46)) //Normal
			{
			Draw16bitRectangleEx(1, 2,2,154,46, PA_RGB(31,31,31),4);
			
			MODO_DE_JUEGO = MODO_NORMAL;
			JUEGO_ACTIVO = true;
			MENU_ACTIVO = false;
			PAUSA = false;
			}
		else if(PA_StylusInZone(20,53, 169,96)) //Vs CPU
			{
			Draw16bitRectangleEx(1, 20,53,169,96, PA_RGB(31,31,31),4);
			
			MODO_DE_JUEGO = MODO_CONTRA_CPU;
			JUEGO_ACTIVO = true;
			MENU_ACTIVO = false;
			PAUSA = false;
			}
		else if(PA_StylusInZone(35,105, 186,148)) //Opciones
			{
			Draw16bitRectangleEx(1, 35,105,186,148, PA_RGB(31,31,31),4);
		
			End_Menu();		
			Opciones_Menu();	
			Reload_Menu();
			}
		else if(PA_StylusInZone(197,168, 255,191)) //Créditos
			{
			Draw16bitRectangleEx(1, 197,168,255,191, PA_RGB(31,31,31),4);
				
			End_Menu();		
			Creditos();
			Reload_Menu();
			}
		}
	
	
	//Apagar DS
	if(Pad.Held.Select && Pad.Held.Start && Pad.Held.L && Pad.Held.R) 
		{
		Stop_Song();
		PowerOFF_Countdown(3);
		}
	
	//if(Pad.Held.A && Pad.Held.B && Pad.Held.X && Pad.Held.Y) swiSoftReset();
	
	Actualizar_3D_Menu();
	Graficos_3D_Menu();
	
	Menu_Song();
	PA_WaitForVBL();
	}

Stop_Song();

End_Menu();

Stop_Song(); //Por si acaso
}




void Graficos_3D_Menu()
{
Escribir_3D_Char(TEXT_MEDIUM, 0, 0, CHAR_T,  0,1.0,0.5);
Escribir_3D_Char(TEXT_MEDIUM, 1, 0, CHAR_E,  0,0.9,0.6);
Escribir_3D_Char(TEXT_MEDIUM, 2, 0, CHAR_T,  0,0.8,0.7);
Escribir_3D_Char(TEXT_MEDIUM, 3, 0, CHAR_R,  0,0.7,0.8);
Escribir_3D_Char(TEXT_MEDIUM, 4, 0, CHAR_I,  0,0.6,0.9);
Escribir_3D_Char(TEXT_MEDIUM, 5, 0, CHAR_S,  0,0.5,1.0);

Escribir_3D_Char(TEXT_BIG, 2, 3, NUM_3,   0.6,0,0);
Escribir_3D_Char(TEXT_BIG, 3, 3, CHAR_D,  0.8,0,0);
Escribir_3D_Char(TEXT_BIG, 4, 3, CHAR_S,  1.0,0,0);

Escribir_3D_Char(TEXT_SMALL, 0, 10, CHAR_V,     1.0,1.0,1.0);
Escribir_3D_Char(TEXT_SMALL, 1, 10, NUM_1,      0.9,0.9,0.9);
Escribir_3D_Char(TEXT_SMALL, 2, 10, CHAR_PUNTO, 0.8,0.8,0.8);
Escribir_3D_Char(TEXT_SMALL, 3, 10, NUM_3,      0.7,0.7,0.7);

glPushMatrix();
//not a real gl function and will likely change
glPolyFmt(POLY_ALPHA(31) | POLY_CULL_NONE);
//ds uses a table for shinyness..this generates a half-ass one
glMaterialShinyness();

glClearColor((int)Fondo_Menu.r,(int)Fondo_Menu.g,(int)Fondo_Menu.b,31);

glBindTexture(0, 0);

glTranslatef(Figura_Menu.x,Figura_Menu.y,Figura_Menu.z);
glRotateX(Figura_Menu.gx);
glRotateY(Figura_Menu.gy);
glRotateZ(Figura_Menu.gz);

switch(Figura_Menu.tipopieza) //Color
	{
	case 0:
		glTranslatef(0,-1,0);
		Draw3D_Box(0.9,0.9,0.9, 1,1,1);
		glTranslatef(0,1,0);
		Draw3D_Box(0.9,0.9,0.9, 1,1,1);
		glTranslatef(0,1,0);
		Draw3D_Box(0.9,0.9,0.9, 1,1,1);
		glTranslatef(0,1,0);
		Draw3D_Box(0.9,0.9,0.9, 1,1,1);
		break;
	case 1:
		glTranslatef(0,-1,0);
		Draw3D_Box(0.9,0.9,0.9, 1,1,0);
		glTranslatef(0,1,0);
		Draw3D_Box(0.9,0.9,0.9, 1,1,0);
		glTranslatef(0,1,0);
		Draw3D_Box(0.9,0.9,0.9, 1,1,0);
		glTranslatef(1,0,0);
		Draw3D_Box(0.9,0.9,0.9, 1,1,0);
		break;
	case 2:
		glTranslatef(0,-1,0);
		Draw3D_Box(0.9,0.9,0.9, 1,0.5,0);
		glTranslatef(0,1,0);
		Draw3D_Box(0.9,0.9,0.9, 1,0.5,0);
		glTranslatef(0,1,0);
		Draw3D_Box(0.9,0.9,0.9, 1,0.5,0);
		glTranslatef(-1,0,0);
		Draw3D_Box(0.9,0.9,0.9, 1,0.5,0);
		break;
	case 3:
		glTranslatef(0,-1,0);
		Draw3D_Box(0.9,0.9,0.9, 1,0,0);
		glTranslatef(0,1,0);
		Draw3D_Box(0.9,0.9,0.9, 1,0,0);
		glTranslatef(-1,0,0);
		Draw3D_Box(0.9,0.9,0.9, 1,0,0);
		glTranslatef(0,1,0);
		Draw3D_Box(0.9,0.9,0.9, 1,0,0);
		break;
	case 4:
		glTranslatef(0,-1,0);
		Draw3D_Box(0.9,0.9,0.9, 0,1,0);
		glTranslatef(0,1,0);
		Draw3D_Box(0.9,0.9,0.9, 0,1,0);
		glTranslatef(1,0,0);
		Draw3D_Box(0.9,0.9,0.9, 0,1,0);
		glTranslatef(0,1,0);
		Draw3D_Box(0.9,0.9,0.9, 0,1,0);
		break;
	case 5:
		glTranslatef(0,-1,0);
		Draw3D_Box(0.9,0.9,0.9, 0,0,1);
		glTranslatef(0,1,0);
		Draw3D_Box(0.9,0.9,0.9, 0,0,1);
		glTranslatef(0,1,0);
		Draw3D_Box(0.9,0.9,0.9, 0,0,1);
		glTranslatef(1,-1,0);
		Draw3D_Box(0.9,0.9,0.9, 0,0,1);
		break;
	case 6:
		Draw3D_Box(0.9,0.9,0.9, 0.75,0,1);
		glTranslatef(0,1,0);
		Draw3D_Box(0.9,0.9,0.9, 0.75,0,1);
		glTranslatef(1,0,0);
		Draw3D_Box(0.9,0.9,0.9, 0.75,0,1);
		glTranslatef(0,-1,0);
		Draw3D_Box(0.9,0.9,0.9, 0.75,0,1);
		break;
	}

glPopMatrix(1);
glFlush(0);
}
