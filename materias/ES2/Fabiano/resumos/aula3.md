# Resumo Aula 3
> Resumo criado pelo aluno [João Pedro Trevisan](https://www.linkedin.com/in/joao-pedro-trevisan)

#### Professor
![Fabiano Ferrari](https://img.shields.io/badge/Fabiano_Ferrari-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)

## Processo Unificado de Desenvolvimento de Software
O processo unificado é um modelo de design de software usado principalmente atrelado ao paradigma Orientado a Objeto. Ele combina métodos individuais de James Rumbaugh, Grady Brooch e Ivar Jacobson, seus esforços iniciais acabaram cirando a UML. Em um segundo projeto eles criaram  **PUD**.

Suas características são:
+ Fases divididas em uma série de iterações 
	+ **Concepção**, feita com o cliente
	+ **Elaboração** por meio da criação de casos de uso
	+ **Construção** do código
	+ **Transição** que envolve testes e feedback para aprovar o produto construído em parceria com o cliente
	+ **Produção,** etapa em que o software é posto em atividade
+ Caso de uso são essenciais para a construção
+ Grande foco na arquitetura do modelo ao longo do projeto
+ Ênfase na comunicação com o cliente
+ Listagem e ponderagem dos riscos atrelados às decisões do projeto

Este modelo de desenvolvimento foi refinado muitas vezes ao longo dos anos, muito em decorrência de sua idade. Alguns exemplos são o *Rational Unified Process*, *Essential Unified Process*, *Basic/Open Unified Process*, *Agile Unified Process* e *Enterprise Unified Process*.

O **RUP** (*rational unified process*) tradicional tem as características de asdkjasdkjas

Ele foi desenvolvido pela empresa *Rational Software Corporation* como um produto HTML. São 3 estratégias que norteiam o RUP: Processo adaptável, uso de ferramentas que automatizam a alocação do processo e servições que facilitam a adoção do processo e das ferramentas

O processo pretende descrever *quem vai fazer o que, como e quando*. Os termos usados são:
+ Papeis: funções de cada funcionário, é comum acumular papéis ou ter mais que uma pessoa desempenhando um mesmo papel. Existem 5 super tipos, o analista, o desenvolvedor, gerente testador e suporte, além de 26 outros papeis mais específicos e não necessariamente existentes em todos projetos.
+ Atividades: Durante as atividades de desenvolvimento os detentores de papeis criam artefatos.
+ Artefatos: Tudo que é produzido durante o processo, pode ser composto por outros artefatos. Uma atividade pode conter artefatos de entrada que são aqueles necessários para se realizar uma atividade e os de saída que são os produtos alvo. O **RUP** possui 9 tipos de artefatos.   
+ Fluxos de trabalho: Ordem que as coisas devem ser feitas
+ Disciplinas: Decidem que artefatos devem ser realizados, que papéis devem realizá-los e qual o fluxo de trabalho. Elas definem o **RUP**. **Preciso voltar no slide dos maninhos pra pegar o que cada uma faz**.
	+ Existem as **disciplinas de engenharia** que são: 
		+ Modelagem de Negócios: responsável pela comunicação com os clientes e usuários para modelar as questões do projeto partindo da visão de organização
		+ Requisitos: Transforma as necessidades das partes interessadas em requisitos para a criação do sistema
		+ Análise e design: Cria o sistema com classes, pacotes e subsistemas com interfaces bem definidas
		+ Implementação: Organiza a criação do código, binárias, executáveis, componentes e testes de unidade
		+ Teste: Marcante presença no fim da fase de construção e no início da fase de transição. Realizam testes de integração a fim de checar se os requisitos foram cumpridos
		+ Implantação: Faz a entrega ao usuário final por meio da distribuição de uma *release*
	+ Existem também as disciplinas de apoio e suporte que envolvem:
		+ Gerenciamento de Projeto: Gerencia o desenvolvimento do sistema, define as métricas a serem testadas e calcula os riscos do projeto
		+ Gerenciamento de Configuração e Mudança: Gerenciam as mudanças, o **controle de versões** (como visto na [Aula 2](./aula2.md)) e de dependências
		+ Ambiente: Usada na personalização do **RUP**, a fim de adequar seu funcionamento dentro do contexto do projeto que está sendo aplicado.

O diagrama a seguir mostra as disciplinas junto das fases do Processo Unificado e uma medida de seu grau de atividade em cada uma delas: 

![ES2_aula03_img01.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/ES2/ES2_aula03_img01.png)

A imagem que segue mostra de maneira geral o ciclo de desenvolvimento do **RUP**:  

![ES2_aula03_img02.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/ES2/ES2_aula03_img02.png)

Um diagrama um pouco mais detalhado que apresenta todos os artefatos do **RUP** junto de um fluxo deles pode ser visto a seguir:  

![ES2_aula03_img03.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/ES2/ES2_aula03_img03.png)


## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!
