
#include <stdio.h>
#include <stdlib.h>

void verificarNumeroBase2a10 (char * numero, int * baseOrigen, int * resultado) {
    while ((*numero) != '\0') {
        if (! ( ( (*numero) >= '0') && (*numero) < ('0' + *baseOrigen) )) {
            * resultado = 0;
            break;
        }

        numero ++;
    }
}

void verificarNumeroBase11a16 (char * numero, int * baseOrigen, int * resultado) {
    while ((*numero) != '\0') {

        if (!(( (*numero) >= '0' && (*numero) < ('0' + *baseOrigen)) || ((* numero) >= 'A' && (*numero) < ('A' + *baseOrigen - 10)) || ((* numero) >= 'a' && (*numero) < ('a' + *baseOrigen - 10)))) {
            * resultado = 0;
            break;
        }

        numero ++;
    }
}

int * verificarNumero (char * numero, int * baseOrigen) {
    int * resultado;
    char * numeroAux;

    resultado = (int *) malloc (sizeof (int));
    * resultado = 1;
    numeroAux = numero;

    if ((* baseOrigen) > 16) {
        * resultado = 0;
    } else if ((* baseOrigen) < 10) {
        verificarNumeroBase2a10 (numeroAux, baseOrigen, resultado);
    } else {
        verificarNumeroBase11a16 (numeroAux, baseOrigen, resultado);
    }

    return resultado;
}
