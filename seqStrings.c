#include <stdio.h>

char minusculo(char caractere){
    if (caractere >= 65 && caractere <= 90){ // 65 a 90 são letras maiusculas da tabela ASCII
            return caractere + 32; // olhar na tabela ASCII
    }
    return caractere;
}

int getTamanhoString(const char str[]){
    int i = 0;
    for (i; str[i] != '\0'; i++){}
    return i+1;
}

void frequencia_string(const char *palavra, const char *texto, int *qtd){
    char cTexto, cPalavra;
    int j, quantPalavras, tamanhoPalavra; // j é o indice da palavra
    j = quantPalavras = 0;

    tamanhoPalavra = getTamanhoString(palavra); // retorna o tamanho da palavra passada

    for (int i = 0; texto[i] != '\0'; i++){
        cTexto = minusculo(texto[i]); // não é case sensitive
        cPalavra = minusculo(palavra[j]);

        if (cTexto == cPalavra){
            if (j == tamanhoPalavra - 1){ // indice começa do 0, por isso precisa colocar o -1
                // chegou ao final da palavra passada, somar um na quantidade e zerar
                quantPalavras ++;
                j = 0;
            } else if(j + 1 < tamanhoPalavra){
                j++; // avanca uma posicao na palavra
            }
        } else{
            j = 0; // indice q percorre a palavra passada
        }
    }
    
    *qtd = quantPalavras;
}

void main(){
    const char palavra[] = "test";
    const char texto[] = "teste Teste tesTE t3ste testando test";
    int qtd;

    frequencia_string(palavra, texto, &qtd);
    printf("%d\n", qtd);
}