# Resumo Aula 12
> Resumo criado pelo aluno [João Pedro Trevisan](https://www.linkedin.com/in/joao-pedro-trevisan)

#### Professor
![Fabiano Ferrari](https://img.shields.io/badge/Fabiano_Ferrari-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)

## Manutenção de Software
A **manutenção** é uma atividade da etapa de operação do software já construído e entregue. É claro que isso não é algo tão bem delineado hoje que métodos de entrega incremental são usados para desenvolver sistemas muitas vezes enquanto eles estão sendo usados.

Depois da **manutenção** é necessário realizar a **revalidação** que envolve muitas vezes testes de regressão para garantir que as partes que funcionavam continuam funcionando.

![ES2_aula12_img01.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/ES2/ES2_aula12_img01.png)

Existem vários tipos de **manutenção** em software. Alguns exemplos são:
+ **Manutenção corretiva** para corrigir erros
+ **Manutenção perfectiva** para melhorar performance ou outros atributos
+ **Manutenção adaptativa** para adaptar o software ao ambiente
+ **Manutenção preventiva** para facilitar a manutenibilidade ou confiabilidade

Sobre **manutenção corretiva** é bom sabermos que defeitos de codificação são geralmente baratos de se corrigir, ao passo que defeitos de projeto são, via de regra, mais caros pelo fato de envolverem a correção de diversos níveis de abstração. Não só isso, defeitos nas etapas de requisitos são os mais caros de serem corrigidos porque envolvem muitos e muitos artefatos.

A **manutenção perfectiva** busca muitas vezes atender pedidos do usuário para modificar funcionalidades existentes, incluir novas funcionalidades ou efetuar melhorias gerais. Geralmente é uma forma de alinhar o softwares a tendências do mercado.

**Manutenções adaptativas** vem como fruto de mudanças de infraestrutura. Imagine que foi trocado o SGBD, o sistema operacional ou o hardware sobre o qual uma aplicação roda, tudo isso pode exigir adaptações de software. Este tipo de manutenção pode vir também como fruto de mudanças ou adições de requisitos pelo usuário ou as vezes por alterações de leis.

Realizar **manutenções preventivas** envolve atividades como a refatoração de software, por exemplo, que vai facilitar o trabalho futuro dentro do software. Diferente dos outros, este tipo de **manutenção** tem como foco o desenvolvedor e sua facilidade de trabalho.

As atividades de **manutenção** são a parte mais custosa da implementação de um software e chegam a ocupar 70% do volume de trabalho de empresas de software. Isso se deve a muitos fatores.

Um software tem uma média de idade de uso de 10 a 15 anos. Quando foram implementados os softwares mais antigos o espaço de armazenamento das aplicações era muito caro. Eles podem precisar migrar para novas plataformas ou podem ter sido feitos de maneira mal estruturada.

Os custos da **manutenção** nem sempre são monetários. As consequências de ser forçado a realizar manutenções passam pelo adiamento de oportunidades de desenvolvimento, insatisfação do cliente, redução da qualidade global do software.

Os custos da **manutenção** tem muito a ver com a interpretação do software (tentar entender o que as coisas fazem) e as atividades de se analisar, avaliar, codificar e testar modificações.

Uma métrica para se avaliar o esforço em se realizar **manutenção** são modelados na seguinte equação. Note que as variáveis não são coisas exatamente determinísticas:

**M = p + Ke^(c-d)**

Com *M = esforço total*
*p = esforço produtivo*
*k = constante empírica*
*c = complexidade advinda de falhas de projeto e documentação*
*d = grau de familiaridade com o software*

Os problemas mais clássicos das atividades de manutenção estão relacionados a deficiências na maneira que o software foi planejado.

Pode ser que seja difícil traçar a evolução de um software através de suas funções com alterações não documentadas adequadamente. Isso é chamado de **débito técnico** e permeia muitos projetos.

Outro problema tem relação com não conseguir traçar o processo pelo qual o software foi construído.

Entender o código não documentado de outrem é um problema clássico e revoltante do desenvolvimento de software.

Outro problema grande é quando a aplicação não foi projetada para suportar alterações.

## Manutenibilidade
**Manutenibilidade** é definida como a facilidade com que o software pode ser compreendido, corrigido, adaptado e/ou melhorado.

Alguns dos fatores que influenciam a **manutenibilidade** são:

+  Cuidado inadequado com o projeto, codificação e teste.  
+ Configuração de software ruim.  
+ Disponibilidade de pessoal qualificado de software.  
+ Facilidade de manusear o sistema.  
+ Uso de linguagens de programação padronizadas.  
+ Uso de sistemas operacionais padronizados.
+ Estruturas padronizadas de documentação.
+ Disponibilidade da pessoa ou grupo que desenvolveu o software.
+ ***Design for maintenance***.

A manutenibilidade de um sistema é algo difícil de se quantificar e é por isso que se criam as **métricas de manutenibilidade**.

Algumas dessas métricas são:
+ Tempo de reconhecimento do problema
	+ O tanto que a equipe de operação ou manutenção demora pra reconhecer o problema
+ Tempo de demora administrativa 
	+ Tempo que aquela manutenção passa na fila de tarefas de manutenção a serem feitas
+ Tempo de coleta de ferramentas de manutenção
	+ Tempo pra se preencher algo do gênero de um **bug report**.
+ Tempo de análise do problema 
+ Tempo de especificação da alteração  
+ Tempo de correção ou modificação  
+ Tempo de teste local e global  
+ Tempo de revisão da manutenção

Estas métricas são medidas de esforço a serem coletadas sobre cada manutenção a ser realizada e ao longo do tempo se constrói um perfil de manutenibilidade de um sistema que permite compará-lo com outros.

Pensar em manutenção é algo que deve ocorrer em todos os níveis do processo de engenharia de software. Pode ser que seja necessária a **revisão de requisitos** que visa áreas de melhoramentos futuros, aspectos de portabilidade de software e interfaces que podem impactar a manutenção futura. A **revisão do projeto** pode tratar do projeto arquitetural, procedimental, de interfaces e de dados buscando uma facilidade em alterar e iterar esses elementos.

Outro tipo de revisão muito importante é a **revisão de código** que tende enfatizar os padrões de codificação do projeto e a documentação interna dos arquivos de código. Por fim, podemos também fazer a **revisão de teste** que olha para cada passo do processo de teste em busca de encontrar indícios sobre partes do software que poderiam exigir manutenção preventiva.

Existem normas de manutenção que buscam nortear os projetos de software e uma delas é a **ISO 9126** que prega que os fatores de qualidade de software focam em 3 aspectos do produto: habilidade de ser alterado, adaptabilidade a novos ambientes e caracterísiticas operacionais.

![ES2_aula12_img02.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/ES2/ES2_aula12_img02.png)

As **tarefas de manutenção** em um projeto de software são muitas e pode-se definir uma passo a passo a ser seguido:

1. Estabelecer uma organização da manutenção:
![ES2_aula12_img03.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/ES2/ES2_aula12_img03.png)

2. Descrever os procedimentos de avaliação e de comunicação:
![ES2_aula12_img04.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/ES2/ES2_aula12_img04.png)

3. Definir sequências padronizadas de eventos para os pedidos de manutenção:
![ES2_aula12_img05.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/ES2/ES2_aula12_img05.png)

4. Estabelecer procedimentos para registrar a história das atividades de manutenção. Alguns exemplos de dados que podem ser armazenados são:
- identificação do programa  
- linguagem de programação usada  
- data da instalação do programa  
- número de execuções do programa desde a instalação  
- número de falhas de processamento associadas ao item anterior  
- nível e identificação da alteração no programa  
- número de pessoas-horas despendidos na manutenção  
- identificação do pedido de manutenção  
- tipo de manutenção  
- datas de início e fim da manutenção

5. Definir critério de revisão e avaliação. Eles podem ser baseados em muitas coisas e dentre elas as **métricas de manutenção** citadas previamente.

Todo esse processo é documentado e organizado num conjunto de práticas por uma série de livros chamada **ITIL** composta pleo governo britânico. Existem certificações em **ITIL**.

Por fim, um problema que podemos encontrar ao realizar manutenção em software é a **manutenção em código alienígena** que significa operar sobre código com tecnologias obsoletas e de difícil manutenção. Essa manutenção é mais cara mas muitas vezes devem ser realizadas.

Sistemas bancários, por exemplo, podem ter 20, 30 ou 40 anos, mas ainda estão em operação.

**Software Legado** pode ser caracterizado como **software alienígena**. Existe uma série de problemas em operar com este tipo de sistema e algumas delas são o uso de arquiteturas antigas ou de nenhuma arquitetura, a escassez de profissionais que dominam a tecnologia, documentação ruim.

Uma boa solução para trabalhar neste tipo de ambiente é o uso da **engenharia reversa** ou a **reengenharia** que serão estudadas na próxima aula.


## Contato
Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!
