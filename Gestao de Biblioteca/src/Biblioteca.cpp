#include "Biblioteca.hpp"
#include <iostream>
#include <fstream>

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
void Biblioteca::adicionarLivros(const std::string& titulo, int ano, const std::string& autor)
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
void Biblioteca::adicionarRevista(const std::string& titulo, int ano, int edicao)
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
void Biblioteca::buscarPorTitulo(const std::string& titulo)
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
    std::cout << "---------------------------------------\n";
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
        somaRevistas += revistas[i].getAno();
    }

    std::cout << "Media dos anos de publicacao dos livros: " << (somaLivros / qtdLivros) << std::endl
              << "Media dos anos de publicacao das revistas: " << (somaRevistas / qtdRevistas) << std::endl
              << "Media dos anos de publicacao de todos os itens: " << ((somaLivros + somaRevistas) / (qtdLivros + qtdRevistas)) << std::endl;
    std::cout << "---------------------------------------\n";
}

void Biblioteca::buscaTrechoTitulo(const std::string& trecho)
{
    bool encontrou = false;
    for (int i = 0; i < qtdLivros; i++)
    {
        if (livros[i].getTitulo().find(trecho) != std::string::npos)
        {
            livros[i].mostrarInfo();
            encontrou = true;
        }
    }
    for (int i = 0; i < qtdRevistas; i++)
    {
        if (revistas[i].getTitulo().find(trecho) != std::string::npos)
        {
            revistas[i].mostrarInfo();
            encontrou = true;
        }
    }
    if (!encontrou)
    {
        std::cout << "Nenhum item encontrado com o trecho informado no título.\n";
    }
}

void Biblioteca::salvarAcervo(const std::string& nomeArquivo)
{
    std::ofstream arquivo(nomeArquivo + ".txt");

    if (arquivo.is_open())
    {
        arquivo << "Livros:\n";
        for (int i = 0; i < qtdLivros; i++)
        {
            arquivo << "Titulo: " << livros[i].getTitulo()
                    << ", Ano: " << livros[i].getAno()
                    << ", Autor: " << livros[i].getAutor() << std::endl;
        }
        arquivo << "Revistas:\n";
        for (int i = 0; i < qtdRevistas; i++)
        {
            arquivo << "Titulo: " << revistas[i].getTitulo()
                    << ", Ano: " << revistas[i].getAno()
                    << ", Numero de edicao: " << revistas[i].getNumeroEdicao() << std::endl;
        }
        arquivo.close();
        std::cout << "Acervo salvo com sucesso!" << std::endl;
    }
    else
    {
        std::cout << "Erro ao tentar abrir arquivo!" << std::endl;
    }
}

void Biblioteca::carregarAcervo(const std::string& nomeArquivo)
{
    std::ifstream arquivo(nomeArquivo + ".txt");
    if (!arquivo.is_open()) {
        std::cout << "Erro ao abrir o arquivo para leitura!" << std::endl;
        return;
    }

    qtdLivros = 0;
    qtdRevistas = 0;
    std::string linha;
    bool lendoLivros = false, lendoRevistas = false;

    while (std::getline(arquivo, linha)) {
        if (linha == "Livros:") {
            lendoLivros = true;
            lendoRevistas = false;
            continue;
        }
        if (linha == "Revistas:") {
            lendoLivros = false;
            lendoRevistas = true;
            continue;
        }
        if (linha.empty()) continue;

        if (lendoLivros && qtdLivros < 100) {
            // Exemplo: Titulo: X, Ano: Y, Autor: Z
            size_t t1 = linha.find("Titulo: ");
            size_t t2 = linha.find(", Ano: ");
            size_t t3 = linha.find(", Autor: ");
            if (t1 != std::string::npos && t2 != std::string::npos && t3 != std::string::npos) {
                std::string titulo = linha.substr(t1 + 8, t2 - (t1 + 8));
                int ano = std::stoi(linha.substr(t2 + 7, t3 - (t2 + 7)));
                std::string autor = linha.substr(t3 + 9);
                livros[qtdLivros] = Livro(titulo, ano, autor);
                qtdLivros++;
            }
        } else if (lendoRevistas && qtdRevistas < 100) {
            // Exemplo: Titulo: X, Ano: Y, Numero de edicao: Z
            size_t t1 = linha.find("Titulo: ");
            size_t t2 = linha.find(", Ano: ");
            size_t t3 = linha.find(", Numero de edicao: ");
            if (t1 != std::string::npos && t2 != std::string::npos && t3 != std::string::npos) {
                std::string titulo = linha.substr(t1 + 8, t2 - (t1 + 8));
                int ano = std::stoi(linha.substr(t2 + 7, t3 - (t2 + 7)));
                int edicao = std::stoi(linha.substr(t3 + 21));
                revistas[qtdRevistas] = Revista(titulo, ano, edicao);
                qtdRevistas++;
            }
        }
    }
    arquivo.close();
    std::cout << "Acervo carregado com sucesso!" << std::endl;
}
