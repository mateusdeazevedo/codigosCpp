#include "Biblioteca.hpp"
#include <iostream>

using namespace std;

void limparTela()
{
#ifdef _WIN32
    system("cls");
#elif __linux__
    system("clear");
#endif
}

void mostrarMenu()
{
    limparTela();
    cout << "Bem vindo a biblioteca do Mateus!" << endl;
    cout << "Digite o que voce quer fazer:" << endl
         << "1. Cadastro" << endl
         << "2. Listar acervo" << endl
         << "3. Busca" << endl
         << "4. Ordenacao" << endl
         << "5. Estatisticas" << endl
         << "6. Arquivos" << endl
         << "7. Sair" << endl
         << "Opcao: ";
}

void menuCadastro()
{
    limparTela();
    cout << "Cadastro:" << endl;
    cout << "Voce deseja cadastrar:" << endl
         << "1. Livro" << endl
         << "2. Revista" << endl
         << "Opcao: ";
}

void menuBusca()
{
    limparTela();
    cout << "Busca:" << endl;
    cout << "Que tipo de busca voce deseja fazer?" << endl
         << "1. Buscar item por titulo exato" << endl
         << "2. Buscar por trecho do titulo" << endl
         << "3. Buscar por intervalo de ano" << endl
         << "Opcao: ";
}

void menuOrdenacao()
{
    limparTela();
    cout << "Ordenacao:" << endl;
    cout << "Como voce deseja ordenar o acervo?" << endl
         << "1. Ordenar acervo por titulo (A-Z)" << endl
         << "2. Ordenar acervo por ano (mais antigo -> mais recente)" << endl
         << "Opcao: ";
}

void menuEstatisticas()
{
    limparTela();
    cout << "Estatisticas:" << endl;
    cout << "O que voce quer saber sobre os itens cadastrados:" << endl
         << "1. Contar total de livros e revistas" << endl
         << "2. Calcular media dos anos de publicacao" << endl
         << "Opcao: ";
}

void menuArquivos()
{
    limparTela();
    cout << "Arquivos:" << endl;
    cout << "1. Salvar acervo em arquivo '.txt'" << endl
         << "2. Carregar acervo de um arquivo '.txt'" << endl
         << "Opcao: ";
}

int main()
{
    int opcao;
    string titulo, autor;
    int ano, numeroEdicao, anoIni, anoFim;
    Biblioteca biblioteca;

    do
    {
        do
        {
            mostrarMenu();
            cin >> opcao;
            if (opcao < 1 || opcao > 7)
            {
                cout << "Opcao invalida!" << endl;
            }
        } while (opcao < 1 || opcao > 7);

        limparTela();
        cin.ignore();

        switch (opcao)
        {
        case 1:
            int opcao2 = 0;
            do
            {
                menuCadastro();
                cin >> opcao2;
                if (opcao2 < 1 || opcao2 > 2)
                {
                    cout << "Opcao invalida!" << endl;
                }
            } while (opcao2 < 1 || opcao2 > 2);
            if (opcao2 == 1)
            {
                cout << "Insira o titulo do livro: ";
                getline(cin, titulo);
                cout << "Insira o ano de lancamento do livro: ";
                cin >> ano;
                cin.ignore();
                cout << "Insira o nome do autor do livro: ";
                getline(cin, autor);
                biblioteca.adicionarLivros(titulo, ano, autor);
            }
            else if (opcao2 == 2)
            {
                cout << "Cadastro de revistas: " << endl;
                cout << "Insira o titulo da revista: ";
                getline(cin, titulo);
                cout << "Insira o ano de lancamento da revista: ";
                cin >> ano;
                cin.ignore();
                cout << "Insira o numero da edicao da revista: ";
                cin >> numeroEdicao;
                biblioteca.adicionarRevista(titulo, ano, numeroEdicao);
            }
            break;
        case 2:
            cout << "Listando acervo:" << endl;
            biblioteca.listarTodos();
            cout << "Aperte qualquer tecla para continuar: ";
            cin.ignore();
            cin.get();
            break;
        case 3:
            int opcao2;
            do
            {
                menuBusca();
                cin >> opcao2;
                if (opcao2 < 1 || opcao2 > 3)
                {
                    cout << "Opcao invalida!" << endl;
                }
            } while (opcao2 < 1 || opcao2 > 3);
            if (opcao2 == 1)
            {
                limparTela();
                cin.ignore();
                cout << "Busca por titulo exato:" << endl;
                cout << "Insira o titulo do item que voce quer encontrar: ";
                getline(cin, titulo);
                biblioteca.buscarPorTitulo(titulo);
                cout << "Aperte qualquer tecla para continuar: ";
                cin.ignore();
                cin.get();
            }
            else if (opcao2 == 2)
            {
                limparTela();
                cin.ignore();
                cout << "Busca por trecho do titulo:" << endl;
                cout << "Insira um trecho do titulo do item que voce quer encontrar: ";
                getline(cin, titulo);
                // Chama a função de procurar por trecho do título
                cout << "Aperte qualquer tecla para continuar: ";
                cin.ignore();
                cin.get();
            }
            else
            {
                cout << "Buscar por intervalo de ano:" << endl;
                cout << "Insira o comeco e o final do intervalo de tempo, respectivamente: ";
                if (anoIni > anoFim)
                    std::swap(anoIni, anoFim);
                cin >> anoIni >> anoFim;
                biblioteca.buscaPorIntervaloTempo(anoIni, anoFim);
                cout << "Aperte qualquer tecla para continuar: ";
                cin.ignore();
                cin.get();
            }
            break;
        case 4:
            int opcao2;
            do
            {
                menuOrdenacao();
                cin >> opcao2;
                if (opcao2 < 1 || opcao2 > 2)
                {
                    cout << "Opcao invalida!" << endl;
                }
            } while (opcao2 < 1 || opcao2 > 2);
            if (opcao2 == 1)
            {
                biblioteca.ordenarTitulo();
                cout << "Acervo organizado com sucesso!" << endl;
                cout << "Aperte qualquer tecla para continuar: ";
                cin.ignore();
                cin.get();
            }
            else
            {
                biblioteca.ordenarAno();
                cout << "Acervo organizado com sucesso!" << endl;
                cout << "Aperte qualquer tecla para continuar: ";
                cin.ignore();
                cin.get();
            }
            break;
        case 5:
            int opcao2;
            do
            {
                menuEstatisticas();
                cin >> opcao2;
                if (opcao2 < 1 || opcao2 > 2)
                {
                    cout << "Opcao invalida!" << endl;
                }
            } while (opcao2 < 1 || opcao2 > 2);
            if (opcao2 == 1)
            {
                biblioteca.totalItens();
                cout << "Aperte qualquer tecla para continuar: ";
                cin.ignore();
                cin.get();
            } else {
                biblioteca.mediaAnoItens();
                cout << "Aperte qualquer tecla para continuar: ";
                cin.ignore();
                cin.get();
            }
            break;
        case 6:
            // Arquivos
            break;
        case 7:
            cout << "Encerrando programa..." << endl;
            break;
        default:
            // Impossível ter uma opção menor que 1 ou maior que 7
            break;
        }
    } while (opcao != 7);

    return 0;
}
