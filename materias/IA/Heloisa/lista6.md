# Lista de Exercícios 6

#### Professor
![Heloisa](https://img.shields.io/badge/Heloisa-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)

## Aprendizado de Máquina

### 1 - Uma árvore de decisão deve ser construída para determinar se uma pessoa deve ou não esperar por uma mesa em um restaurante. Os dados disponíveis registram casos de clientes que frequentam restaurantes e cada dado é descrito pelos atributos: cliente, que indica quantas pessoas estão no restaurante (com valores nenhum, algum e cheio); faminto, que indica se o cliente estava ou não faminto quando chegou (com valores sim ou não); tipo, que indica o tipo do restaurante (com valores frances, italiano, tailandês ou só serve hambúrguer) e sex/sab, que indica se é sexta ou sábado (com valores sim ou não). Construa uma árvore de decisão completa para o conjunto de dados da tabela a seguir, selecionado aleatoriamente os atributos de cada nó da árvore (sem cálculo de ganho de informação).

| Exemplo | Cliente | Faminto | Tipo       | Sex/sab | Esperar |
|---------|---------|---------|------------|---------|---------|
|    1    | Alguns  | Sim     | Francês    | Não     | Sim     |
|    2    | Cheio   | Sim     | Tailandês  | Não     | Não     |
|    3    | Alguns  | Não     | Hamburguer | Não     | Sim     |
|    4    | Cheio   | Sim     | Tailandês  | Sim     | Sim     |
|    5    | Cheio   | Não     | Francês    | Sim     | Não     |
|    6    | Alguns  | Sim     | Italiano   | Não     | Sim     |
|    7    | Nenhum  | Não     | Hamburguer | Não     | Não     |
|    8    | Cheio   | Sim     | Hamburguer | Sim     | Sim     |
|    9    | Cheio   | Não     | Hamburguer | Sim     | Não     |
|   10    | Nenhum  | Não     | Tailandês  | Não     | Não     |

### 2 - Calcule o ganho de informação do atributo “Cliente” para os dados do exercício anterior.

### 3 - Considere o conjunto de dados com três atributos (A1, A2 e A3) e uma classe binária (Classe). Construa uma árvore de decisão com esses dados, usando o algoritmo ID3. Indique, a cada passo, o atributo escolhido em cada nó e os exemplos de cada classe cobertos pelo ramo sendo construído. (Dica: usar a tabela de logaritmos do exercício 10).

| Exemplos | A1 | A2 | A3  | Classe |
|----------|----|----|-----|--------|
| X1       | a  | 1  | sim | 0      |
| X2       | b  | 1  | não | 0      |
| X3       | a  | 0  | sim | 0      |
| X4       | a  | 0  | não | 1      |
| X5       | a  | 1  | não | 1      |


### 4 - Considere o conjunto de dados com dois atributos (A1, A2) e uma classe binária (Classe). Supondo que uma árvore de decisão vai ser construída com esses dados, Calcule o ganho de informação e a razão de ganho para cada um dos atributos A1 e A2. Qual atributo seria escolhido para ser atribuído à raiz da árvore, por cada um dos dois critérios de seleção de atributos? (Dica: usar a tabela de logaritmos do exercício 10).

| Exemplos | A1   | A2 | Classe |
|----------|------|----|--------|
| X1       | sim  | x  | 0      |
| X2       | não  | y  | 0      |
| X3       | sim  | x  | 0      |
| X4       | não  | z  | 1      |
| X5       | não  | y  | 1      |

### 5 - Considerando as transações dadas a seguir, gere todas as regras de associação possíveis a partir do 3- itemset {mouse, teclado, impressora} e seus respectivos valores de confiança. Os valores de suporte dos 1- itemsets são dados abaixo. Considerar duas casas decimais para todos os cálculos.

| Tr | Itens comprados                    |
|----|------------------------------------|
| 1  | mouse                              |
| 2  | teclado, vídeo, mouse, impressora  |
| 3  | teclado, impressora, mouse, vídeo  |
| 4  | vídeo                              |
| 5  | vídeo, impressora, mouse, teclado  |
| 6  | vídeo, mouse, teclado, impressora  |
| 7  | teclado, impressora, mouse         | 

| Itemsets     | Transações       | Suporte    |
|--------------|------------------|------------|
| {mouse}      | 1, 2, 3, 5, 6, 7 | 6/7 = 86%  |
| {teclado}    | 2,3,5,6,7        | 5/7 = 71%  |
| {video}      | 2,3,4,5,6        | 5/7 = 71%  |
| {impressora} | 2,3,5,6,7        | 5/7 = 71%  |

#### *(Tabela construída para auxiliar o cálculo da confiança das regras – Não precisa ser construída)*

| Itemsets                     | Transações       | Suporte    |
|------------------------------|------------------|------------|
| {mouse}                      | 1, 2, 3, 5, 6, 7 | 6/7 = 86%  |
| {teclado}                    | 2,3,5,6,7        | 5/7 = 71%  |
| {video}                      | 2,3,4,5,6        | 5/7 = 71%  |
| {impressora}                 | 2,3,5,6,7        | 5/7 = 71%  |
| {mouse, teclado}             | 2,3,5,6,7        | 5/7 = 71%  |
| {mouse, impressora}          | 2,3,5,6,7        | 5/7 = 71%  |
| {teclado, impressora}        | 2,3,5,6,7        | 5/7 = 71%  |
| {mouse, teclado, impressora} | 2,3,5,6,7        | 5/7 = 71%  |

```
3-itemset com 71% de suporte: {mouse, teclado, impressora}

Regras geradas:
mouse -> teclado, impressora
confiança = suporte{mouse, teclado, impressora} / suporte{mouse} = 71/86 = 83%
teclado -> mouse, impressora
confiança = suporte{mouse, teclado, impressora} / suporte{teclado} = 71/71 = 100%
impressora -> mouse, teclado
confiança = suporte{mouse, teclado, impressora} / suporte{impressora} = 71/71 = 100%
mouse, teclado -> impressora
confiança = suporte{mouse, teclado, impressora} / suporte{mouse,teclado} = 71/71 = 100%
mouse, impressora -> teclado
confiança = suporte{mouse, teclado, impressora} / suporte{mouse,impressora} = 71/71 = 100%
teclado, impressora -> mouse
confiança = suporte{mouse, teclado, impressora} / suporte{teclado,impressora} = 71/71 = 100%
```

### 6 - A base de dados dada na tabela a seguir contém transações de pedidos de uma lanchonete. Encontre os k-itemsets que tenham suporte mínimo de 60%. Encontre as regras de associação geradas pelos 3-itemsets frequentes considerando confiança de 60%.

| Tr | Itens comprados                       |
|----|---------------------------------------|
| 1  | fritas, hamburger, suco               |
| 2  | hamburger, suco, fritas, salada       |
| 3  | cheeseburger, suco                    |
| 4  | fritas, salada                        |
| 5  | hamburger, fritas, suco, cheeseburger |

### 7 - Um classificador foi gerado para um determinado problema com três classes, a, b, c e após os testes, a matriz de confusão mostrada abaixo foi encontrada. Calcule as métricas de acurácia, precisão, revocação e medida F, por classe, para essa matriz de confusão.


|   | a | b | c |
|---|---|---|---|
| a | 5 | 0 | 0 |
| b | 0 | 3 | 1 |
| c | 1 | 2 | 12|

### 8 - Considerando o conjunto de dados da tabela abaixo, calcule o índice de redução de desvio padrão (SDR) para os atributos x1 (com ponto de divisão entre 10 e 16) e x2 (com ponto de divisão entre 85 e 90). Diga qual dos dois atributos seria escolhido durante um processo de construção da árvore de regressão com constantes nas folhas.

| dados  | x1   | x2   | y    |
|--------|------|------|------|
| 1      | 2    | 45   | 0,3  |
| 2      | 10   | 90   | -1,6 |
| 3      | 7,5  | 80   | -0,4 |
| 4      | 8    | 85   | -0,2 |
| 5      | 16,5 | 100  | 0,3  |
| 6      | 16   | 82,5 | 0,8  |
| 7      | 18   | 90   | 1,6  |
| 8      | 18,5 | 85   | 1,7  |

### 9 - A figura abaixo mostra uma árvore de regressão com constantes nas folhas gerada a partir de um conjunto de dados para fazer previsão do consumo de carros. Calcule o erro médio quadrático obtido com o uso dessa árvore de regressão para os dados de teste mostrados na tabela.

![Arvore](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/IA/imagem_2024-03-19_183520437.png)

### 10 - Uma árvore de decisão deve ser construída a partir dos dados relacionados na tabela a seguir, usando o algoritmo C4.5. Os atributos A1 e A2 são nominais e o atributo A3 é contínuo. Calcule o ganho de informação do atributo A3. Utilize a tabela de logaritmos (arredondado para duas casas decimais) para fazer os cálculos. (Dica: um conjunto em que todos os dados são da mesma classe tem entropia 0. Um conjunto com número igual de dados em cada classe tem entropia 1.)

| Exemplos | A1 | A2 | A3 | Classe |
|----------|----|----|----|--------|
| 1        | a  | 1  | 31 | 0      |
| 2        | b  | 1  | 32 | 0      |
| 3        | a  | 0  | 29 | 1      |
| 4        | b  | 0  | 30 | 1      |
| 5        | a  | 1  | 35 | 1      |
| 6        | a  | 0  | 36 | 1      |

| n    | log2n | nlog2n |
|------|-------|--------|
| 0,25 | -2,00 | -0,50  |
| 0,33 | -1,60 | -0,53  |
| 0,5  | -1,00 | -0,50  |
| 0,66 | -0,60 | -0,40  |
| 0,75 | -0,42 | -0,31  |
| 1    | 0,00  | 0,00   |

#### Calcular a entropia do conjunto de dados original S:
```
E(S) = -1/3*log21/3 – 2/3*log22/3 = 0,53 + 0,40 = 0,93
```


#### Calcular o ganho de informação de cada atributo:

##### Atributo A1
```
Valor a: 3, 5, 6 (classe 1) 1 (classe 0)
Valor b: 4 (classe 1) 2 (classe 0)
E(a) = -0,75* log20,75 – 0,25*log20,25 = (-0,75 * (-0,31) – (0,25 * -2 = 0,31 + 0,5 = 0,81
E(b) = -0,5* log20,5 – 0,5*log20,5 = 1
E_Restante(A1) = 4/6 * 0,81 + 2/6 * 1 = 0,66 * 0,81 + 0,33 = 0,5346 + 0,33 = 0,8646
Ganho de informação (A1) = E(S) – E_Restante(A1) = 0,93 – 0,8646 = 0,0654
```

##### Atributo A2
```
Valor 0: 3, 4, 6 (classe 1)
Valor 1: 5 (classe 1) 1,2 (classe 0)
E(0) = -1* log21 – 0*log20 = 0
E(1) = -0,33* log20,33 – 0,66*log20,66 = 0,53 + 0,40 = 0,93
E_Restante(A2) = 1/2 * 0 + 1/2 * 0,93 = 0,465
Ganho de informação (A2) = E(S) – E_Restante(A2) = 0,93 – 0,465 = 0,465
```

##### Atributo A3 (contínuo)
```
Ordenando os exemplos pelos valores do atributo A3
Os pontos de divisão são entre 30 e 31 e entre 32 e 35.
Dividindo entre 30 e 31:
Valores <= 30: 3, 4(classe 1)
Valores > 30: 1,2 (classe 0) 5,6, (classe 1)
E(<=30) = 0
E(>30) = 1
E_Restante(A3-1) = 4/6 * 1 = 0,66
Ganho de informação (A3-1) = 0,93 – 0,66 = 0,27
Dividindo entre 32 e 35:
Valores <= 32: 3, 4(classe 1) 1,2 (classe 0)
Valores > 32: 5,6 (classe 1)
Exemplo A1 A2 A3 Classe
1 a 1 31 0
2 b 1 32 0
3 a 0 29 1
4 b 0 30 1
5 a 1 35 1
6 a 0 36 1

n log2n nlog2n
0,25 -2,00 -0,50
0,33 -1,60 -0,53
0,5 -1,00 -0,50
0,66 -0,60 -0,40
0,75 -0,42 -0,31
1 0,00 0,00

E(<=32) = 1
E(>32) = 0
E_Restante(A3-2) = 4/6 * 1 = 0,66
Ganho de informação (A3-2) = 0,93 – 0,66 = 0,27
```
**O atributo escolhido é o atributo A2 que tem o maior ganho de informação.**

### 11 - Suponha que o algoritmo de agrupamento de dados K-means vai ser aplicado nos dados não rotulados da tabela abaixo, para k=2 e com medida de similaridade baseada em distância Euclidiana (similaridade entre x1 e x2 é definida como sim(x1,x2) = 1-Dist(x1,x2)). Os valores dos centróides iniciais foram definidos como c1 = (1,5; 2) e c2 = (4,3). Faça a atribuição dos dados aos clusters usando a medida de similaridade definida e recalcule os centróides. (Dica: fazer um gráfico no plano Cartesiano, com os dados como pontos e encontrar a similaridade visualmente com o auxílio do gráfico.)

| ID | x1 | x2 |
|----|----|----|
| 1  | 0  | 0  |
| 2  | 0  | 2  |
| 3  | 1  | 1  |
| 4  | 1  | 3  |
| 5  | 3  | 2  |
| 6  | 4  | 2  |
| 7  | 5  | 1  |
| 8  | 5  | 2  |
| 9  | 6  | 6  |


## Contato
Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!