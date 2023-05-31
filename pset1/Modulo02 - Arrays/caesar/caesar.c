#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void cifraCesar(char *texto, int chave) {
    int tamanho = strlen(texto);

    for (int i = 0; i < tamanho; i++) {
        if (isalpha(texto[i])) {
            if (isupper(texto[i])) {
                texto[i] = ((texto[i] - 'A' + chave) % 26) + 'A';
            } else {
                texto[i] = ((texto[i] - 'a' + chave) % 26) + 'a';
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Use: ./caesar key\n");
        return 1;
    }

    int chave = atoi(argv[1]);

    if (chave < 0) {
        printf("Use: ./caesar key\n");
        return 1;
    }

    char texto[1000];

    printf("plain_text: ");
    fgets(texto, sizeof(texto), stdin);

    int tamanho = strlen(texto);
    if (texto[tamanho - 1] == '\n') {
        texto[tamanho - 1] = '\0';
    }

    cifraCesar(texto, chave);

    printf("cipher_text: %s\n", texto);

    return 0;
}
