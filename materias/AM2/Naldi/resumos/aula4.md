# Resumo Aula 4
> Resumo criado pelo aluno [João Pedro Trevisan](https://www.linkedin.com/in/joao-pedro-trevisan)

#### Professor
![Murilo Naldi](https://img.shields.io/badge/Murilo_Coelho_Naldi-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)

## Aprendizado de Máquina Sobre Fluxo de Dados
**Dados em fluxo** são dados que estão sendo gerados e colhidos constantemente. Trabalhar com fluxo de dados é diferente de trabalhar com conjuntos de dados, principalmente no que tange volume e velocidade desses dados.

Basicamente tudo que se pode fazer com dados **em batch** (em conjuntos), se pode fazer com dados em fluxo. Quando se trabalha com dados em fluxo é importante notar que há uma ordem e um tempo de chegada que permeia as instâncias.

Definindo em termos formais, um fluxo de dados é uma sequência massiva de objetos potencialmente ilimitado em uma sequência de *timestamps*. Normalmente este dado não pode ser armazenado de maneira indefinida devido a limitações de memória, este dado pode ser descartado depois de processado.

![Aula04_img10.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula04_img10.png)

*database* = base de dados | *datastream* = fluxo de dados

Note que o resultado quando se opera por fluxo de dados é aproximado. Isso se deve ao fato de que os dados não estarão todos disponíveis para se gerar um modelo e também que passado tempo suficiente este modelo pode ter sido influenciado por dados suficientes para se perder muito do que foi construído num momento passado.

Comentando sobre as asserções de que os recursos de memória são infinitos e sobre a natureza distribuída dos programas, cuidado com essas afirmações. Nem sempre se possui memória praticamente infinita para se trabalhar com datasets, nem mesmo se faz trabalho com datasets exclusivamente de maneira focada em apenas um núcleo de processamento, tampouco todas as tarefas sobre datastreams serão invariavelmente paralelas.

As aplicações do aprendizado sobre fluxos de dados são das mais diversas, assim como quando se trabalha sobre bases. O que muda é o cenário de aplicação dada a natureza do problema, assim sendo pode-se fazer uso de Classificação, Agrupamento, Associação, Redução de dimensionalidade...

Vale ressaltar que alguns tipos de dados são mais naturalmente interpretados em fluxo, como dados colhidos por sensores críticos ou mesmo dados de ataques em rede, no caso dos ataques em rede trabalhar com dataset significa trabalhar com o que já aconteceu.

Fluxos de dados tem distribuição não estacionária, ou seja, ela pode mudar conforme se varia o fluxo e esta nuance fará com que algumas técnicas de se operar sobre batch não funcionem. É como se o fluxo mudasse de estado e o modelo deve ser preciso e coerente em relação ao estado atual.

Invariavelmente, devem ser levadas em consideração as seguintes propriedades:
+ Incrementalidade
	+ Deve-se poder incrementar o modelo conforme chegam novos dados.
	+ Podem surgir novas classes ou novos grupos (classificação e agrupamento respectivamente)
	+ Se a padronização usar mínimos e máximos esta janela pode variar com o tempo (uso de distâncias que passam por padronização)
+ Aprendizado em tempo real (online)
	+ Objetos não podem ser indefinidamente armazenados
		+ Durante o tempo que que eles estão disponíveis se analisa o dado e se atualiza o modelo
		+ O uso do modelo não precisa necessariamente ser online
+ Memória limitada
	+ O modelo deve ser atualizado o mais rápido possível
	+ O modelo não pode ser incrementado indefinidamente
		+ Deve haver um mecanismo de descarte
+ Acesso limitado ao "passado"
	+ O modelo reflete apenas parte das características dos dados
+ Capacidade de adaptação (mudança de conceito)
	+ Pode haver um fenômeno chamado **mudança de conceito** (***concept drift***)
		+ Isso não trata apenas de mudanças pontuais
		+ Mudanças mais radicais podem exigir a detecção de novos padrões, novas classes, novos grupos ou mesmo valores nunca antes apresentados para os atributos.

Quanto a leitura, normalmente os dados são lidos um a um, porém pode ser usado um sistema de **micro-batch**, isso faz com que se receba um pequeno conjunto de dados ordenados por vez. Muitas vezes isso ocorre com sistemas distribuídos pois não se pode passar dados por rede continuamente devido a uma série de fatores relacionados a transmissão e recebimento desses dados em cada protocolo de comunicação, é melhor trabalhar com pequenos batches.

![Aula04_img11.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula04_img11.png)

Passa-se os dados para um gerenciador que particiona o fluxo.

Pensando sobre armazenamento (quando há) temos que considerar que ele é limitado, tanto para dados quanto para modelos. Algoritmos diferentes tem distintas técnicas para lhe dar com isso, más o fato é que se precisa de uma estratégia de "esquecimento".

Um exemplo dessas técnicas na literatura é o **sliding window**. Dado um fluxo de dados ou a progressão de um modelo, tem-se uma janela de operabilidade que "deslisa" sobre o fluxo de maneira a abarcar dados novos e descartar antigos. Veja a imagem:

![Aula04_img12.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula04_img12.png)

Existe também o **fading/damped window** que faz uso de uma função para atribuir maior peso a dados mais recentes e menor peso para dados mais antigos. Esta função, em oposição a **sliding window** não é discreta pois o "passo" dado é feito de maneira suavizada.

![Aula04_img13.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula04_img13.png)

Por fim, temos a técnica de **landmark window** que busca encontrar eventos subjetivos que definirão quando se começa a guardar e descartar dados. Este modelo direcionado a eventos só é usado quando o cenário de uso permite ou impõe esta técnica.

![Aula04_img14.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula04_img14.png)

Um elemento muito importante no processamento de dados é a abstração destes dados. Isto é, podemos obter objetos "puros", não processados, ou podemos gerar um modelo para estes dados que os resume em um outro formato.

A imagem a seguir exemplifica o uso deste conceito:

![Aula04_img15.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula04_img15.png)

Um exemplo de abstração é o chamado **feature vector**, o vetor de características. Ele resume um subconjunto dos dados por meio de cálculos como o número dos objetos *N*, a soma linear dos objetos *LS* ou a soma quadrada dos objetos *SS*. Estas informações são capazes de ajudar no cálculo de outras informações sobre os dados.

Usamos as seguintes fórmulas:

![Aula04_img16.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula04_img16.png)

*Estudar o algoritmo BIRCH*.

A geração do modelo vem a seguir, o modelo inicial depende do algoritmo e da tarefa, alguns algoritmos precisam de um conjunto inicial que é geralmente gerado com um batch ou em cima de suas abstrações. Existem modelos completamente incrementais, contudo é necessário ressaltar que os modelos iniciais são obviamente imprecisos dada a baixa quantidade de instâncias triadas.

Como dito anteriormente, o modelo pode ser usado de maneira online ou offline. O primeiro caso é usado quando se precisa de uma resposta para cada entrada recebida, deve-se então levar em consideração o tempo computacional e o tempo entre cada instância. Quando trabalhamos de forma offline não temos este problema.

## Classificação em FCD (Fluxo contínuo de dados)
O modelo inicial gerado sobre um conjunto deve incorporar novas informações na velocidade que os dados chegam, esquecer a informação desatualizada e detectar mudanças para se adaptar à informação mais recente.

Quanto a atualização do modelo, isso pode ser feito com feedback, sem feedback ou com feedback parcial. O feedback em questão é algum mecanismo, seja uma informação de parâmetro ou um usuário.

Trabalhar sem feedback significa usar apenas informações internas do sistema, pensando em grupos é mais fácil notar quando a distribuição dos dados mudou, mas trabalhando com classes é impossível obter esta informação sem feedback. Para classes trabalhamos então com feedback parcial que se trata de assumir um conjunto de características que possam te levar à detecção da classe.

Deve-se ainda definir quando atualizar o modelo, isso pode ter algum custo a ponto de atrapalhar até mesmo a coleta dos dados. Existem várias propostas para se definir quando atualizar o modelo:
+ Propostas supervisionadas
	+ Supõem que o rótulo de todas instâncias está disponível imediatamente após a sua classificação (impossível no contexto atual)
+ Propostas não supervisionadas
	+ Supõem que nenhuma instância rotulada estará disponível para atualização
		+ Assumir o conceito de grupo ou outro conceito preestabelecido para as classes
+ Propostas semi-supervisionadas
	+ Usa instâncias rotuladas e não rotuladas para atualizar o modelo
	+ Também assume uma estrutura de grupos, mas consegue identificar o surgimento de novas classes ou mudança de classes existentes
+ Propostas de aprendizado ativo
	+ Escolhe o melhor conjunto de instâncias a serem rotuladas, essa escolha pode ter vários critérios
		+ Escolha aleatória
		+ Escolha baseada na confiança de classificação
		+ Escolher os mais antigos
		+ Escolher os mais recentes

Alguns dos desafios encontrados para o problema da atualização dos modelos são:
+ O custo da rotulação
+ Atraso na entrega de instâncias rotuladas
+ Limite de instâncias que um especialista pode rotular
+ Rotular apenas parte das instâncias
+ A questão da presença ou ausência de feedback
+ A diferença em importância de cada instância

## Very Fast Decision Tree (VFDT)
Este algoritmo decide expandir cada nó de uma árvore de acordo com o teste de Hoeffding que objetiva substituir uma folha por um nó de decisão buscando a maior pureza possível, evitando divisões excessivas.

Isso só funciona com latencia 0 e quando não há o ***concept drift*** (há um algoritmo CVFDT que trata isso).

## Stream Classification Algorithm Guided by Clustering (SCARGC)
Esta solução trabalha com o conceito de latência infinita e mudança incremental. Ela cria modelos para o batch inicial e "segue" a distribuição dos dados usando o k-means.

O modelo é atualizado quando há grande discordância, porém novas classes não são admitidas.

## Agrupamento em FCDs
É geralmente dividido em duas fases, a primeira fase online abstrai os dados em micro-grupos, esta tarefa vai depender do conceito de grupo (métodos de similaridade, métodos de densidade).

A fase offline extrai os grupos e obtém os resultados.

CluStream (k-means), DenStream (HDBSCAN)...

## Detecção de anomalias
Isso é muito importante quando se trabalha com fluxos de dados, portanto ela é geralmente realizada online.

É dificil detectar quando é de fato um outlier ou uma mudança de conceito, uma solução para isso é fazer o uso de um buffer antes de assumir alguma das situações.

## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!
