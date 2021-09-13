char * metodoDivision(int* numero , int* baseDestino ){
    int* numeroAux;
    int* sizeNumero;
    char* resultado;
    numeroAux = numero;
    *cocienteDivision = 0;
    *sizeNumero = 0;
    resultado = (char*) malloc(sizeof(char));
    while( *numeroAux > 0 ){
        if(*baseDestino <= 10)
            *resultado = *numeroAux % 10;
        else
            convertirLetra(resultado);
        *numeroAux = *numeroAux / 10;
        resultado++;
        *sizeNumero++;
    }
    invertirNumero(resultado , sizeNumero);
    return resultado;
}

char * convertirLetra ( char* numero ){
    char* resultado;
    *resultado = 'A' + *numero - 10;
    return resultado;
}

void invertirNumero(char* numero , int* sizeNumero ){
    char* aux;
    *sizeNumero--;
    while(*sizeNumero / 2 != 0){
        *aux = *numero;
        *numero = (*numero) + (*sizeNumero);
        (*numero) + (*sizeNumero) = *aux;
        *sizeNumero++;
    }
}
