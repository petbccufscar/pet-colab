# Lista de Exercícios 1

#### Professor
[![Joice](https://img.shields.io/badge/Joice_Otsuka-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)](https://site.dc.ufscar.br/docente/5cee7e5d48365a001679f750)



## Lista sobre Alocação Dinâmica

### 1 - Escreva um programa em linguagem C que solicita ao usuário a quantidade de alunos de uma turma e aloca dinamicamente um vetor de notas (números reais). Leia as notas e imprima a média.

#### Crie uma função que leia as notas dos alunos e uma função que calcule a média aritmética.
#### não deve ocorrer desperdício de memória; e após ser utilizada a memória deve ser devolvida.


### 2 - Crie um programa para manipular vetores. O seu programa deve implementar uma função que receba um vetor de inteiros V e retorne um outro vetor de inteiros alocado dinamicamente com todos os valores de V que estejam entre o valor mínimo e máximo (que também são passados como parâmetro para a função). A função deve obedecer ao seguinte protótipo:

```
int* valores_entre(int *v, int n, int min, int max, int *qtd);
```

#### A função recebe:
- v: vetor de números inteiros;
- n: a quantidade de elementos do vetor v;
- min: valor mínimo a ser buscado;
- max: valor máximo a ser buscado.

#### A função deve:
- Verificar a quantidade de elementos do vetor que sejam maiores do que min e menores que max;
- Caso a quantidade seja maior do que 0 (zero), alocar dinamicamente uma área do exato tamanho necessário para armazenar os valores;
- Copia os elementos do vetor que sejam maiores do que min e menores que max para a área alocada dinamicamente.

#### A função retorna:
- O endereço da área alocada dinamicamente, preenchida com os números maiores do que min e menores que max, ou NULL, caso essa relação de números não tenha sido criada;
- A quantidade de números carregados na área alocada dinamicamente, através do parâmetro qtd.

#### Em seguida, crie a função principal do programa para inicializar um vetor de inteiros, exibir esses valores na tela e pedir para o usuário digitar o valor mínimo e máximo a ser buscado. Em seguida o programa deverá chamar a função valores_entre e exibir na tela os valores resultantes. Lembre-se de exibir uma mensagem de erro caso nenhum valor seja encontrado. Não se esqueça de liberar a memória alocada dinamicamente.

### 3 - Crie uma função que receba como parâmetros dois vetores de inteiros, v1 e v2, e as suas respectivas quantidades de elementos, n1 e n2. A função deverá retornar um ponteiro para um terceiro vetor, v3, com capacidade para (n1 + n2) elementos, alocado dinamicamente, contendo a união de v1 e v2. Por exemplo, se v1 = {11, 13, 45, 7} e v2 = {24, 4, 7,16, 81, 10, 12}, v3 irá conter {11, 13, 45, 7, 24, 4, 16, 81, 10, 12}.Caso o número de elementos da união seja menor do que a capacidade alocada, reduza a memória alocada para o vetor v3 de acordo com a capacidade utilizada. O cabeçalho dessa função deverá ser o seguinte: 

```
int* uniao(int *v1, int n1, int *v2, int n2, int *qtd);
```

#### Em seguida, crie a função principal do programa para chamar a função uniao passando dois vetores informados pelo usuário (ou declarados estaticamente). Em seguida, o programa deve exibir na tela os elementos do vetor resultante. A quantidade de números carregados na área alocada dinamicamente deverá ser retornada por meio do parâmetro qtd. Não esqueça de liberar a memória alocada dinamicamente.

### 4 - Desenvolva um programa que calcule a soma de duas matrizes MxN de números reais (double). A implementação deste programa deve considerar as dimensões fornecida pelo usuário (Dica: represente a matriz através de variáveis do tipo double **, usando alocação dinâmica de memória).

## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!