# Lista de Exercícios 8

#### Professor
[![Mario](https://img.shields.io/badge/Mario_San_Felice-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)](https://site.dc.ufscar.br/docente/5cee7e5d48365a001679f750)

## Busca em largura, caminhos mínimos e Dijkstra

### 1. Considere um grafo não orientado e conexo com `n >= 2`. Lembrando que a busca em largura explora o grafo por camadas, qual o menor e o maior número de camadas que o grafo pode ter? Dê um exemplo do tipo de grafo que estaria em cada categoria.

### 2. Quais das seguintes sentenças é verdadeira? Como de costume, `n` e `m` correspondem ao número de vértices e arestas do grafo, respectivamente.
   a) Busca em largura pode ser usada para encontrar os componentes conexos de um grafo não orientado em tempo O(`n` + `m`).  
   b) Busca em largura pode ser usada para calcular as distâncias não ponderadas de todos os vértices com relação a um vértice origem em tempo O(`n` + `m`).  

### 3. Considerando o seguinte grafo e tomando o vértice `s` como origem, diga quais as distâncias até `s`, `v`, `w` e `t`.

![Imagem 1](https://github.com/petbccufscar/.github/raw/main/pet-colab/AED2/Mario/Captura%20de%20tela%202024-03-12%20180510.png)

### 4. Qual das seguintes alternativas melhor descreve uma implementação direta (sem estruturas de dados sofisticadas) do algoritmo para caminhos mínimos de Dijkstra? (`n` e `m` correspondem, respectivamente, ao número de vértices e arestas.)
   a) O(`n` + `m`)  
   b) O(`m` log `n`)  
   c) O(`n`^2)  
   d) O(`n` * `m`)  

### 5. Considere um grafo dirigido `G` com vértice origem `s`, vértice destino `t` e arcos com custo não negativo. Sob quais condições o caminho mínimo de `s` até `t` (`s-t` caminho mínimo) é único?
   a) Quando todos os arcos têm custos inteiros e distintos.  
   b) Quando todos os arcos têm custos que são potências de 2 distintas.  
   c) Quando todos os arcos têm custos inteiros e distintos e o grafo não tem ciclos orientados.  
   d) Nenhuma das alternativas anteriores.  

### 6. Considere um grafo dirigido `G` com custos não negativos nos arcos. Dados dois vértices `s` e `t` de `G`, seja `P` um `s-t` caminho mínimo. Se adicionarmos o valor 10 em todo arco de `G`, então (escolha todas as alternativas válidas.)
   a) `P` certamente continua sendo um caminho mínimo de `s` até `t`.  
   b) `P` certamente não é mais um caminho mínimo de `s` até `t`.  
   c) `P` pode ou não ainda ser um caminho mínimo de `s` até `t`.  
   d) Se `P` tem apenas um arco, então `P` certamente continua sendo um caminho mínimo de `s` até `t`.  

### 7. Considere um grafo dirigido `G` e um vértice origem `s`. Suponha que `G` tem algum arco de custo negativo, mas não tem circuitos de custo negativo. Suponha que você executa o algoritmo de Dijkstra nesta instância. Escolha as alternativas válidas.
   a) O algoritmo de Dijkstra pode entrar em loop infinito.  
   b) É impossível executar o algoritmo de Dijkstra em um grafo com custos negativos nos arcos.  
   c) O algoritmo de Dijkstra termina, mas em alguns casos nem todas as distâncias que ele encontra estarão corretas.  
   d) O algoritmo de Dijkstra termina, e em alguns casos todas as distâncias que ele devolve estarão corretas.  

## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!
