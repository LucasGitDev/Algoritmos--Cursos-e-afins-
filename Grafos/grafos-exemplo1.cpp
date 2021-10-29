#include <iostream>
#include <list>

using namespace std;

struct no
{
    int v; // destino da aresta
    int peso; // peso da aresta
};


int main() {

    list<no> adj[10]; // lista de adjacência
    int nVertices; // número de vértices
    int u, v; // origem e destino da aresta
    int p; // peso da aresta
    int i; // contador
    no aux; // auxiliar para inserir arestas em adj

    for(i = 0; i < 4; i++) {
        cin >> u >> v >> p;
        aux.v = v;
        aux.peso = p;
        adj[u].push_back(aux);
    }

    return 0;
}