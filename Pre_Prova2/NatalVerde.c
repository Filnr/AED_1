#include <stdio.h>
#include <string.h>
#define MAX_STR 100
#define MAX 100

typedef struct {
    char nomeItem[MAX_STR];
    float valor;
    int prioridade;
} Item;

typedef struct {
    char nome[MAX_STR];
    int qtItens;
    Item itens[MAX];
} Lista;

void ordenaLista(Lista *lista) {
    for (int j = 0; j < lista->qtItens - 1; j++) {
        for (int k = 0; k < lista->qtItens - 1 - j; k++) {
            // Ordena por prioridade (maior primeiro - invertemos a comparação)
            if (lista->itens[k].prioridade < lista->itens[k + 1].prioridade) {
                Item temp = lista->itens[k];
                lista->itens[k] = lista->itens[k + 1];
                lista->itens[k + 1] = temp;
            }
            // Se prioridade igual, ordena por valor
            else if (lista->itens[k].prioridade == lista->itens[k + 1].prioridade) {
                if (lista->itens[k].valor > lista->itens[k + 1].valor) {
                    Item temp = lista->itens[k];
                    lista->itens[k] = lista->itens[k + 1];
                    lista->itens[k + 1] = temp;
                }
                // Se valor igual, ordena por nome
                else if (lista->itens[k].valor == lista->itens[k + 1].valor) {
                    if (strcmp(lista->itens[k].nomeItem, lista->itens[k + 1].nomeItem) > 0) {
                        Item temp = lista->itens[k];
                        lista->itens[k] = lista->itens[k + 1];
                        lista->itens[k + 1] = temp;
                    }
                }
            }
        }
    }
}

void imprimeLista(Lista *lista) {
    printf("Lista de %s\n", lista->nome);
    for (int i = 0; i < lista->qtItens; i++) {
        printf("%s - R$%.2f\n", lista->itens[i].nomeItem, lista->itens[i].valor);
    }
    printf("\n");
}

int main(void) {
    char nome[MAX_STR];
    int quantidade;
    Lista lista;

    // Lê até EOF
    while (scanf("%s %d", nome, &quantidade) == 2) {
        // Inicializa lista
        strcpy(lista.nome, nome);
        lista.qtItens = 0;

        // Lê os itens
        for (int i = 0; i < quantidade; i++) {
            // Lê nome do item (pode conter espaços)
            scanf(" %[^\n]", lista.itens[lista.qtItens].nomeItem);
            
            // Lê valor e prioridade na próxima linha
            scanf("%f %d", &lista.itens[lista.qtItens].valor, 
                         &lista.itens[lista.qtItens].prioridade);
            
            lista.qtItens++;
        }

        // Ordena e imprime a lista
        ordenaLista(&lista);
        imprimeLista(&lista);
    }

    return 0;
}