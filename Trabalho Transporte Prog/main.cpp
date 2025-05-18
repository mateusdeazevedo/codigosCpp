// G1 - Mateus de Azevedo, Samara da Silva e João Vitor
#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

const int corPreto = 1;
const int corBranco = 2;
const int corPrata = 3;
const int corCinza = 4;
const int corVermelho = 5;
const int corAzul = 6;
const int corVerde = 7;
const int corAmarelo = 8;
const int corMarrom = 9;
const int corRosa = 10;

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

    string getNome(){ return nome; }
    string getCPF(){ return cpf; }
    void setNome(string nome){ this->nome = nome; }
    void setCPF(string cpf){ this->cpf = cpf; }
};

class Passageiro : public Pessoa{
private:
    double nota;
    int estiloPilotagem;
    string destino;
    int avaliacaoMotorista;
public:
    Passageiro(){
    nota = 0;
    estiloPilotagem = 0;
    destino = "";
    avaliacaoMotorista = 0;
    }

    Passageiro(string nome, string cpf) : Pessoa(nome, cpf) {
    this->nota = nota;
    this->cpf = cpf;
    }

    void escolherEstiloPilotagem() {
    int escolha;
    do {
    cout << "Escolha o estilo de pilotagem desejado:" << endl;
    cout << "1 - Tranquilo" << endl;
    cout << "2 - Normal" << endl;
    cout << "3 - Agressivo" << endl;
    cout << "Digite o numero da opcao: ";
    cin >> escolha;

    if (escolha >= 1 && escolha <= 3) {
        estiloPilotagem = escolha;
    } else {
        cout << "Op��o invalida. Tente novamente." << endl;
    }
    } while (escolha < 1 || escolha > 3);
    }

    void imprimirInformacoes() {
    cout << "=== Informacoes cadastradas do Passageiro ===" << endl;
    cout << "Nome: " << nome << endl;
    cout << "CPF: " << cpf << endl;
    cout << "Estilo de pilotagem preferido: ";
    switch (estiloPilotagem) {
    case 1: cout << "Tranquilo"; break;
    case 2: cout << "Normal"; break;
    case 3: cout << "Agressivo"; break;
    default: cout << "Desconhecido"; break;
    }
    cout << endl;
    }

    void iniciarCorrida(){
    cout << "Informe seu destino: ";
    cin.ignore();
    getline(cin, this->destino);
    }

    double getNota(){ return nota; }
    int getEstilo(){ return estiloPilotagem; }
    string getDest(){ return destino; }

    void setNota(double nota) { this->nota = nota; }
    void setEstilo(int estiloPilotagem) { this->estiloPilotagem = estiloPilotagem; }
    void setDest(string destino) { this->destino = destino; }

};

class Motorista : public Pessoa {
private:
    int viagens;
    double notaMedia;
    int estiloPilotagem;

public:
    Motorista(){
    viagens = 0;
    notaMedia = 0.0;
    estiloPilotagem = 0;
    }

    Motorista(string nome, string cpf, int viagens, double notaMedia, int estiloPilotagem) : Pessoa(nome, cpf) {
    this->viagens = viagens;
    this->notaMedia = notaMedia;
    this->estiloPilotagem = estiloPilotagem;
    }

    void escolherEstiloPilotagem() {
    int opcao;
    cout << "\nEscolha seu estilo de pilotagem:\n";
    cout << "1 - Tranquilo\n2 - Normal\n3 - Agressivo\nOpcao: ";
    cin >> opcao;
    while (opcao < 1 || opcao > 3) {
    cout << "Opcao invalida. Digite novamente: ";
    cin >> opcao;
    }
    estiloPilotagem = opcao;
    }

    void avaliar(double novaNota) {
    if (novaNota < 1.0 || novaNota > 5.0) {
    cout << "Nota invalida. Deve ser entre 1 e 5." << endl;
    return;
    }

    notaMedia = (notaMedia * viagens + novaNota) / (viagens + 1);
    viagens++;

    cout << "Nota atualizada com sucesso!" << endl;
    cout << "Nova media: " << fixed << setprecision(2) << notaMedia << " | Total de viagens: " << viagens << endl;
    }

    double getNotaMedia() { return notaMedia; }
    int getViagens() { return viagens; }
    int getEstiloPilotagem() { return estiloPilotagem; }
};

class Carro : public Motorista{
private:
    string placa;
    string marca;
    string modelo;
    int corCarro;
public:
    Carro(){
    placa = "";
    marca = "";
    modelo = "";
    corCarro = 0;
    }

