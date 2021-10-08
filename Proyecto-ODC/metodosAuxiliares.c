#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convertirCaracter (short * digitoActual, char * numeroAux) {
    if (*numeroAux >= '0' && *numeroAux <= '9'){
        *digitoActual = *numeroAux- '0';
    }
    else if (*numeroAux >= 'A' && *numeroAux <= 'F'){
        *digitoActual = *numeroAux - 55;
    }
    else if (*numeroAux >= 'a' && *numeroAux <= 'f'){
        *digitoActual = *numeroAux - 87;
    }
}

void convertirLetra (char * numero ){
    char* resultado;

    resultado = numero;

    if(*resultado >= 10 && *resultado < 16){
        *resultado = 'A' + *resultado - 10;
    }
}
