/*Desenvolver um programa em C++ que contenha uma função recursiva que receba por parâmetro dois números naturais (inteiros maiores que zero) e
calcula o mdc máximo divisor comum desses números. Obs.: Utilizar o método de Euclides para calcular o MDC.*/

#include <iostream>

using namespace std;

int mdc(int n1, int n2)
{
    int r;
    while (n1 % n2 != 0)
    {
        r = n1 % n2;
        n1 = n2;
        n2 = r;
    }
    return n2;
}

int mdcR(int n1, int n2)
{
    if(n1 % n2 == 0) return n2;
    return mdcR(n2, n1%n2);
}

int main()
{

    int n1, n2, resposta;

    cout << "Insira o primeiro numero:" << endl;
    cin >> n1;
    cout << "Insira o segundo numero: " << endl;
    cin >> n2;

    resposta = mdcR(n1, n2);
    cout << "O resultado eh: " << resposta << endl;

    return 0;
}
