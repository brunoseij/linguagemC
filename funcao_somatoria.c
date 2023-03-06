#include <stdio.h>
void teste(int a, int b, int *resultado) {
    int somatoria = 0;
    int soma = 0;
    for(int i = 1; i < a+1; i++) {
        for(int j = 1; j < b + 1; j++) {
            soma += i*j+10;
        }
        somatoria += 5*i * (soma); // primeiro faz o de dentro, depois faz o de fora
        soma = 0; // nao pode esquecer de zerar o resultado do de dentro
    }
    printf("%d\n", somatoria);
    *resultado = somatoria;
}
void main() {
    int a = 2;
    int b = 3; // 600
    int resultado;

    teste(a, b, &resultado);
    printf("%d\n", resultado);
}