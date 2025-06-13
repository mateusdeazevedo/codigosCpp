#include "vendas.h"

Vendas* Vendas::inserirNumeros(Vendas *T, int num)
{
    Vendas *aux = new Vendas();
    aux->num = num;
    aux->elo = T;
    T = aux;
    return T;
}

void Vendas::mostrarNumeros(Vendas *T)
{
    Vendas *aux = T;
    if (aux == NULL)
    {
        std::cout << "Sem vendas!" << std::endl;
    }
    else
    {
        std::cout << "\nVendas:\n";
        while (aux != NULL)
        {
            std::cout << aux->num << " ";
            aux = aux->elo;
        }
        std::cout << std::endl;
    }
}

int Vendas::somarNumeros(Vendas *T)
{
    Vendas *aux = T;
    if (aux == NULL)
    {
        std::cout << "Não foram inseridas vendas." << std::endl;
        return 0;
    }
    else
    {
        int soma = 0;
        while (aux != NULL)
        {
            soma += aux->num;
            aux = aux->elo;
        }
        return soma;
    }
}

Vendas* Vendas::removerNumero(Vendas *T)
{
    Vendas *aux = T;
    T = T->elo;
    delete (aux);
    return T;
}
