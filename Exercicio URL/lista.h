#include <iostream>

class Lista
{
public:
    std::string URL;
    int Quantidade_de_Acessos;
    Lista *elo;

    Lista **Inserir(Lista **R, std::string U, int A);
    void Listar(Lista *I);
    Lista **Excluir(Lista **R, std::string U);
    Lista *Procurar(Lista *I, std::string U);
    Lista **Esvaziar(Lista **R);
};
