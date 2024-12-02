
void Reload_Creditos_Menu()
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
PA_Load16bitBitmap(1,inferior_credits_Bitmap); 

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

void End_Creditos_Menu()
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


void Creditos()
{
Reload_Creditos_Menu();
while(!(Pad.Newpress.Anykey || Stylus.Newpress))
	{
	Actualizar_3D_Menu();
	Graficos_3D_Menu();

	Menu_Song();
	PA_WaitForVBL();
	}

End_Creditos_Menu();
}
