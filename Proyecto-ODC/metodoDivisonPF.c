#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cantidadCaracteresNumero(char * numero , short* resultado){
    char * numeroAux = numero;
    while ( (*numeroAux) != '\0' ){
        *resultado = *resultado + 1;
        numeroAux++;
    }
}

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
    cantidadCaracteresNumero( parteFraccionaria, sizeFraccion );
    parteFraccionaria = parteFraccionaria + *sizeFraccion - 1;
    while( *contador < *sizeFraccion ){
        if(*parteFraccionaria >= '0' && *parteFraccionaria <= '9' ){
            *digito = *parteFraccionaria - '0';
        }
        else if( *parteFraccionaria >= 'A' && *parteFraccionaria <= 'F' ){
            *digito = *parteFraccionaria - 55;
        }
        else if( *parteFraccionaria >= 'a' && *parteFraccionaria <= 'f' ){
            *digito = *parteFraccionaria - 87;
        }
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
