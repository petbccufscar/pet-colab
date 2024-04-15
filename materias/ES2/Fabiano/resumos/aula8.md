# Resumo Aula 8
> Resumo criado pelo aluno [João Pedro Trevisan](https://www.linkedin.com/in/joao-pedro-trevisan)

#### Professor
![Fabiano Ferrari](https://img.shields.io/badge/Fabiano_Ferrari-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)

## Teste de Software: Técnicas e Critérios
Relembrando conceitos da aula 04, o **domínio de entrada** (possíveis valores de entrada para aquele programa) é muito grande ou infinito e portanto devemos criar critérios de seleção de casos de teste.

Podemos definir "pontos de vista" para se testar um software e os mais comuns são:
+ **Teste funcional**, tem em vista a especificação funcional ou não funcional do software.
+ **Teste estrutural**, tem em vista a estrutura interna do programa.
+ **Teste baseado em defeitos**, tem em vista os problemas mais recorrentes.

É importante saber que essas visões de teste de software são complementares e identificam  ora defeitos iguais em testes diferentes e ora defeitos diferentes em testes diferentes gerando assim um processo de teste mais robusto.

![ES2_aula08_img01.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/ES2/ES2_aula08_img01.png)

Relacionado ao teste de software existe uma coisa chamada **efeito de saturação**. Basicamente o que este efeito dita é que conforme se realiza mais testes de um mesmo ponto de vista o tanto de defeitos encontrados vai parar de crescer. É por isso que é importante se variar os tipos de teste usados e também ter em mente que nunca serão encontrados todos os defeitos.

Para determinar os testes a serem feitos usamos **critérios de teste**. Eles são usados *para seleção* dos casos de teste buscando satisfazer os requisitos do critério de teste ou *para adequação* dos casos de teste fazendo com que os critérios criados aleatoriamente serão capazes de atender os requisitos do critério de teste.

Note a diferença entre realizar o **teste exaustivo** ou o **teste com critérios**:

![ES2_aula08_img02.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/ES2/ES2_aula08_img02.png)

Quando se fala de **teste funcional** o processo de testagem também é chamado de **caixa preta** e retira seus requisitos da especificação do software. Ele começa ao se determinar os casos de teste, realizar eles e observar os resultados obtidos e batê-los com os resultados esperados.

Um problema do teste funcional pousa em se quantificar a atividade de teste, ou seja, é impossível garantir que partes essenciais do software foram executadas. Para resolver isso podemos empregar dois critérios: o **particionamento de equivalência** e a **análise do valor limite**.

No **particionamento da equivalência** divide-se o domínio de entrada em **classes** ou **partições de equivalência** que de acordo com a especificação do programa serão tratadas da mesma maneira tanto para valores válidos quanto inválidos. Neste processo a saída pode ser verificada em busca de gerar entradas que ajudem a avaliar se a saída é produzida corretamente.

Este tipo de teste funcional reduz o tamanho do domínio de entrada e concentra-se em criar casos de teste baseados unicamente na especificação. Ele é especialmente adequado para aplicações nas quais as variáveis de entrada podem ser facilmente identificadas e podem ter valores distintos.

Há também a **análise do valor limite** que é um complemento do **particionamento de equivalência**. Ele coloca a atenção da equipe de teste em uma fonte propícia a defeitos que são os limites de uma classe ou partição de equivalência

![ES2_aula08_img03.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/ES2/ES2_aula08_img03.png)

O **teste funcional** encontra alguma dificuldades em seu desenrolar. A atividade de teste é muito difícil de se quantificar pois não se pode garantir que partes essenciais ou criticas do software foram tocadas. Além disso ele depende da qualidade das especificações. Não só isso, dada uma especificação a identificação e criação das classes de equivalência é uma atividade bastante subjetiva. 

## Contato
Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!
