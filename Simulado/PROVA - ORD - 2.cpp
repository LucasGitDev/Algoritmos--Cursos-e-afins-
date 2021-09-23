#include <iostream>
#include <cmath>

using namespace std;


//Função quicksort indicada no enunciado
void quickSort(int vetor[], int tamanho, int i, int j)
{
    int trab, esq, dir, pivo;
    esq = i;
    dir = j;
    pivo = vetor[(int)round((esq + dir) / 2.0)];
    do
    {
        while (vetor[esq] < pivo)
            esq++;
        while (vetor[dir] > pivo)
            dir--;
        if (esq <= dir)
        {
            trab = vetor[esq];
            vetor[esq] = vetor[dir];
            vetor[dir] = trab;
            esq++;
            dir--;
        }
    } while (esq <= dir);
    if (dir - i >= 0)
        quickSort(vetor, tamanho, i, dir);
    if (j - esq >= 0)
        quickSort(vetor, tamanho, esq, j);
}

int main()
{
    int values[100]; //Vetor com valores a serem ordenados durante processo
    int n; //Tamanho utilizado no vetor de acordo com entradas
    int aux;//Variável auxiliar que recebe entradas e é testada de acordo com regra (-1)
    int j;//Ultimo index do vetor
    int i;//Variável contadora

    //Leitura de valores até que seja informado -1
    i = 0;
    cin >> aux;
    while (aux != -1)
    {
        values[i] = aux;
        i++;
        cin >> aux;
    }
    n = i;//Set len of vector
    j = i--;
    
    //Utilização do quicksort para ordenação 
    quickSort(values, n, 0, j);


    //Amostragem das informações pós processamento
    for(i = 0; i < n; i++) {
        cout << values[i] << " ";
    }

    return 0;
}
