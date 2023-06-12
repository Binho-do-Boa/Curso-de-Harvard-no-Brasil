#include <stdio.h>
#include <ctype.h>
#include <string.h>

int contarLetras(const char *texto) {
    int count = 0;

    for (int i = 0; texto[i] != '\0'; i++) {
        if (isalpha(texto[i])) {
            count++;
        }
    }

    return count;
}

int contarPalavras(const char *texto) {
    int count = 1;  // Assume que o texto tem pelo menos uma palavra

    for (int i = 0; texto[i] != '\0'; i++) {
        if (isspace(texto[i])) {
            count++;
        }
    }

    return count;
}

int contarFrases(const char *texto) {
    int count = 0;

    for (int i = 0; texto[i] != '\0'; i++) {
        if (texto[i] == '.' || texto[i] == '!' || texto[i] == '?') {
            count++;
        }
    }

    return count;
}

float calcularIndiceColemanLiau(int letras, int palavras, int frases) {
    float L = (float)letras / palavras * 100;
    float S = (float)frases / palavras * 100;

    return 0.0588 * L - 0.296 * S - 15.8;
}

int main() {
    char texto[1000];

    printf("Digite um texto: ");
    fgets(texto, sizeof(texto), stdin);

    int letras = contarLetras(texto);
    int palavras = contarPalavras(texto);
    int frases = contarFrases(texto);

    float indice = calcularIndiceColemanLiau(letras, palavras, frases);

    // Exibe o resultado do índice Coleman-Liau
    if (indice >= 16) {
        printf("Grade 16+\n");
    } else if (indice < 1) {
        printf("Before Grade 1\n");
    } else {
        printf("Grade %.f\n", indice);
    }

    return 0;
}
