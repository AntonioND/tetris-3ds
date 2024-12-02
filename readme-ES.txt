		-----------------
		-TETRIS 3DS v1.3-
		-----------------

Este juego es un tetris en 3D, con el que podr�s escuchar la m�sica
que quieras en formato MP3 mientras juegas :P. Tienes que reducir el
archivo todo lo que puedas sin que pierda calidad desde tu punto de
vista, de este modo se reducen los problemas que puedan ocurrir al 
intentar decodificar el archivo. Los r�cords del modo normal se 
guardan junto con la configuraci�n autom�ticamente. Si el juego se
bloquea y ves una pantalla roja con n�meros, m�ndame un email con
el "pc" (est� arriba a la izquierda) y una peque�a descripci�n de
lo que hac�as antes de que pasara eso.



Uso:
----

El men� es muy sencillo... No hay mucho que decir... Lo �nico que
puede ser interesante es la JUKEBOX dentro de las opciones, con la
que podr�s escuchar los MP3 del juego sin tener que estar jugando
mientras tanto.

En el men� principal puedes apagar la ds si pulsas L + R + Select
+ Start, no sirve de mucho... pero ah� est� para quien lo quiera.



Controles:
----------

+Botones:

DS de lado: 
 Arriba/Abajo -> Izquierda/Derecha.
 Izquierda -> Cae la pieza m�s r�pido.
 Derecha -> Cae la pieza autom�ticamente.

DS normal:
 Izquierda/Derecha -> Izquierda/Derecha.
 Abajo -> Cae la pieza m�s r�pido.
 Arriba -> Cae la pieza autom�ticamente.

A: Girar.
X: Meter a la reserva.
START: Pausa.


+Con tactil:

DS de lado: 
 Stylus Arriba/Abajo -> Izquierda/Derecha.
 Stylus Izquierda -> Cae la pieza m�s r�pido.
 Movimiento r�pido izquierda -> Cae la pieza autom�ticamente.
 Movimiento r�pido derecha -> Meter a la reserva.

DS normal:
 Stylus Izquierda/Derecha -> Izquierda/Derecha.
 Stylus Abajo -> Cae la pieza m�s r�pido.
 Movimiento r�pido abajo -> Cae la pieza autom�ticamente.
 Movimiento r�pido arriba -> Meter a la reserva.

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
     |-Tetris3DS_Config.dat (Se crea solo si no est�.)

Pon tantos SONG_XX como quieras, pero la numeracion es con 2 digitos,
es decir, 1 = SONG_01.mp3, etc... Si falta un n�mero volver� a la 
canci�n SONG_00.mp3 y las siguientes no se reproducir�n. Si falla al
reproducir una canci�n se la saltar� y se crear� un archivo llamado
"Error_Log.txt" con el archivo que ha dado el error (Se tiene que
abrir con un programa que no sea el bloc de notas). Si no encuentra 
"MENU.mp3" o "SONG_00.mp3", no se escuchar� nada en el men� o durante
el juego respectivamente. Los archivos de m�sica deben ser lo m�s
peque�os posible. Recomiendo dejarlos a unos 2 o 3 MB de tama�o. Si
son m�s grandes es posible que de error al cargarlos. 



Problema al iniciar:
--------------------

Me han comentado un par de personas que al iniciar el juego se quedan
las pantallas negras y no hace nada m�s. Esto es debido a que hay un
error al escribir datos en la tarjeta. Puedes "solucionarlo" si pulsas
L+R mientras se carga el juego. Esto desactivar� el acceso al FAT, por
tanto, no podr�s guardar tus datos o escuchar los MP3 de la carpeta, 
pero el juego funcionar�.



CREDITOS
--------

Joat y Dovoto por libnds (y su parte 3D, jejeje).
Mollusk por PAlib y su parte de 2D.
Noda por las ASlib, sin las que no podr�a reproducir MP3.