#include <stdlib.h>
#include <stdio.h>

typedef struct PilhaDinamica PilhaDinamica;
typedef struct LinkedNode LinkedNode;

struct LinkedNode {
    int data;
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

int empilhar(PilhaDinamica *pilha, int valor) {
    LinkedNode *novo = malloc(sizeof(LinkedNode));
    novo->next = NULL;
    novo->data = valor;
    if (pilha->topo) {
        novo->next = pilha->topo;
    }
    pilha->topo = novo;
    return 1;
}

int desempilhar(PilhaDinamica *pilha, int *valor) { // recebo o endereco de memoria da variavel q guarda o valor
    if (!pilha->topo) return 0;
    
    LinkedNode *antigoTopo = pilha->topo;
    if (pilha->topo->next) {
        *valor = pilha->topo->data;
        pilha->topo = pilha->topo->next;
    } else {
        *valor = pilha->topo->data;
        pilha->topo = NULL;
    }
    free(antigoTopo);
    return 1;
}

void liberar_pilha(PilhaDinamica *pilha) {
    int retorno = 1;
    while (retorno == 1){
        retorno = desempilhar(pilha,&retorno);
    }
}

void main() {
    PilhaDinamica *pilha;
    pilha = criar_pilha();
    int valorTopo = 0;
    empilhar(pilha, 30);
    valorTopo = pilha->topo->data;
    printf("%d\n", valorTopo);
    empilhar(pilha, 150);
    valorTopo = pilha->topo->data;
    liberar_pilha(pilha);
    printf("%d\n", valorTopo);
    desempilhar(pilha, &valorTopo);
    printf("%d\n", valorTopo);
    desempilhar(pilha, &valorTopo);
    //valorTopo = pilha->topo->data;
    printf("%d\n", desempilhar(pilha, &valorTopo));
    //liberar_pilha(pilha);
    // printf("topo: %d\n", desempilhar(pilha, &(valorTopo)));
    // printf("topo: %d\n", desempilhar(pilha, &(valorTopo)));
    // printf("topo: %d\n", desempilhar(pilha, &(valorTopo)));
    // printf("topo: %d\n", valorTopo);
    free(pilha);
}