# Gabarito Lista de Exercícios 7

#### Professor
[![Neris](https://img.shields.io/badge/Luciano_Neris-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)](https://site.dc.ufscar.br/docente/5cee7e5d48365a001679f750)

## Exercícios de Arq1

### 1. Escreve um procedimento chamado AddThree que calcula e retorna no registrador EAX a soma de três inteiros passados como parâmetro via pilha. Utilize Stack Frame.
    AddThree PROC
        push ebp
        mov ebp,esp
        mov eax,[ebp + 16]
        add eax,[ebp + 12]
        add eax,[ebp + 8]
        pop ebp
        ret 12
    AddThree ENDP

### 2. Desenhe o Stack Frame do procedimento gerado no exercício 1 após o mesmo ter sido chamado e o registrador EBP atualizado. Utilize os parâmetros contidos no trecho de código abaixo.
    push 10h
    push 20h
    push 30h
    call AddThree

![Imagem 1](https://github.com/petbccufscar/.github/raw/main/pet-colab/Arq2/lista7_ex2.png)

### 3. Declare um procedimento chamado MultArray, indicando que o registrador ECX deva ser preservado, que recebe dois ponteiros para arrays do tipo DWORD e a quantidade de elementos do array. Crie também o protótipo desse procedimento.
    MultArray PROC USES ECX, array1:PTR DWORD, array2:PTR DWORD, count:DWORD
    MultArray PROTO, array1:PTR DWORD, array2:PTR DWORD, count:DWORD

### 4. Apresente o código gerado pelo montador referente ao procedimento abaixo.
    P1 PROC USES eax ebx,
        pBuffer: PTR BYTE
        LOCAL val: DWORD

        mov esi, pBuffer
        mov val, eax

        ret
    P1 ENDP

    P1 PROC
        push ebp
        mov ebp, esp
        add esp, 0FFFFFFFCh
        push eax
        push ebx
        mov esi, dword ptr [ebp + 8]
        mov dword ptr [ebp - 4], eax
        pop ebx
        pop eax
        leave
        ret 4
    P1 ENDP

### 5. Utilizando a diretiva INVOKE, chame o procedimento P1 apresentado no exercício 4.
    P1 PROTO, pBuffer:PTR BYTE
    .data
        bArray byte 20 dup (?)
    .code
        INVOKE P1, OFFSET bArray

### 6. Converta o código abaixo, escrito em linguagem de alto nível, para linguagem de montagem utilizando Stack Frame para a passagem de parâmetros e criação de variáveis locais. Utilize o registrador EAX para retornar o valor da função proc1.
```c
int proc1(int a, int b, int c)
{
    int x = a + 2;
    int y = b + 3;
    int z = c + 4;
    int sum = x + y + z;
    return x * y * z + sum;
}
int main()
{
    return proc1(10, 20, 30);
}
```

```c
ExitProcess PROTO, dwExitCode:DWORD

.code
main PROC
    push 10
    push 20
    push 30
    call Proc1
    INVOKE ExitProcess, eax
main ENDP

Proc1 PROC
    push ebp
    mov ebp, esp
    sub esp, 16

    mov eax, DWORD PTR [ebp+8]
    add eax, 2
    mov DWORD PTR [ebp-4], eax

    mov eax, DWORD PTR [ebp+12]
    add eax, 3
    mov DWORD PTR [ebp-8], eax

    mov eax, DWORD PTR [ebp+16]
    add eax, 4
    mov DWORD PTR [ebp-12], eax

    mov eax, DWORD PTR [ebp-4]
    add eax, DWORD PTR [ebp-8]
    add eax, DWORD PTR [ebp-12]
    mov DWORD PTR [ebp-16], eax

    mov eax, DWORD PTR [ebp-4]
    imul eax, DWORD PTR [ebp-8]
    imul eax, DWORD PTR [ebp-12]
    add eax, DWORD PTR [ebp-16]

    mov esp, ebp
    pop ebp
    ret 12
Proc1 ENDP
END main
```

## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!
