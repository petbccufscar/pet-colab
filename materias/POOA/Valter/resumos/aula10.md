# Resumo Aula 10
> Resumo criado pelo aluno [João Pedro Trevisan](https://www.linkedin.com/in/joao-pedro-trevisan)

#### Professor
![Valter](https://img.shields.io/badge/Valter_Vieira_Camargo-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)


## Smells de Código
A manutenção de um software é uma atividade essencial para qualquer sistema de software. De 50% a 80% dos custos de software estão relacionados a atividades de manutenção que vão da reparação de falhas até adaptações à diferentes hardwares ou sistemas ou adição/modificação de requisitos.

A manutenção de software não pressupõe boas práticas de design devido a questões mercadológicas que fazem os times correrem para entregar resultados.

O termo **code smell** refere-se a uma indicação superficial de que há um problema profundo no sistema. *Smell* significa cheiro.

Eles são sintomas de escolhas de design ruins e implementações mal feitas. Isso é visto em códigos incompreensíveis, propensão a falhas e diminuição da capacidade de manutenção do sistema.

**Code smells** não impedem o sistema de funcionar e tampouco são falhas ou erros no código.

![POOA_aula10_img01.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/POOA/POOA_aula10_img01.png)

Um exemplo de **smell** é a representatividade dos parâmetros que uma função recebe. Observe as duas funções:

```java
public void doSomething(String nome, int RA, String codDpto, int anoIngresso) {
.
.
.
}

public void doSomething(Student estudante){
.
.
.
}
```

Ambas funções tratam da classe *Student*, mas a primeira recebe seus atributos individualmente. Qual delas é mais legível?

Este é um exemplo simples, mas existe uma taxonomia dos **code smells**, ou seja, eles são listados por nomes e tipos e são coisa de 30 **smells**. Não estudaremos todos a fundo.

Eles são:

- [Dispensables](https://pragmaticways.com/31-code-smells-you-must-know/#Dispensables):
    1.  [Comments](https://pragmaticways.com/31-code-smells-you-must-know/#1_Comments)
    2. [Duplicate Code](https://pragmaticways.com/31-code-smells-you-must-know/#2_Duplicate_Code)
    3. [Lazy Class](https://pragmaticways.com/31-code-smells-you-must-know/#3_Lazy_Class)
    4. [Dead Code](https://pragmaticways.com/31-code-smells-you-must-know/#4_Dead_Code)
    5. [Speculative Generality](https://pragmaticways.com/31-code-smells-you-must-know/#5_Speculative_Generality)
    6. [Oddball Solution](https://pragmaticways.com/31-code-smells-you-must-know/#6_Oddball_Solution)

- [Bloaters](https://pragmaticways.com/31-code-smells-you-must-know/#Bloaters):
  1. [Large Class](https://pragmaticways.com/31-code-smells-you-must-know/#7_Large_Class)
  2. [Long Method](https://pragmaticways.com/31-code-smells-you-must-know/#8_Long_Method)
  3. [Long Parameter List](https://pragmaticways.com/31-code-smells-you-must-know/#9_Long_Parameter_List)
  4.  [Primitive Obsession](https://pragmaticways.com/31-code-smells-you-must-know/#10_Primitive_Obsession)
  5.  [Data Clumps](https://pragmaticways.com/31-code-smells-you-must-know/#11_Data_Clumps)

- [Abusers](https://pragmaticways.com/31-code-smells-you-must-know/#Abusers):
  1.  [Switch Statements](https://pragmaticways.com/31-code-smells-you-must-know/#12_Switch_Statements)
  2.  [Temporary Field](https://pragmaticways.com/31-code-smells-you-must-know/#13_Temporary_Field)
  3.  [Refused Bequest](https://pragmaticways.com/31-code-smells-you-must-know/#14_Refused_Bequest)
  4.  [Alternative Classes with Different Interfaces](https://pragmaticways.com/31-code-smells-you-must-know/#15_Alternative_Classes_with_Different_Interfaces)
  5.  [Combinatorial Explosion](https://pragmaticways.com/31-code-smells-you-must-know/#16_Combinatorial_Explosion)
  6.  [Conditional Complexity](https://pragmaticways.com/31-code-smells-you-must-know/#17_Conditional_Complexity)

- [Couplers](https://pragmaticways.com/31-code-smells-you-must-know/#Couplers):
  1.  [Inappropriate Intimacy](https://pragmaticways.com/31-code-smells-you-must-know/#18_Inappropriate_Intimacy)
  2.  [Indecent Exposure](https://pragmaticways.com/31-code-smells-you-must-know/#19_Indecent_Exposure)
  3.  [Feature Envy](https://pragmaticways.com/31-code-smells-you-must-know/#20_Feature_Envy)
  4.  [Message Chains](https://pragmaticways.com/31-code-smells-you-must-know/#21_Message_Chains)
  5.  [Middle Man](https://pragmaticways.com/31-code-smells-you-must-know/#22_Middle_Man)

- [Preventers](https://pragmaticways.com/31-code-smells-you-must-know/#Preventers):
  1.  [Divergent Change](https://pragmaticways.com/31-code-smells-you-must-know/#23_Divergent_Change)
  2.  [Shotgun Surgery](https://pragmaticways.com/31-code-smells-you-must-know/#24_Shotgun_Surgery)
  3.  [Parallel Inheritance Hierarchies](https://pragmaticways.com/31-code-smells-you-must-know/#25_Parallel_Inheritance_Hierarchies)
  4.  [Solution Sprawl](https://pragmaticways.com/31-code-smells-you-must-know/#26_Solution_Sprawl)

- [Other notable mentions](https://pragmaticways.com/31-code-smells-you-must-know/#Other_notable_mentions):
  1.  [Inconsistent Names](https://pragmaticways.com/31-code-smells-you-must-know/#27_Inconsistent_Names)
  2.  [Uncommunicative Name](https://pragmaticways.com/31-code-smells-you-must-know/#28_Uncommunicative_Name)
  3.  [Type Embedded in Name](https://pragmaticways.com/31-code-smells-you-must-know/#29_Type_Embedded_in_Name)
  4.  [Magic Numbers](https://pragmaticways.com/31-code-smells-you-must-know/#30_Magic_Numbers)
  5.  [Incomplete Library Class](https://pragmaticways.com/31-code-smells-you-must-know/#31_Incomplete_Library_Class)

Os **smells** estudandos em aula são: 7 - **Large Class**, 2- **Code Duplication** e 20 - **Feature Envy**. Fala-se sobre métricas para detectar os **smells** no código.

A **large class** pode ser detectada se uma classe possui mais que 1.000 linhas de código. Outra forma é proposta por Trifu e, outra ainda por Kaur nos slides 16 e 17 respectivamente.

Normalmente uma **large/god class** é demasiadamente complexa para reutilização e para testes, ela pode ser muito complexa e possivelmente faz uso de recursos demais.

No slide 21 tem as métricas para se detectar **code duplication** (mesmo código em partes diferentes do sistema) e no slide 24 temos métricas que identificam o **feature envy** (classe que usa muitos *gets* para acessar dados de uma outra classe, gera acoplamento, dificulta compreensão e manutenção).

## Smell Arquitetural
São decisões de nível de arquitetura que impactam negativamente a qualidade interna do sistema. Eles podem ser causados pela aplicação de soluções de design em contexto inadequado, mistura de fragmentos de design ou aplicações de abstrações com nível errado de granularidade.

Eles são: 
1. Dependência cíclica
2. Dependência Instável
3. Interface Ambígua
4. Componente "Deus"
5. Concatenação de features
6. Funcionalidade espalhada
7. Estrutura Densa

Em aula estudamos a **dependência cíclica** que é definida como a situação na qual um subsistema está envolvido em uma cadeia de relações que modelam um ciclo. Uma métrica para encontrá-lo é o mergulho em profundidade na árvore de relações formada pelo sistema.

As dependências cíclicas inibem a compreensão, teste e reutilização dos módulos.

Outro método estudado mais a fundo é a **dependência instável** que se dá quando um subsistema depende de outros subsistemas mais instáveis do que ele próprio. Isso é aferido por meio da métrica de instabilidade. Isso pode desencadear um efeito cascata de mudanças no sistema.


![POOA_aula10_img02.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/POOA/POOA_aula10_img02.png)

Um alto valor de acoplamento **e**ferente indica que o componente possui muitas dependências e pode estar sujeito a modificações.

O **god component** ocorre quando um pacote, módulo, namespace ou semelhante assume mais responsabilidades do que deveria e acaba acumullando muito controle. Isso torna os componentes difíceis de testar, ler, entender e ainda mais alterar. Uma forma de detectar isso é encontrar um componente com mais que 30 classes.

## Refatoração
Existem muitas [técnicas de refatoração](https://refactoring.guru/refactoring/techniques) e cada uma delas tem seu motivo pra existir. A refatoração é uma mudança feita na estrutura interna do software para torná-la mas fácil de entender e mais barata de modificar sem alterar seu comportamento observável. Refatoração também pode ser definida como uma mudança no sistema que não altera seu comportamento mas melhora qualidades não funcionais como simplicidade, flexibilidade, compreensão ou desempenho.

Uma técnica de refatoração é chamada de **extract method** que consiste em criar um "método de extração" por meio da extração de uma porção de código de algum lugar e transformando ela em um método. Ela busca resolver **smells** como **código duplicado**, **método longo** e **inveja de feature**.

Isso tornará seu código mais legível, reduzirá a duplicação pois todos podem se referir a um mesmo método ao invés de descrever uma tarefa linha a linha sempre e também isola partes independentes do código.

Outra técnica de refatoração é o **move method** que envolve nada mais que mover um método de uma classe para outra que usa esse método mais que a própria classe que o define. Isso busca resolver **feature envy** e **shotgun surgery**.

A **refatoração** busca trazer benefícios como melhor manutenbilidade, melhor legibilidade, menos bugs, melhor performance, diminuição do tamanho do código, redução de código duplicado, testabilidade, maior facilidade em adicionar features, melhor modularidade, menor tempo até o mercado.

A **refatoração** é muitas vezes feita por meio do uso de ferramentas.

## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!