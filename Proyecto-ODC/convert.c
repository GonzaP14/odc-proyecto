#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Conversor.h"

void validarNumero (char * numero, short * check) {
    if ((*numero >= '0' && *numero <= '9') || (*numero >= 'A' && *numero <= 'Z') || (*numero >= 'a' && *numero <= 'z')) {
        *check = 1;
    }
}

void validarBase (char * base, short * check) {

}

void mostrarEntrada (char ** numero) {

}

int main (int argc, char ** argv) {
    char * numero;
    char * resultado;
    short * baseOrigen;
    short * baseDestino;
    short * verbose;
    short * help;
    short * contador;
    short * check;
    short * procesoCompleto;

    baseOrigen = (short *) malloc (sizeof (short));
    baseDestino = (short *) malloc (sizeof (short));
    verbose = (short *) malloc (sizeof (short));
    help = (short *) malloc (sizeof (short));
    contador = (short *) malloc (sizeof (short));
    check = (short *) malloc (sizeof (short));
    procesoCompleto = (short *) malloc (sizeof (short));

    numero = NULL;

    *baseOrigen = 10;
    *baseDestino = 10;
    *verbose = 0;
    *help = 0;
    *contador = 1;
    *check = 0;
    *procesoCompleto = 1;

    printf ("\n");
    printf ("Nombre del programa = %s", argv [0]);
    printf ("\n");
    mostrarEntrada (argv);

    if (argc >= 2 && argc <= 9) {

        while (*contador < argc) {

            if (strcmp (argv [*contador], "-n" ) == 0) {
                // printf ("Asigne -n");
                *contador += 1;
                validarNumero (argv [*contador], check);

                if (*check == 0) {
                    *procesoCompleto = 0;
                    break;
                }

                numero = argv [*contador];

            }

            else if (strcmp (argv [*contador], "-s") == 0) {
                // printf ("Asigne -s");
                *contador += 1;
                validarBase (argv [*contador], check);

                if (*check == 0) {
                    printf ("La base origen '%s' ingresada no es valida. \n", argv [*contador]);
                    *procesoCompleto = 0;
                    break;
                }

                *baseOrigen = atoi (argv [*contador]);
            }

            else if (strcmp (argv [*contador], "-d") == 0 ) {
                // printf ("Asigne -d");
                *contador += 1;
                validarBase (argv [*contador], check);

                if (*check == 0) {
                    printf ("La base destino '%s' ingresada no es valida. \n", argv [*contador]);
                    *procesoCompleto = 0;
                    break;
                }

                *baseDestino = atoi (argv [*contador]);
            }

            else if (strcmp (argv [*contador], "-v") == 0 ) {
                // printf ("Asigne -v");
                *verbose = 1;
            }

            else if (strcmp (argv [*contador], "-h") == 0 ) {
                // printf ("Asigne -h");
                *help = 1;
            }

            else {
                *procesoCompleto = 0;
                break;
            }

            *check = 0;
            *contador += 1;
        }

        if (numero == NULL) {
            printf ("Error: No se ingreso un numero. \n");
            *procesoCompleto = 0;
        }
        else if (*procesoCompleto == 0) {
            printf ("Alguna de las entradas no fue valida.");
        }
        else {
            resultado = convertir (numero, baseOrigen, baseDestino, verbose);
            printf ("El numero %s en base %hd es igual a %s en base %hd. \n", numero, *baseOrigen, resultado, *baseDestino);
        }
    }

    else {
        printf ("Error: La cantidad de argumentos ingresada es incorrecta. \n");
        * procesoCompleto = 0;
    }

    free (resultado);
    free (baseOrigen);
    free (baseDestino);
    free (verbose);
    free (help);
    free (procesoCompleto);
    free (contador);
    free (argv);

    if (*procesoCompleto == 1) {
        return (EXIT_SUCCESS);
    }
    else {
        return (EXIT_FAILURE);
    }
}
