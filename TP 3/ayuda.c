#include "ayuda.h"
#include <stdio.h>

void ayuda(){
    printf("-------AYUDA--------\n\n");
    printf("Lista de comandos:\n");
    printf("(1) LISTAR: Te muestra la lista de superheroes\n");
    printf("Comando: ./ejecutable listar archivo.csv | EJEMPLO\n\n");
    printf("(2) CONTACTAR: Contactas a un superheroe mediante su ID\n");
    printf("Comando: ./ejecutable contactar ID archivo.csv | EJEMPLO\n\n");
    printf("(3) MODIFICAR: Modificar los valores de un superheroe desde su id(existente), cambiandole su edad u estado\n");
    printf("Comando: ./ejecutable modificar ID EDAD ESTADO archivo.csv | EJEMPLO\n\n");
    printf("(4) AGREGAR: Añadis un nuevo superheroe a la lista, la id no puede repetirse\n");
    printf("Comando: ./ejecutable agregar ID NOMBRE EDAD ESTADO archivo.csv | EJEMPLO\n\n");
    printf("(5) AYUDA: I need help!!\n");
    printf("Comando: ./ejecutable ayuda | EJEMPLO\n\n");
    printf("---------------------\n\n");
    printf("El archivo tiene que tener extension .csv\n");
    printf("ID: Numero entero positivo, la id es única\n");
    printf("NOMBRE: Como mucho 50 caracteres\n");
    printf("EDAD: Numero entre 1 y 100 (incluidos)\n");
    printf("ESTADO: Estado actual de superheroe. vivo o muerto\n\n");
    printf("----FIN DE AYUDA----\n");
}