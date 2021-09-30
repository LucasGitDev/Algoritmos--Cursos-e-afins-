#include <iostream>

using namespace std;

struct dado
{
    int k;      // chave
    int status; // 0-vazio, 1-ocupado, 2-removido
};

//Determina primeira posição para a chave e tamanho do vetor
int gen_hash(int k, int m)
{
    return (k % m);
}

//retorna posição para a chave
int h(int k, int i, int m)
{
    return ((gen_hash(k, m) + i) % m);
}

// Função de inserção usando hash
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
//Função de remoção usando hash
int hash_remove(dado t[], int m, int k)
{
    int j;
    int wasRemoved; // Variável que confere se o valor k foi removido da tabela

    //Testar se o valor está na tabela pela primeira vez e
    //caso não esteja, já define que não foi possível remove-lo
    j = hash_search(t, m, k);
    if (j == -1)
        wasRemoved = j;
    else
        wasRemoved = 0;

    //Caso haja mais de 1 valor igual a k na tabela, irá repetir a remoção,
    //até que não haja mais nenhum;
    while (j != -1)
    {
        t[j].status = 2;
        t[j].k = -1;
        j = hash_search(t, m, k);
    }

    return wasRemoved;
}

int main()
{
    int valor;       // valor inserir
    int m;           // tamanho do vetor
    dado table[100]; // tabela dos valores
    int i;           // cont
    int R;           // valor pra remover

    cin >> m;

    // iniciar tabela
    for (i = 0; i < m; i++)
    {
        table[i].k = -1;
        table[i].status = 0;
    }

    // Ler valores e inserir usando função hash_insert
    cin >> valor;
    while (valor != 0)
    {
        hash_insert(table, m, valor);
        cin >> valor;
    }

    //Leitura de R pra remover
    cin >> R;

    //Chama função pra remover
    hash_remove(table, m, R);

    //Exibir tabela final
    cout << table[0].k;
    for (i = 1; i < m; i++)
        cout << " " << table[i].k;
    cout << endl;

    return 0;
}
