#include "sequencia.h"

Sequencia *Sequencia::InserirFila(Sequencia *F, int N)
{
    Sequencia *aux = new Sequencia();
    aux->Num = N;
    aux->elo = NULL;
    if(F != NULL){
        F->elo = aux;
    }
    F = aux;
    return F;
};

Sequencia *Sequencia::InserirPilha(Sequencia *T, int N)
{
    Sequencia *aux = new Sequencia();
    aux->Num = N;
    aux->elo = T;
    T = aux;
    return T;
};

void Sequencia::Listar(Sequencia *Ponteiro)
{
    Sequencia *aux = Ponteiro;
    while (aux != NULL)
    {
        std::cout << aux->Num << " ";
        aux = aux->elo;
    }
};

Sequencia *Sequencia::Excluir(Sequencia *Ponteiro)
{
    Sequencia *aux = Ponteiro;
    while (aux != NULL)
    {
        Ponteiro = Ponteiro->elo;
        delete (aux);
        aux = Ponteiro;
    }
    return Ponteiro;
};