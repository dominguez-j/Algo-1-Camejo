#include "agregar.h"
#include "verificar_id.h"

//PRE: -
//POS: Agrega el heroe ingresado al archivo.
int agregar_al_archivo(FILE* superheroes, heroe_t heroe_a_agregar, char ruta[MAX_RUTA]){

    FILE* archivo_aux = fopen(RUTA_AUX, "w");

    if(archivo_aux == NULL){
        perror("Error al agregar al superheroe\n");
        return ERROR_AGREGAR;
    }

    heroe_t heroe;

    int leido = leer_superheroe(superheroes, &heroe);

    while(leido != EOF && heroe.id < heroe_a_agregar.id){
        escribir_superheroe(archivo_aux, heroe);
        leido = leer_superheroe(superheroes, &heroe);   
    }
    
    escribir_superheroe(archivo_aux, heroe_a_agregar);
    
    while(leido != EOF){
        escribir_superheroe(archivo_aux, heroe);
        leido = leer_superheroe(superheroes, &heroe);  
    }

    printf("Se agregó al superheroe con éxito\n");

    rename(RUTA_AUX, ruta);
    fclose(archivo_aux);
    return NO_HAY_ERROR;
}

int agregar_superheroes(FILE* superheroes, int id, char nombre[MAX_NOMBRE], int edad, char estado[MAX_ESTADO], char ruta[MAX_RUTA]){

    if(id_existente(superheroes, id, 1)) return ERROR_ID_EXISTENTE;

    rewind(superheroes);

    heroe_t heroe_a_agregar = {.id = id, .edad = edad};
    
    if(strcmp(estado,VIVO_COMPLETO) == 0){
        heroe_a_agregar.estado = VIVO;
    }else if(strcmp(estado,MUERTO_COMPLETO) == 0){
        heroe_a_agregar.estado = MUERTO;
    }

    strcpy(heroe_a_agregar.nombre, nombre);

    int codigo = agregar_al_archivo(superheroes, heroe_a_agregar, ruta);
    
    return codigo;
}