# Lista de Exercícios 7

#### Professor
[![Neris](https://img.shields.io/badge/Luciano_Neris-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)](https://site.dc.ufscar.br/docente/5cee7e5d48365a001679f750)

## Exercícios de Arq1

### 1. Escreve um procedimento chamado AddThree que calcula e retorna no registrador EAX a soma de três inteiros passados como parâmetro via pilha. Utilize Stack Frame.

### 2. Desenhe o Stack Frame do procedimento gerado no exercício 1 após o mesmo ter sido chamado e o registrador EBP atualizado. Utilize os parâmetros contidos no trecho de código abaixo.
    push 10h
    push 20h
    push 30h
    call AddThree

### 3. Declare um procedimento chamado MultArray, indicando que o registrador ECX deva ser preservado, que recebe dois ponteiros para arrays do tipo DWORD e a quantidade de elementos do array. Crie também o protótipo desse procedimento.

### 4. Apresente o código gerado pelo montador referente ao procedimento abaixo.
    P1 PROC USES eax ebx,
        pBuffer: PTR BYTE
        LOCAL val: DWORD

        mov esi, pBuffer
        mov val, eax

        ret
    P1 ENDP

### 5. Utilizando a diretiva INVOKE, chame o procedimento P1 apresentado no exercício 4.

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

## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!
