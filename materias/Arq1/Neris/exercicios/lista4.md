# Lista de Exercícios 4

#### Professor
[![Neris](https://img.shields.io/badge/Luciano_Neris-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)](https://site.dc.ufscar.br/docente/5cee7e5d48365a001679f750)


## Arquitetura MIPS

### 1 - Defina os estados dos sinais de controle para a arquitetura monociclo referente a instrução add $s1,$s2, $s3.

|   Nome do Sinal   | add $s1, $s2, $s3 | 
|-------------------|-------------------|
| RegDst            |                   |
| OrigALU           |                   |
| MemtoReg          |                   |
| RegWrite          |                   |
| MemRead           |                   |
| MemWrite          |                   |
| Branch            |                   |
| ALUop1            |                   |
| ALUop0            |                   |
| Jump              |                   |


### 2 - Explique por que as operações de adição e subtração se repetem na coluna de operação na extrema direita da tabela abaixo.

![Tabela](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/Arq1/imagem_2024-03-14_164012274.png)


### 3 - Para que serve o circuito de extensão de sinal de 16 para 32 bits no MIPS?

### 4 - Para que serve o circuito de deslocamento de 2 no MIPS?

### 5 - Dado o circuito combinacional de controle do MIPS monociclo ilustrado pela Figura 1, verificar os valores dos sinais de controle para os opcodes:

#### a) 000000 (formato R) 
#### b) 100011 (lw) 
#### c) 101011 (sw) 
#### d) 000100 (beq)

![Dados](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/Arq1/imagem_2024-03-14_164242681.png)

### 6 - Por que é necessário o multiplexador RegDst, no fluxo de dados do MIPS monociclo?

### 7 - Por que é necessário o multiplexador OrigDado, no fluxo de dados do MIPS monociclo?

### 8 - Por que é necessário o multiplexador MemparaReg, no fluxo de dados do MIPS monociclo?

### 9 - Por que é necessário o multiplexador de desvio no fluxo de dados do MIPS monociclo?


## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!