#include <iostream>

using namespace std;

int qtIguais(float a[], float b[], int TAM)
{
    int qtIguais = 0;
    for(int i = 0; i < TAM; i++)
    {
        if(a[i] == b[i])
            qtIguais++;
    }
    return qtIguais;
}

int rec(float a[], float b[], int TAM, int i)
{
    int qtIguais = 0;
    if(i < TAM)
    {
        if(a[i] == b[i]){
            qtIguais = 1;
        }
        qtIguais = qtIguais + rec(a, b, TAM, i + 1);
    }
    return qtIguais;
}

int main(void)
{   
    int TAM = 5;
    float a[TAM] = {1, 2, 3, 4, 5};
    float b[TAM] = {0, 1, 3, 16, 5};
    cout << "Iguais por iterativo: " << qtIguais(a, b, TAM) << endl;
    cout << "Iguais por recursivo: " << rec(a, b, TAM, 0) << endl;
}