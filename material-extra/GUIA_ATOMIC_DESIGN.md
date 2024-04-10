# Guia básico: Atomic Design
<img src="https://raw.githubusercontent.com/petbccufscar/.github/main/profile/icon.png" align="right" />

> Esse material foi desenvolvido para auxiliar no projeto "Tô na UFSCar?"

O Atomic Design é uma metodologia para design de interfaces que ajuda a criar sistemas de design escaláveis e consistentes. Desenvolvido por Brad Frost, o Atomic Design propõe uma abordagem modular, dividindo interfaces em componentes menores e mais simples, chamados de átomos, que são combinados para formar **moléculas**, **organismos**, **templates** e **páginas completas**. Este guia destina-se a fornecer uma visão geral e passos básicos para entender e começar a aplicar os princípios do Atomic Design.

## Conceitos Básicos

![Diagrama](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/materiais-extras/imagem_2024-04-10_174244333.png)

### Átomos
Os átomos são os componentes de interface mais simples e básicos, como botões, inputs, ícones, cores e tipografias.

![Atomo](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/materiais-extras/imagem_2024-04-10_174304057.png)

### Moléculas
As moléculas são grupos de átomos combinados para formar componentes mais complexos e reutilizáveis, como um formulário de login que consiste em um campo de entrada de texto (átomo) e um botão (outro átomo).

![Molecula](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/materiais-extras/imagem_2024-04-10_174307716.png)

### Organismos 
Os organismos são conjuntos de moléculas e/ou átomos agrupados para formar seções ou componentes maiores e mais complexos, como um cabeçalho de página que contém um logo (atómo), menu de navegação (molécula) e um botão de login (átomo).

![Organismo](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/materiais-extras/imagem_2024-04-10_174311047.png)

### Templates
Os templates são estruturas que combinam vários organismos para formar layouts de página completos, como uma página inicial que inclui um cabeçalho, uma barra lateral e uma área de conteúdo.

![Template](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/materiais-extras/imagem_2024-04-10_174314757.png)

### Páginas
As páginas são as implementações finais e específicas dos templates, onde todos os componentes são preenchidos com conteúdo real, como a página de produto em um site de comércio eletrônico.

![Página](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/materiais-extras/imagem_2024-04-10_174318084.png)

## Princípios do Atomic Design

- **Escalabilidade:** Os componentes modulares podem ser facilmente reutilizados e combinados para criar interfaces complexas sem a necessidade de reescrever código.

- **Consistência:** Ao usar um conjunto consistente de átomos, moléculas e organismos, você garante uma experiência de usuário uniforme em todo o sistema.

- **Flexibilidade:** A abordagem modular do Atomic Design permite adaptar e atualizar interfaces com mais facilidade, mantendo a coesão visual e funcional.

## Passos para Aplicar o Atomic Design

- **Identificar Átomos:** Liste os elementos de interface mais básicos que serão usados em seu projeto, como botões, campos de texto, cores, ícones, etc.

- **Criar Moléculas:** Combine átomos relacionados para formar componentes mais complexos e reutilizáveis, como formulários, cartões ou barras de navegação.

- **Agrupar em Organismos:** Combine moléculas e átomos em seções maiores de interface, como cabeçalhos, rodapés ou barras laterais.

- **Desenvolver Templates:** Crie estruturas flexíveis que definam a disposição dos organismos em uma página, como layouts de página inicial, de produto ou de categoria.

- **Implementar Páginas:** Preencha os templates com conteúdo real para criar páginas finais e específicas, garantindo que todos os componentes funcionem corretamente em conjunto.

## Problemas do Atomic-Design
O sistema de design Atomic Design, desenvolvido por Brad Frost e Dave Olsen, embora seja uma metodologia eficaz para criar interfaces escaláveis e consistentes, apresenta alguns desafios conceituais que podem impactar sua aplicação prática. Abaixo, discutimos dois problemas importantes identificados por Aurélio-Jota em seu artigo.

