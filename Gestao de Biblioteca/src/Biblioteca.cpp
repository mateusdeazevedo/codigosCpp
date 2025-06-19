#include "Biblioteca.hpp"
#include <iostream>

Biblioteca::Biblioteca()
{
    qtdLivros = 0;
    qtdRevistas = 0;
}
Biblioteca::Biblioteca(int qtdLivros, int qtdRevistas)
{
    this->qtdLivros = qtdLivros;
    this->qtdRevistas = qtdRevistas;
}
void Biblioteca::adicionarLivros(std::string titulo, int ano, std::string autor)
{
    if (qtdLivros < 100)
    {
        livros[qtdLivros] = Livro(titulo, ano, autor);
        qtdLivros++;
    }
    else
    {
        std::cout << "Nao eh possivel adicionar mais livros, biblioteca lotada!\n";
    }
}
void Biblioteca::adicionarRevista(std::string titulo, int ano, int edicao)
{
    if (qtdRevistas < 100)
    {
        revistas[qtdRevistas] = Revista(titulo, ano, edicao);
        qtdRevistas++;
    }
    else
    {
        std::cout << "Nao eh possivel adicionar mais revistas, biblioteca lotada!\n";
    }
}
void Biblioteca::listarTodos()
{
    if (qtdLivros == 0 && qtdRevistas == 0)
    {
        std::cout << "Acervo vazio.\n";
    }
    for (int i = 0; i < qtdLivros; i++)
    {
        livros[i].mostrarInfo();
    }
    for (int i = 0; i < qtdRevistas; i++)
    {
        revistas[i].mostrarInfo();
    }
}
void Biblioteca::buscarPorTitulo(std::string titulo)
{
    bool encontrou = false;
    for (int i = 0; i < qtdLivros; i++)
    {
        if (titulo == livros[i].getTitulo())
        {
            std::cout << "Livro encontrado! Exibindo informacoes:\n";
            livros[i].mostrarInfo();
            encontrou = true;
            break;
        }
    }
    for (int i = 0; i < qtdRevistas; i++)
    {
        if (titulo == revistas[i].getTitulo())
        {
            std::cout << "Revista encontrada! Exibindo informacoes:\n";
            revistas[i].mostrarInfo();
            encontrou = true;
            break;
        }
    }
    if (!encontrou)
    {
        std::cout << "Item nao encontrado no acervo.\n";
    }
}
void Biblioteca::buscaPorIntervaloTempo(int anoIni, int anoFim)
{
    bool encontrou = false;
    std::cout << "Livros:" << std::endl;
    for (int i = 0; i < qtdLivros; i++)
    {
        if (livros[i].getAno() >= anoIni && livros[i].getAno() <= anoFim)
        {
            livros[i].mostrarInfo();
            encontrou = true;
        }
    }
    if (!encontrou)
    {
        std::cout << "Não foram encontrados livros com o ano de publicacao dentro do intervalo inserido." << std::endl;
    }
    std::cout << "------------------------------\n";
    std::cout << "Revistas:" << std::endl;
    encontrou = false;
    for (int i = 0; i < qtdRevistas; i++)
    {
        if (revistas[i].getAno() >= anoIni && revistas[i].getAno() <= anoFim)
        {
            revistas[i].mostrarInfo();
            encontrou = true;
        }
    }
    if (!encontrou)
    {
        std::cout << "Não foram encontradas revistas com o ano de publicacao dentro do intervalo inserido." << std::endl;
    }
}

void Biblioteca::ordenarAno()
{
    // Ordena livros por ano de lançamento (Selection Sort)
    int i, j, eleito, menor, pos;
    for (i = 0; i < qtdLivros - 1; i++)
    {
        eleito = livros[i].getAno();
        menor = livros[i + 1].getAno();
        pos = i + 1;
        for (j = i + 2; j < qtdLivros; j++)
        {
            if (livros[j].getAno() < menor)
            {
                menor = livros[j].getAno();
                pos = j;
            }
        }
        if (menor < eleito)
        {
            Livro temp = livros[i];
            livros[i] = livros[pos];
            livros[pos] = temp;
        }
    }

    // Ordena revistas por ano de lançamento (Selection Sort)
    for (i = 0; i < qtdRevistas - 1; i++)
    {
        eleito = revistas[i].getAno();
        menor = revistas[i + 1].getAno();
        pos = i + 1;
        for (j = i + 2; j < qtdRevistas; j++)
        {
            if (revistas[j].getAno() < menor)
            {
                menor = revistas[j].getAno();
                pos = j;
            }
        }
        if (menor < eleito)
        {
            Revista temp = revistas[i];
            revistas[i] = revistas[pos];
            revistas[pos] = temp;
        }
    }
}

void Biblioteca::ordenarTitulo()
{
    // Ordena livros por título (Selection Sort)
    for (int i = 0; i < qtdLivros - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < qtdLivros; j++)
        {
            if (livros[j].getTitulo() < livros[minIdx].getTitulo())
            {
                minIdx = j;
            }
        }
        if (minIdx != i)
        {
            Livro temp = livros[i];
            livros[i] = livros[minIdx];
            livros[minIdx] = temp;
        }
    }

    // Ordena revistas por título (Selection Sort)
    for (int i = 0; i < qtdRevistas - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < qtdRevistas; j++)
        {
            if (revistas[j].getTitulo() < revistas[minIdx].getTitulo())
            {
                minIdx = j;
            }
        }
        if (minIdx != i)
        {
            Revista temp = revistas[i];
            revistas[i] = revistas[minIdx];
            revistas[minIdx] = temp;
        }
    }
}

void Biblioteca::totalItens()
{
    std::cout << "Total de livros cadastrados: " << qtdLivros << std::endl
              << "Total de revistas cadastradas: " << qtdRevistas << std::endl
              << "Quantidade total de itens: " << (qtdLivros + qtdRevistas) << std::endl;
}

void Biblioteca::mediaAnoItens()
{
    int somaLivros = 0, somaRevistas = 0;
    for (int i = 0; i < qtdLivros; i++)
    {
        somaLivros += livros[i].getAno();
    }
    for (int i = 0; i < qtdRevistas; i++)
    {
        somaLivros += revistas[i].getAno();
    }

    std::cout << "Media dos anos de publicacao dos livros: " << (somaLivros / qtdLivros) << std::endl
              << "Media dos anos de publicacao das revistas: " << (somaRevistas / qtdRevistas) << std::endl
              << "Media dos anos de publicacao de todos os itens: " << ((somaLivros + somaRevistas) / (qtdLivros + qtdRevistas)) << std::endl;
}