#ifndef __TERRENO_H__
#define __TERRENO_H__

#include "kronos.h"

#define MAX_FILAS 20
#define MAX_COLUMNAS 20
#define MIN_TABLERO 0
#define MAX_TABLERO 19
#define ESPACIO_VACIO '.'
#define ROBOT 'R'
#define LASER 'L'
#define PINZA 'P'
#define SALIDA 'S'
#define SUPERTRAJE 'T'
#define ELASTIC_GIRL 'E'
#define VIOLETA 'V'
#define DASH 'D'
#define MR_INCREIBLE 'I'
#define SALIDA_FILA 0
#define SALIDA_COLUMNA 19

//PRE: -
//POS: Llena el tablero con ESPACIO_VACIO
void llenar_terreno(char tablero[MAX_FILAS][MAX_COLUMNAS]);

//PRE: El tablero tiene que estar inicializado en ESPACIO_VACIO.
//POS: Pone la salida.
void poner_salida(char tablero[MAX_FILAS][MAX_COLUMNAS]);

//PRE: Juego y tablero tienen que estar inicializados.
//POS: Asigna todo lo del juego en el tablero.
void modificar_terreno(juego_t juego, char tablero[MAX_FILAS][MAX_COLUMNAS]);

#endif /* __TERRENO_H__ */