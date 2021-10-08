#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "metodosAuxiliares.h"

double * parteFraccionariaOrigenA10 (char * parteFraccionaria , short int * baseOrigen , short int * mostrar){
    short int* sizeFraccion;
    short int* contador;
    double* resultado;
    short int* digito;

    resultado = (double*) malloc( sizeof(double));
    sizeFraccion = (short int*) malloc(sizeof(short int));
    contador = (short int*) malloc(sizeof(short int));
    digito = (short int*) malloc(sizeof(short int));

    *sizeFraccion = 0;
    *contador = 0;
    *resultado = 0.00;
    *digito = 0;
    *sizeFraccion = strlen(parteFraccionaria);
    parteFraccionaria = parteFraccionaria + *sizeFraccion - 1;

    while( *contador < *sizeFraccion ){
        convertirCaracter( digito , parteFraccionaria );

        if (*mostrar == 1){
            printf("%hd x %hd ^ (%hd) " , *digito , *baseOrigen , *sizeFraccion *(-1));
        }

        if (*mostrar == 1 && *contador+1 != *sizeFraccion){
            printf(" + ");
        }

        *resultado += *digito;
        *resultado /= *baseOrigen;
        *sizeFraccion-= 1;
        parteFraccionaria--;
    }

    printf("\n");

    free(digito);
    free(sizeFraccion);
    free(contador);

    return resultado;
}
