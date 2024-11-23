#include <stdio.h>
#include <stdbool.h>
const int MAX = 100; // Constante global: tamanho físico
int TAM = 0;         // Variável global: tamanho lógico

typedef struct
{
    char nome[50];
    int idade;
} Pessoa;

int menu()
{
    int op;
    bool invalido;
    printf("\n\tMenu\n\n");
    printf("1-Cadastrar uma pessoa\n2-Listar pessoas cadastradas\n3-Exibir a idade media das pessoas\n0- Encerrar programa\n\n");
    do
    {
        printf("Qual acao deseja realizar?: ");
        scanf("%d", &op);
        invalido = op < 0 || op > 3;
        if (invalido)
            printf("Digite um numero válido\n");
    } while (invalido);
    return op;
}

void exibePessoas(Pessoa pessoas[], int i)
{
    printf("Nome: %s, Idade: %d\n\n", pessoas[i].nome, pessoas[i].idade);
}

void listar_pessoas(Pessoa pessoas[])
{
    printf("\nLista de todas as pessoas registradas:\n");
    for (int i = 0; i < TAM; i++)
    {
        exibePessoas(pessoas, i);
    }
}

void cadastraNome(Pessoa pessoas[])
{
    printf("Digite o nome da pessoa: ");
    while (getchar() != '\n'); // Clear the input buffer
    fgets(pessoas[TAM].nome, sizeof(pessoas[TAM].nome), stdin);
}

void cadastraIdades(Pessoa pessoas[])
{
    printf("Digite a idade da pessoa: ");
    scanf("%d", &pessoas[TAM].idade);
}

void cadastraPessoas(Pessoa pessoas[])
{
    cadastraNome(pessoas);
    cadastraIdades(pessoas);
    TAM++;
}

void mediaIdades(Pessoa pessoas[])
{
    int media = 0;
    for (int i = 0; i < TAM; i++)
    {
        media += pessoas[i].idade;
    }
    media /= TAM;
    printf("Idade media: %d", media);
}

int main(void)
{
    Pessoa pessoas[MAX];
    int op = menu();
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
        default:
            mediaIdades(pessoas);
        }
        op = menu();
    }
    printf("Obrigado por utilizar esse programa");
    return 0;
}