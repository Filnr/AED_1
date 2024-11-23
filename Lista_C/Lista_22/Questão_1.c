#include <stdio.h>
#include <stdbool.h>

int ler_numero()
{
    int n;
    bool invalido;
    do
    {
        printf("Digite a quantidade de alunos na turma: ");
        scanf("%d", &n);
        invalido = n < 0;
        if(invalido) printf("Digite um numero valido");
    } while (invalido);
    return n;
}

void ler_nota(int nota[], int tamanho)
{
    bool invalido;
    for(int i = 0; i < tamanho; i++)
    {
        do
        {
            printf("Digite a nota do %d.o aluno: ", i+1);
            scanf("%d", &nota[i]);
            invalido = nota[i] > 100 || nota[i] < 0;
            if(invalido) printf("Digite uma nota valida\n");
        } 
        while (invalido);
    }
}

int nota_media(int nota[], int tamanho)
{
    int media = 0;
    for(int i = 0; i < tamanho; i++)
    {
        media += nota[i];
    }
    media /=  tamanho;
    return media;
}

void resultado(int alunosAcimaMedia)
{
    printf("A quantidade de notas acima da media foram: %d", alunosAcimaMedia);
}

void acima_media(int nota[], int tamanho, int media)
{
    int acimaDaMedia = 0;
    for(int i = 0; i < tamanho; i++)
    {
        if(nota[i] > media)
        {
            acimaDaMedia++;
        }
    }
    resultado(acimaDaMedia);
}

int main(void)
{
    int n =  ler_numero("a quantidade de alunos na turma: ");
    int nota[n];
    ler_nota(nota, n);
    int media = nota_media(nota, n);
    acima_media(nota, n, media);
}