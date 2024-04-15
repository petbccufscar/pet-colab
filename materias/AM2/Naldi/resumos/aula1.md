# Resumo Aula 1
> Resumo criado pelo aluno [João Pedro Trevisan](https://www.linkedin.com/in/joao-pedro-trevisan)

#### Professor
![Murilo Naldi](https://img.shields.io/badge/Murilo_Coelho_Naldi-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)


## Combinação de Modelos Pt.2 - O Império Contra-Ataca
A combinação de modelos é usada grandemente em tarefas **preditivas**, contudo tarefas **descritivas** também podem ter seus modelos combinados. Além disso podemos realizar a combinação de modelos descritivos com modelos preditivos, criando um novo modelo **semi-supervisionado**.

**Big data** é um fenômeno sobre o qual a combinação de modelos pode ser aplicada devido a variedade dos dados e de suas formas, fato que favorece tarefas descritivas e até a experimentação com diferentes técnicas e combinações delas.

Relembrando o que foi estudado na ultima matéria, Hansen e Salamon definem que múltiplos preditores só podem ser combinados com sucesso se eles erram de maneira independente, se eles tem todos a mesma taxa de erro e se esta taxa é menor que 0,5.

**Atenção**: A questão da semelhança entre as taxas de erro é posta devido ao fato de que se elas forem muito díspares é possível se obter um resultado de combinação pior que o melhor modelo anteriormente gerado, dessa maneira as taxas de erro na verdade não precisam ser iguais, mas devem ser semelhantes.

Se feito de maneira correta, o **ensemble** "caminha" nas taxas e probabilidades de erro da seguinte forma:

![Aula02_img01.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula02_img01.png)

A imagem a seguir foi apresentada na matéria passada, ela mostra 4 grupos de 3 classificadores, todos com 0,6 de acurácia. Sua combinação gera classificadores com diferentes acurácias quando varia a questão da independência de seus erros:

![Aula02_img02.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula02_img02.png)

As questões que nos restam agora são:
- Como **combinar** diferentes modelos?
- Como **gerar** diferentes modelos?

Podemos ter **modelos de combinação homogêneos** gerados pela combinação de modelos que **advém de algoritmos iguais**. Os **modelos heterogêneos** são gerados por **algoritmos diferentes**.

Existe uma maneira de se medir se vale a pena combinar dois modelos que se tenha. Um dos métodos usados para isso é o ***Inter-rated agreement*** gerado pela seguinte equação:

![Aula02_img03.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula02_img03.png)

Quanto mais os modelos discordarem, possuindo uma taxa de erro semelhante, melhor será o resultado de sua combinação.

Sobre as maneiras de se combinar modelos podemos realizar por meio de **votação** ou **seriação**, feitos de maneira **estática** ou **dinâmica**.

O método mais comum é o de **votação**. Ele pode ser feito de maneira **uniforme** ou **ponderada** (atribui um peso maior a um ou mais dos classificadores) e como os processos de votação são independentes eles podem ser paralelizados.

**Votações simples** devem ser realizadas com números ímpares de modelos para evitar empate, diferente da **votação ponderada**. Ainda assim, estatisticamente, pode haver empate na votação ponderada.

Os métodos de **seriação** consideram componentes em série, isso pode ser feito de diversas maneiras, porém todos envolvem processos realizados em sequência com comparação com resultados passados (pode ser o imediatamente anterior ou com outros modelos pretéritos).

Possuindo *m* modelos com *k* classes podemos usar vários critérios diferentes para definir qual será o modelo escolhido:

![Aula02_img04.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula02_img04.png)

![Aula02_img05.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula02_img05.png)

*P* é a probabilidade de uma classe ser escolhida.

Métodos **estáticos** consideram todos os modelos na combinação e essa escolha nunca muda. Os métodos **dinâmicos**, por sua vez, baseiam-se no fato de que diferentes modelos tem diferentes resultados operando em diferentes regiões do espaço e portanto podemos escolher quais serão combinados dinamicamente.

Estudaremos a **generalização por pilha** como forma de combinação de modelos **heterogêneos.** Note a imagem:

![Aula02_img06.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula02_img06.png)

Este método usa como entrada do classificador de nível 1 a saída dos classificadores combinados em nível 0.

Para combinar **modelos homogêneos** precisamos ter diversidade em respostas, mas como conseguir isso se o algoritmo sobre os dados é o mesmo?

Podemos alterar parâmetros com a consciência de que muitos algoritmos podem não ser deveras sensíveis a parâmetros. Podemos também mudar os dados por meio de técnicas de amostragem e reamostragem ou a introdução de ruído nos dados (**perturbação de exemplos**).

Alguns dos processos que podem ser usados para favorecer a combinação de modelos homogêneos é o **Bootstrap aggregating** ( **Bagging**) onde se cria conjuntos de exemplos por amostragem com reposição de forma a criar novos conjuntos de dados do mesmo tamanho do conjunto original.

Claro que novas amostras terão exemplos iguais aos da amostra original, mas essa taxa gira em torno de 1/3 de duplicações. Gera-se um classificador para cada amostragem.

Tomando como exemplo o classificador **Random Forrest**, o processo de **bagging** pode mudar os atributos selecionados, pode mudar os pontos de corte e pode afetar a distribuição dos dados nos filhos de cada nó de decisão. Criando uma árvore para cada conjunto de treino gerado por **bagging** selecionamos *i* atributos aleatoriamente desta árvore para determinar os nós de decisão de cada nível e não utilizamos quaisquer estratégias de poda. Este processo é repetido uma vez para cada árvore que queremos gerar.

Os slides 36 ~ 46 ilustram este processo.

Uma outra maneira de se combinar classificadores fracos para se gerar um classificador forte é por meio de **boosting**. Nesta técnica se atribui maior peso para as classes que os classificadores anteriores não conseguem acertar, desta forma guiamos a criação de um classificador que mira corrigir os erros passados ou mesmo se especializar em um tipo de classificação.

Visite a aula 07 do semestre passado para ler o exemplo de **boosting** muito bem explicado, assim como o de **adaboost** que faz uso dos **stumps**.

Como explicação rápida, **adaboost** baseia-se em amostragem aleatória e na criação de **stumps** (árvores de um só nível com um só atributo) e na combinação deles. É importante notar que isso só funciona com classes binárias.

## Classificação Binária vs Classificação Multiclasse

O grande problema da classificação multiclasse é a abundância de valores que são buscados para o atributo alvo. Em classificação binária possuímos apenas duas classes, o que facilita muito o processo.

Fica claro que para múltiplas classes não ajudam soluções apenas capazes de separar o espaço por meio de uma única fronteira. SVM é um algoritmo que não funciona bem para classificação multiclasse, por exemplo.

![Aula02_img09.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula02_img09.png)

Para mitigar isso, podemos usar abordagens conhecidas como **one-vs-all** e **one-vs-one**. A primeira delas é exemplificada na imagem a seguir:

![Aula02_img10.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula02_img10.png)

Para o exemplo de três classes, criam-se três classificadores binários e computa-se o score de cada um deles.

O método de **one-vs-one** divide os datasets em datasets binários e então os classifica.

O método de **ECOC** consiste em se decompor um problema multiclasse no maior número possível de problemas binários. Isso é feito gerando **metaclasses** compostas por combinações de classes. É gerada então uma **matriz de decomposição** por meio de um processo de **encoding** que gera uma sequencia de bits representando cada classe onde cada bit identifica a associação da classe a um classificador.

O **decoding** faz um classificador binário lançar um voto para uma das duas metaclasses usadas no treinamento. O resultado é então colocado em um vetor e comparado com as classes na matriz de decomposição

Além da classificação **multiclasse**, exitem a **classificação multirrótulo** e a **regressão multiobjetivo**. A primeira delas se dá quando um mesmo exemplo pode ter mais de um rótulo associado a ele ao mesmo tempo e o último é similar à classificação multirrótulo no caso da regressão.

Outros tipos de problema são as classificações **hierárquica**, já estudada a fundo na matéria passada, e **multi-saída** que trata de vários problemas **multi-classe**.

Voltando a questão de **classificação multirrótulo**, alguns exemplos práticos são músicas ou filmes que pertençam a mais que um gênero, fotos com vários objetos, proteínas com várias funções, livros multidisciplinares.

Para tratar este tipo de problema podemos criar novos rótulos que agregam os originais, podemos remover rótulos ou exemplos, podemos decompor os itens do espaço amostral, porém a abordagem mais simples é a **relevância binária**.

Se tivermos *k* possíveis rótulos para cada exemplos, criaremos *k* classificadores binários, cada um dos quais será treinado para predizer se cada exemplo possui ou não um rótulo específico associado a ele.

O processo de **relevância binária** costuma causar desbalanceamento além de assumir que os rótulos são independentes.

Para aproveitar a dependência entre as classes podemos **encadear os classificadores**, como exemplo se temos uma foto onde observamos o mar, dificilmente haverá um carro na foto, é mais provável que haja um barco.

Nesta técnica usaremos o rótulo gerado pelo primeiro modelo como atributo para gerar a saída do segundo modelo. Nos slides 22 ~ 24 existe um exemplo disso.

A partir da combinação dos rótulos os quais um objeto pertence podemos realizar um **label powerset** que é a criação de rótulos baseado nos rótulos que uma instância possui. Isso é uma boa opção quando temos poucos rótulos pois o número de rótulos pode crescer muito. A sequência dos slides 26 e 27 expõe isso.

Para tratar problemas multirrótulo usamos algoritmos adaptados para problemas deste tipo.

Resumir ML kNN, RNAs e RAKEL (random k-labelsets) depois de ver vídeos sobre

Por fim, diferente dos problemas single-class não podemos utilizar as medidas de avaliação estudadas até aqui, devemos adaptá-las ou criar novas.

Um exemplo de medida de avaliação é a **Hamming Loss** onde a (Yi, Zi) é a distância de hamming entre os vetores verdadeiro e predito (soma do XOR). Quanto menor melhor.

![Aula02_img07.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula02_img07.png)

A partir de agora estamos comparando vetores.

![Aula02_img08.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula02_img08.png)


## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!
