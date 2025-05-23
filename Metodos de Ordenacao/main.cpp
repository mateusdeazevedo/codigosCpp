#include <iostream>
#include <ctime>

using namespace std;

const int TAM = 30;

void gerarVetor(int vetor[])
{
    for(int i = 0; i < TAM; i++)
    {
        vetor[i] = rand() % 100 + 1;
    }
}

void exibirVetor(int vetor[])
{
    cout << "O vetor criado eh: ";
    for(int i = 0; i < TAM; i++)
    {
        cout << vetor[i] << " ";
    }
    cout << "." << endl << endl;
}

void exibirVetorOrdenado(int vetor[], int rodada, string metodo)
{
    cout << "Rodada " << rodada << ": Vetor ordenado com o metodo " << metodo << ": ";
    for(int i = 0; i < TAM; i++)
    {
        cout << vetor[i] << " ";
    }
    cout << "." << endl << endl;
}

void copiarVetor(int origem[], int destino[])
{
    for (int i = 0; i < TAM; i++)
    {
        destino[i] = origem[i];
    }
}

void bolhaMelhorado(int vetor[], int *qtdComp, int *qtdTroca)
{
    int i = 1, j, aux;
    bool troca = true;
    while((i <= TAM) && (troca))
    {
        troca = false;
        for(j = 0; j < TAM-1; j++)
        {
            (*qtdComp)++;
            if(vetor[j] > vetor[j+1])
            {
                troca = true;
                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
                (*qtdTroca)++;
            }
        }
        i++;
    }
}

void insertion(int vetor[], int *qtdComp, int *qtdTroca)
{
    int i, j, eleito;
    for(i = 1; i < TAM; i++)
    {
        eleito = vetor[i];
        j = i - 1;
        while((j >= 0) && (vetor[j] > eleito))
        {
            (*qtdComp)++;
            (*qtdTroca)++;
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j+1] = eleito;
        (*qtdTroca)++;
    }
}

void selecao(int vetor[], int *qtdComp, int *qtdTroca)
{
    int i, j, eleito, menor, pos;
    for(i = 0; i < TAM-1; i++)
    {
        eleito = vetor[i];
        menor = vetor[i + 1];
        pos = i + 1;
        for(j = i+2; j < TAM; j++)
        {
            (*qtdComp)++;
            if(vetor[j] < menor)
            {
                menor = vetor[j];
                pos = j;
            }
        }
        (*qtdComp)++;
        if(menor < eleito)
        {
            (*qtdTroca)++;
            vetor[i] = vetor[pos];
            vetor[pos] = eleito;
        }
    }
}

void exibirMedias(int mediaTroca, int mediaComp, string metodo)
{
    cout << "Media das trocas usando o metodo " << metodo << ": " << mediaTroca << endl;
    cout << "Media das comparacoes usando o metodo " << metodo << ": " << mediaComp << endl;
}

int main()
{
    srand(time(NULL));
    int vet[TAM];
    int copia[TAM];
    int qtdComp, qtdTroca;
    int mediasTrocas[3] = {0};
    int mediasComps[3] = {0};
    string metodo[] = {"bolha melhorada", "insercao", "selecao"};

    for(int i = 0; i < 10; i++)
    {

        gerarVetor(vet);
        copiarVetor(vet, copia);

        exibirVetor(vet);

        qtdComp = 0, qtdTroca = 0;
        bolhaMelhorado(copia, &qtdComp, &qtdTroca);
        mediasTrocas[0] += qtdTroca;
        mediasComps[0] += qtdComp;
        exibirVetorOrdenado(copia, i, metodo[0]);

        copiarVetor(vet, copia);
        qtdComp = 0, qtdTroca = 0;
        insertion(copia, &qtdComp, &qtdTroca);
        mediasTrocas[1] += qtdTroca;
        mediasComps[1] += qtdComp;
        exibirVetorOrdenado(copia, i, metodo[1]);

        copiarVetor(vet, copia);
        qtdComp = 0, qtdTroca = 0;
        selecao(copia, &qtdComp, &qtdTroca);
        mediasTrocas[2] += qtdTroca;
        mediasComps[2] += qtdComp;
        exibirVetorOrdenado(copia, i, metodo[2]);

        cout << "---------------------------" << endl;

    }

    for (int i = 0; i < 3; i++) {
        mediasTrocas[i] = mediasTrocas[i] / 10;
        mediasComps[i] = mediasComps[i] / 10;
    }

    for (int i = 0; i < 3; i++) {
    exibirMedias(mediasTrocas[i], mediasComps[i], metodo[i]);
    }

    return 0;
}
