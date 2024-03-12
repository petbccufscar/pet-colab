# Lista de exercícios 1

#### Professor
[![Mario](https://img.shields.io/badge/Diego_Silva-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)](https://site.dc.ufscar.br/docente/5cee7e5d48365a001679f750)

## Sprint prova 1

### 1. Para cada um dos vetores abaixo, ordene os valores com os algoritmos merge sort, quick sort, bucket sort, counting sort e radix sort. Caso não seja possível ou seja inviável, indique o motivo. Quantas operações foram feitas em cada caso? 
    - [1, 2, 3, 4, 5, 6, 7, 8, 9, 10] 
    - [1, 5, 500, 310, 220] 
    - [AB10, BC20, JJ40, HK88, GG88] 
    - [ab12gt4, ahs7, 87jy4, l38hs, aaahyehsn, iurh615] 
    - [-1, -7, 5, 4, -2, 0] 

### 2. Considerando uma árvore binária de busca com n nós, qual é a relação entre o número de comparações (entre a chave procurada e chaves em nós) e a altura da árvore? 

### 3. O TAD dicionário (especialização de uma tabela de símbolos) possui as seguintes operações principais: 
    - `Insere(k, D)`: Insere um elemento de chave igual a k (string) no dicionário D;
    - `Remove(k, D)`: Remove o elemento de chave igual a k do dicionário D;
    - `Pesquisa(k, D)`: Retorna o elemento de chave igual a k do dicionário. 
    Assumindo que a chave k é única, discuta os prós e contras e as complexidades de tempo e memória desse TAD utilizando as seguintes implementações: 
    a. Uma lista estática (vetor) não ordenada;  
    b. Uma lista estática (vetor) ordenada pela chave k;  
    c. Uma lista dinâmica (lista ligada) ordenada pela chave k;  
    d. Uma árvore binária de busca;  
    e. Uma árvore AVL.  
    f. Uma árvore vermelha e preta.  
    g. Uma skip-list.  
    h. Uma tabela hash.  

### 4. A partir de uma árvore AVL vazia, ilustre o resultado das seguintes operações (nessa ordem)  
   
    a. Inserir os elementos com chaves 55, 56, 11, 33, 41, 43, 35, 64, 62, 51  
    b. Remover os elementos com chaves 55, 35, 33, 62, 64, 56  

### 5. Responda se as afirmações abaixo são verdadeiras ou falsas e justifique resumidamente a escolha da sua resposta.   
   
    a. Para um dado nó em uma árvore AVL com fator de balanceamento +1, uma inserção em seu descendente esquerdo pode causar desbalanceamento (no nó em questão).  
    b. Em uma árvore binária completa, pode haver nós com fatores de balanceamento 0, +1 e -1, mas nunca -2 ou +2.  
    c. O tempo de execução do quick sort quando todos os elementos possuem a mesma chave é O(n).  
    d. Um arranjo que está em sequência ordenada é um heap mínimo.  
    e. O pior caso do quick sort acontece quando todas as execuções do método de partição criam um subvetor de tamanho 0 e outro de n-1 elementos (sendo n o tamanho do subvetor atual).  
    f. Não há pior caso para o merge sort.  
    g. O counting sort é pode lidar com valores negativos, desde que estejam em um universo bem definido e pequeno. O mesmo vale para o radix sort.  
    h. Em uma tabela hash, é possível criar uma operação de imprimir suas chaves de maneira ordenada.  

### 6. Uma busca inexata é aquela que, quando a chave procurada não existe, retorna a chave mais próxima existente. Discuta como se pode implementar uma busca inexata em uma lista ligada e em uma árvore AVL. Escreva um algoritmo e discuta a sua complexidade.

### 7. Vamos criar uma nova ED! Ela vai se chamar AED2Tree. A AED2Tree tree é uma árvore binária de busca em que buscamos posicionar próximos à raiz ositens com as chaves consultadas com maior frequência. Para isso, cada vez que uma chave é pesquisada, promovemos o seu nó para o nível acima. Discuta como podemos utilizar as rotações associadas às árvores AVL e RBT para definir essa função que promove o nó pesquisado e apresente argumentos para a sua decisão. Além disso, discuta qual é o benefício de se criar uma estrutura como essa, uma vez que não estamos a rotacionando para mantê-la balanceada (na verdade, as rotações devem tender a deixá-la bastante desbalanceada). Como essa árvore se diferencia da Splay Tree?

### 8. Suponha que você esteja projetando uma tabela hash. Nesse contexto, responda às seguintes perguntas:  
    a. Qual é a função hash que você escolheu e por quê?  
    b. Como escolher o tamanho da tabela hash? Qual é a vantagem (e a desvantagem) de escolher um valor grande para esse parâmetro?  
    c. Qual estratégia você escolheria para tratar colisões? Quais as vantagens ou desvantagens dela?  
    d. Dado o seu projeto de hash, mostre pelo menos 10 inserções, com pelo menos 3 colisões. Além disso, comente como tratar a remoção no seu caso.  

### 9. Considere o problema da seleção. Explique o melhor e o pior caso para se resolver esse problema utilizando variações dos algoritmos de ordenação. Especificamente, utilizar algum algoritmo quadrático, ordenar com merge sort e pegar o k-ésimo elemento e a modificação de quick sort.

## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!