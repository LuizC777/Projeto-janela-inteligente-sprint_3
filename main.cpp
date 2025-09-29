#include <WiFi.h>
#include <ESP32Servo.h>
#include <WiFiClient.h> 
#include <HTTPClient.h>
#include <WebServer.h>

// ==== CONFIG WIFI PRINCIPAL ====
const char* ssid1 = "Wifi";       
const char* password1 = "Senha Wifi";  

// ==== CONFIG HOTSPOT ====
const char* ssid2 = "Hotspot";       
const char* password2 = "Senha Hotspot";

// ==== CONFIG SERVO ====
Servo servoMotor;
int servoPin = 18;   // GPIO 18 do ESP32
int angleClosed = 0; // posição de fechamento
int angleOpen = 90;  // posição de abertura

// ==== SERVIDOR LOCAL ====
WiFiServer server(80);

// ==== FUNÇÃO PARA CONECTAR WIFI ====
void conectaWiFi() {
  Serial.println("Tentando conectar no Wi-Fi principal...");
  WiFi.begin(ssid1, password1);

  unsigned long start = millis();
  while (WiFi.status() != WL_CONNECTED && millis() - start < 10000) {
    delay(500);
    Serial.print(".");
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nConectado no Wi-Fi principal!");
    return;
  }

  Serial.println("\nFalhou no Wi-Fi principal, tentando Hotspot...");
  WiFi.begin(ssid2, password2);

  start = millis();
  while (WiFi.status() != WL_CONNECTED && millis() - start < 10000) {
    delay(300); // 500
    Serial.print(".");
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nConectado no Hotspot!");
  } else {
    Serial.println("\nFalha total, sem rede.");
  }
}

// ==== FUNÇÕES DO SERVO ====
void abrirJanela() {
  servoMotor.write(angleOpen);
  Serial.println("Janela ABERTA");
}

void fecharJanela() {
  servoMotor.write(angleClosed);
  Serial.println("Janela FECHADA");
}

// ==== SETUP ====
void setup() {
  Serial.begin(115200);

  // Conectar Wi-Fi
  conectaWiFi();

  if (WiFi.status() == WL_CONNECTED) {
    Serial.print("IP Local: ");
    Serial.println(WiFi.localIP());
  }

  // Configurar Servo
  servoMotor.attach(servoPin);
  servoMotor.write(angleClosed); // começa fechado

  // Iniciar servidor web
  server.begin();
  Serial.println("Servidor iniciado.");
}

// ==== LOOP ====
void loop() {
  WiFiClient client = server.available();
  if (!client) return;

  String request = client.readStringUntil('\r');
  client.flush();

  if (request.indexOf("/abrir") != -1) {
    abrirJanela();
  }
  if (request.indexOf("/fechar") != -1) {
    fecharJanela();
  }

  // ==== RESPOSTA HTTP ====
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("Connection: close");   // encerra conexão
  client.println();
  client.println("<h1>Controle da Janela</h1>");
  client.println("<p><a href=\"/abrir\"><button>Abrir</button></a></p>");
  client.println("<p><a href=\"/fechar\"><button>Fechar</button></a></p>");
  client.println();

  // Fecha o cliente
  client.stop();
} 
