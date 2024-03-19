# Lista de Exercícios 3

#### Professor
![Heloisa](https://img.shields.io/badge/Heloisa-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)

## Resolução de Problemas por Busca – Busca não Clássica

### 1 - Aplique as rotinas Minimax e Alfa-Beta na árvore abaixo considerando que os quadrados representam jogadas para Max e os círculos, jogadas para Min. Aplique a rotina Alfa-Beta da esquerda para direita e da direita para esquerda. Considere que os valores da função heurística das folhas são: I=3, J=5, K=0, L=7, M=5, N=7, O=8, P=4, Q=8, R=2.

![Grafo](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/IA/imagem_2024-03-19_173831829.png)

### 2 - Considerando o jogo da velha, definimos Xn como o número de linhas, colunas ou diagonais com exatamente n X’s e nenhum O’s. Similarmente, On é o número de linhas, colunas ou diagonais com apenas n O’s. Usando a função de avaliação definida como E(n) = 3X2 + X1 - (3O2 + O1), responda:

#### a) mostre a árvore de jogo completa começando com um tabuleiro vazio, até o nível 2;

#### b) marque o resultado da aplicação da função de avaliação em todas as posições no nível 2.

#### c) marque os valores propagados aos níveis 1 e 0 usando a rotina minimax;

#### d) marque os nós do nível 2 que não seria avaliados se a rotina alfa-beta fosse aplicada.

#### e) os nós assinalados no item anterior são os mesmos, independente da ordem em que os nós aparecem na árvore? Explique.


### 3 - Considere a árvore de jogo a seguir, onde os círculos representam nós Min e os quadrados representam nós Max. Realize uma busca Alfa-Beta indicando quais nós seriam gerados e de que tipo seriam os cortes realizados. Reaplique a rotina, fazendo a geração dos nós da direita para a esquerda.

![Arvore](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/IA/imagem_2024-03-19_173847183.png)

### 4 - Considere a árvore de jogo a seguir, onde os círculos representam nós Min e os quadrados representam nós Max. Realize uma busca Alfa-Beta nessa árvore indicando quais nós seriam gerados e onde e de que tipo seriam os cortes realizados.

![Arvore](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/IA/imagem_2024-03-19_173914318.png)

### 5 - Aplique o algoritmo de busca Alfa-Beta nas duas figuras do jogo da velha dadas a seguir, usando a função heurística dada em aula. Diga quantos e quais nós folha podem ser eliminados em cada caso.

![Jogo da Velha](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/IA/imagem_2024-03-19_173935338.png)

![Jogo da Velha 2](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/IA/imagem_2024-03-19_174113425.png)

### 6 - A árvore dada a seguir mostra um exemplo de aplicação do procedimento Alfa-Beta. Os nós folhas têm seus respectivos valores de avaliação heurística indicados na figura. Os nós em que ocorreram cortes estão marcados com um X. Explique qual o tipo de corte foi aplicado no nó identificado pela letra A e porque esse corte pode ser efetuado.

![Arvore](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/IA/imagem_2024-03-19_174213916.png)

## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!