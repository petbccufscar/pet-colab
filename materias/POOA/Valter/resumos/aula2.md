# Resumo Aula 2
> Resumo criado pelo aluno [João Pedro Trevisan](https://www.linkedin.com/in/joao-pedro-trevisan)

#### Professor
![Valter](https://img.shields.io/badge/Valter_Vieira_Camargo-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)


## Revisão de UML
Note o seguinte esquema em UML:  

![POOA_aula02_img01.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/POOA/POOA_aula02_img03.png)

Os pacotes são criados primariamente para agrupar classes relacionadas e então organizar o trabalho em código de maneira saudável. Note que á o aninhamento de pacotes de forma que o pacote *controller*, por exemplo, tenha dentro de si dois outros pacotes de forma a gerar uma organização ainda mais inteligente.  

Existem também relacionamentos entre pacotes de forma a torná-los interdependentes. Um pacote não pode sequer ser compilado se não estiver presente o outro pacote do qual ele depende. Um exemplo de relacionamentos está na imagem a seguir, note que existem pacotes **terminais** como *FusionChart.swf*, ele não depende de ninguém e portanto é de fácil reaproveitamento. Note também a direção das dependências, o pacote *controle* é claramente o mais dependente de todos os pacotes (até mesmo por sua função).  

![POOA_aula02_img02.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/POOA/POOA_aula02_img03.png)

Neste exemplo não fica claro se existe interdependência entre pacotes com outros pacotes dentro dele ou mesmo entre os vários pacotes dentro de um pacote maior. Outra coisa é o fato de que se um pacote não tem dependentes ele talvez seja inútil (o que torna estranha a presença do pacote *controle*). Tudo isso se resume no fato de que UML é uma linguagem não determinística e que seus diagramas são criados para mostrar algo em uma dada situação. Então objetivos diferentes podem gerar diagramas com detalhamento maior ou menor e com focos diferentes.  

Vale ressaltar que se um diagrama tem ciclos entre dois ou mais pacotes este diagrama sugere algo ruim no seu sistema. Isso se dá pelo fato de que se um pacote for alterado ele pode gerar uma cadeia de mudanças imprevistas que pode fazer seu sistema desmoronar.  

Sobre as notações textuais em UML temos uma série de símbolos e seu significado segue:  

- **-** Privado, só visível dentro da própria classe.  
- **+** Público, todos, até mesmo classes de outro pacote tem acesso direto.  
- **#** Protegido, somente classes filhas tem acesso.  
- **~** Pacote, é público mas só dentro de um mesmo pacote.  
## Visibilidade de Pacotes
Um conceito importante no design de software é a **visibilidade de pacotes** para tornar o código organizado. O exemplo a seguir mostra um controlador que possui uma camada entre ele e a classe sobre a qual ele opera composto pelas classes *ICliente* (interface, classe abstrata) e pela classe *FactoryCliente* (classe que cria objetos cliente). Isso é uma boa prática que pousa sobre o conceito de **dynamic binding**. Note que em UML os métodos grifados denotam um método *estático*, ou seja, pode ser chamado independente de haver instanciada uma classe que o usa.  

![POOA_aula02_img03.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/POOA/POOA_aula02_img03.png)

## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!
