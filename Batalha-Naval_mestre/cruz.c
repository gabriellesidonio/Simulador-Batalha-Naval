#include <stdio.h>

#define TAM 10  // Tamanho do tabuleiro
#define H 5     // Tamanho da matriz de habilidade

int main() {
    int tabuleiro[TAM][TAM];
    int i, j;

    // Inicializa o tabuleiro com água (0)
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Posiciona um navio exemplo para visualização
    // Navio vertical de 3 posições, começando em [4][4]
    for (i = 0; i < 3; i++) {
        tabuleiro[4 + i][4] = 3;
    }

    // ========================
    // MATRIZ DE HABILIDADE: CRUZ
    // ========================
    int cruz[H][H];

    // A cruz tem linha e coluna centrais com valor 1
    for (i = 0; i < H; i++) {
        for (j = 0; j < H; j++) {
            if (i == H / 2 || j == H / 2) {
                cruz[i][j] = 1;  // parte da cruz
            } else {
                cruz[i][j] = 0;  // fora da cruz
            }
        }
    }

    // ========================
    // SOBREPOSIÇÃO DA CRUZ NO TABULEIRO
    // ========================
    int origemLinha = 5;  // linha central no tabuleiro
    int origemColuna = 5; // coluna central no tabuleiro

    for (i = 0; i < H; i++) {
        for (j = 0; j < H; j++) {
            int linhaT = origemLinha + i - H / 2;
            int colunaT = origemColuna + j - H / 2;

            // Verifica se a posição está dentro dos limites do tabuleiro
            if (linhaT >= 0 && linhaT < TAM && colunaT >= 0 && colunaT < TAM) {
                // Aplica a habilidade apenas sobre a água
                if (cruz[i][j] == 1 && tabuleiro[linhaT][colunaT] == 0) {
                    tabuleiro[linhaT][colunaT] = 5;  // 5 = área afetada pela habilidade
                }
            }
        }
    }

    // ========================
    // EXIBIÇÃO DO TABULEIRO
    // ========================
    printf("Tabuleiro com Habilidade Cruz:\n\n");

    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

return 0;
}