#include <stdio.h>
#include <stdlib.h>
#include "metodoMultiplicacionPF.h"
#include "metodoDivisionPF.h"

int main () {

    /*
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
    */

    char numero [4] = "7632";
    char * pnum = &numero [0];

    short base = 8;
    short * pb = &base;

    short uno = 1;
    short * pu = &uno;

    printf ("Numero %s en base [%i] es igual a %lf en base 10.", numero, *pb, *metodoDivisionPF (pnum, pb, pu));

    return 0;
}
