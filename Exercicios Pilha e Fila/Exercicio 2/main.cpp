#include "pilha.h"

using namespace std;

int main()
{
    Pilha P, *Topo = nullptr;

    int n;

    do
    {

        do
        {
            cout << "Insira um numero inteiro positivo: ";
            cin >> n;
            if (n < 0)
                cout << "Numero invalido. Insira outro." << endl;
        } while (n < 0);

        if (n != 0)
            Topo = P.Inserir(Topo, n);

    } while (n != 0);

    cout << "<------------------------------------------->" << endl;

    P.Listar(Topo);
    if(Topo != nullptr)
    {
    P.ListarMaior(Topo);
    P.ListarMenor(Topo);
    P.MediaNumeros(Topo);
    Topo = P.Esvaziar(Topo);
    }

    return 0;
}