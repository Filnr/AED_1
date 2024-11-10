#include <stdio.h>
#include <stdbool.h>
#define aprovado 60

bool invalido;
int Menu()
{
    int op;
    printf("Menu\n0 - Sair do programa\n1 - Cadastrar uma nota\n2 - Quantidade de aprovados\n3 - Amplitude das notas\n");
    do
    {
        printf("Sua escolha: ");
        scanf("%d", &op);
        invalido = op > 3 || op < 0;
        if(invalido) printf("Valor invalido\n");
    } while (invalido);
    return op;
}

float ler_nota()
{
    float nota;
    do
    {
        printf("Digite a nota: ");
        scanf("%f", &nota);
        invalido = nota < 0 || nota > 100;
        if(invalido) printf("Nota invalido\n");
    } while (invalido);
    return nota;
}

void cadastro_nota(float nota[], int aluno)
{
    nota[aluno] = ler_nota();
}

int alunos_aprovados(float notas[], int tamanho)
{
    int aprovados = 0;
    if(tamanho >= 0)
    {
        if(notas[tamanho - 1] >= aprovado) 
        {
            aprovados = 1;
        }
        aprovados += alunos_aprovados(notas, tamanho - 1); 
    }
    return aprovados;
}

void amplitude(float notas[], int tamanho)
{
    float maior = notas[0], menor = notas[0];
    for(int i = 1; i < tamanho; i++)
    {
        if(maior < notas[i]) maior = notas[i];
        else if(menor > notas[i]) menor = notas[i];
    }
    printf("Amplitude das notas: %.1f\n", maior - menor);
}

int main(void)
{
    float notas[80];
    int op = Menu();
    int aluno = 0;
    printf("Bem vindo ao programa de notas\n\n");
    while(op != 0)
    {
        switch (op)
        {
        case 1:
            cadastro_nota(notas, aluno);
            aluno++;
            break;
        case 2:
            printf("Quantidade de aprovados: %d\n", alunos_aprovados(notas, aluno));
            break;
        case 3:
            amplitude(notas, aluno);
            break;
        }
        op = Menu();
    }
    printf("Obrigado por utilizar o programa");
}