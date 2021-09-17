#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char * parteFraccionariaSourceA10 (double * numero, short * baseDestino) {
    char * resultado;

    double * numeroAux;
    double * resultadoActual;

    short * digitoActual;
    short * limite;
    short * cantidadDigitos;

    //printf ("Num = %lf \n",*numero);

    resultado = (char *) malloc (5 * sizeof (char));
    numeroAux = (double *) malloc (sizeof (double));
    resultadoActual = (double *) malloc (sizeof (double));
    digitoActual = (short *) malloc (sizeof (short));
    limite = (short *) malloc (sizeof (short));
    cantidadDigitos = (short *) malloc (sizeof (short));

    * numeroAux = * numero;
    * cantidadDigitos = 0;
    * limite = 5;

    while ((*limite) != 0) {
        *resultadoActual = (*numeroAux) * (*baseDestino);
        *digitoActual = floor (*resultadoActual);
        *numeroAux = *resultadoActual - *digitoActual;

        if (*digitoActual < 10) {
            *resultado = *digitoActual + '0';
        } else {
            *resultado = 'A' + *digitoActual - 10;
        }

        resultado ++;
        *cantidadDigitos = *cantidadDigitos + 1;
        *limite = *limite - 1;
        printf ("%i", *digitoActual);
    }

    resultado = resultado - *cantidadDigitos;

    free (resultadoActual);
    free (digitoActual);
    free (limite);
    free (cantidadDigitos);
    free (numeroAux);

    return resultado;
}
