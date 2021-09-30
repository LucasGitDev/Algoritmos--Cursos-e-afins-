#include <iostream>

using namespace std;

//Função MOD: recebe dividendo e divisor e retorna o resto da divisão entre ambos
int mod(int x, int y){

    if(x > y)
        return mod(x-y, y);
    else if(x < y)
        return x;
    else
        return 0;
}


int main()
{

    int x; // valor dividendo
    int y; // valor divisor
    int restos[100]; //Vetor que guarda valores retornados da função
    int i; // Contador
    int n; // Tamanho do vetor

    // Ler valores até que ambos sejam == -1
    i = 0;
    cin >> x >> y;

    while(x != -1 && y != -1) {
        restos[i] = mod(x, y);
        i++;
        cin >> x >> y;
    }

    n = i; // Atribuindo tamanho do vetor

    //Amostragem de resultados obtido

    for(i = 0; i < n; i++) {
        cout << restos[i] << " ";
    }

    return 0;
}