#include <stdio.h>
#include <stdlib.h>

int main () {
    char numero[5] = "1672";
    char* pnum = &numero[0];

    short base = 8;
    short * pb = &base;

    short uno = 1;
    short * pu = &uno;

    long* resultado = parteEnteraOrigenA10( pnum, pb, pu );
    free(resultado);
    return 0;
}
