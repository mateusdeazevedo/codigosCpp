#include "frase.h"

using namespace std;

int main()
{
    Frase F, *Topo = nullptr;

    string frase;

    cout << "Insira uma frase: ";
    getline(cin, frase);

    for(char c : frase)
    {
        Topo = F.Inserir(Topo, c);
    }

    cout << "Frase invertida (como pilha): ";
    F.Listar(Topo);
    Topo = F.Esvaziar(Topo);

    return 0;
}