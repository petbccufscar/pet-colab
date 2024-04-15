# Resumo Aula 2
> Resumo criado pelo aluno [João Pedro Trevisan](https://www.linkedin.com/in/joao-pedro-trevisan)

#### Professor
![Helio](https://img.shields.io/badge/Helio_Crestana_Guardia-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)


## Projeto de Programas Paralelos
É comum a paralelização começar a partir de um código procedural já existente buscando trechos que podem ser paralelizados, Além disso, os mecanismos que serão usados para rodar o código em paralelo não são levados em consideração ao se dividir os blocos e as tarefas neles. Pode ser que o programador pense em diferentes formas de mapear as atividades sobre diferentes plataformas e arquiteturas.

Existem ferramentas como compiladores paralelizantes que podem ser usados para automaticamente tornar um código capaz de fazer o uso de múltiplas unidades de processamento ou ainda gerar avisos ao desenvolvedor sobre possibilidades de paralelização, bem como sobre fatores inibidores de paralelismo. Vale lembrar que os loops são os principais candidatos ao paralelismo.

A paralelização automática é uma frente complexa na computação e seus resultados não são sempre os melhores dado a uma série de fatores, como exemplo, a paralelização pode ser pouco flexível, limitada, incorreta devido a má predição de conflitos, subótima gerando poucos ganhos ou ainda ser limitada trechos específicos de código (como os loops que são o caso mais fácil).

Atacando este problema, abordagens como *OpenMP* realizam a paralelização semi-automatizada, isto é, o programador sinaliza os trechos a serem paralelizados e o compilador se encarrega do como.

De maneira geral, a criação de programas paralelos envolve decompor as atividades e atribuir os blocos de processamento aos diferentes núcleos. 

É importante que se entenda o problema em questão pois existem processamentos, como o cálculo da sequencia de Fibonacci, em que o passo atual depende do passo anterior. Não só isso, é preciso entender em quais trechos de código ocorre a maior quantidade de trabalho para compreender como atacar as partes mais importantes de um problema no qual se busca ganhar desempenho.

Para testar sua solução paralela (ver se ela melhora em alguma coisa a execução do programa) faz bem usar programas perfiladores e ferramentas de análise de desempenho.

Por fim, vale a pena atentar-se nos gargalos e nos fatores inibidores de paralelismo. Os gargalos são áreas de execução mais lenta ou que parem/retardem o processamento de blocos paralelos a exemplo de operações de entrada e saída. Fatores capazes de inibir o paralelismo como a dependência de dados devem ser atentados e para atacá-los muitas vezes pode-se procurar algoritmos específicos.

A decomposição é a divisão do código em partes menores de forma que algumas (ou todas) possam ser realizadas em paralelo e pode ser feita por meio de duas abordagens principais:
- Decomposição de domínio: 
	- Dados associados a cada tarefa são particionados e mapeados junto delas.
	- Cada tarefa executa as mesmas instruções sobre dados distintos.
	- Considera-se a localidade dos acessos.
- Decomposição funcional:
	- As atividades em si são divididas em blocos funcionais, não os dados.
	- As diferentes tarefas fazem diferentes manipulações sobre dados distintos ou os mesmos dados.

Abordando mais especificamente a decomposição de domínio, ela é a abordagem mais popular e o resultado de seu particionamento é um conjunto de tarefas que contém parte dos dados e um conjunto de operações a serem realizadas sobre eles. Ainda assim pode ser que diferentes operações acessem dados de diferentes tarefas, desta forma exigindo a necessidade de mecanismos de comunicação.

Diferentes formas de particionar podem ser possíveis ao levar em consideração diferentes estruturas de dados e as abordagens principais envolvem cocar na maior estrutura de dados ou na que é mais acessada.

As imagens a seguir ilustram algumas formas de decomposição por domínio:

![aula02_img01.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/PPD/aula02_img01.png)

![aula02_img02.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/PPD/aula02_img02.png)

Para estes casos facilita pensar em operações realizadas sobre vetores e matrizes.

Sobre a decomposição funcional, ela é bem mais simples conceitualmente. Ela foca nas computações a serem feitas e não nos dados, então as divide em tarefas disjuntas. É indicado buscar independência entre as tarefas de forma a sobrepor suas execuções. Quando houver sobreposição de dados pode-se usar mecanismos de sincronização ou replicar parte deles, contudo se essa sobreposição for muito grande talvez valha a pena trabalhar com decomposição por domínio.

A imagem a seguir ilustra bem o pensamento por trás deste tipo de decomposição:

![aula02_img03.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/PPD/aula02_img03.png)

No que trata da comunicação entre os blocos paralelos, os programas que não requerem nenhum tipo de comunicação são chamados de "embaraçosamente paralelos". Contudo, quando a comunicação é exigida devemos considerar:
- Sobrecarga de Comunicação:
	- Gasto de tempo com comunicação
	- Mecanismos de sincronização de envio e recebimento com possíveis tempos ociosos esperando conclusão de comunicação.
- Latência/Largura de Banda:
	- Latência é dada pelo tempo de se enviar um pacote mínimo entre os pontos A e B.
	- Largura de banda indica a quantidade de dados transmitidos num período de tempo (Bytes/seg).

Quando pensamos em comunicação devemos levar em consideração que a comunicação síncrona (bloqueante) tanto emissor quanto receptor devem estar em pontos específicos do código para que a transmissão ocorra e isso pode fazer com que certas tarefas fiquem tarefas à espera da conclusão de outras.

Na comunicação assíncrona (não bloqueante) as transmissões podem ocorrer de maneira independente, muitas vezes por uso explícito ou implícito de buffer.

A forma das comunicações também varia e pode se dar de maneira ponto-a-ponto ou coletiva, sendo que na primeira é necessário que haja um transmissor e um receptor, enquanto na segunda existem várias formas de se organizar sem um regra geral.

Alguns exemplos comuns de mecanismos de sincronização são as barreiras que são bloqueantes e vão parar todas as tarefas até que cheguem em um determinado ponto; os semáforos/mutexes que são normalmente usados para serializar recursos; e mecanismos de envio e recebimento bloqueantes que podem sincronizar as tarefas emissora e receptora.

A dependência de dados ocorre quando a ordem das operações influi no produto do processamento. Para atacar este problema temos abordagens diferentes dependendo da arquitetura do sistema:

Em sistemas de memória distribuída deve-se propagar os dados em pontos de sincronização apropriados. Em sistemas de memória compartilhada é preciso sincronizar as operações de leitura e escrita de variáveis ou estruturas compartilhadas entre tarefas.

Outra faceta ainda não explorada por aqui do projeto de programas paralelos é o balanceamento de carga que consiste na alocação de porções equivalentes de trabalho entre as tarefas na busca de melhor aproveitamento das unidades de processamento. Atitudes que miram otimizar o balanceamento de carga são o esforço para reduzir o tempo ocioso dos núcleos e particionamento igual ou semelhante das quantidades de trabalho a serem executadas.

Podem-se usar mecanismo de atribuição dinâmica de carga ou mesmo escalonadores para gerar menor desbalanceamento entre o trabalho dos núcleos.

A granularidade das tarefas tem grande impacto no balanceamento de carga visto que a definição de granularidade é "taxa de processamento em relação às comunicações".

Um elemento dos programas computacionais que tende a inibir o paralelismo são as operações de entrada e saída que, via de regra, são ordens de magnitude mais demoradas que os tempos de manipulação de dados em memória e dependem da disponibilidade do servidor de arquivos. Existem sistemas de arquivos paralelos, contudo estas são soluções específicas para aplicações específicas, isso não é de uso doméstico.

Em sistemas de memória compartilhada, threads de um mesmo processo compartilham seu vetor de arquivos abertos o que faz o acesso de múltiplas threads à um mesmo arquivo exigir atenção especial. Somando a esta questão, cada operação solicitada por cada thread passará pelo sistema do SO para acesso ao disco, isso significa que elas serão realizadas no final das contas possivelmente acarretando na perda da eficiência do uso de cache. Para remediar isto, é comum que apenas uma thread fazendo leitura.

## Estratégias de Paralelização
Via de regra, o estudo de PPD (assim como de muitas outra áreas) perpassa o estudo de problemas característicos desta área, a exemplo:
- Dense and Sparse Linear Algebra
- Particle Methods
- Structured Grids
- Unstructured Grids
- Monte Carlo
- Spectral Methods
- Grafos
- Hashing
- Sorting
Vale lembrar que não vamos estudar todas essas coisas, então se você não pesquisar por estes nomes eles não significam nada.

Depois de estudar diferentes códigos para estes diferentes problemas (KKKKKKKKK), você perceberá que eles caem dentro de 4 tipos de estratégias de paralelização:
- Decomposição Recursiva
- Decomposição de Dados
- Decomposição Exploratória
- Decomposição Especulativa

Wilkson e Allen em seu trabalho sobre computação paralela criaram uma categorização de programas paralelos das quais entraremos mais profundamente em 3: Computações Embaraçosamente Paralelas, Particionamento e Divisão e Conquista.

Na primeira delas, atacamos problemas que possuem muitas partes independentes, o que garante que elas podem ser executadas em simultâneo sem risco de problemas. Neste tipo de problemas as principais estruturas necessárias são as que tem o papel de distribuir os dados e iniciar as tarefas e em geral elas seguem o modelo SPMD (single-program multiple-data), o que por sua vez as torna ótimas candidatas para processamento vetorial em GPU.

A falta de interdependência entre os dados é um fator que favorece tanto o uso de ambientes de memória distribuída quanto de passagem de mensagem. Vale nos atentarmos, porém, no fato de que mesmo que a quantidade de trabalho entre as tarefas seja igual uma atribuição de cargas estática (não dinâmica) pode não produzir o melhor resultado.

Por fim, este tipo de tarefa se adéqua bem a abordagem Master-Worker (antigamente chamada de Master-Slave) na qual um objeto mestre possui ou pode criar uma série de trabalhadores a medida que hajam tarefas em aberto.

A abordagem de Particionamento por sua vez pode ser baseada nas decomposições de domínio ou funcionais apresentadas anteriormente e constitui a estratégia básica da programação paralela.

Podemos pensar como exemplo simples dessa abordagem a soma paralela dos elementos de um vetor, problema na qual fatalmente se terá que tomar os resultados produzidos por cada unidade de processamento e juntar eles de forma a conseguir as somas parciais e depois a soma completa. Note que podemos ter tantas tarefas quanto temos processadores e a cada passo diminuiremos a quantidade de processadores em uso.

Neste exemplo, em ambientes de memória compartilhada bastaria dizer para cada core onde começa e termina sua porção do vetor, em ambientes de passagem de mensagem cada porção deveria ser enviada para seu respectivo core, variando entre o modelo de mensagens específicas para cada nó ou de *broadcast* no qual todos recebem todos os dados e apenas trabalham a sua parte.

Finalmente chegamos a abordagem de paralelização por divisão e conquista e todos vocês devem lembrar das aulas de *QuickSort* e *MergeSort*. A divisão e conquista pressupõe o particionamento dinâmico das tarefas na forma de problemas menores com a mesma estrutura do problema maior e portanto a recursão é uma ideia natural aqui.

Pensando em tarefas que podem ser quebradas em duas tarefas menores subsequentemente, formaremos uma árvore binária a ser dividida até que tenhamos elementos atômicos, a partir de então "subimos a árvore" até sua raiz resolvendo os problemas, somando seus resultados e fazendo uso da maior quantidade de núcleos possível.

## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!