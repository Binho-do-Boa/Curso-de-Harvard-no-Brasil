import csv
import sys


def count_str(dna_sequence, str_sequence):
    max_count = 0
    current_count = 0
    str_len = len(str_sequence)
    i = 0

    while i < len(dna_sequence):
        if dna_sequence[i:i + str_len] == str_sequence:
            current_count += 1
            i += str_len
            if current_count > max_count:
                max_count = current_count
        else:
            current_count = 0
            i += 1

    return max_count


def identify_dna(csv_file, dna_file):
    # Leitura do arquivo CSV
    with open(csv_file, "r") as file:
        reader = csv.DictReader(file)
        data = list(reader)

    # Leitura do arquivo de sequência de DNA
    with open(dna_file, "r") as file:
        dna_sequence = file.read()

    # Obtenção dos STRs da primeira linha do arquivo CSV
    strs = list(data[0].keys())[1:]

    # Contagem dos STRs na sequência de DNA
    counts = {}
    for str_sequence in strs:
        counts[str_sequence] = count_str(dna_sequence, str_sequence)

    # Verificação das correspondências no arquivo CSV
    for row in data:
        name = row["name"]
        match = True

        for str_sequence in strs:
            if int(row[str_sequence]) != counts[str_sequence]:
                match = False
                break

        if match:
            print(name)
            return

    print("No match")


# Verificação dos argumentos de linha de comando
if len(sys.argv) != 3:
    print("Uso: python dna.py arquivo_csv arquivo_dna")
    sys.exit(1)

# Identificação da sequência de DNA
csv_file = sys.argv[1]
dna_file = sys.argv[2]
identify_dna(csv_file, dna_file)
