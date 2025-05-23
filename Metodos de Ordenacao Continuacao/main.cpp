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
    cout << endl;
}

void exibirVetorOrdenado(int vetor[], int tam, int *qtdTroca, int *qtdComp)
{
    cout << "Vetor ordenado: ";
    for (int i = 0; i < tam; i++)
    {
        cout << vetor[i] << " ";
    }
    cout << endl;

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

void limparTela()
{
#ifdef _WIN32
    system("cls"); // Windows
#elif __linux__
    system("clear"); // Linux
#else
    cout << "Sistema não suportado para limpar a tela.\n";
#endif
}

int main()
{
    // Criação das variáveis que serão utilizadas no programa
    int *vet = NULL, *copia = NULL, tam, ini, fim, opcao, qtdComp, qtdTroca;
    char opcao2;
    srand(time(NULL));

    // Começo da repetição do menu
    do
    {
        cout << "Bem vindo! O que deseja fazer?" << endl
             << "1 - Gerar vetor" << endl
             << "2 - Ordenacoes" << endl
             << "3 - Finalizar" << endl
             << "Opcao: ";
        cin >> opcao;

        limparTela();

        switch (opcao)
        {
        case 1:
            // Opção 1
            cout << "1 - Gerar vetor" << endl;
            cout << "Informe o tamanho do vetor: ";
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
            if (vet != NULL)
            {
                copia = new int[tam];
                // Se o vetor foi criado
                cout << "Qual ordenacoes voce deseja usar?" << endl
                     << "a) Apenas Bolha Melhorado" << endl
                     << "b) Apenas Insercao" << endl
                     << "c) Apenas selecao" << endl
                     << "d) Bolha Melhorado e Insercao" << endl
                     << "e) Bolha Melhorado e Selecao" << endl
                     << "f) Insercao e Selecao" << endl
                     << "g) Todos os metodos" << endl
                     << "Opcao: " << endl;
                cin >> opcao2;

                switch (opcao2)
                {
                case 'a':
                    limparTela();
                    cout << "a) Apenas Bolha melhorado" << endl;
                    qtdComp = qtdTroca = 0;
                    copiarVetor(vet, copia, tam);
                    bolhaMelhorado(copia, &qtdComp, &qtdTroca, tam);
                    exibirVetorOrdenado(copia, tam, &qtdTroca, &qtdComp);
                    cout << "-------------------------" << endl;
                    break;
                case 'b':
                    limparTela();
                    cout << "b) Apenas insercao" << endl;
                    qtdComp = qtdTroca = 0;
                    copiarVetor(vet, copia, tam);
                    insertion(copia, &qtdComp, &qtdTroca, tam);
                    exibirVetorOrdenado(copia, tam, &qtdTroca, &qtdComp);
                    cout << "-------------------------" << endl;
                    break;
                case 'c':
                    limparTela();
                    cout << "c) Apenas selecao" << endl;
                    qtdComp = qtdTroca = 0;
                    copiarVetor(vet, copia, tam);
                    selecao(copia, &qtdComp, &qtdTroca, tam);
                    exibirVetorOrdenado(copia, tam, &qtdTroca, &qtdComp);
                    cout << "-------------------------" << endl;
                    break;
                case 'd':
                    limparTela();
                    cout << "d) Bolha Melhorado e Insercao" << endl;
                    cout << "Bolha melhorado:" << endl;
                    qtdComp = qtdTroca = 0;
                    copiarVetor(vet, copia, tam);
                    bolhaMelhorado(copia, &qtdComp, &qtdTroca, tam);
                    exibirVetorOrdenado(copia, tam, &qtdTroca, &qtdComp);

                    cout << endl;

                    cout << "Insercao:" << endl;
                    qtdComp = qtdTroca = 0;
                    copiarVetor(vet, copia, tam);
                    insertion(copia, &qtdComp, &qtdTroca, tam);
                    exibirVetorOrdenado(copia, tam, &qtdTroca, &qtdComp);
                    cout << "-------------------------" << endl;
                    break;
                case 'e':
                    limparTela();
                    cout << "e) Bolha Melhorado e Selecao" << endl;
                    cout << "Bolha melhorado:" << endl;
                    qtdComp = qtdTroca = 0;
                    copiarVetor(vet, copia, tam);
                    bolhaMelhorado(copia, &qtdComp, &qtdTroca, tam);
                    exibirVetorOrdenado(copia, tam, &qtdTroca, &qtdComp);

                    cout << endl;

                    cout << "Selecao:" << endl;
                    qtdComp = qtdTroca = 0;
                    copiarVetor(vet, copia, tam);
                    selecao(copia, &qtdComp, &qtdTroca, tam);
                    exibirVetorOrdenado(copia, tam, &qtdTroca, &qtdComp);
                    cout << "-------------------------" << endl;
                    break;
                case 'f':
                    limparTela();
                    cout << "f) Insercao e Selecao" << endl;
                    cout << "Insercao:" << endl;
                    qtdComp = qtdTroca = 0;
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
                    limparTela();
                    cout << "g) Todos os metodos" << endl;
                    cout << "Bolha melhorado:" << endl;
                    qtdComp = qtdTroca = 0;
                    copiarVetor(vet, copia, tam);
                    bolhaMelhorado(copia, &qtdComp, &qtdTroca, tam);
                    exibirVetorOrdenado(copia, tam, &qtdTroca, &qtdComp);

                    cout << endl;

                    cout << "Insercao:" << endl;
                    qtdComp = qtdTroca = 0;
                    copiarVetor(vet, copia, tam);
                    insertion(copia, &qtdComp, &qtdTroca, tam);
                    exibirVetorOrdenado(copia, tam, &qtdTroca, &qtdComp);

                    cout << endl;

                    cout << "Selecao:" << endl;
                    qtdComp = qtdTroca = 0;
                    copiarVetor(vet, copia, tam);
                    selecao(copia, &qtdComp, &qtdTroca, tam);
                    exibirVetorOrdenado(copia, tam, &qtdTroca, &qtdComp);
                    cout << "-------------------------" << endl;
                    break;
                default:
                    limparTela();
                    cout << "Opcao invalida." << endl;
                }
            }
            else
            {
                // Se o vetor ainda não foi criado
                cout << "Primeiro gere o vetor!" << endl;
            }
            break;
        case 3:
            // Opção 3
            cout << "Encerrando programa..." << endl;
            delete[] vet;
            delete[] copia;
            break;
        default:
            cout << "Opcao invalida." << endl;
        }

        // Fim da repetição do menu
    } while (opcao != 3);

    return 0;
}
