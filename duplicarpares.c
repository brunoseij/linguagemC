#include <stdio.h>
#include <stdlib.h>


typedef struct LinkedNode LinkedNode;
struct LinkedNode {
   int data;
   LinkedNode *next;
};

typedef struct DLinkedNode DLinkedNode;
struct DLinkedNode {
   int data;
   DLinkedNode *next, *prev;
};

void duplicar_pares1(LinkedNode *inicio){
    if (inicio->data % 2 == 0){
        LinkedNode *copia = malloc(sizeof(LinkedNode));
        copia->data = inicio->data;
        copia->next = inicio->next;
        inicio->next = copia;

        if (copia->next) {
            duplicar_pares1(copia->next);
        }
        return;
    }
    
    if (inicio->next) {
        duplicar_pares1(inicio->next);
    }
}


void duplicar_pares2(DLinkedNode *inicio){
    if (inicio->data % 2 == 0) {
        DLinkedNode *copia = malloc(sizeof(DLinkedNode));
        copia->data = inicio->data;
        copia->next = inicio->next;
        copia->prev = inicio;
        if (inicio->next) {
            inicio->next->prev = copia;
        }
        inicio->next = copia;

        if (copia->next) {
            duplicar_pares2(copia->next);
        }
        return;
    }

    if (inicio->next){
        duplicar_pares2(inicio->next);
    }
}

void printarFila(LinkedNode *inicio) {
    printf("%d ", inicio->data);
    if (inicio->next) {
        printarFila(inicio->next);
    } else {
        printf("\n");
    }
}

void printarFila2(DLinkedNode *inicio) {
    printf("%d ", inicio->data);
    if (inicio->next) {
        printarFila2(inicio->next);
    } else {
        printf("\n");
    }
}

void main() {
    LinkedNode d1 = {6};
    LinkedNode d2 = {2};
    LinkedNode d3 = {3};
    LinkedNode d4 = {4};

    d1.next = &d2;
    d2.next = &d3;
    d3.next = &d4;

    duplicar_pares1(&d1);
    printarFila(&d1);

    DLinkedNode dd1 = {6};
    DLinkedNode dd2 = {2};
    DLinkedNode dd3 = {3};
    DLinkedNode dd4 = {4};

    dd1.next = &dd2;
    dd2.next = &dd3;
    dd3.next = &dd4;
    dd4.prev = &dd3;
    dd3.prev = &dd2;
    dd2.prev = &dd1;

    duplicar_pares2(&dd1);
    printarFila2(&dd1);
}