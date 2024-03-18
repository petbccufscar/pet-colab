# Gabarito Lista de Exercícios 6

#### Professor
[![Neris](https://img.shields.io/badge/Luciano_Neris-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)](https://site.dc.ufscar.br/docente/5cee7e5d48365a001679f750)


## Arquitetura MIPS

### Questão 1 

![Resposta1](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/Arq1/imagem_2024-03-18_174737704.png)

### Questão 2 

![Resposta2](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/Arq1/imagem_2024-03-18_174753255.png)

### Questão 3 

![Resposta3](https://github.com/petbccufscar/.github/blob/main/pet-colab/Arq1/imagem_2024-03-18_174814060.png)

### Questão 4

A instrução add $5, $2, $4 depende da instrução sub $2, $4, $6 – no registrador $2.
Solução: antecipação.

A instrução or $7, $2, $8 depende da instrução sub $2, $4, $6 – no registrador $2.
Solução: antecipação.

A instrução lw $9, 10($7) depende da instrução or $7, $2, $8 – no registrador $7.
Solução: antecipação.

A instrução sw $7, 10( $5) depende da instrução or $7, $2, $8 – no registrador $7.
Solução: antecipação – observando que esse circuito de antecipação não é o mesmo
circuito de antecipação colocado no estágio EX, e sim, um circuito que deve ser colocado
no estágio M.

### Questão 5

#### I.

![Resposta5_1](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/Arq1/imagem_2024-03-18_174832093.png)

#### II.

![Resposta5_2](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/Arq1/imagem_2024-03-18_174841465.png)

#### III.

![Resposta5_3](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/Arq1/imagem_2024-03-18_174857066.png)

## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!