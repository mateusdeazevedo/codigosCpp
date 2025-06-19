#pragma once

#include "Item.hpp"
#include "Livro.hpp"
#include "Revista.hpp"
#include <string>

const int MAX_ITENS = 100;

class Biblioteca
{
private:
    Livro livros[MAX_ITENS];
    int qtdLivros;

    Revista revistas[MAX_ITENS];
    int qtdRevistas;

public:
    Biblioteca();
    Biblioteca(int qtdLivros, int qtdRevistas);
    void adicionarLivros(const std::string& titulo, int ano, const std::string& autor);
    void adicionarRevista(const std::string& titulo, int ano, int edicao);
    void listarTodos();
    void buscarPorTitulo(const std::string& titulo);
    void buscaPorIntervaloTempo(int anoIni, int anoFim);
    void ordenarAno();
    void ordenarTitulo();
    void totalItens();
    void mediaAnoItens();
    void buscaTrechoTitulo(const std::string& trecho);
    void salvarAcervo(const std::string& nomeArquivo);
    void carregarAcervo(const std::string& nomeArquivo);
};
