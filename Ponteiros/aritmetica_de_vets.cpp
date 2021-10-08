#include <iostream>

using namespace std;


int main(){

    int vet[3]; //vetor
    int *p = NULL; //ponteiro para varrer o vetor
    
    vet[0] = 2;
    vet[1] = 5;
    vet[2] = -3;

    cout <<"vetor: " << vet << endl;

    cout << "*vetor = " << *vet << endl;

    p = vet;

    cout << "*p = " << *p << endl;

    p++;

    cout << "*p = " << *p << endl;

    p++;

    cout << "*p = " << *p << endl;


    p--;

    cout << "*p = " << *p << endl;


    return 0;
}