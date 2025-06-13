#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    char cores[4] {'v', 'a', 'p', 'b'}, senha[4], chute[4];
    int tentativas = 0, acertos = 0, i, jogada = 1;
    srand(time(NULL));

    for(i = 0; i < 4; i++) {
    senha[i] = cores[rand() % 4];
    }

    do{
    tentativas++;
    cout << "Informe uma senha de 4 caracteres, sendo v - vermelho | a - azul | p - preto | b - branco \nInforme sua jogada: " << tentativas << ":" << endl;
    for(i = 0; i < 4; i++) {
    cin >> chute[i];
    }

    int comp = 0;
    acertos = 0;

    for(i = 0; i < 4; i++) {
    if(senha[i] == chute[i]) {
    acertos++;
    }
    }

    cout << acertos << " acertos!!!" << endl;
    }while(tentativas < 10 && acertos < 4);
    if(acertos == 4) {
    cout << "Parabéns, você ganhou!!!" << endl;
    } else {
    cout << "Perdeukkkkkkkkkkkkkkkkkkkkkk" << endl;
    cout << "Senha gerada: ";
    for(i = 0; i < 4; i++) {
    cout << senha[i];
    }
    }

    return 0;
}
