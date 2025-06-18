#include "Revista.hpp"
#include <iostream>

Revista::Revista() : Item()
{
    numeroEdicao = 0;
}
Revista::Revista(std::string titulo, int ano, int numeroEdicao)
    : Item(titulo, ano), numeroEdicao(numeroEdicao) {}
void Revista::setNumeroEdicao(int numeroEdicao)
{
    this->numeroEdicao = numeroEdicao;
}
int Revista::getNumeroEdicao() const
{
    return numeroEdicao;
}
void Revista::mostrarInfo() const
{
    std::cout << "Titulo: " << titulo << ". Ano: " << ano << ". Numero da Edicao: " << numeroEdicao << std::endl;
}
