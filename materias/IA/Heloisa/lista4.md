# Lista de Exercícios 4

#### Professor
![Heloisa](https://img.shields.io/badge/Heloisa-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)

## Representação do Conhecimento e Raciocínio

### 1 - Construa as sentenças da lógica de primeira ordem na forma de cláusulas definidas de primeira ordem que representam as sentenças em linguagem corrente dadas na sequência, assumindo os seguintes predicados:

#### *( Cláusulas definidas de primeira ordem são cláusulas atômicas ou uma implicação cgujo antecedente é uma conjunção de literais positivos e cujo conseqüente é um único literal positivo. Em sentenças em que as variáveis são quantificadas universalmente, o quantificador é omitido. Em sentenças quantificadas existencialmente, a variável deve ser substituída por uma constante, por meio da regra de inferência instanciação existencial.)*

```
Programa(x) “x é um programa”
Bom(x) “x é bom”
Assiste(x) “o público assiste x”
Horário(x, y) “x passa no horário y”
Gosta(x) “o público gosta de x”
Audiência(x,alta) “a audiência de x é alta”
Propaganda(x, y) “ a propaganda de x é y”
```

```
Se o programa é bom, então o público assiste.
Se o programa passa no horário nobre, então o público assiste.
Se o público assiste o programa e gosta, então a audiência é alta.
Se a audiência é alta, então a propaganda é cara.
Se o programa passa de madrugada, então a propaganda é barata.
```

### 2 - Descreva, passo a passo, a execução do Algoritmo de **Encadeamento para trás com busca em profundidade**, com a construção da **árvore de prova AND/OR** e da **tabela de prova** para encontrar a resposta para a pergunta “Qual o custo da propaganda do programa P1?”, para a base de conhecimento do exercício 1, assumindo que as sentenças são utilizadas na ordem em que aparecem e sabendo que o programa P1 passa no horário nobre e o público gosta.


### 3 - Descreva, passo a passo, a execução do Algoritmo de **Encadeamento para frente**, com a construção da **árvore de prova AND/OR**, para encontrar a resposta para a pergunta “Qual o custo da propaganda do programa P1?”, para a base de conhecimento do exercício 1, assumindo que as sentenças são utilizadas na ordem em que aparecem e sabendo que o programa P1 passa no horário nobre e o público gosta.

### 4 - Descreva, passo a passo, a execução do Algoritmo de **Encadeamento para trás com busca em profundidade**, com a construção da **árvore de prova AND/OR** e da **tabela de prova**, para encontrar a resposta para a pergunta “Qual o custo da propaganda do programa P2?”, para a base de conhecimento do exercício 1, assumindo que as sentenças são utilizadas na ordem em que aparecem e sabendo que o programa P2 passa de madrugada e o público gosta.

### 5 - Descreva a execução do Algoritmo de **Encadeamento para trás com busca em profundidade**, para a base de conhecimento representada em sentenças da lógica de primeira ordem (cláusulas definidas de primeira ordem) do sistema Consultor Financeiro, usando a consulta na forma Investimento(X), construindo a **árvore de prova (árvore AND/OR)** e a **tabela de prova** para os seguintes casos:

#### a) Dois dependentes, R$20.000,00 em poupança, renda estável de R$30.000,00.

#### b) Dois dependentes, R$30.000,00 em poupança, renda estável de R$30.000,00.

#### As sentenças são:

#### 1) Inadequada(Conta_poupança) -> Investimento (Poupança).

#### 2) Adequada (Conta_poupança) ^ Adequada (Renda) -> Investimento(Ações).

#### 3) Adequada (Conta_poupança) ^ Inadequada (Renda) -> Investimento(Combinação).

#### 4) Quantia_poupada(x) ^ Maior(x, 20.000) -> Adequada (Conta_poupança).

#### 5) Quantia_poupada(x) ^ ¬Maior(x,20.000) -> Inadequada (Conta_poupança).

#### 6) Ganhos(x,Estavel) ^ Maior(x, 50.000) -> Adequada (Renda).

#### 7) Ganhos(x,Estavel) ^ Dependentes(y) ^ Entre(x, 36.000,50.000) ^ Menor(y, 3) -> Adequada (Renda).

#### 8) Ganhos(x,Estavel) ^ Dependentes(y) ^ Entre(x, 36.000,50.000) ^ ¬Menor(y, 3) -> Inadequada(Renda).

#### 9) Ganhos(x,Estavel) ^ ¬Maior(x, 36.000) -> Inadequada (Renda).

#### 10) Ganhos(x,Instavel) -> Inadequada (Renda).

#### 11) Maior_ou_igual(x,y) ^ Menor_ou_igual (x,z) -> Entre(x,y,z).

#### Observação
##### *As sentenças relativas aos casos a) e b) devem ser acrescentadas à base, um caso de cada vez. Por exemplo, para o caso a), devem ser criadas as sentenças: Dependentes(2). Quantia_poupada(20.000). Ganhos(30.000,estável).*

### 6 - Uma base de conhecimento foi construída, usando cláusulas definidas de primeira ordem, para identificar problemas em um eletro-doméstico. Construa a árvore de prova (árvore AND/OR) e a tabela de prova correspondentes à execução do Algoritmo de **Encadeamento para trás com busca em profundidade** para a consulta **Problema(x)**, até encontrar uma (apenas uma) resposta para essa consulta. Antes de aplicar o algoritmo, faça a eliminação dos quantificadores universais e existencias dando o tratamento adequado a cada um deles. Os fatos acrescentados à base correspondem à seguinte situação: tem alguma lampada no ambiente e ela não acende, o usuário sentiu cheiro de fumaça. As sentenças são:

#### 1) Observou(Ruptura_fio) -> Problema(Fio_rompido)

#### 2) Falha(Alimentação) ^ Falha(Energia) -> Problema(Fuzivel_queimado)

#### 3) Falha(Alimentação) ^ Observou(Estouro) -> Problema(Fuzivel_queimado)

#### 4) ∀x Lampada(x) ^ Não_acende(x) -> Falha(Energia)

#### 5) Observou(Cheiro_fumaça) -> Falha(Alimentação)

#### Fatos:

#### 1) Ǝx Lampada(x) ^ Não_acende(x)

#### 2) Observou(Cheiro_fumaça)

### 7 - Construa todas as asserções (sentenças) da lógica de primeira ordem que correspondem aos arcos que aparecem na rede semântica dada a seguir:

![Ordem](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/IA/imagem_2024-03-19_175823171.png)


### 8 - Considere as estruturas A e B a seguir:

![Ordem](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/IA/imagem_2024-03-19_175853284.png)

#### a) Diga quais os nós relativos a objetos e classes seriam acessados em cada uma das duas estruturas e quais seriam as repostas das consultas:

##### Qual a cor de polly?
##### Qual a dieta de polly?

#### b) Caso sejam encontradas respostas diferentes para a mesma consulta em cada uma das estruturas, explique por que.


## Contato
Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!