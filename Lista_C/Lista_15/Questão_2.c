#include <stdio.h>

int minimoDeViagens(int c, int a)
{
    int viagens;
    viagens = a / (c - 1);
    if(a % (c - 1) != 0) viagens += 1;
    if(c > a) viagens = 1;
    return viagens;
}

int main()
{
     int C; scanf("%i", &C); // Capacidade da cabine
     int A; scanf("%i", &A); // Número total de alunos na turma
     printf("%i", minimoDeViagens(C,A) );
     return 0;
}