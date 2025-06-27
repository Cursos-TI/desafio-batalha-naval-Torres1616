#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define VALOR_AGUA 0
#define VALOR_NAVIO 3
#define TAMANHO_NAVIO 3

int main() {
    // Declaração do tabuleiro 10x10 e inicialização com água (0)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};
    
    // POSICIONAMENTO DOS NAVIOS
   
    // 1. Navio Horizontal - Linha 2, começando na coluna 1
   
    int linhaH = 2;
    int colunaH = 1;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaH][colunaH + i] = VALOR_NAVIO;
    }

    // 2. Navio Vertical - Coluna 5, começando na linha 0
    int colunaV = 5;
    int linhaV = 0;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaV + i][colunaV] = VALOR_NAVIO;
    }

    // 3. Navio Diagonal Principal - Começa em (6,6), vai até (8,8)
    int linhaDiag1 = 6;
    int colunaDiag1 = 6;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaDiag1 + i][colunaDiag1 + i] = VALOR_NAVIO;
    }

    // 4. Navio Diagonal Secundária - Começa em (2,7), vai até (4,5)
    int linhaDiag2 = 2;
    int colunaDiag2 = 7;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaDiag2 + i][colunaDiag2 - i] = VALOR_NAVIO;
    }

    // EXIBIÇÃO DO TABULEIRO
 
    printf("\n= TABULEIRO =\n\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}


