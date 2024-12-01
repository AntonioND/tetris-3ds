//Gfx converted using Mollusk's PAGfx Converter

//This file contains all the .c, for easier inclusion in a project

#ifdef __cplusplus
extern "C" {
#endif

#include "all_gfx.h"


// Sprite files : 
#include "Pieza.c"
#include "botones.c"
#include "numeros.c"
#include "cursor_sonido.c"

// Background files : 
#include "custom_font.c"
#include "superior_inicio.c"
#include "inferior_inicio.c"
#include "inferior_juego.c"
#include "inferior_versus.c"
#include "inferior_disco.c"
#include "menu_inferior.c"
#include "inferior_credits.c"
#include "options_inferior.c"
#include "inferior_records.c"

// Palette files : 
#include "Pieza.pal.c"
#include "botones.pal.c"
#include "numeros.pal.c"
#include "cursor_sonido.pal.c"
#include "custom_font.pal.c"
#include "inferior_inicio.pal.c"
#include "inferior_juego.pal.c"
#include "inferior_versus.pal.c"
#include "inferior_disco.pal.c"
#include "inferior_records.pal.c"

// Background Pointers :
PAGfx_struct custom_font = {(void*)custom_font_Map, 768, (void*)custom_font_Tiles, 11264, (void*)custom_font_Pal, (int*)custom_font_Info };
PAGfx_struct inferior_inicio = {(void*)inferior_inicio_Map, 768, (void*)inferior_inicio_Tiles, 6528, (void*)inferior_inicio_Pal, (int*)inferior_inicio_Info };
PAGfx_struct inferior_juego = {(void*)inferior_juego_Map, 768, (void*)inferior_juego_Tiles, 28672, (void*)inferior_juego_Pal, (int*)inferior_juego_Info };
PAGfx_struct inferior_versus = {(void*)inferior_versus_Map, 768, (void*)inferior_versus_Tiles, 39488, (void*)inferior_versus_Pal, (int*)inferior_versus_Info };
PAGfx_struct inferior_disco = {(void*)inferior_disco_Map, 768, (void*)inferior_disco_Tiles, 31104, (void*)inferior_disco_Pal, (int*)inferior_disco_Info };
PAGfx_struct inferior_records = {(void*)inferior_records_Map, 768, (void*)inferior_records_Tiles, 25536, (void*)inferior_records_Pal, (int*)inferior_records_Info };


#ifdef __cplusplus
}
#endif

