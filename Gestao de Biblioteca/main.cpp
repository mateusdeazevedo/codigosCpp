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
    void mostrarInfor(string titulo, int ano)
    {
        cout << "Titulo: " << titulo << ". Ano: " << ano << endl;
    }
};

class Livro : public Item
{
private:
    string autor;

public:
    Livro()
    {
        titulo = "";
        ano = 0;
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
    void mostrarInfor(string titulo, int ano, string autor)
    {
        cout << "Titulo: " << titulo << ". Ano: " << ano << ". Autor: " << autor << endl;
    }
};

class Revista : public Item
{
private:
    int numeroEdicao;

public:
    Revista()
    {
        titulo = "";
        ano = 0;
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
    void mostrarInfor(string titulo, int ano, int numeroEdicao)
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
        for (int i = 0; i < qtdLivros; i++)
        {
            livros[i].mostrarInfor(livros[i].getTitulo(), livros[i].getAno(), livros[i].getAutor());
        }
        for (int i = 0; i < qtdRevistas; i++)
        {
            revistas[i].mostrarInfor(revistas[i].getTitulo(), revistas[i].getAno(), revistas[i].getNumeroEdicao());
        }
    }
    void buscarPorTitulo(string titulo)
    {
        for (int i = 0; i < MAX_ITENS; i++)
        {
            if (titulo == livros[i].getTitulo())
            {
                cout << "Livro encontrado. Exibindo informacoes:" << endl;
                livros[i].mostrarInfor(livros[i].getTitulo(), livros[i].getAno(), livros[i].getAutor());
                break;
            }
            if (titulo == revistas[i].getTitulo())
            {
                cout << "Revista encontrada. Exibindo informacoes:" << endl;
                revistas[i].mostrarInfor(revistas[i].getTitulo(), revistas[i].getAno(), revistas[i].getNumeroEdicao());
                break;
            }
        }
    }
};

int main()
{

    return 0;
}
