# Resumo Aula 7
> Resumo criado pelo aluno [João Pedro Trevisan](https://www.linkedin.com/in/joao-pedro-trevisan)

#### Professor
![Helio](https://img.shields.io/badge/Helio_Crestana_Guardia-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)

## História e Detalhes sobre CUDA
A GPU foi inventada pela NVIDIA em 1999 e é o processador paralelo mais conhecido e usado atualmente (além do multiprocessador comum a maioria dos sistemas). Depois de alguns anos de uso das GPUs seu uso foi explorado para resolver problemas não relacionados com gráficos como de protein folding, precificação de ações, queries SQL e muitos outros. Em momentos pretéritos do trabalho deste problemas com GPUs estes programas se chamavam Programas GPGPU (General Purpose GPU).

O modelo de trabalho GPGPU apesar de prover acelerações na resolução de problemas tinha uma série de fatores que complicavam seu uso. Ele exigia que o desenvolvedor conhecesse profundamente as APIs da GPU e sua arquitetura, além disso os problemas deveriam ser expressados na forma de coordenadas vetoriais, texturas e programas shader, o que aumentava muito a complexidade das soluções. Por fim, características básicas da programação como leituras e escritas aleatórias em memória não eram presentes e não havia suporte a precisão dupla.

Para atacar estes problemas a NVIDIA introduziu 2 tecnologias: a arquiteturas unificada G80 e CUDA que é uma arquitetura de software e hardware que permitia que a GPU fosse programada com uma série de linguagens de alto nível.

A arquitetura de software e hardware CUDA ativa a execução de Kernels compostos de uma série de Threads que executam em paralelo. O programador deve saber organizar estas threads em blocos e grids de blocos, cada thread em um bloco executará uma instância do Kernel e terá um identificador, um contador de programa, registradores e uma área de memória privada.

Um bloco é um conjunto de threads que podem cooperar através de barreiras e memória compartilhada e contém um identificador de bloco assim como as threads individuais.

Um grid é um arranjo de blocos que executam o mesmo kernel, fazem leitura de dados e salvam resultados em memória global.

A imagem a seguir ilustra estes elementos:
![aula07_img01.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/PPD/aula07_img01.png)

As GPUs são composta de múltiplos elementos de processamento e uma hierarquia de memória, para algumas placas da NVIDIA a arquitetura consiste de uma série de Streaming Multiprocessors, um cache L2 e um banco de memória DRAM. Como exemplo, uma GPU Volta V100 tem 80SMs, 6MB de cache L2 e até 32GB de memória HBM2.

A imagem a seguir ilustra um Streaming Multiprocessor:
![aula07_img02.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/PPD/aula07_img02.png)

Quando usamos um Kernel devemos especificar o número de threads por bloco e o número de blocos que vão compor o grid de execução da seguinte forma:

![aula07_img03.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/PPD/aula07_img03.png)

Dentro de cada SM, a execução de _threads_ ocorre em blocos de 32, chamados _**warps**_. Warps são a unidade de execução paralela, que ocorre no modelo **SIMT** (_Single-Instruction, Multiple-Thread_). Assim, a mesma sequência de instruções é executada simultaneamente em todas as _threads_ deste grupo.

Com relação ao acesso à memória, cada _thread_ tem uma área de memória privada e cada bloco de _threads_ tem acesso a uma área de memória compartilhada. Todas as _threads_ têm acesso também à memória global da GPU, localizada em chips externos.

CUDA assume que as áreas de memória da GPU e da CPU são separadas, de forma que é preciso copiar dados entre elas, antes e depois de suas manipulações. Para GPUs mais recentes, há mecanismos de mapeamento de memória que permitem a criação de áreas comuns entre GPU e CPU.

## Programação CUDA
Uma vez que GPUs foram projetadas inicialmente para o paralelismo de dados é importante lembrar que todos seus processadores executam ao mesmo tempo o mesmo conjunto de instruções, comumente sobre partes distintas dos dados.

Na programação em CUDA as CPUs continuam gerenciando a execução dos programas porém podem delegar parte dos processamentos e dados para a placa de vídeo. Quando trabalhamos neste modelo usamos o termo **host** para designar o sistema computacional e **device** para nos referir a cada elemento de processamento.

De maneira geral, a programação com CUDA (e OpenCL) envolve as seguintes etapas:
1. Declarar e alocar variáveis e espaços de memória para dados na RAM (_host memory_) e dentro do espaço de endereçamento da GPU (_device memory_);
2. Inicializar dados no host;
3. Transferir dados do host para o device;
4. Executar um ou mais _kernels_ no device;
5. Transferir os resultados da memória do _device_ para a memória do _host_.

Para os exemplos de código usaremos CUDA C que é uma extensão da linguagem C que permite ao programador a definição de funções chamadas Kernels que quando chamadas serão executadas n vezes em n threads CUDA diferentes.

Um kernel é definido usando a palavra ```__global__``` antes da definição de uma função e quando ela é chamada o número de threads CUDA que executam aquele kernel para uma dada chamada são definidos usando a assinatura ```funcParalel<<<...>>>(A,B,C)```.

Veja o código a seguir:
``` C
// Kernel definition
__global__ void VecAdd(float* A, float* B, float* C)
{
    int i = threadIdx.x;
    C[i] = A[i] + B[i];
}

int main()
{
    ...
    // Kernel invocation with N threads
    VecAdd<<<1, N>>>(A, B, C);
    ...
}
```

Este código dois vetores A e B de tamanho N são adicionados e guardados no vetor de resultado C. Neste código cada uma das N threads realizam a adição.

Existe uma hierarquia entre as threads, a variável ```threadIdx``` pode ser chamada para retornar um vetor de 3 componentes que pode representar um índice de threads com uma, duas ou três dimensões. Isso dá uma noção natural de processamentos em vetores, matrizes ou volumes.

Existe um limite de threads por bloco uma vez que espera-se que todas threads de um bloco estão no mesmo núcleo do processador e devem compartilhar recursos de memória deste núcleo, um bloco de threads pode conter até 1024 threads.

Um kernel pode ser executado por múltiplos blocos de threads de mesmo formato, dessa forma o número de threads é igual ao número de threads por bloco multiplicado pelo número de blocos.

O número de threads por bloco podem ser de tipo ```int``` ou ```dim3```, sendo que ```dim3``` é uma struct com a seguinte assinatura:
``` C
typedef struct {
   size_t x;
   size_t y;
   size_t z;
} dim3;
```

É necessário que blocos de threads executem de maneira independente, deve ser possível executá-los em qualquer ordem, em paralelo e em série. Essa restrição permite o shceduling de processamento e faz com que o código escale com o número de núcleos.

As threads em um bloco podem cooperar compartilhando dados na memória compartilhada e sincronizando sua execução para coordenar o acesso à memória. Pode se especificar pontos de sincronização com a chamada ```_syncthreads()``` que age como uma barreira na qual toda thread do bloco deve esperar antes de receber a permissão de proceder.

Além da palavra ```__global__``` existem muitos outros termos e funções que podem ser usados para construir um programa em CUDA, suas características são:
- **```__global__```**
	- Declara uma função como um kernel que é executado no *device*, é chamável pelo *host* e é chamável por *devices* de capacidade maior que 3.2.
	- Deve ter tipo ```void```.
	- Não pode ser parte de uma classe.
	- Uma chamada a uma função ```__global__``` deve especificar uma configuração de execução e é assíncrona. 
- **```__host__```**
	- Declara uma função que é executável e chamável apenas pelo *host*.
	- É o mesmo que declarar uma função sem nenhum especificador, isto é, ela é apenas compilada para rodar no *host*.
	- Não pode ser usado junto de ```__global__```.
- **```__device__```**
	- Declara uma função que é executável e chamável apenas pelo *device*.
	- Não pode ser usada junto de ```__global__```.
	- Reside em espaço global de memória.
	- Tem tempo de vida igual ao do contexto CUDA no qual é criado.
	- Possui um objeto diferente por *device*.
	- É acessível por qualquer thread de um grid e pelo *host*.
- **```__constant__```**
	- É opcionalmente usado junto de ```__device__``` para definir características de memória.
	- Reside em espaço de memória constante.
	- Tem tempo de vida igual ao do contexto CUDA no qual é criado.
	- Possui um objeto diferente por *device*.
	- É acessível por qualquer thread de um grid e pelo *host*.
- **```__shared__```**
	- É opcionalmente usado junto de ```__device__``` para definir características de memória.
	- Reside em espaço de memória de um bloco de threads
	- Tem tempo de vida igual ao do bloco no qual reside.
	- Possui um objeto diferente para cada bloco.
	- Só é acessível pelas threads de um mesmo bloco.
	- Não possui um endereço constante.
- **```__managed__```**
	- É opcionalmente usado junto de ```__device__``` para definir características de memória.
	- É acessível por ambos *device* e *host* e seu endereço pode ser tomado, ou lido ou escrito diretamente de uma função do *host* ou do *device*.
	- Tem tempo de vida igual ao da aplicação.
- **```__restrict__```**
	- Ponteiros restritos foram introduzidos em C99 para atacar o problema de aliasing que existe em linguagens de tipo C que inibe todo tipo de otimização desde reorganização de código até eliminação de sub-expressões.
	- Você não vai saber usar, campeão, continua lendo aí.
- **```cudaMalloc()```**
	- Aloca bits de memória linear e retorna um ponteiro para a memória alocada.
	- Exitem ainda ```cudaMalloc3D```,```cudaMalloc3DArray()```,```cudaMallocArray()```,```cudaMallocHost()``` e```cudaMallocPitch()```.
- **```cudaMemcpy()```**
	- Copia bytes da área da memória iniciada no ponteiro fornecido pelo desenvolvedor para a área destino também fornecida por ele na forma de um ponteiro.
	- Existem [muitas formas](https://developer.download.nvidia.com/compute/DevZone/docs/html/C/doc/html/group__CUDART__MEMORY_g48efa06b81cc031b2aa6fdc2e9930741.html#g48efa06b81cc031b2aa6fdc2e9930741) de se copiar memória do *device*.
- **```cudaGetLastError(void)```**
	- Retorna um objeto do tipo ```cudaError_r``` com dados do erro gerado.
- **```cudaGetErrorString(cudaError_t)```**
	- Retorna uma string que descreve o erro.`

Sobre a ativação de um kernel, como vimos anteriormente existem 2 parâmetros que devem ser passados, o primeiro deles indica a estruturação do grid, isto é, quantos blocos de threads serão usados e como estarão organizados, já o segundo parâmetro indica como as threads estão organizadas em blocos. Temos então a forma ```kernel_function << grid, bloco >>```, note que o primeiro atributo indicará o número de blocos de threads em cada dimensão do grid formado por essa invocação de kernel.

Assim, o número total de threads de uma aplicação será igual ao número de threads em cada dimensão multiplicado pelo número total de blocos. O número de dimensões da grade (número de blocos) multiplicado pelas dimensões do bloco (número de threads) deve ser igual ao número de elementos a se processar.

Podemos recuperar informações que identificam as threads e blocos dentro de um grid, são elas:
- Thread dentro do bloco: ```threadIdx.x```, ```threadIdx.y```, ```threadIdx.z```
- Bloco dentro do _grid_: ```blockIdx.x```, ```blockIdx.y``` e ```blockIdx.z```
- Dimensões do bloco: ```blockDim.x```, ```blockDim.y``` e ```blockDim.z```
- Dimensões do grid em blocos: ```gridDim.x```, ```gridDim.y``` e ```gridDim.z```

Estes dados nos permitem mapear identificadores de threads com a organização de estruturas de dados multidimensionais como vetores, matrizes e volumes. Além disso, a organização lógica das threads em blocos abre margem para o mapeamento dos blocos aos elementos de processamento das GPUs.

A imagem a seguir é muito útil para visualizar toda essa estrutura de dados:

![aula07_img06.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/PPD/aula07_img06.png)

Este grid possui apenas duas dimensões de blocos de threads. Para este caso, caso um programador queira criar um identificador único para cada thread pode-se multiplicar o índice de seu bloco pela dimensão do bloco e somar o identificador dessa thread isso é importante pois as treads só são identificadas dentro de seus blocos e não em relação as outras threads de um grid. Veja:

```C
int ind = blockIdx.x * blockDim.x + threadIdx.x;
```

Note como a imagem a seguir mapeia os elementos de dados aos elementos de arquitetura:

![aula07_img04.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/PPD/aula07_img04.png)

Depois que o kernel é ativado, os blocos de threads são atribuídos para execução nos SMs disponíveis e a forma dessa execução pode variar, observe:

![aula07_img05.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/PPD/aula07_img05.png)

Por fim, quando começamos a estudar paralelização em multiprocessadores aprendemos a medir o tempo de execução de um dado programa. Quando fazemos uso de aceleradores como GPUs surge o problema não podermos acessar as diferentes informações que o kernel do SO armazena sobre os processos em execução e espera.

Assim sendo, é preciso saber como medir o tempo de processamento de maneira correta ao usar CUDA. Esta API fornece chamadas que criam e destroem eventos, gravam eventos e convertem diferenças em timestamps em valores de ponto flutuante representando milissegundos.

O código a seguir é um exemplo de contabilização de tempo em CUDA:

``` C
cudaEvent_t start, stop;
float time;

cudaEventCreate(&start);
cudaEventCreate(&stop);

cudaEventRecord( start, 0 );
kernel<<<grid,threads>>> ( d_odata, d_idata, size_x, size_y,
                           NUM_REPS);
cudaEventRecord( stop, 0 );
cudaEventSynchronize( stop );

cudaEventElapsedTime( &time, start, stop );
cudaEventDestroy( start );
cudaEventDestroy( stop )
```

Neste código a função ```cudaEventRecord()``` é usada para colocar os eventos ```start``` e ```stop``` na stream padrão 0. A GPU vai gravar um timestap para o evento quando ela alcançar o evento na stream. A função ```cudaEventElapsedTime()``` retorna o tempo entre a gravação dos eventos ```start``` e ```stop```. Este valor é expresso em milissegundos, tem uma resolução de aproximadamente meio milissegundo e uma vez que é calculado na GPU e é independente do sistema operacional.

## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!