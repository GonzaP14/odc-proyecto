#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "metodosAuxiliares.h"

char * parteEntera10aDestino (long * numero , short * baseDestino , short * mostrar){
    long * numeroAux;
    short * sizeNumero;
    char* resultado;

    sizeNumero = (short *) malloc (sizeof(short));
    resultado = (char*) malloc (2 * sizeof(char));

    numeroAux = numero;
    *sizeNumero = 0;

    while (*numeroAux > 0){

        if (*mostrar == 1){
            printf("X%hd = %ld mod %hd", *sizeNumero , *numeroAux , *baseDestino);
        }

        *resultado = (*numeroAux % *baseDestino);

        if (*resultado >= 10 && *baseDestino > 10){
            convertirLetra(resultado);
        }
        else{
            *resultado = *resultado + '0';
        }

        if (*mostrar == 1){
            printf (" = %c y Q%hd = (%ld - %c) / %hd ", *resultado , *sizeNumero , *numeroAux , *resultado , *baseDestino);
        }

        *numeroAux /= *baseDestino;

        if (*mostrar == 1){
            printf ("= %ld \n" , *numeroAux );
        }

        resultado ++;
        *sizeNumero += 1;
    }

    *resultado = '\0';
    resultado -= *sizeNumero ;
    strrev (resultado);

    free (sizeNumero);

    return resultado;
}

