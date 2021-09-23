#include <iostream>

using namespace std;

//Função combinatória dada pelo enunciado
int Comb(int n, int k)
{
    if(k == 1)
        return n;
    else if(k == n)
        return 1;
    else
        return (Comb(n-1, k-1) + Comb(n-1, k));
}

int main()
{
    int n; //n pessoas diferentes
    int k; //k pessoas num grupo
    int qtd; //valor da combinação de n e k

    //Leitura de dados
    cin >> n >> k;

    //Utilização da função Comb
    qtd = Comb(n, k);

    //Saída do resultado
    cout << qtd ;

    return 0;
}
