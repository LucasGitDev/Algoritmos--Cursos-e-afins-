#include <iostream>

using namespace std;

void insercaoDireta(int vetor[], int tamanho)
{
    int i, j; // contadores
    int chave;
    for (j = 1; j < tamanho; j++)
    {
        chave = vetor[j];
        cout << "chave = " << chave << endl;
        i = j - 1;
        while ((i >= 0) && (vetor[i] > chave))
        {
            vetor[i + 1] = vetor[i];
            i = i - 1;
        }
        vetor[i + 1] = chave;
    }
}

int main()
{
    int n = 10;
    int vet[100];

    for(int i = 0; i < n; i++) {
        cin >> vet[i];
    }

    insercaoDireta(vet, n);

    return 0;
}