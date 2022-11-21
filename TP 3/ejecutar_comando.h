#ifndef __EJECUTAR_COMANDO_H_
#define __EJECUTAR_COMANDO_H_

#include "heroe.h"

//PRE: -
//POS: Retorna 0 si no hubo error. Sino el código correspondiente de error.
int activar_comando(char* argv[], FILE* superheroes, char ruta[MAX_RUTA]);


#endif /*__EJECUTAR_COMANDO_H_*/