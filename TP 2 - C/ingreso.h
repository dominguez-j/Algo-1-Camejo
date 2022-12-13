#ifndef __INGRESO_H__
#define __INGRESO_H__

#include "kronos.h"

#define ARRIBA 'W'
#define ABAJO 'S'
#define IZQUIERDA 'A'
#define DERECHA 'D'
#define ACTIVAR_PODER 'C'

//PRE: Juego tiene que estar inicializado.
//POS: Devuelve la tecla ingresada.
char movimiento();

#endif /* __INGRESO_H__ */
