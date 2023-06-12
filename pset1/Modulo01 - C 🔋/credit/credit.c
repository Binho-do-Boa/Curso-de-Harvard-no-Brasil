#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool validarLuhn(const char *numero) {
    int len = strlen(numero);
    int soma = 0;
    bool duplicar = false;

    for (int i = len - 1; i >= 0; i--) {
        int digito = numero[i] - '0';

        if (duplicar) {
            digito *= 2;

            if (digito > 9) {
                digito = (digito % 10) + 1;
            }
        }

        soma += digito;
        duplicar = !duplicar;
    }

    return (soma % 10 == 0);
}

bool validarAMEX(const char *numero) {
    int len = strlen(numero);

    if (len != 15 || numero[0] != '3' || (numero[1] != '4' && numero[1] != '7')) {
        return false;
    }

    return validarLuhn(numero);
}

bool validarMASTERCARD(const char *numero) {
    int len = strlen(numero);

    if (len != 16 || numero[0] != '5' || (numero[1] < '1' || numero[1] > '5')) {
        return false;
    }

    return validarLuhn(numero);
}

bool validarVISA(const char *numero) {
    int len = strlen(numero);

    if ((len != 13 && len != 16) || numero[0] != '4') {
        return false;
    }

    return validarLuhn(numero);
}

int main() {
    char numero[20];

    printf("Digite somente números sem espaços do cartão de crédito: ");
    scanf("%s", numero);

    if (validarAMEX(numero)) {
        printf("Número do cartão AMEX válido.\n");
    } else if (validarMASTERCARD(numero)) {
        printf("Número do cartão MASTERCARD válido.\n");
    } else if (validarVISA(numero)) {
        printf("Número do cartão VISA válido.\n");
    } else {
        printf("Número do cartão Inválido.\n");
    }

    return 0;
}
