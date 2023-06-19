// Pergunta de múltipla escolha
const options = document.querySelectorAll('.option');

options.forEach(option => {
  option.addEventListener('click', () => {
    options.forEach(btn => {
      btn.classList.remove('correct', 'incorrect');
    });

    if (option.textContent === 'Brasília') {
      option.classList.add('correct');
      displayResult('Correto!');
    } else {
      option.classList.add('incorrect');
      displayResult('Incorreto');
    }
  });
});

// Pergunta de resposta livre
const answerInput = document.getElementById('answer');
const confirmBtn = document.getElementById('confirm');

confirmBtn.addEventListener('click', () => {
  const userAnswer = answerInput.value.toLowerCase();
  answerInput.classList.remove('correct', 'incorrect');

  if (userAnswer === 'júpiter') {
    answerInput.classList.add('correct');
    displayResult('Correto!');
  } else {
    answerInput.classList.add('incorrect');
    displayResult('Incorreto');
  }
});

function displayResult(result) {
  const resultDiv = document.createElement('div');
  resultDiv.textContent = result;

  if (result === 'Correto!') {
    resultDiv.classList.add('correct-answer');
  } else {
    resultDiv.classList.add('incorrect-answer');
  }

  document.body.appendChild(resultDiv);
}
