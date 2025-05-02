#include <WiFi.h>
#include <WebServer.h>

WebServer server(80);

void handleRoot() {
  server.send(200, "text/plain", "ESP32 funcionando como ponto de acesso!");
}

void setup() {
  Serial.begin(115200);
  
  // Modo AP + STA
  WiFi.mode(WIFI_AP_STA);
  WiFi.begin("SUA_REDE", "SENHA");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  WiFi.softAP("ESP32_AP", "12345678");

  // Inicia o servidor
  server.on("/", handleRoot);
  server.begin();
  Serial.println("Servidor iniciado.");
}

void loop() {
  server.handleClient();  // Atende requisições HTTP dos clientes
}
