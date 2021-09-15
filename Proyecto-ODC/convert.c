#include <stdio.h>
#include <stdlib.h>
#include "metodoDivision.h"
int main () {
    short int* base;
    long int* numero;
    short int* caca;
    numero = (long int*) malloc(sizeof(long int));
    base = (short int*) malloc(sizeof(short int));
    caca = (short int*) malloc(sizeof(short int));
    *caca = 1;
    *numero = 32680;
    *base = 16;
    char * res;
    res = metodoDivision(numero,base,caca);
    for(int i = 0;i < 4 ; i++){
        printf("%i" , *res);
        res++;
    }
    free(res);
    free(numero);
    free(base);
    free(caca);
    return 0;
}
