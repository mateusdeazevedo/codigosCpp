#include "binario.h"

using namespace std;

int main()
{
    Binario B, *Topo = nullptr;

    int n;

    do
    {
        cout << "Insira um numero inteiro positivo: ";
        cin >> n;
        if (n <= 0)
        {
            cout << "Por favor, insira um numero inteiro positivo.\n";
        }
    } while (n <= 0);

    while(n > 0)
    {
        Topo = B.Inserir(Topo, n % 2);
        n /= 2;
    }

    cout << "<------------------------------------------------------->" << endl;
    
    cout << "O numero inserido convertido para binario vira ";
    B.Listar(Topo);
    Topo = B.Esvaziar(Topo);

    return 0;
}