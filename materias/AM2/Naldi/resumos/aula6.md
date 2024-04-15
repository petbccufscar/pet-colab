# Resumo Aula 6
> Resumo criado pelo aluno [João Pedro Trevisan](https://www.linkedin.com/in/joao-pedro-trevisan)

#### Professor
![Murilo Naldi](https://img.shields.io/badge/Murilo_Coelho_Naldi-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)

## Introdução ao Aprendizado Profundo
Como maneira de iniciar os estudos em aprendizado profundo conceitualizaremos o **Teorema da Aproximação Universal**. Ele diz que uma rede neural com uma única camada escondida e um número finito de neurônios pode aproximar qualquer função contínua, contudo o teorema nada fala sobre tempo de treinamento, complexidade da implementação ou mesmo sobre capacidade de generalização.

Pensar em uma única camada não é algo ótimo quando se pensa que podemos usar quantas quisermos. Com várias camadas, cada uma delas corresponde a uma representação e cada unidade representa uma características da entrada, estas unidades podem estar ativas simultaneamente.

Alguns exemplos são carros auto-dirigíveis, processamento de linguagem natural (ChatGPT), detecção de fake news, reconhecimento visual e de padrões, recomendação de conteúdo, composição de padrões (música, imagens).

Um dos problemas no treinamento de deep neural nets está justamente na correção de erro pois com um número elevado de camadas que atribuem pesos pequenos às variáveis do problema a tendencia é que o gradiente da função seja diluído e desapareça. Isso e o **underfitting**.

Se usarmos muitos parâmetros ou se treinarmos muito uma rede podemos gerar o **overffiting**.

![Aula06_img01.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula06_img01.png)

Existem métodos de tentar inicializar um treinamento de grandes redes de forma a gerar melhores regularizações, alguns deles são o treinamento não supervisionado, o dropout estocástico e a utilização de outros estimadores.

O uso de aprendizado não supervisionado força a rede a aprender a estrutura da distribuição dos dados de entrada, além de encorajar camadas escondidas a codificar a estrutura:

![Aula06_img02.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula06_img02.png)

Durante a fase de aprendizado a rede não supervisionada tenta imitar os dados fornecidos, o erro vem da saída imitada e serve para corrigir o modelo e ele pode ser expresso também como uma baixa probabilidade de ocorrência da saída incorreta ou como um estado instável.

Podemos usar uma técnica greedy e pre-treinar camada a camada de maneira não supervisionada, cada camada ajusta os parâmetros das anteriores.

![Aula06_img03.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula06_img03.png)

Primeira camada: encontra características que são mais comuns nos dados de treino do que em dados aleatórios
- Segunda camada: encontra combinações de características dos neurônios escondidos
- Terceira camada: combinações de combinações
- Quarta camada: ....

O pré-treino inicializa os parâmetros em uma região onde haja menos overffiting.

Depois de treinadas todas as camadas, adiciona camada de saída e treina toda a rede com aprendizado supervisionado. Dessa forma se ajusta todos os parâmetros e a rede se torna mais discriminativa.

Existe também a ideia do dropout que consiste em zerar alguns dos neurônios das camadas intermediárias aleatoriamente. Isso implica que os neurônios da mesma camada do neurônio removido serão forçados a reaprender e se tornarem capazes de reconhecer o padrão que aquele neurônio reconhecida. Isso diminui a especialização individual dos neurônios.

A técnica de Adagrad ajusta a taxa de aprendizado para cada parâmetro de acordo com os gradientes das iterações anteriores, isso é importante pois as vezes uma taxa muito alta ou muito baixa pode fazer com que o modelo "se corrija de mais ou de menos".

O AdaDelta estende o Adagrad e se utiliza de uma janela de gradientes ao invés da acumulação de todos os gradientes anteriores em busca de tornar o aprendizado ainda alto.

O RMSProp adiciona decaimento no cálculo da soma dos gradientes.

A técnica Adam combina Adagrad com RMSProp.

## Redes Neurais Convolucionais
Redes totalmente conectadas são mais adequadas para dados tabulados onde linhas representam exemplos de treinamento, colunas representam características e pode haver interações entre os atributos, porém não assumimos a priori nenhuma estrutura correspondente a como os atributos interagem.

Tomamos como exemplo uma imagem: cada pixel tem o seu valor de cor, porém pixels vizinhos possuem relação, em uma foto é possível afirmar que haverá gradiente de cores nas transições entre um objeto e outro.

Sendo assim, quando se pensa em imagens não há tanta informação em um pixel isolado quanto na composição de pixels de uma região.

Outra questão a se dar atenção é que é uma ideia bastante idiota criar um neurônio por pixel, veja:

![Aula06_img04.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula06_img04.png)

Ainda com imagens coloridas, podemos ter diferentes canais de cor em uma mesma imagem:

![Aula06_img05.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula06_img05.png)

Se levarmos em consideração que conjuntos de imagens podem ter o tamanho que desejarmos para um treinamento, essa tarefa se torna quase infinita.

As Redes Neurais de Convolução foram propostas para o reconhecimento visual baseando-se em conceitos da visão humana. Ela considera a relação entre os pixels vizinhos dada por filtros aplicados por uma operação de [**convolução**](https://www.youtube.com/watch?v=KuXjwB4LzSA).

Camadas convolucionais costumam requerer bem menos parâmetros do que camadas completamente conectadas. Cada região é chamada de **local receptive field**, cada uma dessas regiões tem um neurônio correspondente que possui uma função de ativação.

![Aula06_img06.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula06_img06.png)

Quando se deslisa o filtro se tem:

![Aula06_img07.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula06_img07.png)

Para uma imagem de 2x2 com apenas + e - possuímos 2⁴=16 possibilidades. Se aumentarmos essa matriz, ou se ao invés de positivo e negativo usarmos números reais a gente tá fudido. Tomemos um exemplo binário 2x2 para entender um filtro.

![Aula06_img18.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula06_img18.png)

Note que quando tentamos "resumir" as imagens de um "\\" e um "/" se tomarmos a soma dos valores este filtro será ruim.

A vantagem dos pesos compartilhados, porém, é a redução de parâmetros, se temos um filtro de tamanho 5 cada neurônio das camadas ocultas tem um viés e uma matriz de pesos 5x5 conectada a imagem, os mesmos pesos e vieses serão utilizados para cada um dos neurônios escondidos. Para cada filtro de 5x5 precisamos de 25 pesos + o bias, fazendo o uso de 26 filtros teremos 20 x 26 = 520 parâmetros definindo a camada convolucional.

Considere uma imagem de 3x3 e um kernel (filtro) de 2x2, se realizarmos a convolução dessa imagem usando o filtro iremos sumarizar os dados da seguinte forma:

![Aula06_img19.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula06_img19.png)

Um exemplo de como podemos usar um kernel (filtro) de convolução é na detecção de padrões. O seguinte filtro quando é usado em um processo de convolução é capaz de detectar bordas dentro da imagem:

![Aula06_img08.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula06_img08.png)

Tente imaginar uma convolução com este filtro (ou veja o vídeo linkado acima).

Conforme estudamos, a dimensão da saída da camada convolucional é definida pela dimensão da entrada e pela dimensão do kernel de convolução, se a dimensão da entrada for *Nh*x*Nw* e a dimensão do kernel for *Kh*x*Kw* então a saída terá dimensão (*Nh-Kh+1*)x(*Nw-Kw+1*). Podemos aplicar técnicas que afetam o tamanho da saída, como o **padding**.

O que motiva a usar o padding é que quando aplicamos a convolução há uma tendência a termos uma saída com dimensão consideravelmente menor do que a dimensão de entrada.

Podemos adicionar pixels nas bordas de uma imagem antes de rodar a convolução. Parece com o seguinte:

![Aula06_img09.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula06_img09.png)

A geração de neurônios de uma rede com uso de padding se encontra na imagem a seguir:

![Aula06_img10.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula06_img10.png)

Um outro conceito em CNN é o **stride** (passo largo). Ele é definido pelo número de linhas e colunas percorridas a cada movimentação do filtro de convolução. Até agora pensamos em strides de tamanho 1 tanto para altura quanto para largura, podemos aumentá-lo de forma a aumentar o passo na largura e na altura de mesma maneira ou de maneira diferente, ou seja, podemos "dar 2 passos na horizontal e 3 na vertical".

Um exemplo visual (em uma imagem minúscula de mais para ilustrar isso de forma correta) é desenhado a seguir:

![Aula06_img11.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula06_img11.png)

De maneira geral, quando a altura do stride é sh, e a largura do stride é
sw, a dimensão da saída é dada por:

(*Nh-Kh+Ph+Sh*)/*Sh*) X ((*Nw-Kw+Pw+Sw*)/*Sw*)

Por padrão, geralmente o padding é igual a 0 e o stride é igual a 1. Na
prática, geralmente não usa-se strides e padding heterogêneos. Ou
seja, geralmente usa-se *Ph* = *Pw* e *Sh* = *Sw*.

O padding pode aumentar a altura e a largura da saída. Isso pode ser
usado para dar à saída a mesma altura e largura da entrada, e ajuda a
considerar as bordas das imagens. O stride pode reduzir a resolução da saída, padding e stride podem ser usados para ajustar a dimensionalidade dos dados.

Nosso estudo sobre convolução até então não considera que imagens coloridas possuem 3 canais de cor, um para vermelho, um para azul e outro para verde, isso é chamado de canal de dimensão 3.

Quando se trabalha com mais que um canal pode se usar diferentes filtros, strides e paddings para cada canal, porém isso não é algo a ser feito de maneira arbitrária.

![Aula06_img12.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula06_img12.png)

tá ligado

É importante ter consciência de que o número de canais de entrada, até agora consideramos haver apenas um canal de saída. Contudo, aumentamos a dimensão do canal conforme a camada da rede neural fica mais profunda e, ao mesmo tempo, reduzimos a resolução para compensar a resolução espacial por maior profundidade de canal.

Seja C*i* e C*o* o número de canais de entrada e saída, respectivamente, e seja K*h* e K*w* a altura e largura do kernel. Para uma saída com múltiplos canais, é necessário um kernel com dimensão C*i* x K*h* x K*w* para cada canal de saída. Eles são concatenados à dimensão do canal de saída, dando origem a um kernel de convolução de dimensão  C*o* x C*i* x K*h* x K*w*.

O resultado em cada canal de saída é calculado a partir do kernel de convolução correspondente a esse canal de saída, obtendo sua entrada de todos os canais da entrada

A medida que processamos imagens, queremos reduzir gradualmente a resolução espacial das representações ocultas, geralmente queremos responder algum tipo de pergunta (do tipo "essa imagem tem um gato?"). Ao agregar informações produzindo mapas cada vez menores alcançamos este objetivo de aprender uma representação global.

A técnica de **pooling** consiste em aplicar uma janela de formato fixo deslizada sobre todas as regiões na entrada de acordo com o stride, computando uma única saída. Esta camada de pooling não contém parâmetros, ela normalmente calcula o valor máximo ou médio dos elementos da janela.

O pooling reduz a informação (dimensionalidade) agregando valores, a imagem a seguir é um exemplo de max pooling:

![Aula06_img13.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula06_img13.png)

A combinação da convolução com o pooling nos da um processo da seguinte forma:

![Aula06_img14.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula06_img14.png)

Note como a informação "linha diagonal 1" e "linha diagonal 2" é bem mais simples que a informação contida em uma matriz 3x3. Quando se faz este processo em um conjunto de imagens seus alvos ficam bem mais fáceis de serem identificados e buscados:

![Aula06_img15.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula06_img15.png)

## Montando uma CNN
De maneira geral a LaNet (LeNet-5) possui 2 partes:
- Um codificador convolucional de duas camadas de convolução.
- um bloco denso consistindo de três camadas completamente conectadas.

![Aula06_img16.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula06_img16.png)

Ele faz uso de uma camada de convolução com um kernel 5x5 com função de ativação sigmoidal. Existe uma operação de average pooling (2x2) com stride 2, a primeira camada convolucional tem 6 canais de saída e a segunda tem 16.

![Aula06_img17.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula06_img17.png)

## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!
