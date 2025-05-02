#include <Wire.h>        // Biblioteca para comunicação I2C
#include <RTClib.h>      // Biblioteca para o módulo RTC (DS1307, DS3231, etc.)
#include <LiquidCrystal.h> // Biblioteca para display LCD

// Define os pinos do LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Cria um objeto RTC_DS3231
RTC_DS3231 rtc;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  rtc.begin();
  lcd.begin(16, 2);
  lcd.print("Relogio Arduino");
  lcd.setCursor(0, 1);
  lcd.print("Inicializando...");

  // Se precisar ajustar a hora pela primeira vez, descomente as linhas abaixo
  // rtc.adjust(DateTime(2025, 4, 17, 19, 55, 0)); // Ano, Mes, Dia, Hora, Minuto, Segundo
}

void loop() {
  DateTime now = rtc.now();

  lcd.clear();
  lcd.print(now.hour());
  lcd.print(":");
  if (now.minute() < 10) {
    lcd.print("0");
  }
  lcd.print(now.minute());
  lcd.print(":");
  if (now.second() < 10) {
    lcd.print("0");
  }
  lcd.print(now.second());

  lcd.setCursor(0, 1);
  lcd.print(now.day());
  lcd.print("/");
  lcd.print(now.month());
  lcd.print("/");
  lcd.print(now.year());

  delay(1000); // Atualiza a cada segundo
}