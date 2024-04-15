# Resumo Aula 5
> Resumo criado pelo aluno [João Pedro Trevisan](https://www.linkedin.com/in/joao-pedro-trevisan)

#### Professor
![Murilo Naldi](https://img.shields.io/badge/Murilo_Coelho_Naldi-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)

## **Atenção!**
Neste resumo eu falhei.

Sugiro fortemente que assistam [a playlist do 3Blue1Brown](https://www.youtube.com/playlist?list=PLZHQObOWTQDNU6R1_67000Dx_ZCJB-3pi) sobre redes neurais. Lá está tudo muito bem explicado e bem ilustrado.

Este resumo passa pelos conceitos que a aula do professor Naldi passou e portanto deve tocar naquilo que ele vai pedir na prova, porém se você quer escrever nela como quem entende do tema e não como quem lembra da aula eu te digo que não só você deveria assistir a playlist como deveria buscar alguns exercícios sobre.

E vai ser um inferno.

Porém quando você olha pro nível das coisas que são feitas hoje por redes neurais você perceberá que este é só o primeiro dos infinitos círculos do inferno e que talvez você queira (ou tenha que) entrar mais fundo na toca do capeta.

Me parece muito interessante ir trocar uma ideia com o tinhoso dentro do mundo dessa analogia.

Enfim, já falei bosta o suficiente, lê o resumo aí.

## Multi Layer Perceptron
Em um perceptron de múltiplos níveis existem 3 características que permitem o uso de uma técnica chamada **retropropagação de erro**:
+ O modelo de cada neurônio inclui uma função de ativação não linear e diferenciável
+ Contém uma ou mais camadas escondidas entre a camada de entrada e a de saída 
+ Possui alto grau de conectividade

Ele trás algumas dificuldades consigo, dentre elas temos a análise teórica difícil devido o grau de conectividade e das funções não lineares, a dificuldade de visualização do processo de aprendizado devido a quantidade de neurônios escondidos. Por fim, o aprendizado é mais difícil pois há um espaço muito maior de possíveis funções e mais representações dos padrões de entrada.

O método de **back-propagation** é o meio pelo qual o **MLP** aprende. Ele possui a **forward phase** onde os valores são propagados pela rede camada por camada até a saída e as mudanças só ocorrem nos potenciais de ativação e nas saídas dos neurônios da rede. Na **backward phase** um sinal de erro é produzido comparando a saída desejada com a obtida, ele deve ser retropropagado por todas as camadas para que sejam ajustados os pesos sinápticos da rede.

A imagem a seguir representa uma **MLP**. 

![Aula05_img01.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula05_img01.png)

Cada sinal (estímulo) que vem da entrada da rede (**sinal de função**, o que vai do "começo" pro "fim") passa por cada neurônio e sai no fim da rede como um sinal de saída. A saída deve ser aquilo que se busca prever ou classificar. Cada neurônio fará o cálculo do sinal por meio de uma função que recebe entradas da camada anterior e possui seus pesos.

![Aula05_img02.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula05_img02.png)

Cada neurônio de saída ou escondido é desenvolvido para executar 2 cálculos:
1. Do sinal de função que aparece na saída de cada neurônio na forma de uma função não linear contínua do sinal de entrada e seus pesos.
2. Da estimativa do vetor gradiente que será usado na fase de retropropagação.

Os neurônios escondidos agem como detectores de atributos, conforme o aprendizado vai progredindo eles começam a descobrir os atributos que caracterizam os dados de treinamento, isso se da por meio da transformação não linear dos dados de entrada em um novo espaço, o **espaço de características**.

Nesse novo espaço, classes podem ser mais facilmente separadas do que no espaço original. É como se houvesse uma distorção do espaço tal qual quando é usado um truque de kernel em uma SVM.

Quando se pensa nas camadas intermediárias (não de entrada, que não é uma camada, e nem de saída), a primeira delas gera linhas retas no espaço de decisão, a segunda camada combina as linhas da camada anterior para formar regiões convexas (polígonos), da terceira camada para frente as figuras convexas são combinadas para formar espaços abstratos. Nos slides 15 ~ 18 se pode observar esse processo.

![Aula05_img03.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula05_img03.png)

Consideremos uma MLP . Tomamos um conjunto com vários vetores x(n) e uma série de rótulos d(n). O sinal de erro produzido é dado pela diferença entre o rótulo verdadeiro e o sinal produzido numa mesma camada.

O erro instantâneo de um neurônio J é dado por:

![Aula05_img04.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula05_img04.png)
 
O erro total da camada da rede conseguido pela soma de todos os neurônios da camada de saída é dado por: 

![Aula05_img05.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula05_img05.png)

Tomando *C* como o conjunto de todos os neurônios de saída, em um conjunto com *N* exemplos o erro médio sobre todos os exemplos (chamado de risco empírico) é dado por:

![Aula05_img06.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula05_img06.png)

Quando se pensa no treinamento de uma **MLP** ele pode se dar tanto em **batch** quanto **on-line**. Quando se treina em **batch** apenas se atualiza os pesos da rede quando todos objetos do batch são passados, isso se chama **época**. Em cada época embaralhamos os exemplos pois cada neurônio reagirá baseado na ordem que os exemplos lhes são apresentados.

Uma curva de aprendizado é obtida pelo gráfico do erro pelo número de épocas. 

Neste método realizam-se vários experimentos com valores diferentes para os parâmetros iniciais.

Busca-se uma estimativa mais precisa do vetor de gradientes por meio da derivada da função de custo com relação aos pesos em busca da convergência para um mínimo local.

Este processo faz com que a busca deixe de ser aleatória por natureza, podendo ficar presa em mínimos locais. É mais difícil também detectar mudanças pequenas nos dados e não se beneficia de exemplos redundantes uma vez que os pesos são apenas ajustados quando são vistos todos os exemplos.

Quando pensamos no treinamento **online**/**em fluxo**, o ajuste dos pesos ocorre após a apresentação de cada exemplo, então o objetivo é minimizar o erro instantâneo de toda a rede.

A busca no espaço de pesos multidimensional torna-se aleatória por natureza e há uma tendencia menor a ficar preso em mínimos locais.

Se tira maior vantagem da redundância nas instâncias pois os pesos são atualizados após a apresentação de cada exemplo. Este método também é melhor em detectar mudanças nos dados de treinamento.

## Back propagation
O potencial de ativação de um neurônio é dado pela soma das suas entradas (saída da camada passada) multiplicadas pelos seus pesos.

![Aula05_img07.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula05_img07.png)

A sentido no qual se deve atualizar os pesos *w* tendo base nos erros *e* obtidos é conseguido por meio das derivadas parciais do erro normal pelo instantâneo, do erro instantâneo pela saída, da saída pelo potencial de ativação e do potencial de ativação pelo peso:

![Aula05_img08.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula05_img08.png)

Esse caminhão depois de muitas operações serem feitas sobre ele se torna a seguinte equação:

![Aula05_img09.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula05_img09.png)

Confia (nos slides 28 ~ 36 e nas vídeo aulas do 3Blue1Brown sobre o cálculo de back prop e sobre gradient descent).

O gradiente local é dado por:

![Aula05_img10.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula05_img10.png)

O gradiente local define a mudança necessária nos pesos, ele é dado pelo produto do erro e da derivada da função de ativação do neurônio.

Os slides 37 ~ 49 explicam o algoritmo de back propagation. Isso não é simples de se resumir e mais uma vez eu te encorajo a assistir a série de vídeos do 3Blue1Brown.

## Funções de Ativação
Para calcular o δ para cada neurônio, precisamos conhecer a derivada da função de ativação φ(⋅) associada ao neurônio e para existir a derivada φ(⋅) deve ser contínua. Sendo assim, ser diferenciável é o único requisito para a função de ativação. Uma função comumente usada é a sigmoidal:

![Aula05_img11.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula05_img11.png)

Existe também a hiperbólica:

![Aula05_img12.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula05_img12.png)

As derivadas de ambas estão no slide.

## Taxa de Aprendizado
A taxa de aprendizado é o valor que dita a mudança nos pesos sinápticos da rede e suaviza a trajetória no espaço de busca o quão menor ela for, reduzindo a velocidade do aprendizado. Aumentando esta taxa temos um aprendizado mais veloz sob o risco de tornar a rede mais instável.

É interessante aumentar a taxa de aprendizado sem perder a estabilidade, isso é feito com o uso do **momentum α**. Se a atualização anterior de um dado peso tem o mesmo sentido da atualização atual entende-se que "estamos indo no caminho certo" e então "aceleramos" em direção a isso.

![Aula05_img13.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula05_img01.png)

![Aula05_img14.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula05_img14.png)

## Critérios de parada
Como estamos tratando de neurônios individuais, não podemos dizer que uma MLP convergiu e não possuímos outros critérios de parada bem definidos.

Um deles é tomar um valor suficientemente pequeno para o erro e parar quando ele for alcançado. Outra maneira é ter um vetor de pesos *W* mínimo. Uma outra ainda é testar a cada iteração a generalização da rede.

## Critérios para obter melhor desempenho
Sabemos que o método em stream é computacionalmente mais rápido que o modo batch quando se tem muitos dados e redundância neles.

Podemos apresentar exemplos seguidos com grande disparidade para melhorar o desempenho.

Podemos ainda escolher os valores para que fiquem entre os limiares da função de ativação.

Por fim, a normalização dos dados é muito importante para que melhore a convergência e leve em consideração os cálculos de vieses (*biases*) e pesos.

## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!
