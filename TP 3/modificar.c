#include "modificar.h"
#include "verificar_id.h"

//PRE: -
//POS: Muestra el heroe modificado.
void mostrar_heroe_modificado(heroe_t heroe_modificado){
    char estado_completo[MAX_ESTADO];

    if(heroe_modificado.estado == VIVO){
        strcpy(estado_completo, "Vivo");
    }else{
        strcpy(estado_completo, "Muerto");
    }

    printf("Modificó a: \n");
    printf("ID: %i\n", heroe_modificado.id);
    printf("Nombre: %s\n", heroe_modificado.nombre);
    printf("Edad: %i\n", heroe_modificado.edad);
    printf("Estado: %s\n", estado_completo);
    printf("Se modificó al superheroe con éxito\n");
}

//PRE: -
//POS: Modifica la linea del heroe ingresado.
int modificar_linea_del_archivo(FILE* superheroes, heroe_t heroe_modificado, char ruta[MAX_RUTA]){

    FILE* archivo_aux = fopen(RUTA_AUX, "w");

    if(archivo_aux == NULL){
        perror("Error al modificar al superheroe\n");
        return ERROR_MODIFICAR;
    }

    heroe_t heroe;

    int leido = leer_superheroe(superheroes, &heroe);

    while(leido != EOF){   
        if(heroe.id != heroe_modificado.id){
            escribir_superheroe(archivo_aux, heroe);
        }else{
            strcpy(heroe_modificado.nombre, heroe.nombre);
            escribir_superheroe(archivo_aux, heroe_modificado);
        }
        leido = leer_superheroe(superheroes, &heroe);
    }
    
    mostrar_heroe_modificado(heroe_modificado);
    
    rename(RUTA_AUX, ruta);
    fclose(archivo_aux);
    return NO_HAY_ERROR;
}

int modificar_superheroes(FILE* superheroes, int id, int edad, char estado[MAX_ESTADO], char ruta[MAX_RUTA]){

    if(!id_existente(superheroes, id, 2)) return ERROR_ID_EXISTENTE;

    rewind(superheroes);

    heroe_t heroe_modificado = {.id = id, .edad = edad};

    if(strcmp(estado,VIVO_COMPLETO) == 0){
        heroe_modificado.estado = VIVO;
    }else if(strcmp(estado,MUERTO_COMPLETO) == 0){
        heroe_modificado.estado = MUERTO;
    }

    int codigo = modificar_linea_del_archivo(superheroes, heroe_modificado, ruta);
    
    return codigo;
}