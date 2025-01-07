// SPDX-License-Identifier: GPL-3.0-only
//
// Copyright (c) 2008, 2024-2025 Antonio Niño Díaz

#ifndef MUSIC_H__
#define MUSIC_H__

#include <nds.h>

extern u8 Current_Song;
extern bool SONG_ERROR;

void Wait_To_Stop_Song(void);

void Set_New_Song_Path(void);

void Set_Menu_Song_Path(void);

void Pause_Song(void);

void Reset_Song_Loop(void);

void Clear_Song_Error(void);

void Unpause_Song(void);

void Stop_Song(void);

void Init_Song_Loop(void);
void Init_Menu_Song_Loop(void);

void Check_Song_End(void);

void Menu_Song(void);

void Set_Song_Number(int numero);
int Get_Song_Number(void);

void Write_Error_Log(int numero);

#endif // MUSIC_H__
