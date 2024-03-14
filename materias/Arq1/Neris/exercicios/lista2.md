# Lista de Exercícios 2

#### Professor
[![Neris](https://img.shields.io/badge/Luciano_Neris-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)](https://site.dc.ufscar.br/docente/5cee7e5d48365a001679f750)


## Arquitetura MIPS

### 1 - Descrever qual o artifício usado pela instrução beq ou bne para executar um desvio dentro de um programa da à impossibilidade de inserir no código da instrução endereços de 32 bits.

### 2 - Para que serve o circuito de extensão de sinal de 16 para 32 bits no MIPS?

### 3 - Dada a instrução slt $7, $2, $6, dar o conteúdo do registrador $7, após a sua execução, se o conteúdo de $2 é igual a 1 e de $6 é igual a 3.

### 4 - Dada a instrução bne $7, $0, L1, verificar se a instrução seguinte é sequencial, ou do endereço L1, dado o conteúdo de $7 igual a 1.

### 5 - Considerando que não existe instrução de subtração imediata e que as variáveis são guardadas em registradores e os vetores em memória, escrever a instrução, ou o menor conjunto de instruções em Assembly do MIPS, que realiza as operações em código C seguintes:

#### a) a = a – 1

#### b) a = 0

#### c) v[10] = 0 (elemento 10 do vetor v, sendo início de v dado pelo registrador $4)

#### d) se a < b salta para L1

#### e) se a > 0 salta para L1

### 6 - Dada a instrução add $4, $5, $6 mostrar, em binário, o conteúdo dos campos rs, rt e rd no diagrama da figura abaixo.

| OP     | RS  | RT  | RD  | SHAMT   | FUNCTION  |
|--------|-----|-----|-----|---------|-----------|
| 000000 |     |     |     |  00000  |  100000   |

### 7 - Dada a instrução lw $4, 5 ($3) mostrar o conteúdo, em binário, dos campos no diagrama da figura abaixo.

| OP     | RS  | RT/RD  | 16 bits de endereço |
|--------|-----|--------|---------------------|
|        |     |        |                     |


### 8 - Dada a instrução bne $3, $4, 5 mostrar o conteúdo em binário dos campos no diagrama da figura abaixo.

| OP     | RS  | RT/RD  | 16 bits de desvio de endereço |
|--------|-----|--------|-------------------------------|
|        |     |        |                               |

### 9 - O Dado trecho de código abaixo em Assembly do MIPS realize a execução passo a passo mostrando os valores de registradores a cada iteração, dado o conteúdo inicial dos registradores e de parte da memória indicados na figura seguinte. Mostrar o conteúdo da memória no final da execução. O símbolo # na metade direita das instruções abaixo indica o início de um comentário:

```
L1: muli $14, $2, 4 # $14 = i x 4
    add $3, $4, $14 # $3 = endereço de A [i]
    sw $0, 0 ($3) # A [i] = 0
    addi $2, $2, 1 # i = i +1
    slt $7, $2, $6 # $7 = (i < n)
    bne $7, $0, L1 # se (i < n) vai para L1
```
![Registradores](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/Arq1/imagem_2024-03-14_160706846.png)

### 10 - Escrever um programa em Assembly do MIPS que some dois vetores A e B, colocando o resultado em A, ou seja, A [i] = A[i] + B[i] , para i = 0, .. n-1. Considerar $4, o ponteiro para o início do vetor A, e $5 o ponteiro para o início do vetor B. Usar $t0 e $t1 como registradores temporários.

### 11 - Fazer a adição dos números -126 e -64 em binário, e verificar se ocorre overflow.

### 12 - Realizar a adição binária bit a bit dos números naturais 17 e 18, em 8 bits.

### 13 - Representar o número -63 em palavra de 16 bits em complemento de dois.

### 14 - Gere um segmento de código para um processador MIPS que desvie o fluxo de execução para um label denominado Exit caso uma variável ‘a’, armazenada em $s0, for menor do que uma variável ‘b’, armazenada em $s1.

### 15 - Supondo que o endereço base de um array de words tenha sido armazenado previamente no registrador $s3, gere um trecho de código em assembly, para a arquitetura MIPS, que represente a seguinte expressão:

```
A[12] = h + A[8]
```
### 16 - O endereço base do array A de 100 words foi previamente armazenado em $s3 e as variáveis g, h e i foram associadas aos registradores $s1, $s2 e $s4 de um processador MIPS. Qual deve ser o código assembly para a operação g = h + A[i] utilizando apenas as instruções lw e add?

### 17 - Apresente o código assembly, para a arquitetura MIPS, da função swap abaixo supondo que: xp em $a0 e yp em $a1.

```c
void swap(int *xp, int *yp)
{
    int t0 = *xp;
    int t1 = *yp;
    *xp = t1;
    *yp = t0;
}
```

## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!