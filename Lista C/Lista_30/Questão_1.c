#include <stdio.h>
#include <stdbool.h>

typedef struct
{
    float ladoA;
    float ladoB;
    float ladoC;
} Triangulo;

int ler_numero(char *msg)
{
    float n;
    bool invalido;
    do
    {
        printf("Digite um %s:", msg);
        scanf("%f", &n);
        invalido = n < 1;
        if (invalido)
            printf("Digite um valor valido");
    } while (invalido);
    return n;
}
void ler_lados(Triangulo triangulos[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf("\nDigite os valores para o %d triangulo\n", i+1);
        triangulos[i].ladoA = ler_numero("para o lado A");
        triangulos[i].ladoB = ler_numero("para o lado B");
        triangulos[i].ladoC = ler_numero("para o lado C");
    }
}

bool verificaEquilatero(Triangulo triangulos[], int posicao)
{
    bool ehEquilatero = false;
    if(triangulos[posicao].ladoA == triangulos[posicao].ladoB && triangulos[posicao].ladoB == triangulos[posicao].ladoC)
    {
        ehEquilatero = true;
    }
    return ehEquilatero;
}

int contaEquilateros(Triangulo triangulos[], int tam)
{
    int contador = 0;
    for(int i = 0; i < tam; i++)
    {
        if(verificaEquilatero(triangulos, i))
        {
            contador++;
        }
    }
    return contador;
}

void resultado(int n)
{
    printf("A quantidade de triangulos equilateros vale %d", n);
}

int main(void)
{
    const int tam = 5;
    Triangulo triangulos[tam];
    ler_lados(triangulos, tam);
    resultado(contaEquilateros(triangulos, tam));
}