#ifndef __VERIFICAR_ID_H__
#define __VERIFICAR_ID_H__

#include "heroe.h"

//PRE: id > 0 , modo tiene que ser igual a 1 o 2
//POS: Devuelve true si la id ya existe.
bool id_existente(FILE* superheroes, int id, int modo);

#endif /*__VERIFICAR_ID_H__*/