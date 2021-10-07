#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void convertirCaracter (short * digitoActual, char * numeroAux) {
    if (*numeroAux >= '0' && *numeroAux <= '9'){
        *digitoActual = *numeroAux- '0';
    }
    else if (*numeroAux >= 'A' && *numeroAux <= 'F'){
        *digitoActual = *numeroAux - 55;
    }
    else if (*numeroAux >= 'a' && *numeroAux <= 'f'){
        *digitoActual = *numeroAux - 87;
    }
}



// Implementar mostrar.
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
