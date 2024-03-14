# Gabarito Lista de Exercícios 3

#### Professor
[![Neris](https://img.shields.io/badge/Luciano_Neris-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)](https://site.dc.ufscar.br/docente/5cee7e5d48365a001679f750)


## Arquitetura MIPS

### Questão 1 
```
Loop: add $t1, $s3, $s3 #Calcula o endereço da Word (4 bytes) i na memória (end = i * 4 + end inicial) Obs.: i * 4 = i+i +i+i
    add $t1, $t1, $t1
    add $t1, $t1, $s6
    lw $t0, 0 ( $t1)
    bne $t0, $s5, Exit
    add $s3, $s3, $s4
    jump Loop
Exit:
```

### Questão 2 

```
(a) 000101;
(b) 11011110;
(c) overflow;
(d) 001000011100;
(e) 11011011;
(f) overflow.
```

### Questão 3 

```
    mult $t2, $t4 # multiplica $t2 by 100
    mfhi $t5 # carregar o registrador HI em $t4 para verificar overflow
    bnez $t5, ovrf # se sim, então tratar o overflow
    mflo $t2 # se não, obter o resultado da multiplicação
    .
    .
    .
ovrf:
```

### Questão 4 

| Interação |           Passo         | Multiplicando |  Produto  |
|-----------|-------------------------|---------------|-----------|
| 0 | Valores Iniciais                |     00110     | 0000 0011 |
| 1 | 1: prodH= prodH + multiplicando |     0110      | 0110 0011 |
|   | shift right produto             |     0110      | 0011 0001 |
| 2 | 1: prodH= prodH + multiplicando |     0110      | 1001 0001 |
|   | shift right produto             |     0110      | 0100 1000 |
| 3 | 0: nada a somar                 |     0110      | 0100 1000 |
|   | shift right produto             |     0110      | 0010 0100 |
| 4 | 0: nada a somar                 |     0110      | 0010 0100 |
|   | shift right produto             |     0110      | 0001 0010 |

### Questão 5 

```
    lui $t0, 0x0000
    ori $t0, $t0, 0x0000 # Inicializa t0 com 0
    lui $t1, 0x0000
    ori $t1, $t1, 0x0001 # Inicializa t1 com 1
    lui $t2, 0x0000
    ori $t2, $t2, 0x000A # numero de repetições (10)
loop:
    add $a0, $t0,$0 # move $t0 para ser impresso
    lui $v0, 0x0000
    ori $v0, $v0, 0x0001 # escolhe impressao de inteiro (Inicializa v0 com 1)
    syscall # imprime o numero
    lui $a0, 0x0000
    ori $a0, $a0, 0x0020 # carrega o espaço (32 da tabela ASCII)
    lui $v0, 0x0000
    ori $v0, $v0, 0x0004 # escolhe impressao de string
    syscall # imprime um espaco
    add $t3, $t1,$0 # salva $t1 anterior
    add $t1, $t1, $t0 # calcula novo elemento em $t1
    add $t0, $t3, $0 # move $t1 anterior para $t0
    addi $t2, $t2, -1 # decrementa contador de loop
    bgtz $t2, loop # repete enquanto maior que 0
```

### Questão 6 
Para o circuito de soma (a + b), considerando carry = 0, temos a seguinte tabela verdade:

| a | b | r | 
|---|---|---|
| 0 | 0 | 0 |
| 0 | 1 | 1 |
| 1 | 0 | 1 |
| 1 | 1 | 0 |

Portanto, a solução é usar o circuito de soma, ou seja, operação = 10.
Numa ULA de 32 bits que usa também o carry como entrada da soma, o circuito de soma já não funciona para a operação XOR de 32 bits.

## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!