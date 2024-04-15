# Resumo Aula 5
> Resumo criado pelo aluno [João Pedro Trevisan](https://www.linkedin.com/in/joao-pedro-trevisan)

#### Professor
![Murilo Naldi](https://img.shields.io/badge/Murilo_Coelho_Naldi-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)

## SVM - Support Vector Machine
O **SVM** é um classificador linear binário e não probabilístico, isso significa dizer que ele quebra classes em duas por meio de uma linha no gráfico e para isso não faz uso de cálculos de probabilidade. Ele busca gerar hiperplanos e nisso tenta maximizar a distância entre os pontos mais próximos das classes.

Note a separação entre classes a seguir e note a distância da fronteira entre elas e da primeira instância de uma classe:

![AM1_aula06_img35.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula06_img35.png)

Perceba que está bem próximo da classe vermelha.

Agora note o seguinte exemplo:

![AM1_aula06_img36.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula06_img36.png)

Note que a fronteira é equidistante das classes, ou seja, tem a maior distância possível de cada uma delas.

A matemática que envolve o processo será explicada a seguir. *Y* é a classe que queremos definir, digamos que ela é representada pelo conjunto {-1, +1}. *X* é o plano linearmente separável e *w* é um vetor normal ao hiperplano, não necessariamente unitário, b/|w| é a distância do hiperplano em relação a origem no sentido do vetor normal *w*. Temos:

**Y pertence a {-1, +1}**
**h(X) = w · X + b**

![AM1_aula06_img01.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula06_img01.png)

Geometricamente, a distância entre duas margens é 2/||w|| e sendo assim para maximizar a distância entre as margens o problema resume-se em minimizar ||w|| restrito a **Yi(w \* Xi + b) >= 1** para i = 1, ..., n. Isso garante que não há exemplos entre as margens. A solução para isso é encontrar *w* e *b* que solucionam este problema.

Um dos problemas do **SVM** é que ele é muito sensível à *outliers*. Observe:

![AM1_aula06_img02.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula06_img02.png)

Introduzimos então um nó vermelho no canto inferior esquerdo:

![AM1_aula06_img03.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula06_img03.png)

Podemos realizar o processo de suavização de margens do **SVM**. Se liga no processo: 

![AM1_aula06_img04.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula06_img04.png)

A constante *C* é um termo de regularização que impõe um peso à minimização dos erros no conjunto de treinamento em relação à minimização da complexidade do modelo. Quanto maior o peso dos erros (valor de *C*) menor a margem.

Quando meus dados não forem linearmente separáveis devemos torná-los linearmente separáveis. Isso é feito por meio da transformação do espaço dos dados para então realizar um corte por hiperplano usando a **SVM**. Esse processo é a aplicação de um **kernel**.

![AM1_aula06_img05.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula06_img05.png)

Aplicar um kernel é distorcer o espaço e portanto projetá-los em outra dimensão. Os dados não alterados mas sim o espaço, é uma jogada de geometria analítica.

Este processo pode ter algumas abordagens. Uma delas envolve criar atributos de ordem superior para transformar dados como *Caixa² + Avaliação² + Caixa \* Avaliação*. Outra abordagem envolve transformar o espaço por meio de um kernel.

![AM1_aula06_img06.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula06_img06.png)

Tomaremos 2 atributos vermelhos e 1 azul para curvar o espaço:

![AM1_aula06_img07.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula06_img07.png)

![AM1_aula06_img08.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula06_img08.png)

![AM1_aula06_img09.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula06_img09.png)

O resultado da aplicação de uma função Gaussiana é o seguinte;

![AM1_aula06_img10.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula06_img10.png)

![AM1_aula06_img11.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula06_img11.png)

![AM1_aula06_img12.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula06_img12.png)

![AM1_aula06_img13.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula06_img13.png)

![AM1_aula06_img14.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula06_img14.png)

![AM1_aula06_img15.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula06_img15.png)

![AM1_aula06_img16.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula06_img16.png)

![AM1_aula06_img17.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula06_img17.png)

Estes são os "passos" da aplicação de um Kernel Gaussiano.

## Redes Neurais
Redes neurais foram desenvolvidas na década de 50 e sua inspiração é na biologia do nosso cérebro. Ela é um processador massivamente distribuído e paralelo feito de unidades de processamento simples, os neurônios. Não só isso, esta rede armazena conhecimento experimental com objetivo de induzir-se um modelo.

Este conceito até 10 anos atrás tinha sido muito pouco explorado.

A bioinspiração das redes neurais vem do estudo do neurônio para criar o modelo mais simples chamado de *Perceptron*:

![AM1_aula06_img18.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula06_img18.png)

Os dendritos do neurônio são a parte que recebe uma entrada de sinais que serão juntos no corpo do neurônio. No nosso modelo matemático cada "dendrito" possui um peso que é somado em uma função de junção que determinará se a soma dos pesos será suficiente para gerar a ativação de um neurônio.

Existe um valor de *bias* para dar o valor total da junção dos dados. Este valor é somado a soma dos valores de entrada multiplicados pelos pesos:

![AM1_aula06_img19.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula06_img19.png)


Graficamente o efeito deste *bias* gera o seguinte:

![AM1_aula06_img20.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula06_img20.png)

Se meu "neurônio" recebe estímulo suficiente ele passa seus dados por uma **função de ativação** antes de gerar uma saída.

Existem diferentes tipos de **função de ativação**, alguns exemplos são:

**Limiar**:
![AM1_aula06_img21.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula06_img21.png)


**Linear**:
![AM1_aula06_img22.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula06_img22.png)


**Sigmoidal**:
![AM1_aula06_img23.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula06_img23.png)

Vamos a um exemplo. Imagine que tenhamos uma tabela que lista 2 atributos de algum minério:

![AM1_aula06_img37.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula06_img37.png)


Se fossemos plotar isso faríamos um gráfico muito simples:

![AM1_aula06_img38.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula06_img38.png)


Queremos criar um classificador com redes neurais que classifique corretamente os minérios. Utilizaremos a seguinte rede neural com ativação limiar:

**Wk1 = -1, Wk2 = -1, bk = 0.6**

As operações que ocorrerão serão exemplificadas com a amostra 1:

**(0,3 · -1) + (0,2 · -1) + 0.6 = 0,1**
passando este valor por uma função limiar teremos resultado igual a **1**.

Para treinarmos o **Perceptron** usamos um conjunto de dados e calculamos o erro *ek* da seguinte forma:

**ek(n) = dk(n) - yk(n)**

Para atualizarmos os pesos usamos:

![AM1_aula06_img24.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula06_img24.png)


+ k = o neurônio que está operando
+ n = iteração de treino
+ j = atributo
+ *n* bonito que multiplica o erro = taxa de aprendizado
+ w = peso

Se lidamos com dados linearmente separáveis dizemos que o algoritmo converge. Caso contrário ele nunca para de iterar.

Tem um exemplo no slide que eu não vou colocar nesse resumo pra não ficar grande igual o exemplo do kernel. O exemplo é bom, ele treina um **Perceptron** pra identificar um AND entre os dados e vai da página 24 ~ 28.

Basicamente a saída do algorítimo vai cortar o plano da seguinte forma:

![AM1_aula06_img25.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula06_img25.png)


Agora a questão é, como treinar uma rede para executar a função XOR?

![AM1_aula06_img26.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula06_img26.png)


A resposta pousa na criação de novas camadas de neurônios, gerando um **MLP** (Multi Layer Perceptron). Neurônios de uma camada tem como entradas sinais provenientes apenas dos neurônios das camadas anteriores.

Sobre redes neurais é importante salientar sobre linearidade e generalização que a rede neural é construída por meio da interconexão de neurônios, o que torna a rede toda não linear, isso é importante para criar generalização em suas saídas.

![AM1_aula06_img27.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula06_img27.png)


![AM1_aula06_img28.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula06_img28.png)


![AM1_aula06_img31.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula06_img31.png)


A imagem anterior possui uma **topologia completamente conectada**. As topologias podem ainda ser **parcialmente conectadas**:

![AM1_aula06_img32.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula06_img32.png)


As conexões entre  os neurônios podem ser:
+ Excitatórias: pesos positivos
+ Inibitórias: pesos negativos
+ Aprendizado: usam algoritmo de retropropagação (*backpropagation*)

Podemos gerar infintas combinações de divisões lineares para classificar nosso hiperplano. São as **regiões convexas** geradas por combinações de hiperplanos:

![AM1_aula06_img29.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula06_img29.png)


Podem ainda ser gerados múltiplos polígonos:

![AM1_aula06_img30.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula06_img30.png)

A topologia clássica de redes neurais que simplesmente caminha ao longo das camadas até gerar uma saída é chamada de *feedforward*. Existe também a rede neural de *feedback* que usa sua saída como entrada para uma nova iteração. Elas também são chamadas de redes neurais *recorrentes*.

Para entender os tipos de redes neurais recorrentes veja [este vídeo](https://youtu.be/nvCY5GUq1xw?t=209).

Existem ainda as redes no **modelo de Kohenen**. Elas tem objetivo de gerar mapas artificiais que aprendem por meio de auto organização de maneira neuro-biologicamente inspirada. Neste modelo a localização espacial dos neurônios de saída correspondem a um domínio particular ou característica dos dados de entrada.

Para uma dada entrada o neurônio vencedor é estimulado junto aos seus vizinhos de forma que os objetos mais parecidos entre si alimentam uma região determinada.

![AM1_aula06_img33.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula06_img33.png)


Isso vai "colorir" o grid de forma a especializar neurônios em uma dada classe e mapear o espaço de forma a dividir as classes.

Estas redes são chamadas de **mapas auto organizáveis** ou **SOM** ( *self organizing maps*). Uma visão diferente deste mapa é a seguinte:

![AM1_aula06_img34.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula06_img34.png)


## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!
