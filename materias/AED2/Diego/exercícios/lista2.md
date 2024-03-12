# Lista de exercícios 2

#### Professor
[![Mario](https://img.shields.io/badge/Diego_Silva-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)](https://site.dc.ufscar.br/docente/5cee7e5d48365a001679f750)

## Sprint prova 2

### 1. (Adaptado de Paulo Feofiloff) Use o algoritmo de Boyer-Moore para contar o número de ocorrências da palavra  A B C B C C A B C  no texto A B C C B A A B C A B C B C C A B C A B C B C C A B C B C C.

### 2. (Exercício adaptado de http://monge.univ-mlv.fr/~mac/TSP/DOC/week4.pdf) Considerando o algoritmo de Boyer-Moore, preencha os vetores utilizados pelas heurísticas bad character (DA[]) e good suffix (suff[]) para as entradas listadas em cada linha das tabelas abaixo.

| DA[i]    |      a   |     b     |     c     |   | Tabela 2 | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
|:--------:|:--------:|:---------:|:---------:|---|:--------:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| ababa    |          |           |           |   | ababa    |   |   |   |   |   |   |   |   |   |   |
| abcacabb |          |           |           |   | abcacabb |   |   |   |   |   |   |   |   |   |   |
|abcacababc|          |           |           |   |abcacababc|   |   |   |   |   |   |   |   |   |   |
|abacabacab|          |           |           |   |abacabacab|   |   |   |   |   |   |   |   |   |   |

### 3. Fazer os problemas 34.5-X do livro CRLS (ver, alternativamente, em http://staff.ustc.edu.cn/~csli/graduate/algorithms/book6/chap34.htm).

### 4. (SW 5.2.3) Insira as chaves now is the time for all good people to come to the aid of numa trie inicialmente vazia. Faça um desenho da trie resultante.

### 5. (Adaptado de Paulo Feofiloff) Projete a operação min() para uma trie. Esse método deve devolver a menor chave (no sentido lexicográfico) da trie. Escreva uma versão recursiva e uma iterativa do método. Escreva os invariantes da versão iterativa.

### 6. Cada par da lista abaixo corresponde a uma aresta de um grafo G, não-direcionado e não-ponderado, com 10 vértices. Por exemplo, um par (1,3) significa que há uma aresta entre os vértices identificados por 1 e 3. Escreva o grafo em suas representações de matriz e lista de adjacências. A partir disso, identifique o custo computacional em termos de memória das duas representações e discuta as vantagens e desvantagens de cada uma delas.
```(0,1), (1,2), (1,7), (1,4), (2,3), (2,4), (2,9), (2,8), (3,7), (3,5), (3,6), (4,9), (5,6), (5,7), (6,8), (6,9), (7,8), (8,9)```

### 7. Execute a busca em largura e a busca em profundidade no grafo G do exercício anterior, a partir do vértice 0. Discutas as vantagens e desvantagens de se utilizar cada uma das representações para executar essas técnicas de busca.

### 8. Discuta como utilizar a busca em profundidade para encontrar o número de componentes conexos de um grafo. É possível realizar a mesma tarefa com uma busca em largura?

### 9. Um grafo bipartido GP é um grafo não-direcionado que pode ser dividido em dois grupos {U,W} de vértices tal que toda e qualquer aresta possui uma ponta em U e outra em W. Podemos, informalmente, dizer que, para todos os vértices do grafo GP que estão em um grupo (pintados de uma cor, por exemplo, preta) possui todos os vizinhos no outro grupo (pintados, por exemplo, na cor cinza). Defina um algoritmo baseado em busca em profundidade que determine se um grafo é bipartido (e, consequentemente, atribuir cores aos seus vértices).

### 10. Descreva um algoritmo para encontrar ciclos em um grafo direcionado e discuta sua complexidade.

### 11. Considere o grafo da figura a seguir. Quanto componentes fortemente conexos ele possui? Descreva um algoritmo para encontrar tais componentes e discuta sua complexidade. 

![Imagem 1](https://github.com/petbccufscar/.github/raw/main/pet-colab/AED2/Diego/Captura%20de%20tela%202024-03-12%20163929.png)

(fonte: visualgo.net)

### 12. Considere o grafo abaixo. Encontre o caminho mínimo, a partir do vértice 0, até o vértice 4. Utilize o algoritmo de Dijkstra. (fonte: visualgo.net)

![Imagem 2](https://github.com/petbccufscar/.github/raw/main/pet-colab/AED2/Diego/Captura%20de%20tela%202024-03-12%20164149.png)

### 13. (CLRS 24.3-2) Mostre um grafo orientado com arestas negativas para o qual o algoritmo de Dijkstra não funciona corretamente.

### 14. Sejam os algoritmos (gulosos) de Prim e Kruskal para a construção de árvores geradoras mínimas. Quais estruturas auxiliares podem ser utilizadas para melhorar o desempenho de tempo desses algoritmos? Quais são as complexidades de tempo desses algoritmos com e sem as referidas estruturas?

## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!