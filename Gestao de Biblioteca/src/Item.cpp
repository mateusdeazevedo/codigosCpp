#include "Item.hpp"

Item::Item()
{
    titulo = "";
    ano = 0;
}
Item::Item(std::string titulo, int ano)
{
    this->titulo = titulo;
    this->ano = ano;
}
void Item::setTitulo(std::string titulo)
{
    this->titulo = titulo;
}
std::string Item::getTitulo() const
{
    return titulo;
}
void Item::setAno(int ano)
{
    this->ano = ano;
}
int Item::getAno() const
{
    return ano;
}
