#include <iostream>
#include <cstdlib>

using namespace std;

void sorteiaNum()
{
    cout << "Numeros sorteados iterativo: ";
    for(int i = 0; i < 6; i++)
    {
        int num = rand() % 60 + 1;
        cout << num << " ";
    }
    cout << endl;
}

void sorteiaNumRec(int i)
{
    int num = rand() % 60 + 1;
    if(i == 0)
    {
        cout << num << endl;
    }
    else if(i > 0)
    {
        cout << num << " ";
        sorteiaNumRec(i - 1);
    }
}

int main(void)
{
    sorteiaNum();
    cout << "Numeros sorteados recursivo: ";
    sorteiaNumRec(6);
    return 0;
}