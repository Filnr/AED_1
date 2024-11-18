#include <stdio.h>
#include <stdbool.h>

const int MAX = 50;
int TAM = 0;

typedef struct
{
    float ladoA;
    float ladoB;
    float ladoC;
} Triangulo;

int menu()
{
    bool invalido;
    int op;
    printf("\n\tMenu\n\n");
    printf("0 - Sair do programa\n");
    printf("1 - Ler um triangulo\n");
    printf("2 - Informar o numero de triangulos equilateros\n");
    printf("3 - Informar o numero de triangulos isosceles\n");
    printf("4 - Informar o numero de triangulos escalenos\n");
    do
    {
        printf("Digite a sua escolha: ");
        scanf("%d", &op);
        invalido = op < 0 || op > 4;
        if(invalido) printf("Digite uma opção valida\n");
    } while (invalido);
    return op;
}
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
void ler_triangulo(Triangulo triangulos[])
{
    printf("Digite os valores para o %d triangulo\n", TAM + 1);
    triangulos[TAM].ladoA = ler_numero("para o lado A");
    triangulos[TAM].ladoB = ler_numero("para o lado B");
    triangulos[TAM].ladoC = ler_numero("para o lado C");
    TAM++;
}

bool verificaEquilatero(Triangulo triangulos[], int posicao)
{
    bool ehEquilatero = false;
    if (triangulos[posicao].ladoA == triangulos[posicao].ladoB && triangulos[posicao].ladoB == triangulos[posicao].ladoC)
    {
        ehEquilatero = true;
    }
    return ehEquilatero;
}

int contaEquilateros(Triangulo triangulos[])
{
    int contador = 0;
    for (int i = 0; i < TAM; i++)
    {
        if (verificaEquilatero(triangulos, i))
        {
            contador++;
        }
    }
    return contador;
}

bool verificaIsosceles(Triangulo triangulos[], int posicao)
{
    bool ehIsosceles = false;
    if (!verificaEquilatero(triangulos, posicao) && (triangulos[posicao].ladoA == triangulos[posicao].ladoB || triangulos[posicao].ladoB == triangulos[posicao].ladoC || triangulos[posicao].ladoA == triangulos[posicao].ladoC))
    {
        ehIsosceles = true;
    }
    return ehIsosceles;
}

int contaIsosceles(Triangulo triangulos[])
{
    int contador = 0;
    for (int i = 0; i < TAM; i++)
    {
        if (verificaIsosceles(triangulos, i))
        {
            contador++;
        }
    }
    return contador;
}

bool verificaEscaleno(Triangulo triangulos[], int posicao)
{
    bool ehEscaleno = false;
    if (!verificaEquilatero(triangulos, posicao) && !verificaIsosceles(triangulos, posicao))
    {
        ehEscaleno = true;
    }
    return ehEscaleno;
}

int contaEscalenos(Triangulo triangulos[])
{
    int contador = 0;
    for (int i = 0; i < TAM; i++)
    {
        if(verificaEscaleno(triangulos, i))
        {
            contador++;
        }
    }
    return contador;
}

void resultado(int n, char *msg)
{
    printf("A quantidade de triangulos %s vale %d.\n", msg, n);
}

void despedida()
{
    printf("\nObrigado por utilizar esse programa\n");
}
int main(void)
{
    Triangulo triangulos[MAX];
    int op = menu();
    while (op != 0)
    {
        switch (op)
        {
        case 1:
            ler_triangulo(triangulos);
            break;
        case 2:
            resultado(contaEquilateros(triangulos), "equilateros");
            break;
        case 3:
            resultado(contaIsosceles(triangulos), "isosceles");
            break;
        case 4:
            resultado(contaEscalenos(triangulos), "escalenos");
        }
        op = menu();
    }
    despedida();
}