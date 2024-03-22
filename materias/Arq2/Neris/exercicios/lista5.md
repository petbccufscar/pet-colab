# Lista de Exercícios 5

#### Professor
[![Neris](https://img.shields.io/badge/Luciano_Neris-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)](https://site.dc.ufscar.br/docente/5cee7e5d48365a001679f750)

## Exercícios de Arq1

### 1. Apresente os valores de AL nos pontos indicados.
    mov al,0D4h
    shr al,1    ; a)
    mov al,0D4h
    sar al,1    ; b)
    mov al,0D4h
    sar al,4    ; c)
    mov al,0D4h
    rol al,1    ; d)

### 2. Apresente os valores de AL nos pontos indicados.
    mov al,0D4h
    ror al,3    ; a)
    mov al,0D4h
    rol al,7    ; b)
    stc
    mov al,0D4h
    rcl al,1    ; c)
    stc
    mov al,0D4h
    rcr al,3    ; d)

### 3. Supondo que não existam instruções rotate na arquitetura IA-32, apresente um trecho de código que utilize a instrução SHR e jumps condicionais para rotacionar o conteúdo do registrador AL 1 bit para a direita.

### 4. Escreva uma instrução que multiplique o conteúdo do registrador EAX por 16 utilizando instruções de deslocamento.

### 5. Escreva uma única instrução de rotação capaz de trocar de posição os 4 bits MSB e LSB do registrador DL.

## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!
