#include "Biblioteca.hpp"
#include <iostream>

using namespace std;

void limparTela(){
    #ifdef _WIN32
        system("cls");
    #elif __linux__
        system("clear");
    #endif
}

void menu()
{
    limparTela();
    cout << "Bem vindo a biblioteca do Mateus!" << endl;
    cout << "Digite o que voce quer fazer:" << endl
         << "1. Adicionar livro" << endl
         << "2. Adicionar revista" << endl
         << "3. Listar acervo" << endl
         << "4. Buscar por titulo" << endl
         << "5. Sair" << endl
         << "Opcao: ";
}

int main()
{
    int opcao;
    string titulo, autor;
    int ano, numeroEdicao;
    Biblioteca biblioteca;

    // Repetidor do menu principal
    do
    {
        // Menu principal
        do
        {
            menu();
            cin >> opcao;
            if (opcao < 1 || opcao > 5)
            {
                cout << "Opcao invalida!" << endl;
            }
        } while (opcao < 1 || opcao > 5);

        limparTela();
        cin.ignore(); // Limpa o buffer do teclado antes de usar getline

        switch (opcao)
        {
        case 1:
            cout << "Cadastro de livros:" << endl;
            cout << "Insira o titulo do livro: ";
            getline(cin, titulo);
            cout << "Insira o ano de lancamento do livro: ";
            cin >> ano;
            cin.ignore(); // Limpa o buffer antes de ler o autor
            cout << "Insira o nome do autor do livro: ";
            getline(cin, autor);
            biblioteca.adicionarLivros(titulo, ano, autor);
            break;
        case 2:
            cout << "Cadastro de revistas: " << endl;
            cout << "Insira o titulo da revista: ";
            getline(cin, titulo);
            cout << "Insira o ano de lancamento da revista: ";
            cin >> ano;
            cin.ignore();
            cout << "Insira o numero da edicao da revista: ";
            cin >> numeroEdicao;
            biblioteca.adicionarRevista(titulo, ano, numeroEdicao);
            break;
        case 3:
            cout << "Listando acervo:" << endl;
            biblioteca.listarTodos();
            cout << "Aperte qualquer tecla para continuar: ";
            cin.get();
            break;
        case 4:
            cout << "Busca por titulo:" << endl;
            cout << "Insira o titulo do livro/revista que deseja encontrar: ";
            getline(cin, titulo);
            biblioteca.buscarPorTitulo(titulo);
            cout << "Aperte qualquer tecla para continuar: ";
            cin.get();
            break;
        default:
            cout << "Saindo do programa..." << endl;
            break;
        }
    } while (opcao != 5);

    return 0;
}
