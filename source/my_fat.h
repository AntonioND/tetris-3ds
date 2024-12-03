#ifndef MY_FAT_H__
#define MY_FAT_H__

extern bool FAT_ERROR; // Activa/desactiva el acceso al FAT

int Checksum(u32 datos);

void Guardar_Datos();

int Leer_Datos();

// Comprobar FAT, de paso hace una lectura de los datos.
void Comprobar_FAT();

#endif // MY_FAT_H__
