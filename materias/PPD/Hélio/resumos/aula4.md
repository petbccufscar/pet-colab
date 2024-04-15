# Resumo Aula 4
> Resumo criado pelo aluno [João Pedro Trevisan](https://www.linkedin.com/in/joao-pedro-trevisan)

#### Professor
![Helio](https://img.shields.io/badge/Helio_Crestana_Guardia-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)


## Paralelização com OpenMP
Ao programar em ambientes de memória compartilhada podemos adotar tanto o modelo MPMD quanto SPMD. Um fator que complica o trabalho em paralelo tanto em sistemas de memória compartilhada quanto em ambientes de memória distribuída é a comunicação entre os processos, é neste ponto que o uso de threads se apresenta como uma vantagem pois usam o mesmo espaço de endereçamento.

Como todos sabemos, programar fazendo o uso de pthreads é um inferno. Deste fato emerge a ideia de gerar APIs que simplificam a aplicação de paralelismo para o programador, daí surge o OpenMP que faz uso de *hints* ("dicas" do programador) para indicar a geração de paralelismo pelo compilador.

O OpenMP (Open Multi-Processing) é uma API que possibilita o desenvolvimento em C, C++ e Fortran. Ele consiste de diretivas de compilação, bibliotecas e variáveis de ambiente que influenciam o  comportamento da execução do programa. 

Quando tratarmos do uso de OpenMP nessa matéria estaremos programando em C. Alguns compiladores oferecem suporte nativo a OpenMP e o nosso conhecido GCC possui este suporte.

```gcc prog.c -o prog -fopenmp``` pode ser usado para compilar um programa que faz uso de OpenMP. A compilação com uso de OMP faz uso de pthreads, portanto  o sistema deve suportar esta biblioteca também.

A imagem a seguir demonstra como o OMP particiona um código fazendo o uso de pthreads:

![aula04_img01.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/PPD/aula04_img01.png)


Por baixo dos panos, o OMP faz uso de pthreads para gerar o paralelismo.

O OpenMP permite:
- Criar times de threads para execução paralela de blocos de código
- Especificar a divisão de um bloco de código entre os membros de um grupo
- Declarar variáveis compartilhadas e privadas
- Sincronizar threads e permitir execução exclusiva por elas
- Executar loops com operações SIMD
- Usar dispositivos como a GPU para processamento vetorial
- Definir paralelismo de forma (exclusivamente) explícita
- Determinar regiões paralelas sem programar explicitamente como elas serão paralelizadas

Uma região paralela é definida em OpenMP fazendo uso de uma anotação da forma ```#pragma omp nome_da_diretiva [clausulas_da_diretiva]```, estas diretivas se aplicam à linha ou bloco de código entre chaves diretamente abaixo delas. Para fazer o uso dessas anotações é preciso incluir o header do OMP com ```#include <omp.h>```.

Uma thread será responsável pela criação de um time de threads para a execução de um bloco de código paralelo indicado por um pragma. Esta thread continuará a execução do programa enquanto as outras threads atacam a região paralela indicada e esta thread que criou o time é chamada de *master thread*.

Se uma thread que está executando uma região paralela e encontra uma *hint* para a criação de uma região paralela ela criará um time de threads e se tornará a *master thread* desse time. 

Regiões paralelas aninhadas são serializadas por padrão e sendo assim serão executadas por um time composto de uma única thread. Isso pode ser mudado com a permissão de criação de regiões paralelas aninhadas, isso pode ser consultado com ```omp_get_nested()```, se permitido estas regiões podem ser ativadas com ```omp_set_nested()``` ou alterando a variável de ambiente **```OMP_NESTED```**. 

Se não forem especificadas quantas threads devem atacar uma região paralela será usado um valor *default* igual ao número de núcleos do sistema. Pode-se consultar quantas threads estão em um dado time com ```omp_get_num_threads()``` e pode-se também consultar quais threads estão executando uma região através de ```omp_get_thread_num()``` que retorna o número lógico delas.

O número de threads pode ser determinado pelo programador mediante a determinação de clausulas nas chamadas pragma como clausulas IF ou num_threads, pelo uso da função ```omp_set_num_threads()``` ou ajuste variável de ambiente **```OMP_NUM_THREADS```**.

Quando trabalhando com threads, toda variável global ou definida dentro da função main que é acessível pelo código da região paralela são compartilhadas por todas as threads de um time. Isto faz com que qualquer modificação nesta variável ocorra sobre a mesma instância dela que é acessível por todas threads. É possível se definir variáveis como privadas de forma que cada thread do time tenha sua cópia e como compartilhadas para que o time todo use uma mesma variável. Variáveis declaradas dentro do bloco paralelo são privadas para cada thread, assim como variáveis dentro de funções usadas pelas threads.

Sobre o acesso à variáveis globais, perceba que se as diferentes threads de uma região paralela vão acessar uma variável apenas para leitura não há ressalva a ser feita, esta é uma operação segura. Contudo, se elas vão escrever nessa variável em algum momento será gerada inconsistência pois não existe meio de determinar qual das threads irá escrever primeiro na variável. Caso isso seja necessário deve ser usado algum método de sincronização antes da escrita ou a variável deve ir para as threads de forma privada.

O OMP, alem de permitir que seja replicada a execução de um trecho de código possui construções que permitem dividir as execuções desses trechos, elas são chamadas de **work-sharing** e se aplicam dentro de uma região paralela definida pela diretiva ```parallel```.

Essas execuções não criam novas threads, elas apenas usam as threads da região paralela atual. Alguns exemplos de contruções para work-sharing são:
- **For**: divide as operações de um loop entre as threads do time para realizar o paralelismo de dados.
- **Sections**: Divide o trabalho em regiões explicitamente definidas e cada uma é executada por uma thread. Representa o paralelismo funcional.
- **Single**: Serializa um trecho de código que é executado é 1 thread do time.

Quando fazendo uso de da diretiva ```pragma omp parallel for``` para paralelizar um loop, as cláusulas possíveis de serem alteradas são:
- **```schedule (type \[,chunk])```**: determina como iterações do loop são divididas entre threads do time
	- Static: iterações divididas em blocos de tamanho *chunk*
	- Dynamic: Iterações divididas em blocos de tamanho *chunk* e alocados dinamicamente entre as threads, à medida que terminam as iterações atribuídas anteriormente.
	- Guided: Número de iterações atribuído em cada rodada é calculado em função das iterações restantes divididas pleo número de threads, sendo o resultado decrescido de *chunk*.
	- Runtime: A decisão de distribuição é decidida até o tempo de execução pela variável OMP_SCHDEDULE. Não se pode definir um tamanho de *chunk* para esta clausula.
	- Auto: Entrega na mão de deus.
- **```ordered```**: Indica que as iterações devem ser executadas em sequência como se fossem tratadas em um programa serial
- **```private (list)```**
- **```firstprivate (list)```**
- **```lastprivate (list)```**
- **```shared (list)```**
- **```reduction (operator: list)```**
- **```collapse (n)```**: Indica quantos loops em um aninhamento de loops (*nested loops*) devem ser agrupados (*collapsed*) em um bloco de iteração maior dividido de acordo com a cláusula schedule.
- **```nowait```**: indica que as threads não devem ser sincronizadas ao fim do loop paralelo.

Para que seja usada a diretiva **for** para paralelizar um loop em OMP é preciso que o compilador seja capaz de verificar que o sistema em tempo de execução terá informações necessárias para determinar o número de iterações para avaliar a cláusula de controle.

Isto significa dizer que deve ser possível saber quantas e quais iterações haverão no loop para poder dividi-las entre as threads do time de maneira correta.

Um **for canônico** tem a seguinte forma geral:
```C
for ( index = start;
      index {<,<=,>=,>} end;
     { indx++, ++indx, indx--, --indx, indx+=inc, index -= inc, indx= indx+inc, indx=inc+indx, indx=indx-inc} )
```

Note que ainda com um for canônico, cada thread do time deve ter sua própria cópia da variável de controle do loop (```index```, neste caso). Contudo a API sinaliza automaticamente ao compilador que esta deve ser uma variável privada.

É possível ainda dividir as iterações de um loop paralelo de maneira explícita. Por padrão, se fizermos uso de N threads cada uma dela terá 1/N das iterações totais a fazer de forma que um programa com 12 iterações a serem feitas em 4 threads tenha 3 iterações em cada uma delas.

O compilador é capaz de tratar os casos nos quais esta divisão não é exata de forma a atribuir as iterações "que sobram" para as threads de menor número lógico. A divisão das iterações é feita como explicado a cima pela cláusula **schedule**.

Usada também dentro de uma região paralela, ```pragma omp sections``` permite especificar seções dessa região que devem ser divididas entre as threads do time. Cada uma delas é executada apenas uma vez por qualquer thread do time e se houver mais que uma seção threads diferentes podem estar executando seções ao mesmo tempo.

Uma barreira é inserida automaticamente ao final das _sections_, exceto se a cláusula _nowait_ for especificada.

Além de permitir a criação de tarefas implícitas associadas às threads de um time numa região paralela, o OMP permite a criação de tarefas sob demanda dinamicamente de maneira circunstancial ou recursiva sem saber a priori quantas tarefas serão necessárias por meio de ```pragma omp task```. 

Ao programar com tarefas um desenvolvedor pode particionar o código em blocos a serem executados em paralelo, de forma a atacar ao mesmo tempo tarefas independentes.

Estas *tasks* devem ser escalonadas pelo sistema em tempo de execução. Além de tudo, vale lembrar que esta chamada não cria um time de threads, mas aproveita um time já existente.

A diretiva *task* tem as cláusulas:
- **```united```**: Indica que a *task* pode ser executada por qualquer thread do time e não só aquela que a criou, como é o padrão.
- **```mergable```**: Indica que podem ser unidos os ambientes de dados das tasks.
- **```final(expr)```**: Indica que se a task criada é a última, serve para definir um nível máximo para a recursão que cria novas tarefas.
- **```depend(dependence-type : list)```**: Indica relações de dependência entre tasks.

Duas diretivas úteis que atacam um problema comum ao se trabalhar com paralelismo são as diretivas ```critical``` e  ```atomic```. Anteriormente foi falado sobre o problema de escrita sobre variáveis compartilhadas por todas as threads como aquelas declaradas de forma global, a primeira diretiva define uma região critica do código que deve ser executada por uma thread de cada vez, o que pode ser usado para resolver este tipo de problema (e não só esse). Já a diretiva ```atomic``` faz com que a região de memória seja lida ou escrita de maneira atômica, isto é, sem interrupção e descartando a possibilidade de outra thread ler ou escrever naquela região de memória durante a operação atômica.

Ainda no tópico de diretivas para tratar acesso a variáveis, pode ser usado ```firstprivate``` para inicializar cada cópia privada de uma variável com o valor atual da variável comum a qual estão associadas na master thread. Para fazer isso em variáveis globais deve se usar a cláusula ```copyin```. Já para tomar o valor da última iteração de um loop podemos usar ```lastprivate```.

As 5 últimas diretivas apresentadas (```critical``` , ```atomic```, ```firstprivate```, ```lastprivate``` e ```copyin```) são muito usadas para sincronização do trabalho das threads. Outras diretivas que auxiliam neste tipo de trabalho são:
- **```master```**: Especifica um bloco de código que só deve ser executado pela *master thread*.
- **```ordered```**: Serializa e ordena o código em uma seção dentro de uma região paralela, esta seção será executada de forma ordenada.
- **```barrier```**: Sinaliza para todas as threads de um time e faz com que elas esperem até que cada uma das threads alcance a barreira..
- **```taskwait```**: Faz com que a task atual espere o fim das tasks filhas.
- **```threadprivate```**: Especifica que variáveis sejam replicadas com cada thread tendo sua própria cópia. Variáveis globais tornam-se locais para as threads ao longo da execução de regiões paralelas.

Por fim, falaremos de operações de redução. A clausula que redução possui um identificador de operação e uma lista com um ou mais nomes de variáveis, para cada uma delas uma cópia privada será gerada para cada thread do time com valor inicial correspondente ao elemento neutro da operação selecionada. Ao final do bloco paralelo as variáveis originais são atualizadas com uma combinação de valores das cópias de todas as threads usando o operador selecionado.

Basta chamar ```reduction(operador : variáveis)```.


## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!