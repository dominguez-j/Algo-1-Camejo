#include "listar.h"

int listar_superheroes(FILE* superheroes){

    heroe_t heroe;
    
    int leido = leer_superheroe(superheroes, &heroe);

    if(leido == EOF){
        printf("El archivo esta vacío no hay nada para mostrar\n");
        return ERROR_LISTAR;
    }

    char estado_completo[MAX_ESTADO];

    printf("------------------------------------------\n");
    while(leido != EOF){
     
        if(heroe.estado == VIVO){
            strcpy(estado_completo, VIVO_COMPLETO);
        }else{
            strcpy(estado_completo, MUERTO_COMPLETO);
        }

        printf("ID: %i - Nombre: %s - Edad: %i - Estado: %s\n", heroe.id, heroe.nombre, heroe.edad, estado_completo);
        printf("------------------------------------------\n");

        leido = leer_superheroe(superheroes, &heroe);
    }
    
    return NO_HAY_ERROR;
}