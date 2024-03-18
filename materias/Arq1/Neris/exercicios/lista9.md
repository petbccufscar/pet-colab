# Lista de Exercícios 9

#### Professor
[![Neris](https://img.shields.io/badge/Luciano_Neris-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)](https://site.dc.ufscar.br/docente/5cee7e5d48365a001679f750)


## Desempenho

### 1 - Um computador C1 executa um programa A em 10 segundos. Um computador C2 executa o mesmo programa A em 15 segundos. Quais são os desempenhos dos dois computadores para a execução do programa A?

### 2 - Se o computador C1 executa o programa A do exercício anterior em 20 milhões de ciclos, qual é a taxa de clock do processador?

### 3 - Dado um computador com taxa de clock de 500 MHz, e um programa com 6 milhões de instruções classe A de 1 ciclo, 3 milhões de instruções classe B de 2 ciclos, e 2 milhões de instruções classe C de 3 ciclos, calcular:

#### a) Tempo de ciclo do processador;

#### b) Número de ciclos do programa;

#### c) Tempo de execução do programa;

#### d) CPI médio do programa;

#### e) Throughput em MIPS (Milhões de Instruções Por Segundo) para esse programa.


### 4 - Considerando-se a execução do programa abaixo com n = 10x106, se as instruções tipo-R levam 4 ciclos; lw, 5 ciclos; sw, 4 ciclos; bne, 3 ciclos e de operandos imediatos 4 ciclos, calcular o desempenho para um computador MIPS de 1GHz.

```
        sub $2, $2, $2 # i=0
loop1:  muli $14, $2, 4 # $14 = i x 4
        add $3, $4, $14 # $3 = endereço de A[i]
        sw $0, 0($3) # A[i] = 0
        addi $2, $2, 1 # i = i + 1
        slt $7, $2, $6 # $7 = (i<n)
        bne $7, $0, loop1 # se (i < n) vai para loop1
```

### 5 - Supor que a execução sequencial de um programa num computador, leva um tempo de 100 segundos. Considerando-se que todas as instruções tem um mesmo número de ciclos, e que seja possível melhorar o tempo de execução de uma parte desse programa correspondente a 40 segundos do tempo de execução sequencial, fazendo o computador executar simultaneamente duas instruções, calcular:

#### a) O novo tempo de execução;

#### b) O speedup obtido.

### 6 - Suponhamos que melhoramos uma máquina fazendo todas as instruções de ponto flutuante serem executadas 5 vezes mais rápido. Se o tempo de execução de certo benchmark antes do melhoramento é de 10 segundos, qual seria o speedup se metade dos 10 segundos é despendida em instruções de ponto flutuante?

### 7 - Estamos procurando um benchmark para testar a nova unidade de ponto-flutuante do exercício anterior, e queremos que o benchmark todo mostre um speedup de 3. Um benchmark é executado em 100 segundos, com o antigo hardware de ponto flutuante. Qual a porcentagem das instruções de ponto flutuante nesse programa para que possamos produzir o speedup desejado nesse benchmark?

## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!