# Resumo Aula 5
> Resumo criado pelo aluno [João Pedro Trevisan](https://www.linkedin.com/in/joao-pedro-trevisan)

#### Professor
![Valter](https://img.shields.io/badge/Valter_Vieira_Camargo-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)


## Acoplamento - CBO: Coupling Between Objects
O conceito de **acoplamento** diz respeito a quando classes estão acopladas uma a outra. Um baixo nível de **acoplamento** indica um bom nível de **modularidade**, ou seja, mais independentes são as componentes do projeto.

Os tipos de **acoplamento** são **eferente** (de saída) e **aferente** (de entrada). No **acoplamento eferente** observamos *o número de classes dos quais a classe em análise depende*, isso nos fornece um indicativo do número de classes que precisam ser compreendidas para que a classe em análise seja compreendida além de nos fornecer uma probabilidade da classe em análise ser impactada por modificações nas classes que ela depende. Já no caso do **acoplamento aferente** observamos *o número de classes que dependem da classe em análise* e é intuitivo perceber que alterar esta classe pode gerar consequências para todas suas dependentes.

![POOA_aula05_img01.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/POOA/POOA_aula05_img01.png)

O diagrama a cima ilustra dependência entre classes, a relação entre as classes *8, 9 e 7* é uma relação de **acoplamento aferente** (entrada/*in*) e a relação entre as classes *7, 10, 11 e 12* é uma de **acoplamento eferente** (saída/*out*).

Note que quando falamos de **associação**, **herança** e **agregação** estamos falando de **acoplamento**.

Ao pensar em evoluções prováveis a um sistema de software deve-se pensar quais dessas mudanças vão impactar negativamente o **acoplamento**. Quando olhamos para uma porção *A* **acoplada** em *B* devemos avaliar se *A* está realmente interessada em todos os serviços de *B* e se não for o caso talvez valha a pena criar uma interface ou classe abstrata para *B* e colocar nela os serviços em que *A* tem interesse.

## Padrões GRASP
**GRASP** significa ***G****eneral* ***R****esponsibility* ***A****ssignment* ***S****oftware* ***P****atterns*

Estes padrões estão em nível de análise e seus objetivos são nos auxiliar em distribuir adequadamente as responsabilidades pelas classes do sistema, ou seja, responder as perguntas "*qual classe deve ser responsável por executar uma dada tarefa?*" e "*Como distribuo as responsabilidades sem aumentar o acoplamento?*"

Os três padrões que analisaremos nesta aula são:
+ **Especialista**
+ **Acoplamento Fraco**
+ **Controlador**

Tomemos como exemplo o seguinte diagrama:

![POOA_aula05_img02.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/POOA/POOA_aula05_img02.png)

Observe que não aparece a classe que seria o *Controller*, o qual manipula os objetos e faz interface com o *GUI*. Vamos manter em mente que o nível de acoplamento já foi acordado e não será alterado.

Ao adotar o padrão **especialista** estamos atribuindo responsabilidades ao **especialista** de uma informação, ou seja, a classe que determina alguma informação. No exemplo do sistema biblioteca a data prevista de devolução do livo é determinada pelo *tipo de leitor*, ou seja, a classe **especialista** no caso é a classe *Leitor* e portanto o método que informa a data de devolução deve ser da classe leitor. Isso favorece o **acoplamento fraco**, distribui as tarefas entre as classes que tem a informação necessária, tornando seus métodos mais leves e favorece o reuso de classes. 

Um diagrama que ilustra um modelo de comunicações possível consta na imagem a seguir. Note que ele acaba criando métodos e que a chamada ```data = calcularDataDevolucao()``` implica em atribuir ao Leitor o método ```calcularDataDevolucao()```.

![POOA_aula05_img03.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/POOA/POOA_aula05_img03.png)

Para promover o padrão de **acoplamento fraco** podemos dizer que um alto grau de acoplamento faz com que mudanças em classes interdependentes forçam mudanças em outras classes, quando uma classe está conectada a muitas outras é necessário entender toda uma cadeia de classes para compreender uma classe original e por fim isso dificulta o reuso de classes.

Pensemos no problema "*como favorecer a baixa dependência e aumentar a reutilização?*"

A resposta para isso pousa no atribuir responsabilidades de maneira que o acoplamento se mantenha baixo.

No sistema de biblioteca tomado como exemplo queremos criar a responsabilidade de devolução da cópia do livro por meio de um método com a assinatura ```devolverCopia(cdoCopia)```. Qual classe deve ser responsável pela tarefa de forma a não afetar o acoplamento? Pense que essa tarefa pode ser quebrada em tarefas menores.

Note a solução dada, ela não altera  o design original e portanto não impacta o grau de acoplamento de forma negativa:

![POOA_aula05_img04.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/POOA/POOA_aula05_img04.png)

Vejamos outro exemplo simples. Um sistema de vendas tem 3 classes: Registro, Pagamento e Venda. Queremos registrar o pagamento de uma venda, a classe Registro tem a função de registrar uma venda no mundo real e vamos supor que ela será responsável por criar o pagamento.

Observe a primeira tentativa de modelagem:

![POOA_aula05_img05.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/POOA/POOA_aula05_img05.png)

Esta alternativa para comunicações gera acoplamento entre Registro e Venda e entre Registro e Pagamento. Vejamos agora a alternativa número 2:

![POOA_aula05_img06.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/POOA/POOA_aula05_img06.png)

Perceba que esta alternativa a classe Registro não se acopla à classe Pagamento e portanto é uma solução melhor do ponto de vista do baixo acoplamento.

Devemos pensar que o extremo do acoplamento fraco não é desejável pois acabará ferindo os princípios da orientação a objetos, principalmente a *comunicação por mensagens* como visto em [[POOA_Aula03]]. A falta de comunicação entre classes gera excesso de responsabilidades, o que é indesejável também.

Por fim, falaremos do padrão chamado **controlador**. Para ilustrar melhor vamos tomar como base o questionamento "*quem deveria ser responsável por tratar um evento do sistema?*". 

A responsabilidade de receber ou tratar as mensagens de eventos (operações) do sistema pode ser atribuída uma classe que represente todo o sistema, um dispositivo ou subsistema (chamado de **controlador fachada**). Ou ainda podemos atribuir uma classe que represente um cenário de um caso de uso dentro do qual ocorre o evento (**controlador artificial**).

Voltemos ao exemplo do sistema de biblioteca, poderíamos criar chamadas ```iniciarEmprestimo()```, ```emprestarLivro()``` e ```encerrarEmprestimo()```. Em uma solução de **controlador de fachada** criaríamos uma só classe controladora que receberia todas estas comunicações, já no paradigma de **controlador artificial** seriam feitos controladores para cada caso de uso. A imagem a seguir ilustra as diferenças: 

![POOA_aula05_img07.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/POOA/POOA_aula05_img07.png)

Os benefícios do uso de um controlador são a reutilização de classes e o uso de **interfaces plugáveis**.
## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!
