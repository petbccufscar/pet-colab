# Resumo Aula 4
> Resumo criado pelo aluno [João Pedro Trevisan](https://www.linkedin.com/in/joao-pedro-trevisan)

#### Professor
![Sergio Zorzo](https://img.shields.io/badge/Sergio_Zorzo-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)


## Videos

- [UFC13](https://www.youtube.com/watch?v=VK2b1lW-Kss&list=PLYLYA7XrlskMAn9hVe0tSAO_zg7tt0hr6&index=14&pp=iAQB)
- [CQD-Ling liv con](https://www.youtube.com/watch?v=6G-da97ROw4&list=PLncEdvQ20-mhD_qMeLHtLnA3XDT1Fr_k4&index=35&pp=iAQB)
- [CQD-Gram liv con](https://www.youtube.com/watch?v=W88XbH2e4_w&list=PLncEdvQ20-mhD_qMeLHtLnA3XDT1Fr_k4&index=33&pp=iAQB)
- [AGO-Árvores](https://www.youtube.com/watch?v=SrXUY1vRxSQ)
- [LFA17](https://www.youtube.com/watch?v=piipVxbpkU0&list=PLqlIQgAFrQ14oDPZliY1-tyupYs0prBmW&index=19),
- [LFA18](https://www.youtube.com/watch?v=QE2bbLI5Ez8&list=PLqlIQgAFrQ14oDPZliY1-tyupYs0prBmW&index=19&pp=iAQB)
- [LFA19](https://www.youtube.com/watch?v=OsO_v6A2xCo&list=PLqlIQgAFrQ14oDPZliY1-tyupYs0prBmW&index=20&pp=iAQB)
- [LFA20](https://www.youtube.com/watch?v=Ng0Wxa-_WGg&list=PLqlIQgAFrQ14oDPZliY1-tyupYs0prBmW&index=22&pp=iAQB)
- [CQD-Bomb liv con](https://www.youtube.com/watch?v=ByQcwPhSuI0&list=PLncEdvQ20-mhD_qMeLHtLnA3XDT1Fr_k4&index=44&pp=iAQB)


## Linguagens e Gramáticas Livres de Contexto
LLCs são linguagens geradas por gramáticas livres de contexto com por exemplo L1={0^n 1^n | n >=1} ou L2={w∈Ʃ\*|w=w^R} (w^R = o reverso de w).

Uma Gramática Livre de Contexto é formalmente definida como uma 4-upla (V,Ʃ,R,S) onde:
- V é um conjunto finito de variáveis
- Ʃ é um conjunto finito de símbolos terminais, com V⋂Ʃ=Ø
- R é um conjunto finito de regras de substituição na forma:
	- x->a, onde x∈V e a∈(Ʃ⋃V)\*
- S é a variável inicial

Se a,b e w são cadeias de variáveis e terminais  A->w é uma regra de substituição, então dizemos que "aAb origina awb" e escrevemos aAb => awb (aAb deriva awb).

Algo importante de se ressaltar é que gramáticas livres de contexto podem gerar linguagens regulares, tomemos o exemplo: A -> 0A | ε. Esta gramática gera uma linguagem do tipo L3={0^k|k>=0}, o que em expressão regular pode ser denotado como 0\*. Assim, concluímos que há intersecção entre as linguagens livres de contexto e as regulares.

Na verdade, todas as linguagens regulares são englobadas pelas linguagens livres de contexto. Para provar isso tomamos L como uma linguagem regular e portanto existe um DFA que reconhece esta linguagem, se pudermos converter este autômato em uma LLC (linguagem livre de contexto) poderemos provar que toda linguagem regular é livre de contexto.

Tomemos o seguinte autômato:
![Aula04_img01.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/TC/Aula04_img01.png)

Podemos criar uma GLC (gramática livre de contexto) da seguinte forma para o definir:

![Aula04_img02.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/TC/Aula04_img02.png)

Colocando o processo de transformação de DFA para GLC em palavras devemos construir uma gramática G=(Q,Ʃ,R,q0) em que R possui uma regra do tipo X->aY para cada transição δ(X,a)=Y e uma regra X->ε para cada X∈F (X no conjunto de estados finais).

Agora, podemos mostrar que a linguagem gerada por esta gramática é a mesma linguagem reconhecida pelo DFA que é a mesma linguagem inicial. Essa prova contudo é muito longa e não consta nas aulas desse curso, mas está na lista de vídeos no início deste documento.

## Árvores de Análise Sintática
As árvores são uma representação intuitiva pra derivações. São árvores ordenadas nas quais os nós são rotulados com os lados esquerdos das regras de produção e seus filhos são os lados direitos das regras de produção.

Cada nó interior é rotulado por uma variável V, cada folha é rotulada por uma variável, símbolo terminal ou ε e se um nó interior é rotulado por A e seus filhos por x1,x2...xn isso significa que A->x1,x2...xn pertence às regras de produção desa gramática.

Para estudarmos árvores vamos tomar a seguinte gramática:
G=(V,Ʃ,R,P)
p -> ε | 0 | 1 | 0P0 | 1P1

Para realizar a derivação P=>\* 0110 teremos a seguinte árvore:

![Aula04_img03.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/TC/Aula04_img03.png)

Esta árvore é lida de baixo para cima, da esquerda para a direita:

![Aula04_img04.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/TC/Aula04_img04.png)

De forma a representar a derivação P->0P0->01P10->01ε10=0110

As árvores podem acabar indicando a ambiguidade existente nas gramáticas, vejamos o exemplo a seguir:

![Aula04_img05.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/TC/Aula04_img05.png)

Se conseguirmos montar duas árvores diferentes para uma mesma palavra ou duas derivações diferentes que resultam na mesma palavra, provamos então que a linguagem é ambígua.

A eliminação das ambiguidades pode vir tanto por meio da reescrita da gramática para alcançar uma gramática equivalente não ambígua, quanto pelo uso da associação de regras de precedência de operadores.

## Formas Normais
As formas normais vem para estabelecer restrições rígidas a definição das produções sem reduzir o poder de geração das Gramáticas Livres de Contexto. São muito usadas na prova de teoremas matemáticos e no reconhecimento de linguagens.

### Forma normal de Chomsky
[LFA18](https://www.youtube.com/watch?v=QE2bbLI5Ez8&list=PLqlIQgAFrQ14oDPZliY1-tyupYs0prBmW&index=19&pp=iAQB)

Uma gramática livre de contexto está na forma normal de Chomsky (FNC) se todas suas produções são da forma:
- A->BC ou
- A->a

Podemos, em três etapas, adequar uma gramática à FNC:
1. Simplificação da Gramática
	1. Eliminar produções inúteis
		1. Nunca é alcançada.
		2. Impossibilita chegar em uma sentença final.
	2. Eliminar produções vazias
		1. Cria-se um grupo das variáveis vazias.
		2. Criam-se produções para abarcar os casos nos quais as produções vazias influem.
		3. Verifica-se a necessidade de incluir uma produção puramente vazia na linguagem.
	3. Eliminar produções unidade (que troca de um símbolo variável pelo outro como A -> B)
		1. Eliminar qualquer estado do tipo A -> A.
		2. Criar um conjunto P' das produções não unidade.
		3. Listar os pares unidade, inclusive por transitividade (se A -> B e B -> C, então A ->C).
		4. Atribuímos às produções de P' toda geração símbolos terminais feita por variáveis fora deste conjunto.  
2. Transformação das produções que tem lado direito > 2
3. Transformação das produções que tem lado direito >=3 em produções que tenham duas variáveis
Isso só pode ser feito se a linguagem não possuir produções vazias do tipo A->ε.

Elucidando um pouco sobre a simplificação, dentro das produções inúteis que impossibilitam a chegada em uma sentença final imaginemos as seguintes regras de produção:
S -> ABC | b
A -> a
B -> b

Perceba que se tomada a derivação de ABC a partir de S, nunca seremos capazes de nos livrarmos da variável C, impossibilitando a chegada a um estado final. Removemos então este estado:
S -> b
A -> a
B -> b

Porém agora não há meios de se alcançar A ou B, o que cai no nosso primeiro tipo de produção inútil. De forma geral, para eliminar os estados inúteis bastam os passos de se conservar as derivações que geram um símbolo terminal diretamente (apenas um símbolo terminal) ou indiretamente (símbolo terminal associado de variáveis) e depois eliminar os estados inalcançáveis por meio do desenho do grafo.

O segundo passo da conversão de uma gramática para FNC é a transformação das produções que tem lado direito maior ou igual a 2 com símbolos terminais. Isto é, uma produção da forma A -> Bd não pode existir, para tanto devemos criar uma variável auxiliar **C** que nos permitirá ter então 2 regras:

A -> BC
C -> d

A solução para o passo 3 que proíbe regras de produção com mais que duas variáveis no lado direito. Se existe uma regra do tipo S -> BACD, criaremos as variáveis E e F para podermos ter produções da seguinte maneira:

S -> BE
E -> AF
F -> CD

Uma vez que durante o curso nunca foi cobrado um aprofundamento sobre a questão da simplificação, optarei por seguir o estudo das formas normais a partir daqui. Contudo, se sentir a necessidade o vídeo [LFA17](https://www.youtube.com/watch?v=piipVxbpkU0&list=PLqlIQgAFrQ14oDPZliY1-tyupYs0prBmW&index=19) contém mais informações sobre o assunto.

### Forma Normal de Greibach
[LFA19](https://www.youtube.com/watch?v=OsO_v6A2xCo&list=PLqlIQgAFrQ14oDPZliY1-tyupYs0prBmW&index=20&pp=iAQB)

Uma gramática livre de contexto é dita na Forma Normal de Greibach se suas produções tem a forma: A -> a*w*, onde *w* é uma palavra composta apenas por símbolos variáveis.

As etapas para se colocar uma gramática na FNG (Forma Normal de Greibach) são:
1. Simplificação da Gramática.
2. Renomeação das variáveis em uma ordem crescente.
	- A1, A2, A3...
3. Colocar todas produções na forma A1 -> A2*w* onde Ax > Ay.
	- Se há uma regra do tipo A2 -> A1*w* deve se substituir A1 por usas derivações. Se A1 -> B1*w* | B2*w* | B3*w* teremos então A2 -> B1*w* | B2*w* | B3*w*.
4. Exclusão das recursões à esquerda da forma A1 -> A2*w*.
	- Criamos uma variável auxiliar B e as regras B -> *w* e B -> *w*B (recursão à direita pode).
	- Se A2 foi excluído e havia alguma produção que o usava (como A2 -> b) deve-se criar uma nova regra do tipo A2 -> bB
5. Um terminal no início do lado direito de cada produção.
	- Para fazer esta inversão basta tomar nossas regras do tipo An-1 -> An*w* e então substituir o An pelas suas regras de produção.
6. Transformação das produções A -> a*w* para produções onde a palavra *w* só possa ser composta por variáveis.

## Autômatos com Pilha (Pushdown Automata, PDA)
PDAs são autômatos finitos não deterministas (o que aumenta seu poder computacional) com uma pilha de me memória auxiliar que independe da entrada e possui tamanho indefinido.

Revisando o conceito de pilha, ela é uma estrutura de dados com o comportamento chamado FILO (**f**irst **i**n, **l**ast **o**ut), isto é, o primeiro elemento a ser posto será o último a sair. Devido a este fato, é comum dizer que "a pilha acontece no topo" pois é no topo dela que os dados são inseridos (push) e retirados (pop).

A imagem a seguir mostra a notação de transição de estados em um autômato com pilha:

![Aula04_img06.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/TC/Aula04_img06.png)

Vale ressaltar que *v* é uma **palavra** gravada na pilha, ou seja, pode conter mais de um símbolo.

Existe também o símbolo **?** que indica um teste para checar se a pilha está vazia. Ele é útil para criar estados finais que só são visitados após o esvaziamento da pilha, além de outros mecanismos úteis.

O símbolo ε de vazio pode ser usado tanto para movimentos vazios de leitura na fita quanto na pilha (não lê nem move a cabeça de leitura). Ele também pode ser usado na escrita na pilha para não gravar nenhum símbolo.

A definição formal de um PDA é dada por P = (Q,Σ,Γ,δ,q0,Z0,F):
- Q = Um conjunto finito de estados.
- Σ = Um conjunto finito de símbolos de entrada.
- Γ = Um alfabeto de pilha finito – conjunto de símbolos que temos permissão para inserir na pilha (pode incluir elementos de Σ).
- δ = Função de transição – governa o comportamento do autômato.
- q0 = Estado inicial.
- Z0 = Símbolo de início – Inicialmente, a pilha do PDA consiste em uma instância desse símbolo e em nada mais.
- F = Conjunto de estados de aceitação.

Tomemos como exemplo o problema do duplo balanceamento onde queremos gerar uma cadeia do tipo w = {a^n b^n | a, b∈Σ}. Para resolver este problema temos o seguinte autômato:

![Aula04_img07.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/TC/Aula04_img07.png)

A definição formal deste autômato é:
M1 = {{q0, q1, qf}, {a, b}, {A, B}, δ, q0, ε, qf}

Ao tentar gerar a palavra "aabb", por exemplo, nosso autômato passa duas iterações em q0, onde reconhece dois símbolos *a*, não desempilha nada (ε) e empilha BB. Depois disso, vamos ao estado q1 desempilhando um *B* e sem empilhar nada, lá realizamos um loop de mesmo efeito, reconhecendo o segundo *b*, desempilhando outro B e novamente não empilhando nada. Após isso, checamos se está vazia a pilha com o símbolo **?** e então vamos para o estado de aceitação qf. Note que a transição (?,?,ε) poderia ser escrita como (ε,?,ε).

## Bombeamento em LLC
Semelhante com o Lema do Bombeamento para Linguagens Regulares, o bombeamento em LLCs pousa sobre o fato de que toda LLC tem uma propriedade que permite o bombeamento, mas esta propriedade não sinaliza que uma linguagem é livre de contexto. Sendo assim, só é possível provar que uma linguagem não é livre de contexto através do bombeamento.

O lema diz que se L é uma linguagem livre de contexto então existe um número p tal que toda cadeia *w*∈L com |*w*|>=p pode ser escrita da forma *w* = αβγλμ onde:
1. β e λ != ε
2. |βγλ| <= p
3. para todo k >= 0, α β^k γ λ^k μ ∈ L

Além disso o lema afirma que, tomado L como LLC e G=(V,Ʃ,R,S) um GLC que gera L, seja *b* a maior quantidade de símbolos do lado direito de uma regra de formação, então em qualquer árvore sintática todo nó tem no máximo *b* filhos. Sendo assim, qualquer árvore de altura *i* tem no máximo b^i folhas.

Seja então o valor *p* usado acima igual a b^(|V|+1), onde |V| = quantidade de variáveis da gramática. Assim, qualquer árvore sintática para *w* tem a altura pelo menos |V| + 1 pois b^(|V|+1) > B^|V| + 1. Isso deve valer então para a árvore com menor número de nós que gera *w*.

Podemos afirmar então que o maior caminho da raiz até uma folha tem pelo menos |V|+2 nós dos quais no mínimo |V|+1 são variáveis, pelo principio da casa dos pombos alguma variável se repete nesse caminho.

A imagem a seguir mostra como a árvore sintática chega na palavra αβγλμ:
![Aula04_img08.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/TC/Aula04_img08.png)

Tomaremos E como uma variável que se repete, sua ocorrência mais alta gera βγλ e sua ocorrência mais baixa gera γ. Como estas cadeias são geradas pela mesma variável, podemos substituir uma pela outra e ainda obter árvores sintáticas válidas

![Aula04_img09.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/TC/Aula04_img09.png)

Note que este desenho ilustra muito bem os pontos 1 e 3 do lema do bombeamento para LLCs.

## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!
