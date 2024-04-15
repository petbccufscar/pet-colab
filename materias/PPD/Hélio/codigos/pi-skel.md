# Cálculo paralelo do valor de pi
> Código criado pelo aluno [Jorge Pires](https://www.linkedin.com/in/jorgeprj)


#### Professor
![Helio](https://img.shields.io/badge/Helio_Crestana_Guardia-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)

## Conceito

Entre muitas formas para o cálculo do valor de pi, há algumas que usam o método de Monte-Carlo, baseado em probabilidades.

Por exemplo, suponha um círculo de raio 1 inserido em um quadrado de lado 2.

Se forem gerados valores aleatórios para pontos dentro do quadrado, a relação entre pontos que estiverem dentro do círculo e os pontos totais gerados pode ser dada pela relação entre a área do círculo e a área do quadrado.

Relação entre as áreas:

![Formula 1](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/PPD/imagem_2024-04-15_022551567.png)

![Formula 2](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/PPD/imagem_2024-04-15_022621659.png)

Considerando a geração de valores aleatórios entre 0 e 1 (raio) para as coordenadas x e y de um ponto, pode-se usar a equação do teorema de Pitágoras para determinar se ponto está dentro do círculo ou não:

```
z^2=x^2+y^2
```
**Tarefa:** fazer um programa que usa esse método de Monte Carlo para o cálculo do valor de pi.


## Resolução

### Utilizando *PThreads*

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define SAMPLES 10000000

long amostras, hits = 0;
unsigned short seed[3];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *monte_carlo(void *arg) {
	int num_samples = *(int *)arg;
	long local_hits = 0;

	for (long i = 0; i < num_samples; i++) {
    	double x = erand48(seed);
    	double y = erand48(seed);

    	if (x * x + y * y <= 1.0)
        	local_hits++;
	}

	pthread_mutex_lock(&mutex);
	hits += local_hits;
	pthread_mutex_unlock(&mutex);

	return NULL;
}

int main(int argc, char **argv) {
	if (argc > 1)
    	amostras = atoi(argv[1]);
	else
    	amostras = SAMPLES;

	seed[0] = 0.5;
	seed[1] = 0.5;
	seed[2] = (unsigned short)time(NULL);

	int num_threads = 4; // Escolha o número de threads desejado

	pthread_t threads[num_threads];
	int samples_per_thread = amostras / num_threads;

	for (int i = 0; i < num_threads; i++) {
    	pthread_create(&threads[i], NULL, monte_carlo, &samples_per_thread);
	}

	for (int i = 0; i < num_threads; i++) {
    	pthread_join(threads[i], NULL);
	}

	double pi = (4 * (double)hits / (double)amostras);
	printf("hits: %ld\n", hits);
	printf("Pi: %.16f\n", pi);

	return 0;
}
```

Neste código, você especifica o número de threads que deseja criar (neste exemplo, definido como 4), divide o trabalho igualmente entre as threads e usa um mutex para proteger a variável hits de condições de corrida. Cada thread executa a função ``monte_carlo`` e, após todas as threads terem concluído, o programa principal calcula o valor de pi com base nos resultados coletados.


### Utilizando *OpenMP*

```c
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <limits.h>

#define N_THREADS 8
#define SAMPLES 2<<25


void *
calcula(void *arg)
{
    pthread_exit(NULL);
}


int main(int argc, char **argv) {
	int status;
	long amostras, fracao, parcial;
	long hits = 0;
	double pi;

	if (argc > 1)
    	amostras = atoi(argv[1]);
	else
    	amostras = SAMPLES;

	unsigned short seed[3];

	seed[0] = 0.5;
	seed[1] = 0.5;
	seed[2] = (unsigned short)time(NULL);

	double x, y;

	#pragma omp parallel for private(x, y) reduction(+:hits)
	for (long i = 0; i < amostras; i++) {
    	x = erand48(seed);
    	y = erand48(seed);

    	if (x * x + y * y <= 1.0)
        	hits++;
	}

	printf("hits: %ld\n", hits);

	pi = (double)(4 * (double)((double)hits / (double)amostras));

	printf("Pi: %.16f\n", pi);

	return 0;
}
```

Essa foi a maneira mais simples encontrada para paralelizar. No entanto, existem outras possibilidades melhores.

## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!