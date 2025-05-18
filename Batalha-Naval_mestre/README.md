## Nivel mestre - Habilidades Especiais (Cone, Cruz e Octaedro)

Este nível implementa três habilidades especiais que afetam áreas do tabuleiro:
- *Cone* – área triangular (expande para baixo)
- *Cruz* – área com linhas horizontal e vertical cruzadas
- *Octaedro* – área em forma de losango

## Legenda do tabuleiro
- 0 = água
- 3 = navio
- 5 = área afetada por habilidade

Cada habilidade é implementada em seu próprio arquivo:
- cone.c
- cruz.c
- octaedro.c

## Conceitos utilizados
- Matrizes 2D
- Estruturas condicionais com loops aninhados
- Sobreposição de matrizes de habilidade no tabuleiro
- Distância de Manhattan para o octaedro

## Como compilar e executar

gcc cone.c -o cone && ./cone
gcc cruz.c -o cruz && ./cruz
gcc octaedro.c -o octaedro && ./octaedro