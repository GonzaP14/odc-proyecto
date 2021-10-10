#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "metodosAuxiliares.h"

double * parteFraccionariaOrigenA10 (char * numero, short * baseOrigen , short * mostrar){
    short * contador;
    short * limite;
    double* resultado;
    short * digito;
    char * auxiliar;

    resultado = (double*) malloc (sizeof (double));
    contador = (short *) malloc (sizeof (short));
    limite = (short *) malloc (sizeof (short));
    digito = (short *) malloc (sizeof (short));

    *limite = 0;
    *resultado = 0.00;
    *digito = 0;
    *contador = strlen(numero) - 1;

    auxiliar = numero;
    numero = numero + *contador;

    while (*contador >= *limite){
        convertirCaracter (digito, numero);

        if (*mostrar == 1 && (*contador != *limite)){
            printf("%hd x %hd ^ (%hd) + " , *digito , *baseOrigen , (*contador + 1) *(-1));
        } else {
            printf("%hd x %hd ^ (%hd)" , *digito , *baseOrigen , (*contador + 1) *(-1));
        }

        *resultado += *digito;
        *resultado /= *baseOrigen;
        *contador -= 1;
        numero --;
    }

    if (strlen (numero) - 1 != 0) {
        printf (" = (%lf) 10 \n", *resultado);
    }
    else {
        printf("%s * %hd ^ (-1) = (0) 10 \n" , numero, *baseOrigen);
    }

    if (*mostrar == 1) {
        printf ("Luego, (0.%s) %hi = (%lf) 10 \n", auxiliar, *baseOrigen, *resultado);
    }

    free (digito);
    free (contador);
    free (limite);

    return resultado;
}
