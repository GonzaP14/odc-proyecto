#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "metodosAuxiliares.h"

char * parteEntera10aDestino (long long * numero , short * baseDestino , short * mostrar){
    long long * numeroAux;
    short * sizeNumero;
    char* resultado;

    sizeNumero = (short *) malloc (sizeof(short));
    resultado = (char*) malloc (45 * sizeof(char));

    numeroAux = numero;
    *sizeNumero = 0;

    while (*numeroAux > 0){
        if (*mostrar == 1){
            printf("X%hd = %I64d mod %hd", *sizeNumero , *numeroAux , *baseDestino);
        }

        *resultado = (*numeroAux % *baseDestino);

        if (*resultado >= 10 && *baseDestino > 10){
            convertirLetra(resultado);
        }
        else{
            *resultado = *resultado + '0';
        }

        if (*mostrar == 1){
            printf (" = %c y Q%hd = (%I64d - %c) / %hd ", *resultado , *sizeNumero , *numeroAux , *resultado , *baseDestino);
        }

        *numeroAux /= *baseDestino;

        if (*mostrar == 1){
            printf ("= %I64d \n" , *numeroAux );
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
