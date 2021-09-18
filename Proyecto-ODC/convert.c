#include <stdio.h>
#include <stdlib.h>
#include "metodoMultiplicacionPF.h"
#include "metodoDivisionPF.h"
int main () {

    char numero [4] = "1010";
    char * pnum = &numero [0];

    short base = 2;
    short * pb = &base;

    short uno = 1;
    short * pu = &uno;

    printf ("Numero %s en base [%i] es igual a %lf en base 10.", numero, *pb, *metodoDivisionPF (pnum, pb, pu));

    return 0;
}
