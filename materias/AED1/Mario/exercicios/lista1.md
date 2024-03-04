# Lista de Exercícios 1

#### Professor
[![Mario](https://img.shields.io/badge/Mario_San_Felice-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)](https://site.dc.ufscar.br/docente/5cee7e5d48365a001679f750)


## Recursão

### 1 - A função abaixo promete encontrar o valor de um elemento máximo de v[0..n-1]. A função cumpre a promessa?

```c
int maxI (int n, int v[]) {
    int j, m = v[0];
    for (j = 1; j < n; ++j)
        if (v[j-1] < v[j]) m = v[j];
    return m;
}
```
### 2 - Critique a seguinte função recursiva; ela promete encontrar o valor de um elemento máximo de v[0..n-1].

```c
int maximoR1 (int n, int v[]) {
    int x;
    if (n == 1) return v[0];
    if (n == 2) {
        if (v[0] < v[1]) return v[1];
        else return v[0];
    }
    x = maximoR1 (n-1, v);
    if (x < v[n-1]) return v[n-1];
    else return x;
}
```

### 3 - Escreva uma função recursiva que calcule a soma dos elementos positivos do vetor de inteiros v[0..n-1]. O problema faz sentido quando n é igual a 0? Quanto deve valer a soma nesse caso?

### 4 - Escreva uma função recursiva que calcule a soma dos dígitos de um inteiro estritamente positivo n. A soma dos dígitos de 132, por exemplo, é 6.

### 5 - Critique a seguinte função recursiva:

```c
int XX (int n) {
    if (n == 0) return 0;
    else return XX (n/3+1) + n;
}
```

### 6 - 6 - Régua inglesa [Sedgewick 5.8, Roberts 5.11] Escreva uma função recursiva que imprima uma régua de ordem n no intervalo [0..2^n]. O traço no ponto médio da régua deve ter comprimento n,os traços nos pontos médios dos subintervalos superior e inferior devem ter comprimento n-1, e assim por diante. A figura mostra uma régua de ordem 4.
```
.
. -
. --
. -
. ---
. -
. --
. -
. ----
. -
. --
. -
. ---
. -
. --
. -
```

### 7 - O que faz a função f descrita a seguir?

```c
int f (int *v, int n) {
    int m;
    if (n==0) return 0;
    m = f (v, n-1);
    if (v[n-1] == 0) return m;
    v[m] = v[n-1];
    return m+1;
}
```


### Material auxiliar
- https://www.ime.usp.br/~pf/algoritmos/aulas/recu.html


## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!