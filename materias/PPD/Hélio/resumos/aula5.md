# Resumo Aula 5
> Resumo criado pelo aluno [João Pedro Trevisan](https://www.linkedin.com/in/joao-pedro-trevisan)

#### Professor
![Helio](https://img.shields.io/badge/Helio_Crestana_Guardia-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)

## Processamento Vetorial
Originalmente o recurso de processamento vetorial surgiu em supercomputadores da década de 70, conforme a tecnologia avançou se tornou possível ter paralelismo de dados em CPUs comerciais.

Este modelo de programação é conhecido como SIMD (Single Instruction, Multiple Data) e é um paralelismo de granularidade fina que realiza de maneira simultânea a mesma operação em diferentes dados.

As arquiteturas que disponibilizam processamento vetorial possuem registradores adicionais mais logos e uma lógica de circuitos que permite realizar operações aritméticas sobre várias partes destes registradores. Vejamos o exemplo a seguir:

Aqui temos o código de um loop simples que soma dois registradores
``` C
for (i=0; i < MAX; i++)
   c[i] = a[i] + b[i];
```

Quando fazemos uso de um processador vetorial um *for* como este pode ser operado com a técnica chamada *loop unrolling*
``` C
for (int i=0; i < MAX; i+=4){
	c[i]   = a[i]   + b[i];
	c[i+1] = a[i+1] + b[i+1];
	c[i+2] = a[i+2] + b[i+2];
	c[i+3] = a[i+3] + b[i+3];
}
```

Note que com todas estas operações ocorrendo ao mesmo tempo teremos 1/4 das operações do loop original. Este é um exemplo de operação SIMD.

Quando pensamos em vetorização temos instruções do tipo:
``` C
for (int i=0; i < MAX; i+=4)
	addFourValuesAtOnceAndStoreResult(&c[i], &a[i], &b[i]);
```

O nome da função ```addFourValuesAtOnceAndStoreResult()``` é bem auto explicativo, ela faz exatamente a mesma coisa que o código anterior.

De maneira geral, a maioria das extensões que operam sobre múltiplos dados no processador consistem de armazenar valores na memória em registradores específicos como se fossem uma só grande palavra de bits e então operar sobre esta palavra.

A vetorização de loops pode ser realizada automaticamente por compiladores, contudo é necessário que algumas condições sejam cumpridas para que a vetorização seja possível. Elas são:
1. Ter um número identificável de iterações.
2. Haver uma única entrada e uma única saída no loop.
3. Todas iterações devem seguir o mesmo caminho (sem branch).
4. Se houver aninhamento de loops só se pode vetorizar o loop mais interno.
5. Não se deve chamar funções dentro do loop, a não ser funções ligadas a operações matemáticas.

Outros pontos a nos atentarmos para não impedir a vetorização tangem o armazenamento de dados e a dependência deles. 

Para que possam ser realizadas operações vetoriais é necessário que os dados sejam salvos de maneira contígua na memória, isto é, em vetores ou matrizes. Se os valores não são contíguos eles devem ser levados aos registradores com múltiplas instruções de fetching, imagine isso ocorrendo ao longo das muitas iterações de um loop. 

Quanto ao problema da dependência de dados, uma vez que o processador vai calcular vários valores ao mesmo tempo é preciso que isso não gere dados inconsistentes. Os problemas de dependência são caracterizados como:

**Read-after-write**:
Quando uma variável é escrita em uma iteração e lida na próxima, também conhecido como dependência de fluxo.
``` C
A[0] = 0;
for(j=1; j < MAX; j++)
	A[j] = A[j-1] + 1;

// Equivalente a:

A[1] = A[0] + 1; 
A[2] = A[1] + 1;
A[3] = A[2] + 1;
A[4] = A[3] + 1;
```
Este loop não pode ser vetorizado com segurança pois as n primeiras iterações são realizadas simultaneamente em SIMD e o valor, por exemplo, de ```A[1]``` não pode ser usado pela segunda iteração antes de ser alcançado pela primeira.

**Write-after-read**:
Uma variável é lida em uma iteração e escrita na iteração subsequente.
``` C
for(j=1; j < MAX; j++)
	A[j-1] = A[j] + 1;

// Equivalente a:

A[0] = A[1] + 1; 
A[1] = A[2] + 1;
A[2] = A[3] + 1;
A[3] = A[4] + 1;
```
Em processamento paralelo tradicional, nenhuma instrução que usa um valor maior que o índice pode ser completa antes de uma iteração com um valor menor que o índice (no nosso caso o índice e j e o problema é j - 1 vir antes de j + 1). Contudo este loop pode ser vetorizado, mas o loop a seguir não:
``` C
for(j=1; j < MAX; j++){
	A[j-1] = A[j] + 1;
	B[j]   = A[j] * 2;
}
```
Este exemplo é inseguro em ambientes vetorizados pois pode ser que alguns elementos de ```A[]``` sejam sobrescritos antes que o vetor ```B[]``` possa fazer o uso deles e outros não, gerando resultados inconsistentes.

**Read-after-read**:
Esse pode :).

**Write-after-write**:
Conhecido também como dependência de saída, as mesmas variáveis são escritas em mais que uma iteração. Isso é inseguro tanto para paralelização tradicional estudada até aqui quanto para operações vetoriais.

Situações notáveis sobre vetorização que devemos nos atentar são listadas a seguir:

De início o seguinte código:
``` C
for(j=1; j < MAX; j++)
	sum = sum + A[j] * b[j];
```
Embora a variável ```sum``` seja lida e escrita em toda iteração os compiladores conseguem reconhecer estas situações de redução e torná-las vetoriais.

Loops com potenciais dependências também não podem ser vetorizados, note:
``` C
form (j=0; j < MAX; j++)
	C[i] = A[i]* B[i];
```
Em casos como este, para alguma iteração *i*, pode ser que ```C[i]``` esteja mapeado para a mesma posição de memória que ```A[]``` ou ```B[]``` em uma iteração diferente, com locais de memória ditos "aliased". No caso de os ponteiros ```A[i]``` e ```C[i-1]``` estarem "aliased" haveria uma dependência **read-after-write**.

## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!