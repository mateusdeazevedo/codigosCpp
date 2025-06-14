#include "function.h"

void procurarPacote(Pacote pacotes[], int total, std::string codigo)
{
    bool encontrou = false;
    for (int i = 0; i < total; i++)
    {
        if (codigo == pacotes[i].Pacote::getCodigo())
        {
            std::cout << "Pacote encontrado! Mostrando as informacoes:" << std::endl;
            pacotes[i].Pacote::listarPacotes();
            encontrou = true;
            break;
        }
    }

    if (!encontrou)
        std::cout << "Pacote nao encontrado." << std::endl;

    std::cout << "Pressione Enter para continuar." << std::endl;
    std::cin.ignore();
    std::cin.get();
}
void mostrarMenu()
{
    std::cout << "O que voce deseja fazer?" << std::endl
              << "1 - Cadastrar pacote" << std::endl
              << "2 - Listar pacotes cadastrados" << std::endl
              << "3 - Procurar pacote por codigo" << std::endl
              << "4 - Sair" << std::endl
              << "Opcao: ";
}