#include <stdio.h>

void impressao(int n1)
{
    printf("%d ", n1);
    if (n1 > 0) 
    {
        impressao(n1 - 1);
    }
}

int ler_numero()
{
    int n1;
    printf("Digite um numero: ");
    scanf("%d", &n1);
    return n1;
}

int main(void)
{
    int num1 = ler_numero();
    impressao(num1);
    return 0;
}