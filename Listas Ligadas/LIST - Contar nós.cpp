#include <iostream>
#include <list>

using namespace std;

int contar(list<int> lista) {
    // contar nós
    int cont = 0;
    list<int>::iterator p; // iterador para varrer a lista

    for ( p = lista.begin(); p != lista.end(); p++ )
        cont++;
    return cont;
}

int main()
{
    list<int> lista; // ponteiro para a lista

    int x; // var aux para leitura dos dados a serem inseridos na lista e a procura

    // Inserindo elementos na lista
    cin >> x;
    while (x != 0)
    {
        lista.push_front(x);
        cin >> x;
    }    

    //contar nós e imprimir

    cout << contar(lista) << endl;


    // Liberando a memória utilizada pela lista
    while (!lista.empty())
        lista.pop_front();
    return 0;
}