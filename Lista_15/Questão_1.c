#include <stdio.h>

int  maisVelho(int m, int a, int b)
{
    int mais_velho;
    int idadeDo3 = m - (a + b);
    if(a > b && a > idadeDo3) mais_velho = a;
    else if(b > idadeDo3) mais_velho = b;
    else mais_velho = idadeDo3;
    return mais_velho;
}

int main()
{
     int M; scanf("%i", &M); // Idade da Dona Mônica
     int A; scanf("%i", &A); // Idade de um dos filhos
     int B; scanf("%i", &B); // Idade de outro filho
     printf("%i", maisVelho(M,A,B) );
     return 0;
}