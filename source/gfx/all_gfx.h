//Gfx converted using Mollusk's PAGfx Converter

//This file contains all the .h, for easier inclusion in a project

#ifndef ALL_GFX_H
#define ALL_GFX_H

#ifndef PAGfx_struct
    typedef struct{
    void *Map;
    int MapSize;
    void *Tiles;
    int TileSize;
    void *Palette;
    int *Info;
} PAGfx_struct;
#endif


// Sprite files : 
extern const unsigned char Pieza_Sprite[3584] __attribute__ ((aligned (4))) ;  // Pal : Pieza_Pal
extern const unsigned char botones_Sprite[2048] __attribute__ ((aligned (4))) ;  // Pal : botones_Pal
extern const unsigned char numeros_Sprite[768] __attribute__ ((aligned (4))) ;  // Pal : numeros_Pal
extern const unsigned char cursor_sonido_Sprite[512] __attribute__ ((aligned (4))) ;  // Pal : cursor_sonido_Pal

// Background files : 
extern const int custom_font_Info[3]; // BgMode, Width, Height
extern const unsigned short custom_font_Map[768] __attribute__ ((aligned (4))) ;  // Pal : custom_font_Pal
extern const unsigned char custom_font_Tiles[11264] __attribute__ ((aligned (4))) ;  // Pal : custom_font_Pal
extern PAGfx_struct custom_font; // background pointer

extern const unsigned short superior_inicio_Bitmap[49152] __attribute__ ((aligned (4))) ;  // 16bit bitmap

extern const int inferior_inicio_Info[3]; // BgMode, Width, Height
extern const unsigned short inferior_inicio_Map[768] __attribute__ ((aligned (4))) ;  // Pal : inferior_inicio_Pal
extern const unsigned char inferior_inicio_Tiles[6528] __attribute__ ((aligned (4))) ;  // Pal : inferior_inicio_Pal
extern PAGfx_struct inferior_inicio; // background pointer

extern const int inferior_juego_Info[3]; // BgMode, Width, Height
extern const unsigned short inferior_juego_Map[768] __attribute__ ((aligned (4))) ;  // Pal : inferior_juego_Pal
extern const unsigned char inferior_juego_Tiles[28672] __attribute__ ((aligned (4))) ;  // Pal : inferior_juego_Pal
extern PAGfx_struct inferior_juego; // background pointer

extern const int inferior_versus_Info[3]; // BgMode, Width, Height
extern const unsigned short inferior_versus_Map[768] __attribute__ ((aligned (4))) ;  // Pal : inferior_versus_Pal
extern const unsigned char inferior_versus_Tiles[39488] __attribute__ ((aligned (4))) ;  // Pal : inferior_versus_Pal
extern PAGfx_struct inferior_versus; // background pointer

extern const int inferior_disco_Info[3]; // BgMode, Width, Height
extern const unsigned short inferior_disco_Map[768] __attribute__ ((aligned (4))) ;  // Pal : inferior_disco_Pal
extern const unsigned char inferior_disco_Tiles[31104] __attribute__ ((aligned (4))) ;  // Pal : inferior_disco_Pal
extern PAGfx_struct inferior_disco; // background pointer

extern const unsigned short menu_inferior_Bitmap[49152] __attribute__ ((aligned (4))) ;  // 16bit bitmap

extern const unsigned short inferior_credits_Bitmap[49152] __attribute__ ((aligned (4))) ;  // 16bit bitmap

extern const unsigned short options_inferior_Bitmap[49152] __attribute__ ((aligned (4))) ;  // 16bit bitmap

extern const int inferior_records_Info[3]; // BgMode, Width, Height
extern const unsigned short inferior_records_Map[768] __attribute__ ((aligned (4))) ;  // Pal : inferior_records_Pal
extern const unsigned char inferior_records_Tiles[25536] __attribute__ ((aligned (4))) ;  // Pal : inferior_records_Pal
extern PAGfx_struct inferior_records; // background pointer


// Palette files : 
extern const unsigned short Pieza_Pal[10] __attribute__ ((aligned (4))) ;
extern const unsigned short botones_Pal[4] __attribute__ ((aligned (4))) ;
extern const unsigned short numeros_Pal[7] __attribute__ ((aligned (4))) ;
extern const unsigned short cursor_sonido_Pal[6] __attribute__ ((aligned (4))) ;
extern const unsigned short custom_font_Pal[7] __attribute__ ((aligned (4))) ;
extern const unsigned short inferior_inicio_Pal[12] __attribute__ ((aligned (4))) ;
extern const unsigned short inferior_juego_Pal[46] __attribute__ ((aligned (4))) ;
extern const unsigned short inferior_versus_Pal[32] __attribute__ ((aligned (4))) ;
extern const unsigned short inferior_disco_Pal[51] __attribute__ ((aligned (4))) ;
extern const unsigned short inferior_records_Pal[89] __attribute__ ((aligned (4))) ;


#endif

