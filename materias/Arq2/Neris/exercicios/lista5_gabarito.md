# Gabarito Lista de Exercícios 5

#### Professor
[![Neris](https://img.shields.io/badge/Luciano_Neris-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)](https://site.dc.ufscar.br/docente/5cee7e5d48365a001679f750)

## Exercícios de Arq1

### 1.
    (a) 6Ah (b) EAh (c) FDh (d) A9h

### 2.
    (a) 9Ah (b) 6Ah (c) 0A9h (d) 3Ah

### 3.
    shr al,1     ; shift AL into Carry flag
    jnc next     ; Carry flag set?
    or al,80h    ; yes: set highest bit
    next:        ; no: do nothing

### 4.
    shl eax,4

### 5.
    ror dl,4 (or: rol dl,4)

## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!
