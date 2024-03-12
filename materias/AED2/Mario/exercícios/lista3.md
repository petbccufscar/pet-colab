# Lista de Exercícios 3

#### Professor
[![Mario](https://img.shields.io/badge/Mario_San_Felice-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)](https://site.dc.ufscar.br/docente/5cee7e5d48365a001679f750)

## Tabelas Hash

### 1. 
Suponha que `ch` e `M` são divisíveis por um inteiro `k`. Mostre que `ch % M` também será divisível por `k`. (Este exercício dá uma pequena indicação das vantagens de usar um número primo como valor de `M` numa tabela de espalhamento.)

### 2. 
Sendo `R` o número de chaves possíveis no universo e `M` o tamanho da tabela de espalhamento, seja `d` o número ⌈R/M⌉, isto é, teto de R/M. Considere a função de espalhamento que associa a cada chave `ch` o piso de `ch/d` (ou seja, o resultado da divisão inteira de `ch` por `d`). Por exemplo, se `R` é 10^5 e `M` é 10^2 então `d` vale 10^3 e portanto `ch/d` é dado pelos dois primeiros dígitos decimais de `ch`. Discuta a qualidade dessa função de espalhamento.

### 3. 
Considere uma tabela de espalhamento de tamanho `M = 13` cuja função de espalhamento é o resto da divisão da chave por `M`. Dado o fluxo de chaves `17 21 19 4 26 30 37` faça:
   - a) Uma figura do estado final da tabela de espalhamento usando hashing com encadeamento.
   - b) Uma figura do estado final da tabela de dispersão usando hashing com sondagem linear.

### 4. 
A execução da função `contabiliza` apresentada a seguir é abortada se a tabela de dispersão estiver cheia. Escreva uma versão melhor, que redimensione a tabela escolhendo um novo valor de `M` que seja aproximadamente o dobro do anterior, alocando uma nova tabela `tb`, e reinserindo todas as chaves na nova tabela.

```c
void contabiliza (int ch) {
    int c, sonda, h;
    h = hash (ch, M);
    for (sonda = 0; sonda < M; sonda++) {
        c = tb[h].chave;
        if (c == -1 || c == ch) break;
        h = (h + 1) % M;
    }
    if (sonda >= M)
        exit (EXIT_FAILURE);

    if (c == -1)
        tb[h].chave = ch;
    tb[h].ocorr++;
}
```

### 5. 
Considere a função `convert` apresentada a seguir.
```c
typedef char *string;
unsigned convert (string s) {
    unsigned h = 0;
    for (int i = 0; s[i] != '\0'; i++)
        h = h * 256 + s[i];
    return h;
}
```
   - a) **Demonstração da colisão:**
     - Se trocarmos o valor 256 por 1 na função `convert`, o resultado de `h` será sempre igual ao número de caracteres na string `s`. Portanto, todas as permutações da string `s` resultarão no mesmo valor de `h`, o que causa colisão.
     
   - b) **Razão para não trocar as linhas:**
     - Trocar as linhas para `unsigned h = s[0];` e `for (i = 1; s[i] != '\0'; i++)` resultará em uma função de espalhamento que considera apenas o primeiro caractere da string `s`. Isso significa que muitas chaves diferentes terão o mesmo valor de espalhamento, o que pode aumentar a incidência de colisões e reduzir a eficácia da tabela de espalhamento.

## Material Auxiliar

Para revisar conceitos sobre tabelas hash e encontrar mais exercícios acesse:

- https://www.ime.usp.br/~pf/algoritmos/aulas/hash.html
  
## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!
