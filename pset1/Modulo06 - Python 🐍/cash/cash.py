valor = input("Digite o valor em Reais R$: ")

# Verifica se a entrada é um número válido
try:
    valorFloat = float(valor)
    if valorFloat < 0:
        raise ValueError
except ValueError:
    print("Entrada inválida. O valor deve ser um número positivo.")
    exit(1)

# Converte o valor para centavos
centavos = int(valorFloat * 100)

# Calcula a quantidade de moedas de 25 centavos necessárias
moedas25 = centavos // 25
centavos %= 25

# Calcula a quantidade de moedas de 10 centavos necessárias
moedas10 = centavos // 10
centavos %= 10

# Calcula a quantidade de moedas de 5 centavos necessárias
moedas5 = centavos // 5
centavos %= 5

# A quantidade de moedas de 1 centavo será o valor restante
moedas1 = centavos

# Exibe a melhor divisão de moedas
print("Melhor divisão de moedas:")
print(f"Moedas de 25 centavos: {moedas25}")
print(f"Moedas de 10 centavos: {moedas10}")
print(f"Moedas de 5 centavos: {moedas5}")
print(f"Moedas de 1 centavo: {moedas1}")
