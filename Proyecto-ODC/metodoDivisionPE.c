#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "metodosAuxiliares.h"

char * parteEntera10aDestino (long long * numero, short * baseDestino, short * mostrar){
    long long * numeroAux;
    long long * auxiliar;
    short * sizeNumero;
    char* resultado;

    sizeNumero = (short *) malloc (sizeof(short));
    resultado = (char *) malloc (45 * sizeof(char));
    auxiliar = (long long *) malloc (sizeof (long long));

    *auxiliar = *numero;
    numeroAux = numero;
    *sizeNumero = 0;

    while (*numeroAux > 0){
        if (*mostrar == 1){
            printf("X%hd = %I64d mod %hd", *sizeNumero , *numeroAux , *baseDestino);
        }

        *resultado = (*numeroAux % *baseDestino);

        if (*resultado >= 10 && *baseDestino > 10){
            convertirLetra (resultado);
        }
        else{
            *resultado = *resultado + '0';
        }

        if (*mostrar == 1){
            printf (" = %c y Q%hd = (%I64d - %c) / %hd ", *resultado , *sizeNumero , *numeroAux , *resultado , *baseDestino);
        }

        *numeroAux /= *baseDestino;

        if (*mostrar == 1){
            printf ("= %I64d \n" , *numeroAux);
        }

        resultado ++;
        *sizeNumero += 1;
    }

    if (*sizeNumero == 0 && *mostrar == 1) {
        *resultado = '0';
        printf("X%hd = %I64d mod %hd ", *sizeNumero , *numeroAux , *baseDestino);
        resultado++;
        *sizeNumero+=1;
        printf ("= (%I64d) %hd \n" , *numeroAux, *baseDestino);
    }

    *resultado = '\0';
    resultado -= *sizeNumero ;
    strrev (resultado);

    if (*mostrar == 1) {
        printf ("Luego, (%I64d) 10 = (%s) %hi \n", *auxiliar, resultado, *baseDestino);
    }

    free (auxiliar);
    free (sizeNumero);

    return resultado;
}
