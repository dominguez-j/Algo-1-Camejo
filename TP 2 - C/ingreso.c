#include "ingreso.h"
#include "terreno.h"
#include <stdio.h>
#include <stdlib.h>

//PRE: El juego y el movimiento tienen que estar inicializados.
//POS: Te pide que ingreses de vuelta en caso de que el ingreso sea erróneo. 
void verificar_ingreso(char* movimiento){
    if((*movimiento != ARRIBA) && (*movimiento != ABAJO) && (*movimiento != IZQUIERDA) && (*movimiento !=  DERECHA) && (*movimiento != ACTIVAR_PODER)){
        printf("Por favor, ingrese W / S / A / D / C para hacer su jugada: ");
        scanf(" %c", movimiento);
        verificar_ingreso(movimiento);
    }
}

char movimiento(){
    char movimiento;
    
    printf("Ingrese su movimiento:\n");
    printf("W - Arriba\n");
    printf("S - Abajo\n");
    printf("A - Izquierda\n");
    printf("D - Derecha\n");
    printf("C - Activar poder, en caso de que tengas supertraje\n");
    printf("Tecla: ");
    scanf(" %c", &movimiento);
    
    verificar_ingreso(&movimiento);
    system("clear");

    return movimiento;
}
