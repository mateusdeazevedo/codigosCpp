#include <iostream>

class Binario
{
    public:
    int Numero;
    Binario *elo;
    Binario* Inserir(Binario*, int);
    Binario* Esvaziar(Binario*);
    void Listar(Binario*);
};