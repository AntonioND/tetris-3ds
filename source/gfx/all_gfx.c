//Gfx converted using Mollusk's PAGfx Converter

//This file contains all the .c, for easier inclusion in a project

#ifdef __cplusplus
extern "C" {
#endif

#include "all_gfx.h"


// Sprite files : 
#include "Pieza.h"
#include "botones.h"
#include "numeros.h"
#include "cursor_sonido.h"

// Background files : 
#include "custom_font.h"
#include "superior_inicio.h"
#include "inferior_inicio.h"
#include "inferior_juego.h"
#include "inferior_versus.h"
#include "inferior_disco.h"
#include "menu_inferior.h"
#include "inferior_credits.h"
#include "options_inferior.h"
#include "inferior_records.h"

// Palette files : 
#include "Pieza.pal.h"
#include "botones.pal.h"
#include "numeros.pal.h"
#include "cursor_sonido.pal.h"
#include "custom_font.pal.h"
#include "inferior_inicio.pal.h"
#include "inferior_juego.pal.h"
#include "inferior_versus.pal.h"
#include "inferior_disco.pal.h"
#include "inferior_records.pal.h"

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

