#include <stdio.h>
#define MAX_STR 50
#define TAM 5

typedef struct 
{
    char nome[MAX_STR];
    int idade;
}Pessoa;

void exibiPessoa(Pessoa pessoas)
{
    printf("Nome: %s\n", pessoas.nome);
    printf("Idade: %d\n\n", pessoas.idade);
}

void listaPessasRec(Pessoa pessoas[], int posicao)
{
    if(posicao == TAM - 1) exibiPessoa(pessoas[posicao]);
    else if(posicao < TAM - 1)
    {
        exibiPessoa(pessoas[posicao]);
        listaPessasRec(pessoas, posicao + 1);
    }
}

void chamaRec(Pessoa pessoas[])
{
    listaPessasRec(pessoas, 0);
}

int main(void)
{
    Pessoa pessoas[TAM] = {
        {"João Silva", 18},
        {"Maria Santos", 25},
        {"Carlos Oliveira", 19},
        {"Ana Pereira", 22},
        {"Lucas Mendes", 25}};
    chamaRec(pessoas);
}