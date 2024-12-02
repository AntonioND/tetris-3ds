
#include <header.h>
#include "../music.cpp"

void Jukebox();
void Graficos_3D_Juekebox();

int numsongs;
bool movecam = true;
bool logwrote;

void Jukebox()
{
PA_SetBrightness(0, -31);
PA_SetBrightness(1, -31);

PA_ResetBgSys(); //Esto tambien desactiva la fuente personalizada
Stop_Song();
Wait_To_Stop_Song();

PA_Init8bitBg(1,3);
PA_EasyBgLoad(1,2,inferior_disco); 
PA_SetBgPalCol(1, 1, PA_RGB(0, 0, 0));	
PA_SetBgColor(1, PA_RGB(24, 24, 24));

hora = " 00:00 "; 	
sprintf(hora," %02d ", Current_Song);
PA_CenterSmartText(1, 193,19,244,50 ,hora, 1 /*Color*/ , 4, 0);

PA_LoadSpritePal(1, 0,(void*)cursor_sonido_Pal);
PA_CreateSprite(1, 0,(void*)cursor_sonido_Sprite, OBJ_SIZE_16X32,1, 0, (int)(14 + ((float)MASTER_SOUND / 128 * 227) - 8),162);

logwrote = false;
Clear_Song_Error();

My_Init_3D();
Load_Disco_Textures();
Iniciar_Focos();

//Fade up
for (auxiliar = -31; auxiliar < 0; auxiliar++) 
	{
	PA_SetBrightness(0, auxiliar);
	PA_SetBrightness(1, auxiliar);
	PA_WaitForVBL(); 
	}	

PA_SetBrightness(0, 0);
PA_SetBrightness(1, 0);

numsongs = Get_Song_Number();

while(!Pad.Newpress.Start)
	{
	Graficos_3D_Juekebox();
	
	if((!FAT_ERROR) && (numsongs >= 0))
		{
		if((Pad.Newpress.A) || (Stylus.Newpress && PA_StylusInZone(9,55,69,76)))
			{
			if((AS_GetMP3Status() & MP3ST_PLAYING)  == 0)
				{
				//movecam = currmovecam;
				Set_Song_Number(Current_Song);
				}
			}
			
		else if((Pad.Newpress.B) || (Stylus.Newpress && PA_StylusInZone(165,55,232,76))) 
			Stop_Song();
		
		else if((Pad.Newpress.X) || (Stylus.Newpress && PA_StylusInZone(80,55,156,76)))
			{
			if(AS_GetMP3Status() & MP3ST_PAUSED) AS_MP3Unpause();
			else if(AS_GetMP3Status() & MP3ST_PLAYING) AS_MP3Pause();
			}

		Current_Song = Limitar_int(0,numsongs, Current_Song  + Pad.Newpress.Up - Pad.Newpress.Down);
		if(Pad.Newpress.Up || Pad.Newpress.Down)
			{
			hora = " 00:00 "; 
			sprintf(hora," %02d ", Current_Song);
			PA_CenterSmartText(1, 193,19,244,50 ,hora, 1 /*Color*/ , 4, 0);
			}		
		
		
		if((AS_GetMP3Status() & MP3ST_DECODE_ERROR) && !logwrote)
			{
			Write_Error_Log(Current_Song);
			logwrote = true;
			}
		if(logwrote && (AS_GetMP3Status() & MP3ST_PLAYING))
			{
			logwrote = false;
			}
		if(PA_StylusInZone(14,164, 241,178) && Stylus.Held)
			{
			MASTER_SOUND = Limitar_int(0,127,(int)(((float)Stylus.X - 14) / 227 * 128));
			AS_SetMasterVolume(MASTER_SOUND);
			PA_SetSpriteX(1,0,(int)(14 + ((float)MASTER_SOUND / 128 * 227) - 8));
			}
		}
	else if(FAT_ERROR)
		{
		Escribir_3D_Char(TEXT_SMALL, 0,0, CHAR_F,  1,1,1);
		Escribir_3D_Char(TEXT_SMALL, 1,0, CHAR_A,  1,1,1);
		Escribir_3D_Char(TEXT_SMALL, 2,0, CHAR_T,  1,1,1);
		
		Escribir_3D_Char(TEXT_SMALL, 4,0, CHAR_E,  1,1,1);
		Escribir_3D_Char(TEXT_SMALL, 5,0, CHAR_R,  1,1,1);
		Escribir_3D_Char(TEXT_SMALL, 6,0, CHAR_R,  1,1,1);
		Escribir_3D_Char(TEXT_SMALL, 7,0, CHAR_O,  1,1,1);
		Escribir_3D_Char(TEXT_SMALL, 8,0, CHAR_R,  1,1,1);
		}
	else if(numsongs == -1)
		{
		Escribir_3D_Char(TEXT_SMALL, 0,0, CHAR_N,  1,1,1);
		Escribir_3D_Char(TEXT_SMALL, 1,0, CHAR_O,  1,1,1);
		
		Escribir_3D_Char(TEXT_SMALL, 3,0, CHAR_S,  1,1,1);
		Escribir_3D_Char(TEXT_SMALL, 4,0, CHAR_O,  1,1,1);
		Escribir_3D_Char(TEXT_SMALL, 5,0, CHAR_N,  1,1,1);
		Escribir_3D_Char(TEXT_SMALL, 6,0, CHAR_G,  1,1,1);
		Escribir_3D_Char(TEXT_SMALL, 7,0, CHAR_S,  1,1,1);
		
		Escribir_3D_Char(TEXT_SMALL, 0,1, CHAR_A,  1,1,1);
		Escribir_3D_Char(TEXT_SMALL, 1,1, CHAR_V,  1,1,1);
		Escribir_3D_Char(TEXT_SMALL, 2,1, CHAR_A,  1,1,1);
		Escribir_3D_Char(TEXT_SMALL, 3,1, CHAR_I,  1,1,1);
		Escribir_3D_Char(TEXT_SMALL, 4,1, CHAR_L,  1,1,1);
		Escribir_3D_Char(TEXT_SMALL, 5,1, CHAR_A,  1,1,1);
		Escribir_3D_Char(TEXT_SMALL, 6,1, CHAR_B,  1,1,1);
		Escribir_3D_Char(TEXT_SMALL, 7,1, CHAR_L,  1,1,1);
		Escribir_3D_Char(TEXT_SMALL, 8,1, CHAR_E,  1,1,1);
		}
	
	
	PA_WaitForVBL();
	}
	
PA_WaitForVBL();
PA_WaitForVBL();

if(AS_GetMP3Status() & MP3ST_PAUSED) 
	{
	AS_MP3Unpause();
	for(auxiliar = 0; auxiliar < 30; auxiliar ++) PA_WaitForVBL();
	}
Stop_Song();
Wait_To_Stop_Song();
for(auxiliar = 0; auxiliar < 30; auxiliar ++) PA_WaitForVBL();

Init_Menu_Song_Loop();
}



void Graficos_3D_Juekebox()
{
glPushMatrix();
//not a real gl function and will likely change
glPolyFmt(POLY_ALPHA(31) | POLY_CULL_BACK);
//ds uses a table for shinyness..this generates a half-ass one
glMaterialShinyness();

glTranslatef(5,-2.5,0);//Ajustar camara
glRotateY(90);

Dibujar_Discoteca((AS_GetMP3Status() & MP3ST_PAUSED),movecam); //pausa, mover camara


glPopMatrix(1);
glFlush(0);
}

