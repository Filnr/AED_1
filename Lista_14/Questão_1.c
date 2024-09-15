#include <stdio.h>

void impressao(int x)
{
    printf(" %d,", x);
    if(x < 5) impressao(x + 1);
}

int main(void)
{
    impressao(1);
}