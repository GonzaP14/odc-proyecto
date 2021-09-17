#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void convertirCaracter (long * digitoActual, char * numeroAux) {
    switch (*numeroAux) {
        case '1': *digitoActual = 1; break;
        case '2': *digitoActual = 2; break;
        case '3': *digitoActual = 3; break;
        case '4': *digitoActual = 4; break;
        case '5': *digitoActual = 5; break;
        case '6': *digitoActual = 6; break;
        case '7': *digitoActual = 7; break;
        case '8': *digitoActual = 8; break;
        case '9': *digitoActual = 9; break;

        case ('a'):
        case ('A'): *digitoActual = 10; break;
        case ('b'):
        case ('B'): *digitoActual = 11; break;
        case ('c'):
        case ('C'): *digitoActual = 12; break;
        case ('d'):
        case ('D'): *digitoActual = 13; break;
        case ('e'):
        case ('E'): *digitoActual = 14; break;
        case ('f'):
        case ('F'): *digitoActual = 15; break;
    }
}

long * parteEnteraSourceA10 (char * numero , short * baseInicio){
    char * numeroAux;
    short * digitoActual;
    short * cantidadCaracteres;

    long * resultado;
    long * pot;
    short * cantidadDigitos;

    digitoActual = (short *) malloc (sizeof(short));
    cantidadCaracteres = (short *) malloc (sizeof(short));
    resultado = (long *) malloc (sizeof(long));
    pot = (long *) malloc (sizeof(long));
    cantidadDigitos = (short *) malloc (sizeof (short));

    numeroAux = numero;
    *digitoActual = 0;
    * cantidadCaracteres = strlen (numero) - 1;
    * resultado = 0;
    * cantidadDigitos = 0;

    while (*cantidadCaracteres >= 0) {
        convertirCaracter (digitoActual, numeroAux);
        *pot = (pow (*baseInicio, *cantidadCaracteres));
        *resultado = *resultado + (*digitoActual) * (*pot);
        *cantidadCaracteres = *cantidadCaracteres - 1;
        numeroAux ++;
    }

    free (digitoActual);
    free (cantidadCaracteres);
    free (pot);

    return resultado;
}
