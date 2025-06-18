#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>

class Item
{
protected:
    std::string titulo;
    int ano;

public:
    Item();
    Item(std::string titulo, int ano);

    void setTitulo(std::string titulo);
    std::string getTitulo() const;

    void setAno(int ano);
    int getAno() const;

    virtual void mostrarInfo() const = 0;
};

#endif
