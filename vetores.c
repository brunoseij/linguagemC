#include <stdio.h>

void main(){
    // strings -- inicialização é utilizando "Bruno"
    char nome[5+1]; // sempre colocar o +1 por conta do caractere delimitador de string \0
    printf("Digite o seu nome: \n");
    scanf("%s", nome); // scanf não consegue ler mais que uma palavra, para isso utiliza-se outra função (gets)
    
    char saudacao[9+1] = "Tudo bem?";
    printf("Olá, %s! %s\n", nome, saudacao);

    

    // caracteres
    char letras[26];
    char asciiCode = 'a';
    for (int i = 0; i < 26; i++){
        letras[i] = asciiCode;
        asciiCode ++; // é possivel fazer operações aritméticas com caracteres ascii
    }

    for (int i = 0; i < 26; i++){
        printf("%c; ", letras[i]);
    }
    printf("\n");
}