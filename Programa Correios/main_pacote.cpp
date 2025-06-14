#include "pacote.h"

Pacote::Pacote()
{
    prefixo = sufixo = quemRecebeu = "";
    codigoNumerico = numAviRec = 0;
}

Pacote::Pacote(std::string pre, std::string suf, std::string qmRec, int cdgNum, int NAR)
{
    this->prefixo = pre;
    this->sufixo = suf;
    this->quemRecebeu = qmRec;
    this->codigoNumerico = cdgNum;
    this->numAviRec = NAR;
}

std::string Pacote::getCodigo()
{
    return prefixo + std::to_string(codigoNumerico) + sufixo;
}

void Pacote::listarPacotes()
{
    std::cout << "Codigo: " << prefixo << codigoNumerico << sufixo << std::endl;
    if (quemRecebeu != "")
        std::cout << "Pessoa que recebeu: " << quemRecebeu << std::endl;
    if (numAviRec != 0)
        std::cout << "Numero de aviso de recebimento: " << numAviRec << std::endl;
    std::cout << "------------------------------" << std::endl;
}
