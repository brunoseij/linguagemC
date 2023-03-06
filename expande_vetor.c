#include <stdio.h>
#include <stdlib.h>

int getTamanhoExpandido(const int vetor[], int n_compactado){
    int tamanho = 0;
    for (int i = 1; i < n_compactado; i += 2){
        tamanho += vetor[i];
    }
    return tamanho;
}

int *expandir_vetor(const int *vetor, int n_compactado, int *n_expandido){
    *n_expandido = getTamanhoExpandido(vetor, n_compactado);
    int *expandido = malloc(sizeof(int) * (*n_expandido));
    int valorAtual, qtdAtual, somaTamanho;
    valorAtual = qtdAtual = somaTamanho = 0;
    // fazer a expansão

    for (int i = 0; i < n_compactado; i++){
        if (i % 2 == 0){
            valorAtual = vetor[i];
        } else {
            qtdAtual = vetor[i];
            
            for (int j = somaTamanho; j < qtdAtual + somaTamanho; j++){// indice expandido ta crescendo tambem
                expandido[j] = valorAtual;
            }
            somaTamanho += qtdAtual;
        }
    }
    return expandido;
}

void main(){
    int vetor[] = {10, 5, 50, 2, 10, 3, 90, 1};
    int tamanho = 8;
    int n_expandido = 0;
    int *v_expandido;
    v_expandido = expandir_vetor(vetor, tamanho, &n_expandido);
    printf("%d\n", n_expandido);
    
    for (int i = 0; i<n_expandido; i++) {
        printf("%d\n", v_expandido[i]);
    }

    free(v_expandido);
}