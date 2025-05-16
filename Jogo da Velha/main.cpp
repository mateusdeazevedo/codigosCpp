#include <iostream>

using namespace std;

const int L = 3;
const int C = 3;

void preencherMatriz(char jogo[][C]) {
for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++)
    jogo[i][j] = ' ';
}
}

void preencherMatrizVe(int jogove[][C]) {
for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++)
    jogove[i][j] = 10;
}
}

void imprimirJogo(char jogo[][C]){
    system("cls");
    cout << "------- ------- -------" << endl;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << "|  " << jogo[i][j] << "   |";
        }
        cout << endl << "------- ------- -------" << endl;
    }
}

int verificarJogo(int jogove[][C], string nome1, string nome2){
    int soma;
    for(int i = 0; i < 3; i++){
        soma = 0;
        for(int j = 0; j < 3; j++){
            soma += jogove[i][j];
        }
        if(soma == 3){
            cout << nome1 << " ganhou!!!" << endl;
            return 0;
        } else if(soma == 0){
                    cout << nome2 << " ganhou!!!" << endl;
                    return 0;
        }

    }
    for(int j = 0; j < 3; j++){
        soma = 0;
        for(int i = 0; i < 3; i++){
            soma += jogove[i][j];
        }
        if(soma == 3){
            cout << nome1 << " ganhou!!!" << endl;
            return 0;
        } else if(soma == 0){
                    cout << nome2 << " ganhou!!!" << endl;
                    return 0;
        }

    }
    soma = jogove[0][0] + jogove[1][1] + jogove[2][2];
    if(soma == 3){
            cout << nome1 << " ganhou!!!" << endl;
            return 0;
        } else if(soma == 0){
                    cout << nome2 << " ganhou!!!" << endl;
                    return 0;
        }
    soma = jogove[0][2] + jogove[1][1] + jogove[2][0];
    if(soma == 3){
            cout << nome1 << " ganhou!!!" << endl;
            return 0;
        } else if(soma == 0){
                    cout << nome2 << " ganhou!!!" << endl;
                    return 0;
        }
    return 1;
}

int main()
{
    char jogo[L][C], opcao1, opcao2, opcao = 0;
    int jogove[L][C], linha, coluna, turno;
    string nome1, nome2;

    cout << "Bem vindo ao jogo da velha!!!" << endl;

    cout << "Insira o nome do jogador 1: " << endl;
    cin >> nome1;

    cout << "Insira o nome do jogador 2: " << endl;
    cin >> nome2;

    do{
    do{
    cout << nome1 << ", escolha qual voce vai usar: X ou O: " << endl;
    cin >> opcao1;
    }while(opcao1 != 'X' && opcao1 != 'O');

    if(opcao1 == 'X') {
    opcao2 = 'O';
    } else {
    opcao2 = 'X';
    }

    preencherMatriz(jogo);
    imprimirJogo(jogo);
    preencherMatrizVe(jogove);
    turno = 1;

    do{
    if(turno % 2 == 1){
    do{
    cout << nome1 << ", faca sua jogada escolhendo linha e coluna (valores entre 1 a 3): " << endl;
    cin >> linha >> coluna;

    }while(linha < 1 || linha > 3 && coluna < 1 || coluna > 3 || jogo[linha - 1][coluna - 1] != ' ');
    jogo[linha - 1][coluna - 1] = opcao1;
    jogove[linha - 1][coluna - 1] = 1;
    } else {
    do{
    cout << nome2 << ", faca sua jogada escolhendo linha e coluna: " << endl;
    cin >> linha >> coluna;
    }while(linha < 1 || linha > 3 && coluna < 1 || coluna > 3 || jogo[linha - 1][coluna - 1] != ' ');
    jogo[linha - 1][coluna - 1] = opcao2;
    jogove[linha - 1][coluna - 1] = 0;
    }
    imprimirJogo(jogo);
    if (verificarJogo(jogove, nome1, nome2) == 0) {
    break;
    }
    turno++;
    }while(turno != 10);

    if(turno == 10) {
    cout << "Empate!!!" << endl;
    }

    cout << "Deseja jogar novamente? Digite 1 para sim e 2 para nao: " << endl;
    cin >> opcao;

    }while(opcao != 2);

    return 0;
}
