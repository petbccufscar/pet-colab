# Resumo Aula 3
> Resumo criado pelo aluno [João Pedro Trevisan](https://www.linkedin.com/in/joao-pedro-trevisan)

#### Professor
![Helio](https://img.shields.io/badge/Helio_Crestana_Guardia-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)


## Programação com Memória Compartilhada
Quando programamos em ambientes de memória compartilhada é possível criar tarefas de dois tipos: Processos ou Threads. Para cada caso teremos uma série de especifidades no que tange a ativação das tarefas, sua comunicação e sincronização.

Ainda assim, elementos comuns a serem considerados em ambas abordagens são:
- O uso dos modelos SPMD ou MPMD.
- A atribuição dos dados.
- Os mecanismos que possibilitam o uso de cada abordagem.

Abordaremos primeiro o uso de processos, neste modelo assumiremos o uso de sistemas compatíveis com as APIs POSIX nas quais a criação de um novo processo se dá por meio de uma chamada ```fork()```. Quando usada, esta função cria um novo processo que é cópia do processo atual e após esta criação ambos processos partirão para rodar a linha imediatamente após a chamada. Uma vez que esta função retorna 0 para o processo filho e o PID do processo filho para o pai, é praxe que a linha após a chamada tenha relação com o tratamento deste retorno.

Quando usamos processos é importante ter em mente que o sistema manterá áreas de memória separadas para cada um deles e assim sendo é necessário usar recursos do SO para intercomunicá-los. Alguns destes mecanismos são:
- Arquivos
- Pipes
- Sockets
- Filas de mensagem
- Semáforos

Caso se veja a necessidade, pode-se mapear uma área comum da memória para uso entre alguns processos, isso deve ser feito de maneira explícita. Podem ser definidas estruturas na memória global para que cada processo receba uma cópia dessa estrutura, isso porém só permite que os processos leiam as cópias, mas não que escrevam naquele espaço, a alternativa para isso é o uso de threads que compartilham espaço de endereçamento.

As APIs sysv (shmget, shmat) e a API POSIX (mmap) permitem a criação de áreas de memória que todos processos tem acesso, porém não é tarefa do SO orquestrar os acessos a esta memória e o programador deve sincronizar os acesso para que não haja problemas nos dados devido a acessos simultâneos ou fora de ordem.

Considerando a decomposição de dados, talvez o modelo de programação com processos mais comum seja ter a iniciação de vários processos a partir da função _main_, usando os **identificadores** desses processos para indicar quais partes do código cada um irá executar, ou quais partes dos dados serão manipuladas por cada um deles. Via de regra, é mais difícil decompor um programa de maneira funcional pelo uso de processos.

Um modelo de código comum neste paradigma é a criação de uma função main que apenas cria processos de forma estática ou dinâmica para lhe dar com a mudança de estados que se quer atacar no problema.

Quando fazemos o uso das threads, por sua vez, criamos novas linhas de execução dentro de um mesmo processo. Aqui vale a pena pensar em uma analogia com uma fábrica fordista com esteiras de montagem paralelas, cada conjunto de esteiras paralelas tem trabalhadores que realizam a mesma tarefa.

As threads, uma vez que estão associadas a um mesmo processo, compartilham espaço de memória global que incluem o BSS (block starting symbol, onde ficam variáveis alocadas estaticamente que foram declaradas mas ainda não receberam valores), o *heap* e todas outras áreas mapeadas na memória do processo. A área da pilha de chamadas (call stack) é individual para cada thread (obviamente).

A comunicação entre as threads é comummente realizada por meio das variáveis globais as quais todas elas tem acesso. Isso contudo pode gerar problemas de sincronização e deve ser feito de forma inteligente.

Um problema que surge quando trabalhamos com processos e threads é o problema de *false sharing* que será caracterizado a seguir.

Em sistemas computacionais multicore cada núcleo do processador tem acesso a uma memória local chamada *cache* que o faz ganhar muita velocidade no acesso aos dados. O sistema de memória deve garantir que estes caches tenham consistência em relação a memória principal do sistema.

Isso faz com que quando um mesmo conteúdo da memória está me linhas de cache diferentes do processado a alteração de uma dessas linhas faça com que o sistema de memória invalide as outras linhas e force acessos à memória principal para atualizar co conteúdo de todas elas. Isso faz perder muito desempenho.

Uma linha de cache normalmente tem 64 bytes, digamos que temos um vetor de *floats*. Uma vez que cada float tem 4 bytes (32 bits de precisão) devemos dividir nosso vetor em threads que acessem até 16 posições contíguas do vetor ou múltiplos desse valor para que em linhas distintas de cache não tomemos posições de memória que possam invalidar este cache (com valores menores ou não múltiplos as posições de memória vão ao cache ainda que não sejam operadas).

## Gerenciamento de Processos
Quando usamos uma chamada do tipo ```fork()``` sabemos que cria-se um processo que é uma cópia do original, contudo vale lembrar que não é apenas isso que acontece. É necessário que se tenha uma descrição do projeto criado e em Linux isso se chama *task-struct* e se parece com isso:

```
$ pahole -C task_struct vmlinux

struct task_struct {
    struct thread_info thread_info;                  /*     0     8 */
    volatile long int          state;                /*     8     4 */
    void *                     stack;                /*    12     4 */

    ...

    /* --- cacheline 45 boundary (2880 bytes) --- */
    struct thread_struct thread __attribute__((__aligned__(64))); /*  2880  4288 */

    /* size: 7168, cachelines: 112, members: 155 */
    /* sum members: 7148, holes: 2, sum holes: 12 */
    /* sum bitfield members: 7 bits, bit holes: 2, sum bit holes: 57 bits */
    /* paddings: 1, sum paddings: 2 */
    /* forced alignments: 6, forced holes: 2, sum forced holes: 12 */
} __attribute__((__aligned__(64)));
```

Além disso é preciso poder identificar o processo por meio de um PID (process ID), um ppid (parent process id), pgid (process group id), uid (user id) e um gid (group id).

Um processo herda todas as permissões do processo pai, mas se pode fazer ele herdar as permissões de um usuário ou grupo. As páginas de memória do processo pai também são herdadas, mas o mecanismo conhecido como *copy-on-write* só de fato as copia fisicamente se o processo operar sobre elas, caso contrário há apenas uma referência para elas, isso permite que o processo não gaste tempo copiando memória caso vá usar uma parte completamente distinta dos dados ou se for encerrar rapidamente sem usá-las.

Caso se queira que um novo processo realize um código completamente novo basta usar a chamada ```exec()``` que fará com que ele execute um arquivo passado como parâmetro.

Quando se trabalha com threads são mantidas filas ou árvores de threads prontas para execução para cada núcleo e o SO deve evitar o desbalanceamento de carga reorganizando as filas quando for necessário que elas se equilibrem. É possível tratar isso de forma explícita alterando a afinidade de processos e threads às CPUs.

## Comunicação Entre Processos
Ao trabalhar com processos que atuam em regiões de memória disjuntas enfrentamos o problema de comunicar um processo com outro. Quando trabalhamos com sistemas de memória distribuída apenas podemos nos comunicar pela rede, contudo processos em ambiente de memória compartilhada tem mais oportunidades de comunicação.

Uma solução simples é o uso do sistema de arquivos uma vez que normalmente se usa a mesma árvore de diretórios entre diferentes processos gerados por um programa (a não ser que se escolha outra explicitamente). Neste tipo de comunicação os processos escrevem e leem em um mesmo arquivo e assim podem trocar sinais e dados, contudo este tipo de comunicação é muito lento por exigir os passos:

- Leitura
	1. cópia de dados da área de memória do processo (espaço de usuário) para área de memória do SO (kernel space).
	2. Cópia dos dados da área do SO para o sistema de arquivos (lento).
- Escrita
	1. Cópia dos dados do disco para buffers na memória do SO (lento).
	2. Cópia da área de memória do SO para a área do processo.

Postos estes poréns da comunicação inter-processos por meio de arquivos, faz mais sentido pensarmos em usar mecanismos que façam uso apenas das memórias dos processos e do SO. Alguns exemplos são **pipes**, **fifos**, **filas de mensagens**, **semárforos**, **sockets** ou **arquivos mapeados em memória**.

Caso as transferências *user space->kernel space* e *kernel space->user space* em comunicações ainda soem muito lentas para sua aplicação, o SO possibilita o compartilhamento de áreas de dados entre processos e para isso usamos algumas chamadas de sistema. É possível que se associe um ponteiro a uma área de memória de forma que ela seja compartilhada pelos processos, esta variável deve apontar o inicio de uma página lógica não mapeada pela tabela de páginas fazendo o SO ajustar a tabela de páginas de memória de forma que a página indicada aponte para uma página física compartilhada.

Esta abordagem tem um efeito semelhante ao uso de memória global ao se operar com threads, assim sendo, deve-se criar uma lógica de aplicação que não gere inconsistências ao operar sobre essa área como quando se escreve de maneira simultânea no mesmo espaço de memória por exemplo.

No [material da semana 3](https://ava2.ead.ufscar.br/mod/book/view.php?id=675313&chapterid=66502) (se você está lendo isso depois do semestre 2023/2 terá que procurar o link correto) ele entra em detalhes sobre o uso dos mecanismos de sincronização citados alguns parágrafos atrás. Este nível de detalhe em implementação tornaria um resumo redundante, portanto leia o original para conhecer as implementações, aqui apenas haverá uma explicação superficial de cada um deles.

**Pipes e FIFOs**:
São mecanismos equivalentes criados pelo kernel sob demanda. Correspondem a um buffer logicamente contíguo com armazenamento sequencial de dados e são usados como canal unidirecional para comunicação entre processos (como um cano, pipe).

O que separa eles é que o FIFO (*First in, First Out*) tem um nome no sistema de arquivos, ainda que esteja apenas salvo na memória e não no sistema de arquivos.

**Filas de Mensagem**:
As filas de mensagem, diferentes dos pipes e FIFOs, permitem troca de mensagens segmentadas, isto é, permitem comunicação em múltiplos sentidos. Cada mensagem tem associada a si um atributo que dita seu tipo ou prioridade.

As mensagens são mantidas pelo SO e devem ser copiadas de kernel space para user space.

**Semáforos**:
Semáforos são estruturas de sincronização cujas primitivas que os operam apenas podem consultar ou alterar o estado atual deles incrementando ou decrementando seu contador.

Através desse mecanismo, a lógica de programação deve ser montada de forma que processos mutuamente exclusivos tenham que consultar o semáforo antes de executar, alterar seu estado para bloquear outras atividades e novamente alterar o estado do semáforo quando terminarem sua execução de forma a "abrir espaço" para outras atividades.

**Memória Compartilhada**:
É sem dúvidas o meio mais veloz de comunicação entre processos de um mesmo sistema. Contudo é o mais fácil de fazer merda.

Uma vez que os dois processos podem enxergar a mesma área de memória da forma que foi explicado anteriormente, a lógica da aplicação deve ser estruturada de forma que acessos a uma mesma estrutura de dados de forma simultânea sejam impedidos.

**Mapeamento de memória**:
Feito através da chamada de sistema ```mmap```, permite mapear uma área de memória do espaço de endereçamento de um processo. Uma vez que o SO traga os dados do sistema de arquivos até a memória este conteúdo pode ser manipulado facilmente pelos processos

## Sincronização de Threads
Antes de falar sobre a sincronização de threads, vale ressaltar que existe um [material](https://ava2.ead.ufscar.br/mod/book/view.php?id=675314) (galera pós 2023/2, busquem no ava) que ataca o funcionamento da API pthreads a fundo. Ainda que no primeiro capitulo deste material tenha uma sessão que fala sobre threads em si nada abordado ali já não foi resumido em um de meus textos. Sendo assim, leia o original para conhecer mais detalhadamente o funcionamento da API.

Aqui serão mencionados e brevemente explicados os mecanismos de sincronização de threads a título de introdução, o estudo da implementação é tarefa que foge do escopo deste resumo.

**Detach e Join**:
O comando ```pthread_join``` é executado para esperar o fim de uma thread, contudo não se pode esperar pelo fim de qualquer thread. As treads quando criadas recebem um atributo que as torna *joinable* ou *detached*.

O comando ```pthread_detach``` serve para mudar o status de uma thread para *detached*. 

Posto que se possa esperar pelo fim da execução de threads a utilidade nestas funções é a de esperar que operações sejam concluídas antes de prosseguir com algum processamento que possa ter dependência de dados ou mesmo que possa alterar em simultâneo posições de memória usadas por uma thread.

**Semáforos POSIX**:
Mesma coisa que os outros, só que são implementados diretamente na API POSIX.

**Mutex**:
O termo mutex é uma abreviação de *mutual exclusion* e servem para bloquear recursos que podem ser do interesse de uma ou mais threads, porém cada mutex só pode ser liberado por uma thread de cada vez.

Eles são tipicamente usados para proteger regiões críticas do código (nas quais apenas uma thread deve operar por vez) e garantir a exclusão mútua de recursos (só uma thread fazendo uso por vez).

**Barreiras**:
Barreiras são usadas de forma a parar todas as threads até que um determinado número delas chame a função da barreira. Isso serve para sincronizar trabalhos de forma que nenhum avance até que uma porção do código seja atravessada por todos os outros.

**Variáveis Condicionais**:
Sem variáveis condicionais, programa deve fazer uma varredura constante para verificar se condição está satisfeita. Uma variável condicional é usada junto com um mutex para bloquear uma thread em função do valor de alguma condição.  
  
Variáveis condicionais permitem que uma _thread_ bloqueie a si mesma até que uma condição seja satisfeita. Pode haver diversas _threads_ bloqueadas aguardando condição. Cabe a outra _thread_ do processo verificar se a condição foi satisfeita e, então desbloquear a(s) _thread(s)_ bloqueada(s)  
Uma variável de condição pode estar associada a vários predicados, mas comumente está associada a apenas um predicado e a um _mutex._

**Bloqueios de leitura e escrita (rwlocks)**:
Realizam o bloqueio seletivo de leitores e escritores que desejam manipular alguma estrutura compartilhada. Um bloqueio de leitura impede que se escreva em uma estrutura, um bloqueio de escrita impede o acesso de leitores e de outros escritores.

**Spinlocks**:
São bloqueios de curta duração nos quais a thread que chamar ```pthread_spin_lock()``` segurará a "tranca" (*lock*) se ela não estiver com outra thread, uma thread que não possui a "tranca" devera "girar" (*spin*), isto é, não retornar da chamada ```pthread_spin_lock()``` até que a "tranca" fique disponível. Sei lá como eu usaria isso, mas a opção existe.

**Cancelamento de threads**:
Quando as threads trabalham de maneira independente em busca de uma solução para um dado problema pode ser que uma das threads alcance uma condição satisfatória e a partir de então não faz mais sentido continuar com as outras. Em casos como este podemos fazer uso do mecanismo de *thread cancelation*.

Toda thread é por padrão cancelável, mas isso pode ser mudado. Além do mais se pode adicionar e remover *cleanup handlers*, que são rotinas de tratamento para threads a serem executadas, isso pode ajudar a realizar algum tratamento nos dados antes de simplesmente cortar o funcionamento daquela thread.

## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!