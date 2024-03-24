# Lista de Exercícios 9

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

### 2. Declare um array com 100 elementos de estruturas do tipo triângulo definida no exercício 1. Inicialize o vértice 1 de cada triângulo com os valores 0 e 0.

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

### 4. Corrija os problemas de alinhamento da estrutura definida no exercício 3 e apresente novamente os endereços lógicos de cada campo da variável s2.

### 5. Utilizando a estrutura gerada no exercício 4, escreva um trecho de código que preenche cada elemento do campo f4 da variável s1 com o valor 12345678h utilizando a diretiva de repetição rep e uma instrução primitiva de manipulação de strings.

### 6. Apresente cada byte da memória alocada para a variável s1 após a execução do trecho de código gerado no exercício 5.

## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!
