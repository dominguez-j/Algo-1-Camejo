#ifndef __AGREGAR_H__
#define __AGREGAR_H__

#include "heroe.h"
#include "verificar_ingreso.h"

//PRE: id mayor a 0, edad entre 1 y 100 (inclusives), estado igual a vivo o muerto, el nombre menor a 50 caracteres.
//POS: Agrega un superheroe a la lista. Retorna -3 o -6 si hubo un error. Sino 0.
int agregar_superheroes(FILE* superheroes, int id, char nombre[MAX_NOMBRE], int edad, char estado[MAX_ESTADO], char ruta[MAX_RUTA]);

#endif /*__AGREGAR_H__*/