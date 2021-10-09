#ifndef CONVERSOR_H_INCLUDED
#define CONVERSOR_H_INCLUDED
/**
@file Validacion.h
@version 1.0
@date 09/10/2021
@author: Gonzalo Martin Perez y Nicolas Messina.
*/

/**
Se separa la parte entera del numero para proximos metodos
@param: numero Numero del cual vamos a obtener la parte entera
@return: Puntero a char asociado a la parte entera del numero ingresado
*/
char * parteEntera (char * numero);
/**
Se separa la parte fraccionaria del numero para proximos metodos
@param: numero Numero del cual vamos a obtener la parte fraccionaria
@return: Puntero a char asociado a la parte fraccionaria del numero ingresado
*/
char * parteFraccionaria (char * numero);
/**
Metodo con el cual convertimos la parte entera de la baseOrigen a la baseDestino
@param: numPE Parte entera del numero
@param: baseOrigen Base de la cual partimos para hacer la conversion de la parte entera
@param: baseDestino Base a la cual vamos a llegar con la conversion de la parte entera
@param: mostrar Es utilizado para saber si debemos hacer el verbose o no en el metodo
@return: Puntero a char asociado al resultado de las conversiones correspondientes de la parte entera del numero ingresado
*/
char * convertirParteEntera (char * numPE, short * baseOrigen, short * baseDestino, short * mostrar);
/**
Metodo con el cual convertimos la parte fraccionaria de la baseOrigen a la baseDestino
@param: numPF Parte fraccionaria del numero
@param: baseOrigen Base de la cual partimos para hacer la conversion de la parte fraccionaria
@param: baseDestino Base a la cual vamos a llegar con la conversion de la parte fraccionaria
@param: mostrar Es utilizado para saber si debemos hacer el verbose o no en el metodo
@return: Puntero a char asociado al resultado de las conversiones correspondientes de la parte fraccionaria del numero ingresado
*/
char * convertirParteFraccionaria (char * numPF, short * baseOrigen, short * baseDestino, short * mostrar);
/**
Metodo con el cual convertimos el numero de la baseOrigen a la baseDestino
@param: numero Numero a convertir
@param: baseOrigen Base de la cual partimos para hacer la conversion
@param: baseDestino Base a la cual vamos a llegar con la conversion
@param: mostrar Es utilizado para saber si debemos hacer el verbose o no en el metodo
@return: Puntero a char asociado al resultado de las conversiones correspondientes del numero ingresado
*/
char * convertir (char * numero, short * baseOrigen, short * baseDestino,short* mostrar);

#endif // CONVERSOR_H_INCLUDED
