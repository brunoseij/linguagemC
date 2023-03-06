void verificar_adj(int l, int c, int nLinhas, int nColunas, int matriz[nLinhas][nColunas], int valor){
    if (matriz[l+1][c] == valor && l+1 <= nLinhas) {
        remover_adj(l + 1, c, nLinhas, nColunas, matriz);
    }
    if (matriz[l-1][c] == valor && l-1 > 0) {
        remover_adj(l - 1, c, nLinhas, nColunas, matriz);
    }
    if (matriz[l][c+1] == valor && c + 1 <= nColunas) {
        remover_adj(l, c + 1, nLinhas, nColunas, matriz);
    }
    if (matriz[l][c - 1] == valor && c-1 >= 0) {
        remover_adj(l, c - 1, nLinhas, nColunas, matriz);
    }
}


void remover_adj(int l, int c, int nLinhas, int nColunas, int matriz[nLinhas][nColunas]){
    int valor = matriz[l][c];
    matriz[l][c] = 0;

    if (matriz[l+1][c] == valor && l+1 <= nLinhas) {
        remover_adj(l + 1, c, nLinhas, nColunas, matriz);
    }
    if (matriz[l-1][c] == valor && l-1 > 0) {
        remover_adj(l - 1, c, nLinhas, nColunas, matriz);
    }
    if (matriz[l][c+1] == valor && c + 1 <= nColunas) {
        remover_adj(l, c + 1, nLinhas, nColunas, matriz);
    }
    if (matriz[l][c - 1] == valor && c-1 >= 0) {
        remover_adj(l, c - 1, nLinhas, nColunas, matriz);
    }
}