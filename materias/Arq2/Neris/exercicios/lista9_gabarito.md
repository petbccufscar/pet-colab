# Gabarito Lista de Exercícios 9

#### Professor
[![Neris](https://img.shields.io/badge/Luciano_Neris-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)](https://site.dc.ufscar.br/docente/5cee7e5d48365a001679f750)

## Exercícios de Arq1

### 1. Utilizando a estrutura triângulo abaixo, declare uma variável do tipo triângulo inicializada com os vértices (0,0), (5, 0) e (7,6).
    Coord STRUCT
        X word ?
        Y word ?
    Coord ENDS

    Triangle STRUCT
        Vertex1 COORD <>
        Vertex2 COORD <>
        Vertex3 COORD <>
    Triangle ENDS

    myShape Triangle < <0,0>, <5,0>, <7,6> >

### 2. Declare um array com 100 elementos de estruturas do tipo triângulo definida no exercício 1. Inicialize o vértice 1 de cada triângulo com os valores 0 e 0.
    .data
        ARRAY_SIZE =100
        triangles Triangle ARRAY_SIZE DUP(<>)
    .code
        mov ecx,ARRAY_SIZE
        mov esi,0
    L1: mov triangles[esi].Vertex1.X, 0
        mov triangles[esi].Vertex1.Y, 0
        add esi,TYPE Triangle
        loop L1

### 3. Supondo endereços lógicos, apresente o endereço de cada campo da variável s2 da declaração abaixo.

    St1 STRUCT
        f1 BYTE "00"
        f2 BYTE 0
        f3 WORD
        f4 DWORD 0, 0
        f5 BYTE 0
    St1 ENDS

    .data
        s1 St1 <>
        s2 St1 <>
    s1.f1 = 0x00000000h
    s1.f2 = 0x00000002h
    s1.f3 = 0x00000003h
    s1.f4 = 0x00000005h
    s1.f5 = 0x0000000Dh

    s2.f1 = 0x0000000Eh
    s2.f2 = 0x00000010h
    s2.f3 = 0x00000011h
    s2.f4 = 0x00000013h
    s2.f5 = 0x0000001Bh

### 4. Corrija os problemas de alinhamento da estrutura definida no exercício 3 e apresente novamente os endereços lógicos de cada campo da variável s2.
    St1 STRUCT
        f1 BYTE "00"
        f2 BYTE 0
        ALIGN WORD
        f3 WORD 0
        ALIGN DWORD
        f4 DWORD 0, 0
        f5 BYTE 0
    St1 ENDS

    .data
        s1 St1 <>
        s2 St1 <>

    s2.f1 = 0x00000011h
    s2.f2 = 0x00000013h
    s2.f3 = 0x00000015h
    s2.f4 = 0x00000019h
    s2.f5 = 0x00000021h

### 5. Utilizando a estrutura gerada no exercício 4, escreva um trecho de código que preenche cada elemento do campo f4 da variável s1 com o valor 12345678h utilizando a diretiva de repetição rep e uma instrução primitiva de manipulação de strings.
    mov edi, OFFSET s1.f4
    mov eax, 12345678h
    mov ecx, LENGTHOF s1.f4
    rep stosd

### 6. Apresente cada byte da memória alocada para a variável s1 após a execução do trecho de código gerado no exercício 5.
    Endereço 00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F 10
    Valor    30 30 00 00 00 00 00 00 78 56 34 12 78 56 34 12 00

## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!
