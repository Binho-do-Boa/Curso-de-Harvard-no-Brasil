import string


def contar_letras(texto):
    count = 0

    for char in texto:
        if char.isalpha():
            count += 1

    return count


def contar_palavras(texto):
    count = 1  # Assume que o texto tem pelo menos uma palavra

    for char in texto:
        if char.isspace():
            count += 1

    return count


def contar_frases(texto):
    count = 0

    for char in texto:
        if char in ('.', '!', '?'):
            count += 1

    return count


def calcular_indice_coleman_liau(letras, palavras, frases):
    L = (letras / palavras) * 100
    S = (frases / palavras) * 100

    return 0.0588 * L - 0.296 * S - 15.8


texto = input("Digite um texto: ")

letras = contar_letras(texto)
palavras = contar_palavras(texto)
frases = contar_frases(texto)

indice = calcular_indice_coleman_liau(letras, palavras, frases)

# Exibe o resultado do índice Coleman-Liau
if indice >= 16:
    print("Grade 16+")
elif indice < 1:
    print("Before Grade 1")
else:
    print(f"Grade {indice:.0f}")
