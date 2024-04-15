# Resumo Aula 3
> Resumo criado pelo aluno [João Pedro Trevisan](https://www.linkedin.com/in/joao-pedro-trevisan)

#### Professor
![Murilo Naldi](https://img.shields.io/badge/Murilo_Coelho_Naldi-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)

## One Class Classification (OCC)
Anteriormente, estudamos que AM semi-supervisionado pode ser útil, especialmente quando levamos em conta a dificuldade de se rotular exemplos.

Não exploramos porém a questão que pergunta o que acontece quando não conseguimos exemplos de todas as classes. Se existem objetos de outras classes que não estão no meu conjunto, porém eu preciso criar um classificador, o que eu faço?

Problemas dessa natureza são convenientes para detecção de anomalias, detectar outliers ou mesmo trabalhar quando não se é possível coletar dados do universo.

Para este tipo de problema temos alguns classificadores especiais adaptados para trabalhar com **one class**. Alguns exemplos são:
+ Baseados em distribuição
+ OC_SVM
+ Isolation Forest
+ OC-kNN

Os algoritmos baseados em distribuição assumem que os dados da classe se comportam segundo uma distribuição pré-definida como uma distribuição gaussiana ou de Poisson. Isso dito, depois de se assumir um modelo estatístico tomamos todos dados sob o modelo com uma classe e os outros como outra classe.

![Aula04_img01.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula04_img01.png)

O Suport Vector Machine para **one class** é uma variação do SVM que pode ser usada de maneira não supervisionada para detecção de anomalias. Uma vez que se trabalha com apenas uma classe é difícil se conseguir exemplos anômalos rotulados, sendo assim poder separar o espaço por meio de hiperplanos ou hiperesferas e então observar o que fica fora dos espaços definidos é uma maneira de se detectar anomalias.

O algoritmo de Isolation Forest é comumente usado para detectar anomalias que não pertencem a classe conhecida. Se nos recordarmos da aula de árvores de decisão sabemos que o plano é dividido em hiperplanos, no caso dos problemas de **one class** a árvore de decisão é explorada muito profundamente, sem poda.

Se houverem folhas próximas a raiz que possuem poucos pontos isso indica anomalias, que é exatamente o que é buscado.

Uma questão interessante é "como diabos se faz um kNN com uma só classe?"

O que acontece nesse algoritmo é o seguinte: se não temos classes diferentes para "votar" no kNN temos apenas a posição de uma instância, usamos os algoritmo para checar se o lugar onde um dado ponto está é tão denso, ou seja, tem uma vizinhança tão parecida quanto a de um dado ponto classificado.

+ d(z,y): distância entre duas amostras z e y 
+ kNN(y): k-ésimo vizinho mais próximo da amostra y  
+ + Amostra z, encontra kNN(z) = y, classifica z como pertencente à classe alvo quando d(z,y)/d(y, kNN(y)) < δ  
	+ δ pré definido

δ diz quantas vezes a amostra pode se distanciar de um vizinho para ainda pertencer a uma dada classe.

## Positive and Unlabeled Learning (PUL)
Em alguns cenários podemos não conseguir exemplos além da classe positiva e é fácil conseguir exemplos não rotulados.

Tomemos o seguinte exemplo:

![Aula04_img02.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula04_img02.png)

Se tomássemos uma abordagem semelhante a OCC faríamos o seguinte:

![Aula04_img03.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula04_img03.png)

Contudo essa atitude é muito simplista, é mais apropriado apenas separar os dados rotulados dos outros e não "atropelar" dados que estão "no caminho":

![Aula04_img04.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula04_img04.png)

Os métodos para realizar essa tarefa podem envolver modelos probabilísticos que modelam P e U, modelos baseados em otimização que maximizam o número de U fora da região e garantem os pontos positivos da região e atribuição de pesos aos U e ajuste subsequente da curva (regressão logística com erro ponderado).

Uma estratégia alternativa envolve encontrar rótulos negativos nos quais se possa confiar e então criar um classificador com base nestes rótulos e nos positivos que já se possui. Isso pode ser feito com label-propagation seguido da construção de um classificador, por exemplo.

Quando se vai avaliar os resultados de tarefas PUL precisa-se separar dados conhecidos para poder testar o modelo ou se pode testar o desempenho no mundo real. Imagine que se quer criar uma metralhadora montada com câmera que mata todos que passam com uma camisa amarela, basta contar quantos mortos estão com camisas de outras cores.

## Meta-aprendizado
Como vimos até aqui, precisamos de dados para gerar bons modelos, porém nem sempre temos uma quantidade grande de dados para aplicações específicas. Sendo assim, dificilmente conseguiremos um modelo bom e deveremos escolher outras técnicas como por exemplo extrair exemplos semelhantes ou buscar conhecimento refletido em modelos já treinados anteriormente.

Isso carrega alguns problemas por si só, como o fato de que diferentes algoritmos podem obter resultados distintos ou só podem ser aplicados em certos tipos de dados. Certos algoritmos possuem hiper-parâmetros a serem definidos como *k* e δ.

É preciso lembrar que no aprendizado de máquina (e na vida) não existe ganho sem perda. Isso nos faz levar em consideração que precisamos buscar o uso de modelos e soluções cujo viés indutivo melhor se adapta ao problema. 

O meta-aprendizado foca em resultados anteriores por meio dos resultados obtidos de outros conjuntos com meta-dados semelhantes. Buscamos aprender a relação entre problemas e técnicas.

Encontrar o algoritmo apropriado para um problema específico se chama **algorithm selecton problem** (ASP). Encontrar os melhores parâmetros para um algortimo conhecido se chama **hyper-parameter optimization** (HPO). Existem outros.

Na recomendação de algoritmos, nosso dado de entrada para o treino é um conjunto de dados (**meta-exemplos**) junto do algoritmo que obteve melhor desempenho em cada um (**meta-alvos**). O modelo gerado na etapa de **meta-treinamento** é chamado de **meta-modelo**.

Para a seleção de algoritmos (ASP) possuímos o Modelo Rice, publicado em 1976:

![Aula04_img05.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula04_img05.png)

O problema começa com um conjunto de conjuntos no canto superior esquerdo, extraímos daí os melhores meta-features (melhores variáveis) e passamos adiante para o feature space para aplicarmos algoritmos de aprendizado neles e então descobrir os melhores algoritmos para aquele tipo de dados. No algorithm space fazemos uso de aprendizado de máquina para descobrir os melhores algoritmos dentre todos os outros.

Note que o modelo é genérico, então colocá-lo em prática tem muitas nuancias. Busca-se simplificar o processo de alguma forma. Isso pode ser feito pelas técnicas **direta**, de **propriedades de modelos** e de **landmarking**

A **caracterização direta** pode ser feita de maneira **simples** usando números de exemplos, classes e atributos, números de atributos categóricos e numéricos, etc. A **caraterização direta estatística** faz uso de informações como média, desvio padrão, oblicuidade, distribuição... Por fim podemos usar **métodos diretos da teoria da informação** que faz uso de entropia, informação mútua ou conceitos semelhantes.

As **caracterizações baseadas em modelos** buscam induzir modelos e caracterizar o conjunto de dados por modelos indutivos. Tomando como exemplo o uso de uma árvore de decisão podemos medir o número de folhas, a profundidade, a entropia média nas folhas...

Por fim, a ideia de **landmarking** não faz uso do modelo, mas sim conceitos como precisão, recall, área sob a curva ROC...

Mudando o assunto de ASP para HPO. Para otimizarmos os hiper-parâmetros podemos, em redes neurais por exemplo, buscar a diminuição da função de perda pode ser feita pelo conceito conhecido como **descida do gradiente**.

Gera-se um modelo, realiza-se uma mudança, gera de novo e de novo e de novo de forma a ter opções para escolher aquela que mais diminui a função de perda. Utiliza-se um vetor de parâmetros θ para selecionar aquele que mais rende diminuição da função de perda.

Exemplos podem ser o Model-Agnostic Meta-Learning (MAML), Reptile, ou os chamados **algoritmos genéticos**.

O algoritmo MAI (Meta Applicability Induction) é um exemplo de meta-aprendizado em nível de instância. Nele tomamos um conjunto de dados para criar um conjunto de classificadores e testar sobre os objetos que possuímos anteriormente, isso geralmente faz uso da técnica **leave-one-out**. Na tabela a seguir, a coluna *erro* é o resultado da previsão feita por meio do **leave-one-out**.

![Aula04_img06.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula04_img06.png)

Se utilizarmos a coluna *erro* como as novas classes do conjunto, nós teremos um conjunto que nos diz se um algoritmo acerta ou erra dado um exemplo da base de dados, ou seja, um meta-modelo. Cria-se uma árvore que determina mediante a quais entradas um dado algoritmo tende a acertar ou errar e então se pode escolher um algoritmo baseado no dado que se tem.

![Aula04_img07.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula04_img07.png)

Isso é semelhante ao método de **stacking** estudado na matéria passada. Porém o conjunto de dados do segundo nível guarda as probabilidades de acerto de cada modelo.

![Aula04_img08.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula04_img08.png)

Coloca-se todos os exemplos dentro de todos os modelos de nível 0 e então se combina suas saídas de forma a conseguir um classificador de nível 1. É polêmico chamar isso de meta-learning, pois o classificador não decide qual é o melhor modelo, ele só combina os melhores resultados.

![Aula04_img09.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula04_img09.png)


## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!
