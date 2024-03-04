# Guia básico: Git
<img src="https://raw.githubusercontent.com/petbccufscar/.github/main/profile/icon.png" align="right" />

> Esse material é parte do curso de Git e Github do PET-BCC

Git é um sistema de controle de versão distribuído utilizado para rastrear as alterações em arquivos durante o desenvolvimento de software. Ele permite que várias pessoas colaborem em um projeto, mantendo um histórico completo de todas as mudanças.

## Repositório

Um repositório (ou "repo") no Git é um local onde seus arquivos do projeto são armazenados, juntamente com o histórico de todas as alterações. Pode ser local (no seu computador) ou remoto (em um servidor, como no GitHub).

## Instalação do Git e Pré-requisitos

Antes de começar, você precisa instalar o Git no seu computador. [Baixe e instale o Git](https://git-scm.com/). Após a instalação, configure suas informações:

```bash
git config --global user.name "Seu Nome"
git config --global user.email "seu@email.com"
```

## Comandos Básicos do Git

1. **Verificar o Status:**

   O comando `git status` mostra o estado atual do seu repositório, indicando quais arquivos foram modificados, adicionados ou removidos.

   ```bash
   git status
   ```

2. **Adicionar Alterações ao Stage:**

   O comando `git add` prepara as alterações para serem confirmadas. Você pode adicionar arquivos específicos ou todos de uma vez.

   ```bash
   git add nome_do_arquivo
   ```

   Para adicionar todas as alterações:

   ```bash
   git add .
   ```

3. **Confirmar Alterações:**

   O comando `git commit` salva as alterações no repositório, fornecendo uma mensagem descritiva.

   ```bash
   git commit -m "Mensagem de commit"
   ```

## Trabalhe com o Ambiente de Preparo Staging

1. **Criar um novo repositório:**

   O comando `git init` cria um novo repositório local no diretório atual.

   ```bash
   git init
   ```

2. **Clonar um repositório existente:**

   O comando `git clone` faz uma cópia de um repositório remoto para o seu computador.

   ```bash
   git clone URL_do_Repositório
   ```

## Delete Arquivos

### Excluir e Desfazer Alterações

- **Excluir um arquivo do diretório de trabalho:**

  ```bash
  git rm nome_do_arquivo
  ```

- **Cancelar as mudanças não confirmadas em um arquivo:**

  ```bash
  git checkout -- nome_do_arquivo
  ```

### Status e Recuperação

- **Verificar o status das alterações:**

  ```bash
  git status
  ```

- **Adicionar alterações ao Stage:**

  ```bash
  git add nome_do_arquivo
  ```

- **Restaurar um arquivo do Stage (unstage):**

  ```bash
  git restore --staged nome_do_arquivo
  ```

- **Desfazer alterações no diretório de trabalho:**

  ```bash
  git restore nome_do_arquivo
  ```

### Reset HEAD

- **Desfazer o último commit, mantendo as alterações no diretório de trabalho:**

  ```bash
  git reset --soft HEAD^
  ```

- **Desfazer o último commit e as alterações no diretório de trabalho:**

  ```bash
  git reset --hard HEAD^
  ```

## Lide com os seus Logs

O comando `git log` exibe o histórico de commits, mostrando quem fez alterações e quando.

```bash
git log
```

## Controle Estados com Ramos (Branches)

1. **Criar uma nova branch:**

   O comando `git branch` cria uma nova branch (ramo) para trabalhar.

   ```bash
   git branch nome_da_branch
   ```

2. **Mudar para uma branch existente:**

   O comando `git checkout` muda para a branch especificada.

   ```bash
   git checkout nome_da_branch
   ```

   Ou em versões mais recentes do Git:

   ```bash
   git switch nome_da_branch
   ```

3. **Mesclar alterações de uma branch para outra:**

   O comando `git merge` combina as alterações de uma branch em outra.

   ```bash
   git merge nome_da_branch
   ```


## Contato

Se você tiver alguma dúvida, sugestão ou precisar de suporte, por favor, sinta-se à vontade para entrar em contato conosco:

- **E-mail:** petbcc.ufscar@gmail.com

Você também pode criar uma **Issue** no [GitHub](https://github.com/petbccufscar/pet-colab/issues) para relatar problemas, sugerir melhorias ou contribuir para o desenvolvimento do PET-COLAB. Estamos sempre abertos para receber feedback e colaboração. Obrigado!

Lembre-se, a prática é fundamental para se familiarizar com o Git e o GitHub. Boa sorte!