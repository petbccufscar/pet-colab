# Teoria da Computação - Exercícios Aula 3

## Linguagens Regulares - Propriedades, Expressões Regulares

> Fonte: `TC-Ex3.pdf`. Notação matemática normalizada e diagramas preservados do original.

## 1

Descreva os conjuntos denotados pelas expressões regulares sobre o alfabeto $\Sigma=\{0,1\}$.

- **a)** $0\mid 10^*$
- **b)** $(0\mid 1)0^*$
- **c)** $(0011)^*$
- **d)** $(0\mid 1)^*1(0\mid 1)^*$
- **e)** $0^*11^*0$
- **f)** $0(0\mid 1)^*0$
- **g)** $\varnothing^*$
- **h)** $(\varepsilon\mid 0)(\varepsilon\mid 1)$
- **i)** $(000^*\mid 1)^*$
- **j)** $(0^*\mid 0^*11(1\mid 00^*11)^*)(\varepsilon\mid 00^*)$

## 2

Determine, para cada linguagem sobre o alfabeto $\Sigma=\{0,1\}$ abaixo, uma expressão regular que a denote. Admita a convenção $|x|_0$ como sendo o número de símbolos 0 que ocorrem na cadeia $x\in\Sigma^*$.

- **a)** $\{0\}\Sigma^*\{1\}$
- **b)** $\Sigma^*\{01\}$
- **c)** $\{x\in\Sigma^*\mid |x|_0\geq 3\}$
- **d)** $\{x\in\Sigma^*\mid |x|_1\text{ é par}\}$
- **e)** $\{x\in\Sigma^*\mid x\text{ não possui dois 0's e não possui dois 1's consecutivos}\}$

## 3

Seja o autômato finito não determinístico:

$$
M=\langle\{q_0,q_1,q_2\},\{0,1\},\delta,q_0,\{q_2\}\rangle,
$$

com o mapeamento $\delta$ dado por:

| Estado | 0 | 1 |
| --- | --- | --- |
| q₀ | {q₁, q₂} | {q₀} |
| q₁ | {q₀, q₁} | ∅ |
| q₂ | {q₀, q₂} | {q₁} |

Pede-se: descreva $L(M)$ por uma expressão regular.

## 4

Seja o AFND $M=\langle Q,\Sigma,\delta,q_0,F\rangle$, onde:

$$
Q=\{q_0,q_1,q_2,q_3\},\quad\Sigma=\{0,1\},\quad F=\{q_3\}.
$$

O mapeamento $\delta$ é dado por:

| Estado | 0 | 1 |
| --- | --- | --- |
| q₀ | {q₀} | {q₁} |
| q₁ | {q₂} | {q₁, q₃} |
| q₂ | ∅ | {q₂, q₃} |
| q₃ | {q₃} | ∅ |

Pede-se: descreva por uma expressão regular a linguagem $L(M)$.

## 5

Seja o autômato finito com movimento vazio ($\varepsilon$) $M$, dado por $M=\langle Q,\Sigma,\delta,q_0,F\rangle$, onde:

$$
Q=\{q_0,q_1,q_2,q_3\},\quad\Sigma=\{0,1\},\quad F=\{q_3\}.
$$

O mapeamento $\delta$ é dado por:

| Estado | 0 | 1 | ε |
| --- | --- | --- | --- |
| q₀ | ∅ | {q₀} | {q₁} |
| q₁ | {q₃} | {q₁} | {q₀} |
| q₂ | {q₂} | ∅ | ∅ |
| q₃ | {q₂} | {q₃} | ∅ |

Pede-se:

- **a)** Obtenha um AFD equivalente a $M$ que tenha um número mínimo de estados.
- **b)** Escreva a expressão regular que denota $L(M)$.

## 6

Construa autômatos finitos que reconheçam as sentenças denotadas pelas seguintes expressões regulares:

- **a)** $10\mid(0\mid 11)0^*1$
- **b)** $01(((10)^*\mid 111)^*\mid 0)^*1$
- **c)** $1^*\mid 1^*(011)^*(1^*(011)^*)^*$
- **d)** $(0\mid 01\mid 10)^*$
- **e)** $(11\mid 0)^*(00\mid 1)^*$

## 7

Encontre as expressões regulares dos autômatos finitos descritos a seguir:

**a)** $M_a=(\{a,b,c\},\{0,1\},\delta_a,a,\{a\})$.

| δₐ | 0 | 1 |
| --- | --- | --- |
| a | a | b |
| b | c | b |
| c | a | b |

**b)** $M_b=(\{a,b,c\},\{0,1\},\delta_b,a,\{b,c\})$.

| δᵦ | 0 | 1 |
| --- | --- | --- |
| a | b | c |
| b | a | c |
| c | b | a |

