#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "metodosAuxiliares.h"

char * parteEntera10aDestino (long int* numero , short int* baseDestino , short int* mostrarPasos ){
    long int* numeroAux;
    short int* sizeNumero;
    char* resultado;
    sizeNumero = (short int*) malloc(sizeof(short int));
    resultado = (char*) malloc(sizeof(char));
    numeroAux = numero;
    *sizeNumero = 0;
    while( *numeroAux > 0 ){
        if( *mostrarPasos == 1){
            printf("X%hd = %ld mod %hd", *sizeNumero , *numeroAux , *baseDestino);
        }
        *resultado = *numeroAux % *baseDestino;
        if( *resultado >= 10 && *baseDestino > 10){
            convertirLetra(resultado);
        }
        else{
            *resultado = *resultado + '0';
        }
        if( *mostrarPasos == 1 ){
            printf(" = %c y Q%hd = (%ld - %c) / %hd ", *resultado , *sizeNumero , *numeroAux , *resultado , *baseDestino );
        }
        *numeroAux /= *baseDestino;
        if( *mostrarPasos == 1 ){
            printf("= %ld \n" , *numeroAux );
        }
        resultado++;
        *sizeNumero+= 1;
    }
    //Vuelvo el resultado a su posicion inicial osea a resultado[0]
    resultado -= *sizeNumero ;
    strrev(resultado);
    free(sizeNumero);
    return resultado;
}

