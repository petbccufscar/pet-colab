# Lista de exercícios 4

#### Professor
[![Marilde](https://img.shields.io/badge/Marilde_Santos-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)](https://site.dc.ufscar.br/docente/5cee7e5d48365a001679f750)

## Exercícios Requisitos 

### Elaborar o documento de requisitos consolidado e o esquema conceitual de acordo com as especificações abaixo.

### 1. LOJA DE VENDA DE OBJETOS USADOS E SERVIÇOS DE CONSERTO
```
João Silva decidiu abrir uma loja para vender seus objetos usados e
seus serviços de conserto e limpeza em geral.

João vende produtos e serviços, sendo que possui clientes de vários
bairros da cidade, sendo que ele agrupa a entrega de produtos por
bairro. Sobre os clientes armazenam-se o nome, cpf, endereço,
telefones, e-mail.

Um cliente também pode ser uma empresa e se for, deve-se armazenar
o CNPJ da mesma ao invés do cpf, além das demais informações sobre
clientes.

Sobre seus produtos deve-se armazenar o nome do produto, o código, o
tempo de uso, o estado dele, o preço e descrição.

Sobre os serviços, deseja-se armazenar o código, o nome do serviço,
preço, descrição e tempo que o mesmo leva para ser concluído.

Um cliente pode solicitar um ou mais produtos disponíveis ou serviço.

Sempre quando é feita essa solicitação é registrado a data de envio do
produto ou a data de realização do serviço.

No momento em que o serviço será realizado ou o produto entregue, o
cliente deve pagar pelo mesmo e a nota fiscal com a descrição dos
produtos/serviços envolvidos é gerada.
```

### 2. SISTEMA DE RESERVAS PARA UMA COMPANHIA DE AVIAÇÃO

```
O objetivo é projetar um sistema de reservas para uma companhia de
aviação.

O sistema contará com um banco de dados central, que será acessado
por aplicações clientes, rodando tanto dentro da própria companhia,
quanto fora dela.

A transação central do sistema é a reserva.

Uma reserva é identificada por um código gerado pelo sistema em
computador. A reserva é feita para um único passageiro, do qual se
conhece apenas o nome.

A reserva compreende um conjunto de trechos de voos, que
acontecerão em determinada data e hora. Para cada trecho, a reserva é
feita em uma classe (econômica, executiva, etc.).

Um voo é identificado por um código e possui uma origem e um destino.
Por exemplo, o voo 595 sai de Porto Alegre, com destino a São Paulo.

Um voo é composto de vários trechos, correspondendo às escalas
intermediárias do voo. Por exemplo, o voo 595 é composto de dois
trechos, um de Porto Alegre a Londrina, o outro de Londrina a São
Paulo.

Cabe salientar que há cidades que são servidas por vários aeroportos.
Por isso, é importante informar ao passageiro que faz a reserva, qual é
o aeroporto no qual o voo passa.

Às vezes os clientes, ao fazer a reserva, desejam saber qual é o tipo de aeronave que será utilizada em determinado trecho do voo.

Alguns poucos voos, principalmente internacionais, tem troca de
aeronave em determinadas escalas.

Nem todos os voos operam em todos os dias da semana. Inclusive,
certos voos têm pequenas mudanças de horário em certos dias da
semana.

Cada reserva possui um prazo de validade. Caso os bilhetes não
tenham sido emitidos, até esgotar-se o prazo da reserva, a mesma é
cancelada. Reservas podem ser prorrogadas.

Como o “check-in” de todos os voos está informatizado, a companhia
possibilita a reserva de assento para o passageiro.

Reservas de assento podem ser feitas com até 6 meses de
antecedência.

Além de efetivar reservas, o sistema deve servir para vários tipos de
consultas que os clientes podem querer fazer:  
(a) possibilidades de viagem de uma cidade ou de um aeroporto para o
outro;  
(b) o mesmo, mas restrito a determinados dias da semana;  
(c) horários de chegada ou de saída em determinados voos;  
(d) disponibilidade de vagas em um trecho de voo;  
(e) disponibilidade de determinados assentos em um trecho de voo.  
```

## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!