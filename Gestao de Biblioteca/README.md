# 📚 Projeto Biblioteca Completa

Bem-vindo ao sistema de gerenciamento de acervo de uma biblioteca! Este projeto é um exercício de programação orientada a objetos em C++, com foco em herança, polimorfismo, modularização e manipulação de arquivos.

---

## 🎯 Objetivo

O sistema permite o cadastro e gerenciamento de **livros** e **revistas**, utilizando classes, arrays, arquivos e um menu interativo no terminal.

---

## 🛠️ Funcionalidades

### 📌 Cadastro
- [x] Adicionar livros com título, ano e autor.
- [x] Adicionar revistas com título, ano e número da edição.

### 📌 Listagem
- [x] Listar todo o acervo (livros e revistas).

### 📌 Busca
- [x] Buscar item por título exato.
- [x] Buscar por trecho do título.
- [x] Listar itens por intervalo de ano.

### 📌 Ordenação
- [x] Ordenar acervo por título (A-Z).
- [x] Ordenar acervo por ano (mais antigo → mais recente).

### 📌 Estatísticas
- [x] Contar total de livros e revistas.
- [x] Calcular média dos anos de publicação.

### 📌 Arquivos
- [x] Salvar acervo em arquivo `.txt`.
- [x] Carregar acervo de um arquivo `.txt`.

---

## 🔧 Estrutura de Arquivos

```bash
Biblioteca/
├── include/
│   ├── Item.hpp
│   ├── Livro.hpp
│   ├── Revista.hpp
│   └── Biblioteca.hpp
├── src/
│   ├── Item.cpp
│   ├── Livro.cpp
│   ├── Revista.cpp
│   └── Biblioteca.cpp
├── main.cpp
├── README.md
└── Makefile
```

---

## 🧠 Conceitos Utilizados

- Herança e polimorfismo (`virtual`, `override`)
- Modularização com `.hpp` e `.cpp`
- Alocação dinâmica (`new`, `delete`)
- Manipulação de arquivos (`fstream`)
- Menu interativo via terminal (`switch` + `do/while`)
- Boas práticas com `const` e passagem por referência

---

## 🚧 Próximas Etapas

- [x] Implementar ordenações manuais com Bubble Sort ou Selection Sort.
- [ ] Refatorar `Biblioteca` para usar `Item**` e permitir um array misto de objetos (`Livro` e `Revista`).
- [ ] Adicionar validação de entrada e tratamento de erros.
- [ ] Testar salvamento e carregamento de acervo em arquivo `.txt` com leitura linha a linha.

---

## ✍️ Autor

Projeto desenvolvido por Mateus — estudante de Curso Técnico de Informática.
