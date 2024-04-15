# Gabarito Lista de Exercícios 2

#### Professor
![Helio](https://img.shields.io/badge/Helio_Crestana_Guardia-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)


## Vetorização: processamento SIMD em CPU

### Questão 1

Extensões SIMD (Single Instruction, Multiple Data) são conjuntos de instruções em processadores que permitem realizar operações simultâneas em vários elementos de dados. Elas são usadas para melhorar o desempenho em tarefas que envolvem processamento paralelo, como gráficos, processamento de imagem e áudio. Exemplos incluem SSE e AVX da Intel, e NEON em arquiteturas ARM. Essas extensões aceleram operações ao processar múltiplos dados ao mesmo tempo.

### Questão 2 

Em C, as extensões SIMD podem ser usadas por meio de bibliotecas otimizadas (como OpenBLAS, Intel MKL) ou intrínsecos SIMD. Intrínsecos são funções específicas do compilador que permitem o uso direto de instruções SIMD

### Questão 3 

A vetorização é particularmente eficaz em operações que podem ser realizadas simultaneamente em vários elementos de dados, como operações em arrays. Um exemplo comum é a soma de dois arrays. Aqui está um trecho de código em C que realiza a soma de dois arrays e pode ser vetorizado:

```c
#include <stdio.h>

void vector_add(int *a, int *b, int *result, int n) {
    for (int i = 0; i < n; i++) {
        result[i] = a[i] + b[i];
    }
}

int main() {
    int size = 1000;
    int array1[size];
    int array2[size];
    int result[size];

    // Inicialização dos arrays (pode variar conforme a necessidade)
    for (int i = 0; i < size; i++) {
        array1[i] = i;
        array2[i] = 2 * i;
    }

    // Chamada da função que realiza a soma vetorizada
    vector_add(array1, array2, result, size);

    // Impressão dos resultados
    printf("Resultado da soma:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", result[i]);
    }

    return 0;
}
```

### Questão 4 

O uso de extensões SIMD em programas que realizam operações aritméticas em dados vetorizados pode resultar em melhorias significativas de desempenho. As extensões SIMD permitem a execução de uma única instrução em vários elementos de dados simultaneamente, aumentando a taxa de processamento. Isso é especialmente benéfico em tarefas intensivas em computação, como processamento de imagem e áudio. A vetorização usando SIMD pode reduzir o overhead de loop, melhorar a eficiência energética e, muitas vezes, pode ser otimizada automaticamente pelo compilador.

### Questão 5 

A vetorização é favorecida por condições como:
**Dados Contíguos em Arrays:** Os dados devem ser armazenados de forma contígua na memória, idealmente em arrays.

**Tamanho Significativo dos Dados:** A vetorização é mais eficaz para conjuntos de dados de tamanho considerável.

**Alinhamento de Memória:** Alinhar os dados na memória de acordo com os requisitos da arquitetura SIMD é benéfico.

**Operações Simples e Independentes:** Operações aritméticas simples e independentes favorecem a vetorização.

**Loops com Padrões Similares:** Loops que realizam operações semelhantes em diferentes dados são bons candidatos.

**Uso de Intrínsecos SIMD ou Diretivas de Compilador:** Intrínsecos SIMD ou diretivas de compilador podem facilitar a vetorização.

**Conjuntos de Dados Grandes:** A vetorização é mais eficaz em conjuntos de dados grandes.

O sucesso depende da capacidade do compilador e, em alguns casos, ajustes manuais podem ser necessários.


## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!