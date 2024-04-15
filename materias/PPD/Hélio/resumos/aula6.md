# Resumo Aula 6
> Resumo criado pelo aluno [João Pedro Trevisan](https://www.linkedin.com/in/joao-pedro-trevisan)

#### Professor
![Helio](https://img.shields.io/badge/Helio_Crestana_Guardia-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)

## Sockets
Desenvolvida inicialmente para sistemas Unix e posteriormente incorporada por todos os SOs com a popularização da internet, a API de sockets é usada para comunicações entre processos executados em computadores distintos.

Um Socket é uma estrutura semelhante a uma caixa postal que permite a comunicação entre processos em diferentes nós interligados em uma rede. Isso não significa dizer que esta rede seja simples e desobstruída, mas esta simplificação já é suficiente.

As aplicações podem pedir para um SO criar um socket tendo como parâmetro o protocolo a ser usado e o tipo de transmissão que será realizada. Aquilo que a aplicação escreve no socket é encaminhado para o destino usando formatações para enquadrar os dados ao protocolo selecionado.

Na internet toda transmissão usa uma versão do protocolo IP (ipv4 ou ipv6), as mensagens por sua vez usualmente usam os protocolos de transporte TCP ou UDP, sendo que com o primeiro é preciso que a aplicação solicite ao SO que "estabeleça uma conexão" com o socket do programa servidor no destino para então enviar pacotes. Quando se faz uso de UDP não se estabelece conexão nem mesmo controle de sequência ou fluxo.

Para o estudo de programação distribuída neste curso serão usadas APIs de bem mais alto nível que a API de sockets, mas esta revisão é importante para a visualização do que está acontecendo. Além disso vale ressaltar que alguns supercomputadores podem ter protocolos próprios de comunicação, este não é o nosso caso pois estudaremos mais adiante o padrão MPI.

Existem tipos diferentes de sockets, entre eles:
- **SOCK_STREAM**: provê transmissões de fluxos de bytes com conexão, são bi-direcionais, tem controle de sequência e são confiáveis. Podem também incluir um mecanismo para transmissão de dados fora do fluxo principal.
- **SOCK_DGRAM**: fornece a transmissão de *datagrams* - mensagens de tamanho máximo limitado, sem conexão e sem garantia de entrega.
- **SOCK_SEQPACKET**: canal de comunicação com conexão para transmissão confiável e bi-direcional de datagramas de tamanho máximo limitado. Neste modelo o consumidor deve ler o pacote de dados inteiro em cada chamada de sistema.
- **SOCK_RAW**: providencia a transmissão diretamente sobre a PDU do protocolo de rede.
- **SOCK_RDM**: entrega uma chamada de datagrama confiável mas que não garante a ordenação dos pacotes.

## SSH
Sistemas Unix podem ser acessados via rede, na forma de uma sessão de login remoto na qual os usuários interagem com o sistema como se estivessem trabalhando sobre uma sessão de shell no computador local, mas as instruções são processadas remotamente.

O SSH (Secure SHell) permite acesso de uma sessão de shell remoto usando encriptação das transmissões e autenticação dos computadores e usuários.

Computadores e servidores são comummente equipados com o SSH por ser uma forma garantida e segura de acessar seus conteúdos, além do que servidores normalmente ficam isolados em locais específicos por uma série de razões, então não se pode depender de acesso físico para programar a máquina.

Ferramentas como MPI e slurm fazem uso de ssh para iniciar a execução de programas remotos usados na programação com passagem de mensagens.

O ssh funciona com base no servidor ssh e no cliente ssh. O servidor, também conhecido como sshd (d significa daemon, programa que roda no background) permite o acesso de clientes de acordo com as configurações em /etc/ssh/sshd_config.

O cliente ssh por sua vez é a porção do programa que acessa um servidor, envia a ele requisições e recebe seus retornos. Ele é autenticado normalmente através de login e senha ou pelo uso de chaves de criptografia configuradas no servidor.

## Comunicação com Passagem de Mensagem
Normalmente programação em sistemas com passagem de mensagem é feita por meio de programação sequencial associada a uma biblioteca de passagem de mensagem. É preciso que o desenvolvedor defina a identificação dos processos criados, quando passar mensagens e identificação de quais informações passar nas mensagens. Os recursos necessários são métodos para criação de processos em máquinas remotas e mecanismos para enviar e receber mensagens.

Numa aplicação distribuída muitos processos são criados e executados em computadores distintos, a criação desses processos pode ocorrer de maneira estática quando os processos são especificados antes da execução ou dinâmica quando os processos podem ser criados dinamicamente e são iniciados durante a execução de outros processos.

Códigos a executar devem ser compilados antes da execução, levando em consideração que nós interligados em rede podem ter arquiteturas ou SOs diferentes e requerem diferentes compilações de programas.

Uma estrutura comum para programas deste tipo é ter um processo mestre (master) e processos trabalhadores (workers, antigamente chamados de slave). Em geral é gerado um único código para aplicação com partes que podem ser executadas pelo mestre e partes tratadas pelos trabalhadores.

O uso de IDs pode ajudar a controlar os processos ou determinar destinos para as mensagens e identificadores únicos permitem diferenciar trabalhadores fazendo tarefas iguais.

No modelo SPMD (Single Program Multiple Data) é comum que os processos sejam criados estaticamente. Aqui, diferentes programas são agrupados em um único arquivo e controles internos permitem selecionar diferentes partes do código para cada processo.

Já no modelo MPMD (Multiple Program...) os processos distintos são usados nos diferentes processadores, um programa é executado no mestre e outro nos nós trabalhadores. Os programas trabalhadores podem ser identificados e ter sua execução personalizada.

Uma vez que os espaços de endereçamento dos processos são diferentes quaisquer comunicações entre eles devem ser tratadas de forma explícita em cada um dos processos envolvidos.

Comumente as bibliotecas para programação distribuída oferecem mecanismos para abstrair detalhes do uso das primitivas básicas de comunicação em rede e também permitem a identificação lógica dos processos.

Um exemplo das primitivas básicas de comunicação são as funções:
```C
send(&msg, id_destino);
recv(&msg, id_origem);
```
O uso de endereço de mensagem para transmissão e recepção permite envio de mensagens de tamanhos diferentes com dados simples ou complexos tratados de maneira adequada tanto no envio quanto no recebimento.

A transmissão pelo meio físico está sujeita a system overhead (tempo de processamento local e remoto das mensagens), sync overhead (atrasos devido a sincronização dos nós participantes na comunicação) e latência.

As bibliotecas de programação distribuída provém comunicações com diferentes características como buffering, comunicação blocante e não blocante, síncrona e assíncrona.

**Broadcast**: Trata do envio de mensagem para todos os processos.

**Multicast**: Envia a mensagem para um grupo de processos.

**Transmissão Síncrona** ou **Rendezvous**: Pode ser feita por meio de **envio síncrono** ou **recebimento síncrono**. Na primeira o emissor espera que o destinatário envie uma solicitação de recebimento, na segunda o processo destino é quem espera. Este tipo de comunicação é um mecanismo de sincronização e não requer buffers para armazenamento intermediário, nele ambos processos podem ser suspensos até que ocorra a sincronização.

![aula06_img01.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/PPD/aula06_img01.png)

**Transmissão bloqueante**: Fazem uso de *buffers* para envio de mensagens e são consideradas concluídas assim que os dados são passados para a área do sistema e o ponteiro na área do processo pode ser reutilizado, independente da mensagem ter sido transmitida.

**Transmissão Não Bloqueante**: Também usa *buffers*, não guarda uma cópia dos dados no envio e retorna imediatamente. É responsabilidade da aplicação garantir que a região de memória usada para o envio não será adulterada antes da leitura.

![aula06_img02.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/PPD/aula06_img02.png)

Da mesma forma que se pode identificar processos de forma lógica, é possível atribuir identificadores à mensagens. É possível também definir o recebimento de mensagens de qualquer origem ou usar tags transmitidas junto das mensagens para selecioná-las.

![aula06_img03.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/PPD/aula06_img03.png)

Já os tipos diferentes de comunicação podem ser:
- **Point to Point**: Comunicações com 1 origem e 1 destino.
- **One to All Broadcast**: 1 transmite, todos recebem.
- **All to All Broadcast**: Isso aí que você pensou.
- **One to All Personalized**: Transmissão contendo dados específicos para cada destinatário.
- **All to All Personalized**: Sim.
- **Collective Communications (computations)**:
	- **Sincronização**: Processos aguardam todos os membros do grupo alcançarem o ponto de sincronização.
	- **Transmissão de dados**: broadcast, scatter, gather, all to all.
		- **Scatter**: Descreve o envio de cada elemento de um vetor para um processo separado
		- ![aula06_img04.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/PPD/aula06_img04.png)
		- **Gather**: Usado para um processo coletar valores individuais de cada processo após alguma operação realizada de maneira distribuída.
		- ![aula06_img05.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/PPD/aula06_img05.png)
		- **Reduce**: Realiza uma comunicação de **gather** e então uma operação sobre os dados recebidos. 
		- ![aula06_img06.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/PPD/aula06_img06.png)
	- **Collective Computations (reduções)**: um membro do grupo coleta dados de todos os outros e realiza alguma operação, assim como vimos em OpenMP.

## Programação com MPI
MPI significa ***Message Passing Interface*** e este nome é bastante auto-explicativo, ainda assim vale ressaltar que trata-se de uma **especificação** de biblioteca padronizada para passagem de mensagens em um padrão portável, eficiente e flexível. Uma vez que MPI é uma especificação e não uma biblioteca, é de bom tom citar aqui que algumas implementações de MPI são o MPICH e o Open-MPI.

Uma das principais vantagens de se trabalhar com um padrão de passagem de mensagem e não uma ferramenta específica é que para ambientes de memória distribuída a definição de uma interface permite que vendedores tenham um conjunto base de rotinas claramente definido que eles podem implementar de maneira eficiente e prover suporte de hardware, abrindo espaço para escalabilidade.

O padrão MPI inclui:
- Comunicação ponto a ponto
- Tipos de dados
- Operações coletivas
- Grupos de processos
- Contextos de comunicação
- Topologias de processos
- Gerenciamento de ambientes
- *The info object*
- Criação e gerenciamento de processos
- Comunicação *one-sided*
- Interfaces externas
- Entrada e saída de arquivos em paralelo
- *Bindings* de linguagem para Fortran e C
- Suporte a ferramentas

Ao compilar um programa em C fazendo uso de MPI podemos usar uma ferramenta de linha de comando como ```mpicc```. A forma com a qual o manual dessa ferramenta a descreve explica muito sobre como ela funciona:

"*Conceitualmente o papel destes comandos é bastante simples: adicionar de maneira transparente flags de compilador e linker na linha de comando do usuário que são necessários para compilar e linkar programas que usam MPI e então invocar o compilador para de fato realizar o comando*.

*De tal forma, estes comandos são frequentemente referidos como wrappers de compiladores pois eles **não compilam ou linkam** as aplicações, eles apenas adicionam as flags para sinalizar ao compilador.*"

A programação em MPI é tipicamente usada em clusters interligados em rede, porém qualquer conjunto de computadores interligados dessa maneira pode ser usado, contanto que satisfaça os seguintes requisitos:
- O usuário deve poder acessar cada um dos nós.
- Deve ser possível que o usuário realize comandos ssh nos nós sem fornecer senha.
- O MPI deve estar instalado no mesmo diretório em todos os nós.
- O programa executável a ser iniciado deve ser acessível no mesmo diretório em todos os nós.

As questões que envolvem caminho de diretórios podem ser simplificadas usando um sistema de arquivos compartilhados como NFS.

A execução de um programa MPI é comumente realizada através do comando ```mpirun```, ele permite indicar quantas instâncias de processos serão utilizados bem como a relação entre os computadores onde estas instâncias serão ativadas.

A atribuição dos processos aos nós na rede pode ocorrer segundo 2 políticas:
- **By slot**: Esta é a politica de *scheduling* padrão, mas ela também pode ser usada de maneira explícita. Neste modo o Open MPI vai realizar o scheduling em um nó até que todos seus slots padrão sejam preenchidos antes de proceder para o próximo nó. Em termos do próprio MPI, isso significa dizer que serão maximizados os ranks adjacentes em MPI_COMM_WORLD de um mesmo host sem sobrecarregá-lo.
- **By node**: Esta politica deve ser determinada de maneira explícita e faz com que o Open MPI faça o scheduling de um processo por nó de maneira *round-robin* (igual uma das políticas do scheduler do processador), isto é, navegando uma lista ordenada de nós e voltando ao primeiro depois do fim da lista. Nós serão pulados quando seu máximo número de slots for exaurido.
- **Em ambas politicas** o Open MPI pulará nós com sua quantidade máxima de slots preenchida e buscará nós com algum slot aberto até que todos processos estejam alocados. Se todos os nós estiverem cheios e ainda há processos a serem alocados o Open MPI irá abortar a execução.

Ainda que MPI seja focado em gerar programas para ambiente de memória distribuída ele ainda fornece suporte a paralelismo de dados em arquiteturas distribuídas. 

Vale destacar que um programa em MPI consiste de processos autônomos executando seu próprio código, um modelo MIMD. Os códigos rodados não precisam ser idênticos e os processos se comunicam através do uso de primitivas de comunicação MPI e tipicamente cada processo executa em seu próprio espaço de endereçamento ainda que se possa usar memória compartilhada.

Dito isso, o número de tarefas dedicadas ao processamento paralelo é geralmente estático e definido a priori, elas podem ser criadas de maneira dinâmica, mas a sua forma de criação e ativação não são especificadas pelo padrão MPI, assim como o mapeamento de processos em processadores.

Quando se vai trabalhar de fato com MPI algumas das funções de gerenciamento são:
- **```MPI_Init(&argc, &argv)```**: Inicia o ambiente de execução MPI e deve ser a primeira função a ser chamada, além de só ser chamada uma vez.
- **```MPI_Init_thread(int *argc, char ***argv, int required, int *provided)```**: Inicia o ambiente MPI e ativa o suporte à operação com múltiplas threads.
- **```MPI_Initialized(&flag)```**: Indica se ```MPI_Init``` já foi executada.
- **```MPI_Comm_size(comm, &size)```**: Determina o número de processos em um comunicador, quando usado com ```MPI_COMM_WORLD``` indicará o número de processos em uso pela aplicação.
- **```MPI_Comm_rank(comm, &rank)```**: Determina o índice lógico do processo dentro do comunicador. Os processos tem valores de 0 à p-1 e podem ter um rank diferente para cada comunicador que participarem.
- **```MPI_Abort(comm,errorcode)```**: Termina os processos associados a um dado comunicador, em geral termina todos os processos.
- **```MPI_Get_processor_name(&name, &resultlength):```** Retorna o nome do processador e o tamanho do nome.
- **```MPI_Wtime()```**: Retorna o *wall clock* em segundos.
- **```MPI_Get_version(&version, &subversion)```**: Retorna número da versão do padrão implementada pela biblioteca em uso.
- **```MPI_Finalize()```**: Encerra o ambiente de execução MPI e deve ser a última instrução MPI a ser executada.

Os **comunicadores** citados nas funções a cima são identificadores de grupos que são considerados nas primitivas de transmissão. MPI_COMM_WORLD é um grupo pré-definido que inclui todos os processos de uma aplicação.

As comunicações em MPI por sua vez podem se dar de maneira ponto a ponto ou em grupo. Obviamente, as primitivas de comunicação ponto a ponto se dão entre duas tarefas apenas.

Neste tipo de comunicação, emissor e receptor são identificados em função de seus números lógicos (*ranks*) dentro de um grupo de processo (*communicator*) da aplicação.

Ao fazermos o uso de comunicações ponto a ponto podemos escolher alguns modos de comunicação no envio:
- **Standard**: Não assume que uma primitiva de recebimento correspondente já foi iniciada. Se forem providos buffers o envio pode ser concluído antes do recebimento.
- **Buffered**: ```MPI_Buffer_attach()``` e ```MPI_Buffer_detach()``` tratam da definição de espaços de buffer.
- **Synchronous**: Permite usar ```send()``` e ```recv()``` em momentos distintos, mas só ocorrem após a sincronização.
- **Ready**: O envio pode ser iniciado apenas quando o recebimento já foi solicitado.

As operações de transmissão ponto a ponto são:
- ```MPI_Send(buffer,count,type,dest,tag,comm)```: envio bloqueante
- ```MPI_Isend(buffer,count,type,dest,tag,comm,request)```: envio não-bloqueante
- ```MPI_Recv(buffer,count,type,source,tag,comm,status)```: recebimento bloqueante
- ```MPI_Irecv(buffer,count,type,source,tag,comm,request)```: recebimento não bloqueante.

Os parâmetros dessas funções correspondem a:
- **Buffer**: endereço de memória da localização dos dados; geralmente é o endereço de uma variável.
- **Data Count**: número de elementos de dados do tipo especificado a serem enviados.
- **Data Type**: tipos pré-definidos ou definidos pelo usuário.
- **Destination**: indica o rank do processo a quem se destina a msg.
- **Source**: especifica o rank do processo emissor. MPI_ANY_SOURCE permite receber de qualquer tarefa.
- **Tag**: identificador atribuído (0..32767) pelo programador para identificar uma mensagem. Permite especificar a mensagem a receber. MPI_ANY_TAG permite receber qualquer mensagem.
- **Communicator**: indica o conjunto de processos a quem se destina a mensagem. Normalmente usa-se MPI_COMM_WORLD.
- **Status**: em C, é um ponteiro para uma estrutura MPI_Status. Ex. stat.MPI_SOURCE, stat.MPI_TAG, MPI_Get_count routine (núm. Bytes recebidos)
- **Request**: usado em operações não-bloqueantes, retorna um "request number", que pode ser usado posteriormente (em operações do tipo WAIT) para determinar o estado da operação.

Tanto para grupos quanto para comunicação entre pares, primitivas permitem esperar pela chegada de dados ou verificar se mensagens específicas já foram recebidas e mecanismos de bufferização permitem tratar o envio e recebimento quando emissor e receptor não estão sincronizados.

A decisão de como tratar esta área de buffer não é padronizada entre as diferentes implementações de MPI, ela pode ser parte da memória do emissor ou do receptor. Ainda assim, o MPI garante a transmissão da mensagem sem gerar erros ou time-outs. 

Dois conceitos importantes em MPI são **ordenação** e **justiça**. Quanto a ordem, a aplicação de MPI garante que as mensagens não ultrapassem umas as outras, assim se duas mensagens são enviadas em ordem e são "pegas" por uma mesma chamada de recebimento será passada primeiro a mensagem 1 e depois a segunda. A mesma ordem segue se duas chamadas de recebimento forem usadas. A única coisa que sobrepõe as regras de ordem é o processamento paralelo em threads.

Quando a justiça, ela não existe em MPI, isto é, se **processos diferentes** enviam mensagens "pegas" por uma mesma chamada de recebimento apenas um processo emissor terá sua mensagem entregue. Cabe ao programador garantir que os processos não morram de inanição (*operation starvation*) por não poderem proceder sem a comunicação que tentaram realizar.

Quando se vai comunicar com um processo, os dados são empacotados em alguns tipos de dados definidos pela especificação MPI:
- MPI_CHAR: signed char
- MPI_SHORT: signed short int
- MPI_INT: signed int
- MPI_LONG: signed long int
- MPI_UNSIGNED_CHAR: unsigned char
- MPI_UNSIGNED_SHORT: unsigned short int
- MPI_UNSIGNED: unsigned int
- MPI_UNSIGNED_LONG: unsigned long int
- MPI_FLOAT: float
- MPI_DOUBLE: double
- MPI_LONG_DOUBLE: long double
- MPI_BYTE: 8 binary digits
- MPI_PACKED: data packed or unpacked with MPI_Pack()/ MPI_Unpack

O material no AVA entra em bastante detalhe sobre transmissões bloqueantes, não-bloqueantes, bufferizadas, sobre espera por comunicação e comunicação coletiva. "Resumir" esta parte seria copiar as descrições das funções e isso tornaria esse resumo ainda mais gigante.

Encaminhando o fim de nossos estudos, é preciso falar sobre o gerenciamento de grupos. Os grupos definem uma coleção ordenada de processos, cada um com um rank (índice lógico), e o grupo também define os nomes de baixo nível para comunicação entre processos. Eles definem um escopo de nomes de processo em comunicação ponto a ponto, além disso definem o escopo de operações coletivas. Eles podem ser manipulados de maneira separada dos comunicadores, mas apenas os comunicadores podem ser usados para comunicar.

Cada comunicador contém um grupo de participantes válidos, este grupo sempre inclui o processo local e o emissor e  transmissor da mensagem são identificados por rank de processo dentro deste grupo.

Em MPI não existe meio de criar grupos do zero, apenas partindo de outros grupos isso é possível.

Sobre os comunicadores, eles são divididos em dois tipos e o primeiro deles é o de **intra**-comunicadores para operações que contém apenas um grupo de processos. O segundo são os **inter**-comunicadores para operações entre dois grupos de processos.

Os **intra**-comunicadores são mais comuns e eles contém contextos de comunicação capazes de separar "universos" seguros para passagem de mensagem . Eles são como uma tag adicional que diferencia mensagens.

Como seria de se esperar, a manipulação de arquivos por aplicações paralelas distribuídas pode beneficiar-se de funcionalidades que considerem a distribuição. Nesse sentido, o padrão MPI procura oferecer operações para acesso segmentado aos dados de arquivos. Cabe à aplicação, contudo, determinar como o mapeamento de dados pode ser explorado para melhor eficiência, por exemplo, considerando aspectos de localidade.

Estas otimizações só podem ser realizadas se o sistema de arquivos paralelo provê uma interface de alto nível que suporta o particionamento de dados de um arquivo entre vários processos e uma interface coletiva entre os processos que possibilite transferências completas de estruturas de dados globais entre memórias e arquivos de processos. Mais eficiência pode ser ganha se o sistema suportar entrada e saída assíncrona, acesso *strided* (em largos passos) e controle sobre leiaute físico de dados em dispositivos de armazenamento.

Por fim, além da especificação estudada até aqui (que em segredo se chama MPI-**_1_**) existe também o **MPI-2**. A primeira especificação intencionalmente não ataca uma série de problemas considerados muito complexos que foram em 1998 delegados para a segunda especificação que além de algumas revisões contém:
- Extensões que removem o modelo de processos estáticos de MPI-1.
- Rotinas para comunicação unidirecional, operações de memória compartilhada e operações remotas cumulativas.
- Operações coletivas estendidas sobre inter-comunicadores.
- Interfaces externas que dão ao desenvolvedor uma camada sobre o MPI como debugadores e perfiladores
- Suporte estendido a I/O paralelos.

Existe também o **_MPI-3_** que constrói sobre o MPI-2 no que tange operações coletivas não blocantes, comunicações unidirecionais, coletivos de vizinhos, suporte a Fortran 2008, Interface com ferramentas e probbing em ambientes de múltiplas threads.

Como não cansam de fazer versões do MPI você estaria certo em supor que fizeram o **_MPI-fucking-4_**. Este busca adicionar novas técnicas e conceitos ao padrão MPI que ajudam a atacar problemas atuais e das gerações futuras na criação de aplicações e arquiteturas. Ele busca suportar melhor modelos de programação híbrida, *fault tolerance*, coletivos persistentes, insights sobre performance e comunicações unidirecionais.

Existe um esforço para se prepara uma **quinta** especificação, mas até mesmo o fórum do MPI não tem muita informação sobre este assunto.

## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!