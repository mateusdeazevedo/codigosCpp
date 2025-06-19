#pragma once

#include "Item.hpp"
#include <string>

class Livro : public Item
{
private:
    std::string autor;

public:
    Livro();
    Livro(std::string titulo, int ano, std::string autor);
    
    void setAutor(std::string autor);
    std::string getAutor() const;

    void mostrarInfo() const override;
};
