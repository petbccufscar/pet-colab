# Aula 2 CAP

#### Professor
[![PET-BCC](https://img.shields.io/badge/PET--BCC-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)](https://site.dc.ufscar.br/docente/5cee7e5d48365a001679f750)


## Estruturas Condicionais

### As estruturas codicionais servem para a tomada de decisões em códigos.

Além da estrutura básica de condicinal existem também estruturas para tomar decisões baseadas em mais de uma condição.

#### Else if 

O else if pode ser usado para adicionar outra condição, aumentando a eficiência do código, visto que, caso sua primeira condição for atingida não será necessário analizar a consição dentro de um else if.

Exemplo em pseudocódigo:

```c
// Verificação se é maior de idade 
se (idade<18) entao
|	escreval(“Proibido a venda de álcool”)	
|
senao
|	escreval(“Festa Universitária”)
fimse
```

Exemplo em c:

```c
// Verificação se é maior de idade 
if(idade < 18){
|	printf(“Proibido a venda de álcool\n”)	
}
else if (idade >= 18 && idade <= 125){
|	printf(“Festa Universitária\n”)
}
else{
|	printf(“Vampiro Doidão\n”)
}
```


#### Switch case

O switch case é uma estrutura com funcionamento similar ao else if, contudo adiciona a funcionalidade de um caso padrão caso outras condições não tenham sido atingidas. 

Exemplo em pseudocódigo:

```c
escolha valor
|	caso 1, 3, 5
|	|	total <- 1
|	caso 2, 4, 6
|	|	total <- 3
|	outrocaso
|	|	total <- 2
fimescolha
```

Exemplo em c:

```c
// Verificação se é maior de idade 
switch (expression){
|	case 1:
|	|	total = 1;
|	case 2:
|	|	total = 3;
|	default:
|	|	total = 2;
}
```

## Estruturas de Repetição 

### As estruturas de repetição servem para repetir algum trecho de código dada alguma condição. 

#### While 

Exemplo em pseudocódigo:

```c
enquanto (soma<1000) faça
|	leia(num)
|	soma <- soma + num
fimenquanto
```

Exemplo em c:

```c
while(soma<1000){
|	scanf(“%d”, &num);
|	soma = soma + num;
}
```

#### For 

Exemplo em pseudocódigo:

```c
para n de 1 até 5 faça
|	leia(num)
|	soma <- soma + num
fimpara
```

Exemplo em c:

```c
for(i = 0; i<5; i++){
|	scanf(“%d”, &num);
|	soma = soma + num;
}
```

#### Do while 

Exemplo em pseudocódigo:

```c
repita
|	leia(num)
|	soma <- soma + num
até(soma>1000)
```

Exemplo em c:

```c
do{
|	scanf(“%d”, &num);
|	soma = soma + num;
}while(soma<1000)
```


### Material auxiliar
- https://docs.google.com/presentation/d/19W6_4LikMAzqHu32COlzjnwnHnlEfyBJPehBkiTN7I8/edit?usp=sharing

## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!