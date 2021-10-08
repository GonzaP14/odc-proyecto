#include <stdio.h>
#include <stdlib.h>
#include "Conversor.h"

int main () {
    char numero [17] = "FFFFFFFFFF.FFFFF";
    char * pNumero = &numero[0];

    short baseOrigen = 16;
    short * pBaseOrigen = &baseOrigen;

    short baseDestino = 2;
    short * pBaseDestino = &baseDestino;

    short mostrar = 1;
    short * pMostrar = &mostrar;

    char * resultado = convertir (pNumero, pBaseOrigen, pBaseDestino , pMostrar);

    printf ("El numero %s en base %hd es igual a ", numero, baseOrigen);

    printf("%s",resultado);

    printf (" en base %hd. \n", baseDestino);

    return EXIT_SUCCESS;
}
