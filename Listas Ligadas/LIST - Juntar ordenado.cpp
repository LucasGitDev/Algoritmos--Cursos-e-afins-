#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<int> primeira;
    list<int> segunda;
    list<int> juncao;

    int x;
    int i;
    int tam;

    cin >> x;

    while (x != 0)
    {
        primeira.push_back(x);
        cin >> x;
    }

    cin >> x;

    while (x != 0)
    {
        segunda.push_back(x);
        cin >> x;
    }

    // Juntando as listas e ordenando
    /* método fácil
    juncao.merge(primeira);
    juncao.merge(segunda);
    juncao.sort();
    */

    tam = primeira.size();
    tam += segunda.size(); // tamanho da lista juncao

    while (!primeira.empty() || !segunda.empty())
    {
        if (primeira.front() < segunda.front())
        {                                       // se o primeiro elemento da primeira lista for menor que o primeiro elemento da segunda lista
            juncao.push_back(primeira.front()); // adiciona o primeiro elemento da primeira lista
            primeira.pop_front();               // remove o primeiro elemento da primeira lista
        }
        else if (primeira.front() == segunda.front())
        {
            juncao.push_back(primeira.front());
            primeira.pop_front();
            segunda.pop_front();
        }
        else
        {                                      // se não
            juncao.push_back(segunda.front()); // adiciona o primeiro elemento da segunda lista
            segunda.pop_front();               // remove o primeiro elemento da segunda lista
        }

        if (primeira.empty() && !segunda.empty())
        {
            while (!segunda.empty())
            {
                juncao.push_back(segunda.front());
                segunda.pop_front();
            }
        }
        else if (!primeira.empty() && segunda.empty())
        {
            while (!primeira.empty())
            {
                juncao.push_back(primeira.front());
                primeira.pop_front();
            }
        }
    }

    // Imprimindo a junção

    for (list<int>::iterator it = juncao.begin(); it != juncao.end(); it++)
    {
        cout << *it << " ";
    }

    cout << endl;

    return 0;
}