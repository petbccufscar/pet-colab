# Lista de Exercícios 2

#### Professor
![Sergio Zorzo](https://img.shields.io/badge/Sergio_Zorzo-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)


## Autômatos e Linguagem

### 1 - Descreva os conjuntos denotados pelas expressões regulares sobre o alfabeto Σ = {0,1}.

#### a) ```0 | 10*```

#### b) ```(0 | 1)0*```

#### c) ```(0011)*```

#### d) ```(0 | 1)* 1(0 | 1)*```

#### e) ```0*11*0```

#### f) ```0(0 | 1)*0```

#### g) ```∅*```

#### h) ```(ε | 0) (ε | 1)```

#### i) ```(000* | 1)*```

#### j) ```( 0* | 0*11 (1 | 00*11)*) (ε | 00* )```

### 2 - Determine para cada linguagem sobre o alfabeto Σ = {0,1} abaixo, uma expressão regular que a denote. Admita a convenção | x |0 como sendo o número de símbolos 0 que ocorrem na cadeia x ∈ Σ*.

#### a) ```{0} Σ* {1}```

#### b) ```Σ* {01}```

#### c) ```{ x ∈ Σ* | | x |0 ≥ 3}```

#### d) ```{ x ∈ Σ* | | x |1 é par}```

#### e) ```{ x ∈ Σ* | x não possui dois 0’s e não possui dois 1’s consecutivos}```


### 3 - Construa um autômato finito que reconhece as sentenças das linguagens abaixo sobre o alfabeto Σ = {0,1}.

#### a) ```L = { x ∈ {0,1}* | x não possui três 1’s consecutivos}```

#### b) ```L = { 0^m 1^n | m ≥ 0, n > 0}```

#### c) ```L = { 0* x 1* | x ∈ {0,1}* e x ≠ 101}```

#### d) ```L = { 0^2n | n > 0}```

#### e) ```L = { 0^i 1^j | i, j > 0 e i * j é um número par }```

### 4 - Considere o brinquedo abaixo:

![Brinquedo](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/TC/imagem_2024-03-19_155923383.png)

#### Bolinhas são jogadas em A . As alavancas x1 e x2 causam o desvio da bolinha para a esquerda ou para a direita. Quando uma bolinha atinge a alavanca, causa alteração no estado da alavanca, sendo que a próxima bolinha a atingir a alavanca pegará o caminho oposto. Pede-se:

#### a) Modele este brinquedo por um autômato finito, considerando que pode-se denotar uma bolinha em A como entrada 1 e uma seqüência de entrada será aceita se a última bolinha cair na saída C.

#### b) Qual é a linguagem aceita por este autômato finito?


### 5 - Seja o autômato finito não determinístico (af-nd) M = < {q0, q1, q2}, {0,1}, δ, q0,{q2} >, com o mapeamento δ dado por:

#### δ(q0,0) = {q1,q2} δ(q0,1) = {q0}
#### δ(q1,0) = {q0,q1} δ(q1,1) = { }
#### δ(q2,0) = {q0,q2} δ(q2,1) = {q1}

#### Pede-se:

#### a) encontre um autômato finito determinístico equivalente ao af-nd M dado.

#### b) encontre um autômato finito determinístico com um número mínimo de estados que seja equivalente ao af-nd dado.

#### c) descreva L(M) por uma expressão regular.


### 6 - Prove que a linguagem L definida abaixo é uma linguagem regular. L é a linguagem sobre o alfabeto {0,1} constituída pelas seqüências x tais que:

#### o primeiro símbolo de x é igual ao último, e

#### x contém pelo menos uma ocorrência do símbolo 1.

### 7 - Seja o af-nd M = < Q, Σ, δ,q0, F >, onde

#### Q = { q0, q1, q2, q3 }

#### Σ = { 0,1 }

#### F = { q3 }

#### e o mapeamento δ é dado por:

#### δ(q0,0) = {q0} δ(q0,1) = {q1}
#### δ(q1,0) = {q2} δ(q1,1) = {q1,q3}
#### δ(q2,0) = { } δ(q2,1) = {q2,q3}
#### δ(q3,0) = {q3} δ(q3,1) = { }

#### Pede-se:

#### a) Construa um af-d M’, a partir de M, tal que L(M) = L(M’)

#### b) Descreva por uma expressão regular a linguagem L(M).


### 8 - Construa um autômato finito determinístico a partir do af não determinístico M=<{a,b,c,d}, {0,1}, δ,a,{a}> , onde o mapeamento δ é dado por:

|   |  0  | 1 |
|---|-----|---|
| a |{a,b}| a |
| b |  c  | c |
| c |  d  | - |
| d |  d  | d |


### 9 - Construa um autômato finito não determinístico que reconhece todas as sentenças sobre o alfabeto {a,b,c} que possuem o mesmo valor quando tais sentenças forem avaliadas da esquerda para a direita ou da direita para a esquerda, de acordo com a tabela de multiplicação não associativa, dada a seguir.

|   | a | b | c |
|---|---|---|---|
| a | a | a | c |
| b | c | a | b |
| c | b | c | a |


### 10 - Seja o autômato finito com movimento vazio (ε) M, dado por M = < Q,Σ,δ,q0,F >, onde:

#### Q = {q0, q1, q2, q3}
#### Σ = {0, 1}
#### F = {q3}

#### e o mapeamento δ é dado por:

|    |  a   |  b   |   c  |
|----|------|------|------|
| q0 | {q0} | {q0} | {q1} |
| q1 | {q3} | {q1} | {q0} |
| q2 | {q2} | {q0} | { }  |
| q3 | {q2} | {q3} | { }  |

#### Pede-se:

#### a) Construa um af-dn M’ sem movimento vazio que seja equivalente a M.
#### b) A partir do af-nd M’, construa um af-d M’ ’ que seja equivalente a M.
#### c) A partir do af-d M’ ’, construa um af-d M’ ’ ’ que seja equivalente a M e que tenha um número mínimo de estados.
#### d) Escreva a expressão regular que denota L(M).

### 11 - Construa autômatos finitos que reconhecem as sentenças denotadas pelas seguintes expressões regulares:

#### a) 10 | (0 | 11) 0*1
#### b) 01 ( ( (10)* | 111 )* | 0 )* 1
#### c) 1* | 1* (011)* (1* (011)* )*
#### d) (0 | 01 | 10)*
#### e) (11 | 0)* (00 | 1)*

### 12 - Encontre as expressões regulares dos autômatos finitos descritos a seguir: 

#### a) Ma = ( {a,b,c}, {0,1}, δa, a, {a} )

|   | 0 | 1 |
|---|---|---|
| a | a | b |
| b | c | b |
| c | a | b |

#### b) Mb = ( {a,b,c}, {0,1}, δb, a, {b,c})

|   | 0 | 1 |
|---|---|---|
| a | b | c |
| b | a | c |
| c | b | a |

#### c) Mc = ( {a,b}, {0,1}, δc, a, {b})

|   | 0 | 1 |
|---|---|---|
| a | b | a |
| b | a | b |

### 13 - Para as expressões regulares obtidas no exercício anterior, encontre expressões regulares mais simples que sejam equivalentes.

### 14 - Construir uma gramática regular que gere a linguagem L descrita por:

#### L = {x ∈ {0,1}* | | x |0 mod 2 = 0 e | x |1 mod 2 = 1}

#### Utilizando as propriedades das linguagens regulares, construa, a partir desta gramática, um autômato finito que reconhece as sentenças da linguagem L.

### 15 - Descreva um autômato finito determinístico que aceite todas as cadeias sobre o alfabeto {0,1}, tal que toda ocorrência do símbolo 0 na sentença tenha o símbolo 1 imediatamente a sua direita. A partir deste autômato finito, construa a gramática regular que gera esta mesma linguagem.

### 16 - Sejam os af-d M1 e M2 descritos pelos diagramas de transição de estados a seguir:

![Automatos](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/TC/imagem_2024-03-19_161704084.png)

#### Sabendo-se que:

#### L(M1) = { x ∈ {0,1}* | x é um número binário maior que zero sem sinal e múltiplo de 3 }
#### L(M2) = { x ∈ {0,1}* | x é um número binário maior que zero sem sinal e par }

#### Utilizando as propriedades das linguagens regulares, pede-se para construir um autômato finito M, a partir de M1 e M2, que reconheça a linguagem:

#### L = { x ∈ {0,1}* | x é um número binário ímpar, maior que zero sem sinal e múltiplo de 3}

### 17 - Sejam os autômatos finitos:

![Automatos](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/TC/imagem_2024-03-19_161718695.png)

#### que aceitam as linguagens:

#### L (M1) = {x ∈ {0,1}* | | x |0 mod 3 = | x |1 mod 3}
#### L (M2) = {x ∈ {0,1}* | | x | não contém dois 1’s consecutivos}

#### Utilizando as propriedades das linguagens regulares, pede-se para construir um autômato finito M, a partir de M1 e M2, que aceite a linguagem L, dada por:

#### L = {x ∈ {0,1}* | | x |0 mod 3 = | x |1 mod 3 e x deve conter dois 1’s consecutivos}

### 18 - Considere os autômatos finitos M1 e M2 a seguir:

![Automatos](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/TC/imagem_2024-03-19_161848381.png)

#### Utilizando as propriedades das linguagens regulares, e a partir de M1 e M2, construa os autômatos finitos descritos a seguir:

#### a) M3 tal que L(M3) = L(M1)*
#### b) M4 tal que L(M4) = L(M1) . L(M2)
#### c) M5 tal que L(M5) = L(M1) ∪ L(M2)
#### d) M6 tal que L(M6) = (complemento ( L(M1) ) ∪ L(M2) )*
#### e) M7 tal que L(M7) = L(M1) ∩ L(M2)

### 19 - Mostre que:

#### Se L é uma linguagem regular então
#### L^R= { x | a cadeia reversa de x está em L } também é uma linguagem regular.
#### A reversa de uma cadeia x, que denotaremos por x^r, é a cadeia formada pelos símbolos de x em reverso. Por exemplo: (011)^r = 110.

### 20 - Mostre que:
#### Se L é uma linguagem regular então
#### INIC(L) = { x | xy ∈ L } também é uma linguagem regular.


### 21 - Mostre que:
#### Se L é uma linguagem regular então
#### FIM(L) = { y | xy ∈ L } também é uma linguagem regular.

### 22 - Mostre que:
#### Se L é uma linguagem regular então
#### L’ = { a2 a1 a4 a3 a6 a5. . .an an-1 | a1 a2 a3. . .an ∈ L} também é uma linguagem regular.

### 23 - Prove que as linguagens a seguir não são linguagens regulares:

#### a) La = { 0^n 1^n | n ≥ 0 }

#### b) Lb = { 0^n | n ≥ 0 é um número primo}

#### c) Lc = {x x^r | x ∈ {0,1}* e x^r é a cadeia reversa de x }

#### d) Ld = { x x | x ∈ {0,1}* }

#### e) Le = { x ∈ {0,1}* | | x | 0 = | x | 1 }


## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!