# Lista de Exercícios 1

#### Professor
[![Neris](https://img.shields.io/badge/Luciano_Neris-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)](https://site.dc.ufscar.br/docente/5cee7e5d48365a001679f750)


## Conceitos Básicos

### Questão 1

LOAD R1, #5
LOAD R2, (0xA4B7)
ADD R3, R1, R2
STORE R3, (0x87FE)
LOAD R4, @(R7)
LOAD R5, (R6)
SUB R8, R4, R5
STORE R8, (0xA451)

### Questão 2 

1. Imediato;
2. Direto;
3. Via registrador;
4. Direto;
5. Indireto via memória;
6. Indireto via registrador;
7. Via registrador;
8. Direto.

### Questão 3 

Considerando 8 modos de endereçamento (0 a 7), 4 ações (LOAD - 00, STORE-01, ADD-10 e SUB-11), endereços de 16 bits e 8 registradores (0 a 7) podemos definir 2 bis para a operação, 3 bits para o modo de endereçamento, 3 bits para o código do registrador e 2 formatos de instrução: A e B.

**A (LOAD e STORE)**
| OP     | MODO   | REG1   | REG2   | END/IMEDIATO |
|--------|--------|--------|--------|--------------|
| 2 bits | 3 bits | 3 bits | 3 bits | 16 bits      |

**B (ADD e SUB)**
| OP     | MODO   | REG1   | REG2   | REG3   | UNUSED  |
|--------|--------|--------|--------|--------|---------|
| 2 bits | 3 bits | 3 bits | 3 bits | 3 bits | 12 bits |

```
00 000 000 000 0000000000000101
00 001 001 000 1010010010110111
10 010 010 000 001 000000000000
01 011 010 000 1000011111111110
00 100 011 110 0000000000000000
00 101 100 101 0000000000000000
11 111 011 100 101 000000000000
01 111 111 000 1010010001010001
```

### Questão 4 

| Endereço | Byte     |
|----------|----------|
| 0001h    | 0x01     |
| 0002h    | 0x02     |
| 0003h    | 0x03     |
| 0004h    | 0x02     |
| 0005h    | 0x01     |
| 0006h    | 0x03     |
| 0007h    | 0x04     |
| 0008h    | 0x06     |
| 0009h    | 0x05     |
| 000Ah    | 0x08     |
| 000Bh    | 0x07     |
| 000Ch    | 0x06     |
| 000Dh    | 0x05     |

### Questão 5 

| Endereço | 
|----------|
| 0000h    |       
| 0004h    | 
| 0008h    |   
| 000Ch    |   
| 0010h    |   
| 0014h    |    
| 0018h    |   

**Bytes**
|     |     |     |     |
|-----|-----|-----|-----|
| 01  | 02  | 03  |     |
| 02  | 01  | 03  | 04  |
| 06  | 05  |     |     |
| 08  | 07  | 06  | 05  |


### Questão 6 

Pilha: os dois operandos devem ser empilhados previamente.
Acumulador: um dos operandos deve ser carregado previamente no registrador AC.
Reg-Reg: nenhuma ação é necessária, pois todos os operandos são informados na instrução.
Reg-Mem: nenhuma ação é necessária, pois todos os operandos são informados na instrução.

### Questão 7 

##### c) II e III;


## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!