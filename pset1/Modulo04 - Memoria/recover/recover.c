#include <stdio.h>
#include <stdint.h>

#define BLOCK_SIZE 512

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Verificar se o programa foi executado com exatamente um argumento de linha de comando
    if (argc != 2)
    {
        printf("Uso correto: ./recover imagem_forense\n");
        return 1;
    }

    // Abrir o arquivo de imagem forense para leitura
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Não foi possível abrir o arquivo de imagem forense.\n");
        return 1;
    }

    BYTE buffer[BLOCK_SIZE];
    int jpegCount = 0;
    FILE *jpeg = NULL;

    // Ler o arquivo de imagem forense em blocos de 512 bytes
    while (fread(buffer, BLOCK_SIZE, 1, file))
    {
        // Verificar se o bloco atual corresponde ao início de um novo JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Fechar o arquivo JPEG anterior, se existir
            if (jpeg != NULL)
            {
                fclose(jpeg);
            }

            // Criar um novo arquivo JPEG com um nome numerado
            char filename[8];
            sprintf(filename, "%03d.jpg", jpegCount);
            jpeg = fopen(filename, "w");
            jpegCount++;
        }

        // Se um arquivo JPEG estiver aberto, escrever o bloco no arquivo
        if (jpeg != NULL)
        {
            fwrite(buffer, BLOCK_SIZE, 1, jpeg);
        }
    }

    // Fechar o último arquivo JPEG
    if (jpeg != NULL)
    {
        fclose(jpeg);
    }

    // Fechar o arquivo de imagem forense
    fclose(file);

    return 0;
}
