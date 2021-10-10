#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "metodosAuxiliares.h"

double * parteFraccionariaOrigenA10 (char * numero, short * baseOrigen , short * mostrar){
    short * sizeFraccion;
    short * contador;
    double* resultado;
    short * digito;
    char * auxiliar;

    resultado = (double*) malloc (sizeof (double));
    sizeFraccion = (short *) malloc (sizeof (short));
    contador = (short *) malloc (sizeof (short));
    digito = (short *) malloc (sizeof (short));

    *sizeFraccion = 0;
    *contador = 0;
    *resultado = 0.00;
    *digito = 0;
    *sizeFraccion = strlen(numero);

    auxiliar = numero;
    numero = numero + *sizeFraccion - 1;

    while (*contador < *sizeFraccion){
        convertirCaracter (digito, numero);

        if (*mostrar == 1){
            printf("%hd x %hd ^ (%hd) " , *digito , *baseOrigen , *sizeFraccion *(-1));
        }

        if (*mostrar == 1 && (*contador + 1 != *sizeFraccion)){
            printf(" + ");
        }

        *resultado += *digito;
        *resultado /= *baseOrigen;
        *sizeFraccion -= 1;
        numero --;
    }

    if (*mostrar == 1 && *sizeFraccion != 0){
        printf(" = (%lf) 10 \n",*resultado);
    }
    else if (*mostrar == 1){
        printf("%hd x %hd ^ (%hd) = (%lf) 10 \n" , *digito, *baseOrigen, *sizeFraccion *(-1), *resultado);
    }

    if (*mostrar == 1) {
        numero ++;
        printf ("Luego, (0.%s) %hi = (%lf) 10 \n", auxiliar, *baseOrigen, *resultado);
    }

    free (digito);
    free (sizeFraccion);
    free (contador);

    return resultado;
}