    Carro(string nome, string cpf, int viagens, double notaMedia, int estilo, string placa, string marca, string modelo)
    : Motorista(nome, cpf, viagens, notaMedia, estilo) {
    this->placa = placa;
    this->marca = marca;
    this->modelo = modelo;
    this->corCarro = 0;
    }

    string getPlaca(){ return placa; }
    string getMarca(){ return marca; }
    string getModelo(){ return modelo; }
    void setPlaca(string placa){ this->placa = placa; }
    void setMarca(string marca){ this->marca = marca; }
    void setModelo(string modelo){ this->modelo = modelo; }
    void setCor(int cor){ this->corCarro = cor; }

    void escolherCor() {
    int escolha = 0;
    do {
    cout << "\nEscolha a cor do carro:" << endl;
    cout << "1 - Preto" << endl;
    cout << "2 - Branco" << endl;
    cout << "3 - Prata" << endl;
    cout << "4 - Cinza" << endl;
    cout << "5 - Vermelho" << endl;
    cout << "6 - Azul" << endl;
    cout << "7 - Verde" << endl;
    cout << "8 - Amarelo" << endl;
    cout << "9 - Marrom" << endl;
    cout << "10 - Rosa" << endl;
    cout << "Digite o numero da cor desejada: ";
    cin >> escolha;

    if (escolha < 1 || escolha > 10) {
    cout << "Op��o invalida. Escolha novamente." << endl;
    }
    } while (escolha < 1 || escolha > 10);

    corCarro = escolha;
    }

    void imprimirInformacoes() {
    cout << "\n=== Informacoes cadastradas do Carro e Motorista ===" << endl;
    cout << "Nome: " << getNome() << endl;
    cout << "CPF: " << getCPF() << endl;
    cout << "Placa: " << placa << endl;
    cout << "Marca: " << marca << endl;
    cout << "Modelo: " << modelo << endl;
    cout << "Cor: "; getCor();
    cout << "Nota Media: " << getNotaMedia() << endl;
    cout << "Viagens: " << getViagens() << endl;
    cout << "Estilo de Pilotagem: " << getEstiloPilotagem() << endl;
    }

