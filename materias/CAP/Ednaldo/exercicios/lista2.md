# Lista de Exercícios 2

#### Professor
[![Ednaldo](https://img.shields.io/badge/Ednaldo_Pizzolato-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)](https://site.dc.ufscar.br/docente/5cee7e5d48365a001679f750)


## Lista preparatória para a prova 2

### 1 - Elabore um algoritmo ou programa em C que leia um conjunto de 30 valores inteiros e os coloque em 2 vetores conforme estes valores sejam pares positivos (vetor A) ou ímpares positivos (vetor B). O tamanho do vetor A é de 7 posições e o do vetor B é de 12 posições. O valor 0 (zero) não será inserido em nenhum dos vetores, assim como os valores negativos. Se algum vetor estiver cheio, escrevê-lo e não inserir mais nenhum número nele. Terminada a leitura escrever o conteúdo dos dois vetores.

### 2 - Faça um programa em C que armazene 30 valores em um vetor e troque os elementos que estão nas posições ímpares com os elementos que estão nas posições pares imediatamente posteriores. Imprima o vetor inicial e o vetor final para identificar se a transformação foi correta.

### 3 - Faça um programa em C que multiplique dois vetores A e B de mesmo tamanho (15).

### 4 - Considere as duas figuras abaixo para os problemas de matrizes a seguir:

![Figura1](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/CAP/imagem_2024-03-19_232651344.png)

![Figura2](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/CAP/imagem_2024-03-19_232703152.png)

#### a) Faça um programa em C para somar os elementos da área hachurada da figura 1;
#### b) Faça um programa em C para somar os elementos da área hachurada da figura 2;

### 5 - O triangulo de Pascal é uma representação de números binomiais:

![Triangulo Pascal](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/CAP/imagem_2024-03-19_232718434.png)

#### O cálculo do binomial (n k) é feito da seguinte forma:n!/(k!(n−k)!)

### Mas calcular isso para cada elemento pode ser bem demorado. Uma alternativa é verificar que um elemento pode ser obtido através de dois outros (quais?). Dado o triangulo a seguir, produza um programa em C que crie o triangulo de Pascal para as 10 primeiras linhas.

![Binominal](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/CAP/imagem_2024-03-19_232741171.png)

### 6 - Em algumas situações é preciso encontrar um elemento chamado MiniMax, que é o menor elemento da linha onde se encontra o maior elemento da matriz. Escreva um programa em C que dada uma matriz 10 x 10 informe o elemento MiniMax, mostrando sua posição.

### 7 - Dada uma sequencia de n números (n no máximo igual a 20), faça um programa em C que apresente a média dos elementos maiores que a média dos elementos da sequencia.


### 8 - Considere que um vetor armazena os RAs dos alunos e que um outro vetor armazena, nas mesmas posições, as médias finais desses alunos em uma determinada disciplina. Faça um programa em C que apresente a lista ordenada por RA de alunos da disciplina com suas respectivas médias finais.


### 9 - Considere uma matriz de caracteres como a do exemplo a seguir. Faça um programa em C que leia uma palavra do usuário e verifique se a palavra está na matriz ou não. A palavra pode estar nas linhas ou colunas.

![Tabela](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/CAP/imagem_2024-03-19_232802646.png)

#### Se a palavra estiver, informe que está no jogo e, se possível, qual a linha e coluna em que se inicia e sua configuração (horizontal ou vertical). Se não estiver presente, apenas informe que a palavra não se encontra no jogo.

### 10 - Faça um programa que armazene uma sequencia dos n primeiros quadrados (1, 4, 9, 16, 25,...), onde n é um número entre 5 e 20. Em seguida, faça a soma da sequencia e mostre que ela corresponde a seguinte equação: (n(n+1)(2n+1))/6.