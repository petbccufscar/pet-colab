# Resumo Aula 8
> Resumo criado pelo aluno [João Pedro Trevisan](https://www.linkedin.com/in/joao-pedro-trevisan)

#### Professor
![Murilo Naldi](https://img.shields.io/badge/Murilo_Coelho_Naldi-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)

## Agrupamento por Densidade

Até então foram estudados grupos formados por similaridade. Nesse tipo de agrupamento os objetos do mesmo grupo são os mais similares e pode se dizer que é um conceito bastante intuitivo visualmente (algumas vezes pode enganar, veja a aula passada).

Métodos que focam em agrupamento por similaridade acabam encontrando grupos globulares com facilidade, porém agrupamentos que fogem desse formato são bem mais difícil de serem identificados:

![AM1_aula09_img01.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula09_img01.png)

Cria-se agora o conceito de **agrupamento por densidade** no qual observamos uma distribuição de observações e definimos um **limiar de densidade** para "cortar" nosso gráfico e observar os grupos neste plano projetados. Grupos de alta densidade são separados por regiões de baixa densidade.

![AM1_aula09_img02.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula09_img02.png)

Tomemos um ponto cercado por um círculo de raio R:

![AM1_aula09_img03.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula09_img03.png)

É intuitivo ver qual das regiões possui maior densidade.

Ao passo que um algoritmo como o **K-means** tem um único parâmetro *K* que definirá o número de grupos, um algoritmo de agrupamento por densidade tem como parâmetros o raio da área a ser observada e o número de pontos que devem estar dentro deste raio para que haja um grupo. Disso se observa que ao informar raio e quantidade de pontos se está informando a densidade minima de um grupo a ser identificado.

**DBSCAN** é o **Density-Based Spatial Clustering of Applications with Noise**. Ele é o algoritmo de densidade mais popular do mundo com coisa de 25.500 citações, o Professor Naldi trabalhou por dois anos com o criador desse algoritmo.

No **DBSCAN** a densidade é dada por dois parâmetros: 

ε - Vizinhança: conjunto de pontos com distância máxima ε de um ponto de referência *p*.

Mpts: número mínimo de pontos na ε-Vizinhança para considerar *p* como um ponto de região densa.

**Nε(p) = {q|d (p,q) <= ε}**

Nos slides 14 ~ 16 há um exemplo do funcionamento desse algoritmo.

Existe o conceito de **alcançabilidade** (reachability) que diz que todo ponto na ε-vizinhança de um ponto de núcleo *p* é dito **diretamente alcançável** por densidade por *p*. Caso haja uma corrente de pontos **diretamente ancançáveis** de *p* a *q* dizemos que *q* é **indiretamente alcançável** por *p*.

Para cada objeto do universo observado que não tenha sido "classificado" encontramos todos pontos alcançáveis por densidade por um dado ponto *o* e atribua um novo grupo a todos esses pontos, se não atribua *o* ao conjunto de *outliers*. O resultado do algoritmo é algo desse tipo:

![AM1_aula09_img04.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula09_img04.png)

e então (com ε ideal)

![AM1_aula09_img05.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula09_img05.png)

É preciso se atentar que a tendencia é que os Mpts vizinhos mais próximos possuam distâncias pareceidas quando estiverem no mesmo grupo. *Outliers* possuem a distância para seus vizinhos maior do que o ponto *core*. Exemplo disso:

![AM1_aula09_img06.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula09_img06.png)

![AM1_aula09_img07.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula09_img07.png)

Aqui ε = 10 parece apropriado.

A complexidade do **DBSCAN** em espaço é O(n) e em tempo é O(n²) pois se calcula a distância de todos para todos, mas esse tempo pode ser reduzido para O(nlogn) com algumas técnicas.

As limitações do **DBSCAN** se encontram quando um conjunto de dados tem múltiplas densidades:

![AM1_aula09_img08.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula09_img08.png)

![AM1_aula09_img09.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula09_img09.png)

Pensando na interpretação dos dados, podemos dizer que o parâmetro Mpts é um fator de suavização que tornará as "classificações" mais ou menos abrangentes (menos *clumps* de *outliers*) e o ε é o limiar de densidade:

![AM1_aula09_img10.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula09_img10.png)

É importante pensar que uma solução de única densidade pode não refletir a estrutura dos dados como um todo:

![AM1_aula09_img11.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula09_img11.png)

Para solucionar esta questão precisamos usar um algoritmo hierárquico baseado em densidade. Se pensarmos no **DBSCAN** num contexto de grafo podemos pensar nos vértices desse grafo como as observações densas e os vértices adjacentes são as observações diretamente alcançáveis em ε.

Tomemos um grafo ponderado do seguinte formato:

![AM1_aula09_img12.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula09_img12.png)

Os vértices são as observações e os pesos das arestas representam o raio mínimo εpq para que p e q sejam densos e **diretamente alcançáveis** por εpq. Existe um nível de densidade λ = 1/εpq abaixo da qual qualquer aresta (p, q) atende a esses critérios.

Neste viés, os grupos são componentes conexos de subgrafos do grafo original. As arestas mantém apenas os vértices menores do que o limiar ε definido pelo usuário. Dos vértices são mantidos apenas os que possuem grau maior que zero (que não sejam ruído). Na imagem a seguir está delineado um grupo no grafo:

![AM1_aula09_img13.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula09_img13.png)

Podemos dar um passo além: se podemos ordenar as arestas desse grafo e removê-las em ordem decrescente de peso ε é possível tirar um parâmetro da mão do usuário. Não só isso, criamos um algoritmo hierárquico que possui todos os agrupamentos possíveis.

O nome disso é **H**(ierarchical)**DBSCAN\***. 

Ressaltando um ponto importante antes de prosseguir: esses algoritmos trabalham com a distância entre os pontos, ou seja, são relacionais.

O **HDBSCAN\*** é um ***algoritmo hierárquico de ligação simples*** sobre o espaço de distâncias de alcance de densidade e por isso ele é conhecido como **LS Robusto** (resistente a *outliers*). Isso se dá pelo fato de que uma distância entre dois pontos só será relevante se ela tiver relevância para outros pares de pontos.

O **HDBSCAN\*** pode ser obtido calculando a **MST** de um grafo G no espaço de distâncias de alcance.

No slide 35 tem a progressão de um gráfico de observações até sua **MST** e depois para um **dendrograma** com cores simbolizando as distâncias ε.

As imagens a seguir são **gráficos de alcançabilidade**, as regiões mais densas são representadas pelos vales na curva e indicam os agrupamentos. Isso pode ser expandido para *n* dimensões.

![AM1_aula09_img14.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula09_img14.png)

Existem também os **gráficos de silhueta** que mostra como variam as densidades dos grupos e dessa forma mostra onde eles se dividem em subgrupos de densidade diferente:

![AM1_aula09_img15.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula09_img15.png)

Tendo a hierarquia dos dados o usuário pode realizar uma partição nessa hierarquia. Pode-se realizar o corte horizontal tradicional em um dendrograma:

![AM1_aula09_img16.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula09_img16.png)

Considere agora que estejamos buscando uma **partição multidensidade**. O corte pode ser feito de outra maneira nas diferentes densidades encontradas:

![AM1_aula09_img17.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula09_img17.png)

Dada uma hierarquia e seja 𝛿i a escolho do grupo Ci, extrair um conjunto {Ci, Cj, ..., Ck} de grupos que maximiza o critério de qualidade:  𝐽 ( 𝛿1 , 𝛿 2 , ... , 𝛿𝑛 )

Tal que forme uma partição:

( 𝛿𝑖 =1 ⋀ 𝛿 𝑗 =1 ) ⇒ 𝑪 𝑖 ∪ 𝑪 𝑗 =∅  
𝛿 𝑖 =0 ⇒ ∃ 𝛿 𝑗 =1:𝑪 𝑖 ⊂ 𝑪 𝑗 ⋁ 𝑪 𝑗 ⊂ 𝑪 𝑖

O critério de otimização pode ser decomposto como uma soma de termos tais que cada termo S(Ci) representa a medida de qualidade do grupo Ci

Para realizar essa seleção de forma correta tomamos o critério de qualidade J calculado da forma:

𝐽 = ∑  𝛿𝑖 ∙ 𝑆 ( 𝑪 𝑖 )
𝑖=1  
𝑛 

Buscamos maximizar J.

Dada uma hierarquia de grupos representada por uma árvore, um método para estimar a qualidade de cada grupo deve ser encontrado. Também devemos ter um método para agregar as qualidades estimadas a serem maximizadas. Buscamos escolher grupos que formem uma partição além de maximizar a qualidade agregada.

Tomemos o problema de programação dinâmica (de baixo pra cima). Queremos encontrar o máximo global:

![AM1_aula09_img18.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula09_img18.png)

Tomemos os nós C10 e C11, a soma de seus valores é maior que o valor de seu pai C8, sob este viés devemos manter os grupos C10 e C11. Ao subir nessa árvore vemos que quebrar C2 em C4 e C5 gera grupos de qualidade 6, a soma de suas qualidades sendo 12 que é maior que a qualidade 7 do pai C2 e da soma das qualidades dos filhos, ou seja, devemos manter separado até C4 e C5. Do outro lado da árvore C3 tem qualidade maior que a soma das qualidades de seus filhos e portanto devemos particionar a raiz só até C3 neste lado da árvore.

A estabilidade de grupo para hierarquias baseadas em densidade pode ser definida como **S(Ci) = excesso de massa relativo de grupo Ci**. Esta métrica é dada por:

![AM1_aula09_img19.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula09_img19.png)

Note que o cluster C2 tem maior estabilidade que C4 e C5 e portanto será selecionado para a "classificação" o grupo C2. 

## Critérios de Validação de Agrupamento

De maneira quantitativa, o procedimento de validação é feito por meio de um índice e seus tipos podem ser:
+ **Externo**
+ **Interno**
+ **Relativo**

Os **índices externos** comparam partições diferentes e medem sua similaridade. Se forem idênticas o valor retornado é 1.

O **índice externo** é utilizado para verificar a qualidade de um agrupamento de acordo com uma referência, a informação é **externa** aos dados.

Alguns desse índices são:
+ Rand Index
+ Jaccard
+ Rand Index Ajustado
+ Fowlkes-Mallows
+ Estatística G
+ Nomralized Mutual Information

Estes índices se baseiam em algo muito semelhante com os componentes de uma matriz de espalhamento:

**MM**: Nº de pares que pertencem ao mesmo grupo em ambas partições  
**MD**: Nº de pares que pertencem ao mesmo grupo apenas na partição 1  
**DM**: Nº de pares que pertencem ao mesmo grupo apenas na partição 2  
**DD**: Nº de pares que não pertencem ao mesmo grupo em ambas partições

O **Rand Index** é dado por: 

**Rand(P1, P2) = (MM + DD)/(MD + DM + MM + DD)**

Note como ele é parecido com o critério de **precisão** da classificação.

O **Índice de Jaccard** é dado por:

**Jc(P1, P2) = MM / (MD + DM + MM)**

Ele é semelhante ao f measure da calssificação.

Existe também o **Rand Ajustado** que soluciona o problema de que para **jaccard** e **rand** não se espera um valor nulo para 2 partições completamente aleatórias:

![AM1_aula09_img20.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula09_img20.png)

Os **índices internos** são usados quando não se dispõe de partições de referência para validar a estrutura de grupos obtida, ou seja, existe apenas os dados e o resultado a ser avaliado. 

Como exemplo podemos tomar a função objetivo do K-means conhecida como **SSE**: **Sum of squared errors** que mede a variância intra cluster. Ela é dada por:

![AM1_aula09_img26.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula09_img26.png)

Nesta equação *d* é a distância euclidiana. O centróide de do c-ésimo grupo é encontrado pela equação que segue:

![AM1_aula09_img27.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula09_img27.png)


Já os **índices relativos** fazem referência a uma classe de índices capaz de indicar qual a melhor dentre duas ou mais partições, a caracterização como **relativo** pode depender não só do critério mas também as vezes do contexto. Como exemplo disso o SSE é um critério relativo se as partições a serem comparadas possuem o mesmo número de grupos.

**Índices relativos**, num contexto amplo, são definidos como índices capazes de avaliar individualmente uma partição e quantificar esta avaliação através de um valor que possa ser comparado relativamente.

Consideremos o exemplo de um **índice relativo I(  
P)** que é proporcional a qualidade do agrupamento.

![AM1_aula09_img28.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula09_img28.png)

**Índices relativos** são mais flexíveis pois podem ser usados como critérios de otimização para se escolher melhores partições e podem servir como regras de parada para se não se passar de um determinado valor de qualidade.

Um bom exemplo de **índice relativo** e **interno** é o **índice Dunn** que toma a maior distância inter-grupo e a maior distância intra-grupo:

![AM1_aula09_img21.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula09_img21.png)

No índice original, as distâncias inter-grupos e a intra-grupos são calculadas segundo ligação simples e diâmetro máximo o que o torna muito sensível a *outliers*.

**índice silhueta**: Esse índice se baseia nas características relativas a forma com a qual um objeto foi agrupado, quanto maior a distância do objeto para os outros grupos (b(Xi)) e menor a distância para seu grupo (a(Xi)), melhor será a avaliação. A **silhueta** de um objeto é dada por:

![AM1_aula09_img22.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula09_img22.png)

A **silhueta de um grupo/partição** é dada pela média das **silhuetas** de seus objetos:

![AM1_aula09_img23.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula09_img23.png)

Existem diferentes tipos de **silhueta** a serem usados dependendo da situação segundo os valores de (a(Xi)) e (b(Xi)):
+ **a(Xi)**: dissimilaridade média do i-ésimo objeto em relação aos objetos de seu grupo.
+ **b(Xi)**: dissimilaridade média do i-ésimo objeto em relação aos objetos do grupo mais próximo a que **Xi** ***não*** ***pertence**.

Pode-se ainda simplificar a **silhueta** considerando apenas a distância do objeto ao centróide do seu grupo (a(Xi)) ou ao centróide do grupo mais próximo que não seja o seu (b(Xi)). Isso não é uma solução relacional, mas sua complexidade é linear e não quadrática.

Existem muitos outros índices pelos quais se pode avaliar as partições feitas, a imagem a seguir lista alguns deles:

![AM1_aula09_img24.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula09_img24.png)

Vale lembrar que para **algoritmos hierárquicos** o processo de validação dos agrupamentos podemos escolher uma de suas partições e aplicar o critério relativo em qualquer um dos níveis da hierarquia e comparar os resultados em diferentes níveis.

Isso é muito útil para se avaliar a melhor quantidade de partições que um par algoritmo-dataset tem. A tabela a baixo mostra diferentes algoritmos hierárquicos e diferentes quantidades de partições, veja como é fácil avaliar:

![AM1_aula09_img25.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula09_img25.png)

Em suma, índices de validação avaliam a qualidade de um agrupamento em comparação com uma estrutura conhecida ou quantitativamente ou ainda em relação a outro agrupamento. Eles são frequentemente usados para selecionar agrupamentos e diferentes índices podem resultar em avaliações bastante distintas.


## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!
