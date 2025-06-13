#include <iostream>

class Vendas
{
private:
    int num;
    Vendas *elo;

public:
    Vendas *inserirNumeros(Vendas *T, int num);
    void mostrarNumeros(Vendas *T);
    int somarNumeros(Vendas *T);
    Vendas *removerNumero(Vendas *T);
};