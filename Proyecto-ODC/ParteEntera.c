#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validacion.h";
#include "metodoMultiplicacion.h"
#include "metodoDivision.h"



char * cambiarBaseParteEntera (char * numero, short * baseSource, short * baseDestination) {
    int * check;
    long * resultado;

    * check = verificarNumero(numero, baseSource);

    if (*resultado == 0) {
        printf ("El numero ingresado %s no verifica el formato de la base %d.", numero, *baseSource);
    } else {
        *resultado = parteEnteraSourceA10 (numero, baseSource);
        // parteEntera10ADestination (resultado, baseDestination);
        verificarResultadoParteEntera (resultado, baseDestination);
    }
}
