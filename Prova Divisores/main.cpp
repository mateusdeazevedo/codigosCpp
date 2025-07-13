#include <iostream>
#include <ctime>

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
        aux->elo = NULL;
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
        if (aux == NULL) {
            cout << "(vazio)";
            return;
        }
        while (aux->elo != NULL)
        {
            cout << aux->divisor << " * ";
            aux = aux->elo;
        }
        cout << aux->divisor << endl;
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

int main(){

    srand(time(NULL)); // Inicializa o gerador de números aleatórios

    Fatoracao f, *Inicio = NULL, *Fim = NULL, *Topo = NULL;

    int num1, num2, d, copia1, copia2;

    num1 = rand() % 90 + 10;
    copia1 = num1;
    d = 2;

    while(num1 > 1){
        if(num1 % d == 0){
            Fim = f.InserirFila(Fim, d);
            Topo = f.InserirPilha(Topo, d);
            if(Inicio == NULL){
                Inicio = Fim;
            }
            num1 /= d;
        } else {
            d++;
        }
    }

    cout << "Primeiro numero gerado: " << copia1 << endl;
    cout << "Divisores: Ordem crescente: ";
    f.Listar(Inicio);
    cout << "Divisores: Ordem decrescente: ";
    f.Listar(Topo);

    Fim = f.Esvaziar(Fim);
    Topo = f.Esvaziar(Topo);
    Inicio = NULL;

    do{
        num2 = rand() % 90 + 10;
    }while(num2 == copia1);

    copia2 = num2;
    d = 2;
    Fim = NULL;
    Topo = NULL;
    Inicio = NULL;

    while(num2 > 1){
        if(num2 % d == 0){
            Fim = f.InserirFila(Fim, d);
            Topo = f.InserirPilha(Topo, d);
            if(Inicio == NULL){
                Inicio = Fim;
            }
            num2 /= d;
        } else {
            d++;
        }
    }

    cout << endl;

    cout << "Segundo numero gerado: " << copia2 << endl;
    cout << "Divisores: Ordem crescente: ";
    f.Listar(Inicio);
    cout << "Divisores: Ordem decrescente: ";
    f.Listar(Topo);

    Fim = f.Esvaziar(Fim);
    Topo = f.Esvaziar(Topo);
    Inicio = NULL;

    return 0;
}
