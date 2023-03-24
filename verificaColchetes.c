#include <stdio.h>
#include "pilha.h"

char par(char atual) {
    switch (atual) {
        case '{':
            return '}';
        case '[':
            return ']';
        case '(':
            return ')';
        case '}':
        case ']':
        case ')':
            return 'f';
        default:
            return 'n';
    }
}

int verificarColchetes(char* expressao) {
    PilhaDinamica* pilha = criar_pilha();

    for (int i = 0; expressao[i] != '\0'; i++) {
        if (par(expressao[i]) == 'f') {
            if (pilha->topo == NULL || expressao[i] != par(pilha->topo->data)) {
                liberar_pilha(pilha);
                return 0;
            }
            desempilhar(pilha);
        } else if (par(expressao[i]) != 'n') {
            empilhar(pilha ,expressao[i]);
        }
    }

    if (pilha->topo) {
        liberar_pilha(pilha);
        return 0;
    }

    liberar_pilha(pilha);
    return 1;
}


int main() {
    char expressao[100+1];
    scanf("%c", &expressao);
    int resultado = verificarColchetes(expressao);
    if (resultado == 1) {
        printf("SIM\n");
    } else {
        printf("NAO\n");
    }
    return 0;
}