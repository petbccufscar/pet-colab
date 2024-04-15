# Resumo Aula 8
> Resumo criado pelo aluno [João Pedro Trevisan](https://www.linkedin.com/in/joao-pedro-trevisan)

#### Professor
![Helio](https://img.shields.io/badge/Helio_Crestana_Guardia-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)

## Avaliação de Desempenho de Aplicações Paralelas
Até aqui estivemos preocupados em como paralelizar aplicações de acordo com diferentes paradigmas e de forma a poder operar sobre diferentes tipos de sistema e organizações de memória. É importante contudo poder avaliar a qualidade da paralelização e dado que o foco dela é acelerar a execução dos programas é justamente o tempo de execução que será nossa métrica.

De início, a primeira métrica que vamos abordar é a de **speedup** que é uma medida comparativa de desempenho usada para avaliar a diminuição no tempo de execução de uma aplicação a medida que se aumenta o uso de recursos de processamento.

O speedup é dado pelo tempo de execução em um único processador dividido pelo tempo de execução em múltiplos processadores, isto é, o speedup nos diz em quantas vezes o tempo foi diminuído.

![aula08_img01.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/PPD/aula08_img01.png)


O speedup também é calculado como a quantidade de passos sequenciais dividida pela quantidade de passos paralelos.

![aula08_img02.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/PPD/aula08_img02.png)


Intuitivamente, pode-se pensar que o speedup máximo é igual ao número de processadores e isso se chama **speedup linear**. Existe também o speedup **superlinear** onde Sp > p e ele pode ser obtido em circunstâncias especiais:

- Disponibilidade de memória adicional no ambiente multiprocessado
- Algoritmo não-determinístico
- Processamento dependente dos dados

Outra métrica que deriva do speedup e que é muito necessária para avaliar os programas paralelos é a **eficiência** que indica a proporção dos ganhos com o uso dos processadores.

Ela é dada pelo tempo de execução com um processador dividida pela multiplicação entre o tempo de execução om múltiplos processadores pelo número de processadores.

![aula08_img03.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/PPD/aula08_img03.png)


Esperamos:
- 0 < speedup <= p
- Trabalho Serial <= Trabalho Paralelo < infinito
- 0 < Eficiênia <= 1

A Lei de Amdahl trata de identificar o maior aumento de desempenho esperado para a execução de um programa em que apenas uma parte do código pode ser paralelizado. Segundo Gene Amdahl o speedup de um programa está limitado pela sua fração sequencial.

A imagem a seguir ilustra uma aplicação que tem apenas um trecho paralelizável:

![aula08_img04.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/PPD/aula08_img04.png)


O tempo de execução em um núcleo é dado pela soma da parte sequencial (*s*) e da parte paralelizável (*f*), obtendo *s + f = 1*. Já o tempo de execução em *p* núcleos é dado por *s + f/p = 1*. Dessas duas equações podemos tomar que *s = 1 - f e *f = 1 - s*.

Dessa maneira, a **equação de Amdahl** que nos revela a porcentagem de ganho com a paralelização (*speedup factor*) é dada por:

***S(p) = 1/(s + f/p)***

Supondo que p->ထ, isto é, temos processadores infinitos que podem executar blocos de código muito pequenos temos que 

***S(p) = 1/s***

O que significa dizer de maneira matemática que o speedup é limitado pela fração sequencial do programa. Como exemplo, imaginemos um código com 5% de porção sequencial, seu speedup máximo seria de *1/0,05 = 20*.

![aula08_img05.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/PPD/aula08_img05.png)


Perceba que há algo de simplista na lei de Amdahl, pois ela não considera o tamanho do problema na análise da limitação do desempenho. Em muitos problemas de programação paralela é comum aumentar-se o tamanho do problema tratado conforme se aumenta os recursos de processamento, o que não ocorre com a porção sequencial.

Isso significa que mesmo que os trechos sequenciais limitem os ganhos em desempenho é possível que esses trechos se tornem relativamente menores quando se amplia o tamanho do problema, de modo que pode haver ganhos maiores com a paralelização.

Nestes casos podemos avaliar o ganho com paralelismo pela **Lei de Gustafson** que considera o **escalamento fraco** em que o tamanho do problema aumenta proporcionalmente à medida que o número de tarefas aumenta, mantendo fixo o volume de trabalho pro processador.

Aqui assumimos que ao invés de considerar o tamanho do problema é fixo, o tempo de execução paralela é fixo, ou seja, a medida que o número de recursos de processamento aumenta considera-se que o tamanho do problema aumenta também mantendo-se o tempo de execução paralela constante.

Como o tempo de execução paralelo é constante, o fator de speedup na lei de Gustafson é chamado de **speedup escalado**. 

Considerando agora *s* e *p* como os tempos das frações serial e paralela, respectivamente, gastos no sistema com paralelismo, temos que o tempo gasto para a execução da versão sequencial seria *s + p * N*. Com essa formulação, o speedup escalado é dado por:

***Ss(p) = (s + p \* N) / (s + p) = s + p \* N = N + (1 - N) \* s***
assumindo *(s + p) = 1*

Onde *N* é o numero de cores e *s* é a fração serial do programa. Suponhamos que a fração sequencial em um sistema com 32 cores corresponde a 1% do tempo de execução, o speedup escalado desta aplicação em relação à execução inteiramente sequencial pode ser estimada como:

Ss(p) <= 32 + (1-32) \* 0.01 = 31,69

![aula08_img06.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/PPD/aula08_img06.png)


Anteriormente foi citado o **speedup superlinear** que se dá em situações em que o ganho de desempenho com paralelismo pode ser proporcionalmente superior ao número de processadores utilizados. Vejamos um exemplo em um algoritmo de busca em vetor:

![aula08_img07.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/PPD/aula08_img07.png)


Note que no exemplo acima o espaço de busca consome um tempo *ts* para ser processado sequencialmente e está representado por *ts/p* blocos. Supomos também que *p* é o número de processadores disponíveis para execução paralela. Neste caso a solução buscada de maneira sequencial será encontrada depois de percorrido tempo equivalente a *xts/p + ∆t*.

**(b) Pesquisando cada subespaço em paralelo**:
![aula08_img08.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/PPD/aula08_img08.png)


Consideramos agora que *p* processadores são usados para fazer a mesma busca, se há *p* processadores disponíveis e os *p* blocos podem ser executados em paralelo a solução será encontrada após *∆t* segundos. No caso de *x > 1* o speedup será maior que *p* e portanto superlinear.

A aceleração na resolução de problemas está relacionada com a **escalabilidade** do sistema que executa o código, o que significa dizer para um mesmo problema deve ser capaz de obter aumento de desempenho linear à medida que seus recursos de processamento são aumentados.

O tempo de resolução para um mesmo problema computacional pode variar de acordo com o número de recursos de processamento utilizados, a velocidade destes recursos, as características dos canais de comunicação e a arquitetura do sistema como um todo.

A escalabilidade do hardware indica sua capacidade de fazer o aumento no número de recursos refletir na velocidade de resolução do problema. Quanto mais processadores são adicionados mais complexa fica a rede de interconexão dos elementos do sistema e aumenta o atraso na comunicação e os conflitos em busca de recursos, o que põe em risco o desempenho do sistema.

Pode-se falar também sobre a escalabilidade do código em si que deve ser capaz de acomodar aumentos no número e/ou volume de dados tratados sem fazer crescer os passos computacionais.

Escalar simultaneamente a arquitetura e o algoritmo sugere que o aumento do tamanho do problema pode ser acomodado com o aumento do sistema. Porém o aumento no tamanho do problema poder gerar reflexos diferentes na escalabilidade.

Tomemos um trabalho com matrizes, por exemplo. Dobrar a dimensão da matriz gera aumento dobrado na soma, mas quadruplicado na multiplicação.

Seja um programa paralelo rodado com um número fixo de processos e threads e entrada fixa, obteremos uma eficiência *E*. Se fomos capazes de aumentar o número de processos e threads e então encontrar uma tacha correspondente de aumento no tamanho do programa (tido como *W*) de forma que a eficiência se mantenha igual a *E* temos então um programa escalável.

Por fim, lembramos aqui que uma das tradições mais antigas da computação é jogar hardware em cima dos problemas até que eles se resolvam, este curso tenta quebrar esta tradição te ensinando a não programar igual um idiota, mas sim buscar otimizações paralelas para suas aplicações. Ainda assim, numa cultura que nos faz buscar sempre ser **o maior**, **o melhor**, **o mais pica**, é óbvio que alguém ia querer fazer [o computador mais fodido da galáxia](https://en.wikipedia.org/wiki/Matrioshka_brain), mas devemos nos perguntar até que ponto escalar nossos sistemas nos da um retorno real.

Isto significa dizer que devemos nos atentar na conversão de energia empregada em um sistema em processamento. É com base nesse esforço que existe o **Green500** que busca medir qual sistema de HPC tem uma maior eficiência em Mflops (operações de ponto flutuante) por Watt.

## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!