    void getCor() {
    switch(corCarro) {
    case corPreto: cout << "Preto" << endl; break;
    case corBranco: cout << "Branco" << endl; break;
    case corPrata: cout << "Prata" << endl; break;
    case corCinza: cout << "Cinza" << endl; break;
    case corVermelho: cout << "Vermelho" << endl; break;
    case corAzul: cout << "Azul" << endl; break;
    case corVerde: cout << "Verde" << endl; break;
    case corAmarelo: cout << "Amarelo" << endl; break;
    case corMarrom: cout << "Marrom" << endl; break;
    case corRosa: cout << "Rosa" << endl; break;
    default: cout << "Cor invalida" << endl; break;
    }
    }

};

    //Uso de aloca��o din�mica
    Passageiro* passageiro;
    Carro* carro;

    void cadastrarCarrosPadrao(Carro* motoristas[], int& totalMotoristas) {
    Carro* carros[] = {
    new Carro("Carlos", "123.456.789-00", 1500, 4.0, 1, "ABC1A23", "Toyota", "Corolla"),
    new Carro("Ana", "987.654.321-00", 3000, 4.1, 2, "DEF2B34", "Honda", "Civic"),
    new Carro("Joao", "111.222.333-44", 200, 4.2, 3, "GHI3C56", "Ford", "Ka"),
    new Carro("Beatriz", "888.777.666-55", 1000, 4.3, 1, "JKL4D78", "Chevrolet", "Onix"),
    new Carro("Marcos", "222.333.444-55", 5000, 4.4, 2, "MNO5E90", "Volkswagen", "Golf"),
    new Carro("Luciana", "333.444.555-66", 4000, 4.5, 1, "PQR6F12", "Fiat", "Argo"),
    new Carro("Ricardo", "444.555.666-77", 1800, 4.6, 2, "STU7G34", "Renault", "Kwid"),
    new Carro("Patricia", "555.666.777-88", 400, 4.7, 1, "VWX8H56", "Hyundai", "HB20"),
    new Carro("Bruno", "666.777.888-99", 7000, 4.8, 3, "YZA9I78", "Peugeot", "208"),
    new Carro("Juliana", "777.888.999-00", 30000, 4.9, 2, "BCD0J90", "Kia", "Rio"),
    new Carro("Thiago", "888.999.000-11", 1500, 4.0, 1, "EFG1K11", "Nissan", "Versa"),
    new Carro("Fernanda", "999.000.111-22", 2000, 4.1, 2, "HIJ2L22", "Toyota", "Etios"),
    new Carro("Eduardo", "000.111.222-33", 3000, 4.2, 1, "KLM3M33", "Honda", "Fit"),
    new Carro("Camila", "111.222.333-44", 1000, 4.3, 3, "NOP4N44", "Chevrolet", "Celta"),
    new Carro("Felipe", "222.333.444-55", 500, 4.4, 2, "QRS5O55", "Ford", "Fiesta"),
    new Carro("Gabriela", "333.444.555-66", 900, 4.5, 2, "TUV6P66", "Volkswagen", "Fox"),
    new Carro("Henrique", "444.555.666-77", 2000, 4.6, 1, "WXY7Q77", "Fiat", "Uno"),
    new Carro("Isabela", "555.666.777-88", 8000, 4.7, 1, "ZAB8R88", "Renault", "Logan"),
    new Carro("Leonardo", "666.777.888-99", 20000, 4.8, 3, "CDE9S99", "Hyundai", "Creta"),
    new Carro("Marina", "777.888.999-00", 2000, 4.9, 2, "FGH0T00", "Nissan", "Kicks")
    };

    for (int i = 0; i < 20; i++) {
        motoristas[i] = carros[i];
    }

    totalMotoristas = 20;
    }

    void simularCorrida(Passageiro* passageiro, Carro* carrosDisponiveis[], int totalCarros) {
    system("cls");
    passageiro->iniciarCorrida();
    string destino = passageiro->getDest();
    system("cls");
    cout << "Destino escolhido: " << destino << endl;

    srand(time(NULL));
    int indiceMotorista = rand() % totalCarros;
    Carro* motoristaEscolhido = carrosDisponiveis[indiceMotorista];

    int precoCorrida = rand() % 26 + 5;
    int tempoEstimado = rand() % 51 + 10;

    cout << "\nCorrida encontrada!" << endl;
    cout << "Motorista: " << motoristaEscolhido->getNome() << endl;
    cout << "Placa do Carro: " << motoristaEscolhido->getPlaca() << endl;
    cout << "Marca do Carro: " << motoristaEscolhido->getMarca() << endl;
    cout << "Modelo do Carro: " << motoristaEscolhido->getModelo() << endl;
    cout << "Estilo de pilotagem: ";
    switch (motoristaEscolhido->getEstiloPilotagem()) {
    case 1: cout << "Tranquilo"; break;
    case 2: cout << "Normal"; break;
    case 3: cout << "Agressivo"; break;
    default: cout << "Desconhecido"; break;
    }
    cout << "\nPreco da corrida: R$" << precoCorrida << endl;
    cout << "Tempo estimado: " << tempoEstimado << " minutos" << endl;

    int opcaoAceitarCorrida;
    do {
    cout << "\nAceitar corrida?\n1 - Aceitar\n2 - Nao aceitar" << endl;
    cout << "Digite o numero da opcao desejada: ";
    cin >> opcaoAceitarCorrida;
    if (opcaoAceitarCorrida < 1 || opcaoAceitarCorrida > 2) {
    cout << "Opcao invalida. Tente novamente." << endl;
    }
    } while (opcaoAceitarCorrida < 1 || opcaoAceitarCorrida > 2);

    if (opcaoAceitarCorrida == 1) {
    system("cls");
    cout << "Corrida aceita! Iniciando..." << endl;
    cout << "Corrida finalizada! " << endl;
    cout << "Preco da corrida: R$" << precoCorrida << endl;
    int avaliacaoPassageiro;
    do{
    cout << "Deixe uma avaliacao para o motorista, entre 1 a 5: ";
    cin >> avaliacaoPassageiro;
    if(avaliacaoPassageiro < 1 || avaliacaoPassageiro > 5) cout << "Avaliacao invalida. " << endl;
    }while(avaliacaoPassageiro < 1 || avaliacaoPassageiro > 5);
    cout << "Agradecemos pela preferencia, volte sempre!" << endl;
    } else {
    cout << "Corrida nao aceita. Procurando novo motorista..." << endl;
    simularCorrida(passageiro, carrosDisponiveis, totalCarros);
    }
    }

    void cadastrarPassageirosPadrao(Passageiro* passageiros[], int& totalPassageiros) {
    Passageiro* lista[] = {
    new Passageiro("Alice", "101.102.103-00"),
    new Passageiro("Bruno", "104.105.106-11"),
    new Passageiro("Carla", "107.108.109-22"),
    new Passageiro("Daniel", "110.111.112-33"),
    new Passageiro("Elaine", "113.114.115-44"),
    new Passageiro("Fabio", "116.117.118-55"),
    new Passageiro("Giovana", "119.120.121-66"),
    new Passageiro("Heitor", "122.123.124-77"),
    new Passageiro("Iris", "125.126.127-88"),
    new Passageiro("Jorge", "128.129.130-99"),
    new Passageiro("Karen", "131.132.133-00"),
    new Passageiro("Lucas", "134.135.136-11"),
    new Passageiro("Marta", "137.138.139-22"),
    new Passageiro("Nicolas", "140.141.142-33"),
    new Passageiro("Olivia", "143.144.145-44"),
    new Passageiro("Paulo", "146.147.148-55"),
    new Passageiro("Quelia", "149.150.151-66"),
    new Passageiro("Renato", "152.153.154-77"),
    new Passageiro("Sara", "155.156.157-88"),
    new Passageiro("Tiago", "158.159.160-99")
    };

    for (int i = 0; i < 20; i++) {
    passageiros[i] = lista[i];
    }

    totalPassageiros = 20;
    }

    void simularCorridaComoMotorista(Carro* motorista, Passageiro* passageirosDisponiveis[], int totalPassageiros) {
    system("cls");

    cout << "Iniciando busca por passageiro..." << endl;

    srand(time(NULL));
    int indicePassageiro = rand() % totalPassageiros;
    Passageiro* passageiroEscolhido = passageirosDisponiveis[indicePassageiro];

    int distanciaTrajeto = rand() % 40 + 1;
    int dinheiroQuilometro = rand() % 3 + 4;

    int precoCorrida = distanciaTrajeto * dinheiroQuilometro;
    int tempoEstimado = distanciaTrajeto * 3;

    cout << "\nPassageiro encontrado!" << endl;
    cout << "Nome do passageiro: " << passageiroEscolhido->getNome() << endl;
    cout << "Distancia do percurso total: " << distanciaTrajeto << " Km" << endl;
    cout << "R$/Km: " << dinheiroQuilometro << endl;
    cout << "Preco da corrida: R$" << precoCorrida << endl;
    cout << "Tempo estimado: " << tempoEstimado << " minutos" << endl;

    int opcaoAceitarCorrida;
    do {
    cout << "\nAceitar corrida?\n1 - Aceitar\n2 - Recusar" << endl;
    cout << "Digite o numero da opcao desejada: ";
    cin >> opcaoAceitarCorrida;
    if (opcaoAceitarCorrida < 1 || opcaoAceitarCorrida > 2) {
    cout << "Opcao invalida. Tente novamente." << endl;
    }
    } while (opcaoAceitarCorrida < 1 || opcaoAceitarCorrida > 2);

    if (opcaoAceitarCorrida == 1) {
    system("cls");
    cout << "Corrida aceita! Transportando passageiro..." << endl;
    cout << "Corrida finalizada!" << endl;
    cout << "Preco da corrida: R$" << precoCorrida << endl;

    int avaliacaoMotorista;
    do {
    cout << "Deixe uma avaliacao para o passageiro, entre 1 a 5: ";
    cin >> avaliacaoMotorista;
    if (avaliacaoMotorista < 1 || avaliacaoMotorista > 5) cout << "Avaliacao invalida." << endl;
    } while (avaliacaoMotorista < 1 || avaliacaoMotorista > 5);

    cout << "Corrida concluida com sucesso!";
    int notaNova = rand() % 5 + 1;
    carro->avaliar(notaNova);
    int opcaoContinuar;

    do{
    cout << " Deseja fazer outra corrida?\n1 - Iniciar trabalho\n2 - Encerrar programa\n";
    cout << "Digite o numero da opcao desejada: " << endl;
    cin >> opcaoContinuar;
    if(opcaoContinuar == 1) simularCorridaComoMotorista(motorista, passageirosDisponiveis, totalPassageiros);
    if(opcaoContinuar < 1 || opcaoContinuar > 2) cout << "Opcao invalida." << endl;
    }while(opcaoContinuar < 1 || opcaoContinuar > 2);

    } else {
    cout << "Corrida recusada. Procurando outro passageiro..." << endl;
    simularCorridaComoMotorista(motorista, passageirosDisponiveis, totalPassageiros);
    }
    }

