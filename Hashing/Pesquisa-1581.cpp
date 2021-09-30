#include <iostream>

using namespace std;

//1581 URI
//Algoritmo de busca usando técnica de HASH

struct dado
{
    int k;      // chave
    int status; // 0:vazio / 1:ocupado
};

//Determina primeira posição dada a chave e tamanho do vetor
int gen_hash(int k, int m)
{
    return (k % m);
}

//Dada a chave, i (contador para quantas vezes já tentou inserção) e tamanho do vetor,
//retorna posição para a chave
int h(int k, int i, int m)
{
    return ((gen_hash(k, m) + i) % m);
}
// Função de inserção hash de acordo com exemplo
int hash_insert(dado t[], int m, int k)
{
    int i;
    int j;

    i = 0;

    do
    {
        j = h(k, i, m);
        if (t[j].status != 1)
        {
            t[j].k = k;
            t[j].status = 1;
            return j;
        }
        else
            i += 1;
    } while (i != m);

    return -1;
}
//Função de pesquisa usando HASH
int hash_search(dado t[], int m, int k)
{
    int i;
    int j;
    i = 0;

    do
    {
        j = h(k, i, m);
        if (t[j].k == k)
            return j;
        i += 1;
    } while (t[j].status != 0 && i < m);

    return -1;
}

int main()
{
    int value;          // valor a inserir
    int n;              // tamanho do vetor
    dado table[100];    // tabela de valores
    int i;              // contador
    int resultOfSearch; // Resultado da busca pelo elemento
    int elem;           //Elemento à ser pesquisado
    cin >> n;

    // iniciando tabela
    for (i = 0; i < n; i++)
    {
        table[i].k = -1;
        table[i].status = 0;
    }

    // Ler valores e inserir usando função
    cin >> value;
    while (value != 0)
    {
        hash_insert(table, n, value);
        cin >> value;
    }

    // Pesquisar elemento
    cin >> elem;

    resultOfSearch = hash_search(table, n, elem);

    // Show result of search

    if (resultOfSearch == -1)
        cout << "Chave " << elem << " nao encontrada\n";
    else
        cout << "Chave " << elem << " encontrada na posicao " << resultOfSearch << endl;

    return 0;
}
