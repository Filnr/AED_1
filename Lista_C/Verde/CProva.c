#include <stdio.h>
#include <string.h>

void cadastrarRespostas(int n_alunos, int n_questoes, char respostas[][n_questoes]) {
    char temp[100];
    for(int i = 0; i < n_alunos; i++) {
        scanf(" %[^\n]s", temp);  // Mudei para scanf para evitar problemas com o buffer
        int k = 0;
        for(int j = 0; j < strlen(temp); j++) {
            if(temp[j] != ' ' && temp[j] != '\n') {
                respostas[i][k] = temp[j];
                k++;
            }
        }
    }
}

void cadastrarGabarito(int n_questoes, char gabarito[]) {
    char temp[100];
    scanf(" %[^\n]s", temp);  // Mudei para scanf aqui também
    int k = 0;
    for(int j = 0; j < strlen(temp); j++) {
        if(temp[j] != ' ' && temp[j] != '\n') {
            gabarito[k] = temp[j];
            k++;
        }
    }
}

int* calcularPontuacao(int n_alunos, int n_questoes, char respostas[][n_questoes], char gabarito[]) {
    static int pontuacao[100];  // Assumindo um máximo de 100 alunos
    
    for(int i = 0; i < n_alunos; i++) {
        pontuacao[i] = 0;
        for(int j = 0; j < n_questoes; j++) {
            if(respostas[i][j] == gabarito[j]) {
                pontuacao[i]++;
            }
        }
    }
    
    return pontuacao;
}

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    
    char respostas[100][100];
    char gabarito[100];
    
    cadastrarRespostas(n, m, respostas);
    cadastrarGabarito(m, gabarito);
    
    int* pontuacao = calcularPontuacao(n, m, respostas, gabarito);
    
    for(int i = 0; i < n; i++) {
        printf("%d", pontuacao[i]);
        if(i < n - 1) printf(" ");
    }
    printf("\n");
    
    return 0;
}