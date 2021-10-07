#ifndef CONVERSOR_H_INCLUDED
#define CONVERSOR_H_INCLUDED

char * parteEntera (char * numero);
char * parteFraccionaria (char * numero);
char * convertirParteEntera (char * numPE, short * baseOrigen, short * baseDestino, short * mostrar);
char * convertirParteFraccionaria (char * numPF, short * baseOrigen, short * baseDestino, short * mostrar);
char * convertir (char * numero, short * baseOrigen, short * baseDestino,short* mostrar);

#endif // CONVERSOR_H_INCLUDED
