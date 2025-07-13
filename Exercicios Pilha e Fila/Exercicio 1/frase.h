#include <iostream>

class Frase {
public:
    char Letra;
    Frase *elo;
    Frase* Inserir(Frase *, char);
    Frase* Esvaziar(Frase *);
    void Listar(Frase *);
};
