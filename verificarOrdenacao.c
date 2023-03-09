#include <stdio.h>

typedef struct DiscoVoador DiscoVoador;
struct DiscoVoador {
    char *modelo;
    char *planeta;
    int autonomia;
};


int len(char *string){
    int i = 0;
    for (i; string[i] != '\0'; i++){}
    return i;
}

int indiceDiferenca(char *string1, char *string2){
    for (int i = 0; string1[i] != '\0'; i++) {
        if (string1[i] != string2[i] && (i + 1 <= len(string1) && i + 1 <= len(string2))) return i;
    }
    if (len(string1) == len(string2)){
        return -1;
    }
    return -2;
}

int verificaOrdem(char *atual, char *proximo, int indice) {
    if (atual[indice] < proximo[indice]) {
        return 1;
    } else if (atual[indice] > proximo[indice]) return 0;
    if (len(atual) < len(proximo)) return 1;
    return 0;
}

int verificarCrescente(char* string1, char* string2) {
    int iDiferenca = indiceDiferenca(string1, string2);

    if (iDiferenca == -1) return -1;
    if (iDiferenca == -2) {
        if (len(string1) > len(string2)) return -1;
    }
    if (verificaOrdem(string1, string2, iDiferenca) == 1) return 1;
    return 1;
}

int verificarOrdemAutonomia(DiscoVoador *discos, int n_discos) {
    int atual, prox;
    int ordem, ordemAtual;
    int iDiferenca;
    
    for (int i = 0; i < n_discos-1; i++) {
        atual = discos[i].autonomia;
        prox = discos[i+1].autonomia;
        printf("%d %d\n", atual, prox);
        if (atual > prox) {
            return -1;
        }

        if (atual == prox) {
            ordem = verificarCrescente(discos[i].planeta, discos[i+1].planeta);
            if (ordem == -1) {
                ordem = verificarCrescente(discos[i].modelo, discos[i+1].modelo);
                if (ordem == -1) {
                    return -1;
                }
            }
        }
    }
    return 1;
}


int verificarOrdemPlanetaModelo(DiscoVoador *discos, int n_discos, int campo) {
    int iDiferenca, ordem, ordemAtual;
    char *atual, *prox;
    for (int i = 0; i < n_discos - 1; i++) {
        if (campo == 0) {
            atual = discos[i].modelo;
            prox = discos[i + 1].modelo;
        } else {
            atual = discos[i].planeta;
            prox = discos[i + 1].planeta;
        }

        iDiferenca = indiceDiferenca(atual, prox);
        // printf("indice = %d\n",iDiferenca);
        // printf("%s %s\n",atual, prox);
        printf("indice %d\n", iDiferenca);
        if (iDiferenca != -1) {
            if (i == 0) {
                ordem = verificaOrdem(atual, prox, iDiferenca);
            }
            printf("ordem: %d\n", ordem);

            ordemAtual = verificaOrdem(atual, prox, iDiferenca);
            printf("ordem atual: %d\n", ordemAtual);
            if (ordemAtual != ordem) {
                printf("%d %d\n", discos[i].autonomia, discos[i+1].autonomia);
                return -1;
            }
        } else {
            if (campo == 0) {
                return -1;
            }
            ordem = 1;
            if (discos[i].autonomia < discos[i+1].autonomia) {
                printf("%d %d\n", discos[i].autonomia, discos[i+1].autonomia);
                return -1;
            }
            
        }
    }
    return ordem;
}

int verificar_ordenacao(DiscoVoador *discos, int n_discos) {
    if (verificarOrdemPlanetaModelo(discos, n_discos, 0) == 1) return 1;
    if (verificarOrdemPlanetaModelo(discos, n_discos, 0) == 0) return 2;
    if (verificarOrdemPlanetaModelo(discos, n_discos, 1) == 0) return 3;
    if (verificarOrdemAutonomia(discos, n_discos) == -1) return 4;
    return 0;
}

void main() {
    DiscoVoador d1 = {"Modelo_H200", "Jupiter", 90};
    DiscoVoador d2 = {"Modelo_H50", "Jupiter", 90};
    DiscoVoador d3 = {"Modelo_H1000", "Marte", 400};
    DiscoVoador d4 = {"Modelo_D", "Marte", 59};
    DiscoVoador d5 = {"Modelo_E", "Marte", 49};

    DiscoVoador discos[] = {d1, d2, d3, d4, d5};
    printf("%d\n", verificarOrdemPlanetaModelo(discos, 3, 0)); // verificando modelo
    printf("%d\n", verificarOrdemPlanetaModelo(discos, 5, 1)); // verificando planeta
    printf("%d\n", verificarOrdemAutonomia(discos, 3));
}