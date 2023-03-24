#include <stdio.h>

typedef struct LinkedNode LinkedNode;
struct LinkedNode {
   int data;
   LinkedNode *next;
};

void inserir(LinkedNode *primeiro, LinkedNode *segundo, LinkedNode *terceiro) {
    primeiro->next = segundo;
    segundo->next = terceiro;
}

void intercalarListas(LinkedNode *inicio1, LinkedNode *inicio2) {
    //printf("caiu aqui");
    printf("")
    if (inicio1->next && inicio2){
        intercalarListas(inicio1->next, inicio2);
    }
}

LinkedNode* intercalar_listas(LinkedNode *inicio1, LinkedNode *inicio2) {
    intercalarListas(inicio1, inicio2);
    return inicio1;
}

void imprimir1(LinkedNode *inicio) {
    //printf("%d\n", inicio->data);
    if (inicio -> next) imprimir1(inicio -> next);
}

void main() {
    LinkedNode d1 = {1};
    LinkedNode d2 = {3};
    LinkedNode d3 = {5};
    LinkedNode d4 = {9};

    d1.next = &d2;
    d2.next = &d3;
    d3.next = &d4;

    LinkedNode e1 = {2};
    LinkedNode e2 = {4};
    LinkedNode e3 = {6};
    LinkedNode e4 = {10};

    e1.next = &e2;
    e2.next = &e3;
    e3.next = &e4;

    LinkedNode *inicio = intercalar_listas(&d1, &e1);
    imprimir1(inicio);
}