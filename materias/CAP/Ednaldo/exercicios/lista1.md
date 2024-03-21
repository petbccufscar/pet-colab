# Lista de Exercícios 1

#### Professor
[![Ednaldo](https://img.shields.io/badge/Ednaldo_Pizzolato-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)](https://site.dc.ufscar.br/docente/5cee7e5d48365a001679f750)


## Conceitos Básicos

### 1 - Construa um algoritmo que, tendo como dados de entrada dois pontos quaisquer no plano, P(x1,y1) e P(x2,y2), escreva a distância entre eles.

### 2 - Faça um algoritmo que leia o tempo de duração de um vídeo expresso em segundos e mostre-o expresso em horas, minutos e segundos.

### 3 - O custo ao consumidor de um carro novo é a soma do custo de fábrica com a percentagem do distribuidor e dos impostos (aplicados ao custo de fábrica). Supondo que a percentagem do distribuidor seja de 28% e os impostos de 45%, escrever um algoritmo que leia o custo de fábrica de um carro e escreva o custo ao consumidor.

### 4 - Elabore um algoritmo que, dada a idade de um nadador, classifique-o em uma das seguintes categorias:

| Categoria   | Faixa etária |
|-------------|--------------|
| Infantil A  | 5 a 7 anos   |
| Infantil B  | 8 a 10 anos  |
| Juvenil A   | 11 a 13 anos |
| Juvenil B   | 14 a 17 anos |
| Adulto      | Maires de 18 anos |

### 5 - Tendo como dados de entrada a altura e o sexo de uma pessoa (M masculino e F feminino), construa um algoritmo que calcule seu peso ideal, utilizando as seguintes fórmulas:

- para homens: (72.7*h)-58
- para mulheres: (62.1*h)-44.7

### 6 - Um banco concederá um crédito especial aos seus clientes de acordo com o saldo médio no último ano. Faça um algoritmo que leia o saldo médio de um cliente e calcule o valor do crédito de acordo com a tabela abaixo. Mostre uma mensagem informando o saldo médio e o valor do crédito disponível.

| Saldo médio                     | Crédito disponível |
|---------------------------------|--------------------|
| Até R$ 3.000,00                 | Sem crédito        |
| De R$ 3.000,01 a R$ 8.000,00    | 20% do valor médio |
| De R$ 8.000,01 a R$ 12.000,00   | 30% do valor médio |
| Acima de R$ 12.000,00           | 40% do valor médio (limitado ao máximo de R$ 8.000,00)|


### 7 - Elabore um algoritmo que leia 4 valores, sendo que o primeiro deles indicará como os outros três serão apresentados ao usuário. Se o primeiro valor for 1, então os outros 3 devem ser escritos em ordem crescente; se for 2, deve ser escrito em ordem decrescente; se for 3, o maior deve ser escrito no meio dos outros dois.

### 8 - Escrever um algoritmo que leia o RA de um(a) aluno(a), as 3 notas de provas desse(a) aluno(a) e a média dos exercícios. O cálculo da média final deve ser feito de acordo com a seguinte fórmula:

```
MF = (Nota1 + Nota2 x 2 + Nota3 x 3 + ME )/7
```

#### O(a) aluno(a) é considerado aprovado se o conceito obtido for A, B ou C. Caso o conceito seja D ou E, será considerado(a) reprovado(a). A tabela a seguir apresenta as faixas de notas e os respectivos conceitos. O algoritmo deverá apresentar o RA do(a) aluno(a), a média final e o conceito obtido seguido pela mensagem APROVADO ou REPROVADO de acordo com os critérios apresentados.

| Média                    | Conceito |
|--------------------------|----------|
| Maior ou igual a 9.0     | A        |
| Entre 7.5 e 8.9          | B        |
| Entre 6.0 e 7.4          | C        |
| Entre 4.0 e 5.9          | D        |
| Inferior a 4.0           | E        |


### 9 - Faça um algoritmo que leia os valores de COMPRIMENTO, LARGURA e ALTURA e apresente o valor do volume de uma caixa retangular. Utilize para o cálculo a fórmula VOLUME = COMPRIMENTO x LARGURA x ALTURA.

### 10 - Leia um valor de cinco algarismos e gere o digito verificador (DigitoV) para o mesmo. Supondo que os cinco algarismos do código são ABCDE, uma forma de calcular o dígito desejado, com módulo 7 é: DigitoV = resto da divisão de S por 7, onde:

```
S = 6 x A + 5 x B + 4 x C + 3 x D + 2 x E
```

### 11 - Dado um número de três algarismos N = CDU (onde C é o algarismo das centenas, D é o algarismo das dezenas e U o algarismo das unidades), considere o número M constituído pelos algarismos de N em ordem inversa, isto é, M = UDC. Gerar M a partir de N (p.ex.: N = 123 -> M = 321).

### 12 - Suponha que uma escola utilize, como código de matrícula, um número inteiro no formato AASDDD, onde os dois primeiros dígitos, representados pela letra A, são os dois últimos algarismos do ano da matrícula; o terceiro dígito, representado pela letra S, vale 1 ou 2, conforme o(a) aluno(a) tenha se matriculado no 1o ou 2o semestre; os quatro últimos dígitos, representados pela letra D, correspondem à ordem da matrícula do aluno(a), no semestre e no ano em questão. Crie um algoritmo que leia o número de matrícula de um(a) aluno(a) e imprima o ano e o semestre em que ele foi matriculado(a).

### 13 - Crie um algoritmo chamado Zodiaco. Este algoritmo deve ler a data do aniversário de uma pessoa e informar a qual signo essa pessoa pertence, de acordo com a tabela a seguir:

| Datas                          | Signo       |
|--------------------------------|-------------|
| 21/janeiro a 19/fevereiro      | Aquário     |
| 20/fevereiro a 20/março        | Peixes      |
| 21/março e 20/abril            | Peixes      |
| 21/abril a 20/maio             | Áries       |
| 21/maio a 20/junho             | Gêmeos      |
| 21/junho a 21/julho            | Câncer      |
| 22/julho a 22/agosto           | Leão        |
| 23/agosto a 22/setembro        | Virgem      |
| 23/setembro a 22/outubro       | Libra       |
| 23/outubro a 21/novembro       | Escorpião   |
| 22/novembro a 21/dezembro      | Sagitário   |
| 22/dezembro a 20/janeiro       | Capricórnio |

### 14 - Elaborar um algoritmo para imprimir o número de dias de um dado mês e ano. Anos bissextos deverão ser tratados convenientemente. Dica: Anos bissextos são múltiplos de 4 e não são múltiplos de 100, exceto os anos múltiplos de 400, que também são bissextos.

### 15 - Faça um algoritmo que leia a primeira letra do estado civil de uma pessoa e mostre uma mensagem com a sua descrição (Solteiro, Casado, Viúvo, Divorciado, Desquitado). Mostre uma mensagem de erro, se necessário.

### 16 - Construa um algoritmo que leia um conjunto de 50 valores inteiros e informe a soma dos números positivos e a quantidade de números negativos.

### 17 - Faça um algoritmo que leia um número inteiro N e calcule o valor de A, dado por:

```
A = N + (N − 1)/2 + (N − 2)/3 + ⋯ + 1/N
```

### 18 - Uma rainha requisitou os serviços de um monge e disse-lhe que pagaria qualquer preço. O monge, necessitando de alimentos, indagou à rainha sobre o pagamento, se poderia ser feito com grãos de trigo dispostos em um tabuleiro de xadrez (que possui 64 casas), de tal forma que o primeiro quadro deveria conter apenas um grão e os quadros subsequentes, o dobro do quadro anterior. Crie um algoritmo para calcular o total de grãos que o monge recebeu.

### 19 - Para uma turma de 45 alunos, construa um algoritmo que determine: 

#### a) A idade média dos alunos com menos de 1,70m de altura; 
#### b) A altura média dos alunos com mais de 20 anos.

### 20 - Escreva um algoritmo que calcule o produto dos inteiros ímpares de 1 a 15 e, então, exiba os resultados.

### 21 - Escreva um algoritmo que calcule os quadrados e cubos dos números de 0 a 10 e imprima os valores resultantes no formato de tabela a seguir:

| Valor X | X2   | X3   |
|---------|------|------|
| 1       | 1    | 1    |
| 2       | 4    | 8    |
| 3       | 9    | 27   |
| 4       | 16   | 64   |
| ...     |      |      |
| 10      | 100  | 1000 |


### 22 - Elabore um algoritmo que calcule o fatorial de um número e apresente o resultado na tela. Para este problema, tem-se como entrada o valor do número do qual se deseja calcular o fatorial (N). O fatorial de 0 é igual a 1 (por definição). O fatorial de um número N (representado por N!) é obtido através do seguinte cálculo: N! = 1 x 2 x 3 x 4x ... x (N-1) x N.

### 23 - Um determinado material radioativo perde metade de sua massa a cada 50 segundos. Dada a massa inicial, em gramas, faça um algoritmo que calcule (e escreva, claro) o tempo necessário para que essa massa se torne menor que 0,05 gramas.

### 24 - Faça um algoritmo que leia um conjunto de números (X) e imprima sua soma (Soma) e sua média (Media). Assuma que o valor 9999 atue como sentinela, ou seja, quando ele for digitado pelo usuário, isso implicará no fim de leitura e as respostas devem ser apresentadas ao usuário. Ex.: 1, 2, 3, 9999  Soma=6 e Media=2

### 25 - Crie um algoritmo que peça o nome, a altura e o peso de várias pessoas e apresente o nome e peso da mais pesada e o nome e altura da mais alta. Assuma que o nome XXXX encerra o processo de leitura.

### 26 - Faça um algoritmo que leia um número inteiro N e mostre o maior quadrado menor ou igual a N. Por exemplo, se N for igual a 38, o maior quadrado menor que ou igual a 38 é 36 (quadrado de 6).

### 27 - Foi realizada uma pesquisa de algumas características físicas da população de uma certa região, considerando os seguintes dados referentes a cada habitante para serem analisados:

- sexo (masculino e feminino)
- cor dos olhos (azuis, verdes, castanhos)
- cor do cabelos (louros, castanhos, pretos)
- idade

#### Faça um algoritmo que determine e escreva:

#### a) a maior idade dos habitantes;
#### b) a quantidade de indivíduos do sexo feminino cuja idade está entre 18 e 35 anos, inclusive;
#### c) a quantidade de indivíduos que tenham olhos verdes e cabelos louros;

#### Como não se sabia o total de pessoas que seriam pesquisadas, assumiu-se que o processo de coleta de dados terminaria quando o valor -1 fosse apresentado como idade.

### 28 - Provavelmente você já se perguntou como o computador calcula funções como seno e cosseno. Programas antigos usavam tabelas armazenadas na memória, isto é, para um determinado ângulo existia um valor pré-determinado para uma função trigonométrica associada ao mesmo. Nos dias de hoje o que se faz é calcular o valor. Matematicamente pode ser mostrado que seno(x), por exemplo, é a soma de uma série infinita (chamada de série de Taylor) como especificada a seguir:

![Serie de Taylor](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/CAP/imagem_2024-03-19_232206030.png)

### 29 - Um matemático resolveu apresentar uma equação da qual poder-se-ia calcular o valor de Pi. A partir da fórmula, apresentada a seguir, faça um algoritmo que imprima o valor de Pi. Lembre-se que você não poderá calcular a série infinita e, portanto, deverá obter um valor aproximado.

![Valor de Pi](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/CAP/imagem_2024-03-19_232359532.png)

### 30 - Faça um algoritmo que leia um número N e divida-o por dois (sucessivamente) até que o resultado seja menor que 1. Mostre o resultado da ultima divisão e a quantidade de divisões efetuadas.

## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!