#ifndef REVISTA_HPP
#define REVISTA_HPP

#include "Item.hpp"
#include <string>

class Revista : public Item
{
private:
    int numeroEdicao;

public:
    Revista();
    Revista(std::string titulo, int ano, int numeroEdicao);
    void setNumeroEdicao(int numeroEdicao);
    int getNumeroEdicao() const;
    void mostrarInfo() const override;
};

#endif
