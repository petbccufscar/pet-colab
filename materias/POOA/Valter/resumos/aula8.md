# Resumo Aula 8
> Resumo criado pelo aluno [João Pedro Trevisan](https://www.linkedin.com/in/joao-pedro-trevisan)

#### Professor
![Valter](https://img.shields.io/badge/Valter_Vieira_Camargo-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)


## Interfaces
Interfaces são usadas para restringir a visibilidade dos serviços oferecidos por uma classe a outra. De forma geral podemos pensar em algo assim: 

![POOA_aula08_img01.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/POOA/POOA_aula08_img01.png)

Este padrão de design é ótimo para gerenciar o acesso a classes entre pacotes. Ele permite que seja decidido quais classes de um pacote podem ser vistas por outro.

Note que o encapsulamento proposto por este modelo só funciona com o uso de uma *Factory*, pois é desta forma que não criaremos um cliente no código *main*:

![POOA_aula08_img02.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/POOA/POOA_aula08_img02.png)


Ainda assim nem todos os objetos a serem criados podem ter *factories*, caso contrário se código vai ficar gigantesco.

O código ```java``` a seguir implementa um sistema tal qual o diagrama passado:

``` java
package View;

import Controller.*;

public class View {
	
	public static void main (String args[]){
		float divida = Controller.getDividaCliente(1);
		System.out.println("A divida do cliente é " + divida);
	}
}


package Controller;

import Model.*;

public class Controller  {

public static float getDividaCliente(int idCliente){
		
		ICliente c = FactoryCliente.createCliente(idCliente); 
		return c.calcularDivida(idCliente);
	}
}

package Model;

class Cliente implements ICliente {
		
	public float calcularDivida() {
		return x * 3/4 * (z + u);  
	}
}

public class FactoryCliente {
	
	public static ICliente criaObjetosCliente(int id){
		return //recupera cliente do BD;
	}
}

public interface ICliente {
	
	public float calcularDivida();
}
```

É importante notar que uma interface sempre será criada como link entre duas classes que precisam interagir. Imagine um sistema de empresa que tenha as classes *funcionário*, *dependente*, *departamento* e *projeto*. Agora imagine que queremos comunicar *funcionário + dependente*, *funcionário + projeto*, e *projeto + departamento*. Neste caso criaremos as interfaces seguintes:
+ ***IFuncDept***
+ ***IFuncProj***
+ ***IProjDept***

## Composite
O **padrão composite** é usado quando precisamos representar uma composição de objetos e permitir que clientes deste **composite** possam chamar métodos de seus clientes da mesma maneira.

Este padrão induz uma árvore de dependências pois seus elementos agregados podem ser uma composição nova ou um objeto sem associações (uma folha da árvore). Observe:

![POOA_aula08_img03.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/POOA/POOA_aula08_img03.png)


Em termos de UML, possuímos uma definição recursiva de **composite** muito interessante:

![POOA_aula08_img04.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/POOA/POOA_aula08_img04.png)


Imagine um menu cheio de itens. Cada item pode abrir um outro menu quando selecionado.  Podemos pensar também em um diretório que pode conter novos diretórios ou apenas arquivos.

## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!
