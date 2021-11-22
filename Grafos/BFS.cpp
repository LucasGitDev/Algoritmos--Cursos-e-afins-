#include <iostream>
#include <list>

using namespace std;

struct no
{
    int v;    // destino da aresta
    int peso; // peso da aresta
};

void bfs(list<no> adj[], int nVertices, int s)
{

    int u;
    int state[nVertices]; // estado do vertice
    int p[nVertices];     // p[u] = v é o pai de u
    int v;
    list<int> Q; // fila de prioridade

    for (u = 0; u < nVertices; u++)
    {
        if (u != s)
        {
            state[u] = -1; //-1 = não visitado
            p[u] = -1;     // sem pais
        }
    }

    state[s] = 0;   // 0 = visitado
    p[s] = -1;      // sem pais
    Q.push_back(s); // insere o vertice s na fila

    list<no>::iterator it;

    while (!Q.empty())
    {                      // enquanto a fila não estiver vazia
        u = Q.front();     // pega o primeiro elemento da fila
        Q.pop_front();     // remove o primeiro elemento da fila
        cout << u << endl; // imprime o elemento
        for (it = adj[u].begin(); it != adj[u].end(); it++)
        {                                  // percorre a lista de adjacência de u
            v = it->v;                     // pega o destino da aresta
            cout << u << " " << v << endl; // imprime o vértice u e o vértice v
            if (state[v] == -1)
            {                   // se o vértice v ainda não foi visitado
                state[v] = 0;   // marca como visitado
                p[v] = u;       // armazena o pai de v
                Q.push_back(v); // insere v na fila
            }
        }
        state[u] = 1; // marca como visitado
    }
}

void cria_aresta(list<no> adj[], int u, int v, int p, int orientado)
{
    no novo;
    novo.v = v;
    novo.peso = p;
    adj[u].push_back(novo);
    if (orientado == 0) // se não for orientado
    {
        novo.v = u;
        adj[v].push_back(novo);
    }
}

int main()
{

    list<no> adj[100];    // lista de adjacência
    int nVertices;        // número de vértices
    int u, v;             // origem e destino da aresta
    int p;                // peso da aresta
    int i;                // contador
    list<no>::iterator q; // iterador para percorrer lista de adjacência
    int orientado;        // grafo 1:orientado 0:não-orientado
    int inicial;

    cin >> nVertices >> inicial;

    //Lendo e inserindo aresta
    cin >> u >> v >> p;
    while (u != -1 && v != -1 && p != -1)
    {
        cria_aresta(adj, u, v, p, 0);
        cin >> u >> v >> p;
    }

    // imprimir valores de adj
    for (i = 0; i < nVertices; i++)
    {
        cout << "Vertice " << i << ": ";
        for (q = adj[i].begin(); q != adj[i].end(); q++)
        {
            cout << q->v << " ";
        }
        cout << endl;
    }

    //Mostrando a lista de adjacência
    bfs(adj, nVertices, inicial);

    //limpar a memória
    for (i = 0; i < nVertices; i++)
    {
        adj[i].clear();
    }

    return 0;
}