typedef struct PilhaDinamica PilhaDinamica;
typedef struct LinkedNode LinkedNode;

struct LinkedNode {
    char data;
    LinkedNode *next;
};

struct PilhaDinamica {
    LinkedNode *topo;
};

PilhaDinamica *criar_pilha();
int empilhar(PilhaDinamica *pilha, int valor);
int desempilhar(PilhaDinamica *pilha);
void liberar_pilha(PilhaDinamica *pilha);
void printarPilha(PilhaDinamica *pilha);