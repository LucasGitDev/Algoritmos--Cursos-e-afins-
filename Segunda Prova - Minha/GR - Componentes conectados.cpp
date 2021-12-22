#include <iostream>
#include <list>

using namespace std;

bool conexo; // indica se o grafo é conexo

struct no
{
    int v;    // destino da aresta
    int peso; // peso da aresta
};

// Implementação de percurso em largura (BFS) para verificar se um grafo é conexo ou não.
void bfs(list<no>adj[], int nVertices, int s)
{
    char state[10];
    int p[10];
    list<int> Q;
    int i;
    int u,v; // vars aux para mostrar os vértices
    list<no>::iterator q; // iterador para varrer a lista de adjacências
    
    for(i=0;i<nVertices;i++)
    {
        state[i] = 'u';
        p[i] = -1;
    }    
    state[s] = 'd';
    p[s] = -1;
    Q.push_back(s);
    while(!Q.empty())
    {
        u = *Q.begin();
        Q.pop_front();
        //cout << u << endl; // código da questão fornecido
        for(q=adj[u].begin();q!=adj[u].end();q++)
        {
            v = q->v;
            //cout << u << " " << v << endl; // código da questão fornecido
            if(state[v]=='u')
            {
                state[v] = 'd';
                p[v] = u;
                Q.push_back(v);
            }
        }
        state[u] = 'p';
    }
    
    // verifica se o grafo é conexo
    for(i=0;i<nVertices;i++) // 
    {
        if(state[i]=='u') // se algum vértice não for visitado, o grafo não é conexo
        {
            conexo = false;
            return;
        }
    }

    conexo = true;
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

    list<no> adj[10];    // lista de adjacência
    int nVertices;        // número de vértices
    int u, v;             // origem e destino da aresta
    int p;                // peso da aresta
    int i;                // contador
    list<no>::iterator q; // iterador para percorrer lista de adjacência
    int orientado;        // grafo 1:orientado 0:não-orientado
    int inicial; // vértice inicial
    int nArestas; // número de arestas

    cin >> nVertices >> inicial;
    nArestas = 0;
    //Lendo e inserindo aresta
    cin >> u >> v;
    while (u != -1 && v != -1)
    {
        cria_aresta(adj, u, v, 1, 0);
        nArestas++;
        cin >> u >> v;
    }
    
    bfs(adj, nVertices, inicial);

    if (conexo)
        cout << "Conexo" << endl;
    else
        cout << "Nao conexo" << endl;

    //limpar a memória
    for (i = 0; i < nVertices; i++)
    {
        adj[i].clear();
    }

    return 0;
}