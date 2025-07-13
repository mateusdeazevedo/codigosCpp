#include "frase.h"

Frase *Frase::Inserir(Frase *T, char L)
{
    Frase *aux = new Frase();
    aux->Letra = L;
    aux->elo = T;
    T = aux;
    return T;
};

Frase *Frase::Esvaziar(Frase *T)
{
    Frase *aux = T;
    while(aux != nullptr)
    {
        T = T->elo;
        delete(aux);
        aux = T;
    }
    return T;
};

void Frase::Listar(Frase *T)
{
    Frase *aux = T;
    while (aux != nullptr)
    {
        std::cout << aux->Letra;
        aux = aux->elo;
    }
};
