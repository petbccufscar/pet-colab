# Lista de Exercícios 3

#### Professor
[![Neris](https://img.shields.io/badge/Luciano_Neris-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)](https://site.dc.ufscar.br/docente/5cee7e5d48365a001679f750)


## Arquitetura MIPS

### 1 - Considerando o loop escrito em linguagem de alto nível:
```
while (save[i] == k)
    i = i + j;
```
#### e supondo que i, j e k correspondam as variáveis $s3, $s4 e $s5, e que o endereço inicial do array save esteja armazenado em $s6, qual o código em linguagem de montagem para a arquitetura MIPS correspondente a este trecho de código?

### 2 - Os números abaixo se encontram na representação de Complemento de Dois. Efetue as seguintes operações:

```
a. 111000 – 110011
b. 11001100 – 101110
c. 01101111 + 01100010
d. 111100001111 – 110011110011
e. 11000011 – 11101000
f. 11010010 – 01111101
```

### 3 - Supondo que o registrador $t4 da ISA MIPS contém a constante 100, gere um trecho de código MIPS que multiplique a constante anterior por um valor armazenado no registrador $t2 e verifique a ocorrência de overflow.

### 4 - Utilizando a representação do hardware de multiplicação ilustrado abaixo, apresente uma tabela contendo as iterações e os passos realizados em cada iteração da multiplicação dos números de 4 bits 01102 e 00112

![hardware](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/Arq1/imagem_2024-03-14_162404803.png)

### 5 - Escrever um programa em Assembly do MIPS que imprime os 10 primeiros elementos da série de Fibonacci (0, 1, 1, 2, 3, 5 ...).

### 6 - Dado o circuito da ULA de 1 bit abaixo, como seria possível selecionar a execução de uma operação XOR entre a e b, sem alterar o circuito? Nota-se que essa operação XOR é apenas para a ULA de 1 bit, portanto não precisa funcionar quando se encadeia 32 ULAs de 1 bit.

![Circuito](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/Arq1/imagem_2024-03-14_162532153.png)

## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!