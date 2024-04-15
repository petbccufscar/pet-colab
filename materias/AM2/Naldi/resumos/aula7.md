# Resumo Aula 7
> Resumo criado pelo aluno [João Pedro Trevisan](https://www.linkedin.com/in/joao-pedro-trevisan)

#### Professor
![Murilo Naldi](https://img.shields.io/badge/Murilo_Coelho_Naldi-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)

## Busca Evolutiva
Como forma de iniciar os estudos de busca evolutiva tomaremos o problema de de otimização onde se busca por valores mínimos e máximos de uma dada função. Isso pode ser considerado uma "busca guiada" pela função a ser otimizada e o guia da busca pode ser uma heurística por exemplo.

Uma das tarefas clássicas da busca evolutiva é a **subida/descida de encota** (hill climbing). Este processo consiste em mudar para uma solução melhor do que a anterior segundo uma dada heurística, este processo tem essa cara:

![Aula07_img01.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula07_img01.png)

Este processo de hill climbing, como na descida do gradiente da função de uma rede neural por exemplo, se pode ficar preso em mínimos ou máximos locais. Como solução para isso temos a **têmpera simulada**, um algoritmo inspirado no processo de se temperar algum material através do calor. Nele se escolhe o próximo estado aleatoriamente com objetivo de escapar das regiões locais. Ela usa um parâmetro de "temperatura".

Em contraponto a este processo temos a opção de inicializar o hill climbing com pontos diferentes para buscar diferentes regiões.

![Aula07_img02.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula07_img02.png)

têmpera simulada

Chegamos então nos **algoritmos evolutivos**, que são inspirados na Teoria da Evolução de Darwin, principalmente no que tange a "aptidão à sobrevivência" de um dado "indivíduo", isto é, todos tem a chance de passar suas características a diante, porém os mais aptos tem mais chances.

Os **algoritmos evolutivos** são diferentes de **algoritmos genéticos** que tem que ter uma sequência de números que representam uma solução, um gene. Todo **algoritmo genético** é **evolutivo**, mas a reciproca não é verdadeira.

Imaginemos que um possível estado/solução possa ser apresentado como um indivíduo de uma população de estados, a ideia é aplicar a seleção natural como um processo de busca por soluções melhores.

De início para entender o processo dos algorítimos evolutivos temos o conceito de **indivíduo**, na natureza as características dos **indivíduos** são codificadas em **genes** e o conjunto dos **genes** é um **genótipo**. O **genótipo** faz a base do **fenótipo** que é a expressão das características codificadas pelos **genes**.

O **genótipo** é composto por **cromossomos**, ou seja, vetores de números que podem ser **binários**, **inteiros** ou **reais**. **Fenótipo** é a forma que o **genótipo** é aplicado para solucionar o problema, tomemos o exemplo:

O lucro de uma empresa é dado em função das quantidades *X1*, *X2* e *X3* de três determinados produtos construídos por minuto. É dada uma função F() em centenas de reais, exemplo:

~*i ={x1 = 4, x2 = 2, x3 = 7}, f(i) = 0,05*

Se *i* é uma possível solução para do problema podemos codificar esta solução em um genótipo, isto é, um cromossomo que pode ser um vetor de números inteiros:

![Aula07_img04.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula07_img04.png)

O **fenótipo** neste exemplo está relacionado com o resultado da solução *i*, é o que o **genótipo** *Ci* consegue obter. Funções serão usadas para medir o quão bom é um resultado e quanto melhor ele for mais **apta** está a solução. Por este motivo chamamos a função utilizada para avaliar um individuo de **função de aptidão**.

No caso do nosso exemplo a **aptidão** é dada pelo lucro.

Para que um **algoritmo evolutivo** funcione é necessário que, assim como na natureza, haja uma **população**. É importante também que haja diversidade entre os **indivíduos** (soluções) para que a busca possa ocorrer em um espaço amplo de diferentes estados, evitando assim os mínimos/máximos locais.

Observe:

![Aula07_img03.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula07_img03.png)

Para o nosso caso, a população inicial é a primeira população do **AE** (algoritmo evolutivo). Existem muitos métodos para a escolha bem orientada para a população inicial, algumas delas são:
- Soluções de potencial conhecido
- Soluções utilizadas anteriormente
- Soluções aleatórias
- Uma mistura das opções anteriores

O passo da **avaliação** se dá quando comparamos a **aptidão** dos **indivíduos** que nós possuímos. Esta função de aptidão pode ser uma função específica para o problema ou mesmo ser alguma métrica de avaliação de algoritmos de AM como recall, skewness, davies bolduin, a função de erro de uma rede neural ou até um conjunto de métricas.

Se possuirmos múltiplas métricas escolheremos indivíduos que são os melhores em pelo menos uma delas.

Seguimos então para o passo de **seleção**, para tanto é preciso selecionar os indivíduos baseados em sua aptidão ou realizar um **seleção proporcional**, este tipo de seleção é proporcional a aptidão dos indivíduos e a probabilidade de seleção se dá da seguinte forma:

![Aula07_img05.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula07_img05.png)

Podemos comparar a seleção proporcional como uma roleta em que cada fatia corresponde a cada indivíduo, conceitualmente uma probabilidade é dada por um valor positivo entre 0 e 1, por este motivo os valores devem ser tratados antes de serem usados como num processo de padronização MinMax.

Deve se tomar cuidado com a padronização, mesmo que ela possa retirar os valores negativos (o que é necessário para o processo de seleção pois não pode haver probabilidade negativa) ela vai torná-los muito próximos ou iguais a zero, matando as chances deles serem selecionados.

Note que está escrito **padronização** e não **normalização**. A diferença é que uma normalização que passa por uma distribuição normal e possui valores negativos ainda pode resultar em números negativos.

Existe também a **seleção determinística** que é muitas vezes realizada pelo **método do torneio** onde se sorteia dois indivíduos para se "enfrentarem" e "sobra" o mais forte, sendo que o "perdedor" volta para o banco de seleção podendo ser selecionado novamente. Isso significa que os números não precisam lutar até a morte e que se eles conseguirem conciliar suas diferenças eles poderão realizar uma rebelião no calabouço do coliseu e tentar matar o estudante/pesquisador que tanto os tortura.

Chegamos então à etapa de **cruzamento e/ou mutação**. Neste ponto **operadores genéticos** são responsáveis pela modificação dos cromossomos ao longo das gerações, eles serão os responsáveis pela busca de novas soluções e podem ser guiados ou não.

O primeiro método para qual voltaremos nossa atenção é o de **cruzamento/recombinação**, nele selecionamos indivíduos dois a dois para serem os **progenitores** de um novo indivíduo. Serão combinadas características dos indivíduos selecionados.

O **cruzamento** escolhe **progenitores** e troca neles pares de **cromossomos** para gerar **descendentes**:

![Aula07_img06.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula07_img06.png)

Algo a se atentar é que existem algoritmos que transformam em binário os valores em cada **cromossomo**. Isso significa que você pode estar "cortando um número" e isso não faz sentido, é preciso estudar como a solução que você está empregando realiza a combinação de **cromossomos**. 

O objetivo deste cruzamento é gerar novas soluções que possuem características dos progenitores. Ainda que se tenha gerado um indivíduo que só tenha características ruins isso é bom para gerar variabilidade no espaço de busca.

Outro método de se alterar seus indivíduos é a **mutação**, nela modificamos parte de um cromossomo (de forma aleatória ou heurística) de modo a gerar uma nova característica no indivíduo que não foi recebida por seus **progenitores**, isto é, introduzir características novas que não estão na nossa população.

Para gerar soluções inéditas por meio de **mutação** temos como parâmetro a **taxa de mutação** que define a probabilidade de um cromossomo sofrer mutação. Se essa taxa for muito alta o processo de busca para de se assemelhar a uma subida de encosta e passa a ser algo que tende ao aleatório.

Existe um operador chamado **elitismo**. Aplicá-lo significa selecionar uma pequena parcela dos melhores indivíduos de uma população e passá-los para a próxima. Este processo tem como objetivo evitar que uma solução boa perca sua chance de passar suas características para frente, contudo, errar para cima na proporção pode fazer com que o algoritmo convirja para o espaço onde os melhores indivíduos estão ocupando, ou seja, você estará preso em uma região e isso é o oposto do que se busca em algoritmos genéticos.

Depois de todas estas operações temos uma **nova população**, a partir dela realizaremos este processo de novo por novas **gerações**.

Precisamos de **critérios de parada** para que o algoritmo não rode infinitamente, alguns critérios podem ser:
- Convergência da população (mutações e seleções já não alteram grandemente o espaço de busca)
- Número máximo de gerações
- Limite de gerações **sem melhora**

A **população final** é o resultado do AE. Se aplicarmos **elitismo** teremos a melhor solução encontrada, caso contrário é recomendado armazenar o indivíduo mais apto fora das populações. Ela pode ser analisada por um especialista de domínio de forma a permitir a escolha de indivíduos. Podemos também realizar o ensemble dos indivíduos de forma a encontrar uma situação ideal.

Do slide 59 ~ 70 existe um exemplo do processo de um AE.

Algumas aplicações de AE são:
- Otimização de função numérica
- Otimização combinatorial
- Problema do caixeiro viajante
- Problema de empacotamento
- Alocação de recursos (job shop schedulling)
- Projeto de pontes
- Jogos
- Otimização de redes neurais

Nos slides 73 ~ 82 há um exemplo de como algoritmos genéticos podem ajudar com o problema do caxeiro viajante.


## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!
