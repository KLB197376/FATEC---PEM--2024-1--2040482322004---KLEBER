#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUTOS 100
#define MAX_NOME 100
#define MAX_DESC 200

typedef struct {
    int id;
    char nome[MAX_NOME];
    char descricao[MAX_DESC];
    float preco;
    int quantidade;
} Produto;

void inserirProduto(Produto *produtos, int *total);
void listarProdutos(Produto *produtos, int total);
void comprarProduto(Produto *produtos, int total);
void ordenarProdutos(Produto *produtos, int total);

int main() {
    Produto produtos[MAX_PRODUTOS];
    int total = 0;
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1. Inserir produto\n");
        printf("2. Listar produtos\n");
        printf("3. Comprar produto\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                inserirProduto(produtos, &total);
                break;
            case 2:
                listarProdutos(produtos, total);
                break;
            case 3:
                comprarProduto(produtos, total);
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while(opcao != 4);

    return 0;
}

void inserirProduto(Produto *produtos, int *total) {
    if (*total >= MAX_PRODUTOS) {
        printf("Nao e possivel adicionar mais produtos.\n");
        return;
    }

    printf("Inserir produto:\n");
    produtos[*total].id = *total + 1;
    printf("Nome do produto: ");
    scanf(" %[^\n]%*c", produtos[*total].nome);
    printf("Descricao do produto: ");
    scanf(" %[^\n]%*c", produtos[*total].descricao);
    printf("Preco unitario: ");
    scanf("%f", &produtos[*total].preco);
    printf("Quantidade em estoque: ");
    scanf("%d", &produtos[*total].quantidade);

    (*total)++;
    ordenarProdutos(produtos, *total);
}

void listarProdutos(Produto *produtos, int total) {
    printf("\nLista de produtos:\n");
    for (int i = 0; i < total; i++) {
        printf("ID: %d\n", produtos[i].id);
        printf("Nome: %s\n", produtos[i].nome);
        printf("Descricao: %s\n", produtos[i].descricao);
        printf("Preco: %.2f\n", produtos[i].preco);
        printf("Quantidade em estoque: %d\n\n", produtos[i].quantidade);
    }
}

void comprarProduto(Produto *produtos, int total) {
    int id, quantidade;

    printf("Digite o ID do produto: ");
    scanf("%d", &id);

    int index = -1;
    for (int i = 0; i < total; i++) {
        if (produtos[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Produto inexistente.\n");
        return;
    }

    printf("Digite a quantidade desejada: ");
    scanf("%d", &quantidade);

    if (produtos[index].quantidade < quantidade) {
        printf("Estoque insuficiente.\n");
        return;
    }

    produtos[index].quantidade -= quantidade;
    printf("Compra realizada com sucesso!\n");
}

void ordenarProdutos(Produto *produtos, int total) {
    Produto temp;
    for (int i = 0; i < total - 1; i++) {
        for (int j = 0; j < total - i - 1; j++) {
            if (strcmp(produtos[j].nome, produtos[j + 1].nome) > 0) {
                temp = produtos[j];
                produtos[j] = produtos[j + 1];
                produtos[j + 1] = temp;
            }
        }
    }
}

