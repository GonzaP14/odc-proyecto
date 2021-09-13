#include <stdio.h>
#include <stdlib.h>

int main () {
    int base = 8;
    char num [] = "7654";

    char * np = &num ;
    double * res;

    res = metodoMultiplicacion(np , &base);
    printf("%lf" , *res);
    return 0;
}
