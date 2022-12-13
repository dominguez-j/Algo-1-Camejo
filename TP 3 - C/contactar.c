#include "contactar.h"
#include "verificar_id.h"

//PRE: -
//POS: Muestra el heroe con el que se contactó.
void mostrar_heroe_contactado(heroe_t heroe_contactado){

    char estado_completo[MAX_ESTADO];

    if(heroe_contactado.estado == VIVO){
        strcpy(estado_completo, "Vivo");
    }else{
        strcpy(estado_completo, "Muerto");
    }

    printf("Contactó con: \n");
    printf("ID: %i\n", heroe_contactado.id);
    printf("Nombre: %s\n", heroe_contactado.nombre);
    printf("Edad: %i\n", heroe_contactado.edad);
    printf("Estado: %s\n", estado_completo);
    printf("Se contactó con el superheroe con éxito\n");

}

//PRE: -
//POS: Elimina al heroe contactado del archivo. Y retorna 0 si no hubo error.
int eliminar_del_archivo(FILE* superheroes, heroe_t *heroe_contactado, char ruta[MAX_RUTA]){

    FILE* archivo_aux = fopen(RUTA_AUX, "w");

    if(archivo_aux == NULL){
        perror("Error al contactar al superheroe\n");
        return ERROR_CONTACTAR;
    }

    heroe_t heroe;
    
    int leido = leer_superheroe(superheroes, &heroe);

    while(leido != EOF){     
        if(heroe.id != heroe_contactado->id){
            escribir_superheroe(archivo_aux, heroe);
        }else{
            strcpy(heroe_contactado->nombre, heroe.nombre);
            heroe_contactado->edad = heroe.edad;
            heroe_contactado->estado = heroe.estado;
        } 
        leido = leer_superheroe(superheroes, &heroe);
    }

    rename(RUTA_AUX, ruta);
    fclose(archivo_aux);
    return NO_HAY_ERROR;
}

int contactar_superheroes(FILE* superheroes, int id, char ruta[MAX_RUTA]){

    if(!id_existente(superheroes, id, 2)) return ERROR_ID_EXISTENTE;

    rewind(superheroes);

    heroe_t heroe_contactado = {.id = id};

    int codigo = eliminar_del_archivo(superheroes, &heroe_contactado, ruta);

    if(codigo == ERROR_CONTACTAR) return codigo;

    mostrar_heroe_contactado(heroe_contactado);
    
    return codigo;
}