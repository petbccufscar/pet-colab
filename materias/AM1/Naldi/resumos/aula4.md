# Resumo Aula 4
> Resumo criado pelo aluno [João Pedro Trevisan](https://www.linkedin.com/in/joao-pedro-trevisan)

#### Professor
![Murilo Naldi](https://img.shields.io/badge/Murilo_Coelho_Naldi-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)

## Probabilidade a priori

A princípio, resumiremos alguns conceitos de probabilidade e o mais básico deles é o de **variável aleatória**. Este termo representa uma observação em nosso espaço amostral e seu valor é inicialmente desconhecido. Elas podem representar domínios booleanos, discretos ou mesmo contínuos.

Quando se trabalha com probabilidades temos a certeza de que os valores estarão entre 0 e 1, então 0 <= P(a) <= 1. A probabilidade de uma disjunção é dada por P(a V b) = P(a) + P(b) - P(a ^ b).

Chamamos de **probabilidade a priori** aquela que é incondicional, ou seja, ocorre na ausência de quaisquer outras informações. Ela pode ser simples ou conjunta.

![AM1_aula05_img10.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula05_img10.png)

Chamamos de **distribuição de probabilidade** as probabilidades **a priori** de uma determinada variável aleatória. Então se temos P(Clima) = <0.5, 0.2, 0.3> dizemos que clima possui 0.5 de chance de estar em um estado, 0.2 em outro e 0.3 de chance de estar em outro ainda.

A **distribuição de probabilidade conjunta** é quando temos a probabilidade **a priori** de cada combinação de um conjunto de variáveis aleatórias. Quando essas variáveis definem o ambiente a distribuição será chamada de **probabilidade conjunta total**.

Se temos uma base de conhecimento com probabilidades podemos realizar a **totalização** ou **marginalização** que consiste em calcular a probabilidade de um acontecimento a partir da base de conhecimento:

![AM1_aula05_img11.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula05_img11.png)

Variáveis contínuas são ruins de serem representadas em tabelas pois seus valores são infinitos. Utilizamos então **distribuições de probabilidade** sejam elas uniformes ou normais ou outras.

## Probabilidade condicional
Probabilidade condicional se da quando a ocorrência ou não ocorrência de um evento influi na probabilidade de um outro evento ocorrer. 

A probabilidade de um evento *A* ocorrer dado que *B* tem que ocorrer é dada por:

**P(A|B) = P(A^B)/P(B)**

Pode haver também o processo conhecido como **condicionamento** que consiste em tirar a probabilidade a priori tendo em mãos a probabilidade à priori. O processo é o seguinte:

![AM1_aula05_img01.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula05_img01.png)

Outro conceito muito importante é a **independência absoluta** que é quando uma variável aleatória não interfere na outra. Uma variável é **independente** de outra quando sua probabilidade à priori é igual a sua probabilidade condicional quando atrelada a uma outra variável, ou seja:

**P(A|B) = P(A)**

Com base na **independência** das variáveis realizamos o processo de **fatoração** que consiste em reduzir a quantidade de informações para especificar a distribuição do conjunto total. Realizar este processo permite ganho computacional ao tratar variáveis independentemente.

Temos também a relação de **probabilidade conjunta** que é expressa por:

**P(X,Y) = P(Y|X) \* P(X) = P(X|Y) \* P(Y)**

Se invertermos as probabilidades condicionais chegaremos à **regra de Bayes** que é a a base de todos os sistemas de inferência probabilística modernos. Sua ideia é chegar a probabilidade condicional de uma variável baseada na probabilidade condicional de uma outra variável.

**Regra de Bayes**:

![AM1_aula05_img02.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula05_img02.png)

A principal aplicação da **regra de bayes** é para encontrar relações entre causa e efeito:

![AM1_aula05_img03.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula05_img03.png)

Em um exemplo prático, sabemos que o diagnóstico de meningite observa rigidez no pescoço 50% das vezes. Sabemos também que a **probabilidade a priori** de alguém possuir meningite é de 1/50.000 e de alguém simplesmente estar com o pescoço rígido é de 1/20. Tendo isso em mãos, qual a chance de um paciente com pescoço rígido estar com meningite?

Sendo *s* a proposição de que o paciente possui rigidez no pescoço e *m* a proposição de que o paciente possui meningite temos:
+ P(s|m) = 0,5
+ P(m) = 1/50.000
+ P(s) = 1/20
+ P(m|s) = (P(s|m) \* P(m))/P(s) = 0,5 \* 1/50.000 \* 20 = 0,0002

![AM1_aula05_img04.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula05_img04.png)

Agora, se houverem mais que uma variáveis evidência precisamos conhecer a dependência entre cada dupla de variáveis. No caso de haverem *n* variáveis evidência o número de combinações possíveis de variáveis aleatórias será de 2^*n* e sendo assim precisamos encontrar asserções sobre o domínio que permitam simplificar as expressões.

Podemos tomar também a **regra de Bayes condicionada** tomando uma evidência prática chamada de *e*:

**P(Y|X, e) = (P(X|Y,e) \* P(Y|e))/P(X|e)*

Assumindo que exista **independência entre variáveis** não precisaremos calcular as interações entre todas as combinações de variáveis.

Para nos aproveitarmos disso podemos buscar algo mais fácil que **independência absoluta**. Usaremos então o conceito de **independência condicional** que é quando duas variáveis podem ser independentes quando condicionadas aos valores de uma terceira. 

Tomemos um exemplo com o TUSCA: Considere a probabilidade de três pessoas irem no TUSCA. Ana é amiga de Mario e Rafael. Portanto, a probabilidade de Mario ou Rafael ir no TUSCA (ou deixar de ir) influencia na probabilidade de Ana ir. Mario e Rafael também gostam de Ana e a probabilidade de Ana ir (ou deixar de ir) influencia na decisão dos dois. Sem que saibam, a probabilidade de Mario ir influencia indiretamente na probabilidade de Rafael ir, e vice-versa, pois ambos influenciam na probabilidade de Ana ir. Ou seja, existe dependência entre P(Mario) e P(Rafael) enquanto houver incerteza em relação a P(Ana). Entretanto, se Ana decide ir (ou não) no TUSCA, as probabilidades das variáveis Mario e Rafael deixam de se influenciar. Isso é **independência condicional**.

Duas variáveis são independentes condicionalmente se, dada uma terceira variável Z temos:

**P(X,Y|Z) = P(X|Z) \* P(Y|Z)**

Sendo assim, podemos aplicar isso ao exemplo anterior na forma:

**P(Mario, Rafael|Ana) = P(Mario|Ana) \* P(Rafael|Ana)**

Asserções de independência condicional também permitem a decomposição da distribuição conjunta total em itens menores:

```
P(Mario, Rafael, Ana) = 
P(Mario, Rafael|Ana) \* P(Ana) =
P(Mario|Ana \* P(Rafael|Ana) \* P(Ana)
```

A decomposição em problemas menores permite a redução significativa da complexidade de sistemas probabilísticos. Se existirem *n* variáveis independentes condicionalmente dado um evento, a complexidade do tamanho do sistema é reduzida de **O(2^n)** para **O(n)**.

Podemos modelar o problema em que uma variável aleatória influencia de maneira direta um conjunto de variáveis aleatórias condicionalmente independentes. Neste modelo, chamamos a variável que influencia de causa e as influenciadas de efeitos.

Aí que entra o **Bayes Ingênuo**. Assume-se independência condicional entre os efeitos fazendo com que a distribuição conjunta seja dada por:

![AM1_aula05_img05.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula05_img05.png)

Para classificação usando a **Regra de Bayes** utilizamos um modelo probabilístico condicional. Consideramos um objeto *x* = (x1, x2, ..., xn) a ser classificado, composto por *n* características (variáveis independentes). A partir de então é possível calcular a probabilidade deste objeto pertencer à classe Ck como:

**P(Ck|x) = P(Ck|x1, x2, ..., xn)**

classe = variável condicional, ou seja, que define o valor das outras. Classe é o atributo dependente dos outros.

No fim das contas o classificador Bayesiano utiliza o modelo probabilístico combinado com alguma regra de decisão que defina qual classe é preferida dentre as hipóteses testadas e assim será dado pro algo nas linhas de:

![AM1_aula05_img12.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula05_img12.png)

Tomaremos um exemplo de uso de **Naïve Bayes**. Temos a seguinte tabela:

![AM1_aula05_img06.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula05_img06.png)

Eu quero que a combinação dos fatores anteriores definam se eu vou jogar tênis ou não (ultima coluna, classe). É claro que todos os atributos influem um no outro, mas fecharemos os olhos para isso (ingenuamente). 

Criaremos tabelas onde haverão as probabilidades de se jogar ou não baseado nos atributos, **achando assim a distribuição de probabilidade desses atributos em relação à classe JOGAR**. Se liga:

![AM1_aula05_img07.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula05_img07.png)

Note que não calculamos a probabilidade condicional levando em conta todas as variáveis (o que seria computacionalmente muito intenso). Ao invés disso tomamos a classe a ser predita como JOGAR e calculamos em relação a apenas ela.

Tomemos alguns atributos que "montem um dia". Escolheremos clima ensolarado, temperatura fria, umidade alta e vento forte. Faremos as contas para descobrir a chance de haver jogo nesses casos:

![AM1_aula05_img08.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula05_img08.png)

Note que tivemos dois resultados e que eles não são complementares. Não só isso, como foi descartada da conta a divisão pela evidência temos apenas valores proporcionais e não absolutos. Devido a isso escolheremos o maior valor de classe que obtivemos na tabela, no caso 0.0206.

Note também que os números sendo sempre entre 0 e 1 quando eles forem multiplicados eles podem gerar um *underflow* no programa, para remediar isso usamos o chamado **truque do log**:

![AM1_aula05_img09.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula05_img09.png)

Outra coisa que usamos é a **suavização são de Laplace**. Este processo nos ajuda quando há categorias que não possuem entradas para todos os atributos e resultarão em 0 para probabilidades condicionais.

![AM1_aula05_img13.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula05_img13.png)

Para solucionar esta questão somamos 1 no numerador e denominador de categorias vazias:

![AM1_aula05_img14.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula05_img14.png)

*n* é o número de atributos no conjunto de treino.

Por fim, precisamos saber que existem tipos diferentes de **Naïve Bayes**. Dependendo do tipo de dados usaremos uma distribuição de probabilidade diferente:

![AM1_aula05_img15.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula05_img15.png)

Ainda assim, podem haver dados que combinem tipos diferentes de atributos e as possíveis soluções giram em torno de dividir o atributo contínuo em intervalos e ajustar a um modelo multidimensional ou ajustar um modelo gaussiano aos atributos contínuos e categóricos e combinar.


## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!
