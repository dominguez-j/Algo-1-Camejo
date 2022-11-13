#include "kronos.h"
#include "increidle.h"
#include "terreno.h"
#include "ingreso.h"
#include "inicializar.h"
#include <stdio.h>
#include <string.h>

const int ELASTIC_GIRL_ID = 1;
const int VIOLETA_ID = 2;
const int DASH_ID = 3;
const int MR_INCREIBLE_ID = 4;
const int LIMITE_CUADRANTE = 10;
const int GANA = 1;
const int PIERDE = -1;
const int SIGUE_JUGANDO = 0;
const int LONGITUD_MINIMA_LASER = 3;
const int LONGITUD_MAXIMA_LASER = 5;

void inicializar_juego(juego_t* juego, bool contrasenia_completa){
    srand ((unsigned)time(NULL));
    char tablero[MAX_FILAS][MAX_COLUMNAS];
    llenar_terreno(tablero);
    poner_salida(tablero);

    if(contrasenia_completa)
        juego->longitud_laser = LONGITUD_MINIMA_LASER;
    else
        juego->longitud_laser = LONGITUD_MAXIMA_LASER;

    juego->id_personaje_actual = ELASTIC_GIRL_ID;

    inicializar_robots(juego->robots, tablero);
    juego->tope_robots = TOPE_ROBOTS;
    inicializar_lasers(juego->robots, juego->longitud_laser, tablero); 
    inicializar_pinzas(juego->pinzas, tablero);
    juego->tope_pinzas = TOPE_PINZAS;
    inicializar_supertrajes(juego->supertrajes, tablero);
    juego->tope_supertraje = TOPE_SUPERTRAJE;
    inicializar_personajes(juego->personajes, tablero);
    juego->tope_personajes = TOPE_PERSONAJES;   
}

//PRE: -
//POS: Retorna true si se puede mover.
bool se_puede_mover(char movimiento, coordenada_t posicion){

    if((movimiento == ARRIBA && posicion.fila == MIN_TABLERO) || (movimiento == ABAJO && posicion.fila == MAX_TABLERO) || 
    (movimiento == IZQUIERDA && posicion.columna == MIN_TABLERO) || (movimiento == DERECHA && posicion.columna == MAX_TABLERO))
        return false;

    return true;
}

//PRE: -
//POS: Retorna true si puede activar el poder.
bool puede_activar_poder(personaje_t personaje, supertraje_t supertraje){
    if(!personaje.tiene_supertraje || personaje.poder_activado)
        return false;
    
    return true;
}

//PRE: id_o_cuadrante > 0.
//POS: Te la pasa a formato posición de vector.
int cambiar_a_posicion(int id_o_cuadrante){
    return id_o_cuadrante - 1;
}

//PRE: longitud_laser> 0.
//POS: Rota los lasers a 45° en sentido antihorario.
void rotar_lasers(robot_t robots[MAX_ROBOTS], int longitud_laser){
    int fila_robot, columna_robot, fila_laser, columna_laser; 
    int sig_pos = 1;

    for(int i = 0; i < TOPE_ROBOTS ; i++){
        for(int j =0; j < longitud_laser*2; j++){

            fila_robot = robots[i].posicion.fila;
            columna_robot = robots[i].posicion.columna;
            fila_laser = robots[i].lasers[j].fila;
            columna_laser = robots[i].lasers[j].columna;
            if(sig_pos > longitud_laser){
                sig_pos = 1;
            }
                
            if((fila_robot - sig_pos == fila_laser) && (columna_robot == columna_laser))
                robots[i].lasers[j].columna += sig_pos;
            else if((fila_robot- sig_pos == fila_laser) && (columna_robot + sig_pos == columna_laser))
                robots[i].lasers[j].fila += sig_pos;
            else if((fila_robot == fila_laser) && (columna_robot + sig_pos == columna_laser))
                robots[i].lasers[j].fila += sig_pos;
            else if((fila_robot + sig_pos == fila_laser) && (columna_robot + sig_pos == columna_laser))
                robots[i].lasers[j].columna -= sig_pos;
            else if((fila_robot + sig_pos == fila_laser) && (columna_robot == columna_laser))
                robots[i].lasers[j].columna -= sig_pos;
            else if((fila_robot + sig_pos == fila_laser) && (columna_robot - sig_pos == columna_laser))
                robots[i].lasers[j].fila -= sig_pos;
            else if((fila_robot == fila_laser) && (columna_robot - sig_pos == columna_laser))
                robots[i].lasers[j].fila -= sig_pos;
            else if((fila_robot - sig_pos == fila_laser) && (columna_robot - sig_pos == columna_laser))
                robots[i].lasers[j].columna += sig_pos;

            sig_pos++;
        }
    }
}

