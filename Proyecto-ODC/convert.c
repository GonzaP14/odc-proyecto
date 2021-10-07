#include <stdio.h>
#include <stdlib.h>
#include "Conversor.h"

int main () {
    char numero [7] = "F0.123";
    char * pNumero = &numero[0];

    short baseOrigen = 16;
    short * pBaseOrigen = &baseOrigen;

    short baseDestino = 2;
    short * pBaseDestino = &baseDestino;

    short mostrar = 1;
    short * pMostrar = &mostrar;

    char * resultado = convertir (pNumero, pBaseOrigen, pBaseDestino , pMostrar);
    int contador = 0;

    printf ("El número %s en base %hd es igual a ", numero, baseOrigen);

    while (*resultado != '\0') {
        printf ("%c", *resultado);
        resultado ++;
        contador ++;
    }

    printf (" en base %hd. \n", baseDestino);

    return EXIT_SUCCESS;
}
