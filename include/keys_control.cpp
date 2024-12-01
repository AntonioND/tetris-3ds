#ifndef __KEYS_CONTROL__
#define __KEYS_CONTROL__

u8 A_Pressed, B_Pressed, X_Pressed, Y_Pressed, L_Pressed, R_Pressed,
   Select_Pressed, Start_Pressed, Up_Pressed, Down_Pressed, Left_Pressed,
   Right_Pressed, Anykey_Pressed;

typedef struct
	{
	u8 AlreadyPressed, Held;
	} _KEY_STATE_;

_KEY_STATE_ A,B,X,Y,Select,Start,L,R,Up,Down,Right,Left,Anykey,Touch;

typedef struct
	{
	_KEY_STATE_ A,B,X,Y,Select,Start,L,R,Up,Down,Right,Left,Anykey,Touch;
	} _KEYSINFO_;
	
_KEYSINFO_ Keys;

void Anular_Newpress() //:P
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

void My_Newpress()
{
if((Pad.Held.A) && (!A_Pressed)) { A_Pressed = 1; Pad.Newpress.A = 1; }
if(!Pad.Held.A) A_Pressed = 0;

if((Pad.Held.B) && (!B_Pressed)) { B_Pressed = 1;	Pad.Newpress.B = 1; }
if(!Pad.Held.B) B_Pressed = 0;

if((Pad.Held.X) && (!X_Pressed)) { X_Pressed = 1;	Pad.Newpress.X = 1; }
if(!Pad.Held.X) X_Pressed = 0;

if((Pad.Held.Y) && (!Y_Pressed)) { Y_Pressed = 1;	Pad.Newpress.Y = 1; }
if(!Pad.Held.Y) Y_Pressed = 0;

if((Pad.Held.L) && (!L_Pressed)) { L_Pressed = 1;	Pad.Newpress.L = 1; }
if(!Pad.Held.L) L_Pressed = 0;

if((Pad.Held.R) && (!R_Pressed)) { R_Pressed = 1;	Pad.Newpress.R = 1; }
if(!Pad.Held.R) R_Pressed = 0;

if((Pad.Held.Up) && (!Up_Pressed)) { Up_Pressed = 1; Pad.Newpress.Up = 1; }
if(!Pad.Held.Up) Up_Pressed = 0;

if((Pad.Held.Down) && (!Down_Pressed)) { Down_Pressed = 1; Pad.Newpress.Down = 1; }
if(!Pad.Held.Down) Down_Pressed = 0;

if((Pad.Held.Right) && (!Right_Pressed)) { Right_Pressed = 1; Pad.Newpress.Right = 1; }
if(!Pad.Held.Right) Right_Pressed = 0;

if((Pad.Held.Left) && (!Left_Pressed)) { Left_Pressed = 1; Pad.Newpress.Left = 1; }
if(!Pad.Held.Left) Left_Pressed = 0;

if((Pad.Held.Select) && (!Select_Pressed)) { Select_Pressed = 1; Pad.Newpress.Select = 1; }
if(!Pad.Held.Select) Select_Pressed = 0;

if((Pad.Held.Start) && (!Start_Pressed)) { Start_Pressed = 1; Pad.Newpress.Start = 1; }
if(!Pad.Held.Start) Start_Pressed = 0;
}

void Custom_Newpress()
{
Anular_Newpress();
My_Newpress();
}

void My_Press_Buttons()
{

if(Pad.Newpress.Anykey) //Preparar boton
	{Keys.Anykey.AlreadyPressed = 1; Keys.Anykey.Held = 0;}
if(Pad.Released.Anykey) //Reset
	{Keys.Anykey.AlreadyPressed = 0; Keys.Anykey.Held = 0;}
if(Pad.Held.Anykey)
	{
	if(!Keys.Anykey.AlreadyPressed) //Si no estaba pulsado
		{
		Pad.Newpress.Anykey = 1;
		Keys.Anykey.AlreadyPressed = 1;
		Keys.Anykey.Held = 0;
		}
	else //Ya estaba pulsado
		{
		if(Keys.Anykey.Held) //Si estaba pulsado...
			{/*Nada*/}
		else //Si no estaba pulsado
			{Keys.Anykey.Held = 1;}
		}	
	}
else //Si no esta pulsado
	{
	if(Keys.Anykey.Held) //Se acaba de soltar
		{ Keys.Anykey.Held = 0; Pad.Released.Anykey = 1; }
	//No se ha tocado
	else {/*Nada*/}
	}
	
	
if(Pad.Newpress.A) //Preparar boton
	{Keys.A.AlreadyPressed = 1; Keys.A.Held = 0;}
if(Pad.Released.A) //Reset
	{Keys.A.AlreadyPressed = 0; Keys.A.Held = 0;}
if(Pad.Held.A)
	{
	if((!Keys.A.AlreadyPressed) && (!Pad.Newpress.A)) //Si no estaba pulsado
		{
		Pad.Newpress.A = 1;
		Keys.A.AlreadyPressed = 1;
		Keys.A.Held = 0;
		}
	else //Ya estaba pulsado
		{
		if(Keys.A.Held) //Si estaba pulsado...
			{/*Nada*/}
		else //Si no estaba pulsado
			{Keys.A.Held = 1;}
		}	
	}
else //Si no esta pulsado
	{
	if((Keys.A.Held) && (!Pad.Released.A))//Se acaba de soltar
		{ Keys.A.Held = 0; Pad.Released.A = 1; Keys.A.AlreadyPressed = 0;}
	//No se ha tocado
	else {/*Nada*/}
	}


}


#endif
