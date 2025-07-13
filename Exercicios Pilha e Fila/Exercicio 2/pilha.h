#include <iostream>

class Pilha
{
    public:
    int Numero;
    Pilha *elo;
    Pilha* Inserir(Pilha*, int);
    Pilha* Esvaziar(Pilha*);
    void Listar(Pilha*);
    void ListarMaior(Pilha*);
    void ListarMenor(Pilha*);
    void MediaNumeros(Pilha*);
};