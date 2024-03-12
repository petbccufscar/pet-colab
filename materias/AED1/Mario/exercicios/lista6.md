# Lista de Exercícios 6

#### Professor
[![Mario](https://img.shields.io/badge/Mario_San_Felice-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)](https://site.dc.ufscar.br/docente/5cee7e5d48365a001679f750)


## Árvores binárias, árvores binárias de busca, heaps

Seguem alguns exercícios relacionados com árvores binárias, árvores binárias de
busca e heaps.

### 1 - Sejam X e Z dois nós de uma árvore binária. Mostre que existe no máximo um caminho com origem X e término Z.


### 2 - Imprima as folhas de uma árvore binária em ordem e-r-d.

### 3 - Modifique o algoritmo iterativo com pilha que realiza percurso e-r-d em uma árvore binária, para que: (i) ele faça a varredura r-e-d de uma árvore binária, (ii) ele faça a varredura e-d-r de uma árvore binária.


### 4 - [Expressões Aritméticas] Árvores binárias podem ser usadas, de maneira muito natural, para representar expressões aritméticas (como ((a+b)*c-d)/(e-f)+g, por exemplo). Discuta os detalhes desta representação.

### 5 - Considere a árvore binária usada para representar expressões aritméticas do exercício anterior. Discuta a relação entre os percursos e-r-d e e-d-r desta árvore e as notações infixa e posfixa.

### 6 - Desenhe uma árvore binária com 17 nós que tenha a menor altura possível.

### 7 - Escreva uma função iterativa que calcule a altura de uma árvore binária.

### 8 - Escreva uma função que preencha corretamente todos os campos pai de uma árvore binária.

### 9 - A profundidade de um nó em uma árvore binária é a distância entre o nó e a raiz da árvore. Escreva uma função que imprima o conteúdo de cada nó de uma árvore binária precedido de um recuo em relação à margem esquerda do papel. Esse recuo deve ser proporcional à profundidade do nó. Exemplo:

```
         555    
       /    \   
   333       888
 /     \        
111   444 
```

### 10 - Escreva uma função que decida se uma dada árvore binária é ou não é de busca.

### 11 - Modifique o algoritmo visto em aula para calcular o predecessor de um nó em uma árvore binária de busca, para que ele não precise usar o campo pai.

### 12 - Escreva uma função que transforme um vetor crescente em uma árvore de busca balanceada.

### 13 - Escreva uma função que transforme uma árvore de busca em um vetor crescente.

### 14 - Modifique o algoritmo visto em aula para remover um nó de uma árvore binária de busca, para que ele não precise usar o campo pai.

### 15 - Mostre que todo vetor decrescente é um max-heap. Mostre que a recíproca não é verdadeira.

### 16 - Escreva uma função que decida se um vetor v[0 .. m - 1] é ou não um max-heap.

### 17 -Em que condições uma árvore binária pode ser considerada um heap? Escreva uma função que transforme um max-heap em uma árvore binária quase completa. Escreva uma versão da função desceHeap para um max-heap representado por uma árvore binária.

### 18 - Suponha que v[0 .. 2^k - 2] é um max-heap. Mostre que mais da metade dos elementos do vetor está na última “camada” do max-heap, ou seja, em v[2^(k - 1) - 1 .. 2^k - 2].

### 19 -[Ordem Decrescente] Escreva uma versão do algoritmo heapSort que rearranja um vetor v[0 .. n - 1] de modo que ele fique em ordem decrescente.

### 20 -[Ordenação de Strings] Escreva uma versão do algoritmo heapSort que coloque um vetor de strings em ordem lexicográfica (“ordem alfabética”). Veja https://www.ime.usp.br/~pf/algoritmos/aulas/string.html.


### Material auxiliar
- https://www.ime.usp.br/~pf/algoritmos/aulas/bint.html
- https://www.ime.usp.br/~pf/algoritmos/aulas/binst.html
- https://www.ime.usp.br/~pf/algoritmos/aulas/hpsrt.html


## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!