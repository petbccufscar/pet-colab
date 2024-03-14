# Lista de Exercícios 3

#### Professor
[![Mario](https://img.shields.io/badge/Mario_San_Felice-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)](https://site.dc.ufscar.br/docente/5cee7e5d48365a001679f750)


## Listas encadeadas

Seguem alguns exercícios relacionados com listas encadeadas.

### 1 - Uma lista é crescente se o conteúdo de cada célula não é maior que oconteúdo da célula seguinte. Escreva uma função que faça uma busca em uma lista crescente. Faça versões para listas com e sem cabeça. Faça uma versão recursiva e outra iterativa.


### 2 - Critique a seguinte variante da função Remove:

```c
void Remove (celula *p, celula *lst) {
    celula *lixo;
    lixo = p->seg;
    if (lixo->seg == NULL) p->seg = NULL;
    else p->seg = lixo->seg;
    free(lixo);
}
```
### 3 - Por que a seguinte versão de Insere não funciona?
```c
void Insere (int y, célula *p) {
    celula nova;
    nova.conteudo = y;
    nova.seg = p->seg;
    p->seg = &nova;
}
```

### 4 - Escreva uma função para remover de uma lista encadeada todos os elementos que contém x. Faça uma versão iterativa e uma recursiva.Considere a seguinte função que faz uma busca sequêncial emum vetor ordenado e devolve a posição em que x está ou deveria ser inserido. Note que a convenção desta busca é diferente da vista em aula, pois quando não encontra x ela devolve a primeira (mais a esquerda) posição em que x poderia ser inserido de modo a manter o vetor ordenado, ao invés de devolver -1.


### 5 - Considere a seguinte função que faz uma busca binária em um vetor ordenado e devolve a posição em que x está ou deveria ser inserido.


#### a) Escreva uma função que copie um vetor para uma lista encadeada.

#### b) Escreva uma função que copie um vetor para uma lista encadeada.

### 6 - Escreva uma função que concatene duas listas encadeadas (isto é, "pendure" a segunda no final da primeira).

### 7 - Escreva uma função que receba uma lista encadeada e devolva o endereço de uma célula que esteja o mais próximo possível do ponto médio da lista. Faça isso sem calcular explicitamente o número n de células da lista e o quociente
n/2.


### Material auxiliar
- https://www.ime.usp.br/~pf/algoritmos/aulas/lista.html


## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!