#include <stdio.h>

void escreveInvertidoRec(int num)
{
    if(num > 0)
    {
        int ultimo_digito = num % 10;       
        printf("%d", ultimo_digito);
        escreveInvertidoRec(num/10);
    }
}

int main()
{
     int x;
     scanf("%d", &x);
     escreveInvertidoRec(x);
}