# Lista de Exercícios 2

#### Professor
[![Neris](https://img.shields.io/badge/Luciano_Neris-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)](https://site.dc.ufscar.br/docente/5cee7e5d48365a001679f750)

## Exercícios de Arq1

### 1. Apresente o valor das flags CF, ZF, SF e OF para cada instrução aritmética abaixo.
    mov ax, 620h
    sub ah, 0F6h ; CF = , ZF = , SF = e OF =
    
    mov ax, 720h
    sub ax, 0E6h ; CF = , ZF = , SF = e OF =
    
    mov ax, 0B6D4h
    add al, 0B3h ; CF = , ZF = , SF = e OF =
    
    mov al, -127
    dec bl ; CF = , ZF = , SF = e OF =
    
    mov ah, -56
    add ah, -60 ; CF = , ZF = , SF = e OF =

### 2. Apresente o valor retornado pelo operador SIZEOF de cada uma das declarações abaixo:
    a1 byte ?                     ; SIZEOF(a1) =
    a2 word ?                     ; SIZEOF(a2) =
    a4 dword ?                    ; SIZEOF(a4) =
    ary0 byte 10 dup (0)          ; SIZEOF(ary0) =
    ary1 word 10 dup (10 dup (0)) ; SIZEOF(ary1) =

### 3. Utilizando a declaração
    .data
    var1 SBYTE -4,-2,3,1
    var2 WORD 1000h,2000h,3000h,4000h
    var3 SWORD -16,-42
    var4 DWORD 1,2,3,4,5

### determine o valor do operando destino de cada uma das instruções abaixo
    mov al,var1      ;
    mov ah,[var1+3]  ;
    mov ax,var2      ;
    mov ax,[var2+4]  ;
    mov ax,var3      ;
    mov ax,[var3-2]  ;
    mov edx,var4     ;
    movzx edx,var2   ;
    mov edx,[var4+4] ;
    movsx edx,var1   ;

### 4. Escreva uma sequencia de instruções MOV que inverta as words LSB e MSB de uma variável dword chamada DVal.

### 5. Utilizando a declaração
    .data
    myBytes BYTE 10h,20h,30h,40h
    myWords WORD 3 DUP(?),2000h
    myString BYTE "ABCDE"

### determine o valor do registrador eax de cada uma das instruções abaixo
    mov eax,TYPE myBytes     ;
    mov eax,LENGTHOF myBytes ;
    mov eax,SIZEOF myBytes   ;
    mov eax,TYPE myWords     ;
    mov eax,LENGTHOF myWords ;
    mov eax,SIZEOF myWords   ;
    mov eax,SIZEOF myString  ;

### 6. Utilizando a declaração do exercício 4 escreva uma única instrução que move os primeiros 2 bytes de myBytes para o registrador DX. Qual será o valor movido após a execução dessa instrução?

### 7. Utilizando a declaração do exercício 4 escreva uma única instrução que move o segundo byte de myWords para o registrador al.

### 8. Utilizando a declaração do exercício 4 escreva uma única instrução que move todos os 4 bytes de myBytes para o registrador EAX. Qual será o valor movido após a execução dessa instrução?

### 9. Complete o preenchimento dos valores de esi, nos comentários abaixo:
    .data
        bVal BYTE 5 DUP (?)
        wVal WORD ?
        dVal DWORD ?
    .code
        mov esi, OFFSET bVal ; esi = 00404000
        mov esi, OFFSET wVal ; esi =
        mov esi, OFFSET dVal ; esi =

### 10. O trecho de código contido no Exercício 8 pode ser reescrito utilizando variáveis ponteiro. Quais valores serão armazenados no registrador ESI após a execução de cada instrução do código abaixo?
    .data
        bVal BYTE 5 DUP (?)
        pbVal DWORD bVal
        wVal WORD ?
        pwVal DWORD wVal
        dVal DWORD ?
        pdVal DWORD dVal
    .code
        mov esi, pbVal ; esi = 00404000
        mov esi, pwVal ; esi =
        mov esi, pdVal ; esi =

### 11. Escrever os valores dos operandos destino das seguintes instruções:
    .data
        varB BYTE 44h, 32h, 03h, 0Ah, 0Dh
        varW WORD 0FF43h, 3302h
             BYTE ?
        varD DWORD 11223344h
    .code
        mov ax, WORD PTR [varB+3]   ; ax =
        mov bl, BYTE PTR varD       ; bl =
        mov bl, BYTE PTR [varW+3]   ; bl =
        mov ax, WORD PTR [varD+2]   ; ax =
        mov ax, DWORD PTR varW      ; ax =
        mov al,TYPE varB            ; al =
        mov al,TYPE varD            ; al =
        mov eax, LENGTHOF varB      ; eax =
        mov ebx, LENGTHOF varW      ; ebx =
        mov eax, SIZEOF varB        ; eax =
        mov ebx, SIZEOF varW        ; ebx =
        mov ecx, SIZEOF varD        ; ecx =

### 12. Dado o exemplo abaixo modifica-lo para um vetor de bytes e dword
    .data
        arrayW WORD 1000h,2000h,3000h
    .code
        mov esi, OFFSET arrayW
        mov ax, [esi]
        add esi, 2 ; or: add esi,TYPE arrayW
        add ax, [esi]
        add esi, 2
        add ax, [esi] ; AX = sum of the array
### 13. Dado o exemplo abaixo modifica-lo para um vetor de bytes e dword
    .data
        arrayW WORD 1000h,2000h,3000h
    .code
        mov esi, 0
        mov ax, arrayW[esi]
        add esi, 2
        add ax, [arrayW + esi]
        add esi, 2
        add ax, [arrayW + esi]

### 14. Que mudança você faria ao programa anterior se fosse somar o vetor de words utilizando um loop?


## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!
