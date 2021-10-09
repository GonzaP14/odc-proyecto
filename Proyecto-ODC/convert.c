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
    short * contador;

    contador = (short *) malloc (sizeof (short));
    *contador = 0;

    while (base [*contador] != '\0'){
        if (base [*contador] >= '0' && base [*contador] <= '9'){
            *check = 1;
            *contador += 1;
        }
        else
            break;
    }

    free (contador);
}

void mostrarEntrada (char * numero , short* baseOrigen , short* baseDestino , short* verbose , short* help) {
    printf("La entrada es: \n");
    printf("Numero : %s\n",numero);
    printf("Base origen : %hd\n",*baseOrigen);
    printf("Base destino : %hd\n",*baseDestino);
    printf("Verbose mode : ");
    if(*verbose == 1){
        printf("Encendido\n");
    }
    else{
        printf("Apagado\n");
    }
    printf("Help : ");
    if(*help == 1){
        printf("Encendido\n\n");
    }
    else{
        printf("Apagado\n\n");
    }
}

void mostrarHelp(){
    printf("MENU DE AYUDA:\nEl programa recibe las siguientes entradas. No importa el orden.\n");
    printf("-n	Indica que la siguiente entrada es el numero a convertir. Es obligatorio.<number> Es el numero que le sigue a -n.\n");
    printf("Asegurese de lo siguiente:\n");
    printf("* Que el numero sea valido en su base de origen.\n");
    printf("* Que la parte entera no posea más de 10 dígitos.\n");
    printf("* Que la parte fraccionaria no posea más de 6 dígitos.\n");
    printf("Es obligatorio para el correcto funcionamiento.\n\n");

    printf("-s	Indica que la siguiente entrada es la base origen del numero ingresado.\n");
    printf("Las bases validas se comprenden entre el siguiente rango: [2..16]\n");
    printf("Si utiliza '-s', debe ingresar una base correcta <number> en el siguiente argumento.\n");
    printf("Si no lo utiliza, el programa utiliza de forma predeterminada base 10.\n");

    printf("-d	Indica que la siguiente entrada es la base destino del numero ingresado.\n");
    printf("Las bases validas se comprenden entre el siguiente rango: [2..16]\n");
    printf("Si utiliza '-d', debe ingresar una base correcta <number> en el siguiente argumento.\n");
    printf("Si no lo utiliza, el programa utiliza de forma predeterminada base 10.\n");

    printf("-v	Indica al programa que se debe ejecutar en modo 'verbose', mostrando los calculos intermedios del proceso de conversion.\n");

    printf("-h	Indica al programa que se debe mostrar el menu de ayuda.\n");

    printf("Para informacion adicional acerca del funcionamiento del programa, consultar el informe especifico.\n\n");
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

    if (argc >= 2 && argc <= 9) {

        while (*contador < argc) {

            if (strcmp (argv [*contador], "-n" ) == 0) {
                *contador += 1;
                validarNumero (argv [*contador], check);

                if (*check == 0) {
                    *procesoCompleto = 0;
                    break;
                }

                numero = argv [*contador];

            }

            else if (strcmp (argv [*contador], "-s") == 0) {
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
                *verbose = 1;
            }

            else if (strcmp (argv [*contador], "-h") == 0 ) {
                *help = 1;
            }

            else {
                *procesoCompleto = 0;
                break;
            }

            *check = 0;
            *contador += 1;
        }
        mostrarEntrada(numero,baseOrigen,baseDestino,verbose,help);
        if( *help == 1 ){
            mostrarHelp();
        }
        if (numero == NULL) {
            printf ("No se ingreso un numero. \n");
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
