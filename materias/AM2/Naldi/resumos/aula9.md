# Resumo Aula 9
> Resumo criado pelo aluno [João Pedro Trevisan](https://www.linkedin.com/in/joao-pedro-trevisan)

#### Professor
![Murilo Naldi](https://img.shields.io/badge/Murilo_Coelho_Naldi-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)

## Redes Neurais em Textos
Pra quem quiser ir mais a fundo neste tema, consulte [NLTK](www.nltk.com/book).

As linguagens de programação tem **modelos de linguagem** bem definidos conforme se estuda em Teoria da Computação. A **linguagem natural**, por sua vez, não possui normas e estruturas bem caracterizadas a ponto de não haver ambiguidade nunca.

Segundo Russel e Norvig, a linguagem natural pode ser definida como uma **distribuição de probabilidade** sobre sentenças.

Num passado recente, as palavras eram medidas e avaliadas com base em seus significados. Enquanto hoje se busca avaliar a probabilidade de palavras estarem juntas e significarem algo juntas.

Os modelos de uma dada língua serão sempre, na melhor das hipóteses, uma aproximação dado o tamanho das linguagens e os diferentes usos por diferentes pessoas.

O exemplo mais clássico de todos é o **Bag of Words** (**BoW**). A grande ideia é contabilizar as palavras em uma **matriz de frequência**, cada palavra será um atributo e cada sentença ou documento é um exemplo.

A imagem a seguir mostra uma matriz de frequência onde cada *t* é uma palavra pós processada de um dado texto *x*. Note que se for introduzido um texto com novas palavras a matriz deve ser aumentada, **isso faz com que o modelo tenha que ser treinado novamente** devido ao fato de que o espaço sobre o qual ele opera recebeu novas dimensões.

![Aula09_img01.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula09_img01.png)

Alguns dos outros problemas com o BoW são que constar que uma palavra existe no texto exprime muito pouca informação, além disso, fazer uso da frequência absoluta privilegia muito algumas palavras que aparecem mais no texto.

O termo *w(Tix)* pode ser calculado de várias maneiras, a exemplo temos as formas:
- Binária: O termo recebe o valor 1 caso apareça no documento e 0 quando não (perde características do texto)
- Frequência do Termo (TF): Os pesos dos termos correspondem a quantidade de vezes que eles apareceram (privilegia algumas palavras)
- Frequência do termo-frequência inversa dos documentos (TF-IDF - Term Frequency-Inverse Document Frequency): produto da frequência do termo pela frequência inversa dos documentos.

Quando se faz uso do TF-IDF se realiza a seguinte equação:

![Aula09_img02.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula09_img02.png)

O processo de aplicação do Bag of Words é esquematizado na image a aseguir:

![Aula09_img03.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula09_img03.png)

Note que se quisermos aproveitar um mesmo modelo as palavras que não participam do **corpus** (conjunto de palavras nos documentos originais) não serão consideradas.

Quando usamos o BoW temos uma dimensionalidade extremamente grande. São necessários passos de processamento para tornar o texto mais processável, uma dessas técnicas é a remoção de **stopwords** como "a", "o", "mas", "então", "se"... Outro processamento é a remoção de palavras com frequência muito baixa pois estas não ajudam muito na atribuição do rótulo.

Existem também os processos de **estemização** e **lematização**. O primeiro termo consiste em reduzir um termo a seu radical, isso geralmente se dá removendo os afixos e o final das palavras, deve-se tomar cuidado para não tornar palavras com significados diferentes um mesmo radical. Já a lematização é quando se analisa morfologicamente o texto para passar as palavras para sua forma infinitiva.

Existem porém termos compostos, é diferente tomar os termos "machine" e "learning" e o termo "machine learning". Em inglês estes termos compostos são chamados de **n-grams**.

Em algumas línguas existem variações de gênero nas palavras ("professor" e "professora" por exemplo), é necessário processar isso.

Um problema que o Bag of Words carrega e que é resolvido pro outros modelos é que não existe um grau de dissimilaridade entre as palavras, uma das formas de se resolver isso é realizar o **word embedding** onde a palavra é transformada em um ponto no espaço vetorial e assim pode haver proximidade entre elas.

Uma técnica utilizada para realizar o embbeding é o **Seq2Vec**. A imagem a seguir mostra algumas das coisas levadas em consideração quando se transforma uma palavra em um ponto no espaço. 

![Aula09_img04.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula09_img04.png)

Note que aquilo que se escolhe levar em consideração é intimamente relacionado com o modelo que se quer gerar. Veja a imagem que se relaciona com o termo "Apple"

![Aula09_img05.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula09_img05.png)

Para atacar a questão do contexto surgem modelos como o **CBoW** (**Continuous Bag of Words**) onde se usa a soma dos termos próximos de uma palavra para se ter o valor da palavra central dessa região.

![Aula09_img06.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula09_img06.png)

Perceba como a entrada do exemplo a seguir (em one hot encoding) é "a cat \_\_\_\_ a mouse" e a saída esperada é "catches"

![Aula09_img07.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula09_img07.png)

Partindo desta ideia pode-se criar o **skip-gram** onde dada uma palavra tenta se capturar quais mais aparecem antes e depois.

![Aula09_img08.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula09_img08.png)

![Aula09_img09.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula09_img09.png)

Existem outros modelos diferentes do BoW e um deles é o **ELMO** que é um modelo profundo para representação de contexto para as palavras.

![Aula09_img10.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula09_img10.png)

A ideia do uso de LSTMs é conseguir o contexto das palavras, note o texto a seguir e os diferentes usos do termo "cell".

Jack while talking over the **cell** phone entered the prison **cell** to extract blood **cell** samples of Jill and made an entry in the excel **cell** about the blood sample collection.

Outro modelo para processamento de texto é o **Auto-encoder** onde se usa um algoritmo para codificar um texto e se treina um decoder para tentar chegar o mais próximo possível do texto anterior ao encoding. Isso pode ser usado para sumarização (resumo) e tradução, por exemplo.

Existem também vetores de contexto que tomam a combinação do vetor da palavra junto de um **encoding posicional** para se conseguir o embedding da palavra junto do contexto. Neste modelo de deslisa uma janela sobre o texto e se processa as palavras individualmente e a janela pra gerar um positional encoding na palavra.

![Aula09_img11.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula09_img11.png)

![Aula09_img12.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula09_img12.png)

O estado da arte em processamento de texto (o GPT usa) são os **transformers** que foram apenas citados de passagem na aula. Quem se interessar mais siga o [link](https://towardsdatascience.com/illustrated-guide-to-transformer-cf6969ffa067).

## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!
