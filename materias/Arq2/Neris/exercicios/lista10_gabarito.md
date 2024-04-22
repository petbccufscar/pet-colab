# Gabarito Lista de Exercícios 10

#### Professor
[![Neris](https://img.shields.io/badge/Luciano_Neris-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)](https://site.dc.ufscar.br/docente/5cee7e5d48365a001679f750)

## Exercícios de Arq1

### 1. Apresente o valor normalizado dos números binários:
        a. 11011.01011
        b. 0000100111101.1

    11011.01011 = 1.101101011 X 24
    0000100111101.1 = 1.001111011 X 2-8

### 2. Qual é o maior tipo de dados permitido pela instrução FLD e quantos bits ela pode conter?
    REAL10 80 bits

### 3. Qual é a diferença entre as instruções FSTP e FST?
    FSTP pops ST(0) da pilha

### 4. Apresente o número binário +1110.011 no padrão IEEE 754 precisão simples
    1.110011 X (2^3) -> 0 10000010 11001100000000000000000

### 5. Converta o decimal +10.75 para IEEE 754 precisão simples.
    +10.75 = +1010.11 = +1.01011 X (2^3) -> 0 10000010 01011000000000000000000

### 6. Converta o decimal −76.0625 para IEEE 754 precisão simples.
    -76.0625 = -01001100.0001 = -1.0011000001 X (2^-6), -> 1 10000101 00110000010000000000000

### 7. Converta o trecho de código abaixo escrito em C++ para assembly:
        double B = 7.8;
        double M = 3.6;
        double N = 7.1;
        double P = -M * (N + B);
    .data
        B REAL8 7.8
        M REAL8 3.6
        N REAL8 7.1
        P REAL8 ?
    .code
        fld M
        fchs
        fld N
        fadd B
        fmul
        fst P

### 8. Escreva um programa em assembly que calcule a expressão:

    (6.0 * 2.0) + (4.5 * 3.2)

    array REAL4 6.0, 2.0, 4.5, 3.2
    dotProduct REAL4 ?

    .code
        finit                         ; initialize FPU

        fld array                     ; push 6.0 onto the stack
        fmul array+4                  ; ST(0) = 6.0 * 2.0

        fld array+8                   ; push 4.5 onto the stack
        fmul array+12                 ; ST(0) = 4.5 * 3.2
        
        fadd                          ; ST(0) = ST(0) + ST(1)
        fstp dotProduct               ; pop stack into memory operand

## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!
