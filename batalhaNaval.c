#include <stdio.h>

#define TAM 10
#define NAVIO 3
#define AGUA 0
#define HABILIDADE 5
#define TAM_HABILIDADE 5

// Função para inicializar o tabuleiro com 0 (AGUA)
void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("\n=== TABULEIRO FINAL ===\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para sobrepor habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[TAM][TAM], int matrizHabilidade[TAM_HABILIDADE][TAM_HABILIDADE], int origemX, int origemY) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int linhaTab = origemX - TAM_HABILIDADE / 2 + i;
            int colunaTab = origemY - TAM_HABILIDADE / 2 + j;

            // Verifica limites do tabuleiro
            if (linhaTab >= 0 && linhaTab < TAM && colunaTab >= 0 && colunaTab < TAM) {
                if (matrizHabilidade[i][j] == 1 && tabuleiro[linhaTab][colunaTab] != NAVIO) {
                    tabuleiro[linhaTab][colunaTab] = HABILIDADE;
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAM][TAM];
    inicializarTabuleiro(tabuleiro);

    // Posicionar navios como no desafio anterior
    for (int i = 0; i < 3; i++) tabuleiro[2][1 + i] = NAVIO;       // Horizontal
    for (int i = 0; i < 3; i++) tabuleiro[0 + i][5] = NAVIO;       // Vertical
    for (int i = 0; i < 3; i++) tabuleiro[6 + i][6 + i] = NAVIO;   // Diagonal principal
    for (int i = 0; i < 3; i++) tabuleiro[2 + i][7 - i] = NAVIO;   // Diagonal secundária

    // Matrizes das habilidades
    int cone[TAM_HABILIDADE][TAM_HABILIDADE] = {0};
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE] = {0};
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE] = {0};

    // Construção da matriz CONE (forma de pirâmide para baixo)
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (i >= j - 2 && i >= 2 - j && i <= 2) {
                cone[i][j] = 1;
            }
        }
    }

    // Construção da matriz CRUZ (linha e coluna centrais)
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (i == TAM_HABILIDADE / 2 || j == TAM_HABILIDADE / 2) {
                cruz[i][j] = 1;
            }
        }
    }

    // Construção da matriz OCTAEDRO (forma de losango)
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (abs(i - TAM_HABILIDADE / 2) + abs(j - TAM_HABILIDADE / 2) <= 2) {
                octaedro[i][j] = 1;
            }
        }
    }

    // Aplicação das habilidades no tabuleiro
    aplicarHabilidade(tabuleiro, cone, 3, 3);      // Centro da habilidade CONE
    aplicarHabilidade(tabuleiro, cruz, 6, 2);      // Centro da habilidade CRUZ
    aplicarHabilidade(tabuleiro, octaedro, 8, 8);  // Centro da habilidade OCTAEDRO

    // Exibe o tabuleiro final com navios e habilidades
    exibirTabuleiro(tabuleiro);

    return 0;
}


