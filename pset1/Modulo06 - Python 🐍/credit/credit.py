def validar_luhn(numero):
    len_numero = len(numero)
    soma = 0
    duplicar = False

    for i in range(len_numero - 1, -1, -1):
        digito = int(numero[i])

        if duplicar:
            digito *= 2

            if digito > 9:
                digito = (digito % 10) + 1

        soma += digito
        duplicar = not duplicar

    return soma % 10 == 0


def validar_amex(numero):
    len_numero = len(numero)

    if len_numero != 15 or numero[0] != '3' or (numero[1] != '4' and numero[1] != '7'):
        return False

    return validar_luhn(numero)


def validar_mastercard(numero):
    len_numero = len(numero)

    if len_numero != 16 or numero[0] != '5' or (numero[1] < '1' or numero[1] > '5'):
        return False

    return validar_luhn(numero)


def validar_visa(numero):
    len_numero = len(numero)

    if (len_numero != 13 and len_numero != 16) or numero[0] != '4':
        return False

    return validar_luhn(numero)


numero = input("Digite somente números sem espaços do cartão de crédito: ")

if validar_amex(numero):
    print("Número do cartão AMEX válido.")
elif validar_mastercard(numero):
    print("Número do cartão MASTERCARD válido.")
elif validar_visa(numero):
    print("Número do cartão VISA válido.")
else:
    print("Número do cartão Inválido.")
