#include "ejecutar_comando.h"
#include "listar.h"
#include "contactar.h"
#include "modificar.h"
#include "agregar.h"
#include "comandos.h"
#include <stdlib.h>

int activar_comando(char* argv[], FILE* superheroes, char ruta[MAX_RUTA]){

    int codigo = NO_HAY_ERROR;
    
    if(strcmp(argv[1],LISTAR) == 0){
        codigo = listar_superheroes(superheroes);
    }else if(strcmp(argv[1],AGREGAR) == 0){
        codigo = agregar_superheroes(superheroes, atoi(argv[2]), argv[3], atoi(argv[4]), argv[5], ruta);
    }else if(strcmp(argv[1],CONTACTAR) == 0){
        codigo = contactar_superheroes(superheroes, atoi(argv[2]), ruta);
    }else if(strcmp(argv[1],MODIFICAR) == 0){
        codigo = modificar_superheroes(superheroes, atoi(argv[2]), atoi(argv[3]), argv[4], ruta);
    }

    return codigo;
}