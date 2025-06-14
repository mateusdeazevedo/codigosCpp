#ifndef PACOTE_H
#define PACOTE_H

#include <iostream>

class Pacote
{
private:
    std::string prefixo, sufixo, quemRecebeu;
    int codigoNumerico, numAviRec;

public:
    Pacote();
    Pacote(std::string pre, std::string suf, std::string qmRec, int cdgNum, int NAR);
    std::string getCodigo();
    void listarPacotes();
};

#endif
