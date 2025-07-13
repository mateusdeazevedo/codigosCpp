#include <iostream>

using namespace std;

class Fatoracao
{
private:
    int divisor;
    Fatoracao *elo;

public:
    Fatoracao *InserirPilha(Fatoracao *T, int N)
    {
        Fatoracao *aux = new Fatoracao();
        aux->divisor = N;
        aux->elo = T;
        T = aux;
        return T;
    }

    Fatoracao *InserirFila(Fatoracao *F, int N)
    {
        Fatoracao *aux = new Fatoracao();
        aux->divisor = N;
        if (F != NULL)
        {
            F->elo = aux;
        }
        F = aux;
        return F;
    }

    void Listar(Fatoracao *Ponteiro)
    {
        Fatoracao *aux = Ponteiro;
        while (aux->elo != NULL)
        {
            cout << aux->divisor << " * ";
            aux = aux->elo;
        }
        cout << aux->divisor;
    }

    Fatoracao *Esvaziar(Fatoracao *Ponteiro)
    {
        Fatoracao *aux = Ponteiro;
        while (aux != NULL)
        {
            Ponteiro = Ponteiro->elo;
            delete (aux);
            aux = Ponteiro;
        }
        return Ponteiro;
    }
};

int main()
{
    Fatoracao f, *Topo = NULL, *Inicio = NULL, *Fim = NULL;
    int num, d;

    cout << "Informe um numero para fatorar: ";
    cin >> num;

    d = 2;

    while(num > 1){
        if(num % d != 0){
            d++;
        } else {
            Topo = f.InserirPilha(Topo, d);
            Fim = f.InserirFila(Fim, d);
            if(Inicio == NULL){
                Inicio = Fim;
            }
            num /= d;
        }
    }

    cout << "Fatores primos:" << endl;
    f.Listar(Inicio);
    cout << endl;
    f.Listar(Topo);
    Topo = f.Esvaziar(Topo);
    Inicio = f.Esvaziar(Inicio);
    Fim = Inicio;

    return 0;
}