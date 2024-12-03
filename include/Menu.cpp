
#include "graficos_3d/graphics3d.h"
#include "graficos_3d/funciones_texturas.h"
#include "graficos_3d/objetos/3d_box.h"
#include "graficos_3d/objetos/figura_luz.h"
#include "graficos_3d/texto/numeros.h"
#include "graficos_3d/texto/letras.h"

#include "menu.h"

#include "MENU/opciones.cpp"
#include "menu/creditos.h"
#include "MODOS_DE_JUEGO/records.cpp"

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
