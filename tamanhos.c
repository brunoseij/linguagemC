#include <stdio.h>

void printarTamanho(int tamanho) {
    printf("O tamanho é: %d\n", tamanho);
}

void main(){
    printarTamanho(sizeof(int));
    printarTamanho(sizeof(int*));
    printarTamanho(sizeof(char));
    printarTamanho(sizeof(char*));
    printarTamanho(sizeof(char**));
    printarTamanho(sizeof(long int*));
}