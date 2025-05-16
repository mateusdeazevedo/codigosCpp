//Programa para determinar se uma palavra escolhida pelo usuário é palíndromo ou não

#include <iostream>
#include <string>

using namespace std;

bool verificadorPalindromo(string palavra, int tam){
    int j = tam - 1;
    int limit = tam / 2;
    for(int i = 0; i < limit; i++){
        if(palavra[i] != palavra[j]){
            return false;
            break;
        }
        j--;
    }
    return true;
}

int main()
{
    string palavra;

    cout << "Digite a palavra que deseja saber se e palindromo ou nao: " << endl;
    cin >> palavra;

    int tamanho = palavra.length();
    if(verificadorPalindromo(palavra, tamanho)){
        cout << "A palavra escolhida eh um palindromo!" << endl;
    } else {
        cout << "A palavra escolhida nao eh um palindromo." << endl;
    }

    return 0;
}
