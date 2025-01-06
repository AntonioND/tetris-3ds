		-----------------
		-TETRIS 3DS v1.4-
		-----------------

Este juego es un tetris en 3D, con el que podrás escuchar la música
que quieras en formato MP3 mientras juegas :P. Tienes que reducir el
archivo todo lo que puedas sin que pierda calidad desde tu punto de
vista, de este modo se reducen los problemas que puedan ocurrir al 
intentar decodificar el archivo. Los récords del modo normal se 
guardan junto con la configuración automáticamente. Si el juego se
bloquea y ves una pantalla roja con números, mándame un email con
el "pc" (está arriba a la izquierda) y una pequeña descripción de
lo que hacías antes de que pasara eso.



Uso:
----

El menú es muy sencillo... No hay mucho que decir... Lo único que
puede ser interesante es la JUKEBOX dentro de las opciones, con la
que podrás escuchar los MP3 del juego sin tener que estar jugando
mientras tanto.

En el menú principal puedes apagar la ds si pulsas L + R + Select
+ Start, no sirve de mucho... pero ahí está para quien lo quiera.



Controles:
----------

+Botones:

DS de lado: 
 Arriba/Abajo -> Izquierda/Derecha.
 Izquierda -> Cae la pieza más rápido.
 Derecha -> Cae la pieza automáticamente.

DS normal:
 Izquierda/Derecha -> Izquierda/Derecha.
 Abajo -> Cae la pieza más rápido.
 Arriba -> Cae la pieza automáticamente.

A: Girar.
X: Meter a la reserva.
START: Pausa.


+Con tactil:

DS de lado: 
 Stylus Arriba/Abajo -> Izquierda/Derecha.
 Stylus Izquierda -> Cae la pieza más rápido.
 Movimiento rápido izquierda -> Cae la pieza automáticamente.
 Movimiento rápido derecha -> Meter a la reserva.

DS normal:
 Stylus Izquierda/Derecha -> Izquierda/Derecha.
 Stylus Abajo -> Cae la pieza más rápido.
 Movimiento rápido abajo -> Cae la pieza automáticamente.
 Movimiento rápido arriba -> Meter a la reserva.

Doble clic -> Girar.
START: Pausa.


Archivos necesarios:
--------------------

Raiz:
  |
  |-Tetris_3DS
     |
     |-Tetris_3DS.nds (Se puede poner en otro sitio.)
     |-MENU.mp3
     |-SONG_00.mp3
     |-SONG_XX.mp3 (De 01 a 99)
     |-Tetris3DS_Config.dat (Se crea solo si no está.)

Pon tantos SONG_XX como quieras, pero la numeracion es con 2 digitos,
es decir, 1 = SONG_01.mp3, etc... Si falta un número volverá a la 
canción SONG_00.mp3 y las siguientes no se reproducirán. Si falla al
reproducir una canción se la saltará y se creará un archivo llamado
"Error_Log.txt" con el archivo que ha dado el error (Se tiene que
abrir con un programa que no sea el bloc de notas). Si no encuentra 
"MENU.mp3" o "SONG_00.mp3", no se escuchará nada en el menú o durante
el juego respectivamente. Los archivos de música deben ser lo más
pequeños posible. Recomiendo dejarlos a unos 2 o 3 MB de tamaño. Si
son más grandes es posible que de error al cargarlos. 



Problema al iniciar:
--------------------

Me han comentado un par de personas que al iniciar el juego se quedan
las pantallas negras y no hace nada más. Esto es debido a que hay un
error al escribir datos en la tarjeta. Puedes "solucionarlo" si pulsas
L+R mientras se carga el juego. Esto desactivará el acceso al FAT, por
tanto, no podrás guardar tus datos o escuchar los MP3 de la carpeta, 
pero el juego funcionará.



CREDITOS
--------

Joat y Dovoto por libnds (y su parte 3D, jejeje).
Mollusk por PAlib y su parte de 2D.
Noda por las ASlib, sin las que no podría reproducir MP3.
