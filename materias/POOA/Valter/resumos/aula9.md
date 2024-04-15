# Resumo Aula 9
> Resumo criado pelo aluno [João Pedro Trevisan](https://www.linkedin.com/in/joao-pedro-trevisan)

#### Professor
![Valter](https://img.shields.io/badge/Valter_Vieira_Camargo-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)


## Princípios S.O.L.I.D
O design de soluções orientadas a objeto pode seguir uma série de padrões conforme estudamos até aqui. **SOLID** é a sigla que abarca 5 princípios diferentes de design orientado a objeto:
+ **S**ingle Responsibility Principle
	+ Princípio de responsabilidade única
+ **O**pen/Closed Principle
	+ Princípio aberto/fechado
+ **L**iskov Substitution Principle
	+ Princípio da substituição de Liskov
+ **I**nterface Segregation Principle
	+ Princípio de segregação de interfaces
+ **D**ependency Inversion Principle
	+ Princípio de inversão de dependências

![POOA_aula09_img01.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/POOA/POOA_aula09_img01.png)

Estes princípios foram introduzidos pro Robert C. Martin (o famoso Uncle Bob) e segundo ele todo sistema orientado a objeto deveria seguir estes princípios com objetivo de ter uma boa qualidade organizacional de código.

O princípio de **Single Responsibility** é relacionado à **coesão** do código. Ele prega que "*uma classe coesa é aquela que possui apenas uma responsabilidade*" e portanto terá "*apenas uma razão para mudar*" se for o caso de ser alterada.

O princípio **Open/Closed** por sua vez prega que "*um módulo deveria ser aberto para* ***extensão*** *e fechado para* ***modificação***", ou seja, classes devem permitir que suas capacidades sejam aumentadas/aprimoradas sem que seu código fonte seja alterado diretamente.

Isso pode ser alcançado por meio do uso de **herança** ou **delegação** como visto em [[POOA_Aula01]]. Segundo esta ideologia um módulo esta **aberto** quando é possível que sejam adicionados atributos e métodos ao conjunto de funções que ele já possui. O módulo estará **fechado** quando para que se seu comportamento seja estendido devam haver modificações em seu código fonte.

Estar **fechado** não é algo axiomaticamente ruim, significa também que o módulo tem uma interface clara usada por outros métodos, contudo esta interface é imutável.

Avançando para o princípio **Liskov Substitution** precisamos lembrar que a base da herança entre classes dita que se uma classe *B* é subtipo de uma classe *A* todas as propriedades de *A* devem ser satisfeitas por *B*. Isso de certa forma pode ser relacionado à teoria dos conjuntos ao dizer que *B* é subconjunto de *A* e portanto os objetos de *B* devem compartilhar as características de *A*.

Este princípio tem o nome em homenagem a Barbara Liskov e pode ser resumido na frase "*subclasses devem ser substitutíveis por suas classes base*". 

Este princípio é usado para decidirmos se devemos criar subtipos ou usar outra estratégia como **delegação** ou **composição**. Se *q(x)* é uma propriedade os objetos *x* de tipo *T* então a mesma propriedade *q(y)* deve valer para objetos *y* de tipo *S* se *S* for um subtipo de *T*.

Usando um exemplo em ```java``` iremos ilustrar:

```java
/*Imagine que queremos criar uma classe pássaro*/

public class Bird{
	// atributos de passaro
	// metodos de passaro
	public void fly(){
	}
}

/*Se fossemos extender esta subclasse, que aves estariam contempladas pelo metodo fly()?
  No caso de querermos criar uma classe pinguim ou avestruz a classe pai da heranca nao nos permitira fazer um subtipo correto.
  Melhor seria fazer o seguinte: */

public class Bird{
	// atributos de passaro
	// metodos de passaro
}

public class FlyingBird extends Bird{
	// atributos de passaro voador
	// metodos de passaro voador
	public void fly(){
	}
}

public class Duck extends FlyingBird{
	// atributos de pato
	// metodos de pato
}
public class Penguin extends Bird{
	// atributos de pinguim
	// metodos de pinguim
}
public class Ostrich extends Bird{
	// atributos de avestruz
	// metodos de avestruz
}
```

Tratando-se agora do princípio **Interface Segregation**, ele prega que "*muitas interfaces específicas de cliente são melhores que uma interface de propósito geral*". De forma básica é melhor que cada cliente tenha sua própria interface, observe:

Ruim:
![POOA_aula09_img02.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/POOA/POOA_aula09_img02.png)

Melhor:
![POOA_aula09_img03.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/POOA/POOA_aula09_img03.png)

Por fim, temos o princípio conhecido como **Dependency Inversion** que prega "*dependa de abstrações e não de coisas concretas*". Isto é, módulos de alto nível não devem depender de módulos de baixo nível, mas sim de suas **abstrações**. **Abstrações** não devem depender de detalhes mas sim os detalhes dependerem delas.

Ao programar fazendo com que módulos se refiram diretamente aos seus colaboradores concretos não usamos um nível correto de abstração. Uma solução elegante para esta questão é o uso do padrão de design **factory** como visto na [Aula 7](./aula7.md).

Este princípio faz com que busquemos fazer as dependências se apoiarem em classes abstratas ou interfaces e está diretamente ligado com um **smell arquitetural** (sinal de problema) chamado **Unstable Dependency** que ocorre quando um módulo depende de outro que é menos estável do que ele mesmo.

## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!