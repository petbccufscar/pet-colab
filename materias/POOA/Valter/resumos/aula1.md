# Resumo Aula 1
> Resumo criado pelo aluno [João Pedro Trevisan](https://www.linkedin.com/in/joao-pedro-trevisan)

#### Professor
![Valter](https://img.shields.io/badge/Valter_Vieira_Camargo-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)


## Abstração
Abstração é o processo de filtrar e ignorar as características e padrões que não são necessários com objetivo de concentrar no que é necessário. Desse processo surge uma representação do que se está tentando resolver. Segundo *Colburn e Shute*, a ciência da computação sendo primariamente preocupada com o desenvolvimento de padrões de interação tem a ocultação de informação como objetivo de abstração. Um grande exemplo de abstração são as camadas colocadas sobre um sistema de computador, uma linguagem como C é uma abstração da linguagem de máquina.  

## As Bases da Ciência da Computação
As 4 bases da ciência da computação são **decomposição** de problemas, **abstração** para que o funcionamento de uma solução seja fácil de entender e usar para usuários e programadores, **reconhecimento de padrões** para a generalização de processos que os tornam mais fáceis de serem encarados e **algorítimos** que é óbvio.  

Fazendo uso de tudo isso temos o exemplo do problema de se desenhar uma série de gatos. Podemos notar que todo gato tem algumas características gerais como pelo, cauda e olhos. Estas características são relevantes para o desenho do gato, mas informações como se ele gosta ou não de subir no telhado são irrelevantes. Partindo das características relevantes é possível **modelar** um gato básico e então implementar variações.  

## Design for Change
O conceito de **DFX** significa ***Design For X***, ou seja, projetar para algum objetivo particular. Um exemplo na industria seria por exemplo *Design For Assembly* (projeto para montagem), uma fábrica cria as partes de um dado produto e o envia para uma maquiladora que apenas montará este produto, seja com mão de obra seja com máquinas.  

No caso, **Design For Change** significa projetar pensando que aquilo poderá ser mudado. Mudanças não antecipadas são custosas em tempo e em volume de trabalho, logo projetar tendo em mente que aquele software será alterado constantemente é necessário. 

A introdução do conceito de **DFC** pousa sobre a indagação de como se decompor um sistema em objetos. Modelar um sistema no mundo real pode representar o presente mas não necessariamente representar o futuro. **Abstrações** usadas durante o projeto são a chave para design flexível.  

Existe também o conceito de **interface** que não diz respeito a interfaces de usuário, mas sim a interações entre elementos. O conceito pode ser resumido em "*como* ***A*** *fala com e escuta* ***B***".  

Outra forma de definir **interfaces** é como "*o conjunto de assinaturas que um objeto expõe*", ou seja, é por meio desta **interface** que um dado objeto diz ao mundo todos os pedidos que podem ser feitos a ele. As interfaces não dizem nada sobre a implementação de um objeto (como aquilo foi projetado "*debaixo do capô*").  

Um **tipo** (**type**) é o nome usado para denotar uma interface específica, objetos tem vários **tipos** que compõem uma **hierarquia**.  

A técnica primordial para o polimorfismo em POO é o **dynamic binding**. Ele consiste do link entre um pedido para um objeto para uma de suas operações em *runtime*. O termo *dynamic* é usado pois este link é feito instanciando objetos não definidos, mas sim de maneira geral, note os exemplos em UML e Java:  

![POOA_aula01_img01.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/POOA/POOA_aula01_img01.png)

Note que se usarmos a chamada a seguir estaremos fazendo uso de uma ligação dinâmica:  

```java
anUndefinedRobot.printInformation();
```

Num outro tipo de implementação feita com **static binding** poderíamos ter o seguinte esquema:  

![POOA_aula01_img02.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/POOA/POOA_aula01_img02.png)

Nela faríamos a chamada:  

```java
aLegoRobot.printInformation();
```

é uma ligação estática (**static binding**) pois necessita saber o nome do robô em questão e não permite o uso de um mesmo método em vários objetos. Note também que no primeiro esquema a interface *instancia* as classes e no segundo ela as *chama* diretamente.  

Se pensarmos em modificar este sistema, quando usamos **dynamic binding** a vantagem principal está em que não precisamos criar novos métodos no *InformationManager* para cada robô, fazendo o uso de **static binding** precisamos realizar muito mais trabalho. Ainda assim, em ambos os casos, precisamos alterar o método *printInformation()*.  

Um outro conceito importante é o de **delegation**. Ele é semelhante a **herança** e auxilia na composição de objetos. Perceba que quando usamos **delegação** precisamos fazer referência a classe que receberá a delegação na definição dos objetos, no caso quem delega na imagem a seguir é *window*.  

![POOA_aula01_img03.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/POOA/POOA_aula01_img03.png)

## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!
