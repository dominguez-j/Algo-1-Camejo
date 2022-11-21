#include "verificar_id.h"

const int MODO_AGREGAR = 1;
const int MODO_CONTACTAR_MODIFICAR = 2;

bool id_existente(FILE* superheroes, int id, int modo){

    heroe_t heroe;
    bool existe = false;

    int leido = leer_superheroe(superheroes, &heroe);

    while(leido != EOF){
        if(heroe.id == id){
            existe = true;
            if(modo == MODO_AGREGAR){
                printf("La ID ingresada ya existe, pruebe el comando ayuda\n");
            }
        }
        leido = leer_superheroe(superheroes, &heroe);
    }

    if(existe == false && modo == MODO_CONTACTAR_MODIFICAR){
        printf("La ID ingresada no existe, pruebe el comando ayuda\n");
    }

    return existe;
}