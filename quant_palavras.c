#include <stdio.h>

void quantidade_palavras(char texto[]){
    int i = 0; // indice para interar pela string
    int contador = 1; // contador de palavras, começa com 1 pq não tem espaço em branco antes da primeira frase
    // nas frases seguintes tem por conta do .

    while (texto[i] != '\0'){ // iterando pela string inteira
        if (texto[i] == '.'){ // caso encontre o ponto final, significa que a frase acabou
            printf("%d\n", contador); // acabou a frase -> printa a quantidade de palavras
            contador = 0; // contador é zerado para a próxima frase
        }

        if (texto[i] == ' '){ // caso encontre algum espaço em branco, é uma nova palavra
            contador++; // contador é aumentado
        }

        i++; // avanca uma posicao na string
    }

}

void main(){
    // note que todas as frases tem a mesma quantidade de espaços e palavras, exceto a primeira que tem um espaço a menos
    char texto[] = "Olá, meu Nome é Bruno. Eu trabalho na Rede. tenho 21 anos. Moro em uma casa na vila campestre, perto do jabaquara.";

    quantidade_palavras(texto);
}