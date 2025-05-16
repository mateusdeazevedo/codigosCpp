//G2 - Mariana Dixini, Juan Cruz e João bernardes
#include <iostream>

using namespace std;

class Pessoa{
protected:
    string nome;
    int cpf;
public:
    Pessoa(){
        nome = "";
        cpf = 0;
    }

    Pessoa(string nome, int cpf){
        this->nome = nome;
        this->cpf = cpf;
    }

    string getNome(){
        return nome;
    }

    int getCPF(){
        return cpf;
    }

    setNome(string nome){
        this->nome=nome;
    }

    setCPF(int cpf){
        this->cpf=cpf;
    }
};

class Motorista : public Pessoa{
protected:
    int numviagens;
    double nota;
public:
    Motorista(){
        numviagens = 0;
        nota = 0.0;
    }

    Motorista(int numviagens, double nota):Pessoa(nome, cpf){
        this->numviagens=numviagens;
        this->nota=nota;
    }

    double Avaliar(double nota){
        ((nota * numviagens)  / (numviagens + 1));
    }

    int getNV(){
        return numviagens;
    }

    double getNota(){
        return nota;
    }

    setNV(int numviagens){
        this->numviagens=numviagens;
    }

    setNota(double nota){
        this->nota=nota;
    }
};

class Carro : public Motorista{
private:
    string placa;
    string modelo;
    int cor;
public:
    Carro(){
        placa = "";
        modelo = "";
        cor = 0;
    }

    Carro(string placa, string modelo, int cor):Motorista(numviagens, nota){
        this->placa=placa;
        this->modelo=modelo;
        this->cor=cor;
    }
};

class Passageiro : public Pessoa{
private:
    double nota;
public:
    Passageiro(){
        nota = 0;
    }

    Passageiro(double nota):Pessoa(nome, cpf){
        this->nota=nota;
    }
};


int main()
{
    int opc;

    cout << "Ola, qual usuario deseja utilizar?" << endl << endl;
    cout << "1 - Motorista" << endl << "2 - Passageiro" << endl << "3 - Sair" << endl;
    cin >> opc;

    switch(opc){
    case 1:
        cout << "O que deseja fazer?" << endl << endl;
        cout << "1 - Cadastrar" << endl << "2 - Iniciar trabalho" << endl;
        int opc;
        cin >> opc;
        if(opc == 1){
            Motorista m1;
            string x;
            int y;
            cout << "Informe o nome: ";
            cin >> x;
            cout << "Informe o CPF: ";
            cin >> y;
            cout << "Motorista cadastrado!";
        } else {
            cout << "trabalho iniciado.";
        }

        break;

    case 2:
        cout << "O que deseja fazer?" << endl << endl;
        cout << "1 - Cadastrar" << endl << "2 - Solicitar viagem" << endl;
        cin >> opc;
        if (opc == 1){
            Passageiro p1;
            string x;
            int y;
            cout << "Informe o nome: ";
            cin >> x;
            cout << "Informe o CPF: ";
            cin >> y;
            cout << "Passageiro cadastrado!";
        } else {
            cout << "Solicitando viagem...";
        }
        break;

    case 3:
        cout << "ate a proxima viagem !";
        break;

    default:
        cout << "opcao invalida";
    }


    return 0;

}
