#include <iostream>
#include <ctime>

using namespace std;

string palavras[100] = {
    "mesa", "cadeira", "agua", "sol", "lua", "casa", "pasto", "noite",
    "passaro", "caminho", "computador", "livro", "janela", "prateleira",
    "cachorro", "gato", "planta", "flor", "arvore", "caneta", "chave",
    "porta", "telefone", "carro", "bicicleta", "espelho", "parede",
    "telhado", "chao", "piso", "escada", "relogio", "papel", "caderno",
    "cadeado", "sombra", "vento", "chuva", "neve", "areia", "pedra", "rio",
    "lago", "oceano", "nuvem", "estrela", "planeta", "galaxia", "universo",
    "tempo", "relampago", "trovao", "brisa", "montanha", "vale",
    "deserto", "ilha", "praia", "campo", "cidade", "vila", "bairro",
    "estrada", "avenida", "travessa", "rua", "ponte", "tunel", "metro",
    "trem", "aviao", "barco", "navio", "onibus", "caminhao", "moto",
    "helicoptero", "vidro", "cortina", "tapete", "sofa",
    "poltrona", "colchao", "cama", "almofada", "travesseiro", "cobertor",
    "abajur", "luminaria", "fogao", "geladeira", "liquidificador", "microondas",
    "forno", "batedeira", "panela", "frigideira", "colher", "garfo", "faca"
};

string sortearPalavra(){
    int numero = rand() % 100;
    return palavras[numero];
}

void criarTabuleiro(int tamanho, char tabuleiro[]){
    for(int i = 0; i < tamanho; i++){
        tabuleiro[i] = '_';
    }
}

void mostrarTabuleiro(int tamanho, char tabuleiro[], int tentativaErrada, char letrasInformadas[]){
    cout << "Palavra gerada: ";
    for(int i = 0; i < tamanho; i++){
        cout << tabuleiro[i] << " ";
    }
    cout << endl << "Letras informadas: ";
    for(int i = 0; i < 30; i++){
        cout << letrasInformadas[i] << " ";
    }
    cout << endl;
    cout << "Tentativas erradas: " << tentativaErrada << "/7" << endl;
    cout << "Informe a letra: ";
}

bool verificarTentativa(string palavraSorteada, char chute, char tabuleiro[]){
    bool acertou = false;
    for(int i = 0; i < palavraSorteada.length(); i++){
        if(palavraSorteada[i] == chute){
            tabuleiro[i] = chute;
            acertou = true;
        }
    }
    return acertou;
}

bool palavraCompleta(char tabuleiro[], string palavra){
    for(int i = 0; i < palavra.length(); i++){
        if(tabuleiro[i] != palavra[i]){
            return false;
        }
    }
    return true;
}

void resetarLetrasInformadas(char letrasInformadas[]){
    for(int i = 0; i < 30; i++){
        letrasInformadas[i] = ' ';
    }
}

int main(){
    srand(time(NULL));

    string palavraSorteada = sortearPalavra();
    int tamanho = palavraSorteada.length();
    char tabuleiro[tamanho];
    char chute;
    int tentativaErrada;
    char letrasInformadas[30];
    int rodada;
    char opcao = 's';

    cout << "Seja bem-vindo ao jogo da forca!\n" << endl;

    do{
    palavraSorteada = sortearPalavra();
    criarTabuleiro(tamanho, tabuleiro);
    tentativaErrada = 0;
    rodada = 0;
    resetarLetrasInformadas(letrasInformadas);
    do{
        system("clear");
        mostrarTabuleiro(tamanho, tabuleiro, tentativaErrada, letrasInformadas);
        cin >> chute;
        letrasInformadas[rodada] = chute;


        if (!verificarTentativa(palavraSorteada, chute, tabuleiro)) {
            tentativaErrada++;
        }
    rodada++;
    } while(tentativaErrada < 7 && !palavraCompleta(tabuleiro, palavraSorteada));

    system("clear");
    if (palavraCompleta(tabuleiro, palavraSorteada)) {
        cout << "Parabéns! Você acertou a palavra: " << palavraSorteada << endl;
        cout << "Deseja jogar novamente? s/n: ";
        cin >> opcao;
    } else {
        cout << "Você perdeu! A palavra era: " << palavraSorteada << endl;
        cout << "Deseja jogar novamente? s/n: ";
        cin >> opcao;
    }
    }while(opcao == 's');

    return 0;
}
