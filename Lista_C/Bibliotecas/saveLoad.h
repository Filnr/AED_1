#ifndef SAVELOAD_H
#define SAVELOAD_H

#include <stdbool.h>

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
    FILE *registros = fopen("qtRegistros.dat", "wb");
    fclose(registros);
    TAM = 0;
}

void encerramento(Pessoa pessoas[])
{
    FILE *arqPessoas = fopen("pessoas.dat", "wb");
    fwrite(pessoas, sizeof(Pessoa), TAM, arqPessoas);
    fclose(arqPessoas);

    FILE *tam = fopen("qtRegistros.dat", "wb");
    fprintf(tam, "%d", TAM);
    fclose(tam);
    printf("\nObrigado por utilizar esse programa\n");
}

#endif // SAVELOAD_H