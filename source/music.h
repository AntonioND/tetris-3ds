#ifndef MUSIC_H__
#define MUSIC_H__

#include <nds.h>

extern u8 Current_Song;
extern bool SONG_ERROR;

void Wait_To_Stop_Song();

void Set_New_Song_Path();

void Set_Menu_Song_Path();

void Pause_Song();

void Reset_Song_Loop();

void Clear_Song_Error();

void Unpause_Song();

void Stop_Song();

void Init_Song_Loop();
void Init_Menu_Song_Loop();

void Check_Song_End();

void Menu_Song();

void Set_Song_Number(int numero);
int Get_Song_Number();

void Write_Error_Log(int numero);

#endif // MUSIC_H__
