//G2 - Mariana Dixini, Juan Cruz e João Bernardes
#include <iostream>
#include <ctime>
#define VERMELHO 1
#define PRETO 2
#define PRATA 3
#define BRANCO 4
#define MARROM 5
#define CINZA 6
#define AZUL 7
#define POP 1
#define ROCK 2
#define PAGODE 3
#define SERTANEJO 4
#define RAP 5
#define HIPHOP 6
#define FLASHBACK 7
#define COUNTRY 8
#define PIX 1
#define CARTAO 2
#define DINHEIRO 3
#define MAX 30

using namespace std;

class Pessoa{
protected:
    string nome;
    string cpf;
public:
    Pessoa(){
        nome = "";
        cpf = "";
    }

    Pessoa(string nome, string cpf){
        this->nome = nome;
        this->cpf = cpf;
    }

    string getNome(){
        return nome;
    }

    string getCPF(){
        return cpf;
    }

    void setNome(string nome){
        this->nome=nome;
    }

    void setCPF(string cpf){
        this->cpf=cpf;
    }
};

class Passageiro : public Pessoa{
private:
    double nota;
    int prefmusica;
    string partida;
    string destino;
    int formapag;
public:
    Passageiro(){
        nota = 0.0;
        prefmusica = 0;
        partida = "";
        destino = "";
        formapag = 0;
    }

    Passageiro(string nome, string cpf, double nota, int prefmusica, string partida, string
destino, int formapag): Pessoa(nome, cpf) {
        this->nota=nota;
        this->prefmusica=prefmusica;
        this->partida=partida;
        this->destino=destino;
        this->formapag=formapag;
    }

    void SolicitarViagem(string& partida, string& destino){
        cout << "Informe seu ponto de partida: ";
        cin.ignore(1000, '\n');
        getline(cin, partida);
        cout << "informe seu destino: ";
        getline(cin, destino);
    }

    void setNota(double nota){
        this->nota=nota;
    }

    void setPM(int prefmusica){
        this->prefmusica=prefmusica;
    }

    void setPA(string partida){
        this->partida=partida;
    }

    void setDE(string destino){
        this->destino=destino;
    }

    string getPA(){
        return partida;
    }

    string getDE(){
        return destino;
    }

    double getNt(){
        return nota;
    }

    int getPM(){
        return prefmusica;
    }

    void setFP(int formapag){
        this->formapag=formapag;
    }

    void getFP(){
        if(formapag == 1)
            cout << "PIX" << endl;
        else if(formapag == 2)
            cout << "CARTAO" << endl;
        else
            cout << "DINHEIRO" << endl;
    }
};

class Motorista : public Pessoa{
protected:
    int numviagens;
    double notaant;
    double notanova;
    double notaag;
    double si;
    double pag;
    double saldo;
public:
    Motorista(){
        numviagens = 0;
        notaant = 0.0;
        notanova = 0.0;
        notaag = 0.0;
        si = 0.0;
        pag = 0.0;
        saldo = 0.0;
    }

    Motorista(string nome, string cpf, int numviagens, double notaant, double notanova,
double notaag, double si, double pag, double saldo):Pessoa(nome, cpf){
        this->numviagens=numviagens;
        this->notaant=notaant;
        this->notanova=notanova;
        this->notaag=notaag;
        this->si=si;
        this->pag=pag;
        this->saldo=saldo;
    }

    double Avaliar(){
        notaag = ((notaant * numviagens) + notanova)  / (numviagens + 1);
        numviagens++;
        cout << "A nota do motorista agora e: " << notaag << endl;
    }

    int getNV(){
        return numviagens;
    }

    double getNotaant(){
        return notaant;
    }

    void setNV(int numviagens){
        this->numviagens=numviagens;
    }

    void setNota(double notanova){
        this->notanova=notanova;
    }

    void setNotaant(double notaant){
        this->notaant=notaant;
    }

    double getNtaag(){
        return notaag;
    }

    void setSI(double si){
        this->si=si;
    }

    void setPAG(double pag){
        this->pag=pag;
    }

    void SaldoDiario(){
        saldo = si + pag;
        si = saldo;
        cout << "Seu saldo agora e R$ " << saldo << endl;
    }

};

class Carro{
private:
    string marca;
    string modelo;
    string placa;
    int cor;
public:
    Carro(){
        marca = "";
        modelo = "";
        placa = "";
        cor = 0;
    }

