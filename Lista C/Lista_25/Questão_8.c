#include <stdio.h>
#define tam 4

void imprimir_diagonal(float matrix[tam][tam])
{
    for(int i = 0; i < tam; i++)
    {
        printf("%.1f ", matrix[i][i]);
    }
}

int main(void)
{
    float matrix[4][4] = { 
        {1, 2, 3, 4}, 
        {5, 6, 7, 8}, 
        {9, 10, 11, 12}, 
        {13, 14, 15, 16} 
    };
    imprimir_diagonal(matrix);
}