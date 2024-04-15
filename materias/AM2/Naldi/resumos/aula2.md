# Resumo Aula 2
> Resumo criado pelo aluno [João Pedro Trevisan](https://www.linkedin.com/in/joao-pedro-trevisan)

#### Professor
![Murilo Naldi](https://img.shields.io/badge/Murilo_Coelho_Naldi-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)

## Classificação Hierárquica
Os problemas estudados até aqui usam a chamada **classificação plana** onde todos os rótulos estão em um mesmo nível. A **classificação hierárquica**, por sua vez, considera subconjuntos de rótulos de modo a formar taxonomias.

É importante diferenciar **classificação hierárquica** de **classificação multirrótulo**. Nas hierarquias de classificação uma classe pode ser uma subclasse de outra(s) classes, contudo isso não significa que ela possua vários rótulos. Ainda assim, se pode ter uma classificação hierárquica multirrótulo no caso de se encontrar múltiplos rótulos em diferentes famílias hierárquicas.

Olhe a imagem a seguir:

![Aula03_img01.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula03_img01.png)

Imagine que uma musica é classificada como *música sinfônica*. Toda *música sinfônica* tem a **superclasse** *música de orquestra* que possui a superclasse *música clássica* que possui a **superclasse** *música*. Contudo isso não quer dizer que ela possui 3 rótulos, mas sim que ela faz parte de uma hierarquia de classes. No caso de uma musica ser *música sinfônica* e *hard rock*, por exemplo, aí então ela tem múltiplos rótulos.

Dado um conjunto parcialmente ordenado  (C, ≺):
- Existe um único elemento superior “R” que é a raiz
- ∀ci , cj ∈ C, se ci ≺ cj então cj ≺ ci é falso
- ∀ci ∈ C, ci ≺ ci é falso
- ∀ci , cj , ck ∈ C, ci ≺ cj e cj ≺ ck implica ci ≺ ck

O símbolo ''≺'' significa **IS-A** (é um).

Para realizar classificações hierárquicas precisamos de 3 critérios:
- Tipo de estrutura hierárquica
- Quão profundo a classificação é feita
- Como a estrutura hierárquica é explorada

Um tipo de estrutura naturalmente hierárquica da computação e que possui vários subtipos é a **árvore**. Outra estrutura deste tipo é o grafo, como por exemplo o **direct acyclic graph** (DAG) que é uma árvore onde um nó pode ter mais que um pai.

![Aula03_img02.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula03_img02.png)

Com relação a profundidade da classificação podemos trabalhar com **rotulação parcial** ou **completa**.

Quando realizamos uma **rotulação parcial** podemos atribuir um rótulo a qualquer altura da árvore. Usando o exemplo dos tipos de musica é como se chegasse em rock e parasse sem "descer" pra hard rock, pop rock...

Na **rotulação completa** buscamos apenas as folhas de uma árvore, ou seja, queremos a classificação mais completa possível.

Esses problemas se dividem em ***mandatory leaf-node prediction*** (MLNP) quando classificamos apenas em folhas e ***non-mandatory leaf-node prediction*** (NMLNP).

Em respeito a como a estrutura hierárquica é explorada temos 3 métodos mais conhecidos:
- Classificadores planos
- Abordagem global (big-bang)
- Abordagem local (top-down)

Os **classificadores planos** só conseguem dar como resposta os nós folha, ou seja, acabam ignorando a hierarquia de classes. Uma "solução" para este "problema" envolve atribuir para uma instância que já foi classificada em uma folha todas as outras classes ancestrais.

As desvantagens desse modelo é que ele exige um número grande de classes e que ele não é capaz de realizar classificação parcial.

O **modelo global**, também chamado de **big bang** é chamado quando se tem um único classificador capaz de classificar todas as classes possíveis, ele é um modelo único para toda a hierarquia. Este modelo é difícil de ser treinado computacionalmente, mas a literatura diz que um modelo único é menor que o uso de diferentes modelos em termos de armazenamento.

O **modelo local** (**top down**) está preocupado em cortar uma hierarquia em estruturas menores e usar classificadores especializados para cada uma delas. Cada um desses classificadores será especializado e atua como se não estivesse na hierarquia maior.

Suas desvantagens são a grande quantidade de modelos gerados e a propagação de erros para a hierarquia (caso haja erro), a vantagem é que eles podem ser heterogêneos (usar diferentes algoritmos). Podemos usar um classificador **por nó**, **um por pai** ou **um por nível**.

O treinamento **um por nó** usa um classificador binário para cada nó, O treinamento **um por pai**, por ter que reconhecer os nós filhos é treinado com um classificador multiclasse para cada pai. Por fim, o classificador **um por nível** também utiliza classificadores multiclasse, porém com a restrição de que ele não pode classificar um objeto de forma que "seu pai tenha que ser mudado", olhe a imagem a seguir:

![Aula03_img03.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula03_img03.png)

O classificador em L1.1 não pode classificar um filho como Lx.y.z com *x* e *y* != 1.

Na classificação hierárquica é preciso estar atento ao tipo de erro gerado, note a diferença entre os 3 erros a seguir sabendo que a classe real é a verde e a predita é a vermelha:

![Aula03_img04.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula03_img04.png)

![Aula03_img05.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula03_img05.png)

![Aula03_img06.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula03_img06.png)

É por esse motivo que os modelos de avaliação dos resultados de classificadores hierárquicos devem levar em consideração a ancestralidade das classes. Note como se calculam as métricas de precisão e de recall:

![Aula03_img07.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula03_img07.png)

## Aprendizado Semi-Supervisionado
Suponhamos que temos uma grande quantidade de dados porém poucos deles estão de fato rotulados, podemos usar a rotulação parcial para se criar um classificador e rotular o resto das amostras.  Se pensarmos em agrupamento, é possível ignorar os dados já rotulados e tentar realizar um agrupamento.

Aprendizado semi-supervisionado é a parte de aprendizado de máquina que combina inferência de rótulos (aprendizado supervisionado) a partir da forma em que os dados são estruturados (aprendizado não-supervisionado).

Dessa forma podemos realizar ambas tarefas de rotulação ou agrupamento porém de maneira informada.

A maior parte dos trabalhos em aprendizado semi-supervisionado é focado em classificação e portanto nossos estudos começam por esse tipo de problema. Os dados sem rótulo então serão usados para melhorar o resultado de um classificador.

Tomemos o exemplo a seguir:

![Aula03_img08.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula03_img08.png)

Se tomarmos como base apenas os dados já classificados de cada grupo (triângulos e **+**) podemos criar uma fronteira de decisão subótima nos dados.

A ideia principal do conceito de cluster é que os dados dentro de um cluster sejam mais semelhantes entre si do que são semelhantes entre dados alocados em um outro cluster, não importa se os dados são agrupados por densidade ou similaridade.

Classes são atributos pré definidos que não necessariamente seguem alguma regra.

Contrapostos estes dois conceitos precisamos assumir algumas coisas para trabalhar com aprendizado semi-supervisionado. Essas presunções não são necessariamente verdadeiras:
- **Suposição de suavidade**: um objeto próximo de um objeto rotulado tende a possuir o mesmo rótulo.
- **Suposição de baixa densidade**: a fronteira de decisão deve passar por uma região de baixa densidade de dados.
- **Suposição de variedade**: as classes estão estruturadas em um espaço topológico que se parece localmente com um espaço euclidiano nas vizinhanças de cada ponto. (exemplo: 2 esferas sendo divididas em uma variedade de círculos).

A ideia é que o aprendizado semi-supervisionado só funciona quando classes se comportam como grupos. É por isso que as suposições anteriores são conhecidas como a **suposição de agrupamento**. Se os dados não rotulados e rotulados não puderem ser agrupados não é possível um método de aprendizado semi-supervisionado possa melhorar o resultado em relação a um método supervisionado. 

Nos slides 16 ~ 21 temos o exemplo do funcionamento de um algoritmo de aprendizado supervisionado indutivo e uma de aprendizado transdutivo. Geralmente o processo de transdução precede o processo de indução. 

O processo transdutivo pode ser feito por um algoritmo chamado **label propagation** que opera sobre grafos. Dados os nós de um grafo:
1. Cada nó tem seu rótulo correspondente
2. O rótulo denota a comunidade à qual esse nó pertence
3. Através da iteração, cada nó atualizará o seu rótulo com base nos rótulos vizinhos
	1. O rótulo atualizado de cada nó será o mais presente dentre os vizinhos do nó
4. Eventualmente, nós densamente conectados alcançam uma comunidade comum
- Estes rótulos podem ser alcançados por meio de votação (como visto na aula passada), essa votação pode ter base de ponderação os pesos das arestas do grafo.

Espera-se que haja um ponto de convergência nesse tipo de algoritmo, isto é, uma iteração na qual nenhum rótulo muda.

![Aula03_img09.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/AM2/Aula03_img09.png)

Perceba que os dados nem sempre virão em forma de grafo e portanto devemos ser capazes de formar um grafo com os dados.

A forma mais uga uga de fazer isso é assumir um grafo completo, ou seja, tudo está conectado com tudo. Isso implica no fato de que vizinhanças são difíceis de serem geradas.

Podemos usar funções Gaussianas ou RBF (Radial based function) nos dados para ponderar as arestas de a cordo com a distribuição e depois disso aplicar o **label propagation** com votação ponderada pelas arestas.

Outra forma de se fazer o grafo é construir o **grafo de vizinhos mais próximos** por meio de um algoritmo como o **KNNG** (K Nearest Neighbour Graph). Dado um parâmetro K, conecta-se os K-vizinhos mais próximos e então se aplica o **label propagation**. Alternativamente existe o **εNNG** onde o  ε define uma dissimilaridade limite para se conectar vizinhos.

Uma alternativa a esse processo é levar em consideração se os vizinhos mais próximos dos nós são mútuos, ou seja, um objeto só aceita outro como vizinho se houver reciprocidade no julgamento. Os algoritmos usados são o **K*M*NNG*** e o **ε*M*NNG**.

Vale ressaltar que nesses algoritmos nenhum nó previamente rotulado perde seu rótulo ou troca ele.

Até então estudamos a **classificação semi-supervisionada**, agora estudaremos o **agrupamento semi-supervisionado**. Nesta abordagem os objetos rotulados definem o rótulo e o grupo, isto é, um grupo não deve ter dois ou mais objetos com rótulos distintos e um grupo deve possuir todos os objetos que possuem o mesmo rótulo.

Dizer que um grupo não deve ter dois ou mais rótulos distintos implica na possibilidade de definir relações "**must-link**" (deve estar ligado pois tem o mesmo rótulo) e "**cannot-link**" (não deve estar no mesmo grupo por ter rótulo diferente). Além disso os algoritmos devem respeitar essas restrições na construção de um modelo.

Usando como exemplo o algoritmo k-médias:
1) Escolher um número k de protótipos (centros) para os grupos
2) Atribuir cada objeto para o grupo de centro mais próximo (segundo alguma distância, e.g. Euclidiana)
3) Mover cada centro para a média (centróide) dos objetos do grupo correspondente
4) Repetir os passos 2 e 3 até que algum critério de convergência seja obtido

No caso de possuirmos restrições neste algoritmo faríamos levemente diferente:
1) Escolher um número k de protótipos (centros) para os grupos
2) Atribuir cada objeto para o grupo de centro mais próximo, obedecendo a lista de cannot-link
3) Mover cada centro para a média (centróide) dos objetos do grupo correspondente
4) Repetir os passos 2 e 3 até que algum critério de convergência seja obtido
5) Aglomerar grupos com objetos must-link


## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!
