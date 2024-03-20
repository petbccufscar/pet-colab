# Lista de exercícios 2

#### Professor
[![Renato](https://img.shields.io/badge/Renato_Bueno-%2300599C.svg?style=for-the-badge&logo=GoogleScholar&logoColor=white)](https://site.dc.ufscar.br/docente/5cee7e5d48365a001679f750)

## EXERCÍCIOS DE SQL

### 1. Uma universidade oferece vários cursos. Para uma aluno concluir um curso, deve cumprir todas as disciplinas contidas no curso. Para cumprir uma disciplina, o aluno precisa obter nota igual ou superior a 7. Toda disciplina é ministrada por um único professor.
```
Foi criado o seguinte Modelo Relacional:
Aluno = { NumAluno, Nome, Endereco, Cidade, Telefone, NumCurso(Curso.NumCurso) }
Disciplina= { NumDisp, Nome, QuantCreditos }
Professor = { NumFunc, Nome, Admissao, AreaPesquisa }
Curso = { NumCurso, Nome, TotalCréditos }
Aula = { NumAluno(Aluno.NumAluno), NumDisp(Disciplina.NumDisp), NumFunc(Professor.NumFunc), Semestre, Nota }
DisciplinaCurso= { NumDisp(Disciplina.NumDisp), NumCurso(Curso.NumCurso) }
```

Criar a base de dados: as tabelas com respectivas chaves, chaves estrangeiras e cadastrar os dados das tabelas.

## Consultas

### 1. Todos os cursos da universidade.

### 2. Quais os nomes e telefones de alunos da cidade de São Carlos - SP em ordem DESC de nome.

### 3. Quais os nomes de alunos que iniciam com a letra ‘a'.

### 4. Quais os nomes das disciplinas do curso de Ciência da Computação.

### 5. Quais os nomes das disciplinas que o aluno `Fulano de Tal` foi reprovado.

### 6. Quais os nomes de alunos reprovados na disciplina de Programação de computadores no 1o semestre de 2009.

### 7. Quais os nomes dos professores que já ministraram aula de Banco de Dados.

### 8. Qual a maior e a menor nota na disciplina Programação de Computadores no 1o semestre de 2010.

### 9. Qual o nome do aluno que obteve maior nota na disciplina de Engenharia de Software no 1o semestre de 2010. Deve retornar o nome e a nota do aluno.

### 10. Quais os nomes de alunos que cursaram o 1o semestre de 2010 em ordem alfabética, em cada disciplina oferecida nesse semestre (listar também os nomes das disciplinas e os nomes dos professores que ministraram cada disciplina).

### 11. Quais nomes de alunos, nomes de disciplinas e notas do 1o semestre 2010 no curso de Ciência da Computação.

### 12. Qual a média de notas e a quantidade de disciplinas cursadas pelo aluno `Fulano de tal`.

### 13. Quais as médias das notas, por nome de professor, no 1o semestre de 2010.

### 14. Qual foi a quantidade de créditos concluídos (considerar somente as disciplinas aprovadas) do aluno `Fulano de tal`.

### 15. Quais os nomes de alunos que já completaram 70 créditos (considerar somente os aprovados na disciplina). Deve retornar os nomes dos alunos e a quantidade de créditos.

### 16. Quais os nomes de alunos que cursaram o 1o semestre de 2010, pertencem ao curso de Ciência da Computação e possuem nota superior à 8.0. Deve retornar os nomes dos alunos, os nomes da disciplina e os nomes dos professores.


## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!