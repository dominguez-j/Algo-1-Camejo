#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "increidle.h"

const char OPCION_A = 'A';
const char OPCION_B = 'B';
const char OPCION_C = 'C';
const char OPCION_D = 'D';  
const char OCULTO = 'X';
const char PRIMERA_LETRA = 'K';
const char SEGUNDA_LETRA = 'R';
const char TERCERA_LETRA = 'O';
const char CUARTA_LETRA = 'N';
const char QUINTA_LETRA = 'O';
const char SEXTA_LETRA = 'S';
const int NUMERO_MCQUEEN = 95;
const int VALOR_MIN_VALIDO= 1;
const int VALOR_MAX_VALIDO= 100;
const int TOPE_PRIMOS = 5;
const int TOPE_CONTRASENIA = 6;
const int PRIMOS_DIVISORES = 10;
#define MAX_NUM 20
#define POSICION_1 0
#define POSICION_2 1
#define POSICION_3 2
#define POSICION_4 3
#define POSICION_5 4
#define POSICION_6 5

//PRE: -
//POS: Inicializo el vector Contrasenia en 'X';
void inicializar_contrasenia(char contrasenia_adivinada[MAX_CONTRASENIA]){
    for(int i = 0; i < TOPE_CONTRASENIA; i++)
        contrasenia_adivinada[i] = OCULTO;
}

//PRE: El vector numeros_primos tiene que estar inicializado.
//POS: Te muestra true si todos los numeros son primos o false en caso de que alguno no lo sea.
bool es_primo(int numeros_primos[MAX_NUM]){

    int cont_primos = 0;
    bool uno = false;

    for(int i = 0; i < TOPE_PRIMOS; i++){

        if(numeros_primos[i] == 1)
            uno = true;

        for(int j = 1; j <= numeros_primos[i]; j++){

            if(numeros_primos[i]%j == 0)
                cont_primos++;
        }
    }

    if(uno)
        return false;

    return (cont_primos == PRIMOS_DIVISORES);
}

//PRE: -
//POS: Te reemplaza la letra correspondiente en la posicion del vector. 
void corregir_respuesta_pregunta_1(char contrasenia_adivinada[MAX_CONTRASENIA], char opcion){

    if(opcion == OPCION_A)
        contrasenia_adivinada[POSICION_1] = PRIMERA_LETRA;
}

//PRE: -
//POS: Te reemplaza la letra correspondiente en la posicion del vector.
void corregir_respuesta_pregunta_2(char contrasenia_adivinada[MAX_CONTRASENIA], char opcion){

    if(opcion == OPCION_C)
        contrasenia_adivinada[POSICION_2] = SEGUNDA_LETRA;
}

//PRE: -
//POS: Te reemplaza la letra correspondiente en la posicion del vector.
void corregir_respuesta_pregunta_3(char contrasenia_adivinada[MAX_CONTRASENIA], bool todos_primos){

    if(todos_primos){
        contrasenia_adivinada[POSICION_3] = TERCERA_LETRA;
        contrasenia_adivinada[POSICION_5] = QUINTA_LETRA;
    }
}

//PRE: -
//POS: Te reemplaza la letra correspondiente en la posicion del vector.
void corregir_respuesta_pregunta_4(char contrasenia_adivinada[MAX_CONTRASENIA], int numero_mcqueen){

    if(numero_mcqueen == NUMERO_MCQUEEN)
        contrasenia_adivinada[POSICION_4] = CUARTA_LETRA;
}

//PRE: -
//POS: Te reemplaza la letra correspondiente en la posicion del vector.
void corregir_respuesta_pregunta_5(char contrasenia_adivinada[MAX_CONTRASENIA], char opcion){

    if(opcion == OPCION_C)
        contrasenia_adivinada[POSICION_6] = SEXTA_LETRA;
}

//PRE: -
//POS: Te pide que ingreses de vuelta en caso de que el ingreso sea erróneo.
void verificar_ingreso_multiple_choice(char* opcion){

    while((*opcion != OPCION_A) && (*opcion != OPCION_B) && (*opcion != OPCION_C) && (*opcion != OPCION_D)){
        printf("Por favor ingrese bien su respuesta en mayúsculas: ");
        scanf(" %c", opcion);
    }
}

//PRE: -
//POS: Te pide que ingreses de vuelta en caso de que el ingreso sea erróneo.
void verificar_ingreso_numero(int* numero){

    while((*numero < VALOR_MIN_VALIDO) || (*numero > VALOR_MAX_VALIDO)){
        printf("Por favor, ingrese un número válido entre 1 y 100: ");
        scanf("%i", numero);
    }
}

