#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void escrita(char* nome)
{
    FILE* arquivo = fopen(nome, "wb");
    float valor;
    printf("Digite um valor: ");
    scanf("%f", &valor);
    while(valor != 0)
    {
        fprintf(arquivo, "%.2f\n", valor);
        scanf("%f", &valor);
    }
    fclose(arquivo);
}

void amplitude(FILE* arquivo)
{
    float valor;
    arquivo = fopen("arquivo1.txt", "rb");
    fscanf(arquivo, "%f", &valor);
    float menor = valor, maior = valor;
    while(!feof(arquivo))
    {
        fscanf(arquivo, "%f", &valor);
        if(valor > maior)
        {
            maior = valor;
        }
        else if (valor < menor)
        {
            menor = valor;
        }
    }
    printf("Amplitude: %.2f\n", (maior - menor));
    printf("Maior: %.2f\n", maior);
    printf("Menor: %.2f\n", menor);
    fclose(arquivo);
}

int main()
{
    FILE* arquivo;
    escrita("arquivo1.txt");
    amplitude(arquivo);
    return 0;
}