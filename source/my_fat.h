#ifndef MY_FAT_H__
#define MY_FAT_H__

extern bool FAT_ERROR; // Activa/desactiva el acceso al FAT

void Guardar_Datos(void);

int Leer_Datos(void);

// Comprobar FAT, de paso hace una lectura de los datos.
void Comprobar_FAT(void);

#endif // MY_FAT_H__
