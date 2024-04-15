# Resumo Aula 2
> Resumo criado pelo aluno [João Pedro Trevisan](https://www.linkedin.com/in/joao-pedro-trevisan)

#### Professor
![Fabiano Ferrari](https://img.shields.io/badge/Fabiano_Ferrari-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)

## Gerenciamento de Configuração de Software
O processo de desenvolvimento de software envolve muitas etapas dentro das quais o controle das versões de cada componente é muito importante. Contudo, engana-se quem acha que uma vez que o produto é entregue este processo acaba. Após finalizada, uma aplicação segue o processo de manutenção contínua de suas funções, muitas delas vão demandar concertos, muitas delas vão ser atualizadas.  

**Gerenciar Configurações** de software significa coordenar o desenvolvimento de forma a gerar organização. É um elemento de suma importância para a qualidade final de um software e será aplicada em todo o desenvolvimento do projeto de software.  

A imagem a seguir representa um fluxo do desenvolvimento de software. No quadro à direita estão listadas práticas que suportam o desenvolvimento de software:  

![ES2_aula02_img01.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/ES2/ES2_aula02_img01.png)

O termo **item de configuração de software** descreve o produto de software ou de desenvolvimento de software para fazer parte da configuração de uma dada aplicação em desenvolvimento. Isso engloba tanto os softwares de suporte à **configuração de software** ou mesmo as práticas e modelos a serem seguidos. A **configuração de software**, por sua vez é o conjunto de itens de configuração de software inter-relacionados. O **gerenciamento de configuração de software** é o conjunto de atividades que devem ser desenvolvidas para administrar as alterações durante o ciclo de vida de um programa.  

**CM** (***Configuration Management***) é uma **Área de Processo** (***Process Area - PA***). Dentro deste campo os grupos de trabalho são graduados em níveis, o nível 1 chamado de "*caótico*" é atribuído a projetos pelo **CMMI** quando eles não possuem processos de **gerenciamento de configurações**.  

## Conceitos Fundamentais
**Baseline**: Uma especificação ou produto que foi formalmente revisada e aprovada e servirá de base para o desenvolvimento futuro. Ela só pode ser alterada através de processos formais de controle de modificação. Um **item de configuração de software** que passou a constar oficialmente em uma versão de software é chamado **baselined**, ou seja, ele foi revisado formalmente, é base para trabalho futuro é armazenado em um repositório de itens de configuração e só será alterado por meio de procedimentos de controle formais.  

**Repositório de Itens de Configuração**: Um repositório de tal tipo é um local sob controle de acesso onde são armazenados itens de configuração de software depois de liberados por uma baseline. Um exemplo de **repositório de itens de configuração** é uma *biblioteca de projeto*. Itens de configuração escolhidos devem ser identificados, analisados, corrigidos, aprovados e armazenados. Estes itens só são alterados mediante a aprovação de uma solicitação de alteração por um gerente de configuração para haver controle e para evitar inconsistências.  

**Check-in/Check-out**: É o método usado para trabalhar com **itens de configuração** em um repositório. Quando for desejada uma alteração em algum desses itens uma cópia dele é posta na área de trabalho de um *dev* (**check-out**). Após o final das alterações ele será revisado e colocado no repositório (**check-in**). Uma nova linha de referência será traçada de modo que uma nova configuração contendo o item alterado seja formada e congelada no repositório e depois do congelamento o acesso é liberado permitindo que outros desenvolvedores possam alterar o novo item de configuração. A imagem a seguir mostra o funcionamento deste mecanismo.  

![ES2_aula02_img02.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/ES2/ES2_aula02_img02.png)

**Controle de Histórico**: Permite desfazer alterações em documentos e analisar suas versões. Ajuda resgatar versões mais estáveis.  

**Controle de Versões Estáveis**: Uma função que permite marcar uma versão de um documento ou software como uma versão estável para critérios de recuperação do projeto.  

**Ramificação de Projeto**: Uma divisão do projeto em novas linhas de desenvolvimento que saem da linha principal de forma a usar uma das versões para seguir outro rumo. 

## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!
