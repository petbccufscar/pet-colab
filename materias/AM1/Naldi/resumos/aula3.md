# Resumo Aula 3
> Resumo criado pelo aluno [João Pedro Trevisan](https://www.linkedin.com/in/joao-pedro-trevisan)

#### Professor
![Murilo Naldi](https://img.shields.io/badge/Murilo_Coelho_Naldi-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)

## Avaliação de Performance
Das várias maneiras que podemos avaliar o desempenho de um modelo começaremos pela **matriz de confusão**. Uma **matriz de confusão** é uma matriz que tem em suas colunas o **rótulo verdadeiro** e nas suas linhas o **rótulo predito**. Dessa forma, sua diagonal principal indica os acertos e tudo que caia fora dela é um tipo de erro.

![AM1_aula04_img01.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula04_img01.png)

Podemos usar uma **matriz de confusão** binária que não nos dá um grau de acerto ou erro, mas sim se houve acerto **OU** se houve erro. Ela divide seus resultados em *verdadeiro positivo, falso positivo, falso negativo e falso positivo*. O falso negativo é também chamado de **erro de tipo 1** e o falso negativo é o **erro de tipo 2**.

![AM1_aula04_img02.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula04_img02.png)

A notação *f(a,b)* simboliza a frequência em que a *classe real é* **a** e a *classe prevista* é **b**.

A **medida de acurácia** é um valor dado por:

**A = previsõesCorretas/previsõesTotais**

Já a **taxa de erro** é dada por

**E = previsõesErradas/previsõesCorretas**

E há ainda o **erro positivo** e o **erro negativo** dados respectivamente por:

**err+ = falsoNegativo/(verdadeiroPositivo + falsoNegativo)**
**err- = falsoPositivo/(verdadeiroNegativo + falsoPositivo)**

Se fossemos classificar o desempenho de um modelo apenas por **acurácia** e **taxa de erro** poderíamos ter algum grau de viés no nosso julgamento. Imagine um problema esdrúxulo de duas classes a serem rotuladas e temos 9990 exemplos da primeira classe e 10 da segunda classe. Se tomássemos um modelo que rotula tudo como classe 1 ele teria uma precisão de 99,9%, o que não faz sentido. 

Outras métricas que podem ser usadas são o **TFN**: proporção de exemplos positivos + incorretamente classificados. Ou o  **TFP**: proporção de exemplos - incorretamente classificados.

A **precisão** é dada pelo numero de previsões corretas dividida pela soma das previsões corretas e as previsões erradas. Ou seja, usa os verdadeiros do classificador.

A **revocação** é dada pela taxa de acerto dividida pelos verdadeiros positivos + os falsos negativos. Ou seja, usa a taxa de acerto na classe positiva.

Em resumo:

![AM1_aula04_img03.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula04_img03.png)

A **Medida F** (*f measure*) é usada quando se precisa considerar todos os objetos menos os verdadeiros negativos. Ela é dada por:

**F = (2 \* prel(h) sen(h))/prel(h) + sen(h)**, ou seja
**F = (2 \* F11)/ 2 \* F11 + F01 + F10**

Ela desconsidera os verdadeiros positivos pois muitas vezes a ausência de uma característica não indica capacidade de predição. Eu não tenho asas e uma cadeira não tem asas, mas não é por isso que eu sou uma cadeira.

Podemos criar também uma **matriz de custos**, o custo sendo uma penalização por ter classificado um objeto de uma classe de maneira errada. Pode ser que um erro nos custe muito e podemos então escolher um modelo menos preciso mas que erre menos.

Note que a **matriz de custo** elenca os valores de se classificar cada objeto. Um verdadeiro positivo diminui o custo em -1, um falso negativo custa 100, um falso positivo custa 1 e um verdadeiro negativo não adiciona custos.

![AM1_aula04_img04.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula04_img04.png)

## Como Estimar Confiabilidade
O desempenho de um modelo pode depender de outros fatores além do algoritmo de aprendizagem. Elementos que podem influir nisso são a distribuição das classes, o custo de uma má classificação e o tamanho do conjunto de teste. 

Uma métrica útil é a **curva de aprendizado**, ela mostra como a precisão varia com o tamanho da amostra. Os efeitos de uma amostragem pequena são os vieses nas estimativas e a alta variância dos dados. 

![AM1_aula04_img05.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula04_img05.png)

É importante ao estimar uma medida verdadeira que a amostra seja **aleatória**, isto é, os exemplos não devem ser pré-selecionadas. Para problemas reais, normalmente é tomada uma amostra de tamanho *n* e o objetivo consiste em estimar uma medida para aquela população em particular ao invés de fazê-lo para todas populações. 

Existem os métodos **estimadores** para aksldksa. A imagem segue:

imagem

Uma maneira de se fazer isso é por meio de uma técnica chamada **holdout** que consiste em dividir sua amostragem em exemplos de treinamento e exemplos de teste. É importante deixar registrado que a maneira com a qual se divide sua base de dados pode influir nos seus resultados.

A tabela a seguir mostra um exemplo de **holdout**. Tipicamente se divide 2/3 das amostras para treino e 1/3 para teste, porém não há fundamentos teóricos sobre estes valores.

![AM1_aula04_img06.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula04_img06.png)

Outra técnica a ser usada é a **amostragem aleatória**. Nela tomamos uma série de amostras sortidas do nosso conjunto de dados para servirem de casos de teste e usamos o restante das observações como exemplos de treinamento. A imagem a seguir deixa esquematizado:

![AM1_aula04_img07.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula04_img07.png)

Isso é basicamente um **holdout** feito *n* vezes. O erro final será calculado como a média dos erros de todas as hipóteses induzidas e calculados em conjuntos de teste independentes e extraídos aleatoriamente. A **amostragem aleatória** pode produzir resultados melhores que o **holdout** na questão da estimação de erros.

A **validação cruzada** te leva a particionar o dado em *r* partes, fazendo o que se chama um **r-fold**. Esta técnica consiste em dividir uma base de dados em *r* segmentos mutuamente exclusivos e usar estes segmentos como conjunto de teste e o resto da base como conjunto de treinamento, na segunda iteração se usa uma outra porção como teste e o resto como treinamento e assim sucessivamente. 

![AM1_aula04_img08.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula04_img08.png)

Este método é caro se forem usados muitos ***folds***.

Existe também a **validação cruzada estratificada** que é semelhante ao **r-fold**, mas ele busca criar *folds* com distribuições de classes semelhantes às distribuições da base toda. Diga que a base tem x% de dados da classe 1, y% da classe 2 e z% da classe 3, cada sessão da base que criaremos deve ter aproximadamente esta distribuição.

Temos também o **leave-one-out** que é um **r-fold** com *r* = todos os objetos do conjunto. Isso só é possível com amostras pequenas.

Por fim, temos o **bootstraping** que é usado quando temos muito poucos dados. Ele tenta artificialmente aumentar o conjunto de dados por meio de reposição nas amostragens de maneira estratificada, ou seja, mantendo as proporções de classes daquela base.

![AM1_aula04_img09.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula04_img09.png)

Quando um modelo é treinado muito sobre os dados ele acaba perdendo a capacidade de generalização, este processo se chama **overfitting** e é um problema.

Podemos ainda querer comparar desempenhos relativos entre modelos diferentes. Uma forma de realizar esta tarefa é usar a chamada curva de ***Receiver Operating Characteristic***. Este gráfico compara **verdadeiros positivos** (f(1,1), eixo y) e **falsos positivos** (f(0,1), eixo x) e nele o desempenho de cada modelo gerador é representado como um ponto na **curva ROC**. Note que o eixo y é dado pela medida de **sensitividade** (**TPR**, **VP/(VP + FN)**) e o eixo x é dado pela **FPR** (1 - especificidade).

![AM1_aula04_img10.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula04_img10.png)

Em problemas de classificação devemos considerar a área sob a curva de características de operação do receptor. A curva nos diz quanto o modelo é capaz de distinguir entre as classes, a área sob a curva representa o grau da medida de separação, ou seja, quanto maior a área sob a curva melhor o modelo é em predizer se 0 é 0 e 1 é 1 por exemplo.

O objetivo é gerar diferentes modelos variando os limiares dos algoritmos, a distribuição das amostras ou mesmo as matrizes de custo. Um bom modelo terá a área sob o gráfico próxima de 1 e um modelo ruim terá este valor próximo de 0. O objetivo é gerar diferentes modelos variando os limiares dos algoritmos, a distribuição das amostras ou mesmo as matrizes de custo. Um bom modelo terá a área sob o gráfico próxima de 1 e um modelo ruim terá este valor próximo de 0.

Note as diferentes áreas sob as curvas e seus efeitos na predição nos gráficos logo abaixo delas. Veja que quanto menores são as áreas menor é a capacidade de distinção:

![AM1_aula04_img11.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula04_img11.png)

Se temos 2 classificadores dos quais conhecemos a precisão podemos escolher qual é o melhor entre eles por meio de um **teste de significância**. Tomemos um modelo M1 com 85% de precisão que foi treinado em 30 casos e um modelo M2 com 75% de precisão que foi treinado em 3000 casos o modelo M2 soa como uma escolha melhor pois seu volume de treino é mais significante. Para saber qual é o melhor precisamos aplicar o **teste de significância** que é um processo estatístico de medir o quão significantes é essa diferença.

Podemos aplicar sobre estes modelos **testes de hipótese** que são testes estatísticos quem comparam duas amostras segundo uma determinada hipótese. A título de exemplo geralmente se assume como hipótese que os resultados obtidos por um modelo não poderiam ser obtidos por um outro, ou seja, os resultados de ambos não provam a mesma população.

Outros **testes de hipótese** a serem estudados são o **teste -t**, o **Wilcoxon**, o **ANOVA** e o **teste de Friedman**.

## Classificadores
**Árvores de decisão** são classificadores que dividem um problema em subproblemas.

No slide (Aula 05) o professor dá uma boa revisada em árvores que eu não vou dar aqui, vale a pena dar uma olhada ainda que só nos exemplos de tomada de decisão, mas este conceito é básico demais para ser resumido e portanto foge do escopo deste texto.

Cada percursos que vai da raiz a uma folha de uma árvore representa uma **regra de classificação**. A imagem a seguir mostra isso e também o conceito de **espaço de hipóteses**.

![AM1_aula04_img12.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula04_img12.png)

Para se montar uma árvore é preciso **aprender um modelo**, é sobre isso que falaremos a partir daqui.

Começaremos do **Hunt's Concept Learning System** pois ele começou tudo, ele deu origem a muitos outros algoritmos e técnicas, muitos dos quais são patenteados e muitos dos quais tem nomes ridículos como **ID3**, **C4.5**, **J4.8**, **C5.0** ou **CART** e **Random-Forest**.

No que se trata do **algoritmo de Hunt**, seja *Dt* um conjunto de objetos não classificados que atingem o nó *t*. O **primeiro passo** é: se todos objetos de *Dt* pertencem à mesma classe *ct* então *t* é um nó folha rotulado como *ct* (base da recursão). O **passo 2** diz que se *Dt* contém objetos que pertencem a mais de uma classe então *t* deve ser um nó interno.

+ **Passo 2.1**: O nó deve conter uma condição de teste sobre algum dos atributos que não houverem sido selecionados acima da árvore.
+ **Passo 2.2**: Um nó filho é criado para cada possível saída da condição de teste e os objetos *Dt* serão distribuídos sobre ele.
+ **Passo 2.3**: O algoritmo é aplicado recursivamente para cada nó filho (volta-se ao **Passo 1**).

Do slide 24 ao 28 existe um exemplo que não será colocado aqui pro documento não ficar horrível quando exportado pra pdf. Veja o exemplo, ele é importante.

Este algoritmo carrega algumas falhas que fazem com que ele funcione apenas se houver um objeto para cada combinação possível de valores dos atributos preditos e no caso de houver mais de um eles pertencerem à mesma classe.

Resolver esta questão significa dizer que se *Dt* for vazio para um determinado nó *t* este nó deverá ser rotulado na classe majoritária dos objetos do nó pai. Já se *Dt* for composto de vários objetos de classes distintas em um nó *t* e não existem mais atributos a serem avaliados deve se rotular o nó novamente com a classe majoritária.

O **critério de parada** deste tipo de algoritmo é quando temos homogeneidade nos dados (todos da mesma classe) ou quando não temos mais para onde ir, neste caso assumiremos a classe majoritária

As decisões mais importantes quando se trata de **árvores de decisão são**:
+ Como dividir os objetos?
	+ Como escolher o atributo de divisão?
	+ Qual a melhor divisão para aquele atributo?
+ Quando parar de dividir os objetos?

Falaremos então de **condições de teste** para responder essa pergunta. Nossa resposta depende do *tipo de atributo* (binário, nominal, ordinal, contínuo) e do *número de divisões* (2 divisões, mais que duas divisões).

Para atributos binários é simples, só se pode decidir entre um deles para seguir um ramo da árvore.

Para atributos nominais podemos criar uma ramificação para cada valor ou ainda podemos tornar este atributo binário por meio de agrupamento dos valores. A imagem demonstra:

![AM1_aula04_img13.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula04_img13.png)

Para atributos ordinais temos duas alternativas: usar tantos ramos quanto forem possíveis ou agrupá-los porém respeitando sua ordem.

![AM1_aula04_img14.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula04_img14.png)

Para atributos contínuos podemos discretizá-los em intervalos ou podemos realizar comparações de forma a guiar a divisão. Se *Ai* > *x* escolhemos uma decisão; a escolha do valor de *x* é importante para gerar a melhor decisão. A vantagem de se trabalhar com atributos contínuos é que com a discretização podemos tratá-lo como atributo nominal qualquer e não é necessário mudar este algoritmo de induzir ADs. A desvantagem está em se tentar esgotar a capacidade de divisão deste atributo e na incerteza da quantia ideal de intervalos, isso pode gerar muitos ramos desnecessários na árvore.

![AM1_aula04_img15.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula04_img15.png)

## Medidas de Escolha de Atributo
Existem várias medidas para determinar a melhor forma de dividir os objetos, começaremos por **medidas de impureza** que é o quão impuro é o conjunto que entra em cada nó.

Estas medidas são definidas em termos da *distribuição de classes* dos dados antes e após a decisão baseadas na ideia que a melhor partição é aquela em que todos os dados são divididos em grupos com a mesma classe e quanto mais balanceadas as classes pior. 

Algumas **medidas de impureza** são:
+ Entropia
+ Gini
+ Erro de classificação
+ Chi-quadrado

Aqui estão algumas das equações destas medidas:

![AM1_aula04_img16.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula04_img16.png)

P(i|t) = fração de dados pertencentes à classe *i* em um nó *t*.
c = nº de classes

Uma coisa que não é falada no slide é que cada uma dessas medidas se relaciona a um tipo de atributo, uma visão geral pode ser vista na imagem a seguir:

![AM1_aula04_img17.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula04_img17.png)

Nos slides que vão de 47 a 56 existem exemplos bons que tratam da medida GINI, vai lá ver isso agora.

A **medida de ganho** é outra métrica que pode ser usada na seleção de atributos. Ela é dada por:

![AM1_aula04_img18.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula04_img18.png)

I(Vt) = grau de impureza do nó filho Vt
N(Vt) = nº de objetos do nó filho Vt
N = nº de objetos no nó original Vpai

Quando a medida de impureza usada para calcular a **medida de ganho** for a **entropia** o delta medirá o **ganho de informação**. Note que o primeiro termo será constante para todos os atributos e pode ser omitido para comparar os deltas associados a cada atributo.

Dos slides 59 ao 71 existe um exemplo de uso da **média ponderada GINI** para divisão de atributos. Leia e exercite, é importante.

Medidas de entropia como **GINI** favorecem atributos com muitos valores, elas contudo podem gerar muitos subconjuntos dos dados de treinamento e quão menores forem este subconjuntos mais puros eles tendem a ser, ainda assim, são mais susceptíveis a se especializar nos dados de treinamento.

Alternativas para minimizar este problema podem ser usar apenas divisões binárias como faz o algoritmo **CART** ou punir quantidades de valores de atributo como com o uso da **taxa de ganho** no algoritmo **C4.5**.

A taxa de ganho é dada por:

![AM1_aula04_img19.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula04_img19.png)

k = nº de divisões (valores do atributo A)
p(Vt) = fração de objetos cujo valor do atributo Ai = Vt
Sinfo = entropia do conjunto de objetos com relação aos valores do atributo Ai

Devemos manter em mente que algoritmos podem ter alguma espécie de **viés indutivo** que é uma tendencia em privilegiar uma ou um conjunto de hipóteses. Estes vieses são categorizados em **de restrição/linguagem** quando tende a restringir o espaço de hipóteses e **de busca/preferência** quando polariza a escolha dentre as possíveis realizações do modelo.

Outro problema que podemos enfrentar é o ***overfitting*** e ele se dá muitas vezes pela falta de um **viés indutivo** em árvores de decisão, isso pode fazer com que haja um ajuste perfeito ao conjunto de treinamento, tirando o poder de generalização do modelo.

Problemas que também podem levar ao ***overfitting*** são um conjunto de dados não muito representativo, um conjunto contaminado com ruído, ou práticas como a partição recursiva dos dados de forma a fazer as decisões sobre conjuntos cada vez menores. Neste último caso os níveis mais profundos podem ter muito poucos objetos, aumentando a chance de ***overfitting*** e o impacto do ruído no conjunto.

Para evitar problemas de ***overfitting*** podemos usar o princípio da **navalha de Occam** também conhecido como **princípio da parcimônia** que prega que as entidades não devem ser multiplicadas além da necessidade. Esta regra é usada quando em modelos que competem entre si tendemos a escolher o mais simples.

Para se realizar a simplificação de árvores de decisão podemos tomar duas abordagens: interromper o crescimento **a priori** ou interrompê-lo **a posteriori**. 

A **interrupção a priori** será baseada no desempenho dos dados de teste ou em uma comparação entre o desempenho em dados de teste e complexidade do modelo. Tendemos a interromper o crescimento quando o desempenho em dados não usados no treinamento não melhora mais de forma significativa como mostra a imagem a seguir:

![AM1_aula04_img20.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula04_img20.png)

**Interromper a posteriori** também pode ser chamado de realizar a **poda da árvore**, exercício no qual eliminamos subárvores cujas existências reduzem o desempenho do modelo em dados de teste. Isso demanda calcular para cada nó a variação no desempenho de classificação após serem eliminados seus descendentes. É mais caro computacionalmente que a **interrupção a priori**, mas é mais eficiente.

Os passos para se realizar uma **poda** são:

1. Tomar um conjunto de dados de teste não vistos no treinamento.
2. Percorrer a árvore segundo percurso pós fixado e para cada nó *t* calcular:
	+ Et: o erro de classificação dos objetos de teste que chegam até aquele nó como se ele fosse uma folha associada a classe majoritária.
	+ St: a soma dos erros Ei de cada folha descendente de *t*.
	+ Vt: a variação do erro após a poda dos descendente (St - Et).
3. Podar os descendentes daquele nó *t* com maior valor positivo de Vt.
4. Atualizar os valores de St e Vt para os nós ancestrais de *t*.
5. Retornar ao passo 3 enquanto houverem valores positivos de Vt.

Em resumo, os benefícios de se trabalhar com árvores de decisão pousam sobre a rápida classificação de novos dados, a interpretação das hipóteses reduzida (principalmente para árvores relativamente pequenas), a determinação de atributos importantes (podendo também calcular o custo da utilização de um atributo).

As desvantagens das ADs que podem ser elencadas são a limitação de hipóteses a hiper-retângulos (menos em árvores oblíquas), o baixo desempenho em problemas com muitas classes e poucos dados e o elevado custo computacional em indução e simplificação de modelos que pode existir principalmente em algoritmos mais sofisticados.


## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!
