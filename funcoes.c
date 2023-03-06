#include <stdio.h>

// prototipos de funcoes são necessários quando as funções se encontram acima de onde elas são chamadas
int soma(int n1, int n2);

char proximoCaractere(char caractere){
    return caractere + 1;
}

void main(){
    char caractere = 'A';
    printf("%c\n", proximoCaractere(caractere));

    int n1 = 4;
    int n2 = 8;
    int res;
    res = soma(n1, n2);
    printf("%d\n", res);
}

int soma(int n1, int n2){
    return n1 + n2;
}