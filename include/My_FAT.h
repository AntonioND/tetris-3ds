#ifndef __MY_FAT__
#define __MY_FAT__

/*
Datos que se guardan

typedef struct
	{
	char[10] Nombre;
	u32 Puntuacion;
	u16 Lineas;
	} __RECORD_STRUCT__;

__RECORD_STRUCT__ Record[10];

texture_selected;
camera_selected;
MASTER_SOUND;
*/

bool FAT_ERROR = 0; //Activa/desactiva el acceso al FAT

//Rutina de checksum
u16 checksum;
u8 aux_checksum;

int Checksum(u32 datos)
{
checksum = 0;
for(aux_checksum = 0; aux_checksum < 32; aux_checksum++)
	{
	checksum += ( (datos & (1 << aux_checksum)) >> (aux_checksum) );
	}
return checksum;
}


//+ = Checksum parcial; * = Checksum completo
void Guardar_Datos()
{
if(FAT_ERROR) return;

acumulador = 0;
FILE* CONFIG_WRITE_FILE = fopen ("/Tetris_3DS/Tetris3DS_Config.dat", "wb"); //wb = create/truncate & write
if (CONFIG_WRITE_FILE == NULL)
	return;

fwrite(&texture_selected, 1, 1, CONFIG_WRITE_FILE);
fwrite(&camera_selected, 1, 1, CONFIG_WRITE_FILE);
fwrite(&MASTER_SOUND, 1, 1, CONFIG_WRITE_FILE);

for(auxiliar = 0; auxiliar < 10; auxiliar ++)
	{
	fwrite(&Record[auxiliar].Nombre, 1, 10, CONFIG_WRITE_FILE);
	fwrite(&Record[auxiliar].Puntuacion, 4, 1, CONFIG_WRITE_FILE);
	fwrite(&Record[auxiliar].Lineas, 2, 1, CONFIG_WRITE_FILE);
	}
fclose(CONFIG_WRITE_FILE);

//Añadir checsum al final
FILE* CONFIG_CHECKSUM_FILE = fopen ("/Tetris_3DS/Tetris3DS_Config.dat", "rb"); //wb = create/truncate & write
if (CONFIG_CHECKSUM_FILE == NULL)
	return;

auxiliar2 = 0;
for(auxiliar = 0; auxiliar < 163; auxiliar ++)
	{
	fread(&auxiliar2, 1, 1, CONFIG_CHECKSUM_FILE);
	acumulador += auxiliar2;
	}
fclose(CONFIG_CHECKSUM_FILE);

auxiliar = Checksum(acumulador);

FILE* CONFIG_WRITE_CHECKSUM_FILE = fopen ("/Tetris_3DS/Tetris3DS_Config.dat", "a"); //wb = create/truncate & write
if (CONFIG_WRITE_CHECKSUM_FILE == NULL)
	return;
fwrite(&auxiliar, 4, 1, CONFIG_WRITE_CHECKSUM_FILE);
fclose(CONFIG_WRITE_CHECKSUM_FILE);
}



//Leer datos
int Leer_Datos()
{
if(FAT_ERROR) return 2;
acumulador = 0;
FILE* CONFIG_CHECK_READ_FILE = fopen ("/Tetris_3DS/Tetris3DS_Config.dat", "rb"); //rb = read

if(CONFIG_CHECK_READ_FILE == NULL)
	{
	//No existe el archivo
	//fclose(CONFIG_CHECK_READ_FILE);	
	
	//Default
	texture_selected = 2;
	camera_selected = 2;
	MASTER_SOUND = 64;
	
	Reset_Records();
		
	return 2;
	}

//Comprobar archivo
auxiliar2 = 0;

for(auxiliar = 0; auxiliar < 163; auxiliar ++)
	{
	fread(&auxiliar2, 1, 1, CONFIG_CHECK_READ_FILE);
	acumulador += auxiliar2;
	}

fread(&auxiliar, 4, 1, CONFIG_CHECK_READ_FILE);
fclose(CONFIG_CHECK_READ_FILE);

if(auxiliar == Checksum(acumulador)) //Si el archivo está bien	
	{
	FILE* CONFIG_READ_FILE = fopen ("/Tetris_3DS/Tetris3DS_Config.dat", "rb"); //rb = read

	fread(&texture_selected, 1, 1, CONFIG_READ_FILE);
	fread(&camera_selected, 1, 1, CONFIG_READ_FILE);
	fread(&MASTER_SOUND, 1, 1, CONFIG_READ_FILE);
		
	for(auxiliar = 0; auxiliar < 10; auxiliar ++)
		{
		fread(&Record[auxiliar].Nombre, 1, 10, CONFIG_READ_FILE);
		fread(&Record[auxiliar].Puntuacion, 4, 1, CONFIG_READ_FILE);
		fread(&Record[auxiliar].Lineas, 2, 1, CONFIG_READ_FILE);
		}

	fclose(CONFIG_READ_FILE);
	return 0;
	}
	
//Archivo modificado / corrupto.

//Default
texture_selected = 2;
camera_selected = 2;
MASTER_SOUND = 64;
	
Reset_Records();

return 1;
}

//Comprobar FAT, de paso hace una lectura de los datos.
void Comprobar_FAT()
{
if(!FAT_ERROR)
	{
	switch(Leer_Datos())
		{
		case 0:
			//Todo correcto
			Guardar_Datos();
			break;
			
		case 1:
			//Archivo dañado
			texture_selected = 2;
			camera_selected = 2;
			MASTER_SOUND = 64;
			Reset_Records();
			
			Guardar_Datos();
			PA_OutputSimpleText(1,0,10,"       Save file damaged.");
			PA_OutputSimpleText(1,0,11,"   A new one will be created.");
			PA_OutputSimpleText(1,0,14,"           Press START");
			while(!Pad.Newpress.Start) PA_WaitForVBL();
			break;
	
		case 2:
			//Archivo no existe
			texture_selected = 2;
			camera_selected = 2;
			MASTER_SOUND = 64;
			Reset_Records();
			
			Guardar_Datos();
			if(Leer_Datos() == 2) //Error del FAT
				{
				FAT_ERROR = true;
				PA_OutputSimpleText(1,0,10,"       FAT access error.");
				PA_OutputSimpleText(1,0,14,"          Press START");
				while(!Pad.Newpress.Start) PA_WaitForVBL();
				}
			else
				{
				PA_OutputSimpleText(1,0,10,"       Save file created.");
				PA_OutputSimpleText(1,0,14,"          Press START");
				while(!Pad.Newpress.Start) PA_WaitForVBL();
				}
			break;
		}	
	}
else
	{
	PA_OutputSimpleText(1,0,10,"       FAT access error.");
	PA_OutputSimpleText(1,0,14,"          Press START");
	while(!Pad.Newpress.Start) PA_WaitForVBL();
	
	texture_selected = 2;
	camera_selected = 2;
	MASTER_SOUND = 64;
	Reset_Records();
	}
	
PA_OutputSimpleText(1,0,10,"                                ");
PA_OutputSimpleText(1,0,11,"                                ");
PA_OutputSimpleText(1,0,14,"                                ");
}

#endif
