# Lista de Exercícios 5

#### Professor
[![Neris](https://img.shields.io/badge/Luciano_Neris-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)](https://site.dc.ufscar.br/docente/5cee7e5d48365a001679f750)


## Arquitetura MIPS

### 1 - Assuma que cada estágio do pipeline do processador MIPS tenha as seguintes latências:

|    |  IF   |  ID   |  EX   |  MEM  |  WB   | 
|----|-------|-------|-------|-------|-------|
| a. | 250ps | 350ps | 150ps | 300ps | 200ps |
| b. | 200ps | 170ps | 220ps | 210ps | 150ps |

#### I. Qual seria o tempo de um ciclo de clock em versões com a técnica de pipelining, sem pipelining (monociclo) ?

#### II. Qual é a latência total para executar uma instrução LW, nas versões com e sem pipelining ?

#### III. Se você pudesse dividir um dos estágios do pipeline em 2 novos estágios, cada um deles tendo metade da latência do estágio original, qual estágio você dividiria, e qual seria o novo tempo do ciclo de clock do processador ?

### 2 - Considerando às seguintes instruções MIPS:

|    |    Instrução     |
|----|------------------|
| a. | SW R16, -100(R6) |
| b. | OR R2, R1, R0    |

#### Conforme cada uma delas é executada, quais dados/sinais são armazenados nos registradores de pipeline entre cada um dos estágios do datapath da Figura 1?

![Fluxo Dados](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/Arq1/imagem_2024-03-18_171859137.png)

### 3 - Assumindo que instruções abaixo são executadas no datapath da Figura 1, de acordo com a frequência relativa entre a totalidade delas responda os itens a, b e c.

|    |  ADD   |  BEQ  |  LW   |  SW  |
|----|--------|-------|-------|------|
| a. | 40% | 30% | 25% | 5% | 
| b. | 60%| 10% | 20% | 10% |

#### I. Assumindo que nenhuma parada (stall) ocorra, e que 60% de todos os desvios condicionais ocorram,qual é a porcentagem de ciclos de clock em que o somador do estágio EX produz um valor que éutilizado de fato?

#### II. Assumindo que nenhuma parada (stall) ocorra, qual é a porcentagem de ciclos em que todas asportas (read1, read2, write1) do arquivo de registradores são utilizadas?

#### III. Assumindo que nenhuma parada (stall) ocorra, qual é a porcentagem de ciclos em que a memória de dados é usada?

### 4 - Quais são os registradores utilizados no MIPS pipeline, quais são os sinais de controle neles presentes, e quais são os sinais que são usados no estágio imediatamente seguinte?

### 5 - Dada a sequencia de instruções:

```
lw $5, 0($6)
add $2, $3, $4
sw $6, 0($6)
and $2, $5, $7
or $4, $5, $6
```
#### a) Em que estágios estão as instruções quando a última instrução está no estágio IF (busca de instrução)?

#### b) Quais são os sinais de controle presentes nos registradores de pipeline entre os estágios do pipeline quando a última instrução está no estágio IF?

#### c) Dos sinais listados no item b, quais são usados imediatamente nesse mesmo ciclo, ou seja, no estágio subsequente?

#### d) Quais são os dados contidos no registrador MEM/WB nesse mesmo ciclo?

## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!