# Lista de Exercícios 7

#### Professor
[![Mario](https://img.shields.io/badge/Mario_San_Felice-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)](https://site.dc.ufscar.br/docente/5cee7e5d48365a001679f750)

## Busca em Profundidade

### 1. Quantas ordens topológicas diferentes o seguinte grafo possui? Use apenas os rótulos {1, 2, 3, 4}.

![Imagem 1](https://github.com/petbccufscar/.github/raw/main/pet-colab/AED2/Mario/Captura%20de%20tela%202024-03-12%20180014.png)


### 2. O que acontece quando nosso algoritmo de ordenação topológica é executado em um grafo dirigido que possui um ciclo?
   #### a) o algoritmo pode ou não entrar em loop infinito.  
   
   #### b) o algoritmo garantidamente entra em loop infinito.  
   
   #### c) o algoritmo termina, e pode ou não obter uma ordenação topológica.  
   
   #### d) o algoritmo termina, e com certeza não encontra uma ordenação topológica.  

### 3. Considere um grafo dirigido acíclico (DAG) com `n` vértices e `m` arestas. Qual é o número mínimo e o número máximo de componentes fortemente conexos que esse grafo pode ter, respectivamente?
   #### a) 1 e 1  
   
   #### b) 1 e `n`  
   
   #### c) 1 e `m`  
   
   #### d) `n` e `n`  

### 4. Seja `G` um grafo dirigido (orientado) e `Grev` uma cópia de `G` com as orientações dos arcos invertidas. Qual a relação dos Componentes Fortemente Conexos (CFC) de `G` e `Grev`? (Mais de uma opção pode ser válida.)
   #### a) Em geral, eles não se relacionam.  
   
   #### b) Todo CFC de `G` também é um CFC de `Grev`, e vice-versa.  
   
   #### c) Todo CFC fonte de `G` é também um CFC fonte de `Grev`.  
   
   #### d) Todo CFC sorvedouro de `G` se torna um CFC fonte de `Grev`.  

### 5. Quais das seguintes sentenças é verdadeira? Como de costume, `n` e `m` correspondem ao número de vértices e arestas do grafo, respectivamente.
   #### a) Busca em profundidade pode ser usada para encontrar os componentes fortemente conexos de um grafo orientado em tempo O(`n` + `m`).  
   
   #### b) Busca em profundidade pode ser usada para encontrar uma ordenação topológica para um grafo dirigido acíclico (DAG) em tempo O(`n` + `m`).  

### 6. Qual é o tempo de execução da busca em profundidade, se o grafo de entrada for representado por uma matriz de adjacência (e não por listas de adjacência)? Pode responder usando `n` e `m` para representar o número de vértices e arestas.

### 7. Quando um grafo orientado tem uma única ordenação topológica?
   #### a) Quando ele é acíclico.  
   
   #### b) Quando ele possui um único ciclo.  
   
   #### c) Quando ele possui um caminho orientado que passa por cada vértice uma vez.  
   
   ####  d) Nenhuma das anteriores.  

### 8. Se você adiciona um novo arco em um grafo dirigido `G`, então o número de Componentes Fortemente Conexos (CFC) ... (escolha todos os itens válidos)
   #### a) ... pode ou não permanecer o mesmo.  
   
   #### b) ... não pode diminuir.  
   
   #### c) ... não pode aumentar.  
   
   #### d) ... não pode diminuir de mais que 1.  

### 9.  Considere o algoritmo de duas passadas de Kosaraju para encontrar componentes fortemente conexos. Quais das seguintes sentenças é válida?
   #### a) O algoritmo continuaria correto se usássemos busca em largura no lugar da busca em profundidade nas duas passadas.  
   
   #### b) O algoritmo continuaria correto se usássemos busca em largura no lugar da busca em profundidade na primeira passada.  
   
   #### c) O algoritmo continuaria correto se usássemos busca em largura no lugar da busca em profundidade na segunda passada.  
   
   #### d) O algoritmo não funciona corretamente a menos que usemos busca em profundidade nas duas passadas.  

## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!
