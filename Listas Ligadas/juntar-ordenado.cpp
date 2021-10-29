#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<int> lista; // ponteiro para a lista
    list<int> lista2;
    int x;

    cin >> x;
    while (x != 0)
    {
        lista.push_front(x);
        cin >> x;
    }

    cin >> x;
    while (x != 0)
    {
        lista.push_front(x);
        cin >> x;
    }

    

    // Liberando a memória utilizada pela lista
    while (!lista.empty())
        lista.pop_front();
    return 0;
}