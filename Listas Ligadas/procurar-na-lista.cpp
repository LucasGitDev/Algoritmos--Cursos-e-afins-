#include <iostream>
#include <list>

using namespace std;

bool encontrar(list<int> lista, float x)
{
    list<int>::iterator p; // iterador para varrer a lista
    for (p = lista.begin(); p != lista.end(); p++)
        if(*p == x)
            return true;
        else
            return false;
}


int main()
{
    list<int> lista;       // ponteiro para a lista
    
    int x;                 // var aux para leitura dos dados a serem inseridos na lista e a procura

    // Inserindo elementos na lista
    cin >> x;
    while (x != 0)
    {
        lista.push_front(x);
        cin >> x;
    }    

    if(encontrar(lista, x))
        cout << "Encontrado" << endl;
    else    
        cout << "Nao encontrado" << endl;

 
    // Liberando a memória utilizada pela lista
    while (!lista.empty())
        lista.pop_front();
    return 0;
}