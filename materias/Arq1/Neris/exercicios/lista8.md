# Lista de Exercícios 8

#### Professor
[![Neris](https://img.shields.io/badge/Luciano_Neris-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)](https://site.dc.ufscar.br/docente/5cee7e5d48365a001679f750)


## Memória e Cache

### 1 - Por que um sistema de hierarquia de memória, onde um dispositivo pequeno como o cache fica perto do processador, é eficiente?

### 2 - Quando um programa sequencial é executado, que tipo de localidade de referência (espacial ou temporal) pode ser explorado pelo cache?

### 3 - Quando num programa, um laço é executado repetidas vezes, que tipo de localidade de referência pode ser explorada pelo cache, no que se refere ao acesso às instruções repetidamente?

### 4 - Seja um cache de mapeamento direto com o tamanho de 4 Kbytes, ou 1024 palavras, e tamanho de slot de 4 palavras, inicialmente vazio. Se uma área de memória de 8 Kbytes com endereço inicial igual a 4096 é referenciada pelo processador MIPS em sequência, apenas para leitura, quantos erros e acertos devem ocorrer?

### 5 - Se no exercício anterior, o processador referenciar duas vezes a área de memória de 8 Kbytes, ou seja, faz a leitura de 8 Kbytes completa e repete a operação a) qual seria o número de erros e acertos? b) e se o tamanho do cache fosse de 2048 palavras?

### 6 - Para uma organização do cache fosse associativo por conjunto de 2 vias, com tamanho de bloco de 4 palavras, sendo o tamanho do cache de 8Kbytes, se uma área de memória de 8 Kbytes com endereço inicial igual a 4096 é referenciada pelo processador MIPS em sequência, apenas para leitura, quantos erros e acertos devem ocorrer?

### 7 - Se no exercício anterior, o processador referenciar duas vezes a área de memória de 8 Kbytes, ou seja, faz a leitura de 8 Kbytes completa e repete a operação a) qual seria o número de erros e acertos?

### 8 - Por que num sistema de memória virtual, é usado o TLB (Translation Look-aside Buffer)?

### 9 - Seja o exemplo do cache em mapeamento direto da Fig. 1:

#### a) qual o tamanho de um bloco em bytes?

#### b) onde as palavras de endereços 0, 5, 17 e 66 são mapeados?

#### c) onde o bloco de número 8192 é mapeado? qual é o tag nesse caso?

#### d) qual o endereço da primeira palavra do bloco de número 128?

![Figura 1](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/Arq1/imagem_2024-03-18_180140984.png)

### 10 - Por que as memórias estáticas são usadas se o custo por Mbyte varia em torno de 100 reais, enquanto que as memórias dinâmicas tem um custo 100 vezes menor?

### 11 - Por que as memórias dinâmicas são lentas e precisam ser reavivadas a um intervalo de alguns milisegundos?

### 12 - O que significa princípio de localidade de referência? Quais tipos de localidade de referência existem?

### 13 - Como funciona o cache de mapeamento direto?

### 14 - Como funciona o cache de mapeamento associativo por conjunto?

### 15 - O que significa um mapeamento totalmente associativo?

### 16 - Para que serve o campo tag do endereço de memória? Como o campo tag é usado para verificar se um dado bloco está no cache?

### 17 - O que acontece quando o processador faz uma referência de leitura a uma palavra cujo bloco de memória não é encontrado no cache? O que acontece se no slot do cache onde o bloco deve ser carregado existir um bloco válido?

### 18 - O que acontece quando um processador faz uma referência de escrita a uma palavra?

### 19 - O que se entende por intercalação de bancos de memória, ou interleaving?

### 20 - Por que no sistema de memória virtual, a atualização do disco usa o critério de write-back?

### 21 - Para que serve a tabela de páginas num sistema de memória virtual?

### 22 - Seja o exemplo do cache em mapeamento direto da Fig. 3:

#### a) qual o tamanho de um bloco em bytes?

#### b) onde as palavras de endereços 0, 4, 16 e 64 são mapeados?

#### c) onde o bloco de número 4096 é mapeado? qual é o tag nesse caso?

#### d) qual o endereço da primeira palavra do bloco de número 4096?

### 23 - Considerando-se que é executado um programa num computador MIPS, que lê quatro vezes em seguida, um vetor na memória, de comprimento 20, que se inicia no endereço 16, e que o cache em mapeamento direto da Figura 3 é usado na hierarquia de memória, calcular a quantidade de acertos (hit) e de erros (miss), apenas referente ao acesso às palavras do vetor. Observação: considerar inicialmente, o cache totalmente vazio.

### 24 - Ainda, usando o mesmo cache em mapeamento direto da Figura 3, executando um programa no computador MIPS, que lê duas vezes, alternadamente, dois vetores na memória, A e B, de mesmo comprimento, 20, sendo que o vetor A se inicia no endereço 16, e o vetor B, no endereço 16400, calcular a quantidade de acertos e erros, no que se refere ao acesso às palavras dos vetores A e B (Observação: 1) considerar inicialmente o cache totalmente vazio; 2) sequência de leitura dos vetores -> A, B, A, B); 3) o mapeamento do vetor B coincide com o do vetor A, pois o endereço 16400 é igual a 4x4096 +16.

### 25 - Dado o cache associativo por conjunto da Fig.4:

#### a) Onde se carregam os blocos de números 0, 256, 512 e 1024? Quais são os respectivos tags?

#### b) Como poderia melhorar esse cache para explorar a localidade espacial?

#### c) Explicar como seria a seleção do dado quando um bloco fosse constituído de 2 palavras.

![Figura4](https://raw.githubusercontent.com/petbccufscar/.github/main/pet-colab/Arq1/imagem_2024-03-18_180140984.png)

### 26 - Usando o cache em mapeamento associativo por conjunto da Figura 4, executando um programa no computador MIPS, que lê duas vezes, alternadamente, dois vetores na memória, A e B, de mesmo comprimento, 20, sendo que o vetor A se inicia no endereço 16, e o vetor B, no endereço 16400, calcular a quantidade de acertos e erros, no que se refere ao acesso às palavras dos vetores A e B.


## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!