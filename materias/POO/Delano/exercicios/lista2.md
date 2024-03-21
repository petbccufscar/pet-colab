# Lista de Exercícios 1

#### Professor
[![Delano](https://img.shields.io/badge/Delano-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)](https://site.dc.ufscar.br/docente/5cd02e5568371e00162127f4)


## CLASSES ABSTRATAS
### Atividade: Suponha que você faz parte de uma equipe de desenvolvimento que foi contratada para desenvolver um sistema de gerenciamento (catálogo) de obras de arte de um museu. Após a fase de levantamento de requisitos do sistema, a equipe identificou que as obras de arte são apenas de duas categorias — pinturas e esculturas — e que compartilham algumas características em comum: título, artista, material e ano de criação. Dessa forma, a modelagem orientada a objetos do sistema é composta das 4 classes discutidas nas próximas seções.

### O catálogo de obras de arte será implementado através das seguintes classes: ObraDeArte, Pintura, Escultura e Museu. Organize suas classes no namespace catalogo.
![image](https://github.com/petbccufscar/pet-colab/assets/99228768/fbb159dc-686c-4573-9fca-dc4ee19ddbd2)

## Classe ObraDeArte:
### A classe abstrata ObraDeArte deverá conter atributos privados para armazenar os seguintes dados sobre as mídias: título, artista, material sobre o qual esta foi feita (papel, tela, madeira, etc) e ano de criação. Esta classe deverá também conter um ou mais métodos (métodos getters/setters) que permitam a atribuição/recuperação de valores para cada um dos atributos. A classe ObraDeArte deve conter pelo menos os seguintes métodos/construtores:
### • ObraDeArte(string titulo, string artista, string material, int anoCriacao). Construtor único da classe que recebe os valores iniciais dos atributos título, artista, material e ano de criação.
### • int getCategoria(). Método abstrato que deve ser implementado pelas subclasses de ObraDeArte.
### • void imprimeFicha(). Método abstrato que deve ser implementado pelas subclasses de ObraDeArte. Esse método imprime uma ficha contendo os dados da obra de arte semelhante às apresentadas a seguir.
![image](https://github.com/petbccufscar/pet-colab/assets/99228768/b11cde4f-6a66-4918-b9fc-383ac4bb9652)

## Classe Pintura:
### A classe Pintura representa uma pintura e deve conter o seguinte atributo: tipo (óleo, aquarela, etc). Esta classe deverá também conter um ou mais métodos (métodos getters/setters) que permitam a atribuição/recuperação de valores para cada um dos atributos. Essa classe deve conter pelo menos os seguintes métodos:
### • Pintura(string titulo, string artista, string material, int anoCriacao, string tipo). Construtor único da classe que recebe os valores iniciais dos atributos.
### • int getCategoria(). Implementação do método que retorna um inteiro que representa a categoria. [Pintura = 1 e Escultura = 2]
### • void imprimeFicha(). Implementação do método que imprime os dados da pintura. [Exemplo: ver ficha (a) apresentada anteriormente]

## Classe Escultura:
### A classe Escultura representa uma escultura e deve conter o seguinte atributo: altura. Esta classe deverá também conter um ou mais métodos (métodos getters/setters) que permitam a atribuição/recuperação de valores para cada um dos atributos. Essa classe deve conter pelo menos os seguintes métodos:
### • Escultura(string titulo, string artista, string material, int anoCriacao, double altura). Construtor único da classe que recebe os valores iniciais dos atributos.
### • int getCategoria(). Implementação do método que retorna um inteiro que representa a categoria. [Pintura = 1 e Escultura = 2]
### • void imprimeFicha(). Implementação do método que imprime os dados da escultura. [Exemplo: ver ficha (b) apresentada anteriormente]

## Classe Museu: 
### A classe Museu possui o atributo nome que representa o nome do museu. Esta classe deverá também conter um ou mais métodos (métodos getters/setters) que permitam a atribuição/recuperação de valores do atributo nome. Por fim essa classe possui o atributo obras que representa um relacionamento de 1 para N com a classe abstrata ObraDeArte (As obras de arte são categorizadas em: pinturas e esculturas). A classe Museu deve conter pelo menos os seguintes métodos:
### • boolean adicionaObra(ObraDeArte* obra). Adiciona uma obra de arte ao catálogo.
### • boolean removeObra(string titulo). Remove uma obra de arte (cujo título é igual ao parâmetro passado) do catálogo.
### • ObraDeArte* obtemObra(string titulo). Método que retorna a obra de arte cujo título é igual ao parâmetro passado e null, caso a obra de arte não seja encontrada no catálogo.
### • int qtdeObras(). Fornece a quantidade de obras no catálogo.
### • int qtdePinturas(). Fornece a quantidade de pinturas no catálogo.
### • int qtdeEsculturas(). Fornece a quantidade de esculturas no catálogo.
### • void imprime(). Imprime as fichas das obras de arte da coleção, ordenadas pelo ano + título. Isto é, as obras de arte são ordenadas levando em consideração o ano da obra de arte. Caso duas obras de arte tenham o mesmo ano, então são ordenadas pelo título.
### • void imprimePorCategoria(int categoria). Imprime as fichas das obras de arte de uma determinada categoria, ordenadas pelo ano + título. Isto é, as obras de arte são ordenadas levando em consideração o ano da obras de arte. Caso duas obras de arte tenham o mesmo ano, então são ordenadas pelo título. [Pintura = 1 e Escultura = 2]


## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!
