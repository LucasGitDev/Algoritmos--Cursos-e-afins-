#include<iostream>
using namespace std;
int main()
{
    int *vetor = NULL; // ponteiro para um vetor
    int tam; // tamanho desejado para o vetor
    int i; // contador
    // Ler o tamanho desejado para o vetor
    cin >> tam;
    // Alocar memoria para o vetor
    vetor = new int[tam];
    // Preencher o vetor
    for(i=0;i<tam;i++)
        cin >> vetor[i];
    // Mostrar o vetor
    for(i=0;i<tam;i++)
        cout << vetor[i] << " ";
    cout << endl;
    // Liberar memoria alocada pelo vetor
    delete [] vetor;
    return 0;
}