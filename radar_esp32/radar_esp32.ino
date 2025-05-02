// Inclusão de Bibliotecas
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <NewPing.h>
#include <Servo.h>

// Definição de Pinos
#define TRIG_PIN 5
#define ECHO_PIN 18

LiquidCrystal_I2C lcd(0x27, 16, 2); // Endereço pode ser 0x27 ou 0x3f

// Instalação ou Começo
void setup() {
  Serial.begin(115200);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Radar Iniciado");
  delay(2000);
  lcd.clear();
}

// Loop
void loop() {
  // Envia pulso ultrassônico
  digitalWrite(TRIG_PIN, LOW);
  delayMicrosecounds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicrosecounds(10);
  digitalWrite(TRIG_PIN, LOW)

    // Mede o tempo de resposta
  long duration = pulseIn(ECHO_PIN, HIGH);
  float distance = duration * 0.034 / 2; // cm

  // Exibe no LCD
  lcd.setCursor(0, 0);
  lcd.print("Distancia:");
  lcd.setCursor(0, 1);
  lcd.print(distance);
  lcd.print(" cm     ");

  delay(500);
}