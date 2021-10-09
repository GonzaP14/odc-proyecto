#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "metodosAuxiliares.h"

long long * parteEnteraOrigenA10 (char * numero , short * baseOrigen, short * mostrar){
    long long * resultado;
    long long * pot;
    char * numeroAux;
    short * digitoActual;
    short * cantidadCaracteres;
    short * cantidadDigitos;

    digitoActual = (short *) malloc (sizeof(short));
    cantidadCaracteres = (short *) malloc (sizeof(short));
    resultado = (long long *) malloc (sizeof(long long));
    pot = (long long *) malloc (sizeof(long long));
    cantidadDigitos = (short *) malloc (sizeof (short));
    numeroAux = numero;

    * digitoActual = 0;
    * cantidadCaracteres = 0;
    * resultado = 0;
    * cantidadDigitos = 0;

    *cantidadCaracteres = strlen(numeroAux) - 1;

    while (*cantidadCaracteres >= 0) {

        if (*mostrar == 1){
           printf("%I64i + %c x %hi^%hi " , *resultado , *numeroAux , *baseOrigen , *cantidadCaracteres );
        }

        convertirCaracter (digitoActual, numeroAux);
        * pot = (pow (* baseOrigen, * cantidadCaracteres));
        * resultado = * resultado + ((* digitoActual) * (* pot));

        if (*mostrar == 1){
            printf("= %I64i \n" , *resultado );
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
