#include "increidle.h"
#include "kronos.h"
#include "ingreso.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void instrucciones(){
    printf("INSTRUCCIONES:\n");
    printf("-TECLAS PARA MOVERSE : W/A/S/D\n");
    printf("-TECLA DEL SUPERPODER: C\n");

    printf("CARÁCTERES:\n");
    printf(". - CASILLERO LIBRE\n");
    printf("T - SUPERTRAJE, AGARRALO PARA PODER USAR EL SUPERPODER\n");
    printf("P - PINZA, SI LA PISAS TE MANDA A UN LUGAR RANDOM ALREDEDOR DEL ROBOT EN EL CUADRANTE INICIAL\n");
    printf("R - ROBOT, EVITALO HACEME CASO O VAS A PERDER\n");
    printf("L - LASER, LO MISMO QUE ARRIBA PERO SE MUEVEN EN SENTIDO ANTIHORARIO\n");
    printf("S - SALIDA, TENES QUE ESCAPAR COMO MR. INCREIBLE\n");

    printf("PERSONAJES:\n");
    printf("E - ELASTIC GIRL, COMENZAS JUGANDO CON ELLA Y TENES QUE IR A BUSCAR A VIOLETA\n");
    printf("V - VIOLETA, DESPUES TENES QUE BUSCAR A DASH\n");
    printf("D - DASH, LUEGO A MR. INCREIBLE\n");
    printf("I - MR. INCREIBLE, Y POR ULTIMO BUSCAR LA SALIDA\n");

    printf("PODERES:\n");
    printf("-ELASTIC GIRL PUEDE MOVER 3 CASILLEROS\n");
    printf("-VIOLETA CREA UN ESCUDO Q LA HACE INVULNERABLE A LOS LASERS\n");
    printf("-DASH SE TELETRANSPORTA DE MANERA ALEATORIA AL CUADRANTE DE MR. INCREIBLE\n");
    printf("-MR. INCREIBLE LAS PINZAS NO LE AFECTAN\n");
}

int main(){
    char contrasenia_adivinada[MAX_CONTRASENIA];
    juego_t juego;
  
    adivinar_contrasenia(contrasenia_adivinada);

    printf("Presione una tecla para continuar: ");
    getchar();
    getchar();
    system("clear");

    instrucciones();

    printf("\nPresione una tecla para empezar: ");
    getchar();
    system("clear");

    inicializar_juego(&juego, strcmp(contrasenia_adivinada, "KRONOS") == 0);
    imprimir_terreno(juego);

    while(estado_juego(juego) == 0){
        realizar_jugada(&juego, movimiento(juego));   
        imprimir_terreno(juego);
    }
        
    system("clear");
    
    imprimir_terreno(juego);

    printf("FIN DEL JUEGO\n");
    if(estado_juego(juego) == 1)
        printf("FELICIDADES USTED HA GANADO\n");
    else 
        printf("PERDISTE :'c\n");
    
    return 0;
}
