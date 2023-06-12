altura = int(input("Digite um número entre 1 e 8: "))

# Verifica se a altura está dentro do intervalo válido
if altura < 1 or altura > 8:
    print("Numero inválida. O número deve estar entre 1 e 8.")
    exit(1)

for linha in range(1, altura + 1):
    # Imprime os espaços em branco antes dos hashtags da primeira pirâmide
    for espacos in range(altura - linha, 0, -1):
        print(" ", end="")

    # Imprime os hashtags da primeira pirâmide
    for hashtags in range(1, linha + 1):
        print("#", end="")

    # Adiciona os espaços entre as pirâmides
    print("  ", end="")

    # Imprime os hashtags da segunda pirâmide
    for hashtags in range(1, linha + 1):
        print("#", end="")

    print()
