#include "inicializar.h"

int posicion_random(int rango, int desplazamiento){
    return rand() % rango + desplazamiento;
}

void inicializar_personajes(personaje_t personajes[MAX_PERSONAJES], char tablero[MAX_FILAS][MAX_COLUMNAS]){

    personajes[0].cuadrante_inicial = CUADRANTE_1;
    personajes[0].movimientos = 25;
    personajes[0].movimientos_con_poder = 5;
    personajes[0].posicion.fila = posicion_random(10,0);
    personajes[0].posicion.columna = posicion_random(10,0);
    while(tablero[personajes[0].posicion.fila][personajes[0].posicion.columna] != ESPACIO_VACIO){
        personajes[0].posicion.fila = posicion_random(10,0);
        personajes[0].posicion.columna = posicion_random(10,0);   
    }   
    tablero[personajes[0].posicion.fila][personajes[0].posicion.columna] = ELASTIC_GIRL;

    personajes[1].cuadrante_inicial = CUADRANTE_2;
    personajes[1].movimientos = 30;
    personajes[1].movimientos_con_poder = 5;
    personajes[1].posicion.fila = posicion_random(10,10);
    personajes[1].posicion.columna = posicion_random(10,10);
    while(tablero[personajes[1].posicion.fila][personajes[1].posicion.columna] != ESPACIO_VACIO){
        personajes[1].posicion.fila = posicion_random(10,10);
        personajes[1].posicion.columna = posicion_random(10,10);   
    }   
    tablero[personajes[1].posicion.fila][personajes[1].posicion.columna] = VIOLETA;

    personajes[2].cuadrante_inicial = CUADRANTE_3;
    personajes[2].movimientos = 20;
    personajes[2].movimientos_con_poder = 1;
    personajes[2].posicion.fila = posicion_random(10,10);
    personajes[2].posicion.columna = posicion_random(10,0);
    while(tablero[personajes[2].posicion.fila][personajes[2].posicion.columna] != ESPACIO_VACIO){
        personajes[2].posicion.fila = posicion_random(10,10);
        personajes[2].posicion.columna = posicion_random(10,0);   
    }   
    tablero[personajes[2].posicion.fila][personajes[2].posicion.columna] = DASH;

    personajes[3].cuadrante_inicial = CUADRANTE_4;
    personajes[3].movimientos = 15;
    personajes[3].movimientos_con_poder = 5;
    personajes[3].posicion.fila = posicion_random(10,0);
    personajes[3].posicion.columna = posicion_random(10,10);
    while(tablero[personajes[3].posicion.fila][personajes[3].posicion.columna] != ESPACIO_VACIO){
        personajes[3].posicion.fila = posicion_random(10,0);
        personajes[3].posicion.columna = posicion_random(10,10);   
    }   
    tablero[personajes[3].posicion.fila][personajes[3].posicion.columna] = MR_INCREIBLE;  
}

void inicializar_supertrajes(supertraje_t supertrajes[MAX_SUPERTRAJES], char tablero[MAX_FILAS][MAX_COLUMNAS]){

    supertrajes[0].cuadrante = CUADRANTE_1;
    supertrajes[0].posicion.fila = posicion_random(10,0);
    supertrajes[0].posicion.columna = posicion_random(10,0);
    while(tablero[supertrajes[0].posicion.fila][supertrajes[0].posicion.columna] != ESPACIO_VACIO){
        supertrajes[0].posicion.fila = posicion_random(10,0);
        supertrajes[0].posicion.columna = posicion_random(10,0);
    }

    supertrajes[1].cuadrante = CUADRANTE_2;
    supertrajes[1].posicion.fila = posicion_random(10,10);
    supertrajes[1].posicion.columna = posicion_random(10,10);
    while(tablero[supertrajes[1].posicion.fila][supertrajes[1].posicion.columna] != ESPACIO_VACIO){
        supertrajes[1].posicion.fila = posicion_random(10,10);
        supertrajes[1].posicion.columna = posicion_random(10,10);
    }

    supertrajes[2].cuadrante = CUADRANTE_3;
    supertrajes[2].posicion.fila = posicion_random(10,10);
    supertrajes[2].posicion.columna = posicion_random(10,0);
    while(tablero[supertrajes[2].posicion.fila][supertrajes[2].posicion.columna] != ESPACIO_VACIO){
        supertrajes[2].posicion.fila = posicion_random(10,10);
        supertrajes[2].posicion.columna = posicion_random(10,0);
    }

    supertrajes[3].cuadrante = CUADRANTE_4;
    supertrajes[3].posicion.fila = posicion_random(10,0);
    supertrajes[3].posicion.columna = posicion_random(10,10);
    while(tablero[supertrajes[3].posicion.fila][supertrajes[3].posicion.columna] != ESPACIO_VACIO){
        supertrajes[3].posicion.fila = posicion_random(10,0);
        supertrajes[3].posicion.columna = posicion_random(10,10);
    }

    for(int i = 0; i < TOPE_SUPERTRAJE; i++)
        tablero[supertrajes[i].posicion.fila][supertrajes[i].posicion.columna] = SUPERTRAJE;
}

