#include <stdio.h>
#include <stdbool.h>

#define MAX_ROW 500
#define MAX_COL 500

void readMatrix(char matrix[MAX_ROW][MAX_COL], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf(" %c", &matrix[i][j]);
        }
    }
}
void rainFall(char matrix[MAX_ROW][MAX_COL], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == '.')
            {
                    if ((matrix[i - 1][j] == 'o') || (matrix[i][j - 1] == 'o' && matrix[i + 1][j - 1] == '#') || (matrix[i][j + 1] == 'o' && matrix[i + 1][j + 1] == '#'))    
                    {
                        matrix[i][j] = 'o';
                    }
                    
            }
        }
    }
}

int main()
{
    int rows, cols;
    scanf("%d %d", &rows, &cols);

    char matrix[MAX_ROW][MAX_COL];
    readMatrix(matrix, rows, cols);
    rainFall(matrix, rows, cols);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%c", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}