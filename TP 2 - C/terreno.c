#include "terreno.h"
#include <stdio.h>

void llenar_terreno(char tablero[MAX_FILAS][MAX_COLUMNAS]){
    for(int i = 0; i < MAX_FILAS; i++){
        for(int j = 0; j < MAX_COLUMNAS; j++)
            tablero[i][j] = ESPACIO_VACIO;
    }
}

void poner_salida(char tablero[MAX_FILAS][MAX_COLUMNAS]){
    tablero[SALIDA_FILA][SALIDA_COLUMNA] = SALIDA;
}

void modificar_terreno(juego_t juego, char tablero[MAX_FILAS][MAX_COLUMNAS]){
    llenar_terreno(tablero);
    poner_salida(tablero);

    for(int i = 0; i < juego.tope_robots; i++)
        tablero[juego.robots[i].posicion.fila][juego.robots[i].posicion.columna] = ROBOT;
   
    for(int i = 0; i < juego.tope_pinzas; i++)
        tablero[juego.pinzas[i].fila][juego.pinzas[i].columna] = PINZA;
    
    for(int i = 0; i < juego.tope_supertraje; i++){
        if(!juego.supertrajes[i].recolectado)
            tablero[juego.supertrajes[i].posicion.fila][juego.supertrajes[i].posicion.columna] = SUPERTRAJE;
    }

    if(1 == juego.id_personaje_actual){
        tablero[juego.personajes[0].posicion.fila][juego.personajes[0].posicion.columna] = ELASTIC_GIRL;
        tablero[juego.personajes[1].posicion.fila][juego.personajes[1].posicion.columna] = VIOLETA;
        tablero[juego.personajes[2].posicion.fila][juego.personajes[2].posicion.columna] = DASH;
        tablero[juego.personajes[3].posicion.fila][juego.personajes[3].posicion.columna] = MR_INCREIBLE; 
    }
    else if(2 == juego.id_personaje_actual){
        tablero[juego.personajes[1].posicion.fila][juego.personajes[1].posicion.columna] = VIOLETA;
        tablero[juego.personajes[2].posicion.fila][juego.personajes[2].posicion.columna] = DASH;
        tablero[juego.personajes[3].posicion.fila][juego.personajes[3].posicion.columna] = MR_INCREIBLE;  
    }else if(3 == juego.id_personaje_actual){
        tablero[juego.personajes[2].posicion.fila][juego.personajes[2].posicion.columna] = DASH;
        tablero[juego.personajes[3].posicion.fila][juego.personajes[3].posicion.columna] = MR_INCREIBLE;  
    }else
        tablero[juego.personajes[3].posicion.fila][juego.personajes[3].posicion.columna] = MR_INCREIBLE;  
            
    for(int i = 0; i < juego.tope_robots; i++){
        for(int j = 0; j < juego.robots[i].tope_lasers; j++){
            int fila_l = juego.robots[i].lasers[j].fila;
            int columna_l = juego.robots[i].lasers[j].columna;
            if(fila_l >= MIN_TABLERO && fila_l <= MAX_TABLERO && columna_l >= MIN_TABLERO && columna_l < MAX_TABLERO && tablero[fila_l][columna_l] != ROBOT)
                tablero[juego.robots[i].lasers[j].fila][juego.robots[i].lasers[j].columna] = LASER;
        }           
    }
}

