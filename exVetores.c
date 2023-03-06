#include <stdio.h>

void ex1();
void ex2();

void main(){
    ex2();
}

void ex1(){
    int A[6] = {1, 0, 5, -2, -5, 7};
    int soma = A[0] + A[1] + A[5];
    printf("A soma das posições 0, 1 e 5 é: %d\n", soma);

    A[4] = 100;

    for (int i = 0; i < 6; i++){
        printf("%d\n", A[i]);
    }
}

void ex2(){
    int v[10];
    int quadrados[10];
    for (int i = 0; i < 10; i++){
        scanf("%d", &v[i]);
    }

    for (int i = 0; i < 10; i++){
        quadrados[i] = v[i] * v[i];
        printf("%d\n", quadrados[i]);
    }
}