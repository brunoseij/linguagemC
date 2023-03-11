#include <stdio.h>


typedef struct LinkedNode LinkedNode;
struct LinkedNode {
    int data;
    LinkedNode *next;
};

void contar(LinkedNode *inicio, int *qtd, int *soma) {
    *soma += inicio->data;
    *qtd += 1;
    if (inicio->next){
        contar(inicio->next, qtd, soma);
    } 
}

void imprimir1(LinkedNode *inicio) {
    printf("%d\n", inicio->data);
    if (inicio -> next) imprimir1(inicio -> next);
}

int lenListaLigada(LinkedNode *inicio) {
    LinkedNode *atual = inicio;
    int qtd = 1;
    while (atual->next) {
        qtd ++;
        atual = atual->next;
    }
    return qtd;
}

void imprimir2(LinkedNode *inicio) {
    int qtd = lenListaLigada(inicio);
    int valores[qtd];

    LinkedNode *atual = inicio;
    for (int i = 0; i < qtd; i++) {
        valores[i] = atual->data;
        atual = atual->next;
    }

    for (int i = qtd - 1; i > - 1; i--) {
        printf("%d\n", valores[i]);
    }
}

void main() {
    LinkedNode d1 = {1};
    LinkedNode d2 = {1};
    LinkedNode d3 = {3};
    LinkedNode d4 = {4};

    d1.next = &d2;
    d2.next = &d3;
    d3.next = &d4;
    int qtd = 0;
    int soma = 0;
    contar(&d1, &qtd, &soma);
    printf("soma :%d\ncontagem: %d\n", soma, qtd);
    imprimir1(&d1);
    imprimir2(&d1);
}