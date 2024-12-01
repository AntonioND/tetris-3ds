		-----------------
		-TETRIS 3DS v1.3-
		-----------------

This game is a 3D tetris. You will be able to listen to your own MP3
songs while you play :P. In order to do that you have to keep the size
of the songs under 3MB, if not the game will probably crash. Records 
are saved automatically. If the game freezes and show a red screen
with white numbers, email me with te number "pc" at the upper-left
part of the screen and a brief description of what you were doing
before that.



Usage:
------

Menu is very simple... The only interesting thing is the JUKEBOX
inside opcions. You can listen to your MP3 even if you aren't
playing.

You can switch off the DS in main menu pressing L + R + Select
+ Start, it's useless... 



Controls:
---------

+Buttons:

DS sided: 
 Up/Down -> Left/Right.
 Left -> Down speed increased.
 Right -> Tetromino automaticaly go down.

DS normal:
 Left/Right -> Left/Right.
 Down -> Down speed increased.
 Up -> Tetromino automaticaly go down.

A: Rotate.
X: Reserve.
START: Pause.


+Touch screen:

DS sided: 
 Stylus Up/Down -> Left/Right.
 Stylus Left -> Down speed increased.
 Quick left movement -> Tetromino automaticaly go down.
 Quick right movement -> Reserve.

DS normal:
 Stylus Left/Right -> Left/Right.
 Stylus Down -> Down speed increased.
 Quick down movement -> Tetromino automaticaly go down.
 Quick up movement -> Reserve.

Double clic -> Rotate.
START: Pause.


Needed files:
-------------

Root:
  |
  |-Tetris_3DS
     |
     |-Tetris_3DS.nds
     |-MENU.mp3
     |-SONG_00.mp3
     |-SONG_XX.mp3 (From 01 to 99)
     |-Tetris3DS_Config.dat (It is created automatically.)

Put as many SONG_XX as you want. You have to name them 00,01,01
instead of 0,1,2,3... For example, 1 = SONG_01.MP3. When the game
tries to load a song that doesn't exist it will go back to SONG_00.MP3
If some song gives a decoding error the game will trie to stop it and
load the next song, but it sometimes crash. If the game stops the
song it will create a file named "Error_Log.txt" with the bad file.
If the game doesn't find "MENU.mp3" o "SONG_00.mp3", you won't hear
anything in the menu or during the game. You should keep you MP3 files
under 3MB of size.



Init problem:
-------------

Sometimes the game gives an error while loading and both screens
just turn black and the game freezes. This happens because it gives
a write error even if FAT has inited OK... You can stop FAT init
if you hold R + L when the game loads. It won't load anything from
FAT, but the game will work.



CREDITS
-------

Joat and Dovoto for libnds.
Mollusk for PAlib.
Noda for ASlib.