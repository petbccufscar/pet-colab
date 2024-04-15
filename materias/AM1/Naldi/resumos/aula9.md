# Resumo Aula 9
> Resumo criado pelo aluno [João Pedro Trevisan](https://www.linkedin.com/in/joao-pedro-trevisan)

#### Professor
![Murilo Naldi](https://img.shields.io/badge/Murilo_Coelho_Naldi-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)

## Frequent Itemset Mining
Começaremos esta aula com um problema clássico: A análise da lista de compras.

Quais itens são frequentemente comprados juntos? Essa informação pode ser utilizada para deixar produtos na mesma prateleira ou oferecer promoções específicas. Isso fica óbvio se você pensar que quem compra escovas de dentes provavelmente também comprará pasta, mas precisamos descobrir as combinações não óbvias: 
+ Páginas de um portal acessadas na mesma sessão
+ Minerais encontrados na mesma região
+ Pessoas que demonstram comportamentos semelhantes

Existe por exemplo a correlação encontrada pelo Wall Mart que sempre que havia um aviso de tornado a compra de *Pop Tarts* (um doce) de morango se tornava 7x maior.

Até então só foram apresentadas situações onde isso pode ser útil, veremos agora como usar isso. A tabela a seguir mostra um exemplo de como buscar um correlação:

![AM1_aula10_img01.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula10_img01.png)

A forma de ler esta tabela é: **Se** açúcar é comprado, **então** leite também é comprado. **Se** açúcar e leite são comprados, **então** café também é comprado (em 60% das transações).

Perceba que usamos os termos "**se**" e ''**então**'', não é atoa, são relações lógicas. O conjunto de itens que queremos achar chama-se **itenset** (**conjunto de itens**).

Formalizando isso:
+ A = {a1, a2,... an} é o universo de n itens
+  I ⊆ A é um **itenset**
+ T = {t1, t2,... tn} é o conjunto de *n* transações
+ Cada transação é um par \<TIDi, ITENSi\> (TIDi = i-ésimo id de transação)
+ ITENSi ⊆ A e |ITENSi| = k

Uma transação *t* que pertence o conjunto *T* dá suporte a um **itenset** *I* se ele está contido na transação *t*, isto é, *t* contém todos os elementos de *i*. O conjunto de transações **K(I)** que suporta *I* é dito *conjunto suporte do itenset*

Existem métricas chamadas **suporte absoluto** e **suporte relativo**. Elas são dadas por:

![AM1_aula10_img02.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula10_img02.png)

O problema de se encontrar **itensets** frequentes pode ser definido por:

Dados:
	Um conjunto A de itens, uma tabela T de transações sobre A e um número 0 < σmin <= 1 (**suporte mínimo**)
Encontrar:
	Conjunto de **itensets** com suporte maior ou igual a um valor σmin definido pelo usuário
	Conjunto de regras de associações com **confiança** maior do que a estabelecida pelo usuário

A imagem a seguir expõe uma tabela de transações e a tabela de enumeração de todos os conjuntos de itens frequentes usando o suporte mínimo = 3:

![AM1_aula10_img03.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula10_img03.png)

O **espaço de busca** para o conjunto A tem 2^a **itensets**. Deve ser reduzido o espaço. Usualmente considera-se o fato que:
+ Seja X, Y ⊆ I
+ Se X ⊆ Y -> suporte(Y) <= suporte(X)
+ Portanto, se um **itemset** é pouco frequente todos seus superconjuntos também o serão.

Note que adicionar um item no **itenset** diminui seu suporte.

Uma maneira de se mapear o **espaço de busca** é por meio de um grafo. Começamos com o conjunto vazio e depois com os conjuntos que o contém o elemento vazio e mais um item, depois conjuntos que possuem este item e mais algum outro e assim sucessivamente.

A imagem a seguir mostra um banco de dados de transações com 10 transações e o espaço de busca para encontrar todos os possíveis **itensets** de **suporte mínimo** = 3.

![AM1_aula10_img04.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula10_img04.png)

Os mais escuros atingiram **combinação máxima**, eles nunca vão somar o suficiente para igualar ou superar o suporte mínimo.

Estudaremo os algoritmo chamado **Apriori** que fará um cálculo a priori dos itens que aparecem mais vezes. Ele se baseia em uma busca em largura no grafo do espaço de busca, a cada nível se cria **itensets** a partir dos **itensets** anteriores e calcula-se a frequência de aparecimento dos **itensets**.

Inicialmente, cada elemento é um **itenset** unitário, os **itensets** de tamanho k+1 serão obtidos a partir dos itensets de tamanho k. Isso vem por meio da combinação do k-ésimo conjunto de candidatos (**Fk**) com ele mesmo.

**X U Y** (a união) dos itens **X**, **Y** ∈ **Fk** é gerada se eles tem o mesmo prefixo de k-1 elementos, a obtenção dessas uniões é facilitada se os itens estão ordenados. Varre-se o banco recalculando os suportes e inserindo os **itensets** com **suporte mínimo** em **Fk+1**.

Nos slides 28 ~ 35 há um exemplo de execução do algoritmo.

O algoritmos **apriori** encontra **itensets** frequentes e tem ainda um segundo passo para encontrar regras de associação:

Combina-se termos para construir regras da forma A->B, tal que A U B é um **itenset** frequente. O grau de interesse da regra é dado pela medida de **confiança**

![AM1_aula10_img05.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula10_img05.png)

O algoritmo gera todos subconjuntos não vazios do **itenset** e para cada um deles verifica a confiança da regra dada por **s -> {I/s}**. A imagem que segue mostra o **espaço de busca** de regras de associação para um **itenset** frequante:

![AM1_aula10_img6.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula10_img06.png)

Existem diversas soluções para melhorar a eficiência da solução.

Vale lembrar que há ainda um problema a se atentar: número excessivo de regras. Para remediar isso devemos **pós-processar** a base de regras.

Para tanto devemos ter em mente duas definições:
+ **itenset frequente maximal**: se é frequente mas nenhum dos seus superconjuntos é frequente.
+ **itenset frequente fechado**: se e somente se ele não possui superconjuntos com a mesma frequência.

Tomando como base a tabela anteriormente usada para enumerar todos os **itensets** temos:

![AM1_aula10_img07.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula10_img07.png)
**itensets frequentes maximais**

![AM1_aula10_img08.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula10_img08.png)
**itensets frequentes fechados**

Dito isso, vamos a um exemplo de pós-processamento: queremos avaliar a regrar {chá}->{café}

Esta regra possui **suporte** = 150/1000 = 0,15 e **confiança** = 0,15/0,2 = 0,75. Porém, ao observar a tabela de confusão a seguir notamos que a probabilidade de alguém comprar café independentemente de comprar chá é de 80%, portanto a regra é enganosa:

![AM1_aula10_img09.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula10_img09.png)

Para resolver este tipo de questão podemos usar uma métrica como o **coeficiente de interesse** (também chamado de **lift**) que é definido da forma:

![AM1_aula10_img10.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula10_img10.png)


**Lift** = 1 significa que A e B são independentes, valores menores que 1 indicam correlação negativa e os valores maiores que 1 indicam correlação positiva. No exemplo temos:

**Lift({chá}->{café}) = 0,9375**, ou seja, correlação negativa.

Existe também a medida de **convicção**:

![AM1_aula10_img11.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula10_img11.png)


Ela demonstra efeito negativo da regra quando seu valor é menor que 1. Tende a infinito quando a confiança da regra tende a 1. 0 indica que B está em todas as transações. No exemplo temos:

**convicção({chá}->{café}) = 0,8**, isto é, a regra tem efeito negativo.

A **convicção** é o quociente da frequência esperada de A ocorrer sem B.


## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!
