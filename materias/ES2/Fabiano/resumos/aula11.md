# Resumo Aula 11
> Resumo criado pelo aluno [João Pedro Trevisan](https://www.linkedin.com/in/joao-pedro-trevisan)

#### Professor
![Fabiano Ferrari](https://img.shields.io/badge/Fabiano_Ferrari-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)

## Técnicas e Critérios de Teste de Software (novamente)
Conforme o que foi estudado até então devemos saber que o processo de teste de software pode ser muito simples ou muito complexo. Fato é que não há um único jeito de testar um software e isso abre margem para muitas teorias, práticas e filosofias diferentes nas abordagens do teste.

Buscamos dessa forma meios de se sistematizar o teste de software e as **técnicas de teste** vem para nos ajudar nisso. Elas são formas de se testar o software baseadas em diferentes **artefatos de software** e estão relacionadas aos **pontos de vista do teste de software**: O **teste funcional**, o **teste estrutural** e o **teste baseado em defeitos**.

As **técnicas e critérios de teste** podem ser resumidas em *uma maneira sistemática de planejar e elaborar os casos de teste* e sob este viés podem ser usadas para **selecionar** casos de teste, ou seja, criar casos para satisfazer os critérios ou para **adequar** casos de teste. **Adequar os casos** consiste em criar testes de uso geral e usar alguma métrica para determinar a qualidade deles em uma dada situação.

## Teste Estrutural
O ponto mais importante sobre o **teste estrutural** é que ele se baseia em **uma implementação específica** do software. Ele não avalia especificações.

Ele é conhecido também como **teste de caixa branca** por fazer uso do código para estudar e explorar o fluxo de execução daquele programa. Muitos dos critérios dessa técnica utilizam uma representação de programa conhecida como **gráfico de fluxo de controle** (**GFC**). Esta técnica permite uma avaliação de cobertura do código como vista em aula com o uso do plugin da IDE Eclipse chamado **Eclemma**.

Um dos problemas dessa abordagem é que existem no código **caminhos não executáveis**, um problema não decidível que deve ser sempre levado em consideração pois alguns caminhos simplesmente não podem ser executados devido a condições mutuamente exclusivas.

O **teste estrutural** pode ser baseado em **fluxo de controle** ou em **fluxo de dados**. Este primeiro tipo apenas observa os predicados e caminhos lógicos que podem ser seguidos dentro do código. Já o teste **baseado em fluxo de dados** além de levar em conta predicados e caminhos lógicos olha também para variáveis definidas e manipuladas ao longo do programa.

As visualizações do **fluxo de controle** tem a seguinte forma:

![ES2_aula11_img01.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/ES2/ES2_aula11_img01.png)

Um exemplo de código com uma imagem de seu fluxo de controle seguem:

```pseudo
início
	leia nro                           # 1
	enquanto nro != 0                  # 2
		se nro > 0                     # 3
			raiz = raiz-quadrada(nro)  # 4
			escreva raiz               # 4
		senão                          # 4
			escreva mensagem de erro   # 5
		fim-se                         # 6
		leia nro                       # 6
	fim-enqto                          # 6
fim                                    # 7
```

![ES2_aula11_img02.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/ES2/ES2_aula11_img02.png)

O teste que busca percorrer todos as partes do código se chama **todos-nós** e sua premissa básica é que *um programa não pode ser confiável se ele contém instruções que nunca foram exercitadas*.

## Estratégias de Teste de Software
As estratégias de teste tem em comum o fato de que iniciam-se no nível de módulos e caminham na direção da integração de todo um sistema. Cada estratégia, contudo, será apropriada para diferentes situações.

As etapas do projeto são genericamente a *engenharia do sistema*, *o elencar dos requisitos*, *o projeto* e o *código*. As etapas do teste são **teste de unidade**, **teste de integração**, **teste de validação** e por fim o **teste de sistema**.

No **teste de unidade** concentramo-nos no módulo sendo desenvolvido. Ele pode ser realizado em paralelo para vários módulos, os aspectos a serem considerados são vários, mas alguns exemplos são a *interface*, a *estrutura de dados local*, as *condições limite*, os *caminhos independentes* e os *caminhos de tratamento de erros*.

A estrutura do processo de teste de unidade usando programas auxiliares é esquematizada nessa imagem:

![ES2_aula11_img03.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/ES2/ES2_aula11_img03.png)

Os módulos são "colocados" no programa que testará vários em paralelo gerando os resultados.

O **driver** é um programa que aceita dados de teste e passa esses dados para o módulo a ser testado e imprime os dados relevantes que recebe desse módulo.

Um **stub** é um módulo que substitui os outros módulos que possam ser chamados pelo módulo em teste como forma de testar este módulo isoladamente.

O **teste de integração** envolve a construção da estrutura do programa de forma sistemática e a realização de teste para detectar os defeitos de interface.

Este teste existe pois mesmo que os módulos possam funcionar isoladamente após os **testes de unidade** eles podem não funcionar de maneira *integrada*.

O diagrama a seguir mostra possíveis defeitos relacionados a integração dos módulos:

![ES2_aula11_img04.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/ES2/ES2_aula11_img04.png)

F e G são funções
Si(G) são dados de entrada de G
So(G) são dados de saída de G

A integração dos módulos é feita através de uma abordagem incremental que pode ser **top-down** ou **bottom-up**.

No modelo **top-down** a integração dos módulos é feita de cima pra baixo e pensando-se na navegação de uma árvore de interações. E ainda tendo em vista a árvore podemos explorá-la **em profundidade** ou **em largura**.

![ES2_aula11_img05.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/ES2/ES2_aula11_img05.png)

Em profundidade: M2, M5 e M8 ou M2, M5, M6 e M8
Em largura: M2, M3 e M4

Quando analisa-se **por profundidade** permite-se que uma função específica do módulo principal possa ser testada por completo.

Os 5 passos do **top-down** são:
1. O módulo de controle principal é usado como um driver e substitui-se por *stubs* todos os módulos reais diretamente subordinados ao módulo principal;  
2. Dependendo da abordagem de integração a ser utilizada – por profundidade ou largura – os *stubs* são substituídos pelos módulos reais, um de cada vez;  
3. São realizados testes para cada módulo que seja integrado;  
4. Quando um teste é concluído, outro *stub* é substituído pelo módulo  real;  
5. Teste de regressão (isto é, repetição de todos ou alguns dos testes já realizados) pode ser aplicado novamente para garantir que novos defeitos não tenham sido introduzidos

A **integração bottom-up** tem os testes feitos "de baixo pra cima". Nela quando os módulos de níveis superiores vão ser testados os módulos subordinados já estão prontos e portanto não é necessário se construir *stubs*.

![ES2_aula11_img06.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/ES2/ES2_aula11_img06.png)

A escolha entre as duas abordagens tem relação com o tipo de software e as vezes com o cronograma do projeto.

Pode-se ainda tentar uma integração combinada, a chamada **integração sanduíche** nos quais os módulos superiores vão ter sua integração testada por meio de abordagem **top-down** e os inferiores serão testados com **bottom-up**.

A vantagem do **top-down** pousa sobre o fato de que se pode testar cedo as funções principais do software, mas sua desvantagem está no fato de que criar *stubs* pode ser difícil.

O **bottom up** ganha no fato de não se precisar dos complicados *stubs*, mas sua desvantagem é que o módulo principal não existe enquanto todos os módulos não estiverem testados.

Depois do **teste de integração** temos o **teste de validação**. Nele o software está montado como um pacote e a validação dele será realizada por meio de uma série de testes de caixa preta.

O objetivo fim do **teste de validação** é demonstrar a confiabilidade dos requisitos funcionais e não funcionais, além de checar se a documentação está correta. Há a possibilidade dos resultados serem aceitos ou não e se não forem aceitos pode-se negociar como proceder com o cliente.

No caso do software desenvolvido para vários usuários realiza-se os **testes alpha** no ambiente do desenvolvedor e os **testes beta** no ambiente do usuário.

Por fim, temos os **testes de sistema** que consideram o software dentro do seu ambiente mais amplo (interação com outros softwares, hardwares e pessoas). Estes testes correspondem a uma série de práticas que tem o objetivo de verificar se todos os elementos do sistema foram integrados adequadamente e realizam corretamente suas funções.

Alguns desses testes são:

**Teste de segurança**: tem por objetivo verificar se todos os mecanismos de proteção de fato protegem o software de acessos indevidos.

**Teste de estresse**: tem por objetivo confrontar os programas com situações anormais de frequência, volume e recursos em quantidade.

**Teste de desempenho**: tem por objetivo testar o tempo de resposta do sistema e é aplicado muito mais em sistemas de tempo real.

## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!
