#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int ler_idade()
{
    int n;
    bool invalido;
    do
    {
        printf("Digite uma idade: ");
        scanf("%d", &n);
        invalido = n < 0 || n > 100;
        if(invalido) printf("Digite uma idade valida\n");
    } 
    while (invalido);
    return n;
}
void escrita()
{
    FILE* arquivo = fopen("idade.dat", "w");
    int idade = ler_idade();
    while(idade != 0)
    {
        fprintf(arquivo, "%d\n", idade);
        idade = ler_idade();
    }
    fclose(arquivo);
}

void soma_idades(int *soma, int *quantidade)
{
    FILE* arquivo = fopen("idade.dat", "r");
    if(arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    int idade;
    // Verificando o retorno de fscanf para evitar problemas com feof
    while(fscanf(arquivo, "%d", &idade) == 1)
    {
        *soma += idade;
        (*quantidade)++;
    }
    fclose(arquivo);
}

int calcula_media()
{
    int soma = 0, quantidade = 0;
    float media;
    soma_idades(&soma, &quantidade);
    media = (float) soma / (float) quantidade;
    return media;
}

void idadesMaioresMedia(FILE* arquivo)
{
    int idade, acima_da_media = 0;
    float media = calcula_media();
    arquivo = fopen("idade.dat", "r");
    while(fscanf(arquivo, "%d", &idade) == 1)
    {
        if(idade > media)
        {
            acima_da_media++;
        }
    }
    printf("Quantidade de idades acima da media: %d", acima_da_media);
    fclose(arquivo);
}

int main(void)
{
    FILE* arquivo;
    escrita(arquivo);
    idadesMaioresMedia(arquivo);
    return 0;
}