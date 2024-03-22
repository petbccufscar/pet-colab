# Gabarito Lista de Exercícios 4

#### Professor
[![Neris](https://img.shields.io/badge/Luciano_Neris-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)](https://site.dc.ufscar.br/docente/5cee7e5d48365a001679f750)

## Exercícios de Arq1

### 1.
    a) BX = 006Bh
    b) BX = 092h
    c) BX = 064BBh
    d) BX = A857h

### 2.
    al = A3h

### 3.
    a) CF= 0 ZF= 0 SF=0
    b) CF= 0 ZF= 0 SF=0
    c) CF= 1 ZF= 0 SF=1

### 4.
    EDX = 1

### 5.
    and al, 0Fh

### 6.
        cmp dx,cx
        jbe L1
    L1:

### 7.
        cmp bx,cx                   ; bx > cx?
        jna L1                      ; no: try condition after OR
        cmp bx,dx                   ; yes: is bx > dx?
        jna L1                      ; no: try condition after OR
        jmp L2                      ; yes: set X to 1
        ;-----------------OR(dx > ax) ------------------------
    L1: cmp dx,ax                   ; dx > ax?
        jna L3                      ; no: set X to 2
    L2: mov X,1                     ; yes:set X to 1
        jmp next                    ; and quit
    L3: mov X,2                     ; set X to 2
    next:

### 8.
    ; supondo que
    mov eax, 4    ; A
    mov ebx, 5    ; B
    mov edx, 10   ; N

    whileloop:
        cmp edx ,0
        jle endwhile
        cmp edx, 3                   ; if N != 3
        je elselabel
        ; check N < eax OR N > ebx
        cmp edx, eax                 ; N < A?
        jl orlabel                   ; if true, jump
        cmp edx, ebx                 ; or N > B?
        jg orlabel                   ; if true, jump
        jmp elselabel
    orlabel:
        sub edx, 2
        jmp whileloop
    elselabel:
        sub edx, 1
        jmp whileloop
    endwhile:

## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!
