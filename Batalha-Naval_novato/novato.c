#include <stdio.h>  // Biblioteca padrão para entrada e saída (ex: printf)

#define TAMANHO 10  // Define o tamanho fixo do tabuleiro (10x10)

int main() {
    int tabuleiro[TAMANHO][TAMANHO];  // Declara uma matriz 10x10 para representar o tabuleiro
    int i, j;  // Variáveis de controle para os loops

    // Inicializa o tabuleiro com 0 (representando água em todas as posições)
    for (i = 0; i < TAMANHO; i++) {
        for (j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Define as coordenadas iniciais do navio horizontal
    // O navio horizontal será colocado na linha 2, começando na coluna 4
    int linhaH = 2;  
    int colunaH = 4;

    // Define as coordenadas iniciais do navio vertical
    // O navio vertical será colocado na coluna 7, começando na linha 6
    int linhaV = 6;
    int colunaV = 7;

    // Posiciona o navio horizontal de tamanho 3 no tabuleiro
    // Ele ocupa as posições: [2][4], [2][5], [2][6]
    for (j = 0; j < 3; j++) {
        tabuleiro[linhaH][colunaH + j] = 3;  // 3 representa parte do navio
    }

    // Posiciona o navio vertical de tamanho 3 no tabuleiro
    // Ele ocupa as posições: [6][7], [7][7], [8][7]
    for (i = 0; i < 3; i++) {
        tabuleiro[linhaV + i][colunaV] = 3;  // 3 representa parte do navio
    }

    // Exibe o tabuleiro no console
    // 0 = água, 3 = parte de navio
    printf("Tabuleiro de Batalha Naval:\n\n");
    for (i = 0; i < TAMANHO; i++) {
        for (j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);  // Imprime cada elemento da matriz
        }
        printf("\n");  // Pula para a próxima linha após imprimir uma linha inteira
    }

    return 0;  // Fim do programa
}
