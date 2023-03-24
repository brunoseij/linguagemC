#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedNode LinkedNode;
struct LinkedNode {
   int data;
   LinkedNode *next;
};

typedef struct FilaDinamica FilaDinamica;
struct FilaDinamica {
   LinkedNode *inicio, *fim;
};

FilaDinamica *criar_fila(){
    FilaDinamica *fila = malloc(sizeof(FilaDinamica));
    fila->inicio = NULL;
    fila->fim = NULL;
    return fila;
}

int enfileirar(FilaDinamica *fila, int valor){
    LinkedNode *novo = malloc(sizeof(LinkedNode));
    novo->data = valor;

    if (!fila->inicio) {
        fila->inicio = novo;
        fila->fim = novo;
        return 1;
    }

    fila->fim->next = novo;
    fila->fim = novo;
    return 1;
}

int desenfileirar(FilaDinamica *fila, int *valor){
    // tirar o inicio
    if (!fila->inicio) return 0;
    LinkedNode *inicioAntigo = fila->inicio;
    *valor = fila->inicio->data;

    if (!fila->inicio->next) {
        fila->inicio = NULL;
        fila->fim = NULL;
        free(inicioAntigo);
        return 1;
    }

    fila->inicio = fila->inicio->next;
    free(inicioAntigo);
    return 1;
}

void liberar_fila(FilaDinamica *fila){
    int retorno = 1;
    while (retorno != 0){
        retorno = desenfileirar(fila, &retorno);
    }
    free(fila);
}

void printarFila(LinkedNode *inicio) {
    printf("%d ", inicio->data);
    if (inicio->next) {
        printarFila(inicio->next);
    } else {
        printf("\n");
    }
}

void main() {
    FilaDinamica *fila1 = criar_fila();
    int iniciofila = 0;
    enfileirar(fila1, 10);
    enfileirar(fila1, 10);
    enfileirar(fila1, 10);
    enfileirar(fila1, 20);
    desenfileirar(fila1, &iniciofila);
    desenfileirar(fila1, &iniciofila);
    desenfileirar(fila1, &iniciofila);
    //desenfileirar(fila1, &iniciofila);
    printarFila(fila1->inicio);


    enfileirar(fila1, 10);
    enfileirar(fila1, 10);
    enfileirar(fila1, 10);
    enfileirar(fila1, 20);
    printarFila(fila1->inicio);

    liberar_fila(fila1);
}