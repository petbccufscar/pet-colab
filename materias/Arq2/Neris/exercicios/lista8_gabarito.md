# Gabarito Lista de Exercícios 8

#### Professor
[![Neris](https://img.shields.io/badge/Luciano_Neris-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)](https://site.dc.ufscar.br/docente/5cee7e5d48365a001679f750)

## Exercícios de Arq1

### 1. Escreva um trecho de código para comparar dois arrays de 16 bits utilizando a instrução CMPSW.
    mov ecx, count
    mov esi, offset sw
    mov edi, offset tw
    cld
    repe cmpsw

### 2. Utilizando a instrução SCASW, escreve um trecho de código que localize o valor 0100h em um array de 16 bits chamado wArray. Armazene o endereço do elemento encontrado no registrador EAX. 
    cld
    mov ecx, lengthog wArray
    mov eax, 4
    mov edi, offset wArray
    repne scasw
    sub edi, 4                ; adjust the offset
    mov eax, edi

### 3. Escreva um procedimento que concatene duas strings (source deve ser adicionada a target). Suponha a existência do procedimento StrLength capaz de retornar em EAX o tamanho de uma string passada como parâmetro.
    .data
        tStr BYTE "ABCDE", 10 DUP(0)
        sStr BYTE "FGH", 0

    .code
        INVOKE StrConcat, OFFSET tStr, OFFSET sStr

    StrConcat PROC USES eax ecx esi edi,
        target:PTR BYTE,          ; source string
        source:PTR BYTE           ; target string

        INVOKE StrLength, target  ; get length of target string
        add target, eax           ; move to end of target string
        INVOKE StrLength, source  ; get length of source string
        mov ecx, eax              ; insert length in REP count
        inc ecx                   ; add 1 for null byte
        mov esi, source
        mov edi, target
        cld                       ; direction = up
        rep movsb                 ; copy the string
        ret
    StrConcat ENDP

### 4. Apresente o conteúdo do array String2 após a execução do código abaixo.
    .data
        String1 byte 7 DUP(10h)
        String2 byte 7 DUP(20h)
    .code
        cld
        lea ESI, String1
        lea EDI, String2

        movsb ;String2[0] := String1[0]
        movsb ;String2[1] := String1[1]
        movsb ;String2[2] := String1[2]
        movsb ;String2[3] := String1[3]
        movsb ;String2[4] := String1[4]
        movsb ;String2[5] := String1[5]
        movsb ;String2[6] := String1[6]
    10h, 10h, 10h, 10h, 10h, 10h, 10h,

### 5. Apresente dois trechos de código que realizam a mesma operação do exercício 4). O primeiro trecho deve utilizar apenas uma instrução movsb dentro de um loop. O segundo trecho deve utilizar o prefixo rep.
        lea ESI, String1
        lea EDI, String2
        mov ECX, LENGTHOF String1
    L1:
        movsb
        loop L1

        lea ESI, String1
        lea EDI, String2
        mov ECX, LENGTHOF String1
        rep movsb

## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!
