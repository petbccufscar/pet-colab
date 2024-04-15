# Resumo Aula 8
> Resumo criado pelo aluno [João Pedro Trevisan](https://www.linkedin.com/in/joao-pedro-trevisan)

#### Professor
![Murilo Naldi](https://img.shields.io/badge/Murilo_Coelho_Naldi-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)

## Aprendizado Ativo
Existe uma série de maneiras de se dividir o aprendizado de máquina, as imagens a seguir demonstram algumas destas formas, a primeira mais simplista e a segunda mais específica:

![Aula08_img01.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula08_img01.png)


![Aula08_img02.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula08_img02.png)


É importante reforçar que estas categorizações não englobam todo tipo de aprendizado, não os classificam com precisão e tampouco são mutuamente excludentes. Note que não há nestes fluxogramas o aprendizado semi-supervisionado.

Existe a possibilidade de durante a construção do modelo você pedir a rotulação de um exemplo não rotulado e isso pode ter um custo. Neste ponto se deve ponderar o quanto se deve pedir para um oráculo dado o custo de cada rotulação. Isso é útil para se resolver problemas em aprendizado semi-supervisionado.

Em recapitulação, rótulo é rótulo e grupo é grupo (porra), porém no aprendizado semi-supervisionado propaga-se rótulos assumindo que eles tem estruturas de grupo.

Pode haver a necessidade de se resolver inconsistências, redundâncias e ambiguidades por meio da consulta de um oráculo para se ter um **true label** no problema que se trabalha, mas até que ponto é viável se depender de um especialista para isso? 

É aí que se entra a questão do aprendizado ativo e surge então uma hierarquia estendida do aprendizado de máquina:

![Aula08_img03.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula08_img03.png)


A técnica de aprendizado ativo geralmente se inicia com uma grande quantidade de dados não rotulados e uma pequena quantidade de dados rotulados. O conjunto rotulado é usado para aprender uma hipótese e, baseado em uma estratégia de query, o quão informativos são os pontos não rotulados quando se trabalha com os menos confiantes. Diferente da técnica semi-supervisionada que seleciona os pontos com maior grau de certeza (assumindo a estrutura de grupo de um dado label), algoritmos ativos selecionam os pontos mais incertos.

Os pontos selecionados são chamados de "query instances" e o modelo pergunta a um oráculo sobre eles, os pontos que são rotulados dessa maneira são então adicionados aos outros dados já identificados e a hipótese é atualizada com base no dataset modificado.

Um dos benefícios do aprendizado ativo é explicado na imagem a seguir:

![Aula08_img046.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula08_img04.png)


O que separa o segundo e o terceiro gráfico é a proximidade dos exemplos rotulados da fronteira de decisão, há grande benefício em classificar estes exemplos dado o ajuste fino que acarretará a fronteira de decisão.

Sendo assim, precisamos dar um jeito de quebrar a ambiguidade do modelo de forma a usar um oráculo para consultar apenas os exemplos próximos da fronteira de decisão. Mas como? Como caralhos eu sei que o negócio tá perto da fronteira de decisão? Como ainda eu poderia trabalhar com isso usando um conjunto não rotulado?

A ideia chave por trás do aprendizado ativo é que um algoritmo de aprendizado de máquina pode alcançar maior acurácia  com menos exemplos de treino se ele é capaz de escolher os dados dos quais ele aprende. Um sistema ativo pode apresentar "perguntas" (conhece o CAPTCHA?) na forma de instâncias não rotuladas a serem classificadas por um oráculo.

Para "aprendedores" passivos, os dados de treinamento são escolhidos aleatoriamente, portanto há uma chance de encontrar-se muitos pontos com posições aproximadamente iguais no espaço e se ter partes ainda não cobertas, a estratégia ativa tenta resolver este problema buscando cobrir uma porção maior do espaço através da seleção e anotação de poucos pontos altamente informativos que cobrem uma larga porção do espaço, especialmente em regiões incertas.

Respondendo a pergunta de como classificar dados não rotulados por meio do aprendizado ativo, começa-se por uma tarefa de agrupamento e então se busca os exemplos de mais impacto para serem desambiguados por uma pessoa.

O ciclo do aprendizado ativo é exemplificado pela imagem a seguir:

![Aula08_img05.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula08_img05.png)

Nos slides 14 ~ 18 há um exemplo de aprendizado ativo. Note que no slide 16 temo classificadas apenas 2 classes das 3 presentes, como então buscar pela terceira classe? Neste caso tomamos uma instância do grupo mais discrepante e pedimos o rótulo a um oráculo.

Tendo alguns exemplos iniciais, a partir da segunda iteração temos uma base para o modelo subsequente, daí surgem as **medidas de incerteza**. A imagem a seguir ilustra em cada ponta dos triângulos uma classe e as cores representam o grau de incerteza, elas estão na ordem **menor confiança**, **margem** e **entropia**:

![Aula08_img06.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula08_img06.png)

E necessária também uma estratégia de escolha das queries, a imagem a seguir nomeia algumas delas:

![Aula08_img07.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula08_img07.png)

Nos slides 23 e 24 está um exemplo de escolha baseado em incerteza.

No slide 25 há a diferença entre uma estratégia baseada em informação e uma outra baseada em representação, note como mudam as fronteiras de decisão.

É importante saber quando parar e obviamente não será quando você classificou manualmente todos os rótulos. Um desses critérios é o de **budget** que dá um custo para cada anotação e um "orçamento" a ser gasto, acabou o orçamento o algoritmo para. Podemos também observar quando nossas métricas de avaliação param de melhorar.

Deve-se atentar também ao **viés de seleção**. Como se começa com pouquíssimos dados, um modelo pode começar de maneira grandemente enviesada, isso causa problemas em conseguir mudar a fronteira de decisão se usarmos dados muito próximos dela, neste caso podemos nos beneficiar de tomar exemplos longe da fronteira.

Tomando um exemplo de uma situação de merda, olhe a imagem a seguir:

![Aula08_img09.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula08_img09.png)

Aqui temos uma série de exemplos de classificações diferentes e as fronteiras de decisão são delicadamente próximas, fica caracterizado então um caso onde é muito difícil realizar o ajuste. Neste caso pode-se recorrer a algumas técnicas pra diminuir a entubada que você vai tomar ou, com sorte, resolver isso.

As técnicas de sampling buscam ajudar no ajuste da fronteira de decisão, algumas delas são:
+ Membership query synthesis
	+ Gera-se um ou mais exemplos sintéticos para ajudar a delimitar as fronteiras.
+ Stream-based selective sampling
	+ Tomada uma instância, cria-se um critério para apresentá-la ao oráculo ou descartá-la
+ Pool-based sampling
	+ Determina-se um critério para criar um grupo de instâncias a ser observado para o oráculo como forma de desfazer ambiguidades.

Vale retornar a aula de aprendizado em fluxo, lá estudamos o **concept drift** que se dá quando o modelo recebe exemplos de uma dada classificação suficientes para mudar as fronteiras de maneira significativa e então até mesmo mudar classificações passadas. Quando se recebe em excesso ou em falta algum tipo de exemplo no aprendizado ativo é possível gerar um concept drift.

A imagem a seguir mostra este processo:

![Aula08_img10.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula08_img10.png)

O aprendizado ativo também pode ser usado em problemas de otimização como quando se tenta aproximar uma função de aptidão que é muito custosa para ser verificada.

Outra área que se beneficia bastante de aprendizado ativo é o processamento de linguagem natural. Neste campo da computação o reconhecimento de entidades nomeadas ou mesmo a classificação de exemplos podem ser muito custosos. Tomar estratégias que se apoiam sobre um oráculo para auxiliar no aprendizado pode beneficiar bastante o processo.

Nos slides 37 ~ 39 existem exemplos de tarefas práticas que podem se beneficiar do aprendizado ativo, seja classificar o tema de um texto, termos em um texto ou itens em uma imagem. Isso pode ser uma tarefa de classificação ou da chamada **identificação de entidade nomeada**.

## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!
