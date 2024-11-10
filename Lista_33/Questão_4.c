#include <string.h>
#include <stdio.h>
#define MAX_STR 50
#define TAM 5

typedef struct 
{
    char nome[MAX_STR];
    int idade;
}Pessoa;

typedef struct 
{
    char nome[MAX_STR];
}Clone;

void primeiroNome(Pessoa pessoas[], Clone primeirosNomes[])
{
    char nome[MAX_STR]
    for(int i = 0; i < TAM; i++)
    {
        while(pessoas[i].nome[j] != ' ' && pessoas[i].nome[j] != '\0')
        {
            nome[i] = pessoas[i].nome[j];
            j++;
        }
    }
}

void exibiPessoa(Pessoa pessoas)
{
    printf("Nome: %s\n", pessoas.nome);
    printf("Idade: %d\n\n", pessoas.idade);
}

void BuscaRec(Pessoa pessoas[], int posicao, char* chaveNome, char primeirosNomes[][MAX_STR])
{
    if(srtcmp(primeirosNomes[posicao][MAX_STR], chaveNome == 0) && posicao < TAM) exibiPessoa(pessoas[posicao]);
    else if(posicao == TAM) printf("Nome nao encontrado\n");
    else
    {
        buscaRec(pessoas, posicao + 1);
    }
}

void chamaRec(Pessoa pessoas[], char* chave, char primeirosNomes[])
{
    listaPessasRec(pessoas, 0, chave, primeirosNomes);
}

void criaChave(char chave[])
{
    printf("Qual nome deseja buscar: ");
    scanf("%s", chave);
}


int main(void)
{
    char chave[MAX_STR];
    criaChave(chave);
    Pessoa pessoas[TAM] = {
        {"João Silva", 18},
        {"Maria Santos", 25},
        {"Carlos Oliveira", 19},
        {"Ana Pereira", 22},
        {"Lucas Mendes", 25}};
    Clone primeirosNomes[TAM];
    primeiroNome(pessoas, primeirosNomes);
    chamaRec(pessoas, chave, primeirosNomes);
}