# Lista de exercícios 3

#### Professor
[![Marilde](https://img.shields.io/badge/Marilde_Santos-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)](https://site.dc.ufscar.br/docente/5cee7e5d48365a001679f750)

## Exercícios de Normalização

### 1. Dê o conjunto de DFs para o esquema R(A,B,C,D) com chave primaria AB sob as quais R esta na 1FN mas não na 2FN.

### 2. Dê o conjunto de DFs para o esquema R(A,B,C,D) com chave primaria AB sob as quais R esta na 2FN mas não na 3FN.

### 3. Considere o esquema de relação R(A,B,C), o qual possui a DF BàC. Se A é uma chave candidata para R, é possível para R estar na FNBC? Se sim, sob que condições? Se não, por que não?

### 4. Considere o esquema de relação R(A,B,C,D,E). Dadas as seguintes DFs: AàB, BCàE e EDàA.
    a) liste todas as chaves para R
    b) R esta na 3FN?
    c) R esta na FNBC?

### 5. Considere a seguinte coleção de relações e dependências. Assuma que cada relação i obtida por decomposição a partir de uma relação com atributos ABCDEFGHI e são listadas para cada questão. (As questões são independentes uma vez que as dependências dadas sobre ABCDEFGHI são distintas). Para cada (sub) relação: (5.1) estabeleça a forma normal mais alta na qual a relação está. (5.2) Se a relação não estiver na FNBC, decomponha-a em uma coleção de relações na FNBC.
    a) R1(A,C,B,D,E) AàB, CàD
    b) R2(A,B,F) ACàE, BàF (vou verificar!)
    c) R3(D,C,H,G) DàG, GàH

### 6. Suponha que tenhamos as seguintes 3 tuplas em instância legal do esquema S que possui 3 atributos ABC (listados em ordem): (1,2,3), (4,2,3) e (5,3,3).
    a) Quais das seguintes dependências você pode inferir não ser mantido
    sobre o esquema S? 
        (a1) AàB (a2) BCàA (a3) BàC
    b) Identifique algumas (outras) DFs que são mantidas sobre S.

### 7. Suponha que dada a relação R(ABCD). Para cada um dos seguintes conjuntos de DFs, assumindo que elas são as únicas dependências mantidas sobre R, faça o seguinte: (7.1) Identifique as chaves candidatas para R. (7.2) Estabeleça se a decomposição proposta de R em relações menores é uma boa decomposição e explane brevemente o por quê sim ou o por quê não.
    a) BàC, DàA; decomposta em BC e AD
    b) ABàC, CàA, CàD; decomposta em ACD e BC
    c) AàBC, CàAD; decomposta em ABC e AD

## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!