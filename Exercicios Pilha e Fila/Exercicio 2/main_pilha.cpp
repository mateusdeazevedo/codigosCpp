#include "pilha.h"

Pilha *Pilha::Inserir(Pilha *T, int N)
{
    Pilha *aux = new Pilha();
    aux->Numero = N;
    aux->elo = T;
    T = aux;
    return T;
};

Pilha *Pilha::Esvaziar(Pilha *T)
{
    Pilha *aux = T;
    while (aux != nullptr)
    {
        T = T->elo;
        delete (aux);
        aux = T;
    }
    return T;
};

void Pilha::Listar(Pilha *T)
{
    if (T == nullptr)
    {
        std::cout << "Nenhum numero foi inserido." << std::endl;
    }
    else
    {
        std::cout << "Numeros inseridos: ";
        Pilha *aux = T;
        while (aux->elo != nullptr)
        {
            std::cout << aux->Numero << ", ";
            aux = aux->elo;
        }
        std::cout << aux->Numero;
        std::cout << "." << std::endl;
    }
};

void Pilha::ListarMaior(Pilha *T)
{
    Pilha *aux = T;
    int maior = aux->Numero;

    while (aux != nullptr)
    {
        if (maior < aux->Numero)
            maior = aux->Numero;
        aux = aux->elo;
    }

    std::cout << "O maior numero inserido na pilha e o " << maior << "." << std::endl;
};

void Pilha::ListarMenor(Pilha *T)
{
    Pilha *aux = T;
    int menor = aux->Numero;

    while (aux != nullptr)
    {
        if (menor > aux->Numero)
            menor = aux->Numero;
        aux = aux->elo;
    }

    std::cout << "O menor numero inserido na pilha e o " << menor << "." << std::endl;
};

void Pilha::MediaNumeros(Pilha *T)
{
    Pilha *aux = T;
    int media, soma = 0, contador = 0;

    while (aux != nullptr)
    {
        soma += aux->Numero;
        contador++;
        aux = aux->elo;
    }

    media = soma / contador;
    std::cout << "A media dos numeros inseridos na pilha e " << media << "." << std::endl;
};
