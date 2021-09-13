
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double * cantidadCaracteresNumero(char * numero , int * baseInicio ){
    double * resultado = (double *) malloc(sizeof(double));
    *resultado = -1.0f;
    char * numeroAux = numero;
    while ( (*numeroAux) != '\0' ){
        *resultado = *resultado + 1;
        numeroAux++;
    }
    return resultado;
}

double * metodoMultiplicacion(char * numero , int * baseInicio ){
    char* numeroAux;
    double* digitoActual;
    double* cantidadCaracteres;
    double* resultado;
    resultado = (double *) malloc(sizeof(double));
    digitoActual = (double *) malloc(sizeof(double));
    *resultado = 0;
    *digitoActual = 0;
    numeroAux = numero;
    cantidadCaracteres = cantidadCaracteresNumero(numero , baseInicio );
    while( *cantidadCaracteres >= 0.0f ){
        *digitoActual = *numeroAux - '0';
        *resultado = *resultado + (*digitoActual) * (pow(8, *cantidadCaracteres));
        *cantidadCaracteres = (*cantidadCaracteres) - 1.0f ;
        numeroAux++;
    }
    free(cantidadCaracteres);
    return resultado;
}


