#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *num1, *num2, *soma;
    num1 = malloc(sizeof(int));
    num2 = malloc(sizeof(int));
    scanf("%d", num1);
    scanf("%d", num2);
    soma = malloc(sizeof(int));
    *soma = *num1 + *num2;
    printf("%d" , *soma);

}