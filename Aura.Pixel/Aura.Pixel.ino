// Definição dos pinos do driver L298N
#define ENA 9 // Velocidade do motor esquerdo
#define IN1 8 //  Direção do motor esquerdo
#define IN2 7
#define ENB 10 // Velociade do motor direito
#define IN3 6 // Direção do motor direito
#define IN4 5

void setup() {
    pinMode(ENA, OUTPUT);
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(ENB, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT)
}

void loop() {
    moverFrente();
    delay(2000);
    parar();
    delay(1000);
    moverTras();
    delay(2000)
    parar();
    delay(1000);
    girarEsquerda();
    delay(1000);
    girarDireita();
    delay(1000);
    parar();
    delay(1000);
}

void moverFrente() {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analoglWrite(ENA, 150);
    analogWrite(ENB, 150);
}

void moverTras() {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENA, 150);
    analogWrite(ENB, 150);
}

void girarESqurda() {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    digitalWrite(ENA, 150);
    digitalWrite(ENB, 150);
}

void girarDireita() {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(ENA, 150);
    analogWrite(ENB, 150);
}

void parar() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
