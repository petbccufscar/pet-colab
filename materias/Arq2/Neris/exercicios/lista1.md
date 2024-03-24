# Lista de Exercícios 1

#### Professor
[![Neris](https://img.shields.io/badge/Luciano_Neris-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)](https://site.dc.ufscar.br/docente/5cee7e5d48365a001679f750)

## Exercícios de Arq1

### 1. Quantos bits são utilizados em cada um dos tipos abaixo?
    a) word
    b) doubleword
    c) quadword
    d) double quadword
   
### 2. Qual é a quantidade mínima de bits necessária para representar em binário cada um dos números decimais sem sinal abaixo?
    a) 4095
    b) 65534
    c) 42319
    
### 3. Converta os números inteiros não sinalizados abaixo em números decimais.
    a) 3A16
    b) 1BF16
    c) 100116
  
### 4. Apresente, em hexadecimal, o resultado das operações abaixo envolvendo números inteiros não sinalizados na base 16.
    a) 6B4 + 3FE
    b) A49 + 6BD
    c) 7C4 + 3BE
    d) B69 + 7AD
   
### 5. Apresente 4 flags de status da CPU.
   
### 6. Quais registradores de 32 bits são utilizados para a manipulação da pilha?
   
### 7. Qual é a flag contida no registrador de status da CPU capaz de indicar que o resultado de uma operação aritmética de números não sinalizados é maior do que a capacidade do destino?
   
### 8. O conjunto de instruções contido no processador Intel Itanium é completamente diferente do conjunto de instruções da arquitetura x86?
   
### 9. Por que o termo “linguagem assembler” está incorreto?

### 10. Defina constantes simbólicas que represente o inteiro 25 em decimal, binário e hexadecimal.

### 11. Declare um array de 20 bytes sem sinal e inicialize todos os seus elementos com 0.

### 12. Declare uma string contento o texto “Teste” repetido 500 vezes.

### 13. Declare uma string contendo o seu nome inicializando-a como uma string terminada por caractere nulo.

### 14. Declare um array não inicializado de 120 words.

### 15. Apresente os bytes do número 456789ABh utilizando a ordenação little-endian.

### 16. Quantas páginas de espaço de endereçamento virtual existem em uma máquina com espaço de endereço virtual de 32 bits endereçável por byte utilizando 4KiB de tamanho de página?

### 17. Sabendo que um programa esta sendo executado em um processador x86 no modo real e que o registrador de segmento DS contem o valor 028Fh calcule os endereços físicos da variáveis abaixo:
    a) A = 0030h
    b) B = 0000h
    c) C = 0430h

### 18. No modo protegido os registradores de segmento atuam com seletores ou índices de tabelas que descrevem os seguimentos. Utilizando a tabela simplificada de descritores abaixo, obtenha os endereços virtuais dos seguintes endereços lógicos:
    a) DS = 0x0008 Offset = 0x00000002
    b) DS = 0x0009 Offset = 0x00000003
    c) DS = 0x0010 Offset = 0x00000003
    d) DS = 0x0011 Offset = 0x00000004

![Imagem 1](https://github.com/petbccufscar/.github/raw/main/pet-colab/Arq2/lista1_ex18.png)

### 19. Mostrar o conteúdo da memória na área de dados definida pelas sentenças:

![Imagem 2](https://github.com/petbccufscar/.github/raw/main/pet-colab/Arq2/lista1_ex19.png)

### 20. Apresente os valores contidos nas constantes tamanho1, tamanho2, tamanho3 do trecho de código assembly abaixo.

![Imagem 3](https://github.com/petbccufscar/.github/raw/main/pet-colab/Arq2/lista1_ex20.png)

### 21. Utilizando a tabela abaixo, codifique em hexadecimal as seguintes instruções para a arquitetura IA-32:
    a) mov ah,0x5
    b) mov ax,0x5
    c) mov eax,0x5
    d) mov ecx,0x5

![Imagem 4](https://github.com/petbccufscar/.github/raw/main/pet-colab/Arq2/lista1_ex21.png)

### 22. Utilizando a tabela abaixo, codifique em hexadecimal as seguintes instruções de movimentação de dados para a arquitetura IA-32:
    a) mov ax,dx
    b) mov al,dl
    c) mov cx,dx
    d) mov cl,dl
    e) mov [eax], 01020304h
    f) mov [ecx], eax

![Imagem 5](https://github.com/petbccufscar/.github/raw/main/pet-colab/Arq2/lista1_ex22.png)


## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!
