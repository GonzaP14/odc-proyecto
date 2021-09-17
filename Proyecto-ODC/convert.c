#include <stdio.h>
#include <stdlib.h>
#include "metodoDivisionPE.h"
#include "metodoDivisionPF.h"
int main () {
    //Prueba metodoDivisionPE
    /*short int* base;
    long int* numero;
    short int* hola;
    numero = (long int*) malloc(sizeof(long int));
    base = (short int*) malloc(sizeof(short int));
    hola = (short int*) malloc(sizeof(short int));
    *hola = 1;
    *numero = 32680;
    *base = 16;
    char * res;
    res = metodoDivisionPE(numero,base,hola);
    for(int i = 0;i < 4 ; i++){
        printf("%c" , *(res + i));
    }
    free(res);
    free(numero);
    free(base);
    free(hola);*/
    //Prueba metodoDivisionPF
    short int* baseOrigen;
    short int* chau;
    double* resultado;
    char* np;
    np = (char*) malloc(sizeof(char));
    *np = "7632";
    chau = (short int*) malloc(sizeof(short int));
    baseOrigen = (short int*) malloc(sizeof(short int));
    *chau = 1;
    *baseOrigen = 8;
    resultado = metodoDivisionPF(np,baseOrigen,chau);
    printf("%lf" , *resultado);
    free(np);
    free(baseOrigen);
    free(resultado);
    free(chau);
    return 0;
}
