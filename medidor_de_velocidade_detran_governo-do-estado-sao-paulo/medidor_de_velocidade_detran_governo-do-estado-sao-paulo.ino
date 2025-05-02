/*
      CÓDIGO: Q0727
      AUTOR: Daniel de Morais
      YOUTUBE: https://www.youtube.com/@DanielMoraisSoares-j1g
      APRENDA: https://cursodearduino.net/ ; https://cursoderobotica.net
      COMPRE: https://www.arducore.com.br/
      SKETCH: Radar de Velocidade
      DATA: 12/04/2025
*/

#include <LiquidCrystal_I2C.h>

// DEFINIÇÕES DE PINOS
#define pinLdrA A0
#define pinLdrB A1

//DEFINIÇÕES
#define valA 900
#define valB 900

#define DISTANCIA 0.20 // DISTANCIA ENTRE OS SENSORES EM METROS

// INSTANCIANDO OBJETOS
LiquidCrystal_I2C lcd(0x27, 16, 2);

// DECLARAÇÃO DE VARIÁVEIS
int estadoLdrA;
int estadoLdrB;
int estadoLdrAAnt;
int estadoLdrBAnt;

int estadoContagem;   //0=standby 1=contandoA 2=contandoB 3=Fim contagem

unsigned long tempoA;
unsigned long tempoB;

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();

  pinMode(pinLdrA, INPUT);
  pinMode(pinLdrB, INPUT);

  estadoLdrAAnt = analogRead(pinLdrA);
  estadoLdrBAnt = analogRead(pinLdrB);

  estadoContagem = 0;

  Serial.println("Fim do setup()");
}

void loop() {
  estadoLdrA = analogRead(pinLdrA);
  estadoLdrB = analogRead(pinLdrB);

  if (estadoContagem == 2) {
    if (estadoLdrA <= valA && estadoLdrAAnt > valA) {
      tempoB = millis();
      estadoContagem = 3;
      delay(tempoB - tempoA); //aguarda para filtrar o efeito bouncing
    }
  }

  if (estadoContagem == 1) {
    if (estadoLdrB <= valB && estadoLdrBant > valB) {
      tempoB = millis();
      estadoContagem = 3;
      delay(tempoB - tempoA); //aguarda para filtrar o efeito bouncing
    }
  }

  if (estadoContagem == 0) {
    if (estadoLdrA <= valA && estadoLdrAAnt > valA) {
      tempoA = millis();
      estadoContagem = 1;
    }
  
    if (estadoLdrB <= valB && estadoLdrBAnt > valb) {
      tempoA = millis();
      estadoContagem = 2;
    }
  }

  if (estadoContagem == 3) {
    float intervalo = (float)(tempoB - tempoA) / 1000.0; // INTERVALO EM SEGUNDOS
    Serial.print("Tempo: ");
    Serial.print(intervalo);
    Serial.print(" segundos");

    float velocidade = DISTANCIA / intervalo; // velocidade em METROS/SEGUNDOS

    Serial.print("Velocidade: ");
    Serial.print(velocidade, 2);
    Serial.print(" m/s");

    lcd.print("Velocidade: ");
    lcd.print(velocidade, 2);
    lcd.print(" m/s");

    lcd.setCursor(0, 1);

    velocidade = (float)(DISTANCIA / 1000.0) / (float)(intervalo / 3600.0); // velocidade em KM/H

    Serial.print("Velocidade: ");
    Serial.print(velocidade, 2);
    Serial.print(" km/h");

    lcd.print("Velocidade: ");
    lcd.print(velocidade, 2);
    lcd.print(" km/h");

    delay(5000); // intervalo entre leituras;

    lcd.clear();

    tempoA = 0;
    tempoB = 0;

    estadoContagem = 0;
  }

  estadoLdrAAnt = estadoLdrA;
  estadoLdrBAnt = estadoLdrB;
}

// IMPLEMENTO DE FUNÇÕES
