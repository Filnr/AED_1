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
    printf("A quantidade de notas acima da media foram: %d\n", alunosAcimaMedia);
}

int acima_media(int nota[], int tamanho, int media)
{
    int acimaDaMedia = 0;
    for(int i = 0; i < tamanho; i++)
    {
        if(nota[i] > media)
        {
            acimaDaMedia++;
        }
    }
    return acimaDaMedia;
}

void maiores_menoresNotas(int nota[], int tamanho, int *menor, int *maior)
{
    *menor = nota[0];
    *maior = nota[0];
    for(int i = 0; i < tamanho; i++)
    {
        if(nota[i] > *maior) *maior = nota[i];
        else if(nota[i] < *menor) *menor = nota[i];

    }
}
 
void resultado_maioresEmenores(int menor, int maior)
{
    printf("A maior nota foi: %d\nA menor nota foi: %d\n", maior, menor);
}

int aprovados(int nota[], int tamanho)
{ 
    int aprovados = 0;
    for(int i = 0; i < tamanho; i++)
    {
        if(nota[i] >= 60)
        {
            aprovados++;
        }
    }
    return aprovados;
}

void menor_nota_entreAprovados(int nota[], int tamanho)
{
    int quantidade_aprovados = aprovados(nota, tamanho); 
    int aprovados[quantidade_aprovados], n = 0;
    //Registrar as notas aprovadas
    for (int i = 0; i < tamanho; i++) 
    {
        if (nota[i] >= 60) 
        {
            aprovados[n] = nota[i];
            n++;
        }
    }
    //Encontrar a menor nota entre os aprovados
    int menor_aprovado = aprovados[0]; 
    for(int i = 0; i < quantidade_aprovados; i++)
    {
        if(menor_aprovado > aprovados[i])
        {
            menor_aprovado = aprovados[i];
        }
    }
    printf("Menor nota entre os aprovados: %d\n", menor_aprovado);
}

void porcentagem_aprovacao(int nota[], int tamanho)
{
    int quantidade_aprovados = aprovados(nota, tamanho);
    float porcent_aprovacao = ((float)quantidade_aprovados / tamanho) * 100;
    printf("A taxa de aprovação foi de %.1f\n", porcent_aprovacao);
}
int main(void)
{
    int menorNota, maiorNota;
    int n =  ler_numero("a quantidade de alunos na turma: ");
    int nota[n];
    ler_nota(nota, n);
    int media = nota_media(nota, n);
    maiores_menoresNotas(nota, n, &menorNota, &maiorNota);
    resultado(acima_media(nota, n, media));
    resultado_maioresEmenores(menorNota, maiorNota);
    menor_nota_entreAprovados(nota, n);
    porcentagem_aprovacao(nota, n);
}