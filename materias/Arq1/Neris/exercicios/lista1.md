# Lista de Exercícios 1

#### Professor
[![Neris](https://img.shields.io/badge/Luciano_Neris-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)](https://site.dc.ufscar.br/docente/5cee7e5d48365a001679f750)


## Conceitos Básicos

### 1 - Utilizando os mnemônicos LOAD (carga de dados), STORE (armazenamento de dados), ADD (soma de dados) e SUB (subtração de dados) crie um segmento de código, em linguagem assembly, que realize as operações abaixo. As instruções de movimentação de dados utilizam 2 operandos e as instruções aritméticas utilizam 3 operandos.

#### I. Armazenar o operando "5" no registrador R1;

#### II. Carregar o operando localizado no endereço 0xA4B7 da Memória Principal no registrador R2;

#### III. Somar os operandos localizados em R1 e R2 e armazenar o resultado em R3;

#### IV. Armazenar o operando localizado em R3 no endereço 0x87FE da Memória Principal;

#### V. Carregar para R4 o operando da Memória Principal localizado no endereço contido no endereço armazenado em R7;

#### VI. Carregar para R5 o operando localizado no endereço da Memória Principal contido em R6;

#### VII. Subtrair os operandos localizados em R4 e R5 e armazene o resultado em R8;

#### VIII. Armazenar o operando localizado em R8 no endereço 0xA451 da Memória Principal.

### 2 - Determine e descreva o modo de endereçamento utilizado em cada uma das instruções que compõem o segmento de código gerado no exercício 1.

### 3 - Considerando o Exercício 1 e o Exercício 2, defina um formato de instruções e apresente a sequência de instruções (programa) em hexadecimal que represente as operações I à VIII.

### 4 - Utilizando a ordenação de bytes little-endian, preencha em hexadecimal o mapa de memória abaixo do seguinte bloco de declarações:

- char y1 = 0x01;
- char y2 = 0x02;
- char y3 = 0x03;
- short w1 = 0x0102;
- short w2 = 0x0403;
- short w3 = 0x0506;
- int x = 0x05060708;

| Endereço | Byte |
|----------|------|
| 0001h    |      |
| 0002h    |      |
| 0003h    |      |
| 0004h    |      |
| 0005h    |      |
| 0006h    |      |
| 0007h    |      |
| 0008h    |      |
| 0009h    |      |
| 000Ah    |      |
| 000Bh    |      |
| 000Ch    |      |
| 000Dh    |      |

### 5 - Considerando uma arquitetura alinhada, apresente o mapa de memória ótimo das declarações de dados do Exercício 3.

| Endereço | 
|----------|
| 0000h   |       
| 0004h   | 
| 0008h    |   
| 000Ch    |   
| 0010h    |   
| 0014h   |    
| 0018h    |   

**Bytes**
|   |   |   |   |
|---|---|---|---|
|   |   |   |   |
|   |   |   |   |
|   |   |   |   |
|   |   |   |   |
|   |   |   |   |
|   |   |   |   |
|   |   |   |   |

### 6 - Considerando as arquiteturas baseadas em pilha, acumulador, registrador-registrador e registrador- memória, descreva as ações prévias necessárias para realizar a subtração de dois elementos armazenados em memória.

### 7 - Sobre a Arquitetura de Von Neumann, considere as seguintes informações:

#### I. Dados e instruções são colocadas em memórias de leitura e escrita diferentes;
#### II. Comumente a execução de instruções ocorre de modo sequencial;
#### III. O conteúdo da memória é acessado sempre pela sua posição, independentemente do tipo de dado nela encontrado.
#### Estão corretas as informações:
##### a) I, II e III;
##### b) I e II;
##### c) II e III;
##### d) I e III.


## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!