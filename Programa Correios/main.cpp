#include "pacote.h"
#include "function.h"

using namespace std;

const int TAM = 100;
static int pacotesCriados = 0;

int main()
{
    Pacote pacotes[TAM];
    string prefixo, sufixo, quemRecebeu = "", codigo;
    int codigoNumerico, nAvisoRecebimento = 0, opcaoi = 0;
    char opcao;
    bool repetir = true;

    cout << "Bem vindo ao aplicativo dos correios!" << endl;

    while (repetir)
    {
        if (opcaoi != 0)
            system("cls");

        mostrarMenu();
        cin >> opcaoi;

        switch (opcaoi)
        {
        case 1:
            do
            {
                cout << "Insira o codigo do pacote: ";
                cin >> codigo;

                if (codigo.length() > 13)
                    cout << "Codigo invalido. Insira um codigo no formato AA123456789BB!" << endl;
            } while (codigo.length() > 13);

            prefixo = codigo.substr(0, 2);
            sufixo = codigo.substr(11, 2);
            codigoNumerico = stoi(codigo.substr(2, 10));

            do
            {

                cout << "Voce deseja cadastrar aviso de recebimento para o pacote cadastrado?" << endl
                     << "s - sim" << endl
                     << "n - nao" << endl
                     << "Opcao: ";
                cin >> opcao;
                if (opcao != 's' && opcao != 'n')
                    cout << "Opcao invalida." << endl;

            } while (opcao != 's' && opcao != 'n');

            if (opcao == 's')
            {
                cout << "Digite o numero do aviso de recebimento: ";
                cin >> nAvisoRecebimento;
                cout << "Digite o nome de quem recebeu o produto: ";
                cin >> quemRecebeu;
            }

            pacotes[pacotesCriados] = Pacote(prefixo, sufixo, quemRecebeu, codigoNumerico, nAvisoRecebimento);
            pacotesCriados++;
            cout << "Pacote cadastrado com sucesso! Pressione Enter para continuar!!" << endl;
            cin.ignore();
            cin.get();
            break;
        case 2:
            if (pacotesCriados == 0)
            {
                cout << "Nenhum pacote foi cadastrado ainda!" << endl;
                cout << "Pressione Enter para continuar." << endl;
                cin.ignore();
                cin.get();
            }
            else
            {
                cout << "Listando pacotes:" << endl;
                for (int i = 0; i < pacotesCriados; i++)
                {
                    pacotes[i].listarPacotes();
                }
                cout << "Pressione Enter para continuar!!" << endl;
                cin.ignore();
                cin.get();
            }
            break;
        case 3:
            if (pacotesCriados == 0)
            {
                cout << "Nenhum pacote foi cadastrado ainda!" << endl;
                cout << "Pressione Enter para continuar." << endl;
                cin.ignore();
                cin.get();
            }
            else
            {
                cout << "Insira o codigo do pacote que deseja encontrar: ";
                cin >> codigo;
                procurarPacote(pacotes, pacotesCriados, codigo);
            }
            break;
        case 4:
            cout << "Encerrando programa..." << endl;
            repetir = false;
            break;
        default:
            cout << "Opcao invalida." << endl;
            break;
        }
    }

    return 0;
}
