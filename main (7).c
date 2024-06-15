#include <stdio.h>
<<<<<<< HEAD
<<<<<<< HEAD
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_ALUNOS 50

typedef struct {
    char nome[50];
    double nota;
} Aluno;

void incluir_aluno(Aluno alunos[], int *num_alunos);
void listar_alunos(Aluno alunos[], int num_alunos);
void ordenar_alunos_por_nome(Aluno alunos[], int num_alunos);
void exibir_menu();

int main() {
    setlocale(LC_ALL, "portuguese");

    Aluno alunos[MAX_ALUNOS];
    int num_alunos = 0;
    int opcao;

    do {
        exibir_menu();
        scanf("%d", &opcao);
        getchar();  // Consumir o newline deixado pelo scanf

        switch (opcao) {
            case 1:
                incluir_aluno(alunos, &num_alunos);
                break;
            case 2:
                listar_alunos(alunos, num_alunos);
                break;
            case 3:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 3);
=======
=======
>>>>>>> 8ba026d9d8143e2e9f84bf774f7d8e0f3f487180

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    if (b == 0) {
        printf("Error: Division by zero is not allowed.\n");
        return 0;
    }
    return a / b;
}

int main() {
    int num1, num2, choice, result;
    char exit;

    do {
        printf("Enter two integers: ");
        scanf("%d %d", &num1, &num2);

        printf("Enter choice: 1.Addition 2.Subtraction 3.Multiplication 4.Division\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                result = add(num1, num2);
                printf("Result: %d\n", result);
                break;
            case 2:
                result = subtract(num1, num2);
                printf("Result: %d\n", result);
                break;
            case 3:
                result = multiply(num1, num2);
                printf("Result: %d\n", result);
                break;
            case 4:
                result = divide(num1, num2);
                printf("Result: %d\n", result);
                break;
            default:
                printf("Error! operator is not correct\n");
                break;
        }

        printf("Do you want to continue (y/n)? ");
        scanf(" %c", &exit);

    } while(exit == 'y' || exit == 'Y');
<<<<<<< HEAD
>>>>>>> 8ba026d9d8143e2e9f84bf774f7d8e0f3f487180
=======
>>>>>>> 8ba026d9d8143e2e9f84bf774f7d8e0f3f487180

    return 0;
}

<<<<<<< HEAD
<<<<<<< HEAD
void exibir_menu() {
    printf("\nMenu:\n");
    printf("1. Incluir aluno\n");
    printf("2. Listar alunos\n");
    printf("3. Sair\n");
    printf("Escolha uma opção: ");
}

void incluir_aluno(Aluno alunos[], int *num_alunos) {
    if (*num_alunos >= MAX_ALUNOS) {
        printf("Número máximo de alunos atingido.\n");
        return;
    }

    printf("Digite o nome do aluno: ");
    fgets(alunos[*num_alunos].nome, sizeof(alunos[*num_alunos].nome), stdin);
    alunos[*num_alunos].nome[strcspn(alunos[*num_alunos].nome, "\n")] = 0; // Remove newline

    printf("Digite a nota do aluno: ");
    scanf("%lf", &alunos[*num_alunos].nota);
    getchar();  // Consumir o newline deixado pelo scanf

    (*num_alunos)++;
}

void listar_alunos(Aluno alunos[], int num_alunos) {
    if (num_alunos == 0) {
        printf("Nenhum aluno cadastrado.\n");
        return;
    }

    ordenar_alunos_por_nome(alunos, num_alunos);

    printf("\nLista de Alunos:\n");
    for (int i = 0; i < num_alunos; i++) {
        printf("Nome: %s\n", alunos[i].nome);
        printf("Nota: %.2f\n", alunos[i].nota);
        if (alunos[i].nota >= 6.0) {
            printf("Situação: Aprovado\n");
        } else {
            printf("Situação: Reprovado\n");
        }
        printf("--------------------------------------------\n");
    }
}

void ordenar_alunos_por_nome(Aluno alunos[], int num_alunos) {
    int troca;
    Aluno temp;

    for (int i = 0; i < num_alunos - 1; i++) {
        troca = 0;
        for (int j = 0; j < num_alunos - i - 1; j++) {
            if (strcmp(alunos[j].nome, alunos[j + 1].nome) > 0) {
                temp = alunos[j];
                alunos[j] = alunos[j + 1];
                alunos[j + 1] = temp;
                troca = 1;
            }
        }
        if (!troca) break;
    }
}

=======
>>>>>>> 8ba026d9d8143e2e9f84bf774f7d8e0f3f487180
=======
>>>>>>> 8ba026d9d8143e2e9f84bf774f7d8e0f3f487180
