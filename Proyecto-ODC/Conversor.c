#include <stdio.h>
#include <stdlib.h>
#include "metodoMultiplicacionPE.h"
#include "metodoMultiplicacionPF.h"
#include "metodoDivisionPE.h"
#include "metodoDivisionPF.h"

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
        *numPE = *numero;
        *contador = *contador + 1;
        numPE ++;
        numero ++;
    }

    numero -= *contador;
    free (contador);

    return numPE;
}

char * convertirParteEntera (char * numPE, short * baseOrigen, short * baseDestino) {
    char * resultado;
    long * auxiliar;

    auxiliar = parteEnteraOrigenA10 (numPE);
    resultado = parteEntera10aDestino (auxiliar);

    return resultado;
}

char * convertirParteFraccionaria (char * numPF, short * baseOrigen, short * baseDestino) {
    char * resultado;
    long * auxiliar;

    auxiliar = parteFraccionariaOrigenA10 (numPF);
    resultado = parteFraccionaria10ADestino (auxiliar);

    return resultado;
}

char * convertir (char * numero, short * baseOrigen, short * baseDestino) {
    short * check;
    char * numPE;
    char * numPF;
    char * numPEConvertido;
    char * numPFConvertido;
    char * resultado;

    resultado = malloc (100 * sizeof (char));
    numPE = parteEntera (numero);
    numPF = parteFraccionaria (numero);
    check = (verificarNumero (numPE) && verificarNumero (numPF));

    if (*check == 1) {
        numPEConvertido = convertirParteEntera (parteEntera);
        numPFConvertido = convertirParteFraccionaria (parteFraccionaria);
        resultado = str

        if (numPFConvertido == NULL) {
            resultado = numPEConvertido;
        } else {
            resultado = strcat (strcat (numPEConvertido, "."), numPFConvertido);
        }

        /*
        while (*numPEConvertido != '\0') {
            *resultado = *numPEConvertido;
            numPEConvertido ++;
            resultado ++;
        }

        if (numPFConvertido != NULL) {
            *resultado = '.';
            resultado ++;

            while (*numPFConvertido != '\0') {
                *resultado = *numPEConvertido;
                numPFConvertido ++;
                resultado ++;
            }
        }
        */

    } else {
        printf ("El número no verifica las condiciones de su base origen: %i.", *baseOrigen);
        exit (EXIT_FAILURE);
    }
}


