# Resumo Aula 1
> Resumo criado pelo aluno [João Pedro Trevisan](https://www.linkedin.com/in/joao-pedro-trevisan)

#### Professor
![Helio](https://img.shields.io/badge/Helio_Crestana_Guardia-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)


## Sobre Medições de Tempo
Uma vez que a dimensão temporal é algo ao qual sempre se deve prestar atenção quando fazendo uso de programação em paralelo ou em redes de computadores, é muito importante que tenhamos meios de aferir o tempo de execução de um programa.

Primeiramente, é necessário esclarecer 2 conceitos:
- **Tempo de Execução**: Conhecido em inglês como *elapsed time*, *conclusion time*, *running time* ou *turnaround time*, faz referência a diferença entre o tempo de inicio do programa e o momento no qual ele é concluído, assim constituindo um delta. Comandos úteis para saber o instante atual em C são ```gettimeofday()``` ou ```clock_gettime()```.
- **Tempo de CPU**: Conhecido em linguagem de gringo como *CPU time*, constitui a soma do tempo de usuário e do tempo de sistema, pode ser aferido por meio da função ```getrusage()```.

É comum comparar os tempos gastos executando programas sequenciais e paralelos, ou mesmo comprar duas soluções paralelas diferentes. Para isso podemos contrapor os tempos de execução de cada programa.

O tempo de CPU será diferente do tempo de execução pois o scheduler do processador pode optar por alternar os programas em execução de forma a melhor distribuir os recursos da máquina. O SO contabiliza o **user time** como a soma dos tempos consumidos para execução de instruções do programa e o **system time** como a quantia de tempo dedicada a executar instruções e chamadas de sistema invocadas pelo programa.

O código a seguir é um exemplo de como se aferir o tempo de execução de um bloco que se queira testar:
```C
// para uso com gettimeofday(): precisão de microsegundos
struct timeval {
 time_t      tv_sec;  // seconds
 suseconds_t tv_usec; // microseconds
};

struct timeval inic, fim;
struct rusage r1, r2;

// determina quanto foi consumido de recursos até aqui (getrusage)
getrusage(RUSAGE_SELF, &r1);

// determina o instante atual (gettimeofday)
// int gettimeofday(struct timeval *tv, struct timezone *tz);
gettimeofday(&inic, 0);

   // aqui entra o código cujo tempo se quer avaliar

// verifica instante em que a execução do trecho de código foi concluída
gettimeofday(&fim,0);

// determina quanto foi consumido de recursos até aqui (getrusage)
getrusage(RUSAGE_SELF, &r2);

// diferença entre r2 e r1 (ru_utime e ru_stime) indica consumo de recursos para o trecho de código
// diferença entre fim e inic indica o tempo decorrido (elapsed time)

printf("Elapsed time:%f sec\n User time:%f sec\n System time:%f sec\n\n",
      (fim.tv_sec + fim.tv_usec/1.0e6) - (inic.tv_sec + inic.tv_usec/1.0e6),
      (r2.ru_utime.tv_sec + r2.ru_utime.tv_usec/1.0e6) - (r1.ru_utime.tv_sec + r1.ru_utime.tv_usec/1.0e6),
      (r2.ru_stime.tv_sec + r2.ru_stime.tv_usec/1.0e6) - (r1.ru_stime.tv_sec + r1.ru_stime.tv_usec/1.0e6));
```

Outra forma de se medir tempo pode ser a seguinte:

```C
// para uso com clock_gettime(): precisão de nanosegundos
struct timespec {
  time_t  tv_sec;     // seconds
  long    tv_nsec;    // and nanoseconds
}
   
float etime;  
struct timespec inic, fim;

clock_gettime(CLOCK_REALTIME, &tv_start);
  
   // aqui entra o código cujo tempo se quer avaliar  
  
clock_gettime(CLOCK_REALTIME, &tv_end);

// tempo decorrido: elapsed time  
etime = (fim.tv_sec + fim.tv_nsec/1000000000.) - (inic.tv_sec + inic.tv_nsec/1000000000.) ;
// ou
// etime = (fim.tv_sec + fim.tv_nsec/1.0e9) - (inic.tv_sec + inic.tv_nsec/1.0e9) ;
```

Uma maneira de fazer isso em Bash para quando se organiza um job a ser realizado por um cluster por exemplo é através do comando ```time```.

Também é possível medir o tempo através da contagem dos *ticks* do clock do processador, contudo esta abordagem não é consistente devido ao fato de que mecanismos de otimização de desempenho e energia podem fazer com que o clock do processador varie.

De qualquer forma, medições de tempo de execução de programas sofrem de muitos fatores que podem causar imprecisão nas medidas, alguns aspectos a se levar em consideração são:
- **Granularidade das medidas**: ao medir o tempo para a execução de poucas instruções, pode ser relevante medir a execução de múltiplas instâncias do bloco de interesse e, ao final, dividir o tempo total pelo número de operações repetidas.
- Realizar **múltiplas execuções** e atentar para médias, desvios e valores discrepantes (_outliers_).
- Atenção para efeitos de _**cache**_, tanto no acesso a dados de memória quanto para acesso a dados de arquivos.

## Reentrância e Thread Safety
Quando programando com uso de múltiplas threads que compartilham espaço de endereçamento do processo ao qual estão sujeitas é muito importante que nos atentemos a reentrância das funções utilizadas.

Chamamos uma porção de código ou função de **reentrante** quando é possível que múltiplos chamamentos dela possam ocorrer ao mesmo tempo sem gerar resultados problemáticos.

Quando várias threads de um processo existem ou quando o processador interrompe a execução de uma chamada e o novo código a ser rodado realiza uma nova chamada a esta mesma função sem que o fluxo de execução do programa seja concluído geramos problemas de reentrância.

O problema se dá de verdade quando o código faz uso de informações mantidas em variáveis globais que podem ser alteradas por instruções executadas em outro momento ou por outra thread simultânea.

Para garantir o bom funcionamento do programa, dados a serem utilizados dessa forma devem ser protegidos por meio de mecanismos de sincronização, além de que devemos evitar o uso de variáveis globais ou estáticas como boa prática que garante a consistência dos dados manipulados pelo programa.

O  uso de variáveis compartilhadas pode também influir no desempenho do programa a ser rodado, uma vez que os acessos às informações podem acabar sendo serializados, podem gerar bloqueios de tarefas devido aos mecanismos de sincronização ou ainda podem fazer com que o uso da memória cache perca sua eficiência ao mapear uma mesma posição de memória em caches de diferentes núcleos executando tarefas concorrentes.

## O Porquê de PPD
Nosso silício não consegue ficar (muito) menor e devido a tal processadores de mesmo tamanho não conseguem ser grandemente mais velozes que seus antecessores. Em outras palavras, perdemos nosso direito de ser burros e jogar hardware em um problema de software.

Programação paralela é um meio de tronar viáveis novas aplicações e de melhorar o desempenho de aplicações já existentes, isso é possível pois há uma tendencia de que a maioria dos processadores com os quais entraremos em contato sejam multi núcleo e portanto capazes de realizar processamento em paralelo.

## Paralelização na Prática
O processamento paralelo nos chips que conhecemos hoje pode ter várias formas:
- Múltiplas unidades funcionais dentro de um núcleo de processamento, possibilitando a execução simultânea de múltiplas instruções;
- Unidades de processamento vetorial (SIMD) dentro do núcleo do processador, permitindo a execução de uma operação em múltiplos dados ao mesmo tempo;
- Múltiplos núcleos (_cores_) de processamento em um chip (processador);  
- Múltiplos chips numa mesma placa-mãe;  
- Aceleradores multiprocessados e co-processadores em um computador;
- Múltiplos computadores conectados em rede

Existe também uma grande quantidade de estratégias de paralelização como a **decomposição** de programas, a **distribuição** dos programas ou de seus dados em diferentes unidades de processamento ou ainda a **coordenação** de processamentos e comunicações. Estas abordagens devem levar em consideração a arquitetura paralela disponível para uso e as formas de comunicação entre os elementos de processamento.

Existem 3 modelos de programação paralela, a saber:

1. **Memória Compartilhada**:
Este modelo é comumente baseado em threads que compartilham seus espaços de endereçamento de forma a tornar comunicações e sincronizações simples. Este modelo de processamento é geralmente utilizado para aproveitar processadores *multicore* com memória fisicamente compartilhada e se dá pelo uso (na linguagem C) de bibliotecas como *pthreads* e *OpenMP*.

*pthreads* será estudado primeiro neste curso e e disponibiliza para o programador diferentes funções que podem ser executadas simultaneamente e instâncias múltiplas de funções que realizam uma mesma operação sobre porções diferentes da memória.

*OpenMP* por sua vez permite criar programas em C com blocos a serem executados em paralelo através de indicações feitas pelo programador que levarão o compilador a paralelizar tal bloco de código da melhor forma possível tendo em vista os parâmetros recebidos pelo desenvolvedor.

2. **Memória Distribuída/Passagem de Mensagem**:
O modelo de memória distribuída tem como referência o *cluster*, *grid* e a *cloud* onde a característica principal da estrutura é a agregação de vários computadores diferentes que podem realizar tarefas, cada um com sua memória local. Dessa maneira é preciso que haja comunicação entre estes processadores pela rede por meio de mensagens explicitas feitas pelo programador ou por bibliotecas que abstraiam este trabalho.

Uma ferramenta para se trabalhar com este paradigma é a *MPI* (*message-passing interface*) que é uma API amplamente usada em trabalho com clusters, assim como a *PVM* (*parallel virtual machine*). Este modelo de programação pode ser usado em ambientes multi-core, contudo os esforços de passagem de mensagem e sincronização embutidos nestas APIs pode gerar overhead desnecessário neste caso.

3. **Paralelismo de Dados**:
Este último modelo utiliza núcleos de processamento para realizar operações iguais em porções disjuntas dos dados. Esse paradigma faz uso de hardware conhecido como "acelerador" que tem como exemplo as GPUs contidas nas placas de vídeo ou mesmo recursos de processamento vetorial embutidos em processadores comerciais.

Os programas criados tem partes de seu processamento atribuídas para os aceleradores interligados ao sistema e um exemplo de API capaz de realizar este trabalho é a *CUDA* e pode-se fazer uso de aceleradores em ambiente distribuído utilizando-se de *MapReduce* e do ambiente *Spark*.

- **Modelos Híbridos**:
Pode-se fazer o uso dos diferentes paradigmas de programação paralela de forma a utilizar mais que um deles. Pode-se em um ambiente de passagem de mensagem realizar divisão de tarefas em threads e ainda fazer uso de processamento vetorial em GPU, tudo em um mesmo programa.

As tarefas a serem paralelizadas, contudo, devem ser estudadas a fim de levar em consideração como a paralelização será feita e um aspecto a ser observado é o de **granularidade** (ou granulosidade). Este termo faz referência ao volume de operações nas porções do programa a serem rodadas em paralelo.

Pode ser que haja uma **granularidade fina** caracterizada por tarefas relativamente pequenas e com frequentes comunicações, ou uma **granularidade grossa** onde existem tarefas consideradas grandes acontecendo ao mesmo tempo e uma menor frequência na comunicação entre elas.

É importante levar em consideração a razão entre o tempo gasto em computação e comunicação, caso contrário pode-se acabar gastando mais tempo com sincronização do que com computação ou trabalhar muito antes de fazer contato com os outros processos. Deve-se atentar ao balanceamento entre processamento e acesso a memória para leitura e escrita.

Independente do modelo de programação utilizado ou da arquitetura do sistema em questão, existem alguns fatores que facilitam a paralelização do código, eles são:
- Modularidade do Problema: O quão divisível em componentes simples é o problema em questão.
- Concorrência: A presença de blocos independentes que podem rodar em paralelo.
- Escalabilidade: Capacidade de aproveitar ambientes de processamento com mais recursos, tem relação com granularidade e número de blocos paralelos.
- Localidade: Proximidade física dos dados armazenados a serem trabalhados.


## Aspectos Arquiteturais do Processamento Paralelo
As características de organização e intercomunicação das componentes de um sistema computacional influem muito em seu funcionamento. Hoje em dia, os desenvolvimentos tanto em compiladores quanto em sistemas operacionais nos permitem fazer um ótimo aproveitamento dos sistemas a nossa disposição, contudo conhecer as particularidades dos sistemas nos auxilia muito a fazer bom uso deles.

Como inicio para o estudo deste tópico, os computadores possuem diferentes elementos de processamento como processadores de uso geral, processadores gŕaficos/vetoriais, FPGAs e controladores de dispositivos dedicados. Todas estas unidades podem operar em paralelo seja de maneira independente ou coordenada e cabe ao programador organizar a sobreposição do trabalho delas para ganhar desempenho.

Usar diferentes componentes envolve comunicar dados por meio do uso de memórias RAM ou específicas. Estas transmissões são feitas por meio de barramentos (muitas vezes PCI Express) que são comparativamente lentos.

GPUs por exemplo tem sua memória própria (muitas vezes conhecida como VRAM) e portanto precisam receber os dados a serem trabalhados e encaminhar os dados que processaram, criando assim a tarefa de minimizar os acessos a memória para ganhar efetividade.

O uso de dispositivos controladores (como no seu HD) exige a comunicação de estados de operação e isso pode ser feito por interrupções ou consulta voluntária feita pelo SO. Isso também deve ser considerado pelo programador.

O processador em si possui otimizações internas que fazem o uso de paralelismo, algumas que podem estar presentes são:
- Pipeline de instruções.
- Escalonamento e sobreposição de execução de instruções.
- Predição de branch (condicionais) e rollback de instruções.
- Emissão dinâmica de instruções para execução paralela.
- VLIW (very long instruction word), em tempo de compilação instruções que podem ser realizadas juntas são colocadas numa mesma palavra a ser enviada para o processador.

Apesar de muito falarmos sobre as otimizações existentes nos sistemas computacionais modernos, é preciso nos atentarmos ao fato de que a velocidade da computação é determinada não só pela velocidade do processador, mas também pela rapidez com a qual o sistema consegue lhe entregar dados. Além disso, a performance do sistema de memória é determinado pela fração das requisições de memória que podem ser satisfeitos pelo cache (memória de acesso rápido posicionada entre a CPU e a RAM).

O que deriva dessas afirmações é que algumas aplicações podem ser limitadas pela memória (*memory bound*) e outras pela cpu (*cpu bound*). Se os computadores se comunicam pela rede ela também pode ser um forte gargalo de desempenho (e geralmente é).

Atacando o problemas de *memory boundness*, temos o mecanismo de cache que é populado com dados e instruções por meio do hardware do sistema, quando um dado buscado pelo processador está no cache (*cache hit*) este dado é mais prontamente disponível e libera o canal de memória para acesso de outro processador que compartilha dela. O acesso a dados na memória é feito por meio de blocos de cache (*cache lines*) e a eficiência dele depende do reúso dos dados e de sua proximidade física, assim o cache tende a reduzir a latência de acesso a memória.

Agora, sobre as vicissitudes dos processadores, nossos sistemas computacionais são ou multiprocessados ou constituídos de um agregado de processadores, nesses sistemas temos dois tipos:
- Fortemente acoplados (tightly-coupled):
	- Múltiplas CPUs conectadas por barramentos internos.
	- Acesso à memória compartilhada (SMP, *symetric multiprocessing*) ou hierarquia de memória com acesso não uniforme (NUMA, *non-uniform memory access/architecture*).
- Fracamente acoplados (loosely-coupled):
	- *Clusters* compostos de nós (computadores) simples ou multicore interligados.
	- Interconectados por muitas tecnologias e topologias diferentes.

Pensando na possibilidade de se ter várias unidades de processamento, é necessário pensar na distribuição do trabalho entre elas, isto é, na equivalência da soma das cargas das tarefas atribuídas a cada unidade de processamento. 

Em computadores domésticos com apenas um chip de processado os bancos de memória são fisicamente compartilhados entre todos os núcleos com um único espaço de endereçamento físico. Isso é viável devido ao número reduzido de núcleos que possui um processador comum, contudo com mais unidades de processamento é preciso se pensar em novas topologias de interconexão entre processador e memória.

Assim, computadores com mais chips de processador multicore é comum se posicionar bancos de memória mais perto de diferentes núcleos de processamento, criando ambientes de acesso a memória não uniforme.

Outra ferramenta existente no campo das CPUs é o Hyperthreading que permite a execução simultânea de múltiplas threads em um mesmo núcleo, isso se dá por meio da execução de processamento útil quando ele normalmente estaria ocioso em situações como cache miss, branch misprediction ou dependência de dados. O sistema normalmente enxerga cada thread como um núcleo disponível e aloca trabalho de acordo com seu scheduler. O hyperthreading auxilia muito bem o paralelismo e nível de tarefas.


## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!

![POOA_aula01_img03.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/POOA/POOA_aula01_img03.png)