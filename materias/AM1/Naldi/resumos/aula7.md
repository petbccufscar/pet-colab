# Resumo Aula 7
> Resumo criado pelo aluno [João Pedro Trevisan](https://www.linkedin.com/in/joao-pedro-trevisan)

#### Professor
![Murilo Naldi](https://img.shields.io/badge/Murilo_Coelho_Naldi-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)

## Introdução ao Agrupamento
Modelos preditivos tentam prever o valor de um atributo objetivo (atributo dependente) a partir de outros (atributos independentes). No aprendizado supervisionado isso pode ser feito para rótulos discretos por meio de classificação ou para rótulos contínuos por meio de regressão.

Se não possuirmos um atributo objetivo podemos querer que "os dados falem por si". Aí entram os modelos descritivos que tentarão derivar padrões que resumam relacionamentos subjacentes nos dados.

Note o seguinte fluxograma:

![AM1_aula08_img01.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula08_img01.png)

Perceba que ele não descreve todo tipo de aprendizado que existe, mas a titulo de aprendizado ele descreve bem o que veremos neste curso.

Tratando-se de tarefas **não supervisionadas** temos:
+ **sumarização**: descrição simples e compacta dos dados. Como exemplo CF vectors, micro grupos, kernels são estruturas "compactas" de dados.
+ **associação**: buscar associação entre atributos.
+ **agrupamento**: deseja estabelecer relações entre grupos de exemplos.

A título de exemplo, a **redução de dimensionalidade** não é uma tarefa preditiva, mas nem sempre será **não supervisionada**. De qualquer forma, ela é um exemplo de tarefa **descritiva**.

O **agrupamento de dados** é o conjunto de técnicas que consistem na divisão supervisionada de objetos em grupos e essa forma de trabalhar apresenta vantagens quando não se conhece previamente os dados.

![AM1_aula08_img02.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula08_img02.png)

Modernamente gera-se muitos dados e eles nem sempre são criados tendo o aprendizado de máquina em mente. Quando se tem dados que foram gerados sem um objetivo específico o **agrupamento** é uma boa técnica para se minerar informações de um volume de dados.

Isso significa dizer que a subjetividade é intrínseca a tarefa de **agrupamento**. Podem haver muitas maneiras de se agrupar os mesmos dados.

![AM1_aula08_img03.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula08_img03.png)

A principal questão a ser levantada é: *Sem classes, como o algoritmo aprende?*

Para responder isso devemos pensar que o algoritmo objetiva formar grupos e para isso é preciso definir o conceito de grupos.

Um grupo (ou *cluster*) é formado por objetos similares entre si e dissimilares em relação a outros objetos de outros grupos.

Matematicamente, os objetos podem ser vistos como pontos n-dimensionais (para n atributos) que agrupam-se com objetos similares. A distância entre eles representa a dissimilaridade.

![AM1_aula08_img04.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula08_img04.png)

Este conceito de grupos é o mais uga uga que até mesmo um neandertal consegue entender. Um outro tipo de grupo que nossos cérebros de macacos pelados e tecnológicos consegue compreender é um grupo formado por **densidade**. Note, macaco nu:

![AM1_aula08_img05.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula08_img05.png)

É muito claro que existem 2 grupos no primeiro gráfico e 4 no segundo. Isso se dá não pela distância entre os pontos de forma geral, mas pelo encadeamento das distâncias que agrupam os itens mesmo que alguns deles estejam mais próximos de outros grupos.

Há muita subjetividade no trabalho com agrupamento. Pense no seguinte conjunto de dados e no **agrupamento** realizado entre eles. Qual dos dois agrupamentos é correto?

![AM1_aula08_img06.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula08_img06.png)

![AM1_aula08_img07.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula08_img07.png)

E se eu lhe disser que o conjunto de dados original era agrupado da seguinte maneira:

![AM1_aula08_img08.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula08_img08.png)

A literatura sobre **agrupamento** é bem rica, neste curso estudaremos os algoritmos que são a base pra muitos dos algoritmos usados hoje em dia.

Estudaremos o processo de **KDD** (knowledge discovery in databases) para agrupamento. Suas etapas são as seguintes:

![AM1_aula08_img09.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula08_img09.png)

Um elemento muito importante nesse processo é a dimensão dos dados. Se esses dados não estiverem normalizados e possuírem escalas muito diferentes você terá problemas. Se você possuir muitas dimensões e os dados ficarem pulverizados no espaço você terá problemas. Isso se deve ao fato de que ***agrupamento leva em consideração a medida de similaridade (distância)***.

Sendo assim, a **preparação dos objetos** pode envolver normalização, seleção (antes da seleção) ou técnicas semelhantes.

A **medida de (dis)similaridade** será definida entre pares de objetos.

A **realização** deste agrupamento será feita por meio da escolha de um algoritmo e de sua parametrização.

A **validação** avalia a qualidade dos grupos ou estima com que grau os grupos gerados refletem o conjunto de dados.

Tudo isso tem uma gigante gama de aplicações tanto no marketing, quanto na astronomia, na bioinformática, na mineração de textos e em muitos outros campos. Além disso as abordagens variam para dados numéricos ou simbólicos, relacionais ou não relacionais, para partições ou hierarquia de partições e muito mais.

Falaremos sobre **dados relacionais e não relacionais**.

Métodos **não relacionais** requerem objetos a serem agrupados. Já os **métodos relacionais** requerem apenas as (dis)similaridades entre os objetos. Suas vantagens abordam de maneira unificada o tratamento de atributos mistos, abrem margem pro trabalho com dados sigilosos pois não exige acesso a eles e se pode trabalhar com domínios de aplicação subjetivos. Sua desvantagem pousa no custo computacional mais elevado.

Quanto aos **métodos de agrupamento**, temos os **particionais** e os **hierárquicos**. 

Os **métodos particionais** constroem uma partição dos dados e os **hierárquicos** constroem uma hierarquia de partições:

![AM1_aula08_img10.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula08_img10.png)

No caso da **hierarquia**, o quão mais próximos estiverem os dados (lisa e marge, as irmãs da marge), mais eles tendem a participar de um mesmo grupo. O menor grupo da hierarquia é o elemento isolado.

Os **agrupamentos** podem ser feitos **com e sem sobreposição**:

![AM1_aula08_img11.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula08_img11.png)

A imagem é auto explicativa.

Quanto a partição, a definição mais rigorosa é a seguinte:

Para um conjunto *N* de objetos a serem agrupados da forma *X = {X1, X2, ..., Xn}*, uma **partição rígida** é uma coleção de *k* grupos não sobrepostos *P = {C1, C2, ..., Cn}* tal que:

![AM1_aula08_img12.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula08_img12.png)

O **agrupamento de dados** pode ser visto como um problema combinatorial em que o número de possíveis formas de se agrupar *N* objetos em *k* grupos é dado por:

![AM1_aula08_img13.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula08_img13.png)

## Algoritmo K-means
É o algoritmo mais clássico na área de mineração de dados em geral e é listado como um dos 10 algoritmos mais influentes da mineração de dados. Ele data da década de 50 e não há um consenso sobre quem o inventou.

Seu passo-a-passo é:
1. Escolher aleatoriamente um número k de protótipos (centros) para os grupos
2. Atribuir cada objeto para o grupo de centro mais próximo (segundo alguma distância, Euclidiana por exemplo)
3. Mover cada centro para a média (centróide) dos objetos do grupo correspondente
4. Repetir os passos 2 e 3 até que algum citério de convergência seja obtido:
	+ Número máximo de iterações
	+ Limiar mínimo de mudança nos centróides

Nos slides 38 ~ 44 há um exemplo de "rodagem" desse algoritmo.

Como forma de otimização, o algoritmo minimiza a seguinte função de objetivo conhecida como **sum of squared errors** (SSM):

![AM1_aula08_img14.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula08_img14.png)
Xj = ponto, Xc = centróide

Para utilizar o **k-médias** devemos considerar as questões de:
+ protótipos inicias
+ tamanhos, densidades e formas globulares
+ grupos vazios
+ número de grupos

A questão da **escolha de protótipos inicias** é uma das áreas mais pesquisadas no campo do **k-means**. O resultado pode variar de forma significativa dependendo da escolha das sementes (protótipos) iniciais dos grupos.

Note os diferentes resultados mediante a escolha de protótipos inicias:

![AM1_aula08_img15.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula08_img15.png)

![AM1_aula08_img16.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula08_img16.png)

O erro do do **k-means** (SSE) geralmente é o parâmetro para definir o melhor agrupamento, quanto menor o *J* melhor o resultado.

Pensando num caso ideal para o **k-means** poderíamos selecionar *k* protótipos iniciais tal que *k* = número de grupos diferentes nos dados (assume-se que sabemos essa informação divina a priori). Assumimos também que os grupos são balanceados em suas quantidades de observações. A probabilidade de se selecionar 1 protótipo de cada grupo é dada por.

P = (nº de maneiras de selecionar 1 objeto de cada grupo)/(nº de maneiras de selecionar *k* entre *N* objetos)

Se houverem 10 grupos e cada um tiver aproximadamente *N*/*k* objetos a probabilidade de se selecionar um objeto de cada grupo é de 3,6 \* 10⁻⁴.

Nos slides 54 e 55 temos exemplos de diferentes tipos de inicialização.

Resolver este problema por meio de múltiplas execuções aleatórias é computacionalmente custoso (mas pode ser feito, depende). Podemos buscar uma seleção informada de forma que escolhemos um protótipo nas próximas iterações que seja mais distante da anterior (**Kmeans++**, isso tem problemas com *outliers*). Ou ainda podemos realizar uma busca guiada.

Nos slides 57 ~ 61 há uma exploração da variação de *J* e depois de *K*.

A função de objetivo *J* tende a valores menores a medida que *K* aumenta. Isso é natural pois a medida que o número de grupos aumenta o tamanho deles diminui.

A sugestão de muitos autores é definir um *K* que tenha uma melhora significativa no valor de *J* e não deixar esse *K* subir quando a melhora for insignificante. Quando usamos *K* suficientemente alto (depende totalmente do conjunto) nós subdividimos grupos.

![AM1_aula08_img17.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula08_img17.png)
A função objetivo não é necessariamente *J*.

Nos slides 64 ~ 69 temos um exemplo do funcionamento do **k-means++**. Note que esse algoritmo é grandemente sensível à *outliers*.

Variações do **k-means** são por exemplo o **k-medians** (por medianas). O **k-medóides** que opera com medóides (ponto dentro de um grupo que tem menor distância entre todos os outros) que acaba sendo um algoritmo **relacional**.

O **k-means** apanha para:

Tamanhos de grupos diferentes
![AM1_aula08_img18.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula08_img18.png)

Variação nas densidades dos grupos
![AM1_aula08_img19.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula08_img19.png)

Formas não globulares
![AM1_aula08_img20.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula08_img20.png)

## Agrupamento Hierárquico
O slide dessa aula começa com um ótimo exemplo do funcionamento de algoritmos de **agrupamento hierárquico botom-up** que vai dos slides 4 ~ 17.

Note que em um ponto do algoritmo temos um número máximo de grupos e esse número vai descendo. Isso ocorre por meio da comparação de todos com todos e agrupamento baseado na distância.

A definição de **hierarquia** que usamos nesse tipo de algoritmo é *a sequência de partições **aninhadas***. Uma partição *P1* está aninhada em *P2* se cada componente de *P1* é um subconjunto de um componente de *P2*.

A montagem de **hierarquias** pode ser feita **aglomerativamente** (bottom-up) ou **divisivamente** (top-down).

Em algoritmos **bottom-up** inciamos colocando cada objeto em um grupo e encontramos o melhor par para unir um grupo e unimos depois os pares de grupos.

Em algoritmos **top-down** começamos com todos objetos em um único grupo e subdvidimos o grupo em dois novos subgrupos. Este último passo é repetido recursivamente.

Estes algoritmos são (ou podem ser) relacionais pois operam sobre uma matriz de dissimilaridade. A forma de se definir a dissimilaridade **entre os grupos** (e não os pontos) pode fazer uso de vários parâmetros:

+ **Distância minima**: minima distância entre dois pontos de dois grupos. Algoritmo hierárquico de **ligação simples** (mais próximo).
	+ Isso gera o efeito de **encadeamento**, o que torna possível a identificação de grupos com formas não-globulares (slide 28).
		+ Um problema do **encadeamento** é o **chaining effect** que torna o algoritmo bastante sensível a ruído e outliers (slide 29).
+ **Distância máxima**: máxima distância entre dois pontos.
	+ menos sensível a ruídos e outliers.
	+ tende a quebrar grupos grandes.
	+ só funciona bem com grupos globulares.
+ **Média**: Calcula a média das distâncias entre todos os objetos de dois grupos. Fazer isso obtém um resultado intermediário entre algoritmos de ligação simples e completa.
	+ Funciona para formatos globulares.
	+ Menos susceptível a ruídos e outliers.
+ **Centroides**: O centróide do grupo a ser gerado é a média dos centróides dos grupos a serem combinados.
	+ Perde-se informação sobre o formato dos grupos.
	+ É limitado a distância euclidiana (o algoritmo não é mais relacional).
+ **Outros**:
	+ **Ward's**: tenta formar variância mínima entre os grupos.
	+ **bisecting k-means**: baseia-se em um **k-means** de *K* = 2.

Só vale a pena usar um algoritmo **hierárquico** se pudermos usar essa informação de hierarquia. Para fazer isso temos o **dendrograma**, uma forma de representação de agrupamento hierárquico que nos mostra as hierarquias e as dissimilaridades (altura do nó interno mais baixo compartilhado pelos grupos). Nos slides 39 ~ 44 existe um exemplo de construção de **dendrograma**.

Partições são obtidas por meio de cortes horizontais no **dendrograma** onde haja um número *K* de grupos que você queira.

Para que seja gerado o **dendrograma** precisamos ordenar de forma apropriada os objetos no eixo horizontal.

Nos slides 48 e 49 há um exemplo de como o dendrograma pode indicar o número natural de grupos e de como *outliers* podem influir em sua construção.


## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!
