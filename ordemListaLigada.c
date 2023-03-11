#include <stdio.h>

typedef struct LinkedNode LinkedNode;

struct LinkedNode {
    int data;
    LinkedNode *next;
};

void atualizarOrdem(LinkedNode *atual, int *ordem) {
    if (atual->data <= atual->next->data && *ordem != 0) {
        *ordem = 1;
        return;
    }
    *ordem = 0;
}
void percorrerLista(LinkedNode *inicio, int *ordem) {
    if (inicio -> next) {
        atualizarOrdem(inicio, ordem);
        percorrerLista(inicio->next, ordem);
    }
}

int verificar_ordenacao(LinkedNode *inicio) {
    int ordem = -1;
    percorrerLista(inicio, &ordem);
    return ordem;
}

void main() {
    LinkedNode d1 = {1};
    LinkedNode d2 = {1};
    LinkedNode d3 = {3};
    LinkedNode d4 = {4};

    d1.next = &d2;
    d2.next = &d3;
    d3.next = &d4;

    int ordem = verificar_ordenacao(&d1);
    printf("%d\n", ordem);
}