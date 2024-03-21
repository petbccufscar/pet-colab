# Lista de Exercícios 5

#### Professor
![Heloisa](https://img.shields.io/badge/Heloisa-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)

## Representação do Conhecimento e Raciocínio

### 1 - A figura dada a seguir representa o espaço de estados para um problema, tal que os números ao lado dos nós indicam o valor da função heurística h(n) aplicada ao nó n e os números ao lado dos arcos representam o custo de aplicação do operador correspondente a esse arco. O nó A é o estado inicial e o nó I, com bordas escuras, com valor heurístico zero, é o estado objetivo. Aplique o **Algoritmo A*** nesse problema. Construa a árvore de busca resultante da aplicação do algoritmo, indicando os valores de g, h e f para cada nó. Mostre o conteúdo das listas Open e Closed a cada passo, indicando o que acontece quando um nó que já aparece em alguma das listas é gerado novamente. Mostre a sequência de nós expandidos e a solução (caminho) encontrada.

![Grafo](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/IA/imagem_2024-03-19_180600106.png)

### 2 - O problema do mundo do aspirador de pó pode ser formulado como: Um cenário é representado por uma grade de 2X2, sendo que cada quadrado pode ter ou não sujeira. Um aspirador de pó pode aspirar sujeira ou se mover para um quadrado adjacente nesse cenário, com movimentos que tem os seguintes custos: aspirar a sujeira - custo 1; andar para a esquerda ou para a direita - custo 2; andar para cima ou para baixo - custo 3. Uma função heurística para esse problema pode ser definida como h(n) = número de quadrados sujos em n. Os operadores devem ser aplicados na ordem: 

#### 1) aspirar; 
#### 2) mover à direita; 
#### 3) mover para baixo; 
#### 4) mover à esquerda; 
#### 5) mover para cima. 

#### Encontre a sequencia de movimentos para chegar a um estado onde todos os quadrados estão limpos, supondo que no início, e o aspirador de pó está no quadrado superior esquerdo e que os dois quadrados da direita estão sujos. Construa as árvores de busca para o **Algoritmo Greedy** e para o **Algoritmo A***, mostrando, para cada nó, o valor da função de avaliação, função heurística e de custo (quando houver). Enumerar os nós de acordo com a sequência em que foram expandidos. Indique as ações tomadas quando um nó gerado já tiver sido gerado anteriormente. Mostre a sequência de movimentos que determina a solução.


### 3 - Construa a árvore de busca resultante da aplicação do **Algoritmo A*** ao problema de determinação de rotas, para ir da cidade L até a cidade B, usando, como função heurística, a distância em linha reta entre cada cidade e a cidade B. O custo de cada operação (ir de uma cidade a outra) é a distância em quilômetros da estrada que liga as duas cidades. Consulte o mapa das cidades e estradas e a tabela de distâncias do material de aula. Mostre os valores de g, h e f para cada nó e indique o caminho da solução.

### 4 - O algoritmo de caminho heurístico é uma busca pela melhor escolha na qual a função objetivo é f(n) = (2-w)g(n) + wh(n). Para que valores de w esse algoritmo oferece a garantia de ser ótimo? Que espécie de busca ele executa quando w=0? E quando w=1? E quando w=2?

### 5 - A figura dada a seguir representa o espaço de estados para um dado problema, tal que os números dentro dos retângulos ao lado dos nós indicam o valor da função heurística h(n) aplicada ao nó n e os números ao lado dos arcos representam o custo de aplicação do operador correspondente a esse arco. O nó Z, com bordas escuras e valor heurístico zero, é o nó objetivo. Construa a árvore que resulta da aplicação dos algoritmos de busca heurística:

#### **Algoritmo A***, onde a função de avaliação deve ser f(x) = g(x) + h(x)
#### **Algoritmo Greedy**, onde a função de avaliação deve ser f(x) = h(x)
#### Para cada um dos algoritmos, indique o caminho de solução.

![Arvore](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/IA/imagem_2024-03-19_180626642.png)

### 6 - Aplique o Algoritmo de **Subida da Encosta** (Hil-Climbing) no grafo do Exercício 5, considerando os valores heurísticos (ignorando os custos das operações). Explique porque o algoritmo não permite atingir a solução ótima. Construa a árvore de busca.

### 7 - Aplique o **Algoritmo de Subida da Encosta** (Hill-Climbing) no problema do Exercício 3.


### 8 - O problema das 4 rainhas consiste em posicionar 4 rainhas em um tabuleiro 4X4 de tal forma que não possam atacar umas as outras. Suponha que a configuração abaixo é a situação inicial e aplique o **Algoritmo de Subida da Encosta**. A função heurística que o algoritmo utiliza é o número de pares de rainhas que se atacam, direta ou indiretamente. Calcule o valor da função heurística para todos os movimentos possíveis até o término do algoritmo.

![Xadrez](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/IA/imagem_2024-03-19_180640561.png)

## Contato
Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!