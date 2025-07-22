#include "lista.h"

using namespace std;

void Menu()
{
    system("cls");
    cout << "Menu:" << endl
         << "1 - Inserir" << endl
         << "2 - Excluir" << endl
         << "3 - Listagem Geral" << endl
         << "4 - Finalizar o programa" << endl
         << "Opcao: ";
}

int main()
{
    Lista **L, O, *resp;
    L = new Lista *[2];
    resp = L[0] = L[1] = NULL;
    string URL;
    int op, acessos;

    do
    {
        Menu();
        cin >> op;

        switch (op)
        {
        case 1:
            cout << "Insira uma URL para ser adicionada: ";
            cin >> URL;

            resp = O.Procurar(L[0], URL);
            if (resp == NULL)
            {
                L = O.Inserir(L, URL, 1);
            }
            else
            {
                acessos = resp->Quantidade_de_Acessos + 1;
                L = O.Excluir(L, URL);
                L = O.Inserir(L, URL, acessos);
            }
            cout << "URL adicionada com sucesso!" << endl
                 << "Pressione Enter para continuar!";
            cin.ignore().get();
            break;
        case 2:
            cout << "Insira uma URL para ser excluida: ";
            cin >> URL;

            resp = O.Procurar(L[0], URL);
            if (resp == NULL)
            {
                cout << "URL nao encontrada!" << endl;
            }
            else
            {
                L = O.Excluir(L, URL);
                cout << "URL excluida com sucesso!" << endl;
            }
            cout << "Pressione Enter para continuar!";
            cin.ignore().get();
            break;
        case 3:
            cout << "Listando URL's cadastradas:" << endl;

            if (L[0] == NULL)
            {
                cout << "Lista vazia!" << endl;
            }
            else
            {
                O.Listar(L[0]);
            }
            cout << "Pressione Enter para continuar!";
            cin.ignore().get();
            break;
        case 4:
            L = O.Esvaziar(L);
            resp = NULL;
            delete(L);
            cout << "Finalizando..." << endl;
            break;
        default:
            cout << "Opcao invalida!" << endl
                 << "Pressione Enter para continuar.";
            cin.ignore().get();
            break;
        }
    } while (op != 4);

    return 0;
}