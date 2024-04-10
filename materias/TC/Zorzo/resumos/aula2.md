# Resumo Aula 2
> Resumo criado pelo aluno [João Pedro Trevisan](https://www.linkedin.com/in/joao-pedro-trevisan)

#### Professor
![Sergio Zorzo](https://img.shields.io/badge/Sergio_Zorzo-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)


## Videos

- [TCOMP-1.5](https://www.youtube.com/watch?v=LmBb4zepO2Q&list=PLuARAw3cqFRBLFB9VuGbwFyh_RehmBX1c&index=5&pp=iAQB)

- [LFA04](https://www.youtube.com/watch?v=OAOt9BQpSBE&list=PLqlIQgAFrQ14oDPZliY1-tyupYs0prBmW&index=4&t=738s&pp=iAQB)

- [LFA05](https://www.youtube.com/watch?v=VHUWYy9PB3U&list=PLqlIQgAFrQ14oDPZliY1-tyupYs0prBmW&index=5&pp=iAQB)

- [TCOMP-2.2](https://www.youtube.com/watch?v=0jC59NBgyxU&list=PLuARAw3cqFRBLFB9VuGbwFyh_RehmBX1c&index=6&pp=iAQB)

- [LFA07](https://www.youtube.com/watch?v=hq41dwJFjpw&list=PLqlIQgAFrQ14oDPZliY1-tyupYs0prBmW&index=7&pp=iAQB)

- [TCOMP-2.6](https://www.youtube.com/watch?v=69pu-0Nr6RE&list=PLuARAw3cqFRBLFB9VuGbwFyh_RehmBX1c&index=11&pp=iAQB)

- [TCOMP-2.7](https://www.youtube.com/watch?v=2lok-m5ogKc&list=PLuARAw3cqFRBLFB9VuGbwFyh_RehmBX1c&index=12&pp=iAQB)

- [LFA09](https://www.youtube.com/watch?v=jn-W2N1Mc7k&list=PLqlIQgAFrQ14oDPZliY1-tyupYs0prBmW&index=9&pp=iAQB)

- [UFC5](https://www.youtube.com/watch?v=T3hJSDEqRJg&list=PLYLYA7XrlskMAn9hVe0tSAO_zg7tt0hr6&index=6&pp=iAQB)

- [UFC6](https://www.youtube.com/watch?v=bcNxJyK5yow&list=PLYLYA7XrlskMAn9hVe0tSAO_zg7tt0hr6&index=7&pp=iAQB)

- [LFA10](https://www.youtube.com/watch?v=RUtxRCzI9cg&list=PLqlIQgAFrQ14oDPZliY1-tyupYs0prBmW&index=10&pp=iAQB)

- [LFA11](https://www.youtube.com/watch?v=stvS8lb1o6E&list=PLqlIQgAFrQ14oDPZliY1-tyupYs0prBmW&index=11&pp=iAQB)

- [UFC7.2](https://www.youtube.com/watch?v=bcNxJyK5yow&list=PLYLYA7XrlskMAn9hVe0tSAO_zg7tt0hr6&index=7&pp=iAQB).


---
## ATENÇÃO
O Professor Zorzo usa a nomenclatura dos autômatos em inglês. Isso significa que as siglas usadas em aula podem diferir das siglas usadas no vídeo.

Este resumo é feito para concordar com as aulas, uma vez que seus exercícios e provas terão a nomenclatura usada nelas. Ainda assim, aqui tem uma lista de significados e equivalências:

- DFA = **A**utômato **F**inito **D**eterminístico, **D**efinite **F**inite **A**utomata
- NFA = **A**utômato **F**inito **N**ão Determinístico, **N**on-deterministic **F**inite **A**utomata
- εNFA = **A**ut. **F**in. **N**ão Det. com Transições Vazias


## Linguagens Regulares e Sistemas de Estados Finitos
Quando tratamos de linguagens regulares, existem 3 formalismos de estudo com utilidades diferentes:
1. Autômato Finito:
	- Formalismo operacional (reconhecedor de sentenças)
2. Expressão Regular:
	- Formalismo denotacional (gerador de sentenças)
3. Gramática regular:
	- Formalismo axiomático (formador de sentenças)

Sistemas de estados finitos são os mais simples modelos computacionais e a forma com a qual os enxergaremos é a de modelos matemáticos que descrevem um sistema com entrada e saída.

Sistemas de estados finitos tem uma quantidade pré-definida de estados que mostram a situação atual e passada do sistema. Além disso existe um conjunto de transições que expressa os movimentos possíveis de um estado para outro e um dispositivo hipotético chamado de controle que lê as entradas externas e move o sistema de um estado para outro.

Os Autômatos Finitos Determinísticos (conhecidos como DFAs) possuem uma definição formal denotada como "DFA M" ou "AF-d M" na forma:

M=(Q, Ʃ, δ, q0, F), onde
Q = Conjunto finito de estados
Ʃ = Conjunto finito de símbolos de entrada
δ = Função de transição
q0 = Estado inicial ∈Q
F = um conjunto de estados finais, ou de aceitação (F ⊆ Q)

Tomemos como exemplo o autômato M1 que reconhece a linguagem 
L = {w | w possui *aa* ou *bb* como subpalavra}

M1 = ({a, b}, {q0, q1, q2, qf}, δ, q0, {qf})

![Aula02_img01.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/TC/Aula02_img01.png)

δ é dado pela tabela.

Vale a pena estudar o slide do Zorzo pra ver mais exemplos.

Quando um autômato recebe uma cadeia de entrada ele a processa e produz uma saída binária que aceita ou rejeita a cadeia. A cadeia em questão é processada da esquerda para a direita começando do estado inicial do autômato, após ler um símbolo move-se de acordo com a função de transição daquele estado. A saída do autômato vem depois de completa a leitura da cadeia.

Quanto ao projeto de autômatos finitos determinísticos, não há regras. Eles geralmente são criados através de tentativa e erro e por isso podem acabar não sendo autômatos mínimos (coisa que abordaremos adiante).

Existem portanto diferentes autômatos que serão capazes de reconhecer as mesmas linguagens e nestes casos eles serão equivalentes. L(M1) = L(M2). A linguagem L só é dita regular se existe um autômato finito M tal que L = L(M).

Um outro tipo de autômato é o NFA, o Autômato Finito Não Determinístico. Seu não determinismo implica que a partir de um determinado estado e símbolo lido ele pode assumir mais que um estado diferente.

Este não determinismo não aumenta o poder computacional do autômato, mas torna mais fácil a criação de soluções para nós humanos. Todos os DFA podem ser convertidos em NFA.

O não determinismo do autômato sob estudo ficará evidente no diagrama quando houverem mais que uma ou nenhuma seta apontando para um estado. Já na tabela, observaremos uma tabela cujas células podem conter zero ou mais estados, diferente da tabela de um DFA que é uniformemente preenchida.

Assim como um DFA, os NFA tem a forma M=(Q, Ʃ, δ, q0, F).

É possível converter todo NFA em um DFA e na maioria dos casos eles terão o mesmo número de estados, porém mais transições. A conversão consiste em pegar todas combinações de estados e agregar as transições do NFA, cada combinação de estados do NFA é um estado do DFA. Nos slides 64 ~ 78 há um exemplo simples.

Há também um segundo tipo de autômato finito não determinístico que é o Autômato Finito com Movimentos Vazios. O movimento vazio contido neste formalismo é a generalização de movimentos não determinísticos, ele consiste de uma transição sem leitura de símbolo. Vale lembrar que isso também não aumenta o poder computacional do autômato e que os εNFA podem ser convertidos em NFAs que podem se tornar DFAs.

Bem como seus antecessores, o εNFA tem a forma M=(Q, Ʃ, δ, q0, F).

No diagrama, quando puder ser realizado um movimento vazio de um estado para outro basta indicar com uma seta com o símbolo lambda ou epsolon. Na tabela deverá haver uma coluna para os movimentos vazios também.

![Aula02_img02.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/TC/Aula02_img02.png)

## Equivalência entre Autômatos

### Equivalência NFA -> DFA
Autômatos finitos não determinísticos e autômatos finitos determinísticos. Por teorema, a classe dos autômatos finitos determinísticos é equivalente a classe dos autômatos finitos não determinísticos.

Essa conversão pode ser feita algoritmicamente, seguem os passos:
1. Construir a tabela do NFA que queremos converter.
2. Construir a nova tabela do DFA que queremos criar:
	- Seus estados serão as combinações de estados possíveis do NFA
	- O total de estados será 2^n
	- Para um estado que é um conjunto, o novo estado será a união das transições
3. Marcar os novos estados finais
	- Todos estados que contiverem um estado final em seu conjunto
4. Eliminar estados...
	- ...Inalcançáveis
	- ...Não finais que não possuem saída
5. Verificar se há no grafo algum ciclo inalcançável

**Passo 1:** Tomamos o autômato e geramos sua tabela.

![Aula02_img09.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/TC/Aula02_img09.png)

**Passo 2**: Criamos a tabela do DFA que estamos buscando. No nosso caso ela terá 2³ estados.

![Aula02_img10.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/TC/Aula02_img10.png)

Para ver a tabela sendo feita passo a passo veja o vídeo [LFA11](https://youtu.be/stvS8lb1o6E?list=PLqlIQgAFrQ14oDPZliY1-tyupYs0prBmW&t=199). Para facilitar a construção do grafo do nosso autômato, faz bem nomear cada estado na nossa tabela, veja:

![Aula02_img11.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/TC/Aula02_img11.png)

**Passo 3**: Nossos estados finais são aqueles que possuem em seu conjunto o estado **q2**. Isto é:
- S2
- S4
- S5
- S6

**Passo 4**: Os estados inalcançáveis são mais facilmente eliminados se seguirmos uma ordem:
- Quais estados não são alcançados por ninguém?
	- S1, S5 e S7
- Retirados estes estados, mais algum estado não é mais alcançado?
	- S2 não é mais alcançado pro outros estados

Feito isso, nossa tabela estará assim:

![Aula02_img12.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/TC/Aula02_img12.png)

**Passo 5**: Desenhamos o grafo e vemos que ele não possui loops inalcançáveis

![Aula02_img13.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/TC/Aula02_img13.png)


### Equivalência εNFA -> NFA
Autômatos Finitos Não Determinísticos e Autômtos finitos com movimentos vazios. Esses dois autômatos são equivalentes por teorema.

Para transformar um εNFA não há um algoritmo, mas quando houver um movimento vazio analisaremos ambos o estado de origem quanto o estado destino e substituímos *lambda* por todos os símbolos de um dado alfabeto. Depois disso analisaremos caso a caso.

Note o exemplo a seguir:

![Aula02_img06.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/TC/Aula02_img06.png)

Nosso primeiro passo é substituir *lambda* por todos os símbolos do alfabeto:

![Aula02_img07.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/TC/Aula02_img07.png)

Agora, tendo como parâmetro o autômato original devemos avaliar se os mesmos movimentos são possíveis. Vejamos:

No original deve ser possível chegar a qualquer estado sem nenhum custo, portanto nos perguntamos "estando em q0, eu devo consumir algo além de *a* para chegar a q1?", a resposta é não, então mantemos o *a* naquela transição.

Estando em q1, eu consigo chegar a q2 consumindo apenas um *b* que era exigido no original? Sim, portanto está correto o *b* naquela transição.

Ainda que no q0 original eu não saiba consumir *b* eu poderia ir para q1 pela transição vazia e consumir lá, então não há problemas em banter *b* na primeira transição. O mesmo vale entre q1 e q2 para mantermos *a* na segunda transição.

Temos um problema pois no original deveria ser possível estar em q0, receber um *b* e chegar à q2. Da mesma forma, deveríamos ser capazes de chegar de q0 a q2 recebendo apenas um símbolo *a*. Portanto devemos adicionar mais uma transição:

![Aula02_img08.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/TC/Aula02_img08.png)

Perceba que ainda falta algo. Deveria ser possível receber 2 transições vazias e chegar a um estado final, ou seja, finalizar sem consumir nada. Para resolver isso q0 deve ser um estado de aceitação, mas eu não vou colocar uma imagem nova.

As outras equivalências (εNFA -> NFA e DFA -> NFA) não serão exemplificadas aqui, existem exemplos nos slides do professor Zorzo.

## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!
