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
// Função de inserção hash
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
//Função de remoção
int hash_remove(dado t[], int m, int k)
{
    int j;

    j = hash_search(t, m, k);

    if(j != -1) {
        t[j].status = 2;
        t[j].k = -1;
        return 0; //conseguiu remover
    }else
        return -1; // k não está na tabela
}

int main()
{
    int valor;          // valor inserir
    int m;              // tamanho do vetor
    dado tabela[100];   // tabela dos valores
    int i;              // cont
    int x;              // valor pra remover

    cin >> m;

    // iniciar tabela
    for (i = 0; i < m; i++)
    {
        tabela[i].k = -1;
        tabela[i].status = 0;
    }

    // Ler valores e inserir usando função
    cin >> valor;
    while (valor != 0)
    {   
        if(valor % 2 == 0)
            hash_insert(tabela, m, valor);
        cin >> valor;
    }

    //Leitura de x pra remover
    cin >> x;

    //Chama função pra remover
    hash_remove(tabela, m, x);

    //Exibir tabela
    cout << tabela[0].k;
    for(i = 1; i < m; i++) 
        cout << " " << tabela[i].k;
    cout << endl;

    return 0;
}
