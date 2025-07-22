#include "lista.h"

Lista **Lista::Inserir(Lista **R, std::string U, int A)
{
    Lista *novo = new Lista();
    novo->URL = U;
    novo->Quantidade_de_Acessos = A;
    if (R[0] == NULL)
    {
        R[0] = novo;
        R[1] = novo;
        R[1]->elo = NULL;
    }
    else
    {
        Lista *atual = R[0], *ant = NULL;
        while ((atual != NULL) && (novo->Quantidade_de_Acessos < atual->Quantidade_de_Acessos))
        {
            ant = atual;
            atual = atual->elo;
        }
        while ((atual != NULL) && (novo->Quantidade_de_Acessos == atual->Quantidade_de_Acessos) && (novo->URL > atual->URL))
        {
            ant = atual;
            atual = atual->elo;
        }
        if (ant == NULL)
        {
            novo->elo = R[0];
            R[0] = novo;
        }
        else if (atual == NULL)
        {
            R[1]->elo = novo;
            R[1] = novo;
            R[1]->elo = NULL;
        }
        else
        {
            ant->elo = novo;
            novo->elo = atual;
        }
    }
    return R;
}

void Lista::Listar(Lista *I)
{
    Lista *aux = I;
    while (aux != NULL)
    {
        std::cout << "URL: " << aux->URL << " | Acessos: " << aux->Quantidade_de_Acessos << std::endl;
        aux = aux->elo;
    }
}

Lista **Lista::Excluir(Lista **R, std::string U)
{
    Lista *aux = R[0];
    Lista *ant = NULL;
    while (aux != NULL && aux->URL != U)
    {
        ant = aux;
        aux = aux->elo;
    }
    if (aux == NULL)
    {
        return R;
    }
    else
    {
        if (ant == NULL)
        {
            R[0] = R[0]->elo;
        }
        else if (aux == R[1])
        {
            R[1] = ant;
            R[1]->elo = NULL;
        }
        else
        {
            ant->elo = aux->elo;
        }
        delete (aux);
    }
    return R;
}

Lista *Lista::Procurar(Lista *I, std::string U)
{
    Lista *aux = I;
    while (aux != NULL && aux->URL != U)
    {
        aux = aux->elo;
    }
    return aux;
}

Lista **Lista::Esvaziar(Lista **R)
{
    Lista *aux = R[0];
    while (aux != NULL)
    {
        R[0] = R[0]->elo;
        delete (aux);
        aux = R[0];
    }
    return R;
}
