const int botaoSim = 2;
const int botaoNao = 3;

const int ledSim = 4;
const int ledNao = 5;
const int ledTalvez = 6;
const int ledNaoSei = 7;

void setup() {
  pinMode(botaoSim, INPUT_PULLUP);
  pinMode(botaoNao, INPUT_PULLUP);

  pinMode(ledSim, OUTPUT);
  pinMode(ledNao, OUTPUT);
  pinMode(ledTalvez, OUTPUT);
  pinMode(ledNaoSei, OUTPUT);
}

void loop() {
  // Lógica para decidir a resposta
  // Por exemplo, você pode usar um gerador de números aleatórios:
  int respostaAleatoria = random(4);

  // Acender o LED correspondente à resposta
  switch (respostaAleatoria) {
    case 0:
      digitalWrite(ledSim, HIGH);
      break;
    case 1:
      digitalWrite(ledNao, HIGH);
      break;
    case 2:
      digitalWrite(ledTalvez, HIGH);
      break;
    case 3:
      digitalWrite(ledNaoSei, HIGH);
      break;
  }

  // Esperar um tempo e apagar todos os LEDs
  delay(2000);
  digitalWrite(ledSim, LOW);
  digitalWrite(ledNao, LOW);
  digitalWrite(ledTalvez, LOW);
  digitalWrite(ledNaoSei, LOW);
}