    Carro(string marca, string modelo, string placa, int cor){
        this->marca=marca;
        this->modelo=modelo;
        this->placa=placa;
        this->cor=cor;
    }

    void setMA(string marca){
        this->marca=marca;
    }

    void setMO(string modelo){
        this->modelo=modelo;
    }

    void setPL(string placa){
        this->placa=placa;
    }

    void setC(int cor){
        this->cor=cor;
    }

    string getMA(){
        return marca;
    }

    string getMO(){
        return modelo;
    }

    string getPL(){
        return placa;
    }
};

int main(){

    srand(time(NULL));
    char quer1 = 's', quer2 = 's', aceitar = 'n', enc = 'n';
    string n, ma, mo, p, cpf, partida, destino;
    int i = 0, j = 0, opc, cor, numviagens, prefmusica, opcm, opcp, tempo, numpass, dist,
vlrkm, total, formapag;
    double notaant, preco, notanova, notap, si;
    Motorista* vetm = new Motorista[MAX];
    Carro* vetc = new Carro[MAX];
    Passageiro* vetp = new Passageiro[MAX];

    cout << "CADASTRO DE MOTORISTA(S)" << endl << endl;
    while ((quer1 == 's') && (i < MAX)){
    cin.ignore(1000, '\n');
    cout << "Informe o nome: ";
    getline(cin, n);
    cout << "Informe o CPF: ";
    cin >> cpf;
    cout << "Defina um saldo inicial: ";
    cin >> si;
    cout << "Informe o numero total de viagens e a nota(1.0 a 5.0): ";
    cin >> numviagens >> notaant;
    cin.ignore(1000, '\n');
    cout << "Informe a marca do carro: ";
    getline(cin, ma);
    cout << "Informe o modelo do carro: ";
    getline(cin, mo);
    cout << "Informe a cor do carro: ";
    cin >> cor;
    cout << "Informe a placa do carro: ";
    cin >> p;
    vetm[i].setNome(n);
    vetm[i].setCPF(cpf);
    vetm[i].setSI(si);
    vetm[i].setNV(numviagens);
    vetm[i].setNotaant(notaant);
    vetc[i].setMA(ma);
    vetc[i].setMO(mo);
    vetc[i].setPL(p);
    vetc[i].setC(cor);
    cout << "Motorista cadastrado! Deseja cadastrar mais?(s/n)" << endl << endl;
    cin >> quer1;
    if (quer1 == 's'){
        i++;
    }
    }

    cout << "CADASTRO DE PASSAGEIRO(S)(AS)" << endl << endl;
    while ((quer2 == 's') && (i < MAX)){
    cout << "Informe o nome: ";
    cin.ignore(1000, '\n');
    getline(cin, n);
    cout << "Informe o CPF: ";
    cin >> cpf;
    cout << "Informe sua preferencia musical" << endl << "( 1 - POP | 2 - ROCK | 3 - PAGODE | 4 - SERTANEJO | 5 - RAP | 6 - HIP HOP | 7 - FLASHBACK | 8 - COUNTRY): ";
    cin >> prefmusica;
    cout << "Informe a partida: ";
    cin.ignore(1000, '\n');
    getline(cin, partida);
    cout << "Informe o destino: ";
    getline(cin, destino);
    cout << "Informe a nota(1.0 a 5.0): ";
    cin >> notap;
    vetp[j].setNome(n);
    vetp[j].setCPF(cpf);
    vetp[j].setPM(prefmusica);
    vetp[j].setPA(partida);
    vetp[j].setDE(destino);
    vetp[j].setNota(notap);
    cout << "Passageiro cadastrado! Quer cadastrar mais?" << endl << endl;
    cin >> quer2;
    if (quer2 == 's'){
        j++;
    }
    }

    cout << "Ola, qual usuario deseja utilizar?" << endl << endl;
    cout << "1 - Motorista" << endl << "2 - Passageiro" << endl << "3 - Encerrar" << endl;
    cin >> opc;

    switch(opc){
    case 1:
        cout << "O que deseja fazer?" << endl << endl;
        cout << "1 - Iniciar trabalho" << endl << "2 - Voltar" << endl;
        cin >> opcm;

        switch(opcm){

        case 1:
            {
            int randI = (i > 0) ? rand() % i : 0;
            cout << "Trabalho iniciado!" << endl;
            while (enc == 'n'){
            cout << "Aguardando passageiros..." << endl;
            while (aceitar == 'n'){
            cout << "..." << endl << "..." << endl << "..." << endl;
            int randJ = (j > 0) ? rand() % j : 0;
            numpass = rand() % 3 + 1;
            cout << "Passageiro: " << vetp[randJ].getNome() << endl;
            cout << "Nota: " << vetp[randJ].getNt() << endl;
            cout << "Preferencia musical: " << vetp[randJ].getPM() << endl;
            cout << "Numero de passageiros: " << numpass << endl;
            cout << "Viagem: de " << vetp[randJ].getPA() << " para " << vetp[randJ].getDE() <<
endl;
            tempo = rand() % 9 + 2;
            dist = rand() % 9 + 1;
            vlrkm = rand() % 4 + 2;
            vetm[randI].setPAG(vlrkm);
            total = dist * vlrkm;
            cout << "Distancia: " << dist << " km" << endl;
            cout << "Valor a receber: R$ " << total << endl;
            cout << "O passageiro esta a " << tempo << " minutos de voce" << endl;
            cout << "Aceitar a corrida?(s/n): ";
            cin >> aceitar;
            cin.ignore(1000, '\n');
            if (aceitar == 's'){
                    cout << "Viagem iniciada..." << endl;
                    cout << "..." << endl << "..." << endl << "..." << endl;
                    cout << "Viagem finalizada! Recebendo pagamento..." << endl;
                    vetm[randI].SaldoDiario();
                    cout << "Recebendo avaliacao..." << endl;
                    notanova = rand() % 5 + 1;
                    vetm[randI].Avaliar();
                    aceitar = 'n';
            }
                                cout << "Encerrar trabalho?(s/n): ";
                    cin >> enc;
            }
            }
            }

            break;

        case 2:
            return 0;
            break;

        default:
            cout << "Opcao invalida";
        }

        break;

        case 2:
            cout << "O que deseja fazer?" << endl << endl;
        cout << "1 - Solicitar viagem" << endl << "2 - Sair" << endl;
        opcp;
        cin >> opcp;


        switch(opcp){
        case 1:
            {
            int randJ = (j > 0) ? rand() % j : 0;
            int randI = (i > 0) ? rand() % i : 0;
            vetp[randJ].SolicitarViagem(partida, destino);
            vetp[randJ].setPA(partida);
            vetp[randJ].setDE(destino);
            cout << "Solicitando viagem! Aguardando motorista..." << endl << endl;
            dist = rand() % 10 + 1;
            while (aceitar == 'n'){
            cout << "Motorista: " << vetm[randI].getNome() << endl << "Carro: " <<
vetc[randI].getMA() << " " << vetc[randI].getMO() << endl;
            cout << "Placa: " << vetc[randI].getPL() << endl;
            cout << "Numero de viagens: " << vetm[randI].getNV() << endl;
            cout << "Nota: " << vetm[randI].getNotaant() << endl;
            tempo = rand() % 9 + 2;
            vlrkm = rand() % 3 + 2;
            total = dist * vlrkm;
            cout << "Viagem: de " << vetp[randJ].getPA() << " para " << vetp[randJ].getDE() <<
endl;
            cout << "Distancia: " << dist << " km" << endl;
            cout << "Preco: R$ " << total << endl;
            cout << "Tempo estimado para chegada no seu local: " << tempo << " minutos" <<
endl;
            cout << "Aceitar?(s/n)";
            cin >> aceitar;
            if (aceitar == 's'){
            cout << "..." << endl << "..." << endl << "..." << endl << "Viagem concluida! Escolha a forma de pagamento(1 - PIX | 2 - CARTAO | 3 - DINHEIRO): ";
            cin >> formapag;
            vetp[randJ].setFP(formapag);
            vetp[randJ].getFP();
            cout << "Pagamento realizado! Deixe uma avaliacao para o motorista(1.0 a 5.0): ";
            cin >> notanova;
            vetm[randI].setNota(notanova);
            vetm[randI].Avaliar();
            }
            }
            }
            break;

        case 2:
            cout << "Ate a proxima viagem!" << endl;
            return 0;
            break;

        default:
            cout << "Opcao invalida";
        }
     }

     delete[] vetc;
     delete[] vetm;
     delete[] vetp;

    return 0;

}

