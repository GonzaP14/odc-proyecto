#include <stdio.h>
#include <stdlib.h>

void convertirLetra ( char* numero ){
    char* resultado;
    resultado = numero;
    if(*numero >= 10 && *numero < 16){
        *resultado = 'A' + *numero - 10;
    }
    else
        *resultado = 'j';
}

void invertirNumero(char* numero , short int* sizeNumero ){
    char* aux;
    char* cola;
    aux = (char*) malloc(sizeof(char));
    cola = numero + *(sizeNumero) - 1;
    while( numero != cola ){
        *aux = *numero;
        *numero = *cola;
        *cola = *aux;
        if((++numero) != cola)
            cola--;
    }
    free(aux);
}

char * metodoDivision(long int* numero , short int* baseDestino , short int* mostrarPasos ){
    long int* numeroAux;
    short int* sizeNumero;
    char* resultado;
    sizeNumero = (short int*) malloc(sizeof(short int));
    resultado = (char*) malloc(sizeof(char));
    numeroAux = numero;
    *sizeNumero = 0;

    while( *numeroAux > 0 && *sizeNumero <= 11 ){
        *resultado = *numeroAux % *baseDestino;
        if( *resultado >= 10 && *baseDestino > 10){
            convertirLetra(resultado);
            printf("%c \n" , *resultado);
        }
        *numeroAux /= *baseDestino;
        resultado++;
        *sizeNumero+= 1;
    }
    //Vuelvo el resultado a su posicion inicial osea a resultado[0]
    resultado -= *sizeNumero ;
    if( *sizeNumero > 11 ){
        free(resultado);
        resultado = (char*) malloc(sizeof(char));
        *resultado = 'j';
    }
    else{
        invertirNumero(resultado , sizeNumero);
    }
    free(sizeNumero);
    return resultado;
}

