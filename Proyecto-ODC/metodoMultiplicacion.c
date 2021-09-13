#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int * metodoMultiplicacion (char * numero , int * baseInicio ){
    char * numeroAux;
    int * digitoActual;
    int * cantidadCaracteres;
    int * resultado;
    int * pot;

    resultado = (int *) malloc (sizeof(int));
    digitoActual = (int *) malloc (sizeof(int));
    cantidadCaracteres = (int *) malloc (sizeof(int));
    pot = (int *) malloc (sizeof(int));

    *resultado = 0;
    *digitoActual = 0;
    numeroAux = numero;
    * cantidadCaracteres = strlen (numero) - 1;

    while (*cantidadCaracteres >= 0) {
        *digitoActual = *numeroAux - '0';
        *pot = floor (pow (*baseInicio, *cantidadCaracteres));
        *resultado = *resultado + (*digitoActual) * (*pot);
        *cantidadCaracteres = *cantidadCaracteres - 1;
        numeroAux ++;
    }

    free (digitoActual);
    free (cantidadCaracteres);
    free (pot);

    return resultado;
}

