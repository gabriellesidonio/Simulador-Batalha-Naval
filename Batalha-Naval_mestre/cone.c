#include <stdio.h>

#define TAM 10       // Tamanho do tabuleiro
#define H 5          // Tamanho das matrizes de habilidade (5x5)

int main() {
    int tabuleiro[TAM][TAM];  // Tabuleiro principal 10x10
    int i, j;

    // Inicializa o tabuleiro com água (0)
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Posiciona um navio exemplo para mostrar sobreposição
    // Navio horizontal de tamanho 3 começando em [4][2]
    for (j = 0; j < 3; j++) {
        tabuleiro[4][2 + j] = 3;
    }

    // =========================
    // MATRIZ DE HABILIDADE: CONE
    // =========================
    int cone[H][H];

    for (i = 0; i < H; i++) {
        for (j = 0; j < H; j++) {
            // Habilidade com forma de cone: expande para os lados a cada linha
            if (j >= H/2 - i && j <= H/2 + i) {
                cone[i][j] = 1;
            } else {
                cone[i][j] = 0;
            }
        }
    }

    // =========================
    // SOBREPOSIÇÃO DO CONE NO TABULEIRO
    // =========================
    int origemLinha = 2;  // centro do cone no tabuleiro
    int origemColuna = 4;

    for (i = 0; i < H; i++) {
        for (j = 0; j < H; j++) {
            // Calcula a posição no tabuleiro relativa à origem
            int linhaT = origemLinha + i - H / 2;
            int colunaT = origemColuna + j - H / 2;

            // Verifica se está dentro do tabuleiro
            if (linhaT >= 0 && linhaT < TAM && colunaT >= 0 && colunaT < TAM) {
                // Se posição da habilidade for 1, aplica no tabuleiro
                if (cone[i][j] == 1 && tabuleiro[linhaT][colunaT] == 0) {
                    tabuleiro[linhaT][colunaT] = 5;  // 5 representa área de efeito
                }
            }
        }
    }

    // =========================
    // EXIBE O TABULEIRO FINAL
    // =========================
    printf("Tabuleiro com Habilidade Cone:\n\n");

    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

return 0;
}