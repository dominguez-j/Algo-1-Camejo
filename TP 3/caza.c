#include "verificar_ingreso.h"
#include "ejecutar_comando.h"
#include "heroe.h"
#include "ayuda.h"

int main(int argc, char* argv[]){   

    int codigo = ingresos_validos(argc, argv);

    if(codigo < NO_HAY_ERROR) return codigo;

    if(codigo == NUMERO_AYUDA){
        ayuda();
        return codigo;
    }

    char ruta[MAX_RUTA];  
    strcpy(ruta, argv[argc -1]);

    FILE* superheroes = fopen(ruta, "r");

    if(superheroes == NULL){

        superheroes = fopen(ruta, "w");

        if(superheroes == NULL){
            perror("Error al abrir el archivo\n");
            return ERROR_ABRIR_ARCHIVO;
        }
    }

    codigo = activar_comando(argv, superheroes, ruta);
        
    fclose(superheroes);
    return codigo;
}