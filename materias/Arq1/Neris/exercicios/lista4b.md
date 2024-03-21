# Lista de Exercícios 4b

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


### 2 - Dado o diagrama de estado da unidade de controle do MIPS multiciclo, Figura 1, e o respectivo fluxo de dados, Figura 2, analisar os estados percorridos pelo processador para a execução da instrução lw, e em função dos sinais de controle dos estados, responder:

#### a) quais são os operandos da ULA e qual é a operação aritmética no estado 2

#### b) qual é o dado a ser escrito no registrador, no estado 4?

![Figura1](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/Arq1/imagem_2024-03-14_165436578.png)

![Figura2](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/Arq1/imagem_2024-03-14_165516329.png)


### 3 - Para implementar uma instrução addi, no MIPS multiciclo, lembrando-se que essa instrução tem um formato tipo I, conforme mostrado abaixo, descrever os estados a serem adicionados, as operações realizadas nesses estados, e os respectivos sinais de controle necessários, levando-se em consideração o diagrama da Figura 2.

|   opcode   | rs | rd | 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 | 
|------------|----|----|---------------------------------|

## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!