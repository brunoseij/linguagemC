#include <stdlib.h>
#include <stdio.h>

typedef struct PilhaDinamica PilhaDinamica;
typedef struct LinkedNode LinkedNode;

struct LinkedNode {
    char data;
    LinkedNode *next;
};

struct PilhaDinamica {
    LinkedNode *topo;
};

PilhaDinamica *criar_pilha() {
    PilhaDinamica *pilha = malloc(sizeof(PilhaDinamica));
    pilha->topo = NULL;
    return pilha;
}

int empilhar(PilhaDinamica *pilha, char valor) {
    LinkedNode *novo = malloc(sizeof(LinkedNode));
    novo->next = NULL;
    novo->data = valor;
    if (pilha->topo) {
        novo->next = pilha->topo;
    }
    pilha->topo = novo;
    return 1;
}

int desempilhar(PilhaDinamica *pilha) { // recebo o endereco de memoria da variavel q guarda o valor
    if (!pilha->topo) return 0;
    
    LinkedNode *antigoTopo = pilha->topo;
    if (pilha->topo->next) {
        pilha->topo = pilha->topo->next;
    } else {
        pilha->topo = NULL;
    }
    free(antigoTopo);
    return 1;
}

void liberar_pilha(PilhaDinamica *pilha) {
    int retorno = 1;
    while (retorno == 1){
       retorno = desempilhar(pilha);
    }
    free(pilha);
}

void printarPilha(PilhaDinamica *pilha) {
    LinkedNode* atual = pilha->topo;

    while (atual->next) {
        printf("%c ", atual->data);
        atual = atual->next;
    }
    printf("%c ", atual->data);
    printf("\n"); 
}