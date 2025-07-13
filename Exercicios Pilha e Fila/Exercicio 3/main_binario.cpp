#include "binario.h"

Binario *Binario::Inserir(Binario *T, int N)
{
    Binario *aux = new Binario();
    aux->Numero = N;
    aux->elo = T;
    T = aux;
    return T;
};

Binario *Binario::Esvaziar(Binario *T)
{
    Binario *aux = T;
    while (aux != nullptr)
    {
        T = T->elo;
        delete (aux);
        aux = T;
    }
    return T;
};

void Binario::Listar(Binario *T)
{
    if (T == nullptr)
    {
        std::cout << "Nenhum numero foi inserido." << std::endl;
    }
    else
    {
        Binario *aux = T;
        while (aux != nullptr)
        {
            std::cout << aux->Numero;
            aux = aux->elo;
        }
        std::cout << "." << std::endl;
    }
};