#include <stdio.h>

int main() {
    int populacao_inicial, populacao_final;
    int anos = 0;

    printf("Digite o tamanho populacional inicial (maior que 9): ");
    while (scanf("%d", &populacao_inicial) != 1 || populacao_inicial <= 9) {
        printf("Valor inválido. Digite novamente o tamanho populacional inicial (maior que 9): ");
        while (getchar() != '\n');
    }

    printf("Digite o tamanho populacional final (maior que %d): ", populacao_inicial);
    while (scanf("%d", &populacao_final) != 1 || populacao_final <= populacao_inicial) {
        printf("Valor inválido. Digite novamente o tamanho populacional final (maior que %d): ", populacao_inicial);
        while (getchar() != '\n');
    }

    // Realiza o cálculo do crescimento populacional
    while (populacao_inicial < populacao_final) {
        populacao_inicial += populacao_inicial / 3 - populacao_inicial / 4;
        anos++;
    }

    // Exibe o resultado
    printf("O tamanho Populacional será atingido em %d anos.\n", anos);

    return 0;
}