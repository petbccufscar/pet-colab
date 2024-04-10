# Resumo Aula 1
> Resumo criado pelo aluno [João Pedro Trevisan](https://www.linkedin.com/in/joao-pedro-trevisan)

#### Professor
![Sergio Zorzo](https://img.shields.io/badge/Sergio_Zorzo-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)


## Videos

- [LFA01](https://www.youtube.com/watch?v=XZUz2qjfZos&list=PLqlIQgAFrQ14oDPZliY1-tyupYs0prBmW&index=3&t=905s&themeRefresh=1)

- [LFA02](https://www.youtube.com/watch?v=FZt3AyxTSQQ&list=PLqlIQgAFrQ14oDPZliY1-tyupYs0prBmW&index=4&t=1052s)

- [TCOMP 5.1](https://www.youtube.com/watch?v=CMVkufkjSko&list=PLuARAw3cqFRBLFB9VuGbwFyh_RehmBX1c&index=28)

- [TCOMP 5.2](https://www.youtube.com/watch?v=NvL3qRQLMVI&list=PLuARAw3cqFRBLFB9VuGbwFyh_RehmBX1c&index=30)

- [TCOMP 5.3](https://www.youtube.com/watch?v=nNVLI-etVCs&list=PLuARAw3cqFRBLFB9VuGbwFyh_RehmBX1c&index=31)

- [TCOMP 5.4](https://www.youtube.com/watch?v=ATq4ut2bO9Y&list=PLuARAw3cqFRBLFB9VuGbwFyh_RehmBX1c&index=30) 

- [TCOMP 5.5](https://www.youtube.com/watch?v=rUcpMRQar_c&list=PLuARAw3cqFRBLFB9VuGbwFyh_RehmBX1c&index=31)


## Conceitos Básicos
A Teoria da Computação como conhecemos hoje teve seu inicio na década de 50 com teorias relacionadas a linguagens naturais. O campo da linguística é muito relacionado com a área de Linguagens Formais e Autômatos (outro nome desse curso).

A aplicação das teorias linguísticas sobre a computação enxerga aspectos léxicos, sintáticos e semânticos nas linguagens, em modelagem de sistemas, em desenho de hardware dentre outras áreas contrapostas com linguagens naturais.

Sobre linguagens de programação, por exemplo, podemos vê-las livremente e sem qualquer significado associado de uma interpretação. 

No campo da sintaxe temos as propriedades livres da linguagem, isto é, sua forma e isso é usado para verificação gramatical de programas, por exemplo.

Quanto a semântica, encontra-se através dela a interpretação para a linguagem, coisa que se manifesta como os significados dos termos e valores em um dado programa de computador.

Dito isso, a sintaxe nos é útil para a manipulação de símbolos sem considerar seus significados ao passo que a semântica "complementa" o processo. Se um programa é sintaticamente errado ele simplesmente não é um programa, já dizer que um programa é correto não significa dizer que ele se comporta da maneira esperada, só significa que ele não viola regras sintáticas e portanto é um programa.

Existem 3 abordagens para se olhar para linguagens na teoria da computação, elas são:
- Operacional
	- Autômatos com estados e instruções primitivas que modificam os estados.
	- Máquinas abstratas suficientemente simples e não ambíguas com presença de um *formalismo reconhecedor* que analisa uma entrada a fim de verificar se ela é reconhecida pela máquina.
	- Alguns exemplos de autômatos e máquinas são o **automato finito**, o **autômato com pilha** e a **máquina de turing**.
- Axiomática
	- Associa regras que permitem afirmar o que será verdadeiro após a ocorrência de cada cláusula considerando o que era verdadeiro em um momento anterior.
	- Possui formalismos axiomáticos como **Gramáticas Regulares**, **Gramáticas Livre de Contexto**, **Gramáticas Sensíveis ao Contexto** e **Gramáticas Irrestritas**.
- Denotacional
	- Possui o conceito de Domínio Sintático que permite a caracterização do conjunto de palavras admissíveis na linguagem. Trata-se de funções composicionais cuja saída é especificada em termos dos valores denotados por suas subcomponentes.
	- Existem também os Formalismos Denotacionais como as Expressões Regulares. Também chamados de Formalismos Geradores.

Um dos conceitos mais importantes a serem estudados é a chamada **Hierarquia de Chomsky** expressa na imagem a seguir:

![Aula01_img01.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/TC/Aula01_img01.png)

Alguns exemplos de uso de cada tipo de linguagem na computação podem fazer você se interessar mais por essa matéria, aqui vão alguns:

**Linguagens Regulares**:
- Estudos biológicos de redes de neurônios
- Circuítos de chaveamentos
- Analisadores léxicos de compiladores
- Editores de texto
- Sistemas de pesquisa
- RegEx

**Linguagens Livres de Contexto**:
- Analisadores sintáticos para compiladores (muito importante)

**Linguagens Recursivamente Enumeráveis/Sensíveis ao Contexto**:
- Máquina de Turing
- Reconhecedores e geradores de linguagens
- Solucionabilidade de reconhecedores de linguagens

### De Alfabetos à Gramáticas
Para a definição de **linguagem** é necessário antes definir elementos mais básicos, o mais básico desses elementos é o **caractere** (símbolo) definido como símbolo indivisível abstrato, daí podemos definir um **alfabeto** como um conjunto finito de caracteres.

Um **alfabeto** é comumente denotado pelo símbolo Σ e exemplos de alfabeto são:
- Σ1 = {x, y, z}
- Σ2 = {0, 1, 2, 3, 4, 5, ..., 9}
- Σ3 = {}

Um alfabeto não pode ser definido como Σ = {aba, a, bb, b, bba, ...} pois seus caracteres não são atômicos, são concatenações.

Existe também o **fecho de um alfabeto** expresso por Σ*, o fecho significa todas as palavras possíveis sobre Σ. Além do mais, temos o **fecho positivo de um alfabeto** dado por Σ+, significando Σ* menos a palavra vazia explicada adiante.

Com o uso de um alfabeto podemos formar **palavras** e surgem então conceitos importantes. Em primeiro lugar uma palavra consiste de um conjunto de símbolos pertencentes a um dado alfabeto, diz-se então que uma palavra com caracteres de um alfabeto Σ é uma "palavra sobre Σ".

No que tange as palavras, temos o símbolo ε que simboliza a palavra vazia. ε é palavra sobre todo alfabeto.

Além disso temos os seguintes conceitos:
- **Prefixo**: Qualquer sequência INICIAL de símbolos de uma palavra. ε é prefixo de toda palavra.
- **Sufixo**: Qualquer sequência FINAL de símbolos de uma palavra. ε é sufixo de toda palavra.
- **Subpalavra**: Qualquer sequência de símbolos contíguos (lado a lado) de uma palavra. Todo prefixo e sufixo são subpalavras.
- **Comprimento de uma palavra**: Denotado por |palavra|, é o número de caracteres em uma palavra. |ε| = 0

Podemos realizar operações sobre palavras e caracteres como por exemplo a concatenação:
- **Concatenação**: juntar duas palavras ou caracteres como "b" + "a" = "ba".
	- O elemento neutro da concatenação é o ε.
	- A concatenação é associativa. v(wt) = (vw)t = vwt.
	- A **concatenação sucessiva** acontece quando escrevemos por exemplo a⁵ que é igual a "aaaaa".

Vamos ao conceito de **Linguagem Formal**, seu significado mais simples é "um subconjunto de Σ*", ou seja, uma porção das palavras possíveis dentro de um alfabeto. A notação que usamos para uma linguagem formal é um **L** maiúsculo.

Linguagens formais podem ser até mesmo as linguagens {} e {ε} que são linguagens sobre qualquer alfabeto.

Em termos gerais, **gramáticas** são conjuntos finitos de regras que quando aplicadas sucessivas vezes geram palavras, o conjunto de todas as palavras geradas por uma gramática definem uma linguagem.

A definição formal de uma gramática, também chamada de "gramática de Chomsky" ou "gramática irrestrita" é dada por uma quádrupla da forma **G = (V,T,P,S)** na qual:
- **G** simboliza a gramática em questão.
- **V** é o conjunto finito de símbolos **variáveis** (**não terminais**).
- **T** constitui o conjunto finito de símbolos **terminais**.
- **P** reúne as **regras de produção**.
- **S** contém a(s) **varável**(eis) **inicial**(ais).

As notações tomadas para as regras de produção são uma lista de pares da forma a -> b (a leva a b); ou uma lista a -> b, a -> c, ..., a -> n; ou ainda usando o símbolo **|** para simbolizar uma disjunção lógica (OU lógico) em uma lista como a -> b | c | ... | n.

Das regras de produção vem o **processo de derivação**, denotado pelo símbolo =>, que consiste em aplicá-las sucessivas vezes de forma a gerar uma palavra, vamos a um exemplo:

A partir da gramática a seguir tentaremos derivar a palavra "666".

G = (V, T, P, S)
V = {N, D}
T = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
P = {
N -> D,
N -> DN,
D -> 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
}
S = {N}

N => DN => 6N => 6DN => 66N => 66D => **666**

Este exemplo é simplório comparado com o que será explorado nessa matéria, contudo ele mostra muito bem o processo de derivação. A **definição informal** da **linguagem** anterior é de "linguagem que constitui todos os número naturais" (sem dar atenção ao tipo de gramática ou sua eficiência).

Uma possível **definição formal** da linguagem anterior é L(G) = {w | w ∈ N} (w *tal que* w pertence ao conjunto dos naturais). A notação L(G) simboliza a **linguagem gerada**.

Como convenção e forma de ler as gramáticas usaremos letras maiúsculas para variáveis, letras minúsculas de a ~ t para símbolos terminais e letras de u ~ z para palavras feitas de símbolos terminais.

As gramáticas podem ser definidas segundo a **hierarquia de Chomsky** que estudamos anteriormente, a seguir listamos os tipos de gramática e as condições para sua classificação:
- **Gramática com Estrutura de Frase**, **GEF**, (**Tipo 0**):
	Uma gramática será do tipo 0 se suas regras de produção são da forma:
		α ∈ (V U T)+ e β ∈ (V U T)\*, isto é, as cadeias α e β são formadas por símbolos definidos na gramática (terminais ou não terminais) e a cadeia α não pode ser vazia.
- **Gramática Sensível ao Contexto**, **GSC**, (**Tipo 1**):
	São as gramáticas com regras de produção que seguem o formato:
		α ∈ (V U T)+ e β ∈ (V U T)\* e | α | ≤ | β | (exceto quando β = ε ), ou seja, as cadeias α e β são formadas por símbolos terminais ou não terminais e a cadeia α tem que ser menor que a cadeia β a não ser que β seja vazia.
- **Gramática Livre de Contexto**, **GLC**, (**Tipo 2**):
	O tipo 2 pede que as gramáticas sejam formadas segundo:
		α ∈ V e β ∈ (V U T)\*, que significa dizer que as cadeias α e β são formadas por símbolos terminais ou não terminais com a cadeia α sendo um símbolo não terminal.
- **Gramática Regular**, **GR**, (**Tipo 3**):
	Por fim, o tipo 3 exige a forma:
		α ∈ V e β ∈ T U (V x T)\*, trocando em miúdos, as cadeias α e β são formadas por símbolos definidos na gramática (terminais ou não) e a cadeia α tem que ser um símbolo não terminal enquanto a cadeia β tem que ser um símbolo terminal sozinho ou um símbolo terminal seguido de um não terminal.

O tipo da linguagem é determinado pela menor classe da gramática que ela gera.

As gramáticas do tipo 3 podem ser descritas por **gramáticas lineares**, estas gramáticas tem as formas:
- Gramática Linear à Direita – **GLD**
	- Regras de produção da forma A -> wB ou A -> w
- Gramática Linear à Esquerda – **GLE**
	- Regras de produção da forma A -> Bw ou A -> w
- Gramática Linear Unitária à Direita – **GLUD**
	- Regras de produção da forma A -> wB ou A -> com |w| <= 1
		- *Esta será utilizada no curso do Zorzo*.
- Gramática Linear Unitária à Esquerda – **GLUE**
	- Regras de produção da forma A -> Bw ou A -> com |w| <= 1

## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!
