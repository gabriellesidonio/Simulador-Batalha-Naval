#include <stdio.h>

#define TAMANHO 10  // Tamanho fixo do tabuleiro (10x10)

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    int i, j;

    // Inicializa todas as posições do tabuleiro com 0 (representando água)
    for (i = 0; i < TAMANHO; i++) {
        for (j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // ========================
    // NAVIOS HORIZONTAIS / VERTICAIS
    // ========================

    // Navio 1: horizontal, começa na linha 1, coluna 2
    for (j = 0; j < 3; j++) {
        tabuleiro[1][2 + j] = 3;  // Ocupa [1][2], [1][3], [1][4]
    }

    // Navio 2: vertical, começa na linha 4, coluna 0
    for (i = 0; i < 3; i++) {
        tabuleiro[4 + i][0] = 3;  // Ocupa [4][0], [5][0], [6][0]
    }

    // ========================
    // NAVIOS DIAGONAIS
    // ========================

    // Navio 3: diagonal principal, começa na posição [3][3]
    // Ocupa [3][3], [4][4], [5][5]
    for (i = 0; i < 3; i++) {
        tabuleiro[3 + i][3 + i] = 3;
    }

    // Navio 4: diagonal secundária, começa na posição [0][9]
    // Ocupa [0][9], [1][8], [2][7]
    for (i = 0; i < 3; i++) {
        tabuleiro[0 + i][9 - i] = 3;
    }

    // ========================
    // EXIBIÇÃO DO TABULEIRO
    // ========================

    printf("Tabuleiro de Batalha Naval – Nível Aventureiro:\n\n");

    for (i = 0; i < TAMANHO; i++) {
        for (j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);  // Imprime os valores do tabuleiro
        }
        printf("\n");  // Nova linha após cada linha da matriz
    }
return 0;
}