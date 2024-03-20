# Lista de Exercícios 4

#### Professor
[![Ednaldo](https://img.shields.io/badge/Ednaldo_Pizzolato-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)](https://site.dc.ufscar.br/docente/5cee7e5d48365a001679f750)

## Lista preparatória para a prova 4

### 1 - Determine os valores das variáveis após a execução dos trechos de programas.

#### a)
```
void main()
{
    int a, b, *c;
    a = 3; b = 4; c = &a;
    b++;
    *c = a + 2;
    printf(”%d %d”,a,b);
}
```

#### b)
```
void main()
{
    int a, b, *c;
    a = 4; b = 3; c = &a;
    *c = *c + 1;
    c = &b;
    b = b + 4;
    printf(“ %d %d %d”, a, b, *c);
}
```

#### c)
```
void main()
{
    int a, b, *c, *d, *f;
    a = 4; b = 3; c = &a; d = &b;
    *c /= 2; f = c; c = d; d = f;
    printf(“%d %d”,*c, *d);
}
```

### 2 - Faça uma função em C que receba uma cadeia de caracteres e um caractere e, caso o caractere ocorra na cadeia de caracteres, remover todas as ocorrências dele da cadeia.

### 3 - Faça uma função em C que receba uma cadeira de caracteres e retorne um ponteiro para a primeira ocorrência de um espaço em branco na cadeia.

### 4 - Faça uma função em C que receba um valor e informe se ele é perfeito ou não.

### 5 - Faça uma função recursiva em C para cálculo do fatorial.

### 6 - Apresente um outro problema que pode ser resolvido com uso de recursividade. Apresente a solução do problema usando linguagem C.

### 7 - Faça uma função em C que receba uma matriz de inteiros 10 x 10 e retorne a soma de todos os elementos que estão acima da diagonal principal.

### 8 - Faça um programa em C que receba o nome de um arquivo texto para ser aberto. O arquivo tem várias linhas (não se sabe quantas) com até 100 caracteres cada. O objetivo do programa é modificar esse arquivo substituindo as vogais por *.


### 9 - Faça um programa em C que permita que o usuário informe nomes completos de amigos, bem como o telefone fixo e o celular de cada um e grave as informações sobre cada contato em uma linha de arquivo. Faça de tal forma que se o programa for executado uma segunda ou terceira vez, os dados armazenados anteriormente não são perdidos e novos contatos são armazenados no final do arquivo.

### 10 - Faça um programa em C que procure pelo nome de um amigo e informe seus dados de contato.

### 11 - Se você resolveu os dois exercícios anteriores com arquivos texto, faça agora com arquivos binários.

### 12 - Faça um programa que leia um arquivo que contenha as dimensões de uma matriz (linha e coluna), a quantidade de posições que serão anuladas, e as posições a serem anuladas (linha e coluna). O programa lê esse arquivo e, em seguida, produz um novo arquivo com a matriz com as dimensões dadas no arquivo lido, e todas as posições especificadas no arquivo ZERADAS e o restante recebendo o valor 1.

#### Exemplo 
```
Ex: arquivo “matriz.txt”
3 3 2 /*3 e 3 dimensões da matriz e 2 posições que serão anuladas*/
1 0
1 2 /*Posições da matriz que serão anuladas. arquivo “matriz saida.txt” será:
1 1 1
0 1 0
1 1 1
```

### 13 - Faça um programa gerenciar uma agenda de contatos. Para cada contato armazene o nome, o telefone e o aniversário (dia e mês). O programa deve permitir: (a) inserir contato; (b) remover contato; (c) pesquisar um contato pelo nome; (d) listar todos os contatos; (e) listar os contatos cujo nome inicia com uma dada letra; e (f) imprimir os aniversariantes do mês.

### 14 - Faça um programa gerenciar uma agenda de contatos. Para cada contato armazene o nome, o telefone e o aniversário (dia e mês). O programa deve permitir: (a) inserir contato; (b) remover contato; (c) pesquisar um contato pelo nome; (d) listar todos os contatos; (e) listar os contatos cujo nome inicia com uma dada letra; e (f) imprimir os aniversariantes do mês.

### 15 - Faça um programa que receba como entrada o nome de um arquivo de entrada e o nome de um arquivo de saída. Cada linha do arquivo de entrada possui colunas de tamanho de 30 caracteres. No arquivo de saída deverá ser escrito o arquivo de entrada de forma inversa. Veja um exemplo:

#### Arquivo de Entrada
```
Hoje e dia de prova de CAP
A prova esta muito fácil
Vou tirar uma boa nota
```

#### Arquivo de Saída
```
aton aob amu rarit ouv
licaf otium atse avorp a
pac ed avorp ed aid e ejoh
```

### 16 - Imagine que cada produto de um supermercado tem um código de barras e suas informações como nome do produto, marca e preço estão gravados em um arquivo. Faça um programa que leia um conjunto de códigos de barras com a respectiva quantidade comprada pelo cliente e que estão em um arquivo de compras e produza um arquivo de nota fiscal que contenha informações sobre a compra do cliente, com o seguinte formato:
```
Lojas Mágicas S.A.
R. dos sonhos, 1001
São Carlos – SP

Qdade   Produto     Valor Unitário  Valor Total
# 002   feijão      R$ 2.50         R$ 5,00
# 004   arroz       R$ 8,90         R$ 35,60
# 003   alface      R$ 1,20         R$ 3,60
                                    _________________
                                            R$ 44,20
```