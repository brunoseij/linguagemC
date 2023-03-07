#include <stdio.h>
struct Fracao {
    int num;
    int den;
};

typedef struct Fracao Fracao;

Fracao simplificar(Fracao f, int n) {
    if (f.num < 0){
        if (-n < f.num || n > f.den) {
            return f;
        }
    } else if (n > f.num || n > f.den) {
        return f;
    }

    // verificar o %
    if (f.num % n == 0 && f.den % n == 0) {
        f.num /= n;
        f.den /= n;
    }
    else {
        n++;
    }

    simplificar(f, n);
}

Fracao somar(Fracao f1, Fracao f2) {
    Fracao f3;
    f3.den = f1.den;
    f3.num = f1.num + f2.num;
    if (f1.den != f2.den) {
        f3.den = f1.den * f2.den;
        f3.num = (f1.num * f2.den) + (f2.num * f1.den);
    }
    f3 = simplificar(f3, 2);
    return f3;
}

Fracao subtrair(Fracao f1, Fracao f2) {
    Fracao f3;
    f3.den = f1.den;
    f3.num = f1.num - f2.num;
    if (f1.den != f2.den) {
        f3.den = f1.den * f2.den;
        f3.num = (f1.num * f2.den) - (f2.num * f1.den);
    }
    f3 = simplificar(f3, 2);
    return f3;
}

Fracao multiplicar(Fracao f1, Fracao f2) {
    Fracao f3;
    f3.num = f1.num * f2.num;
    f3.den = f1.den * f2.den;
    f3 = simplificar(f3, 2);
    return f3;
}

Fracao dividir(Fracao f1, Fracao f2) {
    Fracao f3;
    if (f2.num < 0){
        f2.den = -f2.den;
        f2.num = -f2.num;
    }
    f3.num = f1.num * f2.den;
    f3.den = f1.den * f2.num;
    f3 = simplificar(f3, 2);
    return f3;
}

Fracao somar_vetor(Fracao f[], int n_fracoes) {
    Fracao f3 = f[0];
    for (int i = 1; i < n_fracoes; i++){
        f3 = somar(f3, f[i]);
    }
    return f3;
}

Fracao multiplicar_vetor(Fracao f[], int n_fracoes) {
    Fracao f3 = f[0];
    for (int i = 1; i < n_fracoes; i++){
        f3 = multiplicar(f3, f[i]);
    }
    return f3;
}

void main() {
    Fracao soma, subtracao, multiplicacao, divisao, somaVetor, multVetor;
    Fracao f1, f2, f3;
    f1.num = -3;
    f1.den = 5;
    f2.num = 3;
    f2.den = 20;
    f3.num = 8;
    f3.den = 3;
    Fracao vetor[] = {f1, f2, f3};
    soma = somar(f1, f2);
    multiplicacao = multiplicar(f1, f2);
    subtracao = subtrair(f1, f2);
    divisao = dividir(f1, f2);
    somaVetor = somar_vetor(vetor, 3);
    multVetor = multiplicar_vetor(vetor, 3);
    printf("%d/%d\n", soma.num, soma.den);
    printf("%d/%d\n", subtracao.num, subtracao.den);
    printf("%d/%d\n", multiplicacao.num, multiplicacao.den);
    printf("%d/%d\n", divisao.num, divisao.den);
    printf("%d/%d\n", somaVetor.num, somaVetor.den);
    printf("%d/%d\n", multVetor.num, multVetor.den);
}