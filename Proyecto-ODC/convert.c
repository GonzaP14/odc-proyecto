#include <stdio.h>
#include <stdlib.h>
#include "metodoMultiplicacion.h"

int main () {
    char num [7] = "ABCDEF";
    char * pNum = &num [0];
    short base = 16;

    // int b = 0xFAFA;

    long * resultado;

    resultado = parteEnteraSourceA10 (pNum, &base);

    printf ("Numero inicial [base %i] = %s \n", base, num);
    printf ("Numero convertido [base 10] = %li \n", *resultado);

    // printf ("%i",b);

    free (resultado);
}
