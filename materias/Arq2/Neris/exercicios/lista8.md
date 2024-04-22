# Lista de Exercícios 8

#### Professor
[![Neris](https://img.shields.io/badge/Luciano_Neris-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)](https://site.dc.ufscar.br/docente/5cee7e5d48365a001679f750)

## Exercícios de Arq1

### 1. Escreva um trecho de código para comparar dois arrays de 16 bits utilizando a instrução CMPSW.

### 2. Utilizando a instrução SCASW, escreve um trecho de código que localize o valor 0100h em um array de 16 bits chamado wArray. Armazene o endereço do elemento encontrado no registrador EAX.

### 3. Escreva um procedimento que concatene duas strings (source deve ser adicionada a target). Suponha a existência do procedimento StrLength capaz de retornar em EAX o tamanho de uma string passada como parâmetro.

### 4. Apresente o conteúdo do array String2 após a execução do código abaixo.
    .data
        String1 BYTE 7 DUP(10h)
        String2 BYTE 7 DUP(20h)
    .code
        cld
        mov ESI, OFFSET String1
        mov EDI, OFFSET String2
        movsb
        movsb
        movsb
        movsb
        movsb
        movsb
        movsb

### 5. Apresente dois trechos de código que realizam a mesma operação do exercício 4. O primeiro trecho deve utilizar apenas uma instrução movsb dentro de um loop. O segundo trecho deve utilizar o prefixo rep.

## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!
