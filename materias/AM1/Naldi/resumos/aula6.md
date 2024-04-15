# Resumo Aula 6
> Resumo criado pelo aluno [João Pedro Trevisan](https://www.linkedin.com/in/joao-pedro-trevisan)

#### Professor
![Murilo Naldi](https://img.shields.io/badge/Murilo_Coelho_Naldi-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)

## Combinação de Modelos
Combinar classificadores é uma forma que pode ser muito poderosa dependendo do objetivo que se tem e da forma com a qual se combina.

Imagine um perceptron que apenas divide linearmente o espaço, quando queremos dividir o espaço de solução mais que linearmente devemos adicionar mais neurônios em mais camadas nessa rede.

Isso é uma forma de **divisão e conquista** por meio do uso de classificadores que se complementem.

As primeiras ideias desse tipo de trabalho datam da década de 90.

O uso de múltiplos modelos só é bom se os modelos individuais cometem erros independentemente. Hansen e Salamon mostram que se feito de maneira correta a taxa de erro decresce linearmente com o número de modelos se todos eles tem a mesma taxa de erro, essa taxa é menor que 0,5 e ocorre a questão dos erros independentes (diferentes erros).

A imagem a seguir mostra o resultado de combinação de classificadores. Cada linha representa um classificador. Note que, a combinação de classificadores pode gerar resultados melhores, iguais ou mesmo piores, por isso eles devem ser escolhidos de maneira inteligente:

![AM1_aula07_img01.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula07_img01.png)

Duas questões são levantadas então:

Como combinar previsões de modelos diferentes?
Como gerar modelos diferentes?

Podemos fazer o uso de **modelos heterogêneos** e de **modelos homogêneos**.

Ao combinar modelos homogêneos podemos encontrar modelos diferentes ao manipular o conjunto de treinamento (reamostragem/injeção de aleatoriedade e perturbação) ou os parâmetros do modelo a ser usado como *função de ativação*, *bias*, *taxa de aprendizado*. Isso funciona bem para algoritmos instáveis.

Uma forma de realizar manipulação de dados com objetivo de gerar um modelo diferente podemos usar a técnica de **bagging** semelhante à já estudada antes ([[AM1_Aula04]]) de **bootstraping**. A técnica consiste em criar exemplos através de reamostragem criando novos conjuntos do tamanho do conjunto original e terá seu próprio classificador (para combinarmos mais tarde).

Isso é algo semelhante a ideia de **random forest**, gera-se árvores aleatórias (classificadores) geradas por meio de conjuntos diferentes. A ideia é que a maioria delas consiga dar um resultado robusto e que sua combinação gere um modelo bom.

O algoritmo de **random forest** consiste em tomar um conjunto **D** de dados com *m* atributos. É realizada uma amostragem por **bagging** (***bootstraping***). As árvores serão criadas para os conjuntos determinando *i* (*i* << *m*) atributos para determinar a decisão em cada nível e não são usadas estratégias de poda. O processo é repetido *T* vezes. Os slides de 20 ~ 30 ilustram este processo, veja.

Os classificadores que são gerados são então combinados gerando uma **floresta aleatória**.

Isso é um **classificador fraco**, que significa ser pouco melhor que um **classificador aleatório** (que tem taxa de acerto ao redor de 0,5). Ainda assim, a junção de um **comitê** de **classificadores fracos** pode gerar um **classificador forte** por meio de **boosting**.

**Boosting** é muito parecido com **bagging** (o **bootstraping**). A diferença é que o **bagging** gera dados de maneira independente e o **boosting** é um processo iterativo que busca melhorar a cada geração, criando assim dependência entre um modelo e outro.

No **boosting** a cada iteração o peso de cada exemplo é alterado. Se um exemplo é classificado de maneira certa seu peso diminui segundo uma função na próxima iteração, se ele é classificado de maneira errada seu peso sobe. Constrói-se então um novo classificador com esses pesos e repete-se o procedimento.

Note esse gráfico e perceba que a divisão ainda acerta mais da metade dos exemplos:

![AM1_aula07_img02.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula07_img02.png)

Aumenta-se então o peso dos nós que foram classificados de maneira errada e é gerada uma classificação como a do segundo gráfico da imagem a seguir. O último gráfico ilustra a combinação dos classificadores:

![AM1_aula07_img03.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula07_img03.png)

Este exemplo visual se assemelha bastante com o algoritmo **Adaboosting**. Este algoritmo é baseado em amostragem aleatória e cada exemplo é ponderado pela técnica de **boosting** para construir ***stumps*** (divisoes lineares, modelos) para cada atributo. 

**Stump** significa *toco*. Por assim dizer, com a soma dos *tocos* se faz uma *árvore*.

Os erros dos ***stumps*** são usados para recalcular pesos e ponderar a votação. Ou seja, cada modelo gerado é ponderado com base no peso do anterior e eles serão combinados tendo em vista seus pesos para gerar o modelo combinado final.

Exite também o **gradient boosting**. Ele trabalha com uma **taxa de aprendizado** assim como uma rede neural. Ele usa essa taxa de aprendizado para ponderar a razão entre a função de perda da iteração atual e da iteração passada em busca de minimizar os erros.

## Regressão
Regressão é uma técnica que permite inferir a relação de uma variável dependente (atributo objetivo) com variáveis independentes específicas (outros atributos).

Este processo é usado como método descritivo de análise de dados e gera um modelo matemático que descreve a relação entre duas ou mais variáveis.

Do slide 4 ao 8 existe um exemplo muito bem explicado de como se buscar uma função linear para dividir um plano. Note que o *erro* da regressão é a soma das distâncias entre os pontos e sua projeção na reta que corta o plano. Geralmente se usa o **erro quadrático** de forma a se ter sempre um valor positivo (ainda que possa errar pra mais ou pra menos o importante é o quanto ele errou).

Sobre o **erro quadrático**, ele é usado em muitos modelos, mas atente-se que se o erro será usado para ponderar alguma correção talvez você queira ter um erro comum pela possibilidade de haverem valores negativos.

A regressão pode ser feita para todo o conjunto de dados ou para parte dele e ela não é usada para dividir os dados, mas sim gerar um modelo que os represente. Isso é feito para que com essa formula que substitui os dados possamos por exemplo mandar uma função para um app que não depende dos dados originais, o que é muito mais seguro e muitos mais econômico em memória (e muito menos ilegal).

Pode se gerar um vetor que corta os grupos de dados e definir que de um ponto do vetor "pra lá" tem uma classe e deste ponto "pra cá" tem outa classe. A imagem a seguir mostra este vetor a ser usado para separar os dados.

![AM1_aula07_img04.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula07_img04.png)

Ainda se pode usar mais que um vetor e classificar as instâncias baseado na distância de cada vetor:

![AM1_aula07_img05.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula07_img05.png)

Nos slides 14 e 15 há um exemplo de aplicação. Note que a saída é um negócio feio que um especialista vai saber ler.

Do slide 16 ao 22 há outro exemplo ainda. Neste exemplo temos pacientes de câncer com um número de nódulos e a classe que prediz sobrevivência ou morte. Já usamos este exemplo antes e nele dividíamos os exemplos no meio:

Mas aqui usamos uma regressão linear
![AM1_aula07_img06.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula07_img06.png)

Suponhamos que as classes estejam ainda mais desbalanceadas:

![AM1_aula07_img07.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula07_img07.png)

Perceba que a angulação desta reta mudou e isso pode influir em seus resultados. Talvez uma reta não fosse o melhor para se classificar esses exemplos.

Tomássemos uma curva da seguinte forma teríamos um modelo que divide perfeitamente o espaço:

![AM1_aula07_img08.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula07_img08.png)

Esta é uma função logística e muitas vezes ela pode ser usada para classificar um modelo de regressão.

Existe uma relação entre a função linear e a função logística. A função desse tipo tem o nome por causa de *log*. Em inglês ela se chama **função logit**, ou ***log-odds***, o *log* da chance de algo ocorrer.

![AM1_aula07_img09.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula07_img09.png)

Falando agora sobre **combinação** somada a **regressão**, tomemos o exemplo de um conjunto de dados multiclasse da seguinte forma:

![AM1_aula07_img10.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula07_img10.png)

Podemos realizar, por exemplo, três regressões, uma para cada classe e combiná-las para gerar um limiar de decisão multiclasse:

![AM1_aula07_img11.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula07_img11.png)

![AM1_aula07_img12.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula07_img12.png)

![AM1_aula07_img13.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula07_img13.png)

![AM1_aula07_img14.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula07_img14.png)



## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!
