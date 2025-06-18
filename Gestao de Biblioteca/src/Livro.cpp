#include "Livro.hpp"
#include <iostream>

Livro::Livro() : Item()
{
    autor = "";
}
Livro::Livro(std::string titulo, int ano, std::string autor)
    : Item(titulo, ano), autor(autor) {}
void Livro::setAutor(std::string autor)
{
    this->autor = autor;
}
std::string Livro::getAutor() const
{
    return autor;
}
void Livro::mostrarInfo() const
{
    std::cout << "Titulo: " << titulo << ". Ano: " << ano << ". Autor: " << autor << std::endl;
}
