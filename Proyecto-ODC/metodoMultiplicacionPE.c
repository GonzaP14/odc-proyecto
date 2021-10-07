#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "metodosAuxiliares.h"

long * parteEnteraOrigenA10 (char * numero , short * baseInicio, short * mostrar){
    long * resultado;
    long * pot;
    char * numeroAux;
    short * digitoActual;
    short * cantidadCaracteres;
    short * cantidadDigitos;

    digitoActual = (short *) malloc (sizeof(short));
    cantidadCaracteres = (short *) malloc (sizeof(short));
    resultado = (long *) malloc (sizeof(long));
    pot = (long *) malloc (sizeof(long));
    cantidadDigitos = (short *) malloc (sizeof (short));
    numeroAux = numero;

    * digitoActual = 0;
    * cantidadCaracteres = 0;
    * resultado = 0;
    * cantidadDigitos = 0;

    *cantidadCaracteres = strlen(numeroAux) - 1;

    while (*cantidadCaracteres >= 0) {

        if(*mostrar == 1){
           printf("%ld + %c x %hd^%hd " , *resultado , *numeroAux , *baseInicio , *cantidadCaracteres );
        }
        convertirCaracter (digitoActual, numeroAux);
        * pot = (pow (* baseInicio, * cantidadCaracteres));
        * resultado = * resultado + ((* digitoActual) * (* pot));
        if(*mostrar == 1){
            printf("= %ld \n" , *resultado );
        }
        * cantidadCaracteres = * cantidadCaracteres - 1;
        numeroAux ++;
    }

    free (digitoActual);
    free (cantidadCaracteres);
    free (pot);
    free (cantidadDigitos);

    return resultado;
}
