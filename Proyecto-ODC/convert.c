#include <stdio.h>
#include <stdlib.h>
#include "metodoMultiplicacionPF.h"

int main () {
    double numero = 0.1234;
    double * pnumero = &numero;

    short baseDestino = 16;
    short * pBaseDestino = &baseDestino;

    short presicion = 4;
    short * pPresicion = &presicion;

    short mostrar = 1;
    short * pMostrar = &mostrar;

    char * resultado;
    resultado = parteFraccionaria10ADestino (pnumero, pBaseDestino, pPresicion, pMostrar);

    printf ("El número %lf en base 10 es en base 16 igual a", *pnumero);

    for (int i = 0; i < presicion; i ++) {
        printf ("%c", *resultado);
        resultado ++;
    }
    printf (".");

    free (resultado);

    return 0;
}
