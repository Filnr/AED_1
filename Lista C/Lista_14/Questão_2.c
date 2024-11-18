#include <stdio.h>

void impressao(int x)
{
    printf("%d ", x);
    if (x < 5) impressao(x + 1);
    printf("%d ", x);
}

int main(void)
{
    impressao(1);
    return 0;
}