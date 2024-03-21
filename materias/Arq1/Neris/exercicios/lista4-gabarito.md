# Gabarito Lista de Exercícios 4

#### Professor
[![Neris](https://img.shields.io/badge/Luciano_Neris-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)](https://site.dc.ufscar.br/docente/5cee7e5d48365a001679f750)


## Arquitetura MIPS

### Questão 1 

|   Nome do Sinal   | add $s1, $s2, $s3 | 
|-------------------|-------------------|
| RegDst            |  1                 |
| OrigALU           |  0                 |
| MemtoReg          |   0                |
| RegWrite          |    1               |
| MemRead           |     0             |
| MemWrite          |      0             |
| Branch            |       0            |
| ALUop1            |        1           |
| ALUop0            |         0          |
| Jump              |          0         |


### Questão 2 

Para as instruções aritméticas (formato R), o opcode é igual 000000 para as instruções: add, sub, and, or e slt, e a forma de seleção de operação é pelos bits F3, F2, F1 e F0, que são os últimos 4 bits do campo de função no formato de instrução. Os bits F4 e F5 não estão sendo usados. Os bits OpULA1 = 1 e OpULA0 = 0, indicam que a instrução é de formato R. Para as demais instruções o campo de função não existe e portanto, os bits F3,F2,F1,F0 da tabela são irrelevantes (marcados com x). Nesse a seleção de operação é feita exclusivamente pelos bits OpULA1 e OpULA0.

### Questão 3 

O circuito serve para converter os 16 bits da instrução para um número de 32 bits para que eles possam ser
utilizados como operandos das ULAs de 32 bits. Caso o número seja negativo, o número estendido deve
continuar sendo negativo. E caso o número seja positivo, o número estendido deve ser positivo.

### Questão 4 

O circuito de deslocamento de 2 no MIPS, desloca dois bits à esquerda e preenche os espaços resultantes à direita com zeros. Essa operação corresponde a uma multiplicação por 4, e é utilizada para aumentar o alcance efetivo do campo de deslocamento por um fator de 4, uma vez que o endereço de memória é um múltiplo de quatro e todas as instruções possuem 32 bits. Assim, os dois primeiros bits de todas as instruções são zero e podem ser omitidos na própria instrução.

### Questão 5 

| OPcode | RegDst | OrigDado | MempReg | EscreveReg | LeMem | EscreveMem | Desvio | OpULA1 | OpULA0 |
|--------|--------|----------|---------|------------|-------|------------|--------|--------|--------|
| 000000 | 1      | 0        | 0       |  1         |  0    | 0          | 0      | 1      | 0      |
| 100011 | 0      | 1        | 1       |  1         |  1    | 0          | 0      | 0      | 0      |
| 101011 | 0      | 1        | 0       |  0         |  0    | 1          | 0      | 0      | 0      |
| 000100 | 0      | 0        | 0       |  0         |  0    | 0          | 1      | 0      | 1      |

### Questão 6 
Porque as instruções formato R usam o terceiro campo de registrador (bit11 ... bit15) para indicar o registrador de escrita, enquanto que a instrução lw usa o segundo campo de registrador (bit16 ... bit20) para indicar o registrador de escrita.

### Questão 7 
Porque as instruções formato R, bem como beq, usam o segundo registrador (dado2) como o segundo operando da ULA, enquanto que as instruções lw e sw usam os 16 bits estendidos da instrução como segundo operando da ULA.

### Questão 8 
Porque as instruções formato R, usam o resultado de operação da ULA como dado a ser escrito num registrador, enquanto que a instrução lw, usa o dado lido na memória.

### Questão 9 
Porque numa instrução de desvio condicional, caso a condição é satisfeita, a linha de controle de desvio é um, e é enviado um endereço de desvio para o PC, calculado deslocando de 2 à esquerda os 16 bits estendidos da instrução, e somando com o valor contido em PC somado de 4. No caso em que a condição não é satisfeita a linha de controle de desvio é zero e o novo endereço de PC é PC somado de 4.

## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!