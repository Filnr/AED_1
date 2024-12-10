#include <iostream>

using namespace std;

bool ehNatural(int n)
{
    bool ehNatural;
    int divisores = 1;
    if (n > 1)
    {
        for (int i = 2; i <= n/2; i++)
        {
            if (n % i == 0)
            {
                divisores += i;
            }
        }
        ehNatural = divisores == n;
    }
    else
    {
        ehNatural = false;
    }
    return ehNatural;
}

int encontraDivisor(int n, int i)
{
    int divisor = 0;
    if(i == 1)
    {
        divisor = 1;
    }
    else if(i > 1)
    {
        if(n % 1 == 0){
            divisor = i;
        }
        divisor = divisor + encontraDivisor(n, i - 1);
    }
    return divisor;
} 

void ehPerfeito(int n)
{
    int divisores = encontraDivisor(n, n/2);
    if(divisores == n && n > 1)
    {
        cout << "O numero " << n << " e perfeito" << endl;
    }
    else
    {
        cout << "O numero " << n << " nao e perfeito" << endl;
    }
}
int main(void)
{
    int n;
    cout << "Digite um numero: ";
    cin >> n;
    cout << "O numero " << n;
    if (ehNatural(n))
    {
        cout << " e perfeito" << endl;
    }
    else
    {
        cout << " nao e perfeito" << endl;
    }
    cout << "recursivo" << endl;
    ehPerfeito(n);
    return 0;
}