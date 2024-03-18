# Gabarito Lista de Exercícios 7

#### Professor
[![Neris](https://img.shields.io/badge/Luciano_Neris-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)](https://site.dc.ufscar.br/docente/5cee7e5d48365a001679f750)


## Números Binarios 

### Questão 1 

```
1 10000000 11000000000000000000000
Sinal (1 bit) = 1
Expoente (8 bits) = 10000000
Significando (23 bits) = 11000000000000000000000
O valor do número em binário é obtido usando a equação:
Valor em binário = (-1)sinal x (1+ significando) x 2 expoente - bias
O expoente é polarizado, portanto devemos subtrair o bias = 127
expoente = 10000000 = 128
expoente - bias = 128 – 127 = 1
O significando tem um bit implícito à esquerda da parte fracionária portanto
1 + significando = 1 + 0,11000000000000000000000 = 1,11000000000000000000000
Portanto,
Valor em binário = (-1) 1 x 1,11000000000000000000000 x 21
    = (-1) x 1,11000000000000000000000 x 2
    = (-1) x 11,1000000000000000000000
E o valor em decimal é obtido fazendo a conversão:
    (-1) x (1x21 + 1x20 + 1x2-1 + 0x2-2+ 0x2-3+ ...)
    = (-1) x (1x2 + 1x1 + 1x 0.5 + 0 + 0 + ...)
    = (-1) x (2 + 1 + 0.5 + 0 + 0 + ...) = (-1) x 3,5 = -3,5
```

### Questão 2 

4,25

### Questão 3 

4,75

### Questão 4

```
3,75 = 2 + 1 + 0,5 + 0,25 = 21 + 20 + 2-1 + 2-2 = 11,11 = 21 x 1,111 (normalização)
Temos então:
Sinal: 0 (positivo)
Expoente: 10000000 (polarizado, 1 + 127 = 128)
Significando: 11100000000000000000000 (remove-se o 1 depois da vírgula, pois está implícito)
01000000011100000000000000000000
```

### Questão 5

```
11000000111010000000000000000000
```

## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!