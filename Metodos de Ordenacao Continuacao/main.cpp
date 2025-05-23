#include <iostream>
#include <ctime>

using namespace std;

void preencherVetor(int vetor[], int ini, int fim, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        vetor[i] = rand() % (fim - ini + 1) + ini;
    }
}

void exibirVetor(int vetor[], int tam)
{
    cout << "O vetor criado eh: ";
    for (int i = 0; i < tam; i++)
    {
        cout << vetor[i] << " ";
    }
    cout << "." << endl;
}

void exibirVetorOrdenado(int vetor[], int tam, int *qtdTroca, int *qtdComp)
{
    cout << "Vetor ordenado: ";
    for (int i = 0; i < tam; i++)
    {
        cout << vetor[i] << " ";
    }
    cout << "." << endl;

    cout << "Quantidade de trocas: " << *qtdTroca << endl;
    cout << "Quantidade de comparacoes: " << *qtdComp << endl;
}

void copiarVetor(int origem[], int destino[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        destino[i] = origem[i];
    }
}

void bolhaMelhorado(int vetor[], int *qtdComp, int *qtdTroca, int tam)
{
    int i = 1, j, aux;
    bool troca = true;
    while ((i <= tam) && (troca))
    {
        troca = false;
        for (j = 0; j < tam - 1; j++)
        {
            (*qtdComp)++;
            if (vetor[j] > vetor[j + 1])
            {
                troca = true;
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
                (*qtdTroca)++;
            }
        }
        i++;
    }
}

