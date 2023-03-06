#include <stdio.h>

typedef struct Disciplina Disciplina;
struct Disciplina {
    int cod;
    char *nome;
    int creditos;
    Disciplina *requisito;
};

Disciplina *disciplina_inicial(Disciplina *d, int *qtd) {
    if (!d->requisito) {
        return d;
    }
    
    *qtd += 1;
    disciplina_inicial(d->requisito, qtd);
}

void main() {
    Disciplina d1 = {1, "Bases Matemáticas", 3};
    Disciplina d2 = {2, "Calculo I", 4};
    Disciplina d3 = {3, "Calculo II", 5};
    Disciplina d4 = {4, "Calculo III", 6};

    d4.requisito = &d3;
    d3.requisito = &d2;
    d2.requisito = &d1;
    d1.requisito = NULL;
    
    int qtd = 0;

    Disciplina *requisitoInicial = disciplina_inicial(&d4, &qtd);
    printf("%s\n", requisitoInicial->nome);
    printf("%d\n", qtd);
}
