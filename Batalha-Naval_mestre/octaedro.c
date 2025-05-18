#include <stdio.h>
#include <stdlib.h>

#define TAM 10  // Tamanho do tabuleiro
#define H 5     // Tamanho da matriz da habilidade (5x5)

int main() {
    int tabuleiro[TAM][TAM];
    int i, j;

    // Inicializa o tabuleiro com água (0)
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Posiciona um navio para teste visual
    // Navio diagonal, começando em [6][6]
    for (i = 0; i < 3; i++) {
        tabuleiro[6 - i][6 - i] = 3;  // [6][6], [5][5], [4][4]
    }

    // ===========================
    // MATRIZ DE HABILIDADE: OCTAEDRO (LOSANGO)
    // ===========================
    int octaedro[H][H];

    for (i = 0; i < H; i++) {
        for (j = 0; j < H; j++) {
            // Distância de Manhattan ao centro deve ser <= 2
            if (abs(i - H / 2) + abs(j - H / 2) <= 2) {
                octaedro[i][j] = 1;  // parte do losango
            } else {
                octaedro[i][j] = 0;  // fora da área
            }
        }
    }

    // ===========================
    // SOBREPOSIÇÃO NO TABULEIRO
    // ===========================
    int origemLinha = 4;   // centro da área de efeito
    int origemColuna = 5;

    for (i = 0; i < H; i++) {
        for (j = 0; j < H; j++) {
            int linhaT = origemLinha + i - H / 2;
            int colunaT = origemColuna + j - H / 2;

            // Verifica se está dentro dos limites do tabuleiro
            if (linhaT >= 0 && linhaT < TAM && colunaT >= 0 && colunaT < TAM) {
                if (octaedro[i][j] == 1 && tabuleiro[linhaT][colunaT] == 0) {
                    tabuleiro[linhaT][colunaT] = 5;  // 5 representa área de habilidade
                }
            }
        }
    }

    // ===========================
    // EXIBE O TABULEIRO FINAL
    // ===========================
    printf("Tabuleiro com Habilidade Octaedro (losango):\n\n");

    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

return 0;
}