//PRE: desplazar > 0 y desplazar_poder >= 0
//POS: Modifica la posicion del Personaje
void moverse(char tecla, personaje_t* jugador, supertraje_t* supertraje, int desplazar, int desplazar_poder){
    if(tecla !=  ACTIVAR_PODER){     
        if(se_puede_mover(tecla, jugador->posicion)){
            if(tecla == ARRIBA)
            jugador->posicion.fila -= desplazar; 
        else if(tecla == ABAJO)
            jugador->posicion.fila += desplazar;
        else if(tecla == DERECHA)
            jugador->posicion.columna += desplazar;
        else if(tecla == IZQUIERDA)
            jugador->posicion.columna -= desplazar;
        }
        jugador->movimientos--;    
        jugador->movimientos_con_poder -= desplazar_poder;
    }else if(tecla == ACTIVAR_PODER){
        if(puede_activar_poder(*jugador, *supertraje)){
            jugador->poder_activado = true;
            supertraje->usado = true;
            jugador->tiene_supertraje = false;
            printf("Activaste el poder\n");
            if(jugador->cuadrante_inicial == DASH_ID){
                jugador->posicion.fila = posicion_random(10,0);
                jugador->posicion.columna = posicion_random(10,10);
                jugador->movimientos_con_poder = 0;
            }
        }   
    }

}

//PRE: id_actual >= 0.
//POS: Mueve al Personaje hasta donde puede.
void desplazamiento_poder(int* desplazar, char tecla, int id_actual, personaje_t jugador){
    if(jugador.poder_activado && jugador.movimientos_con_poder > 0 && id_actual == ELASTIC_GIRL_ID){
        (*desplazar) = 3;
        bool arriba = (tecla == ARRIBA);
        bool abajo = (tecla == ABAJO);
        bool derecha = (tecla ==  DERECHA);
        bool izquierda = (tecla == IZQUIERDA);  
        int fila = jugador.posicion.fila;
        int columna = jugador.posicion.columna;
        if((arriba && fila == 2)||(abajo && fila == 17)||(derecha && columna == 17)||(izquierda && columna == 2))    
            (*desplazar) = 2;
        else if((arriba && fila == 1)||(arriba && fila == 18)||(derecha && columna == 18)||(izquierda && columna == 1))
            (*desplazar) = 1;
    }    
}

//PRE: id_personaje >= 0
//POS: Mueve al personaje si pisó una pinza.
void pisar_pinza(char tablero[MAX_FILAS][MAX_COLUMNAS], coordenada_t* posicion_jugador, coordenada_t posicion_robot, bool increible_poder_activado){
    if(tablero[posicion_jugador->fila][posicion_jugador->columna] == PINZA){

        int nueva_f = posicion_robot.fila + posicion_random(3,-1);
        int nueva_c = posicion_robot.columna + posicion_random(3,-1);
        int fila_robot = posicion_robot.fila;
        int columna_robot = posicion_robot.columna;
        
    if(!increible_poder_activado){
            while(nueva_f < MIN_TABLERO || nueva_f > MAX_TABLERO || nueva_c < MIN_TABLERO || nueva_f >= MAX_TABLERO || (fila_robot == nueva_f && columna_robot == nueva_c)){
                nueva_f = posicion_robot.fila + posicion_random(3,-1);
                nueva_c = posicion_robot.columna + posicion_random(3,-1);
            }
            posicion_jugador->fila = nueva_f;
            posicion_jugador->columna = nueva_c;
        }      
    }
}

//PRE: -
//POS: Agarra el supertraje si corresponde.
void pisar_supertraje(char tablero[MAX_FILAS][MAX_COLUMNAS], personaje_t* jugador, supertraje_t* supertraje){
    if(tablero[jugador->posicion.fila][jugador->posicion.columna] == SUPERTRAJE){
        if(jugador->cuadrante_inicial == supertraje->cuadrante){
            supertraje->recolectado = true;
            jugador->tiene_supertraje = true;
        }
    }
}

//PRE:-
//POS: Cambia de personaje si corresponde.
void pisar_personaje(char tablero[MAX_FILAS][MAX_COLUMNAS], coordenada_t posicion_jugador, int* id_actual){
    if(tablero[posicion_jugador.fila][posicion_jugador.columna] == VIOLETA){
        if(*id_actual == ELASTIC_GIRL_ID)
            *id_actual = VIOLETA_ID;
            
    }else if(tablero[posicion_jugador.fila][posicion_jugador.columna] == DASH){
        if(*id_actual == VIOLETA_ID)
            *id_actual = DASH_ID;
            
    }else if(tablero[posicion_jugador.fila][posicion_jugador.columna] == MR_INCREIBLE){
        if(*id_actual == DASH_ID)
            *id_actual = MR_INCREIBLE_ID;       
    }
    
}

