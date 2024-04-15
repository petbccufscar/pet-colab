# Resumo Aula 4
> Resumo criado pelo aluno [João Pedro Trevisan](https://www.linkedin.com/in/joao-pedro-trevisan)

#### Professor
![Fabiano Ferrari](https://img.shields.io/badge/Fabiano_Ferrari-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)

## Introdução ao Teste de Software
A definição mais uga uga do que significa testar software é executá-lo e ver se ele funciona. Deste modo, o mero rodar o código e navegar o programa pra ver se ele age de maneira esperada é um teste de software, isso pode funcionar para programas pequenos e mais simples buscando ver se ele atende os casos de uso, mas quando se trata de uma aplicação mais complexa isso se torna impossível.

O teste de software está atrelado a um conceito conhecido como **GQS - Garantia de Qualidade de Software**. O **QGS** é um conjunto de atividades técnicas aplicadas durante todo o processo de desenvolvimento, o objetivo é garantir que tanto o processo quanto o produto de software atinja, níveis de qualidade especificados. 

Um exemplo de **GQS** é o **V&V** (**Verificação e Validação**). O processo de **verificação** busca assegurar consistência, completude e corretude do produto em cada fase e entre as fases do ciclo de vida do software, este processo busca responder a pergunta "*estamos construindo o produto de forma correta?*". Já o processo de **validação** quer assegurar que o produto final corresponda aos requisitos do software e sua principal atividade é o **teste de software** em busca de responder a pergunta "*estamos construindo o produto certo?*"

O **teste de software** é composto de uma série de atividades não necessariamente sequenciais, elas estão ilustradas na imagem a seguir:

![ES2_aula04_img01.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/ES2/ES2_aula04_img01.png)

A etapa de **planejamento** envolve a análise de risco, definição de recursos e ambientes necessários, critérios de parada, cronograma, resultados esperados, equipe e coisas referentes a preparação do teste.

**Projeto de casos de teste** diz respeito à definição dos cenários, identificação e priorização de casos de teste, criação de casos de teste, identificar os dados de teste específicos e coisas do gênero.

A **configuração de dados e do ambiente de teste** envolve o desenvolvimento e priorização dos procedimentos de teste, seu ambiente e a realização dos pré-testes.

**Executar e avaliar o teste** envolve desenvolver o processo de testagem e durante ele relatar incidentes, escrever o *log* de teste, acompanhar o status dos incidentes e etc.

Por fim, **monitoramento e controle** é responsável por conduzir revisões do progresso do teste, monitorar defeitos, conduzir revisões de qualidade do produto, analisar problemas, tomar decisões corretivas e etc.

Exite um modelo de maturidade chamado **TMMi - Test Maturity Model integration** que foi criado para graduar processos de teste de software existem 5 níveis de graduação:
1. Inicial
2. Grenciado
3. Definido
4. Gerenciado qualitativamente
5. em otimização

Cada nível de maturidade é composto por **Áreas de Proceso** (**PAs - Process Areas**), cada uma dessas áreas é formada por **Objetivos Específicos** (**SG - Specific Goals**), cada um desses objetivos é formado por **Práticas Específicas** (**Specific Practices - SP**). Existem também os **Objetivos Genéricos** e suas respectivas **Práticas Genéricas** que podem se relacionar com mais de uma **PA**. O diagrama a seguir ilustra este fluxo.

![ES2_aula04_img02.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/ES2/ES2_aula04_img02.png)


## Objetivos do Teste de Software
Contraintuitivamente pode-se testar o software antes mesmo de ter um código implementado. O teste de software pode ser realizado na fase de modelagem do software.

Mesmo depois de um teste de software não se pode afirmar que o programa está correto.  Isso se deve ao fato de que se pode testar o software em muitos níveis e um único teste não vai lhe garantir que o software está perfeito. 

De maneira geral, a duração de um teste de software é ditada por tempo finito, dinheiro finito ou por ter terminado o plano de testes (desejável).

O teste de software é visto como um processo destrutivo sob o ponto de vista psicológico, contrário às outras fases da engenharia de software onde se constrói algo. As equipes de teste são as mais indigestas entre as equipes que atuam dentro do software.

Uma das principais causas de uma atividade de teste pobre é a falsa impressão de que testar é o processo de demonstrar que defeitos não estão presentes. Isso é estatisticamente impossível, todo software tem problemas, isso é algo inerente ao desenvolvimento.

O teste de software também não quer mostrar que o programa se comporta corretamente. Ele deve mostrar que existem problemas e que alguns são mais importantes que os outros.

O teste também não é o processo de estabelecer uma confiança que o programa faz o que é esperado dele. ***O teste é na verdade o processo de executar programas com o objetivo de revelar defeitos***.

A melhor forma de mostrar que um software é "perfeito" é tentando quebrá-lo de todas as formas possíveis e isso não pode ser feito com a ideologia de que o testador quer atrapalhar os desenvolvedores. Odeie o jogo e não o jogador.  

Um conceito no teste de software é o **teste exaustivo** que envolve testar todas as entradas possíveis para um programa. Isso é obviamente impossível, mas vale mencionar este conceito para termos em mente que nenhum processo de teste de software perfeito é possível.

Tendo isso em mente é criado o **plano de teste** que tem todas as informações sobre a equipe de teste, software de suporte, cronograma de atividades, técnicas e critérios seguidos, forma de execução dos casos de teste, forma de avaliação dos resultados e tudo mais que vai orquestrar um teste feito da melhor forma possível.

## Conceitos do teste de software
Existe uma hierarquia de termos usados, ela é:

**Defeito -> Erro -> Falha**

Um **defeito** é uma deficiência algorítmica que se ativada pode levar a uma falha. Um **erro** é um estado inconsistente decorrente da execução de um **defeito**. Já uma **falha** é um evento observável que mostra que o programa violou as especificações.

Um **caso de teste** é um conjunto de valores a serem fornecidos para o software e uma saída esperada para aquela entrada. Ele pode ser definido como uma **tupla \[d, O(d)\]** onde *d* representa um elemento de um domínio *D* que serve de entrada e *O(d)* é uma saída esperada para uma entrada *d*. 

O **oráculo** é quem decide (um robô automático ou uma pessoa) se a saída obtida é de fato esperada.

Por fim, vale ressaltar que projetar casos de teste pode ser tão difícil quanto projetar o próprio software. 


## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!
