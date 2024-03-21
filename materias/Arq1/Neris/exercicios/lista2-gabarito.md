# Gabarito Lista de Exercícios 2

#### Professor
[![Neris](https://img.shields.io/badge/Luciano_Neris-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)](https://site.dc.ufscar.br/docente/5cee7e5d48365a001679f750)


## Arquitetura MIPS

### Questão 1 

Para executar o desvio dentro de um programa, o contador de programa PC deve ser atualizado com um novo valor de endereço que não seja o endereço sequencial, que no caso do MIPS é o endereço contido no PC acrescido de 4. O novo valor de endereço é calculado somando o valor contido no PC, com os 16 bits contidos na instrução, no campo “constante”, multiplicados por 4. A multiplicação por 4 é necessária para apontar a uma palavra na memória.

### Questão 2 

O circuito serve para converter os 16 bits da instrução para um número de 32 bits. Caso o número seja
negativo, o número estendido deve continuar sendo negativo. E caso o número seja positivo, o número
estendido deve ser positivo.

### Questão 3 

$7 = 1.

### Questão 4 

Endereço L1.

### Questão 5 

- a) Considerando-se a variável a em $t0, addi $t0, $t0, -1
- b) Considerando-se a variável a em $t0, addi $t0, $0, $0
- c) sw $0, 40($4) ; 40($4) = v[10], pois cada elemento do vetor é uma palavra de 32 bits, ou 4 bytes.
- d) Considerando-se a variável a em $2, e a variável b em $3, slt $7,$2,$3 ; ou seja, $2 <$3 então $7 = 1 bne $7, $0, L1 ; portanto desvia se $7 diferente de 0, como $7 =1.
- e) Considerando-se a variável a em $3, slt $7,$0,$3 ; ou seja se $0 < $3 então $7 =1 bne $7, $0, L1 ; portanto desvia se $7 diferente de 0, como $7 =1.

### Questão 6 

**SOLUÇÃO: (lembrar que o registrador destino é o terceiro no formato).**

| OP     | RS  | RT  | RD  | SHAMT   | FUNCTION  |
|--------|-----|-----|-----|---------|-----------|
| 000000 | 00101    | 00110    | 00100    |  00000  |  100000   |

### Questão 7 

**SOLUÇÃO:**

| OP     | RS  | RT/RD  | 16 bits de endereço |
|--------|-----|--------|---------------------|
| 100011 |  00011   |  00100   |  0000000000000101  |

### Questão 8 

**SOLUÇÃO:**

| OP     | RS  | RT/RD  | 16 bits de desvio de endereço |
|--------|-----|--------|-------------------------------|
| 000101  |  00011 | 00100 | 0000000000000101 |

### Questão 9 

![Resolução](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/Arq1/imagem_2024-03-14_161704989.png)

### Questão 10 

```
    sub $2,$2,$2 # zera $2
L1: muli $14, $2, 4 # offset = i * 4
    add $3, $5, $14 # $3 = end B[i]
    lw $t1, 0 ($3) # $t1 = B[i]
    add $3, $4, $14 # $3 = end A[i]
    lw $t0, 0($3) # $t0 = A[i]
    add $t0,$t0, $t1 # $t0 = A[i] + B[i]
    sw $t0, 0 ($3) # A[i] = A[i]+B[i]
    addi $2,$2,1 # i = I +1
    slt $7, $2, $6 # se i < n $7 = 1
    bne $7, $0, L1 # desvia se $7 <> 0
```

### Questão 11 

- 126 em binário = 10000010
- 64 em binário = 11000000
(-126) + (-64) em binário = 01000010
Ocorre overflow pois a soma de dois números negativos (-126 e -64) deu positivo. O resultado em decimal é:

```
01000010 = 1x26+ 1x21= 1x64+ 1x2 = 66.
```

### Questão 12 

```
17 = 00010001
18 = 00010010
17 +18 = 00100011
```
### Questão 13 

```
11111111 11000001
```
### Questão 14 

```
    slt $t0, $s0, $s1        # reg. $t0 recebe 1 se $s0 < $s1
    bne $t0, $zero, Exit     # desvia para Less se $t0 ≠ 0
Exit:                        # instruções caso o desvio seja tomada
```

### Questão 15 

```
lw $t0, 32($s3) # $t0 recebe o valor de A[8]
add $t0, $s2, $t0 # $t0 recebe h + A[8]
sw $t0, 48($s3) # h + A[8] é armazenado em # A[12]
```

### Questão 16 

```
# multiplicar o valor de ‘i’, que está em $s4 por 4
add $t1, $s4, $s4 # $t1 recebe 2 * i
add $t1, $t1, $t1 # $t1 recebe 4 * i
add $t1, $t1, $s3 # soma o end. base em $s3 com o deslocamento de $t1
lw $t0, 0($t1) # carrega A[i] em $t0
add $s1, $s2, $t0 # g = h + A[i]
```

### Questão 17 

```
swap:
    lw $t0,($a0) # t0=*xp
    lw $t1,($a1) # t1=*yp
    sw $t1,($a0) # *xp=t1
    sw $t0,($a1) # *yp=t0
    jr $ra
```

## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!