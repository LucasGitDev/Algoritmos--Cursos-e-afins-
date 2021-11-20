#include<iostream>
#include<list>

using namespace std;

struct no
{
    int v;    // destino da aresta
    int peso; // peso da aresta
};

void bfs(list<no>adj[], int nVertices, int s){
    
    int u;
    int state[nVertices];
    int p[nVertices];
    int v;
    list<int> Q;

    for(u=0;u<nVertices;u++){
        if(u != s) {
            state[u] = -1;//-1 = não visitado
            p[u] = -1;
        }
    }

    state[s] = 0;
    p[s] = -1;
    Q.push_back(s);

    list<no>::iterator it;

    while(!Q.empty()){
        u = Q.front();
        Q.pop_front();
        cout << u << endl;
        for(it = adj[u].begin(); it != adj[u].end(); it++){
            v = it->v;
            cout << u <<" " << v << endl;
            if(state[v] == -1){
                state[v] = 0;
                p[v] = u;
                Q.push_back(v);
            }
        }
        state[u] = 1;// processado
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

int main(){

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

    // // imprimir valores de adj
    // for (i = 0; i < nVertices; i++)
    // {
    //     cout << "Vertice " << i << ": ";
    //     for (q = adj[i].begin(); q != adj[i].end(); q++)
    //     {
    //         cout << q->v << " ";
    //     }
    //     cout << endl;
    // }

    //Mostrando a lista de adjacência
    bfs(adj, nVertices, inicial);

    //limpar a memória
    for (i = 0; i < nVertices; i++)
    {
        adj[i].clear();
    }

    return 0;
}