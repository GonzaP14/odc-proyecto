#include <stdio.h>
#include <stdlib.h>

double * metodoDivisionPF(char * parteFraccionaria , short int * baseOrigen , short int * mostrarPasos){
    short int* sizeFraccion;
    short int* contador;
    double* resultado;
    short int* digito;
    resultado = (double *) malloc(sizeof(double));
    sizeFraccion = (short int*) malloc(sizeof(short int));
    contador = (short int*) malloc(sizeof(short int));
    *sizeFraccion = strlen(parteFraccionaria);
    *contador = 0;
    *resultado = 0.00;
    *digito = 0;
    while( *contador < *sizeFraccion ){
        if(*parteFraccionaria >= '0' && *parteFraccionaria <= '9' )
            *digito = *parteFraccionaria - '0';
        else if( *parteFraccionaria >= 'A' && *parteFraccionaria <= 'F' ){
            *digito = *parteFraccionaria - 55;
        }
        else if( *parteFraccionaria >= 'a' && *parteFraccionaria <= 'f' ){
            *digito = *parteFraccionaria - 87;
        }
        else{
            printf("Error");
        }
        *resultado += *digito;
        *resultado /= *baseOrigen;
        *contador+=1;
    }
    free(sizeFraccion);
    free(contador);
    free(resultado);
    return resultado;
}
