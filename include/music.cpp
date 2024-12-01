#ifndef __MUSIC_CONTROL__
#define __MUSIC_CONTROL__

#include <header.h>

u8 Current_Song;
char* Song_Path;
bool SONG_ERROR;
s8 Wait_Time;
char* Error_Log;


void Wait_To_Stop_Song()
{
//NO VA ¿?

/*if((!SONG_ERROR) && (!FAT_ERROR))
	{
	while((AS_GetMP3Status() & MP3ST_STOPPED) != 0) 
		{
		AS_MP3Stop();
		PA_WaitForVBL();
		}
	}*/
}


void Set_New_Song_Path()
{
Song_Path = "/Tetris_3DS/Song___.mp3";
sprintf(Song_Path,"/Tetris_3DS/Song_%02d.mp3", Current_Song);
}

void Set_Menu_Song_Path()
{
Song_Path = "/Tetris_3DS/Song___.mp3";
sprintf(Song_Path,"/Tetris_3DS/MENU.mp3");
}

void Pause_Song()
{
if((!FAT_ERROR) && (AS_GetMP3Status() & MP3ST_PLAYING)) AS_MP3Pause();
}

void Reset_Song_Loop()
{
Current_Song = 0;
}

void Clear_Song_Error()
{
SONG_ERROR = false;
}

void Unpause_Song()
{
if(!FAT_ERROR)
	{
	if (AS_GetMP3Status() & MP3ST_PAUSED) 
		{
		AS_MP3Unpause();
		}
	}
}

void Stop_Song()
{
if((!FAT_ERROR) && (AS_GetMP3Status() & MP3ST_PLAYING))
	{
	AS_MP3Stop();
	}
}

void Init_Song_Loop()
{
if(!FAT_ERROR)
	{
	Clear_Song_Error();
	Set_New_Song_Path();
	MP3FILE* file = FILE_OPEN(Song_Path);
	if (!file)
		{
		SONG_ERROR = true;
		}
	FILE_CLOSE(file);
	AS_MP3StreamPlay(Song_Path);
	AS_SetMP3Loop(false);
	}
}

void Init_Menu_Song_Loop()
{
if(!FAT_ERROR)
	{
	Clear_Song_Error();
	Set_Menu_Song_Path();
	MP3FILE* file = FILE_OPEN(Song_Path);
	if (!file)
		{
		SONG_ERROR = true;
		}
	FILE_CLOSE(file);
	if(!SONG_ERROR)
		{
		AS_MP3StreamPlay(Song_Path);
		AS_SetMP3Loop(false);
		}
	}
}


void Check_Song_End()
{
if((!SONG_ERROR) && (!FAT_ERROR))
	{
	if(AS_GetMP3Status() & (MP3ST_STOPPED | MP3ST_OUT_OF_DATA))
		{
		if(Wait_Time == -1) Wait_Time = 0;
		
		if(Wait_Time > 20)
			{
			AS_MP3Stop();
			Current_Song = (Current_Song + 1) % 100;
			Set_New_Song_Path();
			MP3FILE* file = FILE_OPEN(Song_Path);
			if (!file)
				{
				Reset_Song_Loop();
				Set_New_Song_Path();
				FILE_CLOSE(file);
				MP3FILE* file = FILE_OPEN(Song_Path);
				if (!file)
					{
					SONG_ERROR = true;
					}
				}
			FILE_CLOSE(file);
			if(!SONG_ERROR)
				{
				AS_MP3StreamPlay(Song_Path);
				AS_SetMP3Loop(false);
				Wait_Time = -64; //No importa el numero...
				}
			}
		else if (Wait_Time >= 0)
			{
			Wait_Time ++;
			}
		}
	else
		{
		Wait_Time = -1;
		if(AS_GetMP3Status() & MP3ST_DECODE_ERROR)//Error al decodificar
			{
			AS_MP3Stop();
			
			//PA_InitASLibForMP3(AS_MODE_MP3 /*| AS_MODE_SURROUND*/ | AS_MODE_16CH);	
			
			Error_Log = "Error decoding SONG_XX.mp3     ";
			sprintf(Error_Log,"Error decoding SONG_%02d.mp3 \r\n",Current_Song);
			
			//Guardar informacion en un archivo
			FILE* ERROR_LOG_WRITE_FILE = fopen ("/Tetris_3DS/Error_Log.txt", "a"); //wb = create/truncate & write
			if(ERROR_LOG_WRITE_FILE)
				{
				fwrite(Error_Log, 28, 1, ERROR_LOG_WRITE_FILE);
				fclose(ERROR_LOG_WRITE_FILE);
				}
			else
				{
				fclose(ERROR_LOG_WRITE_FILE);	
				FILE* ERROR_LOG_WRITE_FILE = fopen ("/Tetris_3DS/Error_Log.txt", "wb"); //wb = create/truncate & write
				fwrite(Error_Log, 28, 1, ERROR_LOG_WRITE_FILE);
				fclose(ERROR_LOG_WRITE_FILE);	
				}
			
			//Nueva cancion
			AS_MP3Stop();
			Current_Song = (Current_Song + 1) % 100;
			Set_New_Song_Path();
			MP3FILE* file = FILE_OPEN(Song_Path);
			if (!file)
				{
				Reset_Song_Loop();
				Set_New_Song_Path();
				FILE_CLOSE(file);
				MP3FILE* file = FILE_OPEN(Song_Path);
				if (!file)
					{
					SONG_ERROR = true;
					}
				}
			FILE_CLOSE(file);
			if(!SONG_ERROR)
				{
				AS_MP3StreamPlay(Song_Path);
				AS_SetMP3Loop(false);
				Wait_Time = -64; //No importa el numero...
				}
			
			}
		}
	}
}

