#include <stdio.h>

void escreveInvertido(int num)
{
    int ultimo_digito, invertido = 0;
    while(num > 0)
    {
        ultimo_digito = num % 10;
        num = num / 10;
        invertido = (invertido * 10) + ultimo_digito;
    }
    printf("%d", invertido);
}

int main()
{
    int x;
    scanf("%d", &x);
    escreveInvertido(x);
}