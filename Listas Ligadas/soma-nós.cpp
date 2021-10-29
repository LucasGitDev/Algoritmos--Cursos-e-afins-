#include <iostream>
#include <list>

using namespace std;

int soma(list<int> lista)
{
    int soma;
    list<int>::iterator p; // iterador para varrer a lista

    soma = 0;
    for ( p = lista.begin(); p != lista.end(); p++ )
        soma += *p;
    cout << "soma = " << soma << endl;
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

    cout << soma(lista);

    // Liberando a memória utilizada pela lista
    while (!lista.empty())
        lista.pop_front();
    return 0;
}