# Lista de Exercícios 3

#### Professor
[![Neris](https://img.shields.io/badge/Luciano_Neris-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)](https://site.dc.ufscar.br/docente/5cee7e5d48365a001679f750)

## Exercícios de Arq1

### 1. Escreva um trecho de código em assembly que utiliza apenas instruções PUSH e POP para trocar os valores armazenados nos registradores EAX e EBX.

### 2. Quais valores estarão contidos no array após a execução do programa abaixo?
    .data
        array DWORD 4 DUP(0)
    .code
    main PROC
        mov eax,10
        mov esi,0
        call proc_1
        add esi,4
        add eax,10
        mov array[esi],eax
        INVOKE ExitProcess,0
    main ENDP
    proc_1 PROC
        call proc_2
        add esi,4
        add eax,10
        mov array[esi],eax
        ret
    proc_1 ENDP
    proc_2 PROC
        call proc_3
        add esi,4
        add eax,10
        mov array[esi],eax
        ret
    proc_2 ENDP
    proc_3 PROC
        mov array[esi],eax
        ret
    proc_3 ENDP

### 3. Qual será o valor de EAX após a execução do trecho de código assembly abaixo?
    push 5
    push 6
    pop eax
    pop eax

### 4. Supondo que a instrução PUSH não tenha sido implementada, escreva uma sequencia de instruções capaz de realizar a mesma função.

### 5. Supondo que AX=1234h, BX=5678h e CX=9ABCh, determine o conteúdo de AX, BX e CX após a execução dotrecho de código a seguir:
    PUSH AX
    PUSH BX
    XCHG AX,CX
    POP CX
    PUSH AX
    POP BX

## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!
