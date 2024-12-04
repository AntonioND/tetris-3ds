#ifndef KEYS_CONTROL_H__
#define KEYS_CONTROL_H__

#include <PA9.h>

typedef struct
{
    u8 AlreadyPressed, Held;
} _KEY_STATE_;

extern _KEY_STATE_ A,B,X,Y,Select,Start,L,R,Up,Down,Right,Left,Anykey,Touch;

typedef struct
{
    _KEY_STATE_ A,B,X,Y,Select,Start,L,R,Up,Down,Right,Left,Anykey,Touch;
} _KEYSINFO_;

extern _KEYSINFO_ KI;

void Anular_Newpress();

void My_Newpress();
void Custom_Newpress();

#endif // KEYS_CONTROL_H__
