# Soma Paralela de Matrizes
> Código criado pelo aluno [Jorge Pires](https://www.linkedin.com/in/jorgeprj)

#### Professor
![Helio](https://img.shields.io/badge/Helio_Crestana_Guardia-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)


## Conceito
O problema da paralelização da soma de matrizes envolve distribuir o cálculo da soma de matrizes grandes entre múltiplos processadores para reduzir o tempo de execução. Isso é feito dividindo as matrizes em blocos menores e atribuindo esses blocos a diferentes processadores para realizar a soma de forma simultânea. A paralelização é uma estratégia eficaz para lidar com grandes conjuntos de dados e pode melhorar significativamente o desempenho, desde que a distribuição de carga e a comunicação entre os processadores sejam otimizadas.


## Resolução

### Utilizando *PThreads*

```c
int matrix1[MATRIX_SIZE][MATRIX_SIZE];
int matrix2[MATRIX_SIZE][MATRIX_SIZE];
int result[MATRIX_SIZE][MATRIX_SIZE];

void *matrix_add(void *arg) {
	int thread_id = *((int *)arg);
	int elements_per_thread = MATRIX_SIZE * MATRIX_SIZE / NUM_THREADS;
	int start = thread_id * elements_per_thread;
	int end = (thread_id == NUM_THREADS - 1) ? MATRIX_SIZE * MATRIX_SIZE : start + elements_per_thread;

	for (int i = start; i < end; i++) {
    	int row = i / MATRIX_SIZE;
    	int col = i % MATRIX_SIZE;
    	result[row][col] = matrix1[row][col] + matrix2[row][col];
	}

	pthread_exit(NULL);
}

int main() {
	pthread_t threads[NUM_THREADS];
	int thread_ids[NUM_THREADS];

	// Preencha as matrizes com valores aleatórios (você pode fornecer seus próprios valores)
	for (int i = 0; i < MATRIX_SIZE; i++) {
    	for (int j = 0; j < MATRIX_SIZE; j++) {
        	matrix1[i][j] = rand() % 10;
        	matrix2[i][j] = rand() % 10;
    	}
	}

	// Crie threads para realizar a soma
	for (int i = 0; i < NUM_THREADS; i++) {
    	thread_ids[i] = i;
    	pthread_create(&threads[i], NULL, matrix_add, &thread_ids[i]);
	}

	// Aguarde a conclusão das threads
	for (int i = 0; i < NUM_THREADS; i++) {
    	pthread_join(threads[i], NULL);
	}
	return 0;
}
```

### Utilizando *OpenMP*

```c
#pragma omp parallel for
	for (int i = 0; i < MATRIX_SIZE; i++) {
    		for (int j = 0; j < MATRIX_SIZE; j++) {
        			result[i][j] = matrix1[i][j] + matrix2[i][j];
    		}
	}

```

## Questões Teóricas

### Como decompôs as atividades do programa para usar múltiplos processadores? Funcional? Dados? Híbrida?
A decomposição de atividades no programa é funcional, com cada thread realizando uma função específica. A decomposição de dados também é usada, com as matrizes sendo divididas entre as threads para processamento paralelo. Isso permite tirar proveito dos múltiplos processadores de forma eficiente.


### As atividades previstas podiam ser executadas em qualquer ordem?
Sim, as atividades previstas no exemplo de soma paralela de matrizes usando OpenMP podem ser executadas em qualquer ordem. Isso ocorre porque a operação de soma é comutativa, o que significa que a ordem em que os elementos das matrizes são somados não afeta o resultado final. Como resultado, as threads podem executar as operações de soma em qualquer ordem, e o resultado será o mesmo.

## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!