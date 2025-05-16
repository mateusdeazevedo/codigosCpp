#include <iostream>
#include <ctime>

using namespace std;

void Preencher(int Mat[12][12]) {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            Mat[i][j] = rand() % 9 + 1;
        }
    }
}

void Imprimir(int Mat[12][12]) {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            cout << Mat[i][j] << " ";
        }
        cout << endl;
    }
}

void SomaAcimaDiagonal(int Mat[12][12]) {
    int soma = 0;
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 12; j++) {
            if (i < j) {
                soma += Mat[i][j];
            }
        }
    }
    cout << "Soma dos valores acima da diagonal principal: " << soma << endl;
}

void MediaAbaixoDiagonal(int Mat[12][12]) {
    int soma = 0, cont = 0;
    for (int i = 1; i < 12; i++) {
        for (int j = 0; j < i; j++) {
            soma += Mat[i][j];
            cont++;
        }
    }
    double media = soma / cont;
    cout << "Media aritmetica dos valores abaixo da diagonal principal: " << media << endl;
}

int main() {

    srand(time(NULL)); 
    int Mat[12][12];

    Preencher(Mat);
    Imprimir(Mat);
    SomaAcimaDiagonal(Mat);
    MediaAbaixoDiagonal(Mat);

    return 0;
}