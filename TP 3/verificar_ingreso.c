#include "verificar_ingreso.h"
#include "heroe.h"
#include "comandos.h"
#include <stdlib.h>

#define MAX_COMANDO 15

const int ARGS_LISTAR = 3;
const int ARGS_CONTACTAR = 4;
const int ARGS_MODIFICAR = 6;
const int ARGS_AGREGAR = 7;
const int ARGS_AYUDA = 2;
const int EDAD_MINIMA = 1;
const int EDAD_MAXIMA = 100;
const int ID_MINIMA = 1;

//PRE: -
//POS: Retorna true si es la edad esta entre 1 y 100.
bool edad_valida(int edad){
    bool valido = true;
    if(edad < EDAD_MINIMA || edad > EDAD_MAXIMA){
        printf("La edad ingresada es inválida, pruebe el comando ayuda\n");
        valido = false;
    }
    return valido;
}

//PRE: -
//POS: Retorna true si el nombre es menor a 50 caracteres.
bool nombre_valido(char nombre[MAX_NOMBRE]){
    bool valido = true;
    if(strlen(nombre) > MAX_NOMBRE){
        printf("El nombre ingresado es muy largo, pruebe el comando ayuda\n");
        valido = false;
    }
    return valido;
}

//PRE: -
//POS: Retorna true si el estado es vivo o muerto.
bool estado_valido(char estado[MAX_ESTADO]){
    bool valido = true;
    if((strcmp(estado,VIVO_COMPLETO)!=0) && strcmp(estado,MUERTO_COMPLETO)!=0){
        printf("El estado ingresado es erróneo, pruebe el comando ayuda\n");
        valido = false;
    }
    return valido;
}

//PRE: -
//POS: Retorna true si la id es un entero positivo.
bool id_valido(int id){
    bool valido = true;
    if(id < ID_MINIMA){
        printf("La ID ingresada es errónea, pruebe el comando ayuda\n");
        valido = false;
    }
    return valido;
}

//PRE: -
//POS: Devuelve true si son una cantidad correcta de argumentos.
bool cant_argumentos_valida(int cant_args){
    bool valido = true;
    if(cant_args != ARGS_LISTAR && cant_args != ARGS_CONTACTAR && cant_args != ARGS_MODIFICAR &&
     cant_args != ARGS_AGREGAR && cant_args != ARGS_AYUDA){
        printf("La cantidad de argumentos ingresada es inválida, pruebe el comando ayuda\n");
        valido = false;
    }
    return valido;
}

//PRE: -
//POS: Devuelve true si es un comando existente.
bool comando_valido(char comando[MAX_COMANDO]){
    bool valido = true;
    if((strcmp(comando,LISTAR) != 0) && (strcmp(comando,AGREGAR) != 0) && (strcmp(comando,CONTACTAR) != 0) && 
    strcmp(comando,MODIFICAR) != 0 && (strcmp(comando,AYUDA) != 0)){
        printf("Nombre del comando inválido, pruebe el comando ayuda\n");
        valido = false;
    }
    return valido;
}

//PRE: -
//POS: Devuelve true si el archivo tiene extension .csv.
bool ruta_valida(char ruta[MAX_RUTA]){
    bool valido = true;
    if(strstr(ruta,".csv") == NULL){
        printf("La ruta ingresada no contiene la extension .csv, pruebe el comando ayuda\n");
        valido = false;
    }
    return valido;
}

int ingresos_validos(int argc, char* argv[]){

    int codigo = ERROR_INGRESO_INVALIDO;

    char comando[MAX_COMANDO];
    strcpy(comando, argv[1]);

    if((strcmp(comando,AYUDA) == 0) && argc == ARGS_AYUDA){
        return NUMERO_AYUDA;
    }

    if(comando_valido(comando) && cant_argumentos_valida(argc) && ruta_valida(argv[argc -1])){
        
        if((strcmp(comando,LISTAR) == 0) && argc == ARGS_LISTAR){
            codigo = NO_HAY_ERROR;
        }
        else if((strcmp(comando,AGREGAR) == 0) && argc == ARGS_AGREGAR && id_valido(atoi(argv[2])) &&
        nombre_valido(argv[3]) && edad_valida(atoi(argv[4])) && estado_valido(argv[5])){
                codigo = NO_HAY_ERROR;
        }
        else if((strcmp(comando,MODIFICAR) == 0) && argc == ARGS_MODIFICAR && id_valido(atoi(argv[2])) &&
         edad_valida(atoi(argv[3])) && estado_valido(argv[4])){
                codigo = NO_HAY_ERROR;
        }
        else if((strcmp(comando,CONTACTAR) == 0) && argc == ARGS_CONTACTAR && id_valido(atoi(argv[2]))){
                codigo = NO_HAY_ERROR;
        } 
    }

    return codigo;
}
