# Lista de Exercícios 4

#### Professor
[![Neris](https://img.shields.io/badge/Luciano_Neris-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)](https://site.dc.ufscar.br/docente/5cee7e5d48365a001679f750)

## Exercícios de Arq1

### 1. Qual será o valor de BX após a execução das instruções abaixo?
    a)
        mov bx, 0FFFFh
        and bx, 6Bh
    b)
        mov bx, 91BAh
        and bx, 92h
    c)
        mov bx, 649Bh
        or bx,3Ah
    d)
        mov bx, 29D6h
        xor bx, 8181h

### 2. Qual será o valor de AL após a execução das instruções abaixo?
    mov al, 01101111b
    and al, 00101101b
    mov al, 6Dh
    and al, 4Ah
    mov al, 00001111b
    or al, 61h
    mov al, 94h
    xor al, 37h

### 3. Apresente os valores das flags carry, zero e signal nos pontos indicados.
    mov al, 00001111b
    test al, 00000010b ; a) CF= ZF= SF=
    mov al, 00000110b
    cmp al, 00000101b ; b) CF= ZF= SF=
    mov al, 00000101b
    cmp al ,00000111b ; c) CF= ZF= SF=

### 4. Qual será o valor de EDX após a execução do trecho de código assembly abaixo?
        mov edx,1
        mov eax, 7FFFh
        cmp eax, 8000h
        jb L1
        mov edx, 0
    L1:

### 5. Escreva uma única instrução capaz de converter um dígito ASCII armazenado no registrador AL (‘0’ ou ‘1’ .. ou ‘9’) em seu correspondente valor binário (0000 ou 0001 ... ou 1001).

### 6. Escreva um trecho de código em assembly que salta para o label L1 quando um valor inteiro sem sinal armazenado em DX é menor ou igual ao inteiro contido em CX.

### 7. Converta o pseudocódigo abaixo em linguagem assembly. Assuma que as variáveis são de 32 bits.
```c
if( ebx > ecx AND ebx > edx) OR ( edx > eax )
    X = 1
else
    X = 2
```

### 8. Converta o pseudocódigo abaixo em linguagem assembly. Assuma que as variáveis são de 32 bits.
```c
while N > 0
    if N != 3 AND (N < A OR N > B)
        N = N – 2
    else
        N = N – 1
end while
```

## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!
