# Resumo Aula 6
> Resumo criado pelo aluno [João Pedro Trevisan](https://www.linkedin.com/in/joao-pedro-trevisan)

#### Professor
![Valter](https://img.shields.io/badge/Valter_Vieira_Camargo-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)


## Métricas de Manutenção
Muitas são as técnicas de tentar prever a **manutenbilidade** de um sistema. Até então estudamos uma serie de conceitos que ajudam a fazer isso e agora buscaremos gerar métricas para tanto. Uma primeira métrica mais simples seria dada por: 

**C = size(i) \* ((1 - inF(i))/número de componentes em níveis mais altos)/ n**

+ *n* é o numero de componentes
+ *size(i)* é o numero de componentes no nó lógico
+ *inF(i)* é o número de componentes afetados por *C*

Isso é calculado para todo nó C de um diagrama 

Depois de calcular isso somaremos todos os valores encontrados e multiplicaremos por 100.  

Calcula-se também uma penalidade para dependências cíclicas que é dada por:

**Penalidade = 5/*size(i),* se *size(i)* > 5, se não 1**

A nova métrica é calculada da mesma forma multiplicada pelo valor de *Penalidade*.

Esta métrica não funciona bem para módulos pequenos com menos de 100 componentes e para tanto foi criada outra métrica dada por:

**ML3 = 100 - n) + n/100 \* ML2, se *n*<100**, se não use ML2.

Ainda assim, o empirismo mostra que alguns sistemas que são ruins de se fazer manutenção podem ter uma métrica que diz o oposto. 

Outra métrica existe para avaliar a **ciclicidade de um grupo cíclico de pacotes**. Esta métrica é dada pelo quadrado do número de pacotes neste grupo, ou seja, um grupo cíclico de pacotes com 5 elementos tem **ciclicidade** de 25. A **ciclicidade de todo um sistema** é dada pela soma das **ciclicidades** de todo o sistema.

A **ciclicidade relativa do sistema** é dada por:

**MLalt = 100 \*  (sqrt(somaDeTodosPacotes))/n** com *n* sendo o número total de pacotes. Esta métrica é uma alternativa a ML3.

A ML4 é dada pelo mínimo entre MLalt e ML3.  

Para que saibamos o processo de aplicação dessas métricas sem erro podemos seguir o documento [Apoio aula 6](./aula6_apoio.pdf).


## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!
