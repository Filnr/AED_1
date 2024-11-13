#include <stdio.h>
#include <string.h>
#define MAX_STR 50
int num;

typedef struct 
{
    char marca[MAX_STR];
    int ano;
    float valorCarro;
}Carro;

void lerDados(Carro carros[])
{
    char marca[MAX_STR];
    for(int i = 0; i < num; i++)
    {
        scanf("%s", carros[i].marca);
        scanf("%d", &carros[i].ano);
        scanf("%f", &carros[i].valorCarro);
    }
}

void exibiCarro(Carro carro)
{
    printf("Marca: %s, Ano: %d, Preco: %.2f\n", carro.marca, carro.ano, carro.valorCarro);
}

void resultado(Carro carros[], float valor)
{
    printf("Carros com preco menor que %.2f:\n", valor);
    for(int i = 0; i < num; i++)
    {
        if(carros[i].valorCarro < valor)
        {
            exibiCarro(carros[i]);
        }
    }
}


int main(void)
{
    scanf("%d", &num);
    Carro carros[num];
    lerDados(carros);
    float valor; scanf("%f", &valor);
    resultado(carros, valor);
}
