#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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
const int PRIMOS_DIVISORES = TOPE_PRIMOS * 2;
#define MAX_NUM 20
#define POSICION_1 0
#define POSICION_2 1
#define POSICION_3 2
#define POSICION_4 3
#define POSICION_5 4
#define POSICION_6 5

//PRE: -
//POS: Inicializo el vector Contrasenia en 'X';
void Inicializar_Contrasenia(char Contrasenia[MAX_NUM]){
    for(int i = 0; i < TOPE_CONTRASENIA; i++)
        Contrasenia[i] = OCULTO;
}

//PRE: El vector numeros_primos tiene que estar inicializado.
//POS: Te muestra true si todos los numeros son primos o false en caso de que alguno no lo sea.
bool Es_Primo(int numeros_primos[MAX_NUM]){

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
void Corregir_Respuesta_Pregunta_1(char Contrasenia[MAX_NUM], char opcion){

    if(opcion == OPCION_A)
        Contrasenia[POSICION_1] = PRIMERA_LETRA;
}

//PRE: -
//POS: Te reemplaza la letra correspondiente en la posicion del vector.
void Corregir_Respuesta_Pregunta_2(char Contrasenia[MAX_NUM], char opcion){

    if(opcion == OPCION_C)
        Contrasenia[POSICION_2] = SEGUNDA_LETRA;
}

//PRE: -
//POS: Te reemplaza la letra correspondiente en la posicion del vector.
void Corregir_Respuesta_Pregunta_3(char Contrasenia[MAX_NUM], bool todos_primos){

    if(todos_primos){
        Contrasenia[POSICION_3] = TERCERA_LETRA;
        Contrasenia[POSICION_5] = QUINTA_LETRA;
    }
}

//PRE: -
//POS: Te reemplaza la letra correspondiente en la posicion del vector.
void Corregir_Respuesta_Pregunta_4(char Contrasenia[MAX_NUM], int numero_mcqueen){

    if(numero_mcqueen == NUMERO_MCQUEEN)
        Contrasenia[POSICION_4] = CUARTA_LETRA;
}

//PRE: -
//POS: Te reemplaza la letra correspondiente en la posicion del vector.
void Corregir_Respuesta_Pregunta_5(char Contrasenia[MAX_NUM], char opcion){

    if(opcion == OPCION_C)
        Contrasenia[POSICION_6] = SEXTA_LETRA;
}

//PRE: -
//POS: Te pide que ingreses de vuelta en caso de que el ingreso sea erróneo.
void Verificar_Ingreso_Multiple_Choice(char* opcion){

    while((*opcion != OPCION_A) && (*opcion != OPCION_B) && (*opcion != OPCION_C) && (*opcion != OPCION_D)){
        printf("Por favor ingrese bien su respuesta en mayúsculas: ");
        scanf(" %c", opcion);
    }
}

//PRE: -
//POS: Te pide que ingreses de vuelta en caso de que el ingreso sea erróneo.
void Verificar_Ingreso_Numero(int* numero){

    while((*numero < VALOR_MIN_VALIDO) || (*numero > VALOR_MAX_VALIDO)){
        printf("Por favor, ingrese un número válido entre 1 y 100: ");
        scanf("%i", numero);
    }
}

//PRE: El vector Contrasenia tiene que estar inicializado.
//POS: Si la respuesta es correcta, te muestra su carácter. Sino, te muestra 'X'. 
void Hacer_Pregunta_1(char Contrasenia[MAX_NUM]){

    char opcion;
    printf("¿Cual es el código de emergencia utilizado en Monster Inc. cuando uno de los personajes tiene una media humana pegada a su cuerpo?\n");
    printf("A) 3312\n");
    printf("B) 3317\n");
    printf("C) 2312\n");
    printf("D) 2031\n");
    printf("Respuesta: ");
    scanf(" %c", &opcion);

    Verificar_Ingreso_Multiple_Choice(&opcion);
    Corregir_Respuesta_Pregunta_1(Contrasenia, opcion);
}

//PRE: El vector Contrasenia tiene que estar inicializado.
//POS: Si la respuesta es correcta, te muestra su carácter. Sino, te muestra 'X'. 
void Hacer_Pregunta_2(char Contrasenia[MAX_NUM]){

    char opcion;
    printf("¿Cuál era el nombre del pez mascota de Lilo?\n");
    printf("A) Stitch\n");
    printf("B) Pez\n");
    printf("C) Pato\n");
    printf("D) Aurelio\n");
    printf("Respuesta: ");
    scanf(" %c", &opcion);

    Verificar_Ingreso_Multiple_Choice(&opcion);
    Corregir_Respuesta_Pregunta_2(Contrasenia, opcion);
}

//PRE: El vector Contrasenia tiene que estar inicializado.
//POS: Si la respuesta es correcta, te muestra su carácter. Sino, te muestra 'X'. 
void Hacer_Pregunta_3(char Contrasenia[MAX_NUM]){

    int numeros_primos[MAX_NUM];

    printf("Ingrese 5 números primos\n");
    for(int i = 0; i < TOPE_PRIMOS; i++){
        printf("Ingrese su %i número: ", i+1);
        scanf("%i", &numeros_primos[i]);

        Verificar_Ingreso_Numero(&numeros_primos[i]);
    }  
    Corregir_Respuesta_Pregunta_3(Contrasenia, Es_Primo(numeros_primos));
}

//PRE: El vector Contrasenia tiene que estar inicializado.
//POS: Si la respuesta es correcta, te muestra su carácter. Sino, te muestra 'X'. 
void Hacer_Pregunta_4(char Contrasenia[MAX_NUM]){

    int numero_mcqueen;
    printf("¿Qué número lleva el Rayo McQueen?\n");
    printf("Respuesta: ");
    scanf("%i", &numero_mcqueen);

    Verificar_Ingreso_Numero(&numero_mcqueen);
    Corregir_Respuesta_Pregunta_4(Contrasenia, numero_mcqueen); 
}

//PRE: El vector Contrasenia tiene que estar inicializado.
//POS: Si la respuesta es correcta, te muestra su carácter. Sino, te muestra 'X'. 
void Hacer_Pregunta_5(char Contrasenia[MAX_NUM]){

    char opcion;
    printf("¿Como se llama el tigre de la princesa Jazmín?\n");
    printf("A) Zafiro\n");
    printf("B) Abú\n");
    printf("C) Rajah\n");
    printf("D) Jafar\n");
    printf("Respuesta: ");
    scanf(" %c", &opcion);

    Verificar_Ingreso_Multiple_Choice(&opcion);
    Corregir_Respuesta_Pregunta_5(Contrasenia, opcion);   
}

//PRE: El vector Contrasenia tiene que estar inicializado.
//POS: Te muestra lo desbloqueado de la Contraseña.
void Mostrar_Contrasenia(char Contrasenia[MAX_NUM]){

    printf("-");
    for(int i = 0; i < TOPE_CONTRASENIA; i++)
        printf("%c", Contrasenia[i]);
    printf("-\n");
}

int main(){

    char Contrasenia[MAX_NUM];

    Inicializar_Contrasenia(Contrasenia);

    Hacer_Pregunta_1(Contrasenia);
    system("clear");
    Hacer_Pregunta_2(Contrasenia);
    system("clear");
    Hacer_Pregunta_3(Contrasenia);
    system("clear");
    Hacer_Pregunta_4(Contrasenia);
    system("clear");
    Hacer_Pregunta_5(Contrasenia);
    system("clear");

    Mostrar_Contrasenia(Contrasenia);
        
    return 0;
}
