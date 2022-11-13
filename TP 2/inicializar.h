#ifndef __INICIALIZAR_H__
#define __INICIALIZAR_H__

#include "kronos.h"
#include "terreno.h"
#include <stdlib.h>
#include <time.h>

#define CUADRANTE_1 1
#define CUADRANTE_2 2
#define CUADRANTE_3 3
#define CUADRANTE_4 4
#define TOPE_PERSONAJES 4
#define TOPE_PINZAS 16
#define TOPE_ROBOTS 4
#define TOPE_SUPERTRAJE 4
#define TOPE_PINZAS_POR_CUADRANTE 4


//PRE: El rango tiene que ser mayor a 0;
//POS: Te doy un numero aleatorio.
int posicion_random(int rango, int desplazamiento);

//PRE: Tablero tiene que estar cargado.
//POS: Asigna aleatoriamente la posición del personaje.
void inicializar_personajes(personaje_t personajes[MAX_PERSONAJES], char tablero[MAX_FILAS][MAX_COLUMNAS]);

//PRE: Tablero tiene que estar cargado.
//POS: Asigna aleatoriamente la posición de los personajes.
void inicializar_supertrajes(supertraje_t supertrajes[MAX_SUPERTRAJES], char tablero[MAX_FILAS][MAX_COLUMNAS]);

//PRE: Tablero tiene que estar cargado.
//POS: Asigna aleatoriamente la posición de las pinzas.
void inicializar_pinzas(coordenada_t pinzas[MAX_PINZAS], char tablero[MAX_FILAS][MAX_COLUMNAS]);

//PRE: Tablero tiene que estar cargado.
//POS: Asigna aleatoriamente la posición de los lasers.
void inicializar_lasers(robot_t robots[MAX_ROBOTS], int longitud_laser, char tablero[MAX_FILAS][MAX_COLUMNAS]);

//PRE: Tablero tiene que estar cargado.
//POS: Asigna aleatoriamente la posición de los robots.
void inicializar_robots(robot_t robots[MAX_ROBOTS], char tablero[MAX_FILAS][MAX_COLUMNAS]);


#endif /* __INICIALIZAR_H__ */