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

    numPE = (char *) malloc (11 * sizeof (char));
    contador = (short *) malloc (sizeof (contador));

    *contador = 0;

    while (*numero != '.' && *numero != '\0') {
        *numPE = *numero;
        *contador = *contador + 1;
        numPE ++;
        numero ++;
    }

    *numPE = '\0';
    numPE -= *contador;
    numero -= *contador;

    free (contador);

    return numPE;
}

char * parteFraccionaria (char * numero) {
    char * numPF;
    short * contador;
    short * contadorNumPF;

    numPF = (char *) malloc (6 * sizeof (char));
    contador = (short *) malloc (sizeof (short));
    contadorNumPF = (short *) malloc (sizeof (short));

    *contador = 0;
    *contadorNumPF = 0;

    while (*numero != '.' && *numero != '\0') {
        numero ++;
        *contador = *contador + 1;
    }

    if (*numero == '.') {
        numero ++;
        *contador = *contador + 1;

        while (*numero != '\0') {
        *numPF = *numero;
        *contadorNumPF += 1;
        *contador += 1;
        numPF ++;
        numero ++;
        }
    }

    *numPF = '\0';
    numero -= *contador;
    numPF -= *contadorNumPF;

    free (contador);
    free (contadorNumPF);

    return numPF;
}

char * convertirParteEntera (char * numPE, short * baseOrigen, short * baseDestino, short * mostrar) {
    char * resultado;
    long long* auxiliar;

    if (*mostrar == 1) {
        printf("Metodo multiplicacion: Parte Entera \n");
        auxiliar = parteEnteraOrigenA10 (numPE, baseOrigen, mostrar);
        printf ("\n");
        printf("Metodo division: Parte Entera \n");
        resultado = parteEntera10aDestino (auxiliar, baseDestino, mostrar);
        printf ("\n");
    }
    else {
        auxiliar = parteEnteraOrigenA10 (numPE, baseOrigen, mostrar);
        resultado = parteEntera10aDestino (auxiliar, baseDestino, mostrar);
    }

    free(auxiliar);

    return resultado;
}

char * convertirParteFraccionaria (char * numPF, short * baseOrigen, short * baseDestino, short * mostrar) {
    short * precision;
    char * resultado;
    double * auxiliar;

    precision = (short*) malloc(sizeof(short));
    *precision = 10;

    if (*mostrar == 1) {
        printf("Metodo division: Parte Fraccionaria \n");
        auxiliar = parteFraccionariaOrigenA10 (numPF, baseOrigen, mostrar);
        printf("\n");
        printf("Metodo multiplicacion: Parte Fraccionaria \n");
        resultado = parteFraccionaria10ADestino (auxiliar, baseDestino, precision, mostrar);
        printf("\n");
    }
    else {
        auxiliar = parteFraccionariaOrigenA10 (numPF, baseOrigen, mostrar);
        resultado = parteFraccionaria10ADestino (auxiliar, baseDestino, precision, mostrar);
    }

    free(auxiliar);
    free(precision);

    return resultado;
}

char * convertir (char * numero, short * baseOrigen, short * baseDestino, short * mostrar) {
    short * checkPE;
    short * checkPF;
    char * numPE;
    char * numPF;
    char * numPEConvertido;
    char * numPFConvertido;
    char * resultado;

    numPE = parteEntera (numero);
    numPF = parteFraccionaria (numero);
    numPEConvertido = NULL;
    numPFConvertido = NULL;
    checkPE = verificarNumero (numPE,baseOrigen);
    checkPF = verificarNumero (numPF,baseOrigen);

    if (*checkPE == 1 && *checkPF == 1 && strlen(numPE) <= 10 && strlen(numPF) <= 5) {
        numPEConvertido = convertirParteEntera (numPE, baseOrigen, baseDestino, mostrar);
        if (strlen (numPF) != 0) {
            numPFConvertido = convertirParteFraccionaria (numPF, baseOrigen, baseDestino, mostrar);
        }

        if (numPFConvertido == NULL || atoi(numPFConvertido) == 0) {
            resultado = numPEConvertido;
        }
        else {
            resultado = strcat (strcat (numPEConvertido, "."), numPFConvertido);
        }

    } else {
        printf ("El numero no verifica las condiciones de su base origen: %i.", *baseOrigen);
        exit (EXIT_FAILURE);
    }

    free (checkPE);
    free (checkPF);
    free (numPE);
    free (numPF);
    free (numPFConvertido);

    return resultado;
}
