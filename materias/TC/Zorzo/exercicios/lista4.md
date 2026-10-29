# Lista 3 - Teoria da Computação

> Fonte: `TC2023_lista4.pdf`. O título acima reproduz o PDF, embora o nome do arquivo indique lista 4. A notação matemática foi normalizada; inconsistências do enunciado foram mantidas e sinalizadas.

## 1

Construa uma gramática livre de contexto que gere a linguagem:

$$
L = \{0^i1^j2^k \mid i=j \text{ ou } j=k,\quad i,j,k>0\}.
$$

## 2

Construa autômatos com pilha não determinísticos que aceitem a linguagem gerada pelas gramáticas livres de contexto:

**a)** $G_1=(\{S\},\{a,b\},S,P_1)$, com:

$$
P_1=\{S\to aSbb\mid aab\}.
$$

**b)** $G_2=(\{S,A,B\},\{a,b\},S,P_2)$, com:

```text
S → aABB | aAA
A → aBB | a
B → bBB | A
```

**c)** $G_3=(\{S\},\{a,b\},S,P_3)$, com:

```text
S → AA | a
A → AS | b
```

> No original, o conjunto de variáveis de $G_3$ contém apenas $S$, embora as produções também utilizem $A$.

## 3

Dado o autômato com pilha não determinístico:

$$
M=(\{q_0,q_1,q_2\},\{a,b\},\{a,b,z\},\delta,q_0,z,\{q_2\}),
$$

com as transições:

$$
\begin{aligned}
\delta(q_0,a,z)&=\{(q_1,a),(q_2,\varepsilon)\},\\
\delta(q_1,b,a)&=\{(q_1,b)\},\\
\delta(q_1,b,b)&=\{(q_1,b)\},\\
\delta(q_1,a,b)&=\{(q_2,\varepsilon)\}.
\end{aligned}
$$

- **a)** Qual a linguagem aceita pelo autômato de pilha não determinístico?
- **b)** Enumere as 8 primeiras cadeias aceitas por [enunciado incompleto no original].
- **c)** Desenhe um diagrama (digrafo) de transições de estado para esse autômato.

## 4

Considere o autômato com pilha abaixo e responda às perguntas:

$$
M=(\{q_0,q_1,q_2\},\{a,b,c,d,e\},\{z,B\},\delta,q_0,z,\{q_2\}),
$$

onde:

$$
\begin{aligned}
\delta(q_0,a,z)&=\{(q_0,z)\},\\
\delta(q_0,a,B)&=\{(q_0,B)\},\\
\delta(q_0,b,z)&=\{(q_0,zB)\},\\
\delta(q_0,b,B)&=\{(q_0,BB)\},\\
\delta(q_0,c,z)&=\{(q_1,z)\},\\
\delta(q_0,c,B)&=\{(q_1,B)\},\\
\delta(q_1,d,B)&=\{(q_1,\varepsilon)\},\\
\delta(q_1,e,z)&=\{(q_1,z)\},\\
\delta(q_1,e,B)&=\{(q_1,B)\},\\
\delta(q_0,\varepsilon,z)&=\{(q_2,\varepsilon)\}.
\end{aligned}
$$

- **a)** Desenhe um diagrama (digrafo) de transições de estado para esse autômato.
- **b)** Verifique se a cadeia `abaabceedd` é aceita, mostrando a sequência de movimentos executados pelo autômato.
- **c)** Qual é a linguagem aceita pelo autômato?

## 5

Verifique se as linguagens geradas pelas gramáticas, cujas produções estão representadas abaixo, são vazias, finitas ou infinitas:

**a)**

```text
S → AB | CA
A → a
B → BC
C → AB | ε
```

**b)**

```text
S → aS | aSbS | X
X → SS
```

## 6

Dada a gramática $G=(\{E,T,F\},\{+,*,[,],x\},P,E)$, onde:

```text
E → T | E+T
T → F | T*F
F → [E] | x
```

Como é feito o reconhecimento da sentença `[x+x]` pelo algoritmo de Early?

> O nome “Early” foi mantido como no original (algoritmo de Earley).

## 7

Dado o autômato finito com movimento vazio (considere $\varepsilon$ o símbolo épsilon):

| Estado | 0 | 1 | ε |
| --- | --- | --- | --- |
| → q₀ | {q₀} | ∅ | {q₁} |
| q₁ | ∅ | {q₁} | {q₂} |
| * q₂ | {q₂} | ∅ | ∅ |

Pede-se:

- **a)** Encontre o autômato finito determinístico equivalente.
- **b)** Usando o método de eliminação de estados, descreva a linguagem aceita por esse autômato finito por uma expressão regular.

## 8

A seguinte linguagem não é livre de contexto:

$$
L=\{a^nb^nc^n\mid n\geq 0\}.
$$

Utilizando o lema do bombeamento, prove por absurdo que a linguagem não é livre de contexto.

## 9

Construa um autômato a pilha que reconheça as sentenças da linguagem $L$:

$$
L=\{w=(a+b)^nc^n\mid \operatorname{nro}(a)+\operatorname{nro}(b)=\operatorname{nro}(c)
\text{ e }w\text{ não contém dois }b\text{'s consecutivos}\}.
$$

## 10

Considere o seguinte autômato finito com movimento vazio ($\varepsilon$-movimento):

$$
\begin{aligned}
Q&=\{q_0,q_1,q_2\},\\
\Sigma&=\{0,1\},\\
q_0&=q_0,\\
F&=\{q_2\}.
\end{aligned}
$$

As transições são:

$$
\begin{aligned}
\delta(q_0,\varepsilon)&=\{q_1\},\\
\delta(q_1,0)&=\{q_1\},\\
\delta(q_1,1)&=\{q_2\},\\
\delta(q_2,\varepsilon)&=\{q_0\}.
\end{aligned}
$$

Construa autômato finito determinístico equivalente por meio do método de eliminação de estados.

> A solicitação do método de eliminação de estados para construir o AFD foi mantida conforme o original.

## 11

Para as gramáticas abaixo, construa as gramáticas equivalentes na FNC e FNG.

- **a)** $L_1=\{w\mid w\text{ é expressão regular sobre o alfabeto }\{x\}\}$.
- **b)** Faça um comparativo das gramáticas originais com as correspondentes na Forma Normal de Chomsky e na Forma Normal de Greibach.

## 12

Como fora discutido no exercício anterior para as gramáticas da linguagem $L_1=\{w\mid w\text{ é expressão regular sobre o alfabeto }\{x\}\}$, faça o reconhecimento da entrada `(x+x)*` para o algoritmo de reconhecimento Cocke-Younger-Kasami (CYK).

## 13

Dada a árvore a seguir:

![Árvore sintática da expressão x+x*x](assets/listas/lista4-q13.png)

Representação textual da mesma árvore:

```text
E
├── E
│   └── x
├── +
└── E
    ├── E
    │   └── x
    ├── *
    └── E
        └── x
```

Escreva a derivação mais à esquerda da sentença `x+x*x`.
