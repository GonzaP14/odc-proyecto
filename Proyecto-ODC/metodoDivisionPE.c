#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "metodosAuxiliares.h"

char * parteEntera10aDestino (long long * numero , short * baseDestino , short * mostrar){
    long long * numeroAux;
    short * sizeNumero;
    short * capacidad;
    char* resultado;
    //char* auxiliar;

    sizeNumero = (short *) malloc (sizeof(short));
    capacidad = (short *) malloc (sizeof(short));
    resultado = (char*) malloc (45 * sizeof(char));

    numeroAux = numero;
    *sizeNumero = 0;
    *capacidad = 40;

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

        /* En progreso: Reacomodar o Alternativa 45 * sizeOf (char)
        if (*sizeNumero == *capacidad) {
            auxiliar = realloc (resultado, 2 * sizeof (numero));
            *capacidad = *capacidad * 2;
            resultado = auxiliar;
        }
        */

        resultado ++;
        *sizeNumero += 1;
    }

    *resultado = '\0';
    resultado -= *sizeNumero ;
    strrev (resultado);

    free (sizeNumero);
    free (capacidad);

    return resultado;
}
