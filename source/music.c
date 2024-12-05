#include <PA9.h>

#include "global.h"
#include "my_fat.h"

u8 Current_Song;
bool SONG_ERROR;

static char Song_Path[50];
static s8 Wait_Time;

void Wait_To_Stop_Song(void)
{
    // NO VA ¿?

    /*
    if ((!SONG_ERROR) && (!FAT_ERROR))
    {
        while ((AS_GetMP3Status() & MP3ST_STOPPED) != 0)
        {
            AS_MP3Stop();
            PA_WaitForVBL();
        }
    }
    */
}

void Set_New_Song_Path(void)
{
    snprintf(Song_Path, sizeof(Song_Path), "/Tetris_3DS/Song_%02d.mp3", Current_Song);
}

void Set_Menu_Song_Path(void)
{
    snprintf(Song_Path, sizeof(Song_Path), "/Tetris_3DS/MENU.mp3");
}

void Pause_Song(void)
{
    if ((!FAT_ERROR) && (AS_GetMP3Status() & MP3ST_PLAYING))
        AS_MP3Pause();
}

void Reset_Song_Loop(void)
{
    Current_Song = 0;
}

void Clear_Song_Error(void)
{
    SONG_ERROR = false;
}

void Unpause_Song(void)
{
    if (FAT_ERROR)
        return;

    if (AS_GetMP3Status() & MP3ST_PAUSED)
        AS_MP3Unpause();
}

void Stop_Song(void)
{
    if ((!FAT_ERROR) && (AS_GetMP3Status() & MP3ST_PLAYING))
    {
        AS_MP3Stop();
    }
}

void Init_Song_Loop(void)
{
    if (FAT_ERROR)
        return;

    Clear_Song_Error();
    Set_New_Song_Path();

    MP3FILE *file = FILE_OPEN(Song_Path);
    if (!file)
    {
        SONG_ERROR = true;
        return;
    }
    FILE_CLOSE(file);

    AS_MP3StreamPlay(Song_Path);
    AS_SetMP3Loop(false);
}

void Init_Menu_Song_Loop(void)
{
    if (FAT_ERROR)
        return;

    Clear_Song_Error();
    Set_Menu_Song_Path();

    MP3FILE *file = FILE_OPEN(Song_Path);
    if (!file)
    {
        SONG_ERROR = true;
        return;
    }
    FILE_CLOSE(file);

    AS_MP3StreamPlay(Song_Path);
    AS_SetMP3Loop(false);
}

void Check_Song_End(void)
{
    if (SONG_ERROR || FAT_ERROR)
        return;

    if (AS_GetMP3Status() & (MP3ST_STOPPED | MP3ST_OUT_OF_DATA))
    {
        if (Wait_Time == -1)
            Wait_Time = 0;

        if (Wait_Time > 20)
        {
            AS_MP3Stop();
            Current_Song = (Current_Song + 1) % 100;
            Set_New_Song_Path();

            MP3FILE *file = FILE_OPEN(Song_Path);
            if (!file)
            {
                Reset_Song_Loop();
                Set_New_Song_Path();
                FILE_CLOSE(file);
                MP3FILE *file = FILE_OPEN(Song_Path);
                if (!file)
                {
                    SONG_ERROR = true;
                }
            }
            FILE_CLOSE(file);

            if (!SONG_ERROR)
            {
                AS_MP3StreamPlay(Song_Path);
                AS_SetMP3Loop(false);
                Wait_Time = -64; //No importa el numero...
            }
        }
        else if (Wait_Time >= 0)
        {
            Wait_Time++;
        }
    }
    else
    {
        Wait_Time = -1;
        if (AS_GetMP3Status() & MP3ST_DECODE_ERROR) // Error al decodificar
        {
            AS_MP3Stop();

            char Error_Log[100];
            snprintf(Error_Log, sizeof(Error_Log), "Error decoding SONG_%02d.mp3 \r\n", Current_Song);

            // Guardar informacion en un archivo
            FILE *ERROR_LOG_WRITE_FILE = fopen("/Tetris_3DS/Error_Log.txt", "a"); //wb = create/truncate & write
            if (ERROR_LOG_WRITE_FILE)
            {
                fprintf(ERROR_LOG_WRITE_FILE, Error_Log);
                fclose(ERROR_LOG_WRITE_FILE);
            }
            else
            {
                fclose(ERROR_LOG_WRITE_FILE);

                FILE *ERROR_LOG_WRITE_FILE = fopen("/Tetris_3DS/Error_Log.txt", "wb"); //wb = create/truncate & write
                fprintf(ERROR_LOG_WRITE_FILE, Error_Log);
                fclose(ERROR_LOG_WRITE_FILE);
            }

            // Nueva cancion
            AS_MP3Stop();
            Current_Song = (Current_Song + 1) % 100;
            Set_New_Song_Path();
            MP3FILE *file = FILE_OPEN(Song_Path);
            if (!file)
            {
                Reset_Song_Loop();
                Set_New_Song_Path();
                FILE_CLOSE(file);
                MP3FILE *file = FILE_OPEN(Song_Path);
                if (!file)
                {
                    SONG_ERROR = true;
                }
            }
            FILE_CLOSE(file);
            if (!SONG_ERROR)
            {
                AS_MP3StreamPlay(Song_Path);
                AS_SetMP3Loop(false);
                Wait_Time = -64; // No importa el numero...
            }
        }
    }
}

