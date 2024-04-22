```c
Algoritmo Triangulo
|	escreva(“Informe Valor 1:)
|	leia(valor1)
|	escreva(“Informe Valor 2:)
|	leia(valor2)
|	escreva(“Informe Valor 3:)
|	leia(valor3)
|	
|    //verificando se é triangulo
|	se (valor1 < valor2 + valor3) e (valor2 < valor1 + valor3) e (valor3 < valor2 + valor1) entao
|	|	escreval(“Formam triangulo”)
|	|
|	|    //verificando o tipo do triangulo
|	|	se (valor1 == valor2) e (valor2 == valor3) entao
|	|	|	escreval(“Triangulo Equilatero”)
|	|	senao se (valor1 == valor2) ou (valor2 == valor3) ou (valor1 == valor3)
|	|	|	escreval(“Triangulo Isoceles”)
|	|	senao
|	|	|	escreval(“Triangulo Escaleno”)
|	senao
|	|	escreval(“Nao formam Triangulo”)
|	fimse
FimAlgoritmo
```