void Menu_Song()
{
if((!SONG_ERROR) && (!FAT_ERROR))
	{
	if(AS_GetMP3Status() & (MP3ST_STOPPED | MP3ST_OUT_OF_DATA))
		{
		if(Wait_Time == -1) Wait_Time = 0;
		
		if(Wait_Time > 20)
			{
			AS_MP3Stop();
			Set_Menu_Song_Path();
			MP3FILE* file = FILE_OPEN(Song_Path);
			if (!file)
				{
				SONG_ERROR = true;
				}
			FILE_CLOSE(file);
			if(!SONG_ERROR)
				{
				AS_MP3StreamPlay(Song_Path);
				AS_SetMP3Loop(false);
				Wait_Time = -64; //No importa el numero...
				}
			}
		else if (Wait_Time >= 0)
			{
			Wait_Time ++;
			}
		}
	else
		{
		Wait_Time = -1;
		if(AS_GetMP3Status() & MP3ST_DECODE_ERROR)//Error al decodificar
			{
			AS_MP3Stop();
			
			SONG_ERROR = true;
			
			//PA_InitASLibForMP3(AS_MODE_MP3 /*| AS_MODE_SURROUND*/ | AS_MODE_16CH);	
			
			Error_Log = "Error decoding MENU.mp3     ";
			sprintf(Error_Log,"Error decoding MENU.mp3 \r\n ");
				
			//Guardar informacion en un archivo
			FILE* ERROR_LOG_WRITE_FILE = fopen ("/Tetris_3DS/Error_Log.txt", "a"); //wb = create/truncate & write
			if(ERROR_LOG_WRITE_FILE)
				{
				fwrite(Error_Log, 28, 1, ERROR_LOG_WRITE_FILE);
				fclose(ERROR_LOG_WRITE_FILE);
				}
			else
				{
				fclose(ERROR_LOG_WRITE_FILE);	
				FILE* ERROR_LOG_WRITE_FILE = fopen ("/Tetris_3DS/Error_Log.txt", "wb"); //wb = create/truncate & write
				fwrite(Error_Log, 28, 1, ERROR_LOG_WRITE_FILE);
				fclose(ERROR_LOG_WRITE_FILE);	
				}
			}
		}
	}
}



void Set_Song_Number(int numero)
{
if(!FAT_ERROR)
	{
	Current_Song = numero;
	Wait_To_Stop_Song();
	Set_New_Song_Path();
	AS_MP3StreamPlay(Song_Path);
	AS_SetMP3Loop(false);
	}
}

int Get_Song_Number()
{
if(!FAT_ERROR)
	{
	auxiliar4 = Current_Song;
	for(auxiliar = 0; auxiliar < 100; auxiliar ++)
		{
		Current_Song = auxiliar;
		Set_New_Song_Path();
		Current_Song = auxiliar4;
		MP3FILE* file = FILE_OPEN(Song_Path);
		if (!file)
			{
			FILE_CLOSE(file);
			return (auxiliar - 1);
			}
		FILE_CLOSE(file);
		}
	return 100;
	}
return -2;
}


void Write_Error_Log(int numero)
{
// if(AS_GetMP3Status() & MP3ST_DECODE_ERROR)     <-- Usar esto
if((!SONG_ERROR) && (!FAT_ERROR))
	{
	Error_Log = "Error decoding SONG_XX.mp3     ";
	sprintf(Error_Log,"Error decoding SONG_%02d.mp3 \r\n ",numero);
	
	//Guardar informacion en un archivo
	FILE* ERROR_LOG_WRITE_FILE = fopen ("/Tetris_3DS/Error_Log.txt", "a"); //wb = create/truncate & write
	if(ERROR_LOG_WRITE_FILE)
		{
		fwrite(Error_Log, 28, 1, ERROR_LOG_WRITE_FILE);
		fclose(ERROR_LOG_WRITE_FILE);
		}
	else
		{
		fclose(ERROR_LOG_WRITE_FILE);	
		FILE* ERROR_LOG_WRITE_FILE = fopen ("/Tetris_3DS/Error_Log.txt", "wb"); 
		fwrite(Error_Log, 28, 1, ERROR_LOG_WRITE_FILE);
		fclose(ERROR_LOG_WRITE_FILE);	
		}		
	}
}
#endif