//PRE: El vector contrasenia_adivinada tiene que estar inicializado.
//POS: Si la respuesta es correcta, te muestra su carácter. Sino, te muestra 'X'. 
void hacer_pregunta_1(char contrasenia_adivinada[MAX_CONTRASENIA]){

    char opcion;
    printf("¿Cual es el código de emergencia utilizado en Monster Inc. cuando uno de los personajes tiene una media humana pegada a su cuerpo?\n");
    printf("A) 3312\n");
    printf("B) 3317\n");
    printf("C) 2312\n");
    printf("D) 2031\n");
    printf("Respuesta: ");
    scanf(" %c", &opcion);

    verificar_ingreso_multiple_choice(&opcion);
    corregir_respuesta_pregunta_1(contrasenia_adivinada, opcion);
}

//PRE: El vector contrasenia_adivinada tiene que estar inicializado.
//POS: Si la respuesta es correcta, te muestra su carácter. Sino, te muestra 'X'. 
void hacer_pregunta_2(char contrasenia_adivinada[MAX_CONTRASENIA]){

    char opcion;
    printf("¿Cuál era el nombre del pez mascota de Lilo?\n");
    printf("A) Stitch\n");
    printf("B) Pez\n");
    printf("C) Pato\n");
    printf("D) Aurelio\n");
    printf("Respuesta: ");
    scanf(" %c", &opcion);

    verificar_ingreso_multiple_choice(&opcion);
    corregir_respuesta_pregunta_2(contrasenia_adivinada, opcion);
}

//PRE: El vector contrasenia_adivinada tiene que estar inicializado.
//POS: Si la respuesta es correcta, te muestra su carácter. Sino, te muestra 'X'. 
void hacer_pregunta_3(char contrasenia_adivinada[MAX_CONTRASENIA]){

    int numeros_primos[MAX_NUM];

    printf("Ingrese 5 números primos\n");
    for(int i = 0; i < TOPE_PRIMOS; i++){
        printf("Ingrese su %i número: ", i+1);
        scanf("%i", &numeros_primos[i]);

        verificar_ingreso_numero(&numeros_primos[i]);
    }  
    corregir_respuesta_pregunta_3(contrasenia_adivinada, es_primo(numeros_primos));
}

//PRE: El vector contrasenia_adivinada tiene que estar inicializado.
//POS: Si la respuesta es correcta, te muestra su carácter. Sino, te muestra 'X'. 
void hacer_pregunta_4(char contrasenia_adivinada[MAX_CONTRASENIA]){

    int numero_mcqueen;
    printf("¿Qué número lleva el Rayo McQueen?\n");
    printf("Respuesta: ");
    scanf("%i", &numero_mcqueen);

    verificar_ingreso_numero(&numero_mcqueen);
    corregir_respuesta_pregunta_4(contrasenia_adivinada, numero_mcqueen); 
}

//PRE: El vector contrasenia_adivinada tiene que estar inicializado.
//POS: Si la respuesta es correcta, te muestra su carácter. Sino, te muestra 'X'. 
void hacer_pregunta_5(char contrasenia_adivinada[MAX_CONTRASENIA]){

    char opcion;
    printf("¿Como se llama el tigre de la princesa Jazmín?\n");
    printf("A) Zafiro\n");
    printf("B) Abú\n");
    printf("C) Rajah\n");
    printf("D) Jafar\n");
    printf("Respuesta: ");
    scanf(" %c", &opcion);

    verificar_ingreso_multiple_choice(&opcion);
    corregir_respuesta_pregunta_5(contrasenia_adivinada, opcion);   
}

//PRE: El vector contrasenia_adivinada tiene que estar inicializado.
//POS: Te muestra lo desbloqueado de la contraseña.
void mostrar_contrasenia(char contrasenia_adivinada[MAX_CONTRASENIA]){

    printf("-");
    for(int i = 0; i < TOPE_CONTRASENIA; i++)
        printf("%c", contrasenia_adivinada[i]);
    printf("-\n");
}

//PRE: -
//POS: -
void adivinar_contrasenia(char contrasenia_adivinada[MAX_CONTRASENIA]){

    inicializar_contrasenia(contrasenia_adivinada);

    hacer_pregunta_1(contrasenia_adivinada);
    system("clear");
    hacer_pregunta_2(contrasenia_adivinada);
    system("clear");
    hacer_pregunta_3(contrasenia_adivinada);
    system("clear");
    hacer_pregunta_4(contrasenia_adivinada);
    system("clear");
    hacer_pregunta_5(contrasenia_adivinada);
    system("clear");

    mostrar_contrasenia(contrasenia_adivinada);

}