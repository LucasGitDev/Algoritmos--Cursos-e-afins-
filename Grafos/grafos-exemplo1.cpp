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
    int nVertices = 4; // número de vértices
    int u, v; // origem e destino da aresta
    int p; // peso da aresta
    int i; // contador
    no aux; // auxiliar para inserir arestas em adj
    list<no>::iterator q; // iterador para percorrer lista de adjacência

    //Lendo e inserindo aresta
    for(i = 0; i < nVertices; i++) {
        cin >> u >> v >> p;
        aux.v = v;
        aux.peso = p;
        adj[u].push_back(aux);
    }

    //Mostrando a lista de adjacência
    for(i = 0; i < nVertices; i++) {
        for(q = adj[i].begin(); q != adj[i].end(); q++) {
            cout << i << "(" << q->v << ", " << q->peso << ") ";
        }
        cout << endl;
    }

    //limpar a memória
    for(i = 0; i < nVertices; i++) {
        adj[i].clear();
    }

    return 0;
}