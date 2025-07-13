#include <iostream>

class Sequencia
{
    public:
    int Num;
    Sequencia *elo;
    Sequencia* InserirPilha(Sequencia*, int);
    Sequencia* InserirFila(Sequencia*, int);
    void Listar(Sequencia*);
    Sequencia* Excluir(Sequencia*);
    
};