void Menu_Song(void)
{
    if (SONG_ERROR || FAT_ERROR)
        return;

    if (AS_GetMP3Status() & (MP3ST_STOPPED | MP3ST_OUT_OF_DATA))
    {
        if (Wait_Time == -1)
            Wait_Time = 0;

        if (Wait_Time > 20)
        {
            AS_MP3Stop();
            Set_Menu_Song_Path();
            MP3FILE *file = FILE_OPEN(Song_Path);
            if (!file)
            {
                SONG_ERROR = true;
            }
            FILE_CLOSE(file);
            if (!SONG_ERROR)
            {
                AS_MP3StreamPlay(Song_Path);
                AS_SetMP3Loop(false);
                Wait_Time = -64; //No importa el numero...
            }
        }
        else if (Wait_Time >= 0)
        {
            Wait_Time++;
        }
    }
    else
    {
        Wait_Time = -1;
        if (AS_GetMP3Status() & MP3ST_DECODE_ERROR) // Error al decodificar
        {
            AS_MP3Stop();

            SONG_ERROR = true;

            //PA_InitASLibForMP3(AS_MODE_MP3 /*| AS_MODE_SURROUND*/ | AS_MODE_16CH);

            char Error_Log[100];
            snprintf(Error_Log, sizeof(Error_Log), "Error decoding MENU.mp3 \r\n ");

            // Guardar informacion en un archivo
            FILE *ERROR_LOG_WRITE_FILE = fopen("/Tetris_3DS/Error_Log.txt", "a"); //wb = create/truncate & write
            if (ERROR_LOG_WRITE_FILE)
            {
                fprintf(ERROR_LOG_WRITE_FILE, Error_Log);
                fclose(ERROR_LOG_WRITE_FILE);
            }
            else
            {
                fclose(ERROR_LOG_WRITE_FILE);
                FILE *ERROR_LOG_WRITE_FILE = fopen("/Tetris_3DS/Error_Log.txt", "wb"); //wb = create/truncate & write
                fprintf(ERROR_LOG_WRITE_FILE, Error_Log);
                fclose(ERROR_LOG_WRITE_FILE);
            }
        }
    }
}

void Set_Song_Number(int numero)
{
    if (FAT_ERROR)
        return;

    Current_Song = numero;
    Wait_To_Stop_Song();
    Set_New_Song_Path();
    AS_MP3StreamPlay(Song_Path);
    AS_SetMP3Loop(false);
}

int Get_Song_Number(void)
{
    if (FAT_ERROR)
        return -2;

    int old_song = Current_Song;
    for (int i = 0; i < 100; i++)
    {
        Current_Song = auxiliar;
        Set_New_Song_Path();
        Current_Song = old_song;
        MP3FILE *file = FILE_OPEN(Song_Path);
        if (!file)
        {
            //FILE_CLOSE(file);
            return (auxiliar - 1);
        }
        FILE_CLOSE(file);
    }

    return 100;
}

void Write_Error_Log(int numero)
{
    // if (AS_GetMP3Status() & MP3ST_DECODE_ERROR)     <-- Usar esto
    if (SONG_ERROR || FAT_ERROR)
        return;

    char Error_Log[100];
    snprintf(Error_Log, sizeof(Error_Log), "Error decoding SONG_%02d.mp3 \r\n ", numero);

    //Guardar informacion en un archivo
    FILE* ERROR_LOG_WRITE_FILE = fopen("/Tetris_3DS/Error_Log.txt", "a"); //wb = create/truncate & write
    if (ERROR_LOG_WRITE_FILE)
    {
        fprintf(ERROR_LOG_WRITE_FILE, Error_Log);
        fclose(ERROR_LOG_WRITE_FILE);
    }
    else
    {
        fclose(ERROR_LOG_WRITE_FILE);
        FILE *ERROR_LOG_WRITE_FILE = fopen("/Tetris_3DS/Error_Log.txt", "wb");
        fprintf(ERROR_LOG_WRITE_FILE, Error_Log);
        fclose(ERROR_LOG_WRITE_FILE);
    }
}
