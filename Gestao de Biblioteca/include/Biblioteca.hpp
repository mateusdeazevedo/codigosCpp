#ifndef BIBLIOTECA_HPP
#define BIBLIOTECA_HPP

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
    void adicionarLivros(std::string titulo, int ano, std::string autor);
    void adicionarRevista(std::string titulo, int ano, int edicao);
    void listarTodos();
    void buscarPorTitulo(std::string titulo);
    void buscaPorIntervaloTempo(int anoIni, int anoFim);
    void ordenarAno();
    void ordenarTitulo();
    void totalItens();
    void mediaAnoItens();
};

#endif
