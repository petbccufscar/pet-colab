# Resumo Aula 3
> Resumo criado pelo aluno [João Pedro Trevisan](https://www.linkedin.com/in/joao-pedro-trevisan)

#### Professor
![Valter](https://img.shields.io/badge/Valter_Vieira_Camargo-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)


## Conceitos de Orientação a Objetos
Os conceitos de **OO** são vários e dentre eles temos a **abstração**, também conhecido como **caixa preta**. Este nome vem pois este conceito consiste da encapsulação de uma função de sistema de forma que esta função receba uma entrada e entregue uma saída sem que possa ser visto o que ocorre dentro daquela função.  

Os conceitos mais óbvios da **OO** são os conceitos de **classes** e **objetos**. Os **objetos** são ocorrências das **classes** e representam alguma coisa, generalizada ou não, do mundo real.  

**Mensagens** são um conceito de **OO** que consistem em um sinal enviado para um objeto a outro requisitando um serviço por meio de um método. Essa interação se dá dentro de uma classe com base no seu alcance dentro da hierarquia de classes. Geralmente uma mensagem é retornada e esta mensagem de retorno se chama **callback**.  

Ainda sobre **mensagens** é preciso implementar **relacionamentos** para que os objetos possam se comunicar um com o outro.  

Existem também os conceitos de **agregação** e **composição** e eles estarão presentes quando objetos representam partes de um todo. Sob esta visão um objeto que represente um todo pode ser **composto** por partes, já a **agregação** é expressa como um tipo de associação que deve ser clara num diagrama que representa o sistema mas não é necessariamente clara no código.  

Um objeto "*parte*" quando necessita de um objeto "*todo*" expressa uma **composição**, a **agregação** por sua vez não exige que haja um objeto "*todo*", suas partes são independentes. Note o seguinte exemplo de **agregação** e perceba que cada componente de um desktop pode existir de maneira independente:  

![POOA_aula03_img01.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/POOA/POOA_aula03_img01.png)

Para um exemplo de **composição** note a imagem a seguir:  

![POOA_aula03_img02.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/POOA/POOA_aula03_img02.png)

Note a notação UML usada. As cardinalidades das relações revelam que na figura primeira as componentes do Desktop podem existir atreladas a 0 ou 1 computador, já na segunda imagem a cardinalidade mostra que deve haver pelo menos um Imóvel associado a suas componentes. Note também as cores das setas, uma seta vazia representa **agregação** e uma seta preenchida representa **composição**. A imagem a seguir resume a notação:  

![POOA_aula03_img03.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/POOA/POOA_aula03_img03.png)


## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!
