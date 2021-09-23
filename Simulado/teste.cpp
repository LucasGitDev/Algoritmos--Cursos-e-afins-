#include <iostream>

using namespace std;

void bubbleSort(int vetor[], int tamanho)
{
    int i,j,k; // contadores
    int trab;
    bool troca;
    int limite;
    troca = true;
    limite = tamanho-1;
    cout << "lim" << limite;
    while (troca)
    {
        troca = false;
	for (i=0;i<limite;i++)
	    if (vetor[i] > vetor[i+1])
	    {
	        trab = vetor[i];
	        vetor[i] = vetor[i+1];
	        vetor[i+1] = trab;
	        j = i;
	        troca = true;
	    }
	limite = j;	
    cout << "lim baixo" << limite;
    }
}

int binaria(int vetor[], int tamanho, int x)
{
    bool achou; // var aux p/ busca
    int baixo, meio, alto; // var aux
    baixo = 0;
    cout << baixo << " ";
    alto = tamanho - 1;
    achou = false;
    while ((baixo <= alto) && (achou == false))
    {
        meio = (baixo + alto) / 2;
	if (x < vetor[meio])
	    alto = meio - 1;
	else if (x > vetor[meio])
	{
        baixo = meio + 1;
        cout << baixo << " ";
    }
	else
	    achou = true;
    }
    if (achou)
        return meio;
    else
        return -1;
}

int main() {

    int vetor[100];
    int n = 10;

    
    for(int i =0; i < n; i++){
        cin >> vetor[i];
    }

    // bubbleSort(vetor, n);
    binaria(vetor, n, 10);

    for(int i = 0; i < n; i++) {
        cout << vetor[i];
    }


    return 0;
}