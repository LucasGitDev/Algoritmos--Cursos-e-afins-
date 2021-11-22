#include <iostream>
#include <list>

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

int main()
{

    list<no> adj[100];     // lista de adjacência
    int nVertices;        // número de vértices
    int u, v;             // origem e destino da aresta
    int p;                // peso da aresta
    int i;                // contador
    list<no>::iterator q; // iterador para percorrer lista de adjacência
    int orientado;        // grafo 1:orientado 0:não-orientado

    cin >> nVertices >> orientado;

    //Lendo e inserindo aresta
    cin >> u >> v >> p;
    while (u != -1 && v != -1 && p != -1)
    {
    	cria_aresta(adj, u, v, p, orientado);
        cin >> u >> v >> p;        
    }

    //Mostrando a lista de adjacência
    // for (i = 0; i < nVertices; i++)
    // {
    //     for (q = adj[i].begin(); q != adj[i].end(); q++)
    //     {
    //         cout << i << " " <<  q->v << " " << q->peso << endl;
    //     }
    // }

    // Imprimir a lista de adjacência de acordo com os vertices
    for (i = 0; i < nVertices; i++)
    {
        for (q = adj[i].begin(); q != adj[i].end(); q++)
        {
            cout << i << " -- " <<  q->v << " p:" << q->peso << endl;
        }
    }

    //limpar a memória
    for (i = 0; i < nVertices; i++)
    {
        adj[i].clear();
    }

    return 0;
}