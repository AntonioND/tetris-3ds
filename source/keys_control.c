// SPDX-License-Identifier: GPL-3.0-only
//
// Copyright (c) 2008, 2024-2025 Antonio Niño Díaz

#include <PA9.h>

#include "keys_control.h"

static u8 A_Pressed, B_Pressed, X_Pressed, Y_Pressed, L_Pressed, R_Pressed,
          Select_Pressed, Start_Pressed, Up_Pressed, Down_Pressed, Left_Pressed,
          Right_Pressed;

void Anular_Newpress(void) // :P
{
    Pad.Newpress.A = 0;
    Pad.Newpress.B = 0;
    Pad.Newpress.X = 0;
    Pad.Newpress.Y = 0;
    Pad.Newpress.L = 0;
    Pad.Newpress.R = 0;
    Pad.Newpress.Right = 0;
    Pad.Newpress.Left = 0;
    Pad.Newpress.Up = 0;
    Pad.Newpress.Down = 0;
    Pad.Newpress.Start = 0;
    Pad.Newpress.Select = 0;
    Pad.Newpress.Anykey = 0;
}

void My_Newpress(void)
{
    if ((Pad.Held.A) && (!A_Pressed))
    {
        A_Pressed = 1;
        Pad.Newpress.A = 1;
    }
    if (!Pad.Held.A)
        A_Pressed = 0;

    if ((Pad.Held.B) && (!B_Pressed))
    {
        B_Pressed = 1;
        Pad.Newpress.B = 1;
    }
    if (!Pad.Held.B)
        B_Pressed = 0;

    if ((Pad.Held.X) && (!X_Pressed))
    {
        X_Pressed = 1;
        Pad.Newpress.X = 1;
    }
    if (!Pad.Held.X)
        X_Pressed = 0;

    if ((Pad.Held.Y) && (!Y_Pressed))
    {
        Y_Pressed = 1;
        Pad.Newpress.Y = 1;
    }
    if (!Pad.Held.Y)
        Y_Pressed = 0;

    if ((Pad.Held.L) && (!L_Pressed))
    {
        L_Pressed = 1;
        Pad.Newpress.L = 1;
    }
    if (!Pad.Held.L)
        L_Pressed = 0;

    if ((Pad.Held.R) && (!R_Pressed))
    {
        R_Pressed = 1;
        Pad.Newpress.R = 1;
    }
    if (!Pad.Held.R)
        R_Pressed = 0;

    if ((Pad.Held.Up) && (!Up_Pressed))
    {
        Up_Pressed = 1;
        Pad.Newpress.Up = 1;
    }
    if (!Pad.Held.Up)
        Up_Pressed = 0;

    if ((Pad.Held.Down) && (!Down_Pressed))
    {
        Down_Pressed = 1;
        Pad.Newpress.Down = 1;
    }
    if (!Pad.Held.Down)
        Down_Pressed = 0;

    if ((Pad.Held.Right) && (!Right_Pressed))
    {
        Right_Pressed = 1;
        Pad.Newpress.Right = 1;
    }
    if (!Pad.Held.Right)
        Right_Pressed = 0;

    if ((Pad.Held.Left) && (!Left_Pressed))
    {
        Left_Pressed = 1;
        Pad.Newpress.Left = 1;
    }
    if (!Pad.Held.Left)
        Left_Pressed = 0;

    if ((Pad.Held.Select) && (!Select_Pressed))
    {
        Select_Pressed = 1;
        Pad.Newpress.Select = 1;
    }
    if (!Pad.Held.Select)
        Select_Pressed = 0;

    if ((Pad.Held.Start) && (!Start_Pressed))
    {
        Start_Pressed = 1;
        Pad.Newpress.Start = 1;
    }
    if (!Pad.Held.Start)
        Start_Pressed = 0;
}

void Custom_Newpress(void)
{
    Anular_Newpress();
    My_Newpress();
}
