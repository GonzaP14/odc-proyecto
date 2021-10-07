#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "metodoMultiplicacionPE.h"
#include "metodoMultiplicacionPF.h"
#include "metodoDivisionPE.h"
#include "metodoDivisionPF.h"
#include "Validacion.h"

char * parteEntera (char * numero) {
    char * numPE;
    short * contador;

    numPE = (char *) malloc (10 * sizeof (char));
    contador = (short *) malloc (sizeof (contador));
    *contador = 0;

    while (*numero != '.' && *numero != '\0') {
        *numPE = *numero;
        *contador = *contador + 1;
        numPE ++;
        numero ++;
    }

    numero -= *contador;
    free (contador);

    return numPE;
}

char * parteFraccionaria (char * numero) {
    char * numPF;
    short * contador;

    numPF = (char *) malloc (5 * sizeof (char));
    contador = (short *) malloc (sizeof (contador));
    *contador = 0;

    while (*numero != '.') {
        numero ++;
        *contador = *contador + 1;
    }

    while (*numero != '\0') {
        *numPF = *numero;
        *contador = *contador + 1;
        numPF ++;
        numero ++;
    }

    numero -= *contador;
    free (contador);

    return numPF;
}

char * convertirParteEntera (char * numPE, short * baseOrigen, short * baseDestino, short * mostrar) {
    char * resultado;
    long * auxiliar;

    auxiliar = parteEnteraOrigenA10 (numPE, baseOrigen, mostrar);
    resultado = parteEntera10aDestino (auxiliar, baseDestino, mostrar);

    return resultado;
}

char * convertirParteFraccionaria (char * numPF, short * baseOrigen, short * baseDestino, short * mostrar) {
    short * precision;
    char * resultado;
    double * auxiliar;

     precision = (short *) malloc (sizeof (short));
    *precision = 10;
    auxiliar = parteFraccionariaOrigenA10 (numPF, baseOrigen, mostrar);
    resultado = parteFraccionaria10ADestino (auxiliar, baseDestino, precision, mostrar);

    return resultado;
}

char * convertir (char * numero, short * baseOrigen, short * baseDestino, short * mostrar) {
    short * check;
    short * check2;
    char * numPE;
    char * numPF;
    char * numPEConvertido;
    char * numPFConvertido;
    char * resultado;

    resultado = (char *) malloc (100 * sizeof (char));

    numPE = parteEntera (numero);
    numPF = parteFraccionaria (numero);
    check = verificarNumero (numPE,baseOrigen);
    check2 = verificarNumero (numPF,baseOrigen);


    if (*check == 1 && *check2 == 1) {
        numPEConvertido = convertirParteEntera (numPE, baseOrigen, baseDestino, mostrar);
        numPFConvertido = convertirParteFraccionaria (numPF, baseOrigen, baseDestino, mostrar);

        if (numPFConvertido == NULL) {
            resultado = numPEConvertido;
        } else {
            resultado = strcat (strcat (numPEConvertido, "."), numPFConvertido);
        }

    } else {
        printf ("El número no verifica las condiciones de su base origen: %i.", *baseOrigen);
        exit (EXIT_FAILURE);
    }
    free(check);
    return resultado;
}


