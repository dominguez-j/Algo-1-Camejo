#ifndef __CONTACTAR_H__
#define __CONTACTAR_H__

#include "heroe.h"
#include "verificar_ingreso.h"

//PRE: id mayor a 0.
//POS: Elimina y muestra al superheroes de la lista. Retorna -4 o -6 si hubo un error. Sino 0.
int contactar_superheroes(FILE* superheroes, int id, char ruta[MAX_RUTA]);

#endif /*__CONTACTAR_H__*/