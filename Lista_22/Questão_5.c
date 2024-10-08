#include <stdio.h>
#include <stdbool.h>


void ler_nota(int nota[], int tamanho)
{
    int n = 1, alunos = 0;
    bool invalido;
    while(n != 0)
    {
        do
        {
            printf("Digite a nota do %d.o aluno: ", alunos+1);
            scanf("%d", &nota[alunos]);
            invalido = nota[alunos] > 100 || nota[alunos] < 0;
            if(invalido) printf("Digite uma nota valida\n");
            if(nota[alunos] == 0) n = 0;
        } 
        while (invalido);
        if(n != 0) alunos++;
    }
    alunos++;
    printf("A quantidade de alunos foi: %d\n", alunos);
}

int main(void)
{
    int n = 100;
    int nota[n];
    ler_nota(nota, n);
    return 0;
}