#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include <stdlib.h>
#include "data.h"
#include "Pessoa.h"
#include "definicoes.h"
void backupDados(FILE *cadastrosN, FILE *cadastrosI, FILE *tamanho, Pessoa pessoas[])
{
    int qtPessoas = 0;
    tamanho = fopen("qtRegistros.dat", "r");
    if (tamanho == NULL) 
    {
        tamanho = fopen("qtRegistros.dat", "w");
        fprintf(tamanho, "0");
        fclose(tamanho);
    }
    else
    {
        fscanf(tamanho, "%d", &qtPessoas);
        fclose(tamanho);
    }
    cadastrosN = fopen("cadastroNome.dat", "r");
    if (cadastrosN != NULL)
    {
        for (int i = 0; i < qtPessoas; i++)
        {
            fgets(pessoas[i].nome, sizeof(pessoas[i].nome), cadastrosN);
        }
    }

    fclose(cadastrosN);
    cadastrosI = fopen("cadastroIdade.dat", "r");
    if (cadastrosI != NULL)
    {
        for (int i = 0; i < qtPessoas; i++)
        {
            fscanf(cadastrosI, "%d/%d/%d", &pessoas[i].dataNascimento.dia, &pessoas[i].dataNascimento.mes, &pessoas[i].dataNascimento.ano);
        }
    }
    fclose(cadastrosI);

    TAM = qtPessoas;
}

void apagaDados()
{
    FILE *idades = fopen("cadastroIdade.dat", "w");
    fclose(idades);
    FILE *nomes = fopen("cadastroNome.dat", "w");
    fclose(nomes);
    FILE *registros = fopen("qtRegistros.dat", "w");
    fclose(registros);
    TAM = 0;
}

void salvaDados()
{
    FILE* tam = fopen("qtRegistros.dat", "w");
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
    FILE *cadastrosN;
    FILE *tam;
    FILE *cadastrosI;
    Pessoa pessoas[MAX];
    int op = menu();
    backupDados(cadastrosN, cadastrosI, tam, pessoas);
    while (op != 0)
    {
        switch (op)
        {
        case 1:
            cadastraPessoas(pessoas, cadastrosN, cadastrosI);
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
    salvaDados();
    return 0;
}