# Lista de Exercícios 4

#### Professor
[![Mario](https://img.shields.io/badge/Mario_San_Felice-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)](https://site.dc.ufscar.br/docente/5cee7e5d48365a001679f750)

## Ordenação

### 1. **Correção da Intercalação:**
   - A seguinte solução do problema da intercalação está correta? Quais são os invariantes do `while`? (Observe que a função realiza a intercalação in loco, ou seja, sem usar vetor auxiliar.) Qual é o consumo de tempo?
```c
    int i, k, x;
    i = p;
    while (i < q && q < r) {
        if (v[i] >= v[q]) {
            x = v[q];
            for (k = q - 1; k >= i; --k)
                v[k+1] = v[k];
            v[i] = x;
            ++q;
        }
        ++i;
    }
```
    
### 2. **Implementação do mergeSort:**
   - Considere a seguinte implementação do mergeSort:
```c
    void mergeSort (int p, int r, int v[]) {
        if (p < r-1) { // 1
            int q = (p + r)/2; // 2
            mergeSort (p, q, v); // 3
            mergeSort (q, r, v); // 4
            intercala (p, q, r, v); // 5
        }
    }
```
   - **a)** O que acontece se trocarmos `(p < r-1)` por `(p < r)` na linha // 1? A função termina? Por que?
   - **b)** O que acontece se trocarmos `(p + r)/2` por `(p + r - 1)/2` na linha // 2? Os subproblemas sempre diminuem? Por que?
   - **c)** O que acontece se trocarmos `(p + r)/2` por `(p + r + 1)/2` na linha // 2? Os subproblemas sempre diminuem? Por que?

### 3. **Versão Decrescente do mergeSort:**
   - Escreva uma versão recursiva do algoritmo mergeSort que rearranje um vetor `v[p..r-1]` em ordem decrescente. Será preciso reescrever o algoritmo da intercalação.

### 4. **Verificação de Arranjo:**
   - Suponha que um vetor `v[p..r]` está arrumado se existe `j` em `p..r` tal que `v[p..j-1] <= v[j] < v[j+1..r]`. Escreva um algoritmo que decida se `v[p..r]` está arrumado. Em caso afirmativo, o seu algoritmo deve devolver o valor de `j`.

### 5. **Crítica à função separa:**
   - Critique a seguinte variante da função separa. Quais são os invariantes?
  
```c
    int separa (int v[], int p, int r) {
        int c = v[p], i = p+1, j = r, t;
        while (i <= j) {
            if (v[i] <= c)
                ++i;
            else {
                t = v[i], v[i] = v[j], v[j] = t;
                --j;
            }
        }
        v[p] = v[j], v[j] = c;
        return j;
    }
```

### 6. **Implementação do quickSort:**
   - Considere a seguinte implementação do quickSort:
```c
    void quicksort (int v[], int p, int r) {
        int j; // 1
        if (p < r) { // 2
            j = separa (v, p, r); // 3
            quicksort (v, p, j-1); // 4
            quicksort (v, j+1, r); // 5
        }
    }
```
   - **a)** O que acontece se trocarmos `p < r` por `p != r` na linha 2? A função termina? Por que?
   - **b)** O que acontece se trocarmos `j-1` por `j` na linha 4? Os subproblemas sempre diminuem? Por que?
   - **c)** O que acontece se trocarmos `j+1` por `j` na linha 5? Os subproblemas sempre diminuem? Por que?

## Material Auxiliar

Para revisar conceitos sobre ordenação e encontrar mais exercícios acesse:

- [MergeSort](https://www.ime.usp.br/~pf/algoritmos/aulas/mrgsrt.html)
- [QuickSort](https://www.ime.usp.br/~pf/algoritmos/aulas/quick.html)
  
## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!