### Problema 1: Nomenclatura Desconexa com a Metáfora Biológica

No conceito atual do Atomic Design, duas camadas, "Templates" e "Páginas", não se relacionam diretamente com a metáfora biológica proposta. Essa desconexão pode causar confusão na compreensão e na aplicação da metodologia. 

![Erro](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/materiais-extras/imagem_2024-04-10_174326897.png)

Aurélio-Jota sugere uma abordagem alternativa apresentada em outro artigo, onde essas camadas são renomeadas para "Ecossistema" e "Ambiente", respectivamente, para estabelecer uma relação mais próxima com a metáfora biológica.

![Nova abordagem](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/materiais-extras/imagem_2024-04-10_174330802.png)

### Problema 2: Tratamento dos Estilos Globais como Componentes
No Atomic Design, o Pattern Lab trata os estilos globais, como paletas de cores e famílias de fontes, no mesmo nível que os átomos. No entanto, esses elementos visuais não são tecnicamente componentes, mas sim estilos. Isso pode gerar uma inconsistência na organização e na compreensão do sistema de design. Aurélio-Jota propõe uma solução baseada na metáfora biológica, sugerindo que os estilos visuais sejam tratados como o "DNA" do sistema, inserindo-os como temas que podem ser aplicados a todos os componentes, evitando a necessidade de declarar uma categoria global separada.

### Resolução Proposta: Integração do DNA ao Fluxo do Atomic Design
Para resolver esse problema, Aurélio-Jota propõe a integração do conceito de DNA ao fluxo do Atomic Design. Assim como os genes determinam características hereditárias em organismos vivos, os temas definem os estilos visuais do sistema de design. Todos os componentes começariam com estilos visuais padrão dos navegadores e, em seguida, receberiam estilos personalizados definidos por temas. Isso simplifica a organização do sistema de design e torna mais consistente a aplicação dos estilos globais.

![Resolução](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/materiais-extras/imagem_2024-04-10_174342061.png)

## Conclusão

O Atomic Design oferece uma estrutura valiosa para criar interfaces de usuário coesas, escaláveis e consistentes. Seguir os princípios do Atomic Design e aplicar os passos básicos descritos neste guia pode ajudar a desenvolver sistemas de design flexíveis e adaptáveis que proporcionam uma experiência de usuário superior em todas as plataformas e dispositivos.

No entanto, é importante reconhecer que o Atomic Design não é isento de desafios conceituais, como os discutidos pelos críticos, como Aurélio-Jota. Para projetos menores ou contextos específicos, pode ser necessário adaptar a metodologia ou considerar abordagens alternativas para garantir a eficácia e a consistência do sistema de design.

Independentemente das nuances, o cerne do Atomic Design reside na compreensão dos conceitos de modularização para promover um código mais limpo e organizado. Isso, por sua vez, fortalece os três pilares fundamentais: escalabilidade, consistência e flexibilidade. No contexto do projeto "To na UFSCar?", uma abordagem derivada do Atomic Design pode ser adotada para simplificar o fluxo e facilitar a aplicação, garantindo que o sistema de design atenda às necessidades específicas do projeto sem sobrecarregar com regras complexas.

## Referências

- [Atomic Design Methodology](https://atomicdesign.bradfrost.com/chapter-2/?source=post_page-----e3ac7b5aca2c--------------------------------)
- [Atomic Design: o que é, como surgiu e sua importância para a criação do Design System](https://medium.com/pretux/atomic-design-o-que-é-como-surgiu-e-sua-importância-para-a-criação-do-design-system-e3ac7b5aca2c)
- [O elo perdido do Design Atômico](https://medium.com/@aureliojota/o-elo-perdido-do-design-atômico-5a623e8984fb)

## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!

Lembre-se, a prática é fundamental para se familiarizar com o Git e o GitHub. Boa sorte!