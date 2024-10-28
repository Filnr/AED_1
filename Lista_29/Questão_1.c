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
            fscanf(cadastrosI, "%d", &pessoas[i].idade);
        }
    }
    fclose(cadastrosI);

    TAM = qtPessoas;
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
    bool invalido;
    do
    {
        printf("Digite a idade da pessoa: ");
        scanf("%d", &pessoas[TAM].idade);
        invalido = pessoas[TAM].idade < 0 || pessoas[TAM].idade > 150;
        if(invalido) printf("Digite uma idade válida\n");
    } while (invalido);

    cadastro = fopen("cadastroIdade.dat", "a");
    fprintf(cadastro, "%d\n", pessoas[TAM].idade);
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

void salvaDados()
{
    FILE* tam = fopen("qtRegistros.dat", "w");
    fprintf(tam, "%d", TAM);
    fclose(tam);
}

int main(void)
{
    FILE *cadastrosN;
    FILE *tam;
    FILE *cadastrosI;
    Pessoa pessoas[MAX];
    int op = menu();
    backupDados(cadastrosN, cadastrosI, tam, pessoas);
    printf("tam = %d\n\n\n", TAM);
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
        default:
            mediaIdades(pessoas);
        }
        op = menu();
    }
    printf("Obrigado por utilizar esse programa");
    salvaDados();
    return 0;
}