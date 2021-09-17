#include <stdio.h>
#include <stdlib.h>
#include "metodoMultiplicacionPF.h"

int main () {

    char * resultado;
    double * numerito;
    short * base;

    //resultado = (char *) malloc (sizeof (char));
    numerito = (double *) malloc (sizeof (double));
    base = (short *) malloc (sizeof (short));

    * base = 16;
    * numerito = (0.9999);

    resultado = parteFraccionariaSourceA10 (numerito, base);
    printf ("El numero %lf en base [10] es en base [%i] = ", *numerito, *base);

    for (int i = 0; i < 5; i ++) {
        printf ("%c", *(resultado + i));
    }

    free (resultado);

    return 0;
}