void insertion(int vetor[], int *qtdComp, int *qtdTroca, int tam)
{
    int i, j, eleito;
    for (i = 1; i < tam; i++)
    {
        eleito = vetor[i];
        j = i - 1;
        while ((j >= 0) && (vetor[j] > eleito))
        {
            (*qtdComp)++;
            (*qtdTroca)++;
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = eleito;
        (*qtdTroca)++;
    }
}

void selecao(int vetor[], int *qtdComp, int *qtdTroca, int tam)
{
    int i, j, eleito, menor, pos;
    for (i = 0; i < tam - 1; i++)
    {
        eleito = vetor[i];
        menor = vetor[i + 1];
        pos = i + 1;
        for (j = i + 2; j < tam; j++)
        {
            (*qtdComp)++;
            if (vetor[j] < menor)
            {
                menor = vetor[j];
                pos = j;
            }
        }
        (*qtdComp)++;
        if (menor < eleito)
        {
            (*qtdTroca)++;
            vetor[i] = vetor[pos];
            vetor[pos] = eleito;
        }
    }
}

int main()
{
    int *vet = NULL, *copia = NULL, tam, ini, fim, opcao, qtdComp, qtdTroca;
    char opcao2;
    srand(time(NULL));

    // Começo da repetição do menu
    do
    {
        cout << "Bem vindo! O que deseja fazer?" << endl
             << "1 - Gerar vetor" << endl
             << "2 - Ordenacoes" << endl
             << "3 - Finalizar" << endl;
        cin >> opcao;

        system("clear");

        switch (opcao)
        {
        case 1:
            // Opção 1
            cout << "1 - Gerar vetor" << endl;
            cout << "Informe o tamanho: ";
            cin >> tam;
            cout << "Intervalo: ";
            cin >> ini >> fim;
            vet = new int[tam];
            preencherVetor(vet, ini, fim, tam);
            exibirVetor(vet, tam);
            cout << "-------------------------" << endl;
            break;
        case 2:
            // Opção 2
            /*De acordo com a opção escolhida pelo usuário, apresentar o vetor ordenado, e as quantidades de trocas
            e comparações realizadas, e retornar ao menu principal.*/
            copia = new int[tam];
            if (vet != NULL)
            {
                cout << "Qual ordenacoes voce deseja usar?" << endl
                     << "a) Apenas Bolha Melhorado" << endl
                     << "b) Apenas Insercao" << endl
                     << "c) Apenas selecao" << endl
                     << "d) Bolha Melhorado e Insercao" << endl
                     << "e) Bolha Melhorado e Selecao" << endl
                     << "f) Insercao e Selecao" << endl
                     << "g) Todos os metodos" << endl;
                cin >> opcao2;

                switch (opcao2)
                {
                case 'a':
                    system("clear");
                    cout << "a) Apenas Bolha melhorado" << endl;
                    qtdComp = 0, qtdTroca = 0;
                    copiarVetor(vet, copia, tam);
                    bolhaMelhorado(copia, &qtdComp, &qtdTroca, tam);
                    exibirVetorOrdenado(copia, tam, &qtdTroca, &qtdComp);
                    cout << "-------------------------" << endl;
                    break;
                case 'b':
                    system("clear");
                    cout << "b) Apenas insercao" << endl;
                    qtdComp = 0, qtdTroca = 0;
                    copiarVetor(vet, copia, tam);
                    insertion(copia, &qtdComp, &qtdTroca, tam);
                    exibirVetorOrdenado(copia, tam, &qtdTroca, &qtdComp);
                    cout << "-------------------------" << endl;
                    break;
                case 'c':
                    system("clear");
                    cout << "c) Apenas selecao" << endl;
                    qtdComp = 0, qtdTroca = 0;
                    copiarVetor(vet, copia, tam);
                    selecao(copia, &qtdComp, &qtdTroca, tam);
                    exibirVetorOrdenado(copia, tam, &qtdTroca, &qtdComp);
                    cout << "-------------------------" << endl;
                    break;
                case 'd':
                    system("clear");
                    cout << "d) Bolha Melhorado e Insercao" << endl;
                    qtdComp = 0, qtdTroca = 0;
                    copiarVetor(vet, copia, tam);
                    bolhaMelhorado(copia, &qtdComp, &qtdTroca, tam);
                    cout << "Bolha melhorado:" << endl;
                    exibirVetorOrdenado(copia, tam, &qtdTroca, &qtdComp);
                    cout << endl;
                    cout << "Insercao:" << endl;
                    qtdComp = 0, qtdTroca = 0;
                    copiarVetor(vet, copia, tam);
                    insertion(copia, &qtdComp, &qtdTroca, tam);
                    exibirVetorOrdenado(copia, tam, &qtdTroca, &qtdComp);
                    cout << "-------------------------" << endl;
                    break;
                case 'e':
                    system("clear");
                    cout << "e) Bolha Melhorado e Selecao" << endl;
                    qtdComp = 0, qtdTroca = 0;
                    copiarVetor(vet, copia, tam);
                    bolhaMelhorado(copia, &qtdComp, &qtdTroca, tam);
                    cout << "Bolha melhorado:" << endl;
                    exibirVetorOrdenado(copia, tam, &qtdTroca, &qtdComp);
                    cout << endl;
                    cout << "Selecao:" << endl;
                    qtdComp = 0, qtdTroca = 0;
                    copiarVetor(vet, copia, tam);
                    selecao(copia, &qtdComp, &qtdTroca, tam);
                    exibirVetorOrdenado(copia, tam, &qtdTroca, &qtdComp);
                    cout << "-------------------------" << endl;
                    break;
                case 'f':
                    system("clear");
                    cout << "f) Insercao e Selecao" << endl;
                    cout << "Insercao:" << endl;
                    qtdComp = 0, qtdTroca = 0;
                    copiarVetor(vet, copia, tam);
                    insertion(copia, &qtdComp, &qtdTroca, tam);
                    exibirVetorOrdenado(copia, tam, &qtdTroca, &qtdComp);
                    cout << endl;
                    cout << "Selecao:" << endl;
                    qtdComp = 0, qtdTroca = 0;
                    copiarVetor(vet, copia, tam);
                    selecao(copia, &qtdComp, &qtdTroca, tam);
                    exibirVetorOrdenado(copia, tam, &qtdTroca, &qtdComp);
                    cout << "-------------------------" << endl;
                    break;
                case 'g':
                    system("clear");
                    cout << "g) Todos os metodos" << endl;
                    cout << "Bolha melhorado:" << endl;
                    qtdComp = 0, qtdTroca = 0;
                    copiarVetor(vet, copia, tam);
                    bolhaMelhorado(copia, &qtdComp, &qtdTroca, tam);
                    exibirVetorOrdenado(copia, tam, &qtdTroca, &qtdComp);
                    cout << endl;
                    cout << "Insercao:" << endl;
                    qtdComp = 0, qtdTroca = 0;
                    copiarVetor(vet, copia, tam);
                    insertion(copia, &qtdComp, &qtdTroca, tam);
                    exibirVetorOrdenado(copia, tam, &qtdTroca, &qtdComp);
                    cout << endl;
                    cout << "Selecao:" << endl;
                    qtdComp = 0, qtdTroca = 0;
                    copiarVetor(vet, copia, tam);
                    selecao(copia, &qtdComp, &qtdTroca, tam);
                    exibirVetorOrdenado(copia, tam, &qtdTroca, &qtdComp);
                    cout << "-------------------------" << endl;
                    break;
                default:
                    system("clear");
                    cout << "Opcao invalida." << endl;
                }
            }
            break;
        case 3:
            // Opção 3
            delete(vet);
            delete(copia);
            break;
        default:
            cout << "Opcao invalida." << endl;
        }

        // Fim da repetição do menu
    } while (opcao != 3);

    return 0;
}
