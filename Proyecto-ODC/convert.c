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

    baseOrigen = (short *) malloc (sizeof (short));
    baseDestino = (short *) malloc (sizeof (short));
    verbose = (short *) malloc (sizeof (short));
    help = (short *) malloc (sizeof (short));
    contador = (short *) malloc (sizeof (short));

    *baseOrigen = 0;
    *baseDestino = 0;
    *verbose = 0;
    *help = 0;

    if (argc <= 9) {

        while (*contador < argc) {
            if (strcmp (argv [*contador], "-n")) {
                numero = argv [*contador + 1];
            }

            if (strcmp (argv [*contador], "-s")) {
                *baseOrigen = atoi (argv [*contador + 1]);
            }

            if (strcmp (argv [*contador], "-d")) {
                *baseDestino = atoi (argv [*contador + 1]);
            }

            if (strcmp (argv [*contador], "-v")) {
                *verbose = 1;
            }

            if (strcmp (argv [*contador], "-h")) {
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

        resultado = convertir (numero, baseOrigen, baseDestino, verbose);

        printf ("El numero %s en base %hd es igual a %s en base %hd.", numero, *baseOrigen, resultado, *baseDestino);
    }

    else if (argc > 9) {
        printf ("Error: La cantidad de argumentos ingresada. ");
    }
    else {
        printf ("Se necesita que ingrese un argumento.");
    }

    free (resultado);
    free (baseOrigen);
    free (baseDestino);
    free (verbose);
    free (help);

    while (*contador > 0) {
        *contador -= 1;
        free (argv [*contador]);
    }

    free (argv);

    return EXIT_SUCCESS;
}
