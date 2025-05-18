# Nível Aventureiro – Batalha Naval com Navios Diagonais

Este programa expande a lógica do nível novato adicionando mais dois navios diagonais ao tabuleiro:
- Dois navios horizontais/verticais
- Dois navios diagonais (↘ e ↙)

## Posições no tabuleiro
- 0 = água
- 3 = parte de navio

## Conceitos utilizados
- Matrizes e vetores
- Navios em posições diagonais (tabuleiro[i][i], tabuleiro[i][9 - i])
- Validação de limites
- Estruturas de repetição

## Como compilar e executar no terminal

gcc aventureiro.c -o aventureiro
./aventureiro