# Resumo Aula 2
> Resumo criado pelo aluno [João Pedro Trevisan](https://www.linkedin.com/in/joao-pedro-trevisan)

#### Professor
![Murilo Naldi](https://img.shields.io/badge/Murilo_Coelho_Naldi-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)


## Aprendizado supervisionado
Retomando a definição de Aprendizado de Máquina feito por Tom Mitchell, "*Um programa de computador é dito aprender de uma experiência E...*". No nosso caso do **Aprendizado Supervisionado**, esta *experiência E* é composta por dados previamente rotulados por uma pessoa, leia-se um *supervisor*.

Partindo dos dados rotulados é buscado gerar um modelo que seja capaz de "acertar" a classificação com a maior taxa de sucesso possível.  Isto é, dado um conjunto de dados rotulados queremos atribuir rótulos a instâncias não rotuladas de maneira esperada.  

Imaginemos um algoritmo que classifica dados baseado na distribuição de pontos em um plano cartesiano. Este algoritmo usará um **conjunto de treinamento** para criar um **modelo**, ou seja, uma função que classifique os pontos baseado no aprendizado advindo do **conjunto de treinamento**. Este **modelo** será então uma **fronteira de decisão** neste gráfico, fazendo com que a divisão do espaço possa ser feita automaticamente num momento posterior. A imagem a seguir ilustra este problema:  

![AM1_aula03_img01.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula03_img01.png)

A linha pontilhada é nossa **fronteira de decisão**.  

Ainda assim, essa fronteira de decisão pode ser imprecisa se for introduzido um conjunto de dados diferente daquele que treinou o nosso **modelo**. Note que, assim como ilustra a imagem a seguir, nosso **conjunto de treinamento** aceita uma miríade de respostas diferentes:  

![AM1_aula03_img02.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula03_img02.png)

Não só isso, mas se fossem introduzidos pontos de alguma outra cor em outro setor do gráfico poderia ser o caso de uma única linha cruzando o plano não ser mais a melhor forma de expressar a **fronteira de decisão**.  Assim como se os dados tivessem dispostos numa espiral ainda fazendo parte de dois grupos linha nenhuma poderia compor uma **fronteira de decisão**.

Isso serve para vermos como não só os programas podem dar respostas corretas apenas em certas condições, mas também que alterações no problema original podem tornar nosso **modelo** inútil.  

## K-NN - Determinar a Distância
É um algoritmo de reconhecimento de padrões, um dos mais antigos e mais simples. Ele pertence a classe de algoritmos **baseados em instâncias ou exemplos**. Ele não induz regras, hiperplanos de separação ou mesmo probabilidades. O aprendizado e a classificação dos novos exemplos utilizam as próprias instâncias dos dados de treinamento. Por não gerar um **modelo** imediatamente é classificado como algoritmo **lazy**.  

O algoritmo aguarda até o último instante para construir um **modelo** e classificar um exemplo. Dado os exemplos de treinamento, o **algoritmo lazy** apenas armazena os exemplos e espera que seja dado um exemplo de teste para realizar algum processamento. O **K-nn** classifica baseado na **proximidade** dos dados com o conjunto de treinamento.  

A classificação fazendo uso dos vizinhos mais próximos faz uso dos rótulos dos vizinhos para descobrir a classe de um objeto não rotulado. São usados os rótulos dos ***K vizinhos mais próximos*** para classificar uma instância com base em sua posição.  

Uma importante questão no **K-NN** e em muitos outros algoritmos é o *como medir a distância* entre os elementos que estou avaliando/comparando.

Nas medidas de distância um padrão muito usado são as **medidas de similaridade e dissimilaridade**. Uma medida de **similaridade** retorna 0 se dois objetos são classificados como *diferentes* e o valor 1 indica que os objetos são *idênticos*. A medida de **dissimilaridade**, também chamada de **medida de distância**, opera de maneira exatamente oposta. Observe o esquema a seguir:  

+ **Medidas de Dissimilaridade**
	+ d(p,q) >= 0
	+ d(p,q) = 0 sse p = q
	+ d(p,q) = d(q,p) -> *simetria*
	+ d(p,q) <- d(p,r) + d(r,q) = *desigualdade triangulada*
+ **Medidas de Similaridade**
	+ d(p,q) = 1 -> *objetos idênticos*
	+ d(p,q) = d(q,p) -> *simetria*

Uma das distâncias entre **atributos nominais** é a chamada **taxa de discordância** que mede a dissimilaridade entre eles. Definimos aqui *m* como o número de atributos em comum entre *i* e *j*. *M* é o número total de atributos. Essa taxa é encontrada por meio da equação:

**d(i,j) = (M - m)/M**

Uma das equações para se encontrar similaridade é posta a seguir:

**s(i,j)  =  1 - d(i,j)  =  m/M**

Atributos binários podem diferir em **binários simétricos** e **binários assimétricos**, eles são representados a seguir:

**Binários simétricos**, 0 e 1, sim e não:
![AM1_aula03_img17.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula03_img17.png)

**Binários Assimétricos**, *one hot encoding*:
![AM1_aula03_img16.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula03_img16.png)

Quando se trata de atributos binários é preciso que se leve em consideração se vai considerar da mesma forma ambas as respostas e depois se pode montar uma **tabela de ocorrências**.

![AM1_aula03_img18.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula03_img18.png)

Tendo como base uma **tabela de ocorrências** temos duas **medidas de similaridade** muito usadas que são o **Coeficiente de Casamento Simples** (**CCS**) e o **Coeficiente de Jaccard** (**JAC**). A medida **CCS** será usada quando ambos atributos 1 e 0 são importantes e a **JAC** é usada quando queremos desconsiderar os atributos que são iguais a 0.

**CCS** - Coeficiente de Casamento Simples:

**CCS(i,j) = (F11 + F00)/(F11 + F10 + F01 + F00)**

Coeficiente de **Jaccard**:

**JAC(i, j) = F11/(F11 + F10 + F01)**
e
**DJAC(i,j) = 1 - JAC(i,j)**

Tendo como exemplo os conjuntos
+ i = (1, 0, 0, 0, 0, 0, 0, 0, 0, 0)
+ j = (0, 0, 0, 0, 0, 0, 1, 0, 0, 1)

CCS = (0 + 7)/(0 + 1 + 2 +7) = 0,7
JAC = 0/(0 + 1+ 2) = 0

Quando tratamos de **atributos numéricos** e não **binários** podemos aplicar funções de distância diferentes. É o caso da **distância de Manhatan** que leva este nome porque a cidade de Manhatan é um grid (não tem diagonais) e portanto somamos o módulo da distância em *X* com o módulo da distância em *Y*. Note:

**MH(Xi, Xj) = |Xi1 - Xj1| + |Xi2 - Xj2| + |Xi3 - Xj3| + ... + |Xim + Xjm|**

![AM1_aula03_img03.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula03_img03.png)

Temos também a **distância euclidiana** dada por 

**ED(i,j) = sqrt((Xi1 - Xj1)² + (Xi2 - Xj2)² + ... + (Xim - Xjm)²)**

Basicamente um teorema de Pitágoras, note o exemplo a seguir:

![AM1_aula03_img04.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula03_img04.png)

Perceba que a escala dos valores varia radicalmente na média escolar do aluno 3. Essa variação de escala é influente em alguns atributos em alguns algoritmos de treinamento. Imagine um atributo que reflita a idade de uma pessoa e um atributo que reflita seu peso em gramas, a escala dos valores vai ser de grande diferença, o que pode acarretar na maior atenção a alguns dados por parte do algoritmo.

Podemos usar processos de **normalização e padronização** para trazer os valores para uma escala semelhante. Veja:

![AM1_aula03_img05.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula03_img05.png)

imagem será atualizada no slide

Se aplicarmos a **normalização** de *min-max cutoff* à tabela anterior obteremos os seguintes valores:

![AM1_aula03_img06.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula03_img06.png)

Neste caso se buscarmos as distâncias entre os dados teremos:
+ **ED(1,2) = 0,81**
+ **ED(1,3) = 1,698**
+ **ED(2,3) = 1,32**

Uma outra medida de distância para atributos numéricos é a **Distância de Minkowski**, ela opera da seguinte forma:

![AM1_aula03_img07.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula03_img07.png)

Os diferentes valores de *p* vão sinalizar diferentes medidas de distância: 
+ *p* = 1: **Distância de Manhattan**
+ *p* = 2: **Distância Euclidiana**
+ *p* -> *infinito*: **Distância de Chebyshev/Suprema** (distância máxima entre os componentes dos vetores)

Veja:

![AM1_aula03_img08.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula03_img08.png)

Todas as medidas estudadas até então não funcionam bem para dados esparsos, ou seja, tabelas populadas com muitos valores nulos. Para estes casos podemos usar a **distância cosseno** que focará nos atributos comuns e nos valores destes atributos ao medir sua similaridade.

![AM1_aula03_img09.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula03_img09.png)

Tomemos como exemplo os conjuntos X1 e X2:
+ X1 = {0, 5, 10, 0}
+ X2 = {1, 0, 5, 0}

A **distância cosseno** entre estes dados é:

![AM1_aula03_img10.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula03_img10.png)

## K-NN: Funcionamento
Em pseudo código o comportamento do K-NN é o seguinte:
1. Definida uma métrica de distância, calcule a distância para todos elementos do conjunto de dados
2. Defina o número de *k* vizinhos (o raio)
3. Identifique os *k* vizinhos mais próximos do vetor de atributos *X* que se quer classificar
4. Determine o número de vizinhos em cada classe
5. Classifique o exemplo como sendo a moda das classes dos vizinhos

Note a imagem a seguir e a diferença de resultado que um aumento no raio pode acarretar no algoritmo K-nn:

![AM1_aula03_img11.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula03_img11.png)

Quando tratamos de algoritmos de IA, temos o conceito de **parâmetro** que significa a variável de configuração do modelo aprendido com dados. Há também o conceito de **hiperparâmetro** que é uma variável de configuração externa ao modelo, é a entrada do algoritmo de aprendizado. No caso do **K-NN** o **hiperparâmetro** é o *K* escolhido pelo usuário. No exemplo anterior tivemos uma prévia do impacto que a escolha de um *K* diferente pode ter nos resultados.

Pode-se adicionar peso aos vizinhos para que vizinhos mais próximos sejam mais influentes na atribuição do rótulo. Uma ponderação muito comum é usar o inverso da distância, mas existem muitas técnicas. Caso não queira adicionar ponderação, alterar a medida de distância pode alterar seu resultado e gerar uma saída melhor.

O algoritmo **K-NN** gera *implicitamente* algo chamado de **Diagrama de Voronoi**. O algoritmo não tem esta imagem como saída e em nenhum momento do uso dele isso vai ficar claro pra você, contudo este comportamento é observado. As imagens a seguir são tais diagramas:

![AM1_aula03_img12.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula03_img12.png)

As fronteiras geradas neste diagrama tem reação com a medida de distância e com o valor de *K* escolhido:

![AM1_aula03_img13.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula03_img13.png)
Valores de *K*

![AM1_aula03_img14.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula03_img14.png)
Medidas de distância

## A Maldição da Dimensionalidade 
Também conhecida como **CoD (Curse of dimensionality)**, vem do fato de que a medida que a quantidade de dimensões aumenta a distância entre vários pontos de dados também aumenta. É por isso que é necessária uma quantidade maior de pontos para cobrir mais espaço e tornar a distância entre os dados mais descritiva. Observe: 

![AM1_aula03_img15.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula03_img15.png)

De modo geral, o desempenho de um classificador tende a se degradar a partir de um determinado número de atributos. As soluções que podem ser tentadas para solucionar esta questão são muitas e podem vir da seleção de atributos de forma a trabalhar com um subespaço mais denso, reduzir a dimensionalidade, juntar atributos e muitas outras alternativas.

## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!
