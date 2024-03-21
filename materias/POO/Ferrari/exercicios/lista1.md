# Lista de Exercícios 1

#### Professor
[![Ferrari](https://img.shields.io/badge/Ferrari-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)](https://site.dc.ufscar.br/docente/5cefcb3648365a001679f773)


## Introdução
### Para cada classe criada nos exercícios propostos a seguir, crie o arquivo de definição da classe (extensão .h), o arquivo de implementação (extensão .cpp) e o arquivo principal (Main.cpp) para testar as funcionalidades implementadas.Para cada classe criada nos exercícios propostos a seguir, crie o arquivo de definição da classe (extensão .h), o arquivo de implementação (extensão .cpp) e o arquivo principal (Main.cpp) para testar as funcionalidades implementadas.

## Exercícios
### 1. Crie uma classe chamada Complexos para fazer aritmética com números complexos. Os números complexos têm a seguinte forma: Utilize atributos privados do tipo double para representar os dados da classe. Forneça um método construtor que possibilite que um objeto da classe Complexos seja inicializado quando declarado. O construtor deve conter valores default no caso de nenhum valor inicializador ser fornecido. Além dos setters e getters necessários, crie métodos públicos para cada um dos seguintes itens:
a) **plus**: adição de dois números complexos, sendo que as partes reais são somadas, e as partes imaginárias são somadas.\
b) **minus**: subtração de dois números complexos, sendo que as partes reais são subtraídas, e as partes imaginárias são subtraídas.\
c) **toString**: cria uma string que representa um número complexo no formato (a, b), onde a é a parte real e b é a parte imaginária.\

### Defina um conjunto de dados de teste e o utilize para testar a classe Complexo. Lembre-se que os dados de entrada são do tipo double, e que diversas possibilidades de criação de um objeto da classe Complexo devem ser exercitadas (por exemplo, passando para o construtor dois valores válidos, passando somente um valor, e sem passar valor algum). Exercite também as funcionalidades de soma, subtração e criação da string.

### 2. Crie uma classe chamada Retangulo para representar o objeto geométrico retângulo. A classe deve ter os atributos comprimento e altura, cada um do tipo double e com valor default igual a 1 (um). Além dos setters e getters necessários, a classe deve ter também os métodos getPerimetro e getArea, que calculam o perímetro e a área do retângulo, espectivamente. Os setters devem verificar se os valores de comprimento e altura estão no intervalo [0, 20]. Crie também o método toString para construir uma string que representa o retângulo no seguinte formato: {c, a}, sendo “c” o comprimento e 2. “a” a altura.
### Defina um conjunto de dados e os utilize para testar a classe Retangulo. Lembre-se que os dados de entrada são do tipo double, e que diversas possibilidades de criação de um objeto da classe Retangulo devem ser exercitadas (por exemplo, passando para o construtor valores válidos, passando somente parte dos valores válidos, e sem passar valor válido algum). Exercite também as funcionalidades de cálculo de perímetro e área e de criação da string.

### 3. Crie uma classe chamada Retangulo mais sofisticada do que a criada no exercício anterior. Essa nova classe armazena somente as coordenadas cartesianas dos quatro cantos do retângulo. Cada coordenada é composta dois valores, que representam os valores de x e de y no plano cartesiano. O construtor chama um método setter que recebe o conjunto de coordenadas e verifica que todos encontram-se no primeiro quadrante, ou seja, estão no intervalo [0, 20]. Esse método setter também verifica se de fato as coordenadas representam um retângulo. Outros métodos dever calcular o comprimento, a altura, o perímetro e a área do retângulo, nomeados getComprimento, getAltura, getPerimetro e getArea. Considere que o comprimento é a maior das duas dimensões (entre comprimento e altura). Crie também um método chamado isQuadrado para decidir se o retângulo é um quadrado; esse método deve retornar um valor do tipo boolean. Por fim, crie o método toString para construir uma string que representa o retângulo; defina um formato que achar adequado para a string criada.
### Defina um conjunto de dados e os utilize para testar a nova classe Retangulo. Lembre-se que os dados de entrada são do tipo double, e que diversas possibilidades de criação de um objeto da classe Retangulo devem ser exercitadas (por exemplo, passando para o construtor valores válidos, passando somente parte dos valores válidos, e sem passar valor válido algum). Exercite também as funcionalidades de cálculos (comprimento, altura, perímetro e área) e de criação da string.


### 4. Crie uma classe chamada ContaDePoupanca para representar contas de caderneta de poupança. Utilize um atributo estático taxaDeJurosAnual para armazenar a taxa de juros cobrada no período de um ano. Uma conta de poupança tem os atributos cliente, dataDeAbertura, e saldo, que armazenam o cliente, a data de abertura, e do saldo atual da conta, respectivamente. cliente é uma instância da classe Cliente, que tem os atributos nome, CPF e telefoneDeContato. para armazenar o nome, o número de CPF e o telefone de contado do cliente. dataDeAbertura é uma instância da classe Data, que tem os atributos dia, mes e ano, para armazenar os campos que representam uma data. Crie o método calcularRendimentoMensal na classe ContaDePoupanca que calcula o rendimento mensal da poupança multiplicando o saldo pela taxaDeJurosAnual dividida por 12; esse rendimento deve ser somado ao saldo corrente da poupança. Crie também um método que permita atualizar a taxaDeJurosAnual. Para todas as classes, crie também todos os setters e getters necessários, assim como os métodos toString para construir uma string que representa cada objeto manipulado; defina um formato que achar adequado para a string criada. Defina um conjunto de dados e os utilize para testar a classe ContaDePoupanca. Exercite todas as funcionalidades criadas para a classe.


## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!
