# Resumo Aula 7
> Resumo criado pelo aluno [João Pedro Trevisan](https://www.linkedin.com/in/joao-pedro-trevisan)

#### Professor
![Valter](https://img.shields.io/badge/Valter_Vieira_Camargo-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)


## Código Cliente
Código cliente é aquele trecho de código que usa/cria objetos, chama métodos, instancia funções. Muitas vezes é bom que esses códigos sejam independentes das classes que eles usam.  

No exemplo a seguir fica muito claro que a classe *Corrida* é o código cliente:

![POOA_aula07_img01.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/POOA/POOA_aula07_img01.png)


Isso nem sempre é claro, olhe o diagrama a seguir e tente encontrar o código cliente:

![POOA_aula07_img02.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/POOA/POOA_aula07_img02.png)


## Design Patterns
**Padrões de design** vem de problemas comuns da industria e que sempre eram resolvidos da mesma maneira ou de formas semelhante. **Padrões de projeto** não são **padrões de código**, eles são um nível acima da linguagem e fazem parte do planejamento da aplicação. 

Modelar um sistema no mundo real pode representar o presente, mas não necessariamente o futuro e a chave para o design flexível é a **abstração**.

Cada **padrão** é uma forma de estruturar as classes, métodos, atributos de forma bem definida. São soluções que visam facilitar a evolução do sistema pois baseiam-se em separar **código cliente** de código que é usado e polimorfismo/herança de forma facilitar a expansão do sistema.

Uma grande vantagem dos **padrões de design** é o uso de termos para descrever certos módulos de uma implementação como:
+ State
+ Strategy
+ Observer
+ Composite
+ etc...

Geralmente não se cria classes com este nome nos projetos.

Em se tratando de **padrões de design** não se programa para implementações específicas, mas sim para interfaces. A seguir existe uma lista dos **Gamma Design Patterns**:

![POOA_aula07_img03.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/POOA/POOA_aula07_img03.png)


Os atributos que descrevem um padrão são os seguintes: 
- Pattern Name and Classification
- Intent
- Also Known As
- Applicability
- Structure
- Participants
- Collaborations
- Consequences 
- Implementation
- Sample Code
- Known Uses  
- Related Patterns

## Padrão Factory
Este método é usado nas situações de não se saber previamente os tipos exatos e dependências dos objetos com os quais seu código deveria trabalhar ou quando quer se dar independência ao cliente dos objetos que ele usa.

Considere que se quer gerir empregados. Uma das responsabilidades da classe que fará isso é calcular os salários de cada tipo de empregado. Seria de bom tom que esta classe (*EmployeeManager*) não soubesse os tipos específicos de empregados que ela manipula.

Pense no seguinte código: 

``` java
class EmployeesManager {
	public calculateSalaries(){
	...
	Employee e1 = new Secretary()
	...
	Employee e2 = new SalesPerson()
	...
	}
}
```

Perceba que o código cliente é grandemente dependente dos tipos de empregado. Com a adição de novos empregados você terá que alterar esta classe e isso é ruim.

Note agora a estrutura geral de uma **Factory**:

![POOA_aula07_img04.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/POOA/POOA_aula07_img04.png)


Com este padrão o código cliente fica isolado do produto concreto sobre o qual ele operará. Note que, a intenção do padrão Factory fica mais clara e evidente quando pensamos em um sistema distribuído, em que classes precisam se comunicar sem saberem de antemão quem usará os seus métodos e quais métodos serão chamados.

O seguinte código em ```python``` cria um sistema com a estrutura anterior:

```python
class Creator:
	def factoryMethod(self) -> Product:
		raise NotImplementedError
		
class Product: 
	def doStuff(self) -> None:
		raise NotImplementedError 
		
class ConcreteCreator(Creator):
	def factoryMethod(self) -> Product:
		return ConcreteProduct()
		
class ConcreteProduct(Product):
	def doStuff(self) -> None:
		pass
```

Usaremos um problema exemplo para uma implementação completa: 

Imagine que seu sistema deve ter um meio de registrar *logs* da execução do sistema. Devem haver dois tipos de *log*, mas podem aparecer outros tipos no futuro. Como implementar isso de forma que o código cliente seja independente dos tipos de *logger*?

O código em ```python``` a seguir soluciona o problema:

``` python
import logging
import sys


class Logger:
	def log(self) -> None:
		raise NotImplementedError

class FileLogger(Logger):
	
	_filePath: None  
	
	def __init__(self, filePath: str) -> None:
		self._filePath = filePath
		
	def log(self) -> None:
		logging.basicConfig()
		logging.info('This message will get logged on to a file')

class StdoutLogger(Logger):
	
	def log(self) -> None:
		handler = logging.getLogger()
		handler.setLevel(logging.INFO)
		ch = logging.StreamHandler(sys.stdout)
		...
		handler.info('This message will get logged on to a stdout')
		
class LoggerFactory:
	
	def createLogger(self) -> Logger:
		raise NotImplementedError
		
class FileLoggerFactory(LoggerFactory):
	def createLogger(self) -> Logger:
		return FileLogger('file.log')
		
class StdoutLoggerFactory(LoggerFactory):
	def createLogger(self) -> Logger:
		return StdoutLogger()
```

Aqui está o diagrama do sistema criado:

![POOA_aula07_img05.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/POOA/POOA_aula07_img05.png)


O nosso código cliente ficaria da seguinte forma:

```python
if __name__ == "__main__":
	fileLogger = FileLoggerFactory().createLogger()
	fileLogger.log()
	
	stdoutLogger = StdoutLoggerFactory().createLogger()
	stdoutLogger.log()
```

## Singleton
Este **padrão** é usado quando classes devem possuir uma só instância. Exemplos de usos são classes que estabelecem conexões com bancos de dados, classes que representam sensores em robôs ou classes responsáveis por realizar o *logging* de eventos de sistema.

O código ```java```  a seguir cria um **singleton** para representar um sensor ultrassônico de um robô:

``` java
public class UltrasonicSensor {

	private static UltrasonicSensor ultrasonicSensorUniqueInstance;
	
	private UltrasonicSensor()  { ... }
	
	public static UltrasonicSensor getInstance(){  
	
		if (ultrasonicSensorUniqueInstance == null)
		{
			synchronized (UltrasonicSensor.class) 
				{
					if (ultrasonicSensorUniqueInstance == null) {
						ultrasonicSensorUniqueInstance = new UltrasonicSensor();
		}      }
	return ultrasonicSensorUniqueInstance;
	}
}
```

## Strategy
Este padrão é usado quando se quer usar várias versões de um algoritmo e se quer ser capaz de trocá-las em tempo de execução. Imagine que se quer fazer um programa para reuniões de vídeo on-line, pode se usar um tipo de algoritmo quando a conexão dos usuários esta boa e outro tipo quando a conexão está fraca.

![POOA_aula07_img06.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/POOA/POOA_aula07_img06.png)

O diagrama a cima mostra a estrutura do **padrão strategy**.

O código abaixo mostra uma implementação de um programa que controla o comportamento de robôs em ```java```:

```java
public class Robot {

	IBehaviour behaviour;
	String name;
	public Robot(String name)
	{
		...
	}
		
	public void move()
	{
		...
		int command = behaviour.moveCommand();
		...
	}
...
}


public interface IBehaviour {
	public int moveCommand();
}


public class NormalBehaviour implements Ibehaviour {
	
	public int moveCommand()
	{
		System.out.println("\tNormal Behaviour: if find"
			" another robot ignore it");
        return 0;
     }
}

public class DefensiveBehaviour implements Ibehaviour {              
	
	public int moveCommand()
	{
		System.out.println("\tDefensive Behaviour: if find"
			" another robot run from it");
		return -1;
	}
}

public class AgressiveBehaviour implements Ibehaviour{
	
	public int moveCommand()
	{
		System.out.println("\tAgressive Behaviour: if find"
			" another robot attack it");
		return 1;
	}
}

	
public class Robot {

	IBehaviour behaviour;
	String name;
	public Robot(String name)
	{
		...
	}
	
	public void move()
	{
		...
		int command = behaviour.moveCommand();
		...
	}
...
}


public class Main {
public static void main(String[] args) {
	Robot r1 = new Robot("Big Robot");
	Robot r2 = new Robot("C3PO"); 
	Robot r3 = new Robot("R2D2");
	
	r1.setBehaviour(new AgressiveBehaviour());
	r2.setBehaviour(new DefensiveBehaviour());
	r3.setBehaviour(new NormalBehaviour());
	r1.move();
	r2.move();
	r3.move();
	if (some condition) 
		 r1.setBehaviour(new DefensiveBehaviour());
		...
	if (some condition) 
		r2.setBehaviour(new AgressiveBehaviour());
		  
	r1.move();
	r2.move();
	r3.move();
```

## State
O padrão **state** implica algo semelhante a uma máquina de estados. Ele faz com que elementos do sistema transitem de um estado para outro de forma a mudar permissões e possibilidades associadas a uma componente. Os estados devem ser mutuamente exclusivos para que este padrão possa ser implementado.

O diagrama a seguir é um diagrama de estados UML e demonstra o comportamento de uma fração do sistema. A bolinha sólida indica o estado de entrada e a bolinha contornada representa o estado de saída. Note que não se pode alcançar o estado de saída quando a conta está bloqueada:

![POOA_aula07_img07.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/POOA/POOA_aula07_img07.png)

Usar o padrão **state** implica em criar uma classe para cada estado do elemento que estamos tratando, o seguinte diagrama representa isso:

![POOA_aula07_img08.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/POOA/POOA_aula07_img08.png)

O código a seguir em ```java``` implementa um portão eletrônico:

```java
public class EletronicGate {  
	
	private State currentState;
	private State previousState;
	
	public EletronicGate() {
		this.currentState = new Closed();
		this.previousState = null;
	}
	public void buttonPressed() {
		this.currentState.buttonPressed(this);
	}
	public void sensorActivated() {
	this.currentState.sensorActivated (this);
	}
}

public class Closed extends State {
	
	public void buttonPressed(EletronicGate eletronicGate) {
		eletronicGate.setCurrentState(new Opening());
		eletronicGate.setPreviousState(this);
	}
	public void sensorActivated(EletronicGate eletronicGate) {
		//nothing....
	}
}

public class Opened extends State {
	
	public void buttonPressed(EletronicGate eletronicGate) {
		eletronicGate.setCurrentState(new Closing());
		eletronicGate.setPreviousState(this);
	}
	public void sensorActivated(EletronicGate eletronicGate) {
		//nothing....
	}
}

public class Stoped extends State  {
	
	public void buttonPressed(EletronicGate eletronicGate) {
		if (eletronicGate.getPreviousState().indexOf("Opening") >= 1) {
			eletronicGate.setCurrentState(new Closing());
		} else {
			eletronicGate.setCurrentState(new Opening());
		}
		eletronicGate.setPreviousState(this);
	}
}
```

O diagrama a seguir é o que resulta deste código:

![POOA_aula07_img09.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/POOA/POOA_aula07_img09.png)

## Observer/listener/pub-sub
Este padrão é usado quando o **estado** no qual um objeto se encontra vai influir no comportamento de outros objetos e não se sabe quantos objetos serão afetados pela mudança de estado em um dado objeto.

O diagrama a seguir explicita a ideia geral deste conceito:

![POOA_aula07_img10.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/POOA/POOA_aula07_img10.png)

O código em ```java``` a seguir usa uma API qualquer para implementar um sensor de luz de um robô:

``` java
public class TestProgram {  
	 
	public static void main(String[] args){    
		TestProgramm a = new TestProgramm ();  
		a.go();  
	}  
	
	public void go (){  
		MyLightListener lightListener = new MyLightListener ();
		//concrete observer  
		MyTouchListener touchListener = new MyTouchListener ();
		//concrete observer  
		
	LightSensor light = new LightSensor (SensorPort.S1);  
	TouchSensor touch = new TouchSensor (SensorPort.S2);  
	   
	SensorPort.S1.addSensorPortListener(lightListener);  //ATTACH  
	SensorPort.S2.addSensorPortListener(touchListener);  //ATTACH  
	   
	LCD.drawString("LightListener:", 0, 1);  
	LCD.drawString("TouchListener:", 0, 4);  
	  
	Button.waitForPress();  
}


class MyLightListener implements SensorPortListener {   
	@overrides
	
	public void stateChanged(SensorPort source, int oldValue, 
		int newValue) {  
	LCD.drawString("alt: "+ oldValue + "   neu: " + 
		newValue, 0, 2);  
	}    
}


class MyTouchListener implements SensorPortListener {
	@overrides
	
	public void stateChanged (SensorPort source, int oldValue, 
		int newValue){  
	LCD.drawString("alt: " + oldValue + "   neu: " + 
		newValue, 0, 5);  
	}
}
```

Fica implementado um sistema da seguinte forma:

![POOA_aula07_img11.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/POOA/POOA_aula07_img11.png)


## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!
