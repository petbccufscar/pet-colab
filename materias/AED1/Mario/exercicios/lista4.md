# Lista de Exercícios 4

#### Professor
[![Mario](https://img.shields.io/badge/Mario_San_Felice-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)](https://site.dc.ufscar.br/docente/5cee7e5d48365a001679f750)


## Pilhas

Seguem alguns exercícios relacionados com pilhas.

### 1 - Suponha que, diferentemente da convenção adotada em aula, a parte do vetor ocupada pela pilha é p[0 .. t]. Escreva o código das funções empilha, desempilha, pilhaVazia, pilhaCheia e tamPilha.


### 2 - Escreva um algoritmo que use uma pilha para inverter a ordem das letras de cada palavra de uma string, preservando a ordem das palavras. Porexemplo, para a string ETSE OICICREXE E OTIUM LICAF o resultado deve ser ESTE EXERCICIO E MUITO FACIL.

### 3 - [Sedgewick] O fragmento de programa abaixo manipula uma pilha de caracteres. A função espiaPilha() devolve uma cópia do topo da pilha, mas não tira esse elemento da pilha. Diga, em português, o que o fragmento de código faz. Escreva um fragmento de código equivalente que seja bem mais curto e mais simples.

```c
if (pilhaVazia()) empilha('B');
    else {
    if (espiaPilha() != 'A') empilha('B');
    else {
        while(!pilhaVazia() && espiaPilha() == 'A')
            desempilha();
        empilha('B');
    }
}
```

### 4 - Dê uma definição formal de sequência bem-formada de parênteses e colchetes. Sugestão: dê uma definição recursiva.


### 5 - Aplique à expressão infixa (A+B)*D+E/(F+A*D)+C o algoritmo de conversão para notação posfixa.

### 6 - [Valor de expressão posfixa] Suponha que posf é uma string não vazia que guarda uma expressão aritmética em notação posfixa. Suponha que posf contém somente os operadores +, -, * e / (todos exigem dois operandos). Suponha também que a expressão não tem constantes e que todos os nomes de variáveis na expressão consistem em uma única letra maiúscula. Suponha ainda que temos um vetor valor que dá os valores das variáveis (todos inteiros): valor[0] é o valor da variável A, valor[1] é o valor da variável B, etc. Escreva uma função que calcule o valor da expressão posf. Cuidado com divisões por zero!

### Material auxiliar
- https://www.ime.usp.br/~pf/algoritmos/aulas/pilha.html


## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!