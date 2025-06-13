#include "vendas.h"

using namespace std;

int main()
{
    Vendas V, *topo = NULL;
    int num = 0;
    int round = 0;

    do
    {
        cout << "Digite um numero para ser armazenado: ";
        cin >> num;
        if (num != 0 && num != -1)
        {
            topo = V.inserirNumeros(topo, num);
        }
        else if (num == 0)
        {
            topo = V.removerNumero(topo);
        }
        round++;
    } while (num != -1);

    if (round == 1)
    {
        cout << "Nenhum numero foi inserido." << endl;
    }
    else
    {
        cout << "Resultado das somas dos numeros: " << V.somarNumeros(topo) << endl;
    }

    return 0;
}
