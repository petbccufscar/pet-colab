# Gabarito Lista de Exercícios 2

#### Professor
[![Neris](https://img.shields.io/badge/Luciano_Neris-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)](https://site.dc.ufscar.br/docente/5cee7e5d48365a001679f750)

## Exercícios de Arq1

### 1. 
    CF = 1, ZF = 0 , SF = 0 e OF = 0
    CF = 0 , ZF = 0 , SF = 0 e OF = 0
    CF = 1, ZF = 0 , SF = 1 e OF = 0
    CF = 1, ZF = 0 , SF = 1 e OF = 0
    CF = 1 , ZF = 0 , SF = 0 e OF = 1

### 2.
    1
    2
    4
    10
    200

### 3.
    FCh
    01h
    1000h
    3000h
    FFF0h
    4000h
    00000001h
    00001000h
    00000002h
    FFFFFFFCh

### 4.
    mov ax,word ptr dVal
    mov bx,word ptr dVal+2
    mov word ptr dVal,bx
    mov word ptr dVal+2,ax

### 5.
    1
    4
    4
    2
    4
    8
    5

### 6.
    mov dx, WORD PTR myBytes ; 2010h

### 7.
    mov al, BYTE PTR myWords + 1

### 8.
    mov eax, DWORD PTR myBytes ; 40302010h

### 9.
    00404005h
    00404007h

### 10.
    00404009h
    0040400Fh

### 11.
    D0Ah
    44h
    33h
    1122h
    ERROR
    01h
    04h
    05h
    02h
    05h
    04h
    04h

### 12.
    .data
        arrayB BYTE 10h,20h,30h
        arrayD DWORD 10000000h,20000000h,30000000h
    .code
        mov esi, OFFSET arrayB
        mov al, [esi]
        inc esi
        add al, [esi]
        inc esi
        add al, [esi]
        mov esi, OFFSET arrayD
        mov eax, [esi]
        add esi, 4
        add eax, [esi]
        add esi, 4
        add eax, [esi]

### 13.
    .data
        arrayB byte 10h,20h,30h
        arrayD DWORD 10000000h,20000000h,30000000h
    .code
        mov esi, 0
        mov al, arrayB[esi]
        inc esi
        add al, [arrayB + esi]
        inc esi
        add al, [arrayB + esi]
        mov esi, 0
        mov eax, arrayD[esi]
        add esi ,4
        add eax, [arrayD + esi]
        add esi ,4
        add eax, [arrayD + esi]

### 14.
    .data
        arrayW WORD 1000h,2000h,3000h
    .code
        mov edi, OFFSET arrayW
        mov ecx, LENGTHOF arrayW
        mov ax, 0
    L1:
        add ax, [edi]
        add edi, TYPE arrayW
        loop L1


## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!
