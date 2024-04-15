# Resumo Aula 10
> Resumo criado pelo aluno [João Pedro Trevisan](https://www.linkedin.com/in/joao-pedro-trevisan)

#### Professor
![Fabiano Ferrari](https://img.shields.io/badge/Fabiano_Ferrari-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)

## JUnit
O **JUnit** é um *framework* para teste de software em ```java```, ou seja, não é uma aplicação pronta. Ele foi criado em 1997 e seu foco é o **teste de unidade** que focam classes ou partes específicas do nosso código. Isso é muito importante para o **teste de regressão** que foca em realizar os mesmos processos em iterações diferentes do código de forma a checar se ele de fato atende as funcionalidades que antes atendia.

Algumas ferramentas de software podem fazer uso do plugin **JUnit** e portanto ser mais robustas que ele próprio ao fornecer sessões de teste, medidas quantitativas de qualidade e criação de relatórios. Ainda assim o foco do nosso estudo será no básico de **JUnit**.

O **JUnit** se tornou uma espécie de padrão no teste de software e deu orgiem à "**família XUnit**" que são ferramentas de teste de unidade que não atendem apenas o ```java```.

A arquitetura do **JUnit** envolve as classes abstratas *CasoDeTeste* e *SuiteDeTeste* que implementam a interface *Test* que usará os métodos das outras classes. O **JUnit** é um *framework* pelo fato de que para fazer uso dos métodos destas classes abstratas você precisa instanciar suas próprias classes de *Test*.

Existe também a classe *Assert* que elenca as assertivas daquele teste, valores a serem checados para determinar se um teste passou ou não. Ela faz o papel do **oráculo**.

A imagem a seguir mostra a arquitetura do **JUnit**:

![ES2_aula10_img01.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/ES2/ES2_aula10_img01.png)

A título de revisão vale a pena tocarmos nos conceitos de **requisito de teste**, **caso de teste** e **oráculo**.
+ **Requisito de teste**: elemento (ou porção) do software que deve ser exercitado durante os testes.
+ **Caso de teste**: conjunto de entradas fornecidas ao sistema para cobrir um determinado requisito de teste, e a saída esperada após a execução.
+ **Oráculo**: é quem decide se o comportamento do software com a execução do caso de teste é o esperado ou não, ou seja, se o software passou ou falhou no teste.

## Criando Testes em JUnit 3
Como foi exposto antes, a classe *TestCase* deve ser estendida e os métodos a serem implementados devem iniciar com a palavra ```test```. Assim serão criados os **casos de teste**.

As assertivas da classe *Assert* devem ser usadas para checar valores e comportamentos da unidade de forma a ver se a saída do teste é a esperada.

A notação dessas assertivas é a seguinte:

```java
// checa se os valores batem
assertEquals(valorEsperado, valorObtido, precisão)

// checa saida verdadeira
assertTrue(condição)

// checa saida falsa
assertFalse(condição)

// checa se foi retornado valor NULL
assertNotNull(objeto)
```

Esta classe ainda pode ser estendida para criar assertivas personalizadas.

Antes de cada caso de teste utilizado é usado o método ```setUp()``` que serve para realizar uma configuração prévia aos testes. Isso pode ser usado por exemplo para inicializar objetos ou conexões.

Existe também o método ```tearDown()```que é usado no momento oposto do ```setUp()```. Ele tem o objetivo de excluir arquivos temporários, encerrar conexões e basicamente "limpar a casa" depois do teste.

Por fim, outro método que vale a pena ser citado é o ```fail(String msg)``` que força uma falha quando é alcançado e retorna uma mensagem. É análogo a usar um ```system.out.println("\nNao era pra chegar aqui.\n")```.

Indo à alguns exemplos tomaremos uma classe que determina um ponto em um plano cartesiano e é capaz de calcular a distância entre um ponto e outro que este primeiro recebe como parâmetro:

```java
public class Point {
	
	private double x, y;
	
	public double distance(Point p) {
		double dist = 0;
		dist = Math.sqrt( Math.pow(this.x-p.getX(),2) +
			Math.pow(this.y-p.getY(),2) );
		return dist;
	}
	
	public void setPoint(double x, double y) {
		this.x = x;
		this.y = y;
	}
}
```

Criaremos agora uma classe de testes para avaliar a classe *Point*:

```java
import junit.framework.TestCase;

public class PointTest extends TestCase {
	
	Point p1, p2;
	public void setUp() {
		p1 = new Point();
		p2 = new Point();
	}
		
		
	public void testDistanceBetweenPoints() {
		
		p1.setPoint(0, 0);
		p2.setPoint(0, 5);
		assertEquals(5, p1.distance(p2), 0f);
	}
		
		
	public void testDistanceSamePoint() {
		p1.setPoint(0, 0);
		assertEquals(0, p1.distance(p1), 0f);
		}
		
		public void testNull() {
			Point p3 = null;
			try {
			assertEquals(0, p1.distance(p3), 0f);
		}
		catch(NullPointerException e) {
			return;
		}
		
		fail("nao deveria chegar aqui...");
	}
}
```

Note que a classe de teste deve estender a classe *TestCase*. Nesta classe de testes instanciamos dois objetos do tipo ponto e usamos o método ```setUp()``` para iniciar estes objetos.

Criamos logo abaixo um caso de teste no qual criamos pontos com 5 unidades de distância e nas assertivas a serem checadas determinamos que esta distância já previamente conhecida deve retornar 5.

Temos também a porção que testa a distância de um ponto a ele mesmo e sabemos que o retorno tem que ser 0. Há o caso de testes para objetos nulos e a a assertiva que busca encontrar 0 na distância entre um objeto existente e outro nulo, no caso deste teste cair do ```catch()``` que busca valores nulos ela retorna (sucesso) e sai do caso de teste, caso contrário chegaremos ao método ```fail()``` que forçará uma falha e exibirá uma mensagem. 

## Teste no JUnit 4
No **JUnit 4** o teste muda um pouco de figura. Ele ainda pode ser feito por meio de extensão das classes de teste, mas geralmente são usadas *Java Anotations*. Os métodos de teste devem iniciar com "*@Test*" 

Estas anotações são usadas também para realizar coisas que antes eram feitas com métodos, por exemplo, usar ```@Before()``` faz o mesmo que o uso do método ```setUp()``` para cada caso de teste de uma classe. Já o uso de ```@BeforeClass()``` faz o mesmo mas para todos os casos da classe de uma só vez.

As anotações ```@After()```e ```@AfterClass``` são usadas de forma análoga, mas substituindo o métodod ```tearDown()```.

A seguir converteremos os testes passados de **JUnit 3** para **JUnit 4**:

```java
import org.junit.Test;
import static org.junit.Assert.*;
import org.junit.Before;

public class PointTest { // nao estende a classe TestCase
		
	Point p1, p2;
		
	@Before
	public void initializePoints() {
		p1 = new Point();
		p2 = new Point();
	}
		
	@Test
	public void distanceBetweenPoints() { // sem test no nome
		p1.setPoint(0, 0);
		p2.setPoint(0, 5);
		assertEquals(5, p1.distance(p2), 0f);
	}
		
	@Test
	public void distanceSamePoint() {
		p1.setPoint(0, 0);
		assertEquals(0, p1.distance(p1), 0f);
	}
		
	@Test(expected= NullPointerException.class)
	public void testNull() {
		Point p3 = null;
		try {
		assertEquals(0, p1.distance(p3), 0f);
		}
		catch(NullPointerException e) {
		throw e;
		}
		fail("should not get here...");
	}
}
```

[Neste vídeo](https://www.youtube.com/watch?v=tn2llyySIVY) o professor demonstra o uso destes testes dentro do próprio Eclipse, vale a pena ver a execução.

## Contato
Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!
