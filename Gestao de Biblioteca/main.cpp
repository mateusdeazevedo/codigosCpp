#include <iostream>

using namespace std;

const int MAX_ITENS = 100;

class Item
{
protected:
    string titulo;
    int ano;

public:
    Item()
    {
        titulo = "";
        ano = 0;
    }
    Item(string titulo, int ano)
    {
        this->titulo = titulo;
        this->ano = ano;
    }
    void setTitulo(string titulo)
    {
        this->titulo = titulo;
    }
    string getTitulo()
    {
        return titulo;
    }
    void setAno(int ano)
    {
        this->ano = ano;
    }
    int getAno()
    {
        return ano;
    }
    void mostrarInfo()
    {
        cout << "Titulo: " << titulo << ". Ano: " << ano << endl;
    }
};

class Livro : public Item
{
private:
    string autor;

public:
    Livro() : Item()
    {
        autor = "";
    }
    Livro(string titulo, int ano, string autor)
    {
        this->titulo = titulo;
        this->ano = ano;
        this->autor = autor;
    }
    void setAutor(string autor)
    {
        this->autor = autor;
    }
    string getAutor()
    {
        return autor;
    }
    void mostrarInfo()
    {
        cout << "Titulo: " << titulo << ". Ano: " << ano << ". Autor: " << autor << endl;
    }
};

class Revista : public Item
{
private:
    int numeroEdicao;

public:
    Revista() : Item()
    {
        numeroEdicao = 0;
    }
    Revista(string titulo, int ano, int numeroEdicao)
    {
        this->titulo = titulo;
        this->ano = ano;
        this->numeroEdicao = numeroEdicao;
    }
    void setNumeroEdicao(int numeroEdicao)
    {
        this->numeroEdicao = numeroEdicao;
    }
    int getNumeroEdicao()
    {
        return numeroEdicao;
    }
    void mostrarInfo()
    {
        cout << "Titulo: " << titulo << ". Ano: " << ano << ". Numero da Edicao: " << numeroEdicao << endl;
    }
};

class Biblioteca
{
private:
    Livro livros[MAX_ITENS];
    int qtdLivros;

    Revista revistas[MAX_ITENS];
    int qtdRevistas;

public:
    Biblioteca()
    {
        qtdLivros = 0;
        qtdRevistas = 0;
    }
    Biblioteca(int qtdLivros, int qtdRevistas)
    {
        this->qtdLivros = qtdLivros;
        this->qtdRevistas = qtdRevistas;
    }
    void adicionarLivros(string titulo, int ano, string autor)
    {
        if (qtdLivros < 100)
        {
            livros[qtdLivros] = Livro(titulo, ano, autor);
            qtdLivros++;
        }
        else
        {
            cout << "Nao eh possivel adicionar mais livros, biblioteca lotada!" << endl;
        }
    }
    void adicionarRevista(string titulo, int ano, int edicao)
    {
        if (qtdRevistas < 100)
        {
            revistas[qtdRevistas] = Revista(titulo, ano, edicao);
            qtdRevistas++;
        }
        else
        {
            cout << "Nao eh possivel adicionar mais revistas, biblioteca lotada!" << endl;
        }
    }
    void listarTodos()
    {
        if (qtdLivros == 0 && qtdRevistas == 0)
        {
            cout << "Acervo vazio." << endl;
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
    void buscarPorTitulo(string titulo)
    {
        bool encontrou = false;
        for (int i = 0; i < qtdLivros; i++)
        {
            if (titulo == livros[i].getTitulo())
            {
                cout << "Livro encontrado! Exibindo informacoes:" << endl;
                livros[i].mostrarInfo();
                encontrou = true;
                break;
            }
        }
        for (int i = 0; i < qtdRevistas; i++)
        {
            if (titulo == revistas[i].getTitulo())
            {
                cout << "Revista encontrada! Exibindo informacoes:" << endl;
                revistas[i].mostrarInfo();
                encontrou = true;
                break;
            }
        }
        if(!encontrou)
        {
        cout << "Item nao encontrado no acervo." << endl;
        }
    }
};

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
            system("cls");
            cout << "Bem vindo a biblioteca do Mateus!" << endl;
            cout << "Digite o que voce quer fazer:" << endl
                 << "1. Adicionar livro" << endl
                 << "2. Adicionar revista" << endl
                 << "3. Listar acervo" << endl
                 << "4. Buscar por titulo" << endl
                 << "5. Sair" << endl
                 << "Opcao: ";
            cin >> opcao;
            if (opcao < 1 || opcao > 5)
            {
                cout << "Opcao invalida!" << endl;
            }
        } while (opcao < 1 || opcao > 5);

        system("cls");
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
