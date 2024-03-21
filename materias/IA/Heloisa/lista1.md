# Lista de Exercícios 1

#### Professor
![Heloisa](https://img.shields.io/badge/Heloisa-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)

## Resolução de Problemas por Busca Desinformada

### 1 - Considere o seguinte grafo, representando o espaço de estados para certo problema:

![Grafo](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/IA/imagem_2024-03-19_172652306.png)

#### Sendo o nó A inicial, e o nó N o objetivo, percorra este grafo usando os algoritmos de **busca em largura** e de **busca em profundidade** e apresente o conteúdo das listas OPEN e CLOSED a cada passo do algoritmo. Indicar as ações tomadas quando um nó gerado já estiver em uma das duas listas.

### 2 - O Problema dos baldes de água pode ser definido como: Existem dois baldes de água, o primeiro com capacidade para 5 litros e o segundo com capacidade para 3 litros. É possível encher qualquer um dos baldes totalmente de uma torneira ou esvaziá-los totalmente independente da quantidade de água que eles tenham, e despejar água de um para o outro, até que o que recebe a água esteja totalmente cheio ou até que aquele do qual se despeja a água esteja totalmente vazio. Supondo que os baldes estão inicialmente cheios, o objetivo é deixar 4 litros de água no balde maior e qualquer quantidade de água no balde menor. Construa a representação dos estados, o estado inicial, final e os operadores.

### 3 - Considere o problema dos baldes de água e assuma que os operadores são aplicados na ordem: 

#### 1) esvaziar balde maior; 
#### 2) esvaziar balde menor; 
#### 3) encher balde maior; 
#### 4) encherbalde menor; 
#### 5) despejar do balde maior para o menor; 
#### 6) despejar do balde menor para o maior. 

#### Aplique os métodos de **busca em largura** e **busca em profundidade**. Para cada um deles, mostre o conteúdo das listas OPEN e CLOSED passo a passo e construa a árvore de busca. Mostre a sequência de movimentos que determina a solução por cada algoritmo e compare as duas soluções.

### 4 - Considere outra versão para o problema dos baldes de água em que a capacidade dos baldes maior e menor é 7 e 5 litros, respectivamente. Aplique os algoritmos de **busca em profundidade** e **busca em profundidade fixa até nível 7**. Para cada um dos algoritmos, construa a árvore de busca e mostre a sequência de movimentos que determina a solução. Compare e comente as duas soluções encontradas.

### 5 - O problema dos jarros é definido como: Existem 3 jarros com capacidade para 12, 8 e 3 litros, respectivamente, e uma torneira. É possível encher os jarros de uma torneira (um de cada vez), esvaziá-los totalmente (um de cada vez) ou despejar água de um para o outro até encher o vaso de destino ou até esvaziar totalmente o vaso de origem. Supondo que os jarros estão inicialmente cheios, o objetivo é deixar um litro de água em qualquer um dos jarros. Defina uma formulação para esse problema e aplique o método de **busca em largura** mostrando a árvore de busca até o nível 2.


### 6 Considere um espaço de estados onde o estado inicial é o número 1 e cada estado k tem dois sucessores: os números 2k e 2k+1. Desenhe a parte do espaço de estados que vai do estado 1 ao 15. Supondo que o estado objetivo é 11, Liste a ordem em que os estados são gerados para a **busca em largura**, **busca em profundidade com limite 3** (até nível 3) e **busca em profundidade iterativa**.

### 7 - O problema do mundo do aspirador de pó pode ser também formulado como: Um cenário é representado por uma grade de 2X2, sendo que cada quadrado pode ter ou não sujeira. Um aspirador de pó pode se mover nesse cenário, com os seguintes movimentos: aspirar a sujeira; andar para a esquerda; andar para a direita; andar para cima; andar para baixo. Os operadores devem ser aplicados na ordem: 

#### 1) aspirar; 
#### 2) mover à direita; 
#### 3) mover para baixo; 
#### 4) mover à esquerda; 
#### 5) mover para cima. 

#### Encontre a sequencia de movimentos para chegar a um estado onde todos os quadrados estão limpos, supondo que no início, e o aspirador de pó está no quadrado superior esquerdo e que os dois quadrados da direita estão sujos. Construa as árvores de busca para os algoritmos de Busca em Largura e Busca em Profundidade até nível 1. Enumerar os nós de acordo com a sequência em que foram expandidos. Indique as ações tomadas quando um nó gerado já estiver em uma das duas listas. Mostre a sequência de movimentos que determina a solução.

### 8 - Construa a árvore de busca resultante da aplicação Algoritmo de Custo Uniforme ao problema de determinação de rotas, para ir da cidade S até a cidade B. O custo de cada operação (ir de uma cidade a outra) é a distância em quilômetros da estrada que liga as duas cidades. Consulte o mapa das cidades e estradas e a tabela de distâncias do material de aula. Mostre os valores de g para cada nó e indique o caminho da solução.

### 9 - A figura dada a seguir representa o espaço de estados para um dado problema, tal que os números ao lado dos arcos representam o custo de aplicação do operador correspondente a esse arco. O nó com bordas escuras é o nó objetivo. Construa a árvore que resulta da aplicação do Algoritmo de Custo Uniforme a este problema, com a indicação do valor de custo de cada nó. Mostre o conteúdo das listas OPEN e CLOSED a cada passo e indique o caminho da solução.

![Grafo](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/IA/imagem_2024-03-19_172711318.png)

## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!