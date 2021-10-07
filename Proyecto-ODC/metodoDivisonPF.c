#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double * metodoDivisionPF(char * parteFraccionaria , short int * baseOrigen , short int * mostrarPasos){
    short int* sizeFraccion;
    short int* contador;
    double* resultado;
    short int* digito;
    resultado = (double*) malloc( sizeof(double));
    sizeFraccion = (short int*) malloc(sizeof(short int));
    contador = (short int*) malloc(sizeof(short int));
    digito = (short int*) malloc(sizeof(short int));
    *sizeFraccion=-1;
    *contador = 0;
    *resultado = 0.00;
    *digito = 0;
    *sizeFraccion = strlen(parteFraccionaria) - 1;
    parteFraccionaria = parteFraccionaria + *sizeFraccion - 1;
    while( *contador < *sizeFraccion ){
        convertirCaracter( digito , parteFraccionaria );
        *resultado += *digito;
        *resultado /= *baseOrigen;
        *contador+= 1;
        parteFraccionaria--;
    }
    free(digito);
    free(sizeFraccion);
    free(contador);
    return resultado;
}
