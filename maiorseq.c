#include <stdio.h>

void main(){
    int tamanho;
    scanf("%d", &tamanho);
    int numeros[tamanho];
    for (int i = 0; i < tamanho; i++){
        scanf("%d", &numeros[i]);
    }
    // leitura do input

    int iInicial, iFinal;
    int iInicialAux, iFinalAux;
    int maiorseq = 0;
    int contador = 0;

    for (int i = 0; i < tamanho-1; i++){
        if (contador == 0){ // defino o indice inicial caso ainda nao tenha sido definido
            iInicialAux = i; // comeca no i
        }

        if (numeros[i+1] > numeros[i]){ // verifica se é uma sequencia crescente
            // aumenta o tamanho e atualiza o indice final para o indice atual + 1
            contador ++; 
            iFinalAux = i+1; // por isso I+1
        } else { // se a sequencia nao é crescente, cabou e o tamanho é zerado para a proxima sequencia
            contador = 0;
        }

        if (contador > maiorseq){ //  maior sequencia comeca em 0, caso o contador ultrapasse ela, os params sao atualizados
            printf("o contador está em: %d\n", contador);
            maiorseq = contador;
            iInicial = iInicialAux;
            iFinal = iFinalAux;
        }
    }

    // printar
    for (int i = iInicial; i < iFinal + 1; i++){
        printf("%d ", numeros[i]);
    }
    printf("\n");
}