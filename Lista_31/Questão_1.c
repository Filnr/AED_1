#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include <stdlib.h>
#include "data.h"
#include "Pessoa.h"
#include "definicoes.h"
void backupDados(Pessoa pessoas[])
{
    FILE *arqTamanho = fopen("qtRegistros.dat", "rb");
    if (arqTamanho == NULL)
    {
        arqTamanho = fopen("qtRegistros.dat", "wb");
        TAM = 0;
        fprintf(arqTamanho, "%i", TAM);
    }
    else
    {
        fscanf(arqTamanho, "%i", &TAM);
    }
    fclose(arqTamanho);

    FILE *arqPessoas = fopen("pessoas.dat", "rb+");

    if (arqPessoas == NULL)
    {
        arqPessoas = fopen("pessoas.dat", "wb+");
    }
    fread(pessoas, sizeof(Pessoa), TAM, arqPessoas);
    fclose(arqPessoas);
}

void apagaDados()
{
    FILE *arqPessoas = fopen("pessoas.dat", "wb");
    fclose(arqPessoas);
    FILE *registros = fopen("qtRegistros.dat", "w");
    fclose(registros);
    TAM = 0;
}

void salvaDados(Pessoa pessoas[])
{
    FILE *arqPessoas = fopen("pessoas.dat", "wb");
    fwrite(pessoas, sizeof(Pessoa), TAM, arqPessoas);
    fclose(arqPessoas);

    FILE *tam = fopen("qtRegistros.dat", "wb");
    fprintf(tam, "%d", TAM);
    fclose(tam);
}

int menu()
{
    int op;
    bool invalido;
    printf("\n\tMenu\n\n");
    printf("1-Cadastrar uma pessoa\n2-Listar pessoas cadastradas\n3- Apagar pessoas registradas\n4-Apresentar informações sobre a data\n0- Encerrar programa\n\n");
    do
    {
        printf("Qual acao deseja realizar?: ");
        scanf("%d", &op);
        invalido = op < 0 || op > 4;
        if (invalido)
            printf("Digite um numero válido\n");
    } while (invalido);
    return op;
}

int main(void)
{
    setlocale(LC_ALL, "");
    Pessoa pessoas[MAX];
    int op = menu();
    backupDados(pessoas);
    while (op != 0)
    {
        switch (op)
        {
        case 1:
            cadastraPessoas(pessoas);
            break;
        case 2:
            listar_pessoas(pessoas);
            break;
        case 3:
            apagaDados();
        case 4:
            printf("O mes %s digitado tem %d dias, sendo o dia uma %s", mesExtenso(pessoas[TAM - 1].dataNascimento), diasMes(pessoas[TAM - 1].dataNascimento), diaSemana(pessoas[TAM - 1].dataNascimento));
        }
        op = menu();
    }
    printf("Obrigado por utilizar esse programa");
    salvaDados(pessoas);
    return 0;
}