#include <cs50.h>
#include <stdio.h>

int main() {
    int altura, linha, espacos, hashtags;

    printf("Digite um número entre 1 e 8: ");
    scanf("%d", &altura);

    // Verifica se a altura está dentro do intervalo válido
    if (altura < 1 || altura > 8) {
        printf("Altura inválida. O número deve estar entre 1 e 8.\n");
        return 1;
    }

    for (linha = 1; linha <= altura; linha++) {
        // Imprime os espaços em branco antes dos hashtags
        for (espacos = altura - linha; espacos > 0; espacos--) {
            printf(" ");
        }

        // Imprime os hashtags
        for (hashtags = 1; hashtags <= linha; hashtags++) {
            printf("#");
        }

        printf("\n");
    }

    return 0;
}