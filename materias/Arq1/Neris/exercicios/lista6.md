# Lista de Exercícios 6

#### Professor
[![Neris](https://img.shields.io/badge/Luciano_Neris-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)](https://site.dc.ufscar.br/docente/5cee7e5d48365a001679f750)


## Arquitetura MIPS

### 1 - Considerando o trecho de código em linguagem de montagem abaixo, liste todos os hazards de dados em potencial e os registradores que causam esses hazards:

```
I1: lw $a1, 4($sp)
I2: sw $a1, 0($v0)
I3: addi $sp, $sp, -4
I4: sw $a0, 8($sp)
I5: addi $a0, $a0, -2
```

### 2 - Considerando os estágios Instruction Fetch (I), Instruction Decode (D), Execution (X), Memory Access (M), Write Back (W) de um Datapath MIPS multiciclo pipelined, preencha a tabela abaixo inserido em cada célula a abreviação de cada estágio e indique as dependências e os conflitos existentes. Leve em consideração os seguintes itens:

- Todas as referências de instrução são encontradas na memória de instrução e requer um único ciclo;
- Todas as referências por dados são encontradas na memória de dados e requer um único ciclo;
- Os desvios (branches) são preditos como não tomados (not taken);
- Assuma que a reescrita de registradores ocorre na primeira metade do estágio W e a leitura de registradores na última metade do estágio D;
- Assuma que não há hazards estruturais;
- Assuma que não há hardware para suportar forwarding/bypassing.

![Tabela](https://github.com/petbccufscar/.github/blob/main/pet-colab/Arq1/imagem_2024-03-18_173558384.png)


### 3 - Considere uma CPU pipelined com 5 estágios (IF, ID, EX, MEM, WB), com memórias de dados e de instruções separadas, sem mecanismo de data forwarding, escrita no banco de registradores na borda de subida e leitura na borda de descida do clock. Quantos ciclos são necessários para executar o código abaixo considerando as informações citadas anteriormente?

```
I1: lw $2, 100($5)
I2: add $1, $2, $3
I3: sub $3, $2, $1
I4: sw $2, 50($1)
I5: add $2, $3, $3
I6: sub $2, $2, $4
```

### 4 - Para a sequência de instruções seguintes, verificar as dependências/conflitos e indicar as soluções para os mesmos:

```
sub $2, $4, $6
add $5, $2, $4
or $7, $2, $8
lw $9, 10($7)
sw $7, 10($5)
and $3, $5, $7
```

### 5 - Considere a sequencia de instruções abaixo a serem executadas no datapath de 5 estágios da Figura 1. Assuma também que os valores na memória de dados são inicializados com zero, e os registradores R0-R3 possuem inicialmente os valores indicados na tabela seguinte.

#### I. Identifique todos os hazards em cada sequencia de instruções para um pipeline de 5 estágios, com e em forwarding.

#### II. Considere os valores iniciais para os registradores R0-R3, qual é o primeiro valor que é transferido via forwarding, e qual o valor que ele sobrescreve?

#### III. Se assumirmos que teremos a unidade de detecção de hardware funcionando, mas NÃO a unidade de forwarding (um erro de projeto), qual é o valor final dos registradores R0-R3 após a execução da sequencia de instruções?

![Tabela2](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/Arq1/imagem_2024-03-18_174241160.png)

|    | R0 | R1 | R2 | R3   |
|----|----|----|----|------|
| a. | 0  | -1 | 31 | 1500 |
| b. | 0  | 4  | 63 | 3000 |


![datapath](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/Arq1/imagem_2024-03-18_174342437.png)


## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!