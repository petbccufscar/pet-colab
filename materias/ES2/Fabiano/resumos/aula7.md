# Resumo Aula 7
> Resumo criado pelo aluno [João Pedro Trevisan](https://www.linkedin.com/in/joao-pedro-trevisan)

#### Professor
![Fabiano Ferrari](https://img.shields.io/badge/Fabiano_Ferrari-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)

## Integração Contínua
Originalmente cada desenvolvedor trabalhava de forma individual em sua parte do projeto e depois era realizada a integração. Contudo, tornar a integração uma parte separada do projeto é algo custoso tanto em questão de tempo quanto em questão de dinheiro.

Para resolver isso, a integração passa a ser uma parte do cotidiano do projeto. A **integração contínua** (usa-se a sigla **CI**, *continuous integration*) é a prática de automatizar a integração de alterações de código de vários colaboradores em um único projeto de software.

As tarefas associadas a isso são:
+ Gestão de repositório
	+ Uso de git, github, gitlab, gitbucket...
+ Automatização das *builds*
	+ Pode ser feito com makefiles ou com uso de ferramentas como o Maven ou GitHub Actions...
+ Teste das *builds*
	+ Uso de ferramentas e de arquivos .yml
+ *Commits* diários da equipe de desenvolvimento
+ *Commits* de *bug-fix*
+ Testes em clones do ambiente de produção
	+ Geralmente se tem 3 ambientes
		+ Desenvolvimento. Testes unitários locais
		+ Homologação. Testes de QA
		+ Produção. 

## Gestão de Repositório - Técnicas de Ramificação
Geralmente se ramifica um projeto com objetivos de dividir melhor o trabalho, descomplicar o compartilhamento de recursos e padronizar o trabalho.

Pode-se realizar a **ramificação de lançamento** para realizar todo trabalho em uma ramificação e depois integrá-la. Também existe a **ramificação de recurso** que permite "ligar e desligar" recursos de uma branch e há ainda a **ramificação de tarefas** que é o modelo convencional de realizar todo um trabalho em uma branch e então integrá-lo com a main.

## Automatização da Builds
As ***builds*** são contínuas e devem integrar pequenas alterações entre si. Elas devem ser criadas sem intervenções externas, é desejável que se realize **self-testing builds**.

O processo de se realizar um **build** consiste na recuperação da última versão do software, execução da **build**, teste da **build** e enfim **deploy** para o ambiente.

![ES2_aula07_img01.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/ES2/ES2_aula07_img01.png)

O primeiro passo da criação de uma **build** é a **compilação** que gera os arquivos binários e garante que as dependências e ferramentas estão em sintonia com o processo de *building*.

Depois o código é **analisado** de forma a verificar falhas que podem gerar dificuldade na manutenção do código, baixa qualidade de código ou mesmo problemas de segurança.

Depois é gerado o **artefato**. Este é o processo final no qual o pacote a ser lançado terá tudo incluído em si para garantir a instalação da aplicação.

## Automação de Testes
O automatizar dos testes é muito importante para a **integração contínua** pois melhora a estrutura do código, ajuda no entendimento e na correção de erros e auxilia o processo de integração. Isso exige um ótimo conhecimento do domínio da aplicação.

Existe um quadro chamado **quadrantes de teste ágil** que define uma taxonomia dos teses quanto a sua natureza e quanto a que setor de trabalho eles servem. Os teste podem ser:
+ **Automáticos**:
	+ Testes de unidade
	+ Testes de componente
+ **Manuais**:
	+ Teste exploratório
	+ Cenários
	+ Teste de usabilidade
	+ Teste de Aceitação do Usuário
	+ Versões Alpha/Beta
+ **Híbridos**:
	+ Testes Funcionais
	+ Exemplos
	+ User Stories
	+ Protótipos
	+ Simulações
+ **Feitos por ferramentas**:
	+ Teste de performance e carregamento
	+ Teste de Segurança
	+ Testes Métricas de Manutenibilidade

![ES2_aula07_img02.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/ES2/ES2_aula07_img02.png)


## Entrega e Implantação Contínuas
Existe ainda uma extensão do conceito de **integração contínua** que é a **entrega contínua**. Esta prática envolve o processo de lançamento automatizado, ainda que conte com intervenção manual para fazê-lo.

Esta prática gera alguns custos quando analisamos pelo viés dos testes que precisam ter boa cobertura, das im-plantações que também deverão ser automatizadas e da implementação de **feature flags**.

Os ganhos gerados, por sua vez, são a eliminação na complexidade de implantação do software, a aceleração do ciclo de feedback com o cliente e a menor pressão nas decisões de pequenas mudanças.

Um passo além da **entrega contínua** está a **implantação contínua** que além de tudo que faz a prática anterior libera para o cliente todas as mudanças nas etapas de produção e retira a intervenção humana para o lançamento.

Isso pode gerar custos na forma de um conjunto de testes ainda mais robusto, documentação atualizada constantemente e **feature flags** indispensáveis e mais robustas assim como os testes.

Os ganhos que podem contrabalancear estes custos pousam no fato de que não existe necessidade de pausar o desenvolvimento para realizar um lançamento, podem ser lançados pequenos lotes de alterações e os clientes veem melhorias diariamente.

## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!
