#include <iostream>

using namespace std;

int menor(int *vetor, int N)
{
    int *p;
    int menor = *vetor; // inicializar menor com o primeiro valor
    for (p = vetor; p < vetor + N; p++) // varrer vetor
    {
        if (*p < menor) // se o valor atual for menor que o menor
        {               
            menor = *p; //atribuir o valor atual ao menor
        }
    }

    return menor;
}

int main()
{
    int *vetor = NULL; // ponteiro para um vetor
    int N;             // tamanho desejado para o vetor

    cin >> N;

    vetor = new int[N];

    // Preencher o vetor
    for (int i = 0; i < N; i++)
    {
        cin >> vetor[i];
    }

    // Mostrar o vetor
    cout << menor(vetor, N) << endl;

    return 0;
}