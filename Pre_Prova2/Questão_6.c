#include <stdio.h>
#include <stdbool.h>
#define TAM 5

bool verificaInverso(int vetor1[], int vetor2[])
{
    bool inverso = true;
    int i = 0;
    int j = TAM - 1;
    while(i < TAM && j >= 0 && inverso)
    {
        if(vetor1[i] != vetor2[j]) inverso = false;
        i++;
        j--;
    }
    return inverso;
}

int main(void)
{
    int vetor1[TAM] ={1,2,3,4,5};
    int vetor2[TAM] = {5,4,2,3,1};
    if(verificaInverso(vetor1, vetor2)) printf("Inversos\n");
    else printf("Nao inversos\n");
}