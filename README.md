# 🏥 Sistema de Clínica Médica

<p align="center">
  <strong>Sistema desenvolvido em Linguagem C para gerenciamento de clínicas médicas.</strong>
</p>

<p align="center">
  Cadastro de pacientes, médicos, especialidades, consultas e geração de relatórios.
</p>

---

## 📖 Sobre o Projeto

O **Sistema de Clínica Médica** é uma aplicação desenvolvida em **Linguagem C** com o objetivo de auxiliar no gerenciamento básico de uma clínica médica.

O sistema permite cadastrar pacientes, médicos, especialidades e consultas, além de disponibilizar relatórios para acompanhamento das informações registradas.

Este projeto foi desenvolvido para fins acadêmicos, aplicando conceitos de:

* Programação Estruturada
* Modularização
* Manipulação de Dados
* Validação de Informações
* Organização de Sistemas

---

## ✨ Funcionalidades

### 👥 Pacientes

* ✅ Cadastrar pacientes
* ✅ Listar pacientes cadastrados
* ✅ Buscar pacientes por código
* ✅ Buscar pacientes por nome
* ✅ Alterar informações
* ✅ Excluir pacientes
* ✅ Validar CPF, telefone e idade

---

### 👨‍⚕️ Médicos

* ✅ Cadastrar médicos
* ✅ Listar médicos cadastrados
* ✅ Buscar por CRM
* ✅ Buscar por especialidade
* ✅ Alterar informações
* ✅ Excluir médicos

---

### 🩺 Especialidades

* ✅ Cadastrar especialidades
* ✅ Listar especialidades
* ✅ Associar médicos às especialidades
* ✅ Consultar especialidades existentes

---

### 📅 Consultas

* ✅ Agendar consultas
* ✅ Listar consultas
* ✅ Buscar consultas por paciente
* ✅ Buscar consultas por médico
* ✅ Alterar consultas
* ✅ Cancelar consultas
* ✅ Marcar como realizadas

---

### 📊 Relatórios

O sistema gera relatórios contendo:

* 📌 Quantidade de pacientes
* 📌 Quantidade de médicos
* 📌 Consultas agendadas
* 📌 Consultas realizadas
* 📌 Consultas canceladas
* 📌 Consultas por especialidade
* 📌 Consultas por médico

---

## 🖥️ Menu Principal

Ao executar o sistema, será exibido o seguinte menu:

```text
===== SISTEMA DE CLÍNICA MÉDICA =====

1 - Pacientes
2 - Médicos
3 - Consultas
4 - Especialidades
5 - Relatórios
6 - Sair

Escolha uma opção:
```

Digite a opção desejada e pressione **ENTER**.

---

## 🚀 Ordem Recomendada de Utilização

Para evitar inconsistências durante o uso:

1. 👨‍⚕️ Cadastrar médicos
2. 🩺 Cadastrar especialidades
3. 🔗 Associar médicos às especialidades
4. 👥 Cadastrar pacientes
5. 📅 Agendar consultas
6. 📊 Consultar relatórios

---

## 📝 Exemplo de Uso

### Passo 1 — Cadastrar Médico

Informações necessárias:

* Nome
* CRM
* Especialidade
* Telefone

### Passo 2 — Cadastrar Paciente

Informações necessárias:

* Nome
* CPF
* Telefone
* Idade
* Convênio

### Passo 3 — Agendar Consulta

Informações necessárias:

* Código da consulta
* Paciente
* Médico
* Data
* Horário

Após o cadastro, a consulta ficará registrada no sistema.

---

## ⚙️ Compilação

Utilizando o GCC:

```bash
gcc main.c pacientes.c medico.c consulta.c especialidades.c relatorios.c -o sistema_clinica
```

---

## ▶️ Execução

### Windows

```bash
sistema_clinica.exe
```

ou

```bash
.\sistema_clinica.exe
```

### Linux

```bash
./sistema_clinica
```

---

## 📂 Estrutura do Projeto

```text
Projeto
│
├── main.c
├── globais.h
├── pacientes.c
├── medico.c
├── consulta.c
├── especialidades.c
├── relatorios.c
└── README.md
```

### Descrição dos Arquivos

| Arquivo          | Função                               |
| ---------------- | ------------------------------------ |
| main.c           | Menu principal e controle do sistema |
| pacientes.c      | Gerenciamento de pacientes           |
| medico.c         | Gerenciamento de médicos             |
| consulta.c       | Gerenciamento de consultas           |
| especialidades.c | Gerenciamento de especialidades      |
| relatorios.c     | Geração de relatórios                |
| globais.h        | Estruturas e definições globais      |

---

## ⚠️ Limitações

Atualmente o sistema possui algumas limitações:

* Os dados existem apenas durante a execução do programa
* Não há banco de dados
* Não existe salvamento automático em arquivos
* Não possui autenticação de usuários
* Interface exclusivamente em terminal

> Ao encerrar o programa, todas as informações cadastradas serão perdidas.

---

## ❓ Possíveis Problemas

### Não consigo agendar uma consulta

Verifique se o médico e o paciente já foram cadastrados.

### O código informado já existe

Cada registro deve possuir um identificador único.

Utilize outro código.

### O programa não executa

Verifique:

* Se todos os arquivos do projeto estão presentes
* Se a compilação ocorreu sem erros

---

## 🎓 Objetivo Acadêmico

Este projeto foi desenvolvido para aplicação prática dos conceitos estudados em Linguagem C:

* Estruturas de Dados
* Vetores
* Funções
* Modularização
* Validação de Dados
* Organização de Sistemas

---

## 👨‍💻 Autores

### Alunos

* Breno de Queiroz Chaves
* Breno de Souza Aguiar
* Marco Antônio Oliveira Silva Júnior
* Arthur Ceregatti Dâmaso de Oliveira
* Gabriel Souza Sarmento
* Kauã do Nascimento Figueiredo
* Nicoly Vaz Moreira
* Arthur Luan Jácome Matias
* Maria Eduarda Silva Canedo
* João Gabriel De Sousa Rodrigues
* Antônio Augusto Ramos de Souza

### Professor

Hudson Silva Neves

### Instituição

🎓 Uniceplac

### Ano

📅 2026

---

<p align="center">
  Desenvolvido para fins acadêmicos ❤️
</p>
