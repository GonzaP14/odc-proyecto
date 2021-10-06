#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Implementar mostrar.
char * parteFraccionaria10ADestino (double * numero, short * baseDestino, short * precision, short mostrar) {
    char * resultado;
    double * numeroAux;
    double * resultadoActual;
    short * digitoActual;
    short * limite;

    resultado = (char *) malloc ((* precision) * sizeof (char));
    numeroAux = (double *) malloc (sizeof (double));
    resultadoActual = (double *) malloc (sizeof (double));
    digitoActual = (short *) malloc (sizeof (short));
    limite = (short *) malloc (sizeof (short));

    * numeroAux = * numero;
    * limite = * precision;

    while ((*limite) != 0) {
        * resultadoActual = (* numeroAux) * (* baseDestino);
        * digitoActual = floor (*resultadoActual);
        * numeroAux = * resultadoActual - * digitoActual;

        if (*digitoActual < 10) {
            *resultado = *digitoActual + '0';
        }
        else {
            *resultado = 'A' + (*digitoActual - 10);
        }

        resultado ++;
        *limite = *limite - 1;
    }

    resultado = resultado - *precision;

    free (resultadoActual);
    free (digitoActual);
    free (limite);
    free (numeroAux);

    return resultado;
}
