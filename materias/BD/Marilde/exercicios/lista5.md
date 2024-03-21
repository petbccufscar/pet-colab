# Lista de exercícios 5

#### Professor
[![Marilde](https://img.shields.io/badge/Marilde_Santos-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)](https://site.dc.ufscar.br/docente/5cee7e5d48365a001679f750)

## Exercícios Transações 

### Suponha duas transações T1 e T2:
```
BEGIN TRANSACTION T1
UPDATE Banco
SET Saldo = ((SELECT Saldo FROM Banco WHERE Conta = 10) – 100)
WHERE Conta = 10
UPDATE Banco
SET Saldo = ((SELECT Saldo FROM Banco WHERE Conta = 20) + 100)
WHERE Conta = 20
COMMIT TRANSACTION T1
```

```
BEGIN TRANSACTION T2
UPDATE Banco
SET Saldo = ((SELECT Saldo FROM Banco WHERE Conta = 20) – 200)
WHERE Conta = 20
UPDATE Banco
SET Saldo = ((SELECT Saldo FROM Banco WHERE Conta = 30) + 200)
WHERE Conta = 30
COMMIT TRANSACTION T2
```

### 1. As instruções de leitura e escrita dos dados da transação T1, obtidas a partir da SQL, são as seguintes:

```
READ Conta 10
WRITE Conta 10
READ Conta 20
WRITE Conta 20
```
Seguindo o exemplo acima, obtenha as instruções de leitura e escrita dos
dados da transação T2.

### 2. Determine as possíveis escalas de execução (schedules) concorrente serializáveis em conflito e/ou em visão.

### 3. Suponha uma nova transação T3 concorrente com T1 e T2:

```
BEGIN TRANSACTION T3
UPDATE Banco
SET Saldo = ((SELECT Saldo FROM Banco WHERE Conta = 30) – 200)
WHERE Conta = 30
UPDATE Banco
SET Saldo = ((SELECT Saldo FROM Banco WHERE Conta = 10) + 200)
WHERE Conta = 10
COMMIT TRANSACTION T3
```

    a. Obtenha as instruções de leitura e escrita dos dados da transação T3;

    b. Determine as possíveis escalas de execução (schedules)
    concorrente serializáveis em conflito e/ou em visão, considerando
    T1, T2 e T3.

### 4. Verifique se o schedule abaixo:

| T5       | T6       | T7       |
|----------|----------|----------|
| Read(A)  |          |          |
|          |  Read(A) |          |
|Write(B)  |          |          |
|          |Write(A)  |          |
|          |          |Read(B)   |
|          |          |Write(A)  |

    a) É serializável em conflito? Explique o por quê.  
    b) É serializável em view? Explique o por quê.

## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!