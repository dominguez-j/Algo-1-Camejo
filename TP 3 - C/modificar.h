#ifndef __MODIFICAR_H__
#define __MODIFICAR_H__

#include "heroe.h"
#include "verificar_ingreso.h"

//PRE: id mayor a 0, edad entre 1 y 100 (inclusives), estado igual a vivo o muerto.
//POS: Modifica un supersonaje si existe. Retorna -5 o -6 si hubo un error. Sino 0.
int modificar_superheroes(FILE* superheroes, int id, int edad, char estado[MAX_ESTADO], char ruta[MAX_RUTA]);

#endif /*__MODIFICAR_H__*/