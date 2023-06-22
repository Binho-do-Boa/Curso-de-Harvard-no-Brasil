import sqlite3
from flask import Flask, render_template, request, redirect

app = Flask(__name__)

# Configuração do banco de dados
conn = sqlite3.connect('birthdays.db', check_same_thread=False)
db = conn.cursor()

# Rota principal
@app.route('/', methods=['GET', 'POST'])
def index():
    if request.method == 'POST':
        # Obtém os dados do formulário
        name = request.form.get('name')
        month = request.form.get('month')
        day = request.form.get('day')

        # Insere o novo aniversário no banco de dados
        db.execute('INSERT INTO birthdays (name, month, day) VALUES (?, ?, ?)', (name, month, day))
        conn.commit()

        # Redireciona de volta para a página principal
        return redirect('/')

    else:
        # Obtém todos os aniversários do banco de dados
        db.execute('SELECT * FROM birthdays')
        birthdays = db.fetchall()

        # Renderiza o template index.html com os dados dos aniversários
        return render_template('index.html', birthdays=birthdays)

if __name__ == '__main__':
    app.run()
