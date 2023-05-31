#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void criptografar(char *texto, char *chave) {
    int tamanho = strlen(texto);

    for (int i = 0; i < tamanho; i++) {
        if (isalpha(texto[i])) {
            if (isupper(texto[i])) {
                texto[i] = chave[texto[i] - 'A'];
            } else {
                texto[i] = tolower(chave[toupper(texto[i]) - 'A']);
            }
        }
    }
}

int verificarChave(char *chave) {
    int freq[26] = {0};
    int tamanho = strlen(chave);

    if (tamanho != 26) {
        return 0;
    }

    for (int i = 0; i < tamanho; i++) {
        if (!isalpha(chave[i])) {
            return 0;
        }

        if (isupper(chave[i])) {
            chave[i] = tolower(chave[i]);
        }

        int posicao = chave[i] - 'a';

        if (freq[posicao] == 1) {
            return 0;
        }

        freq[posicao] = 1;
    }

    return 1;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Use: ./substitution key\n");
        return 1;
    }

    char *chave = argv[1];

    if (!verificarChave(chave)) {
        printf("Chave inválida\n");
        return 1;
    }

    char texto[1000];

    printf("plaintext: ");
    fgets(texto, sizeof(texto), stdin);

    int tamanho = strlen(texto);
    if (texto[tamanho - 1] == '\n') {
        texto[tamanho - 1] = '\0';
    }

    criptografar(texto, chave);

    printf("ciphertext: %s\n", texto);

    return 0;
}
