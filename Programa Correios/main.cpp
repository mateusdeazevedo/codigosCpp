#include <iostream>

using namespace std;

const int TAM = 100;
static int pacotesCriados = 0;

class Pacote
{
private:
    string prefixo, sufixo, quemRecebeu;
    int codigoNumerico, numAviRec;

public:
    Pacote()
    {
        prefixo = sufixo = quemRecebeu = "";
        codigoNumerico = numAviRec = 0;
    }

    Pacote(string pre, string suf, string qmRec, int cdgNum, int NAR)
    {
        this->prefixo = pre;
        this->sufixo = suf;
        this->quemRecebeu = qmRec;
        this->codigoNumerico = cdgNum;
        this->numAviRec = NAR;
    }

    string getCodigo()
    {
        return prefixo + to_string(codigoNumerico) + sufixo;
    }

    void listarPacotes()
    {
        cout << "Codigo: " << prefixo << codigoNumerico << sufixo << endl;
        if (quemRecebeu != "")
            cout << "Pessoa que recebeu: " << quemRecebeu << endl;
        if (numAviRec != 0)
            cout << "Numero de aviso de recebimento: " << endl;
        cout << "------------------------------" << endl;
    }
};

void procurarPacote(Pacote pacotes[], int total, string codigo)
{
    bool encontrou = false;
    for (int i = 0; i < total; i++)
    {
        if (codigo == pacotes[i].getCodigo())
        {
            cout << "Pacote encontrado! Mostrando as informacoes:" << endl;
            pacotes[i].listarPacotes();
            encontrou = true;
            break;
        }
    }

    if (!encontrou)
        cout << "Pacote nao encontrado." << endl;

    cout << "Pressione Enter para continuar." << endl;
    cin.ignore();
    cin.get();
}

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

        cout << "O que voce deseja fazer?" << endl
             << "1 - Cadastrar pacote" << endl
             << "2 - Listar pacotes cadastrados" << endl
             << "3 - Procurar pacote por codigo" << endl
             << "4 - Sair" << endl
             << "Opcao: ";
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