void inicializar_pinzas(coordenada_t pinzas[MAX_PINZAS], char tablero[MAX_FILAS][MAX_COLUMNAS]){

    for(int i = 0; i < TOPE_PINZAS; i++){
        if(i < TOPE_PINZAS_POR_CUADRANTE){
            pinzas[i].fila = posicion_random(10,0);
            pinzas[i].columna = posicion_random(10,0);
            while(tablero[pinzas[i].fila][pinzas[i].columna] != ESPACIO_VACIO){
                pinzas[i].fila = posicion_random(10,0);
                pinzas[i].columna = posicion_random(10,0);      
            }
        }else if(i < TOPE_PINZAS_POR_CUADRANTE * 2){
            pinzas[i].fila = posicion_random(10,10);
            pinzas[i].columna = posicion_random(10,10);
            while(tablero[pinzas[i].fila][pinzas[i].columna] != ESPACIO_VACIO){
                pinzas[i].fila = posicion_random(10,10);
                pinzas[i].columna = posicion_random(10,10);
            }
        }else if(i < TOPE_PINZAS_POR_CUADRANTE * 3){
            pinzas[i].fila = posicion_random(10,10);
            pinzas[i].columna = posicion_random(10,0);
            while(tablero[pinzas[i].fila][pinzas[i].columna] != ESPACIO_VACIO){
                pinzas[i].fila = posicion_random(10,10);
                pinzas[i].columna = posicion_random(10,0);      
            }
        }else if(i < TOPE_PINZAS_POR_CUADRANTE * 4){
            pinzas[i].fila = posicion_random(10,0);
            pinzas[i].columna = posicion_random(10,10);
            while(tablero[pinzas[i].fila][pinzas[i].columna] != ESPACIO_VACIO){
                pinzas[i].fila = posicion_random(10,0);
                pinzas[i].columna = posicion_random(10,10);      
            }
        }
        tablero[pinzas[i].fila][pinzas[i].columna] = PINZA;
    }
}

void inicializar_lasers(robot_t robots[MAX_ROBOTS], int longitud_laser, char tablero[MAX_FILAS][MAX_COLUMNAS]){
    int pos_random;
    int sig_pos = 1;

    for(int i = 0; i < TOPE_ROBOTS; i++)
        robots[i].tope_lasers = longitud_laser * 2;
    
    for(int i = 0; i < TOPE_ROBOTS; i++){
        pos_random = posicion_random(4,0);
        for(int j = 0; j < longitud_laser *2; j++){
            if(sig_pos > longitud_laser)
                sig_pos = 1;
                
            if(pos_random == 0){
                if(j < longitud_laser){
                    robots[i].lasers[j].fila = robots[i].posicion.fila - sig_pos;
                    robots[i].lasers[j].columna = robots[i].posicion.columna;
                    
                }else{
                    robots[i].lasers[j].fila = robots[i].posicion.fila;
                    robots[i].lasers[j].columna = robots[i].posicion.columna + sig_pos;
                }
            }else if(pos_random == 1){
                if(j < longitud_laser){
                    robots[i].lasers[j].fila = robots[i].posicion.fila;
                    robots[i].lasers[j].columna = robots[i].posicion.columna + sig_pos;
                    
                }else{
                    robots[i].lasers[j].fila = robots[i].posicion.fila + sig_pos;
                    robots[i].lasers[j].columna = robots[i].posicion.columna;
                }
            }else if(pos_random == 2){
                if(j < longitud_laser){
                    robots[i].lasers[j].fila = robots[i].posicion.fila + sig_pos;
                    robots[i].lasers[j].columna = robots[i].posicion.columna;
                    
                }else{           
                    robots[i].lasers[j].fila = robots[i].posicion.fila;
                    robots[i].lasers[j].columna = robots[i].posicion.columna - sig_pos;
                }
            }else if(pos_random == 3){
                if(j < longitud_laser){
                    robots[i].lasers[j].fila = robots[i].posicion.fila;
                    robots[i].lasers[j].columna = robots[i].posicion.columna - sig_pos;
                    
                }else{
                    robots[i].lasers[j].fila = robots[i].posicion.fila - sig_pos;
                    robots[i].lasers[j].columna = robots[i].posicion.columna;
                }
            }
            sig_pos++;
        }      
    }  
}

void inicializar_robots(robot_t robots[MAX_ROBOTS], char tablero[MAX_FILAS][MAX_COLUMNAS]){

    robots[0].posicion.fila = posicion_random(10,0);
    robots[0].posicion.columna = posicion_random(10,0);

    robots[1].posicion.fila = posicion_random(10,10);
    robots[1].posicion.columna = posicion_random(10,10);

    robots[2].posicion.fila = posicion_random(10,10);
    robots[2].posicion.columna = posicion_random(10,0);

    robots[3].posicion.fila = posicion_random(10,0);
    robots[3].posicion.columna = posicion_random(10,10);
    
    while(tablero[robots[3].posicion.fila][robots[3].posicion.columna] == SALIDA){
        robots[3].posicion.fila = posicion_random(10,0);
        robots[3].posicion.columna = posicion_random(10,10);
    }

    for(int i = 0; i < TOPE_ROBOTS; i++)
        tablero[robots[i].posicion.fila][robots[i].posicion.columna] = ROBOT;
}
