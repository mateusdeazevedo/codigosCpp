/*Desenvolver um programa em C++ que contenha uma função recursiva que receba por parâmetro um número inteiro positivo N e calcula a soma dos
dígitos desse número. Por exemplo, se a entrada for 123, a saída deverá ser 6 (1+2+3).*/

#include <iostream>

using namespace std;

int soma(int N){
    int soma = 0;
    while(N / 10 != 0){
        soma += N % 10;
        N /= 10;
    }
    soma += N;
    return soma;
}

int somaR(int N){
    if(N / 10 == 0) return N % 10;
    return N % 10 + somaR(N / 10);
}

int main(){

    int N;

    cout << "Digite um numero inteiro positivo: " << endl;
    cin >> N;

    cout << "A soma dos algarismos resulta em: " << somaR(N) << endl;

    return 0;
}
