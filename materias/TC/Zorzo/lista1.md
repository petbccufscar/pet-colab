# Lista de Exercícios 1

#### Professor
![Sergio Zorzo](https://img.shields.io/badge/Sergio_Zorzo-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)


## Alfabeto e Gramática

### 1 - Seja o alfabeto ∆ = { } e considere a cadeia z =   sobre o alfabeto ∆.
#### Escreva as cadeias zz, z3, z0 e determine seus comprimentos.
#### Escreva o fecho de ∆.


### 2 - Seja o alfabeto Γ = { 0, 1} e considere as cadeias x = 01 e y = 110 sobre o alfabeto Γ. Escreva as cadeias xy, xyx, (xy)^2 e (yxx)^0. Escreva os conjuntos Γ^2, Γ^∗e Γ^+.

### 3 - Escreva uma função recursiva que calcule a soma dos elementos positivos do vetor de inteiros v[0..n-1]. O problema faz sentido quando n é igual a 0? Quanto deve valer a soma nesse caso?

### 4 - Construir uma gramática que gere a linguagem regular
#### L ={w ∈ {0,1}∗| w contém um número par de 0’s e um número par de 1’s }

### 5 - Classificar as gramáticas abaixo em Estrutura de Frase, Sensível ao Contexto, Livre de Contexto ou Regular e forneça a linguagem gerada por cada uma delas.

![Gramaticas](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/TC/imagem_2024-03-19_154706229.png)


### 6 - Construir uma gramática que gere a linguagem livre de contexto
```
L = { a^n b^m c^n| n,m ≥ 0}
```



### 7 - Construir gramáticas regulares para as linguagens regulares sobre o alfabeto Σ={0,1} dadas a seguir.

#### a) L1 = 0^+ 1^+ = { 0^n 1^m | n,m > 0 }

#### b) L2 = 0^∗ 1^∗= { 0^n 1^m | n,m ≥ 0 }

#### c) L3 = ( 0 1 )^ + = { (0 1)^n | n > 0 }


### 8 - Construir uma gramática que gere a linguagem L = { w | w ∈ { ( , ) }^∗ e w está balanceada }
#### Uma cadeia está balanceada se satisfazer todas as condições abaixo:

#### a) w = ε está balanceada.
#### b) se w está balanceada, então ( w ) está balanceada.
#### c) se x e y são cadeias balanceadas, então xy também está balanceada.
#### d) nenhuma outra cadeia está balanceada.


### 9 - Seja G = < N, Σ, Ρ, S > uma gramática onde todas as regras de produção são da forma A → u B ou A → u, onde A,B ∈ N e u ∈ Σ^∗. Mostre que L(G) é uma linguagem regular.


## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!