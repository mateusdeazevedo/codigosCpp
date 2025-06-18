#include "Biblioteca.hpp"
#include <iostream>

Biblioteca::Biblioteca()
{
    qtdLivros = 0;
    qtdRevistas = 0;
}
Biblioteca::Biblioteca(int qtdLivros, int qtdRevistas)
{
    this->qtdLivros = qtdLivros;
    this->qtdRevistas = qtdRevistas;
}
void Biblioteca::adicionarLivros(std::string titulo, int ano, std::string autor)
{
    if (qtdLivros < 100)
    {
        livros[qtdLivros] = Livro(titulo, ano, autor);
        qtdLivros++;
    }
    else
    {
        std::cout << "Nao eh possivel adicionar mais livros, biblioteca lotada!\n";
    }
}
void Biblioteca::adicionarRevista(std::string titulo, int ano, int edicao)
{
    if (qtdRevistas < 100)
    {
        revistas[qtdRevistas] = Revista(titulo, ano, edicao);
        qtdRevistas++;
    }
    else
    {
        std::cout << "Nao eh possivel adicionar mais revistas, biblioteca lotada!\n";
    }
}
void Biblioteca::listarTodos()
{
    if (qtdLivros == 0 && qtdRevistas == 0)
    {
        std::cout << "Acervo vazio.\n";
    }
    for (int i = 0; i < qtdLivros; i++)
    {
        livros[i].mostrarInfo();
    }
    for (int i = 0; i < qtdRevistas; i++)
    {
        revistas[i].mostrarInfo();
    }
}
void Biblioteca::buscarPorTitulo(std::string titulo)
{
    bool encontrou = false;
    for (int i = 0; i < qtdLivros; i++)
    {
        if (titulo == livros[i].getTitulo())
        {
            std::cout << "Livro encontrado! Exibindo informacoes:\n";
            livros[i].mostrarInfo();
            encontrou = true;
            break;
        }
    }
    for (int i = 0; i < qtdRevistas; i++)
    {
        if (titulo == revistas[i].getTitulo())
        {
            std::cout << "Revista encontrada! Exibindo informacoes:\n";
            revistas[i].mostrarInfo();
            encontrou = true;
            break;
        }
    }
    if (!encontrou)
    {
        std::cout << "Item nao encontrado no acervo.\n";
    }
}