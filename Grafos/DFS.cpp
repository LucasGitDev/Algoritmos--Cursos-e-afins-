#include <iostream>
#include <cmath>
#include <list>

using namespace std;

struct no
{
    int v;    // destino da aresta
    int peso; // peso da aresta
};

void quickSortDesc(int vetor[], int tamanho, int i, int j)
{
    int trab, esq, dir, pivo;
    esq = i;
    dir = j;
    pivo = vetor[(int)round((esq + dir) / 2.0)];
    do
    {
        while (vetor[esq] > pivo)
            esq++;
        while (vetor[dir] < pivo)
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
    if (i < dir)
        quickSortDesc(vetor, tamanho, i, dir);
    if (j > esq)
        quickSortDesc(vetor, tamanho, esq, j);
}

void cria_aresta(list<no> adj[], int u, int v, int p, int orientado)
{
    no novo;
    novo.v = v;
    novo.peso = p;
    adj[u].push_back(novo);
    if (orientado == 0)
    {
        novo.v = u;
        adj[v].push_back(novo);
    }
}

void dfs_visit(list<no> adj[], int u, int color[], int pi[], int f[], int d[], int &time)
{
    color[u] = 1;
    time++;
    d[u] = time;

    for (list<no>::iterator p = adj[u].begin(); p != adj[u].end(); p++)
    {
        int v = p->v;
        if (color[v] == 0)
        {
            pi[v] = u;
            dfs_visit(adj, v, color, pi, f, d, time);
        }
    }

    color[u] = 2;
    time++;
    f[u] = time;
}

void ordenacao_topologica(int f[], int nVertices)
{
    int ordenado[nVertices];
    int i;
    list<int> ordem;

    // salvar os vertices de f em uma lista e ordenar
    for (i = 0; i < nVertices; i++)
    {
        ordenado[i] = f[i];
        cout << ordenado[i] << " ";
    }

    cout << endl;

    quickSortDesc(ordenado, nVertices, 0, nVertices - 1);

    // for (i = nVertices - 1; i >= 0; i--)
    // {
    //     cout << ordenado[i] << " ";
    // }
    // cout << endl;

    // salvar os indices de f de acordo com a ordem topologica
    for (i = 0; i < nVertices; i++)
    {
        for (int j = 0; j < nVertices; j++)
        {
            if (f[j] == ordenado[i])
            {
                ordem.push_back(j);
                break;
            }
        }
    }

    // mostrar a ordem topologica
    for (list<int>::iterator p = ordem.begin(); p != ordem.end(); p++)
    {
        cout << *p << " ";
    }
}

void dfs(list<no> adj[], int nVertices)
{
    int color[nVertices]; // 0 - branco, 1 - cinza, 2 - preto
    int pi[nVertices];    //pai
    int f[nVertices];     // tempo de chegada
    int d[nVertices];     // tempo de descoberta
    int time;             // tempo
    int u;

    for (u = 0; u < nVertices; u++)
    {
        color[u] = 0;
        pi[u] = -1;
    }

    time = 0;

    for (u = 0; u < nVertices; u++)
    {
        if (color[u] == 0)
        {
            dfs_visit(adj, u, color, pi, f, d, time);
        }
    }

    ordenacao_topologica(f, nVertices);
}

int main()
{

    list<no> adj[11];     // lista de adjacência
    int nVertices;        // número de vértices
    int u, v;             // origem e destino da aresta
    int i;                // contador
    list<no>::iterator q; // iterador para percorrer lista de adjacência
    int orientado;        // grafo 1:orientado 0:não-orientado

    cin >> nVertices >> orientado;

    //Lendo e inserindo aresta
    cin >> u >> v;
    while (u != -1 && v != -1)
    {
        cria_aresta(adj, u, v, 0, orientado);
        cin >> u >> v;
    }

    //Mostrando a lista de adjacência
    dfs(adj, nVertices);

    //limpar a memória
    for (i = 0; i < nVertices; i++)
    {
        adj[i].clear();
    }
    return 0;
}