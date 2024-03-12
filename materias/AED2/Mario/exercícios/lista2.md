# Lista de Exercícios 2

#### Professor
[![Mario](https://img.shields.io/badge/Mario_San_Felice-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)](https://site.dc.ufscar.br/docente/5cee7e5d48365a001679f750)

## Árvores AVL e Rubro-Negra

### 1. Uma árvore é balanceada no sentido AVL se, para cada nó x, as alturas das subárvores que têm raízes x->esq e x->dir diferem de no máximo uma unidade. Escreva uma função que decida se uma dada árvore é balanceada no sentido AVL. Procure escrever sua função de modo que ela visite cada nó no máximo uma vez.

### 2. Complete a função de inserção em árvore AVL das notas de aula de modo que ela também trate os casos de inserção à direita.

### 3. Dê um exemplo de uma árvore binária de busca cujas folhas têm todas a mesma profundidade, mas nem todo caminho da raiz até um apontador NULL passa pelo mesmo número de nós.

### 4. Seja x um nó de uma árvore rubro-negra. Mostre que todos os caminhos que levam de x até um apontador NULL têm o mesmo número de nós pretos.

### 5. Suponha que x é um nó de uma árvore rubro-negra. Suponha que x.dir == NULL mas x.esq != NULL. Prove que x.esq.vermelho == 1 e x.esq não tem filhos (ou seja, x.esq.esq == NULL e x.esq.esq == NULL).

## Material Auxiliar

Para revisar conceitos sobre árvores AVL e Rubro-Negra, além de encontrar mais exercícios, acesse:

- [Seção 8.1 de Estrutura de Dados - Mario](http://www2.dc.ufscar.br/~mario/ensino/edtp.pdf)
- [Árvores Rubro-Negras - IME USP](https://www.ime.usp.br/~pf/estruturas-de-dados/aulas/st-redblack.html)

## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!
