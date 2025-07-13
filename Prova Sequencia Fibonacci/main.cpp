#include "sequencia.h"

using namespace std;

int main()
{
    // Criação das variáveis que serão utilizadas no programa
    Sequencia S, *Inicio = NULL, *Fim = NULL, *Topo = NULL;

    int qtd = 0, num = 0, qtdI = 0, i = 0, j = 0;

    char opcao;

    // Loop principal
    do
    {

        // Loop para garantir que o valor inserido pelo usuário estará dentro do intervalo solicitado
        do
        {
            cout << "Insira um numero maior que 3 (tres): ";
            cin >> qtd;
            if (qtd <= 3)
            {
                cout << "Numero invalido." << endl;
            }
        } while (qtd <= 3);

        // Alocação dos dois primeiros números da sequência de Fibonacci nas estruturas pilha e fila
        Fim = S.InserirFila(Fim, 0);
        if (Inicio == NULL)
        {
            Inicio = Fim;
        }
        Fim = S.InserirFila(Fim, 1);
        Topo = S.InserirPilha(Topo, 0);
        Topo = S.InserirPilha(Topo, 1);

        i = 0, j = 1, qtdI = 2;

        // Loop para inserir os números restantes da sequência até a quantidade solicitada pelo usuário
        while (qtdI < qtd)
        {
            num = i + j;
            Fim = S.InserirFila(Fim, num);
            Topo = S.InserirPilha(Topo, num);
            i = j;
            j = num;
            qtdI++;
        }

        // Mostrando as sequências
        cout << "Sequencia na fila (crescente): ";
        S.Listar(Inicio);
        cout << endl;
        cout << "Sequencia na pilha (decrescente): ";
        S.Listar(Topo);

        //Excluindo as estruturas
        Topo = S.Excluir(Topo);
        Inicio = S.Excluir(Inicio);
        Fim = Inicio;

        cout << endl;

        //Outro loop para garantir que o usuário não irá inserir uma opção inválida
        do
        {
            cout << "Deseja repetir?" << endl
                 << "s - sim" << endl
                 << "n - nao" << endl
                 << "Opcao: ";
            cin >> opcao;
            if (opcao != 's' && opcao != 'n')
            {
                cout << "Opcao invalida." << endl;
            }
        } while (opcao != 's' && opcao != 'n');
    } while (opcao != 'n');

    return 0;
}