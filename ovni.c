#include <stdio.h>
#include <stdlib.h>

// Modelo_A1, Modelo_B1...
// A, B, C, D são fabricantes
// discos é um vetor de strings
// formar um vetor com a quantidade por fabricante
// quantidade_fabricante deve ser um vetor contendo o endereco de memoria de variaveis com a quantidade de vendas de cada um dos fabricantes
char fabricante(char *disco){
    for (int i = 0; disco[i] != '\0'; i++){
        if (disco[i] >= 65 && disco[i] <= 68 && disco[i-1] == 95){
            return disco[i];
        }
    }
}

void quantidade_discos(char **discos, int n_discos, int **quantidade_fabricante){
    int A, B, C, D;
    A = B = C = D = 0;
    char fabricanteAtual = ' ';

    for (int i = 0; i < n_discos; i++){
        fabricanteAtual = fabricante(discos[i]);

        switch(fabricanteAtual){    
            case 'A':
                A++; 
                break;
            case 'B':
                B++;
                break;   
            case 'C':
                C++;
                break;
            case 'D':
                D++;
                break;
        }
    }

    int *vetor = malloc(sizeof(int) * 4);
    vetor[0] = A;
    vetor[1] = B;
    vetor[2] = C;
    vetor[3] = D;
    quantidade_fabricante[0] = vetor;
}

void main() {
    char *discos[7] = {
        "Modelo_A1", "Modelo_B1", "Modelo_C1", 
        "Modelo_D1", "Modelo_D1", "Modelo_D2", 
        "Modelo_A1"};
    int *quantidade_fabricante[1];
    
    quantidade_discos(discos, 7, quantidade_fabricante);
    for (int i = 0; i < 4; i++){
        printf("%d\n", quantidade_fabricante[0][i]);
    }
}