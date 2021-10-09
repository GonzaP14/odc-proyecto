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

    numeroAsignado = (short *) malloc (sizeof (short));
    baseOrigen = (short *) malloc (sizeof (short));
    baseDestino = (short *) malloc (sizeof (short));
    verbose = (short *) malloc (sizeof (short));
    help = (short *) malloc (sizeof (short));
    contador = (short *) malloc (sizeof (short));

    *numeroAsignado = 0;
    *baseOrigen = 0;
    *baseDestino = 0;
    *verbose = 0;
    *help = 0;
    *contador = 1;

    if (argc <= 9) {
        while (*contador <= argc ) {
            if (strcmp (argv [*contador], "-n" ) == 0 && *numeroAsignado == 0) {
                *numeroAsignado = 1;
                numero = argv [*contador + 1];
                printf("%s\n",numero);
            }

            if (strcmp (argv [*contador], "-s") == 0 && *baseOrigen == 0) {
                *baseOrigen = atoi (argv [*contador + 1]);
                printf("%hd\n",*baseOrigen);
            }

            if (strcmp (argv [*contador], "-d") == 0 && *baseDestino == 0) {
                *baseDestino = atoi (argv [*contador + 1]);
                printf("%hd\n",*baseDestino);
            }

            if (strcmp (argv [*contador], "-v") == 0 && *verbose == 0) {
                *verbose = 1;
                printf("%hd\n",*verbose);
            }

            if (strcmp (argv [*contador], "-h") == 0 && *help == 0) {
                *help = 1;
                printf("%hd\n",*help);
            }
            *contador += 1;
        }
        if (*baseOrigen == 0) {
            *baseOrigen = 10;
        }

        if (*baseDestino == 0) {
            *baseDestino = 10;
        }
        printf(".%s.",numero);

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
    free(numeroAsignado);

    while (*contador > 0) {
        *contador -= 1;
        free (argv [*contador]);
    }

    free (argv);

    return EXIT_SUCCESS;
}
