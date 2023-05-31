#include <stdio.h>
#include <stdlib.h>



int main() {
    char valor[20];
    int i;
    int moedas25, moedas10, moedas5, moedas1;

    printf("Digite o valor em Reais R$: ");
    scanf("%s", valor);

    // Substitui vírgula por ponto, se existir
    for (i = 0; valor[i] != '\0'; i++) {
        if (valor[i] == ',') {
            valor[i] = '.';
        }
    }

    // Converte o valor para float
    float valorFloat = atof(valor);

    // Converte o valor para centavos
    int centavos = (int)(valorFloat * 100);

    // Calcula a quantidade de moedas de 25 centavos necessárias
    moedas25 = centavos / 25;
    centavos %= 25;

    // Calcula a quantidade de moedas de 10 centavos necessárias
    moedas10 = centavos / 10;
    centavos %= 10;

    // Calcula a quantidade de moedas de 5 centavos necessárias
    moedas5 = centavos / 5;
    centavos %= 5;

    // A quantidade de moedas de 1 centavo será o valor restante
    moedas1 = centavos;

    // Exibe a melhor divisão de moedas
    printf("Melhor divisão de moedas:\n");
    printf("Moedas de 25 centavos: %d\n", moedas25);
    printf("Moedas de 10 centavos: %d\n", moedas10);
    printf("Moedas de 5 centavos: %d\n", moedas5);
    printf("Moedas de 1 centavo: %d\n", moedas1);

    return 0;
}