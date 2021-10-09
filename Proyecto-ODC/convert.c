#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Conversor.h"

int main (int argc, char ** argv) {
    char * numero;
    char * resultado;
    short * baseOrigen;
    short * baseDestino;
    short * verbose;
    short * help;
    short * contador;
    short * numeroAsignado;
    short * cantidadDeParametros;

    numeroAsignado = (short *) malloc (sizeof (short));
    baseOrigen = (short *) malloc (sizeof (short));
    baseDestino = (short *) malloc (sizeof (short));
    verbose = (short *) malloc (sizeof (short));
    help = (short *) malloc (sizeof (short));
    contador = (short *) malloc (sizeof (short));
    cantidadDeParametros = (short *) malloc (sizeof (short));

    *numeroAsignado = 0;
    *baseOrigen = 0;
    *baseDestino = 0;
    *verbose = 0;
    *help = 0;
    *contador = 1;
    *cantidadDeParametros = 0;

    if (argc <= 9) {
        while (*contador <= argc ) {
            if (*numeroAsignado == 0 && strcmp (argv [*contador], "-n" ) == 0 ) {
                *cantidadDeParametros+= 2;
                *numeroAsignado = 1;
                numero = argv [*contador + 1];
            }

            if (*baseOrigen == 0 && strcmp (argv [*contador], "-s") == 0) {
                *cantidadDeParametros += 2;
                *baseOrigen = atoi (argv [*contador + 1]);
            }

            if (*baseDestino == 0 && strcmp (argv [*contador], "-d") == 0 ) {
                *cantidadDeParametros += 2;
                *baseDestino = atoi (argv [*contador + 1]);
            }

            if (*verbose == 0 && strcmp (argv [*contador], "-v") == 0 ) {
                *cantidadDeParametros += 1;
                *verbose = 1;
            }

            if (*help == 0 && strcmp (argv [*contador], "-h") == 0 ) {
                *cantidadDeParametros += 1;
                *help = 1;
            }
            *contador += 1;
        }
        if (*baseOrigen == 0) {
            *baseOrigen = 10;
        }

        if (*baseDestino == 0) {
            *baseDestino = 10;
        }
        printf("hola");
        resultado = convertir (numero, baseOrigen, baseDestino, verbose);

        printf ("El numero %s en base %hd es igual a %s en base %hd.", numero, *baseOrigen, resultado, *baseDestino);
    }
    else if (argc > 9) {
        printf ("Error: La cantidad de argumentos ingresada. ");
    }
    free (resultado);
    free (baseOrigen);
    free (baseDestino);
    free (verbose);
    free (help);
    free(numeroAsignado);
    while (*cantidadDeParametros > 0) {
        *cantidadDeParametros -=1;
        free (argv [*cantidadDeParametros]);
    }

    free (argv);

    return EXIT_SUCCESS;
}