int main() {
    srand(time(NULL));
    string nomePassageiro, cpfPassageiro;
    string nomeMotorista, placa, marca, modelo, cpfMotorista;
    int viagens, estilo;
    double notaAnterior;
    int opcaoInicial, opcaoPassageiroPosCadastro, opcaoMotoristaPosCadastro;
    const int MAX_CARROS = 20;
    Carro* carrosDisponiveis[MAX_CARROS];
    int totalCarros = 0;
    const int MAX_PASSAGEIROS = 20;
    Passageiro* passageirosDisponiveis[MAX_PASSAGEIROS];
    int totalPassageiros = 0;

    cout << "Bem vindo ao Varginha transportes!!!" << endl;
    do{
    cout << "1 - Criar conta\n2 - Fechar programa\nDigite o numero da opcao desejada: ";
    cin >> opcaoInicial;
    if(opcaoInicial < 1 || opcaoInicial > 2) {
    cout << "Opcao invalida." << endl;
    }
    }while(opcaoInicial < 1 || opcaoInicial > 2);

    if(opcaoInicial == 1){
    int opcaoConta;
    system ("cls");

    cout << "1 - Criar conta" << endl << endl;
    do{
    cout << "Voce eh passageiro ou motorista?\n1 - Passageiro\n2 - Motorista\nDigite o numero da opcao desejada: ";
    cin >> opcaoConta;
    if(opcaoConta < 1 || opcaoConta > 2) {
    cout << "Opcao invalida." << endl;
    }
    }while(opcaoConta < 1 || opcaoConta > 2);

    if (opcaoConta == 1) {
        system("cls");
        cout << "=== Cadastro do Passageiro ===" << endl;
        cin.ignore();
        cout << "Nome: ";
        getline(cin, nomePassageiro);
        cout << "CPF (formato 000.000.000-00): ";
        getline(cin, cpfPassageiro);

        passageiro = new Passageiro(nomePassageiro, cpfPassageiro);
        passageiro->escolherEstiloPilotagem();
        system("cls");
        cout << "Passageiro cadastrado! Seguem as informacoes: \n\n";
        passageiro->imprimirInformacoes();
        do{
        cout << "\n\nO que deseja fazer agora?\n1 - Iniciar corrida\n2 - Fechar programa\nDigite o numero da opcao desejada: ";
        cin >> opcaoPassageiroPosCadastro;
        if(opcaoPassageiroPosCadastro < 1 || opcaoPassageiroPosCadastro > 2){
            cout << "Opcao invalida." << endl;
        }
        }while(opcaoPassageiroPosCadastro < 1 || opcaoPassageiroPosCadastro > 2);
        switch(opcaoPassageiroPosCadastro){
        case 1:
        cadastrarCarrosPadrao(carrosDisponiveis, totalCarros);
        simularCorrida(passageiro, carrosDisponiveis, totalCarros);
        break;
        case 2:
        cout << endl << "Encerrando programa..." << endl;
        break;
        }
    } else {
        system("cls");
        cin.ignore();
        cout << "Nome: ";
        getline(cin, nomeMotorista);
        cout << "CPF (formato 000.000.000-00): ";
        getline(cin, cpfMotorista);
        cout << "Placa: ";
        getline(cin, placa);
        cout << "Marca: ";
        getline(cin, marca);
        cout << "Modelo: ";
        getline(cin, modelo);
        cout << "Numero de viagens anteriores: ";
        cin >> viagens;
        cout << "Nota media anterior: ";
        cin >> notaAnterior;

        cout << "\nEscolha o estilo de pilotagem:\n1 - Tranquilo\n2 - Normal\n3 - Agressivo\nOpcao: ";
        cin >> estilo;

        carro = new Carro(nomeMotorista, cpfMotorista, viagens, notaAnterior, estilo, placa, marca, modelo);

        carro->escolherCor();

        system("cls");
        carro->imprimirInformacoes();
        do{
        cout << "O que deseja fazer agora?\n1 - Iniciar trabalho\n2 - Fechar programa\nDigite o numero da opcao desejada: ";
        cin >> opcaoMotoristaPosCadastro;
        if(opcaoMotoristaPosCadastro < 1 || opcaoMotoristaPosCadastro > 2) cout << "Opcao invalida." << endl;
        }while(opcaoMotoristaPosCadastro < 1 || opcaoMotoristaPosCadastro > 2);
        switch(opcaoMotoristaPosCadastro){
        case 1:
        cadastrarPassageirosPadrao(passageirosDisponiveis, totalPassageiros);
        simularCorridaComoMotorista(carrosDisponiveis[0], passageirosDisponiveis, totalPassageiros);
        break;
        case 2:
        cout << endl << "Encerrando programa..." << endl;
        break;
        }
    }
    } else {
    cout << endl << "Encerrando programa..." << endl;
    }

    if (passageiro) delete passageiro;
    if (carro) delete carro;
    for (int i = 0; i < totalCarros; i++) {
        if(carrosDisponiveis[i]) delete carrosDisponiveis[i];
    }
    for (int i = 0; i < totalPassageiros; i++) {
        if(passageirosDisponiveis[i]) delete passageirosDisponiveis[i];
    }

    return 0;
}
