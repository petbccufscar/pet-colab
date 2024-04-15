# Lista de Exercícios 3

#### Professor
![Helio](https://img.shields.io/badge/Helio_Crestana_Guardia-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)


## Programação paralela com memória distribuída

### 1. Em um software para *clusters*, cada computador normalmente possui um S.O. local acrescido de funcionalidades para comunicação em rede. Identificação unificada de usuários e acesso global aos dados são fatores relevantes neste ambiente. Comente.

### 2. Ainda sobre *clusters*, discuta o uso de mecanismos para a ativação remota de programas, considerando também o caso em que os computadores interligados são heterogêneos.

### 3. Passagem de mensagem normalmente envolve a transmissão por um meio físico serial. Discuta as implicações disso nas transmissões de dados de uma aplicação.

### 4. Recursos necessários para a implementação de uma biblioteca de passagem de mensagem incluem um método para criação de processos em máquinas remotas e mecanismo para enviar e receber mensagens. Relacione mecanismos que podem ser usados para cada um dos aspectos.

### 5. Esquematize a comunicação de uma aplicação baseada no modelo **cliente x servidor** usando TCP/IP e UDP/IP.

### 6. Descreva uma possível implementação de primitivas de comunicação bloqueantes, não bloqueantes, síncronas e assíncronas usando a *API de sockets* em rede.

### 7. Para a resposta anterior, como seriam identificadas os processos? E as mensagens?


##  Biblioteca MPI

### 8. Descreva o mecanismo de criação estática de processos.

### 9. Descreva de que maneira as funções *MPI_Comm_size( )* e *MPI_Comm_rank( )*, permitem o controle do paralelismo e da granularidade da aplicação.

### 10. Descreva como ocorre o tratamento de tipos diferentes de dados para transmissão.

### 11. Descreva os tipos de sincronização que podem ser usados na transmissão de mensagens.

### 12. Descreva a identificação de processos nas primitivas de transmissão.

### 13. Descreva a identificação de mensagem nas primitivas de transmissão.

### 14. Discuta a sincronização de processos via troca de mensagens, e outros mecanismos explícitos para sincronização existentes.

### 15. Descreva a operação das primitivas de comunicação coletiva: *MPI_Bcast( )*, *MPI_Reduce( )*, *MPI_Scatter( )*, *MPI_Gather( )*, *MPI_Alltoall( )*, *MPI_Allgather( )* e *MPI_Barrier( )*.

### 16. Latência e vazão são características da transmissão de dados em rede. Comente esses componentes na determinação dos tempos de transmissão de uma aplicação.

### 17. Comente a relação comunicação/computação no particionamento de aplicações paralelas para ambientes distribuídos.

### 18. O que *latency hiding*? Descreva como pode ser obtida no paralelismo com múltiplos computadores interligados em rede.

### 19. Descreva as etapas de um possível algoritmo paralelo para a ordenação de um vetor em um ambiente com **memória compartilhada**. Trate do particionamento e do paralelismo obtido.

### 20. Descreva as etapas de um possível algoritmo paralelo para a ordenação de um vetor em um ambiente com **memória distribuída**. Trate do particionamento e do paralelismo obtido.

## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!