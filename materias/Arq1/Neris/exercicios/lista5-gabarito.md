# Gabarito Lista de Exercícios 5

#### Professor
[![Neris](https://img.shields.io/badge/Luciano_Neris-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)](https://site.dc.ufscar.br/docente/5cee7e5d48365a001679f750)


## Arquitetura MIPS

### Questão 1 

#### I.

|    |    Pipelined     | Single-Cycle |
|----|------------------|--------------|
| a. | 350ps | 1250ps |
| b. | 220ps    | 950ps|


#### II.

|    |    Pipelined     | Single-Cycle |
|----|------------------|--------------|
| a. | 1750ps           | 1250ps       |
| b. | 1100ps           | 950ps        |

#### III.

|    |    Pipelinexl    | Single-Cycle |
|----|------------------|--------------|
| a. | ID               | 300ps        |
| b. | EX               | 210ps        |

### Questão 2 

Para cada instrução, o registrador IF/ID mantém o PC + 4 e a própria palavra de instrução. O registrador ID/EX mantém todos os sinais de controle para os estágios EX, MEM e WB, PC + 4, os dois valores lidos dos Registradores, os 16 bits menos significativos da instrução estendidos e os campos Rd e Rt da instrução (mesmo para instruções cujo formato não inclua esses campos). O registrador EX/MEM mantém os sinais de controle para os estágios MEM e WB, o PC + 4 + Offset (onde Offset é o sinal de 16 bits menos significativos das instruções, mesmo para instruções que não têm campo de offset), o resultado da ALU e o valor da sua saída Zero, o valor que foi lido a partir do segundo registrador no estágio ID (mesmo para instruções que nunca precisem desse valor) e o número do registrador de destino (mesmo para instruções que não precisem de registrador de escritos). O registrador MEM/WB mantém os sinais de controle WB, o valor lido na memória (ou um valor "aleatório" se não houver memória lida), o resultado da ALU e o número do registrador de destino.

### Questão 3 

#### I.

a. 18% (60% de 30%), b. 6% (60% de 10%) - Somente a instrução BEQ utiliza o somador

#### II. 

a. 40%, b. 60% - Somente ADD necessita dos 3 registradores, 2 de leitura e 1 de escrita

#### III. 

a. 30% (25% + 5%), b. 30% (20% + 10%) – Somente Lw e Sw utilizam a memória de dados.


### Questão 4
Da esquerda para a direita: IF/ID, ID/EX, EX/M e M/WB.

```
    Os sinais neles presentes:
    IF/ID: sem sinais
    ID/EX: OpULA0, OpULA1, RegDst, Origdado, LerMem, EscrMem, Desvio, MempReg, EscReg
    EX/M: LerMem, EscrMem, Desvio, MempReg, EscReg

    M/WB: MempReg, EscReg
    Os sinais usados no estágio imediatamente seguinte:
    ID/EX: OpULA0, OpULA1, RegDst, Origdado
    EX/M: LerMem, EscrMem
    M/WB: MempReg, EscReg
```
### Questão 5

#### a)
```
lw $5, 0($6) # Estágio WB
add $2, $3, $4 # Estágio M
sw $6, 0($6) # Estágio EX
and $2, $5, $7 # Estágio ID
or $4, $5, $6 # Estágio IF
```

#### b)
```
ID/EX : sinais de controle para instrução sw
OpULA0 = 0, OpULA1 = 0, RegDst= x, Origdado = 1; LerMem=0, EscrMem=1, Desvio=0, MempReg=x,
EscReg=0
EX/M: sinais de controle para a instrução add
LerMem=0, EscrMem=0, Desvio=0, MempReg=0, EscReg=1
M/WB: sinais de controle para a instrução lw
MempReg=1, EscReg=1
```

#### c)
```
ID/EX : sinais de controle para instrução sw
OpULA0 = 0, OpULA1 = 0, RegDst= x, Origdado = 1
EX/M: sinais de controle para a instrução add
LerMem=0, EscrMem=0, Desvio=0
M/WB: sinais de controle para a instrução lw
MempReg=1, EscReg=1
```

#### d)
Os dados contidos no latch MEM/WB são os referentes à instrução lw $5, 0($6) que está no estágio
WB: o dado lido na memória, e o endereço de memória da mesma instrução lw, sendo que o multiplexador
MemP.Reg deve selecionar o dado lido na memória, para escrita no registrador.

## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!