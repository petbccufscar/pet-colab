# Guia Básico: GitHub
<img src="https://raw.githubusercontent.com/petbccufscar/.github/main/profile/icon.png" align="right" />

> Esse material é parte do curso de Git e Github do PET-BCC

GitHub é uma plataforma de hospedagem de código fonte que utiliza o Git para controle de versão. Ele facilita a colaboração entre desenvolvedores, permitindo o compartilhamento e gerenciamento eficiente de projetos.

## Estrutura de um Projeto no GitHub

Um projeto no GitHub geralmente consiste em repositórios, issues, pull requests, branches e outros elementos que facilitam o desenvolvimento colaborativo.

## Clone um Repo do GitHub

O comando `git clone` também é usado para clonar repositórios do GitHub.

```bash
git clone URL_do_Repositório_Remoto
```

## Clone um Branch Individual

```bash
git clone -b nome_da_branch URL_do_Repositório_Remoto
```

## Use um Branch do GitHub como Modelo

1. **Crie um novo repositório localmente:**

   ```bash
   git init nome_do_projeto
   ```

2. **Adicione o repositório remoto do GitHub:**

   ```bash
   git remote add origin URL_do_Repositório_Remoto
   ```

3. **Clone o branch desejado como modelo:**

   ```bash
   git pull origin nome_da_branch
   ```

## Pull Requests

Pull Requests são propostas de alterações que os desenvolvedores enviam para o repositório original. Siga estes passos para criar um Pull Request:

1. **Crie uma nova branch para suas alterações:**

   ```bash
   git checkout -b nome_da_sua_branch
   ```

2. **Realize as alterações e faça commits:**

   ```bash
   git add .
   git commit -m "Mensagem descritiva das alterações"
   ```

3. **Envie a branch para o GitHub:**

   ```bash
   git push origin nome_da_sua_branch
   ```

4. **No GitHub, vá para a página do seu repositório e clique em "Compare & pull request".**

5. **Preencha os detalhes do seu Pull Request e clique em "Create pull request".**

6. **Aguarde revisão e feedback de outros colaboradores antes da mesclagem.**

## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!

Lembre-se, a prática é fundamental para se familiarizar com o Git e o GitHub. Boa sorte!