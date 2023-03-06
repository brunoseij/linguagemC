#include <stdio.h>
#include "matem.h"

// lembrar de incluir as dependencias na compilacao do gcc

void main(){
    int n1, n2;
    n1 = 1000;
    n2 = 139;
    int soma = somar(n1, n2);
    int sub = subtrair(n1, n2);
    int mult = multiplicar(n1, n2);
    float div = dividir(n1, n2);
    printf("%d, %d, %d, %.2f\n", soma, sub, mult, div);
}