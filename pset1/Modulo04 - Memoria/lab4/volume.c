#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Verificar os argumentos da linha de comando
    if (argc != 4)
    {
        printf("Uso: ./volume input.wav output.wav fator\n");
        return 1;
    }

    // Abrir os arquivos e determinar o fator de escala
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Não foi possível abrir o arquivo.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Não foi possível criar o arquivo.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // Copiar o cabeçalho do arquivo de entrada para o arquivo de saída
    uint8_t header[HEADER_SIZE];
    fread(header, sizeof(uint8_t), HEADER_SIZE, input);
    fwrite(header, sizeof(uint8_t), HEADER_SIZE, output);

    // Ler as amostras do arquivo de entrada e escrever os dados atualizados no arquivo de saída
    int16_t buffer;
    while (fread(&buffer, sizeof(int16_t), 1, input))
    {
        buffer *= factor;
        fwrite(&buffer, sizeof(int16_t), 1, output);
    }

    // Fechar os arquivos
    fclose(input);
    fclose(output);

    return 0;
}
