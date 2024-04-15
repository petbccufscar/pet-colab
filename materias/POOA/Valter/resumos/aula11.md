# Resumo Aula 11
> Resumo criado pelo aluno [João Pedro Trevisan](https://www.linkedin.com/in/joao-pedro-trevisan)

#### Professor
![Valter](https://img.shields.io/badge/Valter_Vieira_Camargo-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)


## Sonar Graph
O **SonarGraph** é uma ferramenta de análise estática (sem a aplicação funcionar) de projeto. Ela é capaz de gerar uma série de métricas que ajudam tanto na manutenção quanto no desenvolvimento de uma solução computacional.

Ao se iniciar um novo projeto na ferramenta existe a opção "*use quality model*". Essa opção define parâmetros para **code smells** e pode ser muito útil para avaliar um projeto. Uma lista de arquivos .xml que define essas métricas é mostrado quando se seleciona essa opção e estes arquivos podem ser alterados para que você defina suas próprias métricas.

Depois de aberto o sistema na ferramenta SonarGraph existe uma tabela que nos dá algumas informações sobre esse sistema:

![POOA_aula11_img01.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/POOA/POOA_aula11_img01.png)

A aba **metrics** nos dá uma infinidade de métricas pelas quais podemos avaliar o nosso projeto. Essas métricas podem avaliar o sistema em nível de Sistema, módulo, pacote java, componente, arquivo fonte, tipo ou rotina.

![POOA_aula11_img02.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/POOA/POOA_aula11_img02.png)

Por exemplo, na imagem a seguir estamos avaliando em nível de pacote java sob a métrica de **número de dependências aferentes**. Note que na janela de propriedades é explicada a métrica que selecionamos. Caso fosse selecionado o pacote haveria uma breve descrição dele.

![POOA_aula11_img03.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/POOA/POOA_aula11_img03.png)

Quanto  visualizações gráficas, é necessário que seja clicado em um módulo a ser avaliado e então seja selecionada a opção *show in graph view*.

![POOA_aula11_img04.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/POOA/POOA_aula11_img04.png)

Depois de gerado o gráfico, podemos selecionar uma linha para que seja avaliado como aquela dependência se dá.  Note:

![POOA_aula11_img05.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/POOA/POOA_aula11_img05.png)

A classe TelaBalanca.java chama um construtor chamado ControleCalcularPeso() no arquivo ControleCalcularPeso.java que está no pacote Controle.

A grossura das setas indica maior ou menor dependência.

Caso estejamos em busca de uma visão mais fina podemos clicar no ícone verde com 4 setas apontando para o centro de um objeto (canto superior direito), ele se chama *focus*. Nele podemos selecionar que tipo de relação estamos avaliando, no caso de dependências aferentes que é o que estamos avaliando.

![POOA_aula11_img06.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/POOA/POOA_aula11_img06.png)

Uma métrica interessante que é mostrada pelo **SonarGraph** é a **ciclicidade de pacotes**. Quando há um grupo cíclico será indicado na janela de trabalho que eles existem. Veja:

![POOA_aula11_img07.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/POOA/POOA_aula11_img07.png)

O grupo cíclico é mostrado da seguinte forma:

![POOA_aula11_img08.png](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/POOA/POOA_aula11_img08.png)

## Referências

- [Vídeos de SonarGraph](https://www.youtube.com/playlist?list=PLUnP453x5ipFaAe-4Z93U7w8y7J_UJUYg)


## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!