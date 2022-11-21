#include "heroe.h"

int escribir_superheroe(FILE* archivo_aux, heroe_t heroe){
    return fprintf(archivo_aux, ESCRITURA, heroe.id, heroe.nombre, heroe.edad, heroe.estado);
}

int leer_superheroe(FILE* superheroes, heroe_t* heroe){
    return fscanf(superheroes, LECTURA, &(heroe->id), heroe->nombre, &(heroe->edad), &(heroe->estado));
}