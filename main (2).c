#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Função para verificar se uma palavra é um palíndromo
int isPalindrome(char *word) {
    int length = strlen(word);
    if (length <= 1) {
        return 0; // Palavras com 1 ou menos caracteres não são consideradas palíndromos
    }
    for (int i = 0; i < length / 2; i++) {
        if (tolower(word[i]) != tolower(word[length - i - 1])) {
            return 0; // Não é um palíndromo
        }
    }
    return 1; // É um palíndromo
}

// Função para verificar se uma palavra é um artigo ou preposição
int isArticleOrPreposition(char *word) {
    const char *articles_prepositions[] = {"a", "o", "as", "os", "de", "do", "da", "dos", "das", "em", "no", "na", "nos", "nas", "por", "para", "pelo", "pela", "pelos", "pelas"};
    int num_articles_prepositions = sizeof(articles_prepositions) / sizeof(articles_prepositions[0]);
    for (int i = 0; i < num_articles_prepositions; i++) {
        if (strcmp(word, articles_prepositions[i]) == 0) {
            return 1; // É um artigo ou preposição
        }
    }
    return 0; // Não é um artigo ou preposição
}

int main() {
    char frase[1000];
    printf("Digite uma frase: ");
    fgets(frase, sizeof(frase), stdin);

    char *token = strtok(frase, " ");
    while (token != NULL) {
        // Remover o caractere de quebra de linha no final de cada palavra
        if (token[strlen(token) - 1] == '\n') {
            token[strlen(token) - 1] = '\0';
        }
        // Verifica se a palavra não é um artigo ou preposição
        if (!isArticleOrPreposition(token)) {
            // Verifica se a palavra é um palíndromo
            if (isPalindrome(token)) {
                printf("Palíndromo encontrado: %s\n", token);
            }
        }
        token = strtok(NULL, " ");
    }

    return 0;
}