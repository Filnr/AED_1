#include <stdio.h>

void print_tabela(int n)
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            printf("%d ", i * j);
        }
        printf("\n");
    }
}

int main(void)
{
    int n; scanf("%d", &n); //Numero da tabela
    print_tabela(n);
}