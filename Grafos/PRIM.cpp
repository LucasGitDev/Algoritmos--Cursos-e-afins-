#include<iostream>
#include<list>
#define INT_MAX 999

using namespace std;

struct no
{
    int v;    // destino da aresta
    int peso; // peso da aresta
};

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

void prim(list<no> adj[], int nVertices, int start)
{
    int distancia[nVertices];
    int parent[nVertices];
    bool intree[nVertices];
    int v, destino, weight, dist;
    int custo;
    int i;
    custo = 0;
    for (i = 0; i < nVertices; i++)
    {
        distancia[i] = INT_MAX;
        parent[i] = -1;
        intree[i] = false;
    }

    distancia[start] = 0;
    v = start;

    while (intree[v] == false)
    {
        intree[v] = true;
        for (list<no>::iterator p = adj[v].begin(); p != adj[v].end(); p++)
        {
            destino = p->v;
            weight = p->peso;

            if (distancia[destino] > weight && intree[destino] == false)
            {
                distancia[destino] = weight;
                parent[destino] = v;
            }
        }

        v = 0;
        dist = INT_MAX;
        for (i = 0; i < nVertices; i++)
        {
            if (intree[i] == false && distancia[i] < dist)
            {
                dist = distancia[i];
                v = i;
            }
        }
    }
    
    cout << "Arvore Geradora Minima:" << endl;
    for (i = 0; i < nVertices; i++)
    {   
        custo += distancia[i];
        if (parent[i] != -1)
            cout << parent[i] << " " << i << " " << endl;
    }
    
    cout << "Custo: " << custo << endl;
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

    cin >> nVertices >> orientado >> inicial;

    //Lendo e inserindo aresta
    cin >> u >> v >> p;
    while (u != -1 && v != -1 && p != -1)
    {
        cria_aresta(adj, u, v, p, orientado);
        cin >> u >> v >> p;
    }
    
    //Mostrando a lista de adjacência
    prim(adj, nVertices, inicial);

    //limpar a memória
    for (i = 0; i < nVertices; i++)
    {
        adj[i].clear();
    }
    return 0;
}