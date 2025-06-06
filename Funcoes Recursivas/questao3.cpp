/*Desenvolver um programa em C++ que contenha uma função recursiva que calcule e devolva ao programa principal esse número natural convertido para
base binária. Para receber por parâmetro um número inteiro em base decimal, este parâmetro deverá ser do tipo int. Para retornar o valor convertido em
base binária, utilizar como tipo de retorno da função: unsigned long long int.*/

#include <iostream>

using namespace std;

unsigned long long int binario(int n){
    if(n / 2 == 0) return n % 2;
    return n % 2 + binario(n / 2) * 10;
}

int main(){

    int n;

    cout << "Digite um numero natural: ";
    cin >> n;

    cout << binario(n) << endl;

    return 0;
}
