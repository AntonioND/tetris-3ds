#ifndef __RECORDS__
#define __RECORDS__

u8 Add_Record(char* name, u32 score, u16 lines)
{
for(auxiliar = 0; auxiliar < 10; auxiliar ++)
	{
	if(Record[auxiliar].Puntuacion < score) //Puntuacion superada!
		{
		for(auxiliar2 = 9; auxiliar2 > auxiliar; auxiliar2 --)
			{
			Record[auxiliar2].Puntuacion = Record[auxiliar2 - 1].Puntuacion;
			Record[auxiliar2].Lineas = Record[auxiliar2 - 1].Lineas;
			sprintf(Record[auxiliar2].Nombre, "%s", (char*)Record[auxiliar2 - 1].Nombre);
			}
		Record[auxiliar].Puntuacion = score;
		Record[auxiliar].Lineas = lines;
		sprintf(Record[auxiliar].Nombre, "%s", name);
		
		return 1;
		}
	}
return 0;
}

void Records()
{
PA_ResetBgSys();
PA_Init2D();

PA_WaitForVBL(); 
PA_WaitForVBL(); 

PA_SetBrightness(0, 0);
PA_SetBrightness(1, 0);

My_Init_3D_No_Textures();
Iniciar_3D_Menu();

PA_Init8bitBg(1,3);
PA_EasyBgLoad(1,2,inferior_records); 
PA_SetBgPalCol(1, 1,  PA_RGB(31, 31, 31));
PA_SetBgPalCol(1, 2,  PA_RGB(31, 31, 22));
PA_SetBgPalCol(1, 3,  PA_RGB(31, 31, 15));
PA_SetBgPalCol(1, 4,  PA_RGB(31, 31, 7));
PA_SetBgPalCol(1, 5,  PA_RGB(31, 31, 0));
PA_SetBgPalCol(1, 6,  PA_RGB(31, 22, 0));
PA_SetBgPalCol(1, 7,  PA_RGB(31, 15, 0));
PA_SetBgPalCol(1, 8,  PA_RGB(31, 7,  0));
PA_SetBgPalCol(1, 9,  PA_RGB(31, 0,  0));
PA_SetBgPalCol(1, 10, PA_RGB(22, 0, 0));
PA_SetBgColor(1, PA_RGB(0, 0, 0));

//Fade up
for (auxiliar = -31; auxiliar < 0; auxiliar++) 
	{
	PA_SetBrightness(0, auxiliar);
	PA_SetBrightness(1, auxiliar);
	PA_WaitForVBL(); 
	}	

PA_SetBrightness(0, 0);
PA_SetBrightness(1, 0);

u8 newrecord = Add_Record((char*)PA_UserInfo.Name, (u32)puntuacion_total, (u16)linecount);
Guardar_Datos();

//Escribir records
for(auxiliar = 0; auxiliar < 10; auxiliar++)
	{
	char str[30];

	snprintf(str, sizeof(str), "%s", (char *)Record[auxiliar].Nombre);
	PA_CenterSmartText(1, 7,6 + (19 * auxiliar),119,15 + (19 * auxiliar), str, auxiliar + 1 /*Color*/ , 2, 0); 

	snprintf(str, sizeof(str), "%d", (int)Record[auxiliar].Puntuacion);
	PA_CenterSmartText(1, 127,6 + (19 * auxiliar),199,15 + (19 * auxiliar), str, auxiliar + 1 /*Color*/ , 2, 0);

	snprintf(str, sizeof(str), "%d", (int)Record[auxiliar].Lineas);
	PA_CenterSmartText(1, 207,6 + (19 * auxiliar),248,15 + (19 * auxiliar), str, auxiliar + 1 /*Color*/ , 2, 0);
	}

//Bucle de espera
while(!(Stylus.Newpress || Pad.Newpress.Anykey))
	{
	if(newrecord)
		{
		Escribir_3D_Char(TEXT_MEDIUM, 1,2, CHAR_N,  1,1,1);
		Escribir_3D_Char(TEXT_MEDIUM, 2,2, CHAR_E,  1,1,1);
		Escribir_3D_Char(TEXT_MEDIUM, 3,2, CHAR_W,  1,1,1);
		
		Escribir_3D_Char(TEXT_MEDIUM, 2,4, CHAR_R,  1,1,1);
		Escribir_3D_Char(TEXT_MEDIUM, 3,4, CHAR_E,  1,1,1);
		Escribir_3D_Char(TEXT_MEDIUM, 4,4, CHAR_C,  1,1,1);
		Escribir_3D_Char(TEXT_MEDIUM, 5,4, CHAR_O,  1,1,1);
		Escribir_3D_Char(TEXT_MEDIUM, 6,4, CHAR_R,  1,1,1);
		Escribir_3D_Char(TEXT_MEDIUM, 7,4, CHAR_D,  1,1,1);
		
		Escribir_3D_Char(TEXT_MEDIUM, 8,4, CHAR_CERRAREXCLAMACION,  1,1,1);
		}
		
	Actualizar_3D_Menu();
	Graficos_3D_Menu();
	
	PA_WaitForVBL();
	}


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


#endif