//PRE: -
//POS: Movimientos del jugador = 0, pisa un laser o un robot.
void pisar_laser_o_robot(char tablero[MAX_FILAS][MAX_COLUMNAS], personaje_t* jugador, bool violeta_poder_activado){
    if(tablero[jugador->posicion.fila][jugador->posicion.columna] == LASER || tablero[jugador->posicion.fila][jugador->posicion.columna] == ROBOT){
        if(!violeta_poder_activado)
            jugador->movimientos = 0;
    }
}

void realizar_jugada(juego_t* juego, char tecla){   
    char tablero[MAX_FILAS][MAX_COLUMNAS];
    modificar_terreno(*juego, tablero);

    int id_personaje = cambiar_a_posicion(juego->id_personaje_actual);
    personaje_t* jugador = &juego->personajes[id_personaje];
    supertraje_t* supertraje = &juego->supertrajes[id_personaje];
    int desplazar = 1;
    int desplazar_poder = 0;

    desplazamiento_poder(&desplazar, tecla, juego->id_personaje_actual, *jugador);
    
    if(jugador->poder_activado && jugador->movimientos_con_poder > 0)
        desplazar_poder = 1;

    moverse(tecla, jugador, supertraje, desplazar, desplazar_poder);
    
    if(jugador->movimientos_con_poder == 0)
        jugador->poder_activado = false;

    int cuadrante_actual = 5;

    if(jugador->posicion.fila < LIMITE_CUADRANTE && jugador->posicion.columna < LIMITE_CUADRANTE)   
        cuadrante_actual = CUADRANTE_1;
    else if (jugador->posicion.fila >= LIMITE_CUADRANTE && jugador->posicion.columna >= LIMITE_CUADRANTE) 
        cuadrante_actual = CUADRANTE_2;
    else if (jugador->posicion.fila >= LIMITE_CUADRANTE && jugador->posicion.columna < LIMITE_CUADRANTE) 
        cuadrante_actual = CUADRANTE_3;
    else if (jugador->posicion.fila < LIMITE_CUADRANTE && jugador->posicion.columna >= LIMITE_CUADRANTE) 
        cuadrante_actual = CUADRANTE_4;

    bool increible_poder_activado = juego->personajes[cambiar_a_posicion(MR_INCREIBLE_ID)].poder_activado;
    pisar_pinza(tablero, &jugador->posicion, juego->robots[id_personaje].posicion, increible_poder_activado);

    supertraje = &juego->supertrajes[cambiar_a_posicion(cuadrante_actual)];
    pisar_supertraje(tablero, jugador, supertraje); 

    pisar_personaje(tablero, jugador->posicion, &juego->id_personaje_actual);

    rotar_lasers(juego->robots, juego->longitud_laser);
    modificar_terreno(*juego, tablero);

    bool violeta_poder_activado = juego->personajes[cambiar_a_posicion(VIOLETA_ID)].poder_activado;
    pisar_laser_o_robot(tablero, jugador, violeta_poder_activado);
    
}

//PRE: -
//POS: Muestra la cantidad de movimientos restantes.
void imprimir_movimientos_restantes(juego_t juego){
    int cant_mov_jugador = juego.personajes[cambiar_a_posicion(juego.id_personaje_actual)].movimientos;
    int cant_mov_poder_jugador = juego.personajes[cambiar_a_posicion(juego.id_personaje_actual)].movimientos_con_poder;

    printf("Cantidad de movimientos restantes de ese personaje: %i\n", cant_mov_jugador);
    printf("Cantidad de movimientos del poder restantes de ese personaje: %i\n", cant_mov_poder_jugador);
}

void imprimir_terreno(juego_t juego){
    char tablero[MAX_FILAS][MAX_COLUMNAS];
    modificar_terreno(juego, tablero);

    for(int i = 0; i < MAX_FILAS; i++){            
        for(int j = 0; j < MAX_COLUMNAS; j++){      
            printf("%c ", tablero[i][j]);
            if(j == 9)
                printf("| ");                        
        }
        if(i == 9){
            printf("\n");
            for(int j = 0; j < MAX_COLUMNAS + 1; j++)   
                printf("- "); 
        } 
        printf("\n");
    }

    imprimir_movimientos_restantes(juego);
}

int estado_juego(juego_t juego){

    int cant_movimientos_jugador = juego.personajes[cambiar_a_posicion(juego.id_personaje_actual)].movimientos;
    int fila_jugador = juego.personajes[cambiar_a_posicion(juego.id_personaje_actual)].posicion.fila;
    int columna_jugador = juego.personajes[cambiar_a_posicion(juego.id_personaje_actual)].posicion.columna;
    int estado_del_juego = SIGUE_JUGANDO;       

    if(fila_jugador == SALIDA_FILA && columna_jugador == SALIDA_COLUMNA && juego.id_personaje_actual == MR_INCREIBLE_ID)
        estado_del_juego = GANA;
    else if(cant_movimientos_jugador == 0)
        estado_del_juego = PIERDE;

    return estado_del_juego;
}