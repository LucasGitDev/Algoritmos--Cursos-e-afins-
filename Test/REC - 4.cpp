#include <iostream>

using namespace std;

//Função recursiva para cálculo do MDC
int mdc(int x, int y)
{
    if(x == y) {
        return x;
    } else if(x < y)
        return mdc(y, x);
    else
        return mdc(x-y, y);
}

int main()
{
    int x;//número x para cálculo do mdc
    int y;//número y para cálculo do mdc
    int mdcCalculado; //Recebe retorno da função

    //Ler valores x e y

    cin >> x >> y;

    //Executar função mdc
    mdcCalculado = mdc(x, y);

    //Exibir valor
    cout << mdcCalculado;

    return 0;
}