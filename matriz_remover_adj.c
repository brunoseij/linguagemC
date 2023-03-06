#include <stdio.h>

void printar(int nLinhas, int nColunas, int matriz[nLinhas][nColunas]){
    for (int linha = 0; linha < nLinhas; linha++){
        for (int coluna = 0; coluna < nColunas; coluna ++){ // percorre os elementos um por um em cada linha
            
            printf("%d ", matriz[linha][coluna]);
        }
        printf("\n");
    }
}

void remover_adj(int l, int c, int nLinhas, int nColunas, int matriz[nLinhas][nColunas]){
    int valor = matriz[l][c];
    matriz[l][c] = 0;

    if (matriz[l+1][c] == valor && l+1 <= nLinhas) {
        remover_adj(l + 1, c, nLinhas, nColunas, matriz);
    }
    if (matriz[l-1][c] == valor && l-1 >= 0) {
        remover_adj(l - 1, c, nLinhas, nColunas, matriz);
    }
    if (matriz[l][c+1] == valor && c + 1 <= nColunas) {
        remover_adj(l, c + 1, nLinhas, nColunas, matriz);
    }
    if (matriz[l][c - 1] == valor && c-1 >= 0) {
        remover_adj(l, c - 1, nLinhas, nColunas, matriz);
    }
}

void main(){
    int l = 3;
    int c = 3;
    int nLinhas = 4;
    int nColunas = 4;
    int matriz[4][4] = {
                        {1, 12, 44, 11},
                        {1, 1, 44, 24},
                        {31, 1, 1, 1},
                        {44, 44, 43, 1}};

    remover_adj(3, 3, 4, 4, matriz);
    printar(4, 4, matriz);

    l = 4;
    c = 2;
    nLinhas = 5;
    nColunas = 5;
    int matriz2[5][5] = {
                        {1, 12, 44, 14, 11},
                        {1, 1, 44, 24, 13},
                        {31, 1, 1, 11, 11},
                        {11, 44, 11, 1, 15},
                        {11, 11, 11, 11, 21}};

    remover_adj(4, 2, 5, 5, matriz2);
    printar(5, 5, matriz2);
}