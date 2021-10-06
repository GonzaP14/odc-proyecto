#include <stdio.h>
#include <stdlib.h>
#include "metodoMultiplicacionPF.h"
#include "metodoDivisionPF.h"
<<<<<<< HEAD
int main () {

    char numero [4] = "1010";
    char * pnum = &numero [0];
=======

int main () {

    /*
    char * resultado;
    double * numerito;
    short * base;

    //resultado = (char *) malloc (sizeof (char));
    numerito = (double *) malloc (sizeof (double));
    base = (short *) malloc (sizeof (short));

    * base = 16;
    * numerito = (0.9999);
>>>>>>> e36882544bb305e966887c85ccb69eb80c9a5d8a

    short base = 2;
    short * pb = &base;

    short uno = 1;
    short * pu = &uno;

<<<<<<< HEAD
=======
    free (resultado);
    */

    char numero [4] = "7632";
    char * pnum = &numero [0];

    short base = 8;
    short * pb = &base;

    short uno = 1;
    short * pu = &uno;

>>>>>>> e36882544bb305e966887c85ccb69eb80c9a5d8a
    printf ("Numero %s en base [%i] es igual a %lf en base 10.", numero, *pb, *metodoDivisionPF (pnum, pb, pu));

    return 0;
}
