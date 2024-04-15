# Resumo Aula 1
> Resumo criado pelo aluno [João Pedro Trevisan](https://www.linkedin.com/in/joao-pedro-trevisan)

#### Professor
![Murilo Naldi](https://img.shields.io/badge/Murilo_Coelho_Naldi-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)


## Conceitos Básicos de AM
A Inteligência Artificial passou a ser considerada um tópico de pesquisa após um evento conhecido como *The 1956 Dartmouth Workshop* que foi ministrado por um matemático chamado John McCarthy, o termo "Inteligência Artificial" não foi cunhado ali contudo. O objetivo inicial da Inteligência Artificial era entender melhor a inteligência humana e assim tentar tornar máquinas conscientes, criar equipamentos com a capacidade de pensar, tomar decisões sem interferência humana e coisas do gênero.  

Conforme passou o tempo os objetivos da IA se tornaram mais modestos e realistas, hoje pode-se dizer que um dos grandes objetivos da Inteligência Artificial é criar sistemas que tomem decisões com o mínimo possível de interferência humana. Outro grande objetivo da IA que deve ser mencionado no contexto dessa matéria é atingir um processo análogo ao aprendizado humano no sentido de gerar mudanças em um código. Arthur Samuel define que "*O* ***aprendizado de máquina*** *é o campo de estudos que da aos computadores a habilidade de aprender sem serem explicitamente programados*".  

Uma definição mais madura de **Aprendizado de Máquina** é dizer que ela consiste de "*um programa de computador que adquire experiência E em respeito a uma tarefa T e que essa experiência pode ser medida em relação a um parâmetro P*". Com exemplo disso podemos tomar a situação de um leitor de e-mails que sabe todas as vezes que você marca um e-mail como spam e com isso aprende a filtrar melhor suas mensagens. Neste caso a tarefa T é definir se um e-mail é spam ou não, a medida de performance P pode ser o grau de marcação de novas mensagens como spam corretamente e a experiência são os e-mails marcados como spam ou não.  

Uma forma de generalizarmos este processo é tomarmos um conjunto *X*, um conjunto *Y* e um conjunto de dados de experiência chamado *Dados* de forma que *X* = {x1, x2, x3, ..., xn}, *Y* = {sucesso, fracasso} e *Dados* = {(x1, y1), (x2, y2), ..., (xn, yn). Teremos então:  

Conjunto *X*  
Conjunto *Y*  
Função *F*: *X* -> *Y*  
Conjunto *Dados*: (x1, y1), (x2, y2), (x3, y3), ..., (xn, yx)

O nosso problema no **Aprendizado de Máquina** é criar um algoritmo que aproxime a função *F* perfeita, não só isso mas também estudar os diferentes **vieses de aprendizado** que podem guiar este processo. Os diferentes **vieses** são as categorias do aprendizado de máquina e alguns exemplos são: Aprendizado supervisionado, aprendizado não supervisionado, aprendizado semi-supervisionado, aprendizado por reforço e muitos outros.  

A imagem a seguir é um fluxograma de alguns tipos de **Aprendizado de Máquina**:  

![AM1_aula02_img01.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula02_img01.png)

## Dados, Tipos de Atributos e Noções de Pré-Processamento
Ao se falar de Inteligência Artificial muitos elementos se fazem presentes e é preciso elencá-los. Um conceito muito comum neste meio é o **dado**, um dado é basicamente uma observação e depende de um contexto para significar algo, a disponibilidade de dados abre margem para ser extraída informação. Ainda sobre dados surge o conceito não necessariamente relacionado a IA de **Big Data** que olha pros dados que possuem grande *volume*, *variedade* e *velocidade* atribuídas a eles.  

Quando temos um conjunto de dados podemos retirar dele um único exemplar de dados chamado de **amostra**, **exemplo** ou **instância** . Um **atributo** é uma característica observável ou mensurável de uma **instância**, cada **amostra** é descrita por um conjunto de **atributos**. Nem sempre os dados vão possuir características explícitas, chamamos estes dados de "*não-estruturados*", podemos então realizar a extração ou aprendizado de atributos. Grande parte dos algoritmos de AM recebem seus dados na forma de uma *tabela atributo-valor* onde as linhas representam uma **amostra** e as colunas seus **atributos**.  

Dependendo do tipo de atributo que temos em mãos para realizar uma análise podemos extrair diferentes tipos de informação. Começaremos falando de **atributos numéricos**.

Este tipo de dado pode ser dado em uma escala **discreta** ou **contínua**, ou seja, pode andar em passos que tem sempre o mesmo tamanho (por exemplo *idade*, ninguém diz ter 23,83 anos) ou que variam com casas decimais de precisão. Com este tipo de atributo se pode sumarizar *quantis*, avaliar medidas de tendencia central como *moda*, *média* ou *mediana* e encontrar informações sobre o conjunto de dados como *desvio padrão*, *intervalo*, *variância* e muito mais. Exemplos de boas escolhas de gráficos para observar este tipo de dados são o *histograma*, o *box plot* ou até o *violin plot*.

Uma transformação comum feita em **dados numéricos** é o processo de discretização de dados contínuos ou a divisão de dados discretos em intervalos. Em ambos os processos se escolhe um intervalo de dados que será representado por um mesmo valor, simplificando assim as observações. A imagem que segue mostra diferentes objetivos que se pode ter com uma discretização de dados:

![AM1_aula02_img02.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula02_img02.png)

Outro tipo de dado que pode ser encontrado é o dado **nominal**. Também chamado de dado "*categórico*" são valores que servem de nomes ou rótulos que classificam o dado em questão. Não existe relação implícita em dados nominais nem mesmo relação de ordem. Exemplos desse tipo de dado podem ser *período do dia* (manhã, tarde e noite), *cor dos olhos* (castanho, verde, azul), *laboratório do DC* (LE1, LE2, LE3...).

**Dados nominais** podem ser armazenados de várias formas, a mais óbvia sendo a palavra que eles representam. Pode-se também criar um código, se estamos armazenando cores pode-se ter 1 = amarelo, 2 = azul e 3 = vermelho. Pode-se armazenar um texto descritivo ou se o atributo tiver só dois valores também o pode armazenar como um valor booleano.

A imagem a seguir mostra a transformação de dados em binário usando a técnica de *one hot encoding* onde se tem 1 no valor representado e 0 em todos os outros possíveis. 

![AM1_aula02_img03.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM1/AM1_aula02_img03.png)

Por fim, temos os **atributos ordinais** cujo nome entrega que tem uma ordem entre eles. A magnitude da diferença entre eles é desconhecida, ou seja, não se pode ter dimensão do quão separados estão os dados.

É possível extrair deles informações de frequência, quantis, intervalo interquartil e tais tipos de dados.

Uma parte importante de se trabalhar com dados está no **pré processamento dos dados**. É nessa faze do trabalho com dados que se pode tratar valores desconhecidos, classes desbalanceadas, *outliers* e ruídos.


## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!
