// Inclusão da biblioteca wifi
#include <Wifi.h>

// Configurações de rede Wi-Fi existente
const char* ssid_sta = "WIFI_BRATEC_ESP32";
const char* password_sta = "bratecarduinoesp32nanouno";

// Configuração de ponto de acesso (AP)
const char* ssid_ap = "ESP32_BRATEC_WIFI_AP";
const char* password_ap = "bratecarduinoesp32nanouno";

// Instalação ou Começo
void setup() {
  Serial.begin(115200);

  // Modo AP + STA
  WiFi.mode(WIFI_AP_STA);

  // Conecta-se á rede Wi-Fi existente
  WiFi.begin(ssid_sta, password_sta);
  Serial.println("Conectando à rede Wi-Fi...");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConectado à rede Wi-Fi como STA:");
  Serial.println(WiFi.localIP());

  // Cria a rede do ponto de acesso
  WiFi.softAP(ssid_ap, password_ap);
  Serial.println("Ponto de acesso criado:");
  Serial.println(WiFi.softAPIP());
}

// loop
void loop() {
  wifi_sta_list_t stationList;
  tcpip_adapter_sta_list_t adapterList;

  if (esp_wifi_ap_get_sta_list(&stationList) == ESP_OK &&
      tcpip_adapter_get_sta_list(&stationList, &adapterList) == ESP_OK) {
    
    Serial.printf("Clientes conectados: %d\n", adapterList.num);
    for (int i = 0; i < adapterList.num; i++) {
      Serial.printf("IP: %s\n", ip4addr_ntoa(&adapterList.sta[i].ip));
    }
  }

  delay(5000); // Espera 5 segundos antes de checar novamente
}