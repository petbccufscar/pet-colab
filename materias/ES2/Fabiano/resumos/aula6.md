# Resumo Aula 6
> Resumo criado pelo aluno [João Pedro Trevisan](https://www.linkedin.com/in/joao-pedro-trevisan)

#### Professor
![Fabiano Ferrari](https://img.shields.io/badge/Fabiano_Ferrari-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)

## TDD - Test Driven Development
Anterior ao modelo **BDD** existia uma maneira de se organizar o desenvolvimento de software chamada **Test Driven Development** e, como o nome implica, era um processo guiado por testes de software.

Neste modelo os testes são escritos antes mesmo do código que é feito para passar nos testes. De inicio é feito apenas o necessário para passar no teste, mas refatorações são feitas nesse código de forma a amadurecê-lo e a cada iteração os testes são reaplicados.

A imagem a seguir ilustra um ciclo do **TDD**:

![ES2_aula06_img01.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/ES2/ES2_aula06_img01.png)

Este processo, contudo, não é exatamente intuitivo. Por onde se deve começar? O que deve ser testado? Como deve ser testado? Quanto devemos testar?

É então que em 2003 surge a ideia de apresentar o **TDD** com uma diferente roupagem.

## BDD - Behaviou Driven Design
Grande parte do que separa o **BDD** do **TDD** é o foco no comportamento das funcionalidades ao invés das partes unitárias do sistema.

O **BDD** é uma **metodologia ágil** que incentiva a colaboração e a interação entre todas as equipes ligadas ao projeto, os desenvolvedores utilizam sua linguagem nativa juntamente com termos que devem ser entendidos por todos os envolvidos no projeto. Ele ainda é um processo norteado por testes.

Outra coisa que separa o **BDD** das metodologias tradicionais é que em metodologias mais antigas o código sai de um analista, vai para um desenvolvedor e depois para o **quality assurance**. No **BDD** não há um fluxo entre estes setores, mas sim uma integração.

Diferente do **TDD**, o **BDD** não foca apenas a qualidade de código, mas abrange todas as áreas do projeto.

O **B** de **BDD** existe pois os testes são feitos com base em comportamentos desempenhados pelo usuário e comportamentos esperados do sistema. A seguir daremos um exemplo disso, neste caso de teste teremos **contexto**, **evento** e **resultado**:

+ **Contexto**:
	+ Dado que o saldo de uma conta é >= quantia requisitada**E**
	+ O cartão usado é válido **E**
	+ O caixa eletrônico tem dinheiro suficiente
+ **Evento**:
	+ Quando o dono da conta requisitar R$20,00
+ **Resultado**:
	+ O caixa eletrônico deve entregar R$20,00 **E**
	+ Deve ser debitado R$20,00 do saldo da conta

Os testes descrevem nada mais que um grupo de **comportamentos** que o usuário pode esperar do sistema. Todos os testes juntos formam um "contrato" mostrando o que o sistema deve exibir.

Estes **testes de comportamento** podem ser escritos a qualquer momento do desenvolvimento e é justamente escrever os testes antes de desenvolver um funcionalidade que gera o **Desenvolvimento Orientado por Comportamento** (Behaviour Driven Development).

Para se chegar à lista de comportamentos que se quer modelar é necessário que o **product owner** converse com o cliente de forma a levantar seus requisitos e em seguida elabore os comportamentos desejados junto de seus testadores e desenvolvedores que guiarão a equipe de programação.

Um problema deste modelo é que os testes comportamentais tendem a ser mais lentos quando comparados com testes unitários, além disso, quando estes testes falham eles apenas indicam que algo deu errado, mas nada informam sobre a raiz do problema.

O **BDD** pode ainda ser combinado com o **TDD** para tentar atacar as fraquezas de cada abordagem. Pode-se modelar um **comportamento** e testes de unidade que devem ser satisfeitos simultaneamente de forma a gerar uma metodologia mais completa.

Estas metodologias, porém, podem ser difíceis de se empregar em programas já desenvolvidos.

Sob está ótica, o **BDD** tenta melhorar o **TDD** ao formalizar suas práticas, focar na compreensão dos envolvidos, mostrar que o solicitado está funcional pro meio de testes e critérios de aceitação, usar ***user stories*** e **cenários* e a adoção de uma linguagem compreendida por todos.

As **user stories** são construídas com uma estrutura bem definida que preenche os seguinte parâmetros:
+ Como um {função/papel}
+ Eu quero {funcionalidade}
+ Para que {finalidade}

Por exemplo:

+ Como um **estudante**
+ Eu quero **acessar minha conta no ava**
+ Para que **eu possa checar minhas matérias**

Os **cenários** são tem uma forma semelhante, seus termos de construção são: **dado que**, **quando** e **então**. A título de exemplo continuaremos com o caso do estudante que quer acessar o ava:

+ **Dado que**: estou na página "ava2.ead.ufscar.br"
+ **Quando**: preencho o campo "nome de usuário" com um RA válido
	+ **OU** preencho o campo com um e-mail váilod
		+ **E** preencho o campo "senha" com a senha correspondente
		+ **E** clico em "acessar"
+ **Então**: sou redirecionado para á pagina inicial da minha conta no ava onde constam minhas matérias

Estes processos geram uma documentação simples e dinâmica, além de facilitar a comunicação e promover o compartilhamento de conhecimento entre todas as partes envolvidas no projeto.

## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!
