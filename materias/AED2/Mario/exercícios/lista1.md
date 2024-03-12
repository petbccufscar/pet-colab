# Lista de Exercícios 1

#### Professor
[![Mario](https://img.shields.io/badge/Mario_San_Felice-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)](https://site.dc.ufscar.br/docente/5cee7e5d48365a001679f750)

## Árvores Binárias de Busca

### 1. Escreva uma função que calcule o número de nós de uma árvore binária.
   
### 2. Escreva uma função que imprima, em ordem esquerda-raiz-direita, os conteúdos das folhas de uma árvore binária.
   
### 3. Escreva uma função para calcular a altura de uma árvore binária.
   - a) Faça a função recursiva.
   - b) Faça a função iterativa.
  
### 4. Considere uma árvore binária já construída, mas com os campos pai não preenchidos. Escreva uma função que preencha corretamente todos os campos pai desta árvore.
   
### 5. Escreva uma função que verifica se uma dada árvore binária é de busca.
   
### 6. Escreva uma função que transforme uma árvore binária de busca em um vetor crescente.
   
### 7. Escreva uma função que transforme um vetor crescente em uma árvore binária de busca que seja balanceada.
   
### 8. Suponha que as chaves 50 30 70 20 40 60 80 15 25 35 45 36 são inseridas, nesta ordem, numa árvore de busca inicialmente vazia. Desenhe a árvore que resulta. Em seguida, remova o nó que contém 30.
   
### 9. Considere árvores binárias de busca cujos nós têm a estrutura indicada abaixo. Escreva uma função que receba a raiz de uma tal árvore e o endereço de um nó x e devolva o endereço do pai de x.

```c
typedef struct reg {
    int chave;
    int conteudo;
    struct reg *esq, *dir;
} noh;
```

### Material auxiliar
Para revisar conceitos sobre árvores binárias de busca e encontrar mais exercícios
acesse:
- https://www.ime.usp.br/~pf/algoritmos/aulas/binst.html
- https://www.ime.usp.br/~pf/algoritmos/aulas/bint.html


## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!
