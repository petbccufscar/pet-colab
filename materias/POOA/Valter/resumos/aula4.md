# Resumo Aula 4
> Resumo criado pelo aluno [João Pedro Trevisan](https://www.linkedin.com/in/joao-pedro-trevisan)

#### Professor
![Valter](https://img.shields.io/badge/Valter_Vieira_Camargo-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)


## Coesão
O conceito de **coesão** significa a ligação harmônica entre duas partes, e é um conceito usado para manter um projeto claro e compreensível.  

Em engenharia de software falar sobre **coesão** refere-se a quando um componente possui uma única responsabilidade. Uma classe com **alta coesão** é aquela que tem somente uma responsabilidade e faz somente um tipo de tarefa. Uma classe com **baixa coesão** assume responsabilidades que deveriam ser delegadas a outras classes.  

Problemas gerados por **baixa coesão** são por exemplo o código confuso e de difícil compreensão, geração de erros em cadeia ao alterar uma dada classe, pouca reusabilidade.  Classes com nomes ruins podem incentivar baixa coesão.  

Uma maneira de se analisar a **coesão** de uma classe que é bem informal trata de supor mudanças em requisitos e analisar quais métodos seriam alterados em decorrência de tais mudanças. Se a alteração de um requisitos independentes exigir alterações na mesma classe ela pode não ser coesa.  

Tomemos como exemplo a base de códigos a seguir:

```	python
def read_dictionary(file)
	if File.extname(file) == ".xml"
		# read and return definitionas in XML from file
		
	else
		# read and return definitions in text from file
		
	end
	
end

def write_dictionary(file, definitions)
	if File.extname(file) == ".xml"
		#write definitions to file in XML
		
	else
		# write definitions to file in text
		
	end
	
end
```



Note que se precisarmos adicionar um novo tipo de arquivo a ser lido, .json por exemplo, precisaremos adicionar mais um bloco de condicional em cada um dos métodos, gerando uma grande quantidade de trabalho.  Uma solução melhor seria criar uma classe dicionário para conter todas as definições necessárias e delas criar subclasses para cada tipo de arquivo. Segue o exemplo:

```python
class XMLDictionary < Dictionary
	def write
		#write XML to @file using the @definitions hash
	end

	def read
		#read XML form @file and populate de @definitions hash
	end
	
end

class TextDictionary < Dictionary
	def write
		#write text to @file using the @definitions hash
	end

	def read
		#read text from @file and populate the @definitions hash
	end
	
end
```

Dessa maneira podemos ter a classe base ```Dicionáro``` suportando a criação de novas classes que herdam suas definições. Assim podemos ler qualquer tipo de arquivo sem ter que alterar classe nenhuma.  

## LCOM - Lack of Cohesion Metrics
Tomemos como exemplo uma classe que possui 2 métodos que alteram 2 atributos cada um deles. O diagrama abaixo representa isso, e nele é possível ver que existam "2 conjuntos diferentes". Para a métrica **LCOM** essa classe possui 2 responsabilidades.

![POOA_aula04_img01.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/POOA/POOA_aula04_img01.png)

A maneira que o **LCOM** usa para medir a falta de coerência é tomar uma componente *C1* que possui n operação *O1, O2, ..., On*, tomamos o conjunto *{Ai}* como o conjunto de atributos usados pela operação *Oi*. Seja *|V|* o número de intersecções vazias entre *pares de métodos* e *|nV|* o número de intersecções *não* vazias. Tomamos todas essas variáveis para medir o grau de **LCOO** em uma porção do sistema a ser analisada. A equação é a seguinte:  

**|V| - |nV|**, se |V| >= |nV|
**0**, se |V| < |nV|

Medimos também o número total de intersecções usando a fórmula da combinação. Nela *n* será o número de métodos da classe, *p* o número de elementos dos subconjuntos. Daí teremos:

**C(n,p) = n!/(p!(n-p)!)**

A partir de então os passos para se calcular a **LCOO** são:

1. Para cada método listar o conjunto de atributos que ele manipula
	+ M1 = {att1, att2}
	+ M2 = {att1, att3}
2. Fazer as intersecções dos pares de métodos. Devemos então montar as intersecções de todos os pares de métodos mostrando quais atributos são compartilhados por eles.
	+ M1 X M2 = {att1}
	+ M1 X M3 = {...}
	+ M1 X M4 = {...}
3. Contar o número de intersecções vazias **|V|** e o número de não vazias **|nV|**. 
	+ |V| = x
	+ |nV| = y
4. Aplicar o cálculo para se obter o valor de **LCOO**
	+ |V| - |nV| se V > nV
	+ 0 se V <= nV

Pode ser meio abstrato interpretar o valor resultante da **LCOO** por ser um número absoluto. O que um **LCOO** = 20 significa? Significa que existem 20 intersecções vazias a mais que não vazias, mas não informa se isso é muito ou pouco. Geralmente é boa prática considerar a porcentagem de interações vazias em relação as interações totais.  

Tomemos os seguintes cenários:  

- Cenário 1 (LCOO = 15):
	- V = 30
	- NV = 15
	- Total = 45 Interseções (classe com 10 métodos)
	- LCOO = 15 , pois 30 – 15 = 15
- Comparado com o total de interseções temos que
	- 33% (15 NV de 45) de todas interseções são não-vazias
	- 66% (30 V de 45) de todas interseções são vazias! Bastante...
	- Como mais da metade das interseções são vazias, isso sugere que realmente o número LCOO 15 é alto

- Cenário 2 (LCOO = 16):
	- V = 158  
	- NV = 142
	- Total = 300 interseções  (classe com 20 métodos)
	- LCOO = 16, pois 158  – 142 = 16
- Comparando com o total de interseções temos que
	- 47% (142 de 300) de todas as interseções são não vazias
	- 53% (158 de 300) de todas interseções são vazias.
	- O LCOO de 16 aqui não é tão ruim, pois está o número de vazias e não vazias estão próximos

Da contraposição de ambos cenários podemos conculir que primeiramente o tamanho do sistema influencia na porcentagem que encontraremos. Em segundo lugar podemos ver que mesmo que ambos os cenários tenham **LCOO**s semelhantes o cenário 2 (**LCOO** = 16) é bem mais aceitável que o cenário 1 (**LCOO** = 15) dadas as porcentagens de tipos de interações semelhantes no cenário 2. Por fim, se as porcentagens de interações vazias e não vazias forem muito díspares a coesão será comprometida.  

Um questinamento que podem surgir ao se fazer o uso do **LCOO** é como fazer seu cálculo em classes abstratas. Pode se contar toda a hierarquia como um só bloco ou simplesmente não considerar os métodos abstratos na sua contagem, faça o teste e interprete o que é melhor. 


## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!
