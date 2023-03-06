#include <stdio.h>
struct Fracao {
    int num;
    int den;
};

typedef struct Fracao Fracao;

Fracao simplificar(Fracao f, int n) {
    if (f.num / n < 1 || f.den < 1) {
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
    f3.num = f1.num * f2.den;
    f3.den = f1.den * f2.num;
    f3 = simplificar(f3, 2);
    return f3;
}

void main() {
    Fracao soma, subtracao, multiplicacao, divisao;
    Fracao f1, f2;
    f1.num = 3;
    f1.den = 5;
    f2.num = 3;
    f2.den = 20;
    soma = somar(f1, f2);
    multiplicacao = multiplicar(f1, f2);
    subtracao = subtrair(f1, f2);
    divisao = dividir(f1, f2);
    printf("%d/%d\n", soma.num, soma.den);
    printf("%d/%d\n", subtracao.num, subtracao.den);
    printf("%d/%d\n", multiplicacao.num, multiplicacao.den);
    printf("%d/%d\n", divisao.num, divisao.den);
}