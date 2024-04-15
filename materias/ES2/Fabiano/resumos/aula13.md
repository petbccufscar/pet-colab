# Resumo Aula 13
> Resumo criado pelo aluno [João Pedro Trevisan](https://www.linkedin.com/in/joao-pedro-trevisan)

#### Professor
![Fabiano Ferrari](https://img.shields.io/badge/Fabiano_Ferrari-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)

## Engenharia Reversa e Reengenharia
Para abordar adequadamente as técnicas de manutenção de software, deve-se primeiramente considerar três conceitos dependentes: a existência de um processo de desenvolvimento de software, a presença de um sistema a ser analisado e a identificação de níveis de abstração.

Tendo em vista esta colocação, para que as técnicas de **engenharia reversa** e **reengenharia** sejam descritas de forma simplificada, serão tomadas como base apenas três fases do processo de desenvolvimento de software:
+ Requisitos
+ Projeto
+ Implementação

![ES2_aula13_img01.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/ES2/ES2_aula13_img01.png)

Note que o vai e vem entre as etapas de desenvolvimento de software podem demandar vários tipos de **retrabalho**.

O processo de **reengenharia** consiste em reconstruir um software já existente e a **engenharia reversa** é o processo pelo qual a **reengenharia** se dá.

O processo de **engenharia reversa** é caracterizado pelas atividades retroativas do ciclo de vida do software que partem de um baixo nível de abstração para um nível mais alto. Pode se dizer também que ela é a recuperação de um projeto consistindo na análise de um programa na tentativa de criar uma representação dele.

Na **engenharia reversa** se busca descobrir os princípios tecnológicos e o funcionamento de um dispositivo analisando sua estrutura, função e operação.

Pode-se aplicar a **engenharia reversa** com diferentes visões:
+ Implementacional: busca chegar a uma implementação de código semelhante a da aplicação original
+ Estrutural: busca realizar uma mimica das estruturas da programação original em um nível menos detalhado que a visão implementacional
+ Funcional: quer reconstruir a função de um componente (ou sistema)
+ De Domínio: abstrai o contexto em que o sistema está operando, busca o porquê do sistema a ser desenvolvido

![ES2_aula13_img02.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/ES2/ES2_aula13_img02.png)

A **visualização de código** é uma categoria de **engenharia reversa** que cria representações a partir de informações obtidas apenas da análise do código fonte.

Já o **entendimento do programa** é uma categoria alcançada por meio da combinação entre código acessível, documentação existente, experiência de pessoas, conhecimentos sobre o problema e o domínio de aplicação. Este processo busca entender como o sistema foi desenvolvido e é uma forma crítica de engenharia reversa.

O foco geral da **reengenharia** é produzir um sistema novo com maior facilidade de manutenção e a **engenharia reversa** é usada como sua ferramenta.

Um tipo de software muito suscetível a **reengenharia** e **engenharia reversa** é o **software legado**. Esse tipo de software é o tipo de programa que realiza tarefas ainda úteis mas que foi desenvolvido utilizando técnicas atualmente consideradas obsoletas.

Os maiores problemas para se manter **software legado** são a desestruturação e dificuldade de entendimento do código pois foram feitos antes de existirem arquiteturas ou ferramentas mais inteligentes, falta de pessoal que trabalhou naquele software ou mesmo em software semelhante, documentação desatualizada, dificuldade de predição de efeitos colaterais, dificuldade em administrar múltiplas alterações concorrentes.

Esse tipo de aplicação deve ser "desmontado" para ser compreendido e então ser recriado com práticas modernas para se tornar melhor e mais manutenível. Essa é a **reengenharia** de **software legado**.


## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!
