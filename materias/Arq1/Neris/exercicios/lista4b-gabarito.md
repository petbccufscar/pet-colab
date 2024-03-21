# Gabarito Lista de Exercícios 4b

#### Professor
[![Neris](https://img.shields.io/badge/Luciano_Neris-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)](https://site.dc.ufscar.br/docente/5cee7e5d48365a001679f750)


## Arquitetura MIPS

### Questão 1 

No MIPS multiciclo, necessitamos acrescentar:
RI (registrador de instrução), para que a no final do ciclo de busca de instrução, uma nova instrução contida em RI represente o novo estado do computador;

A e B (registradores de dados lidos do banco de registradores), para que no final do segundo ciclo, os dados a serem processados estejam contidos nesses registradores;

ULA (registrador do resultado da ULA), para que no final do ciclo de operação da ULA, o resultado esteja
guardado nesse registrador;


RDM (registrador de dado da memória), para que após a leitura de um dado da memória, o mesmo seja
guardado nesse registrador.


### Questão 2 

#### a) 
No estado 2, ULAFonteA = 1, ULAFonteB = 10, ULAOp = 00. O operando 1 da ULA é sempre o dado1 do banco de registradores. O operando 2, como ULAFonteB = 10, são os 16 bits da instrução estendidos para 32 bits.

A operação aritmética é dada por ULAOp = 00, que resulta em adição.

#### b) 
No estado 4, EscReg = 1, MemParaReg = 1 e Regdst = 0. O dado a ser escrito no registrador depende do multiplexador MemParaReg, que como é igual a 1, deve vir do registrador RDM.

### Questão 3 

#### 1)

Acrescentar o estado 10 com a seguinte operação – calcular a adição de um operando do registrador com um segundo operando proveniente dos 16 bits da instrução estendidos para 32 bits, colocando o resultado no registrador ULA. Os sinais de controle são ULAFonteA = 1, ULAFonteB = 10 e ULALOp = 00, para a operação de adição.

#### 2) 

Acrescentar o estado 11 em sequência ao estado 10, com a operação de escrita do resultado contido no registrador ULA no registrador destino. Os sinais de controle são MemParaReg = 0 para selecionar o caminho do registrador ULA para o registrador destino; EscReg = 1 , para escrever no registrador; e RegDst = 0, para selecionar o registrador destino.

## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!