#ifndef PESSOA_H
#define PESSOA_H
#include "data.h"
#include "definicoes.h"

#define MAX_STR 50
typedef struct
{
    char nome[MAX_STR];
    Data dataNascimento;
} Pessoa;

void exibePessoas(Pessoa pessoas[], int i)
{
    printf("Nome: %s, data de aniversário: %d/%d/%d\n\n", pessoas[i].nome, pessoas[i].dataNascimento.dia, pessoas[i].dataNascimento.mes, pessoas[i].dataNascimento.ano);
}

void listar_pessoas(Pessoa pessoas[])
{
    printf("\nLista de todas as pessoas registradas:\n");
    for (int i = 0; i < TAM; i++)
    {
        exibePessoas(pessoas, i);
    }
}

void cadastraNome(Pessoa pessoas[], FILE *cadastro)
{
    printf("Digite o nome da pessoa: ");
    while (getchar() != '\n')
        ; // Clear the input buffer
    fgets(pessoas[TAM].nome, sizeof(pessoas[TAM].nome), stdin);
    cadastro = fopen("cadastroNome.dat", "a");
    fprintf(cadastro, "%s", pessoas[TAM].nome);
    fclose(cadastro);
}

void cadastraIdades(Pessoa pessoas[], FILE *cadastro)
{
    printf("Digite a data de nascimento: ");
    scanf("%d/%d/%d", &pessoas[TAM].dataNascimento.dia, &pessoas[TAM].dataNascimento.mes, &pessoas[TAM].dataNascimento.ano);
    cadastro = fopen("cadastroIdade.dat", "a");
    fprintf(cadastro, "%d/%d/%d\n", pessoas[TAM].dataNascimento.dia, pessoas[TAM].dataNascimento.mes, pessoas[TAM].dataNascimento.ano);
    fclose(cadastro);
}

void cadastraPessoas(Pessoa pessoas[], FILE *cadastrosN, FILE *cadastrosI)
{
    if (TAM >= MAX) {
        printf("Limite de cadastro atingido!\n");
    } 
    else 
    {
        cadastraNome(pessoas, cadastrosN);
        cadastraIdades(pessoas, cadastrosI);
        TAM++;
    }
}

#endif // PESSOA_H