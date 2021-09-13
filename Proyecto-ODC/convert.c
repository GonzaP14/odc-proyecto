#include <stdio.h>
#include <stdlib.h>

int main () {
    int base = 8;
    char num [] = "1672";

    char * np = &num ;
    int * res;

    res = metodoMultiplicacion(np , &base);
    printf("%i" , *res);
    return 0;
}
