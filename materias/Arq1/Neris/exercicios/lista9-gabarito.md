# Gabarito Lista de Exercícios 9

#### Professor
[![Neris](https://img.shields.io/badge/Luciano_Neris-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)](https://site.dc.ufscar.br/docente/5cee7e5d48365a001679f750)


## Desempenho

### Questão 1 

*desempenho_C1* = 1/*tempo.de.execC1* = 1/10 = 0,1 *programas / segundo*

*desempenho_C2* = 1/*tempo.de.execC2* = 1/15 = 0,066 *programas / segundo*

### Questão 2 

*taxa.de.clock* = 1/*tempo.de.ciclo* = 1/(*tempo.de.exec*/*num.de.ciclos*)= *num.de.ciclos*/*tempo.de.exec* = (20 × 10^6)/10 = 2 MHz

### Questão 3 

#### a) 

*tempo.de.ciclo* = 1/*taxa.de.clock* = 1/(500×10^6) = 2 × 10^−9 *segundos*

#### b)

6×10^6 *instruções da classe A, de 1 ciclo* = 6×10^6 *ciclos*
3×10^6 *instruções da classe B, de 2 ciclos* = 6×10^6 *ciclos*
2×10^6 *instruções da classeC, de 3 ciclos* = 6×10^6 *ciclos*

*Total de ciclos* = 18×10^6 *ciclos*

#### c)

*tempo.de.exec* = *num.de.ciclos* × *tempo.de.ciclo* = 18 × 10^6 × 2 × 10^−9 = 36×10^−3 *segundos*

#### d)

*CPI MÉDIO* = *num.de.ciclos*/*num.de.instruções* = (18 × 10^6)/(11×10^6) = 18/11 = 1,63

#### e)

*throughputMIPS* = *num.de.intruções*/(*tempo.de.exec* × 10^6) = (11 × 10^6)/(36 × 10^−3 × 10^6) = 11/36 × 10^3 = 305 *MIPS*

### Questão 4 

```
        sub $2, $2, $2 # 4 ciclos
loop1:  muli $14, $2, 4 # 4 x 10 x 106 ciclos
        add $3, $4, $14 # 4 x 10 x 106 ciclos
        sw $0, 0($3) # 4 x 10 x 106 ciclos
        addi $2, $2, 1 # 4 x 10 x 106 ciclos
        slt $7, $2, $6 # 4 x 10 x 106 ciclos
        bne $7, $0, loop1 # 3 x 10 x 106 ciclos
```

*total.de.ciclos* = 23×10^7 + 4 ciclos ∼ 23×10^7 ciclos

*tempo.de.exec* = 23×10^7 × 1/10^9 = 23 × 10^− 2

*desempenho* = 1/*tempo.de.exec* = 1/23 × 10^−2 = 10^2/23 = 4,34 programas/s

### Questão 5 

#### a)
| T1 | T2  |
|----|-----|
| 60 |  40 |

T = 100

| T1 |   T2  |
|----|-------|
| 60 |  40/2 |

T' = 80

#### b)
f = 40/100 -> 0,4
S = 40/20 -> 2

1 / (1 - 0,4 + 0,4 /2) -> 1,25 vezes

### Questão 6

| T1 | T2 |
|----|----|
| 5  |  5 |

T = 10

| T1 |  T2  |
|----|------|
| 5  |  5/5 |

T’ = 6

f = 5/10 -> 0,5
S = 5/1 -> 5

1 / (1 – 0,5 + 0,5 /5) -> 1,66 vezes

## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!