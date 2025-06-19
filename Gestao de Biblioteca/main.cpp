#include "Biblioteca.hpp"
#include <iostream>
#include <fstream>

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
    int opcao, opcao2;
    string titulo, autor, nomeArquivo;
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
                cin.ignore();
                cout << "Aperte qualquer tecla para continuar: ";
                cin.get();
            }
        } while (opcao < 1 || opcao > 7);

        limparTela();
        cin.ignore();

        switch (opcao)
        {
        case 1:
            opcao2 = 0;
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
                do
                {
                    cout << "Insira o titulo do livro: ";
                    cin.ignore();
                    getline(cin, titulo);
                    cout << "Insira o ano de lancamento do livro: ";
                    cin >> ano;
                    cout << "Insira o nome do autor do livro: ";
                    cin.ignore();
                    getline(cin, autor);
                    if (titulo.empty() || autor.empty() || ano <= 0)
                    {
                        cout << "Dados invalidos para o livro.\n";
                    }
                    else
                    {
                        biblioteca.adicionarLivros(titulo, ano, autor);
                    }
                } while (titulo.empty() || autor.empty() || ano <= 0);
            }
            else if (opcao2 == 2)
            {
                do
                {
                    cout << "Cadastro de revistas: " << endl;
                    cout << "Insira o titulo da revista: ";
                    cin.ignore();
                    getline(cin, titulo);
                    cout << "Insira o ano de lancamento da revista: ";
                    cin >> ano;
                    cout << "Insira o numero da edicao da revista: ";
                    cin >> numeroEdicao;
                    if (titulo.empty() || ano <= 0 || numeroEdicao <= 0)
                    {
                        cout << "Dados invalidos para a revista.\n";
                    }
                    else
                    {
                        biblioteca.adicionarRevista(titulo, ano, numeroEdicao);
                    }
                } while (titulo.empty() || ano <= 0 || numeroEdicao <= 0);
            }
            break;
        case 2:
            cout << "Listando acervo:" << endl;
            biblioteca.listarTodos();
            cin.ignore();
            cout << "Aperte qualquer tecla para continuar: ";
            cin.get();
            break;
        case 3:
            opcao2 = 0;
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
                do
                {
                    limparTela();
                    cin.ignore();
                    cout << "Busca por titulo exato:" << endl;
                    cout << "Insira o titulo do item que voce quer encontrar: ";
                    getline(cin, titulo);
                    if (titulo.empty())
                    {
                        cout << "Titulo invalido!" << endl;
                    }
                    else
                    {
                        biblioteca.buscarPorTitulo(titulo);
                    }
                    cin.ignore();
                    cout << "Aperte qualquer tecla para continuar: ";
                    cin.get();
                } while (titulo.empty());
            }
            else if (opcao2 == 2)
            {
                do
                {
                    limparTela();
                    cin.ignore();
                    cout << "Busca por trecho do titulo:" << endl;
                    cout << "Insira um trecho do titulo do item que voce quer encontrar: ";
                    getline(cin, titulo);
                    if (titulo.empty())
                    {
                        cout << "Titulo invalido!" << endl;
                    }
                    else
                    {
                        biblioteca.buscaTrechoTitulo(titulo);
                    }
                    cin.ignore();
                    cout << "Aperte qualquer tecla para continuar: ";
                    cin.get();
                } while (titulo.empty());
            }
            else
            {
                do
                {
                    cout << "Buscar por intervalo de ano:" << endl;
                    cout << "Insira o comeco e o final do intervalo de tempo, respectivamente: ";
                    cin >> anoIni >> anoFim;
                    if (anoIni <= 0 || anoFim <= 0)
                    {
                        cout << "Intervalo inválido!" << endl;
                    }
                    else
                    {
                        if (anoIni > anoFim)
                            std::swap(anoIni, anoFim);
                        biblioteca.buscaPorIntervaloTempo(anoIni, anoFim);
                        cin.ignore();
                        cout << "Aperte qualquer tecla para continuar: ";
                        cin.get();
                    }
                } while (anoIni <= 0 || anoFim <= 0);
            }
            break;
        case 4:
            opcao2 = 0;
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
                cin.ignore();
                cout << "Aperte qualquer tecla para continuar: ";
                cin.get();
            }
            else
            {
                biblioteca.ordenarAno();
                cout << "Acervo organizado com sucesso!" << endl;
                cin.ignore();
                cout << "Aperte qualquer tecla para continuar: ";
                cin.get();
            }
            break;
        case 5:
            opcao2 = 0;
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
                cin.ignore();
                cout << "Aperte qualquer tecla para continuar: ";
                cin.get();
            }
            else
            {
                biblioteca.mediaAnoItens();
                cin.ignore();
                cout << "Aperte qualquer tecla para continuar: ";
                cin.get();
            }
            break;
        case 6:
            opcao2 = 0;
            do
            {
                menuArquivos();
                cin >> opcao2;
                if (opcao2 < 1 || opcao2 > 2)
                {
                    cout << "Opcao invalida!" << endl;
                }
            } while (opcao2 < 1 || opcao2 > 2);

            if (opcao2 == 1)
            {
                cin.ignore();
                cout << "Digite o nome do arquivo em que voce deseja salvar o acervo (sem acentos): ";
                getline(cin, nomeArquivo);
                // Verifica se o nome contém acentos
                bool temAcento = false;
                for (char c : nomeArquivo)
                {
                    // Caracteres acentuados em UTF-8 começam com byte negativo
                    if (static_cast<unsigned char>(c) > 127)
                    {
                        temAcento = true;
                        break;
                    }
                }
                while (temAcento || nomeArquivo.empty())
                {
                    cout << "Nome invalido! Nao use acentos. Digite novamente: ";
                    getline(cin, nomeArquivo);
                    temAcento = false;
                    for (char c : nomeArquivo)
                    {
                        if (static_cast<unsigned char>(c) > 127)
                        {
                            temAcento = true;
                            break;
                        }
                    }
                }
                biblioteca.salvarAcervo(nomeArquivo);
                cout << "Aperte qualquer tecla para continuar: ";
                cin.get();
            }
            else
            {
                cin.ignore();
                cout << "Digite o nome do arquivo de qual voce quer carregar o acervo: ";
                getline(cin, nomeArquivo);
                // Verifica se o nome contém acentos
                bool temAcento = false;
                for (char c : nomeArquivo)
                {
                    // Caracteres acentuados em UTF-8 começam com byte negativo
                    if (static_cast<unsigned char>(c) > 127)
                    {
                        temAcento = true;
                        break;
                    }
                }
                while (temAcento || nomeArquivo.empty())
                {
                    cout << "Nome invalido! Nao use acentos. Digite novamente: ";
                    getline(cin, nomeArquivo);
                    temAcento = false;
                    for (char c : nomeArquivo)
                    {
                        if (static_cast<unsigned char>(c) > 127)
                        {
                            temAcento = true;
                            break;
                        }
                    }
                }
                biblioteca.carregarAcervo(nomeArquivo);
                cout << "Aperte qualquer tecla para continuar: ";
                cin.get();
            }
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

//400