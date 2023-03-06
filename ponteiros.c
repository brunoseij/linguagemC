#include <stdio.h>

void incrementar(int* contador){ // recebendo um endereço de memória
    printf("%d\n", contador);
    // valor apontado pelo endereço de memoria ++
    (*contador) ++; // parenteses é essencial nesse caso
}

void main(){
    int contador = 10;
    printf("%d\n", contador);
    incrementar(&contador); // passando o endereço de memória
    printf("%d\n", &contador);
    printf("%d\n", contador);
}