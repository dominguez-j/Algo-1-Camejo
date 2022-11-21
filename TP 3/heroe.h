#ifndef __HEROE_H__
#define __HEROE_H__

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "codigo_error.h"

#define MAX_NOMBRE 50   
#define MAX_ESTADO 10
#define VIVO 'V'
#define MUERTO 'M'
#define VIVO_COMPLETO "vivo"
#define MUERTO_COMPLETO "muerto"
#define MAX_RUTA 100
#define RUTA_AUX "./archivo_aux.csv"
#define LECTURA "%i;%[^;];%i;%c\n"
#define ESCRITURA "%i;%s;%i;%c\n"

typedef struct heroe{
    int id;
    char nombre[MAX_NOMBRE];
    int edad;
    char estado;
} heroe_t;

//PRE: -
//POS: Escribe el heroe ingresado en el archivo.
int escribir_superheroe(FILE* archivo_aux, heroe_t heroe);

//PRE: -
//POS: Toma los valores de la linea del archivo y los guarda en heroe.
int leer_superheroe(FILE* superheroes, heroe_t* heroe);

#endif /*__HEROE_H__*/