**c)** $M_c=(\{a,b\},\{0,1\},\delta_c,a,\{b\})$.

| δ꜀ | 0 | 1 |
| --- | --- | --- |
| a | b | a |
| b | a | b |

Para as expressões regulares obtidas no exercício anterior, encontre expressões regulares mais simples que sejam equivalentes.

## 8

Sejam os AFDs $M_1$ e $M_2$ descritos pelos diagramas de transição de estados a seguir:

![Diagramas dos autômatos M₁ e M₂ do exercício 8](assets/listas/ex3-q8.png)

Sabendo-se que:

$$
L(M_1)=\{x\in\{0,1\}^*\mid x\text{ é um número binário maior que zero, sem sinal e múltiplo de 3}\}
$$

$$
L(M_2)=\{x\in\{0,1\}^*\mid x\text{ é um número binário maior que zero, sem sinal e par}\}.
$$

Utilizando as propriedades das linguagens regulares, pede-se para construir um autômato finito $M$, a partir de $X_1$ e $X_2$, que reconheça a linguagem:

$$
L=\{x\in\{0,1\}^*\mid x\text{ é um número binário ímpar, maior que zero, sem sinal e múltiplo de 3}\}.
$$

> O original escreve $X_1$ e $X_2$ nesse trecho, embora os autômatos sejam identificados como $M_1$ e $M_2$.

## 9

Sejam os autômatos finitos:

![Diagramas dos autômatos M₁ e M₂ do exercício 9](assets/listas/ex3-q9.png)

que aceitam as linguagens:

$$
L(M_1)=\{x\in\{0,1\}^*\mid |x|_0\bmod 3=|x|_1\bmod 3\},
$$

$$
L(M_2)=\{x\in\{0,1\}^*\mid |x|\text{ não contém dois 1's consecutivos}\}.
$$

> O uso de $|x|$ na segunda definição reproduz o original; a condição se refere à cadeia $x$.

Utilizando as propriedades das linguagens regulares, pede-se para construir um autômato finito $M$, a partir de $M_1$ e $M_2$, que aceite a linguagem $L$, dada por:

$$
L=\{x\in\{0,1\}^*\mid |x|_0\bmod 3=|x|_1\bmod 3
\text{ e }x\text{ deve conter dois 1's consecutivos}\}.
$$

## 10

Considere os autômatos finitos $M_1$ e $M_2$ a seguir:

![Diagramas dos autômatos M₁ e M₂ do exercício 10](assets/listas/ex3-q10.png)

Utilizando as propriedades das linguagens regulares, e a partir de $M_1$ e $M_2$, construa os autômatos finitos descritos a seguir:

- **a)** $M_3$ tal que $L(M_3)=L(M_1)^*$.
- **b)** $M_4$ tal que $L(M_4)=L(M_1)\cdot L(M_2)$.
- **c)** $M_5$ tal que $L(M_5)=L(M_1)\cup L(M_2)$.
- **d)** $M_6$ tal que $L(M_6)=(\operatorname{complemento}(L(M_1))\cup L(M_2))^*$.
- **e)** $M_7$ tal que $L(M_7)=L(M_1)\cap L(M_2)$.

## 11

Mostre que, se $L$ é uma linguagem regular, então:

$$
L^R=\{x\mid\text{a cadeia reversa de }x\text{ está em }L\}
$$

também é uma linguagem regular.

A reversa de uma cadeia $x$, que denotaremos por $x^r$, é a cadeia formada pelos símbolos de $x$ em reverso. Por exemplo: $(011)^r=110$.

## 12

Mostre que, se $L$ é uma linguagem regular, então:

$$
\operatorname{INIC}(L)=\{x\mid xy\in L\}
$$

também é uma linguagem regular.

## 13

Mostre que, se $L$ é uma linguagem regular, então:

$$
\operatorname{FIM}(L)=\{y\mid xy\in L\}
$$

também é uma linguagem regular.

## 14

Mostre que, se $L$ é uma linguagem regular, então:

$$
L'=\{a_2a_1a_4a_3a_6a_5\ldots a_na_{n-1}\mid a_1a_2a_3\ldots a_n\in L\}
$$

também é uma linguagem regular.

## 15

Prove que as linguagens a seguir não são linguagens regulares:

- **a)** $L_a=\{0^n1^n\mid n\geq 0\}$.
- **b)** $L_b=\{0^n\mid n\geq 0\text{ é um número primo}\}$.
- **c)** $L_c=\{xx^r\mid x\in\{0,1\}^*\text{ e }x^r\text{ é a cadeia reversa de }x\}$.
- **d)** $L_d=\{xx\mid x\in\{0,1\}^*\}$.
- **e)** $L_e=\{x\in\{0,1\}^*\mid |x|_0=|x|_1\}$.
