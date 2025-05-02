/*
Semáforo Em Arduino com 3 leds!
LED Vermelho no pino 13
LED Amarelo no pino 12
LED Verde no pino 11

Autor: Daniel Morais - www.bratec.corporation.com.sp.br
Data: 9/04/2025

*/

#define ledVermelho 13
#define ledAmarelo 12
#define ledVerde 11



void setup() {
  pinMode (ledVermelho, OUTPUT);
  pinMode (ledAmarelo, OUTPUT);
  pinMode (ledVerde, OUTPUT);
}

void loop() {

digitalWrite(ledVermelho,1); //liga led vermelho
delay(30000); //espera 30s
digitalWrite(ledVermelho,0); //desliga led vermelho
digitalWrite(ledVerde,1);//liga led verde

delay(30000); //espera 30s
digitalWrite(ledVerde,0);//desliga led verde
digitalWrite(ledAmarelo,1); //acende led Amarelo

delay(5000); //espera 5s
digitalWrite(ledAmarelo,0); //apaga led Amarelo
}
