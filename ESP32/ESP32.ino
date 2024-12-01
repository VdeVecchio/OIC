#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "VIVOFIBRA";
const char* password = "V20052003V20052003";

const char* mqttServer = "192.168.15.4";
const int mqttPort = 1883;
const char* mqttUser = "";
const char* mqttPassword = "";

HardwareSerial SerialPort(2);

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  SerialPort.begin(9600, SERIAL_8N1, 16, 17);
  Serial.begin(115200);

  Serial.println("Conectando ao Wi-Fi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("\nWi-Fi conectado!");

  client.setServer(mqttServer, mqttPort);

  connectToMQTT();
}

void loop() {
  if (!client.connected()) {
    connectToMQTT();
  }
  client.loop();

  if (SerialPort.available()) {
    String data = SerialPort.readStringUntil('\n');
    Serial.print("Dados recebidos do Arduino Nano: ");
    Serial.println(data);

    char message[50];
    snprintf(message, 50, "Nivel de agua: %s cm", data.c_str());
    client.publish("sensor/agua", message);
    Serial.println("Mensagem enviada ao broker MQTT.");
  }

  delay(500);
}

void connectToMQTT() {
  while (!client.connected()) {
    Serial.println("Conectando ao broker MQTT...");
    if (client.connect("ESP32Client", mqttUser, mqttPassword)) {
      Serial.println("Conectado ao broker MQTT!");
    } else {
      Serial.print("Falha na conexão. Código: ");
      Serial.println(client.state());
      delay(2000);
    }
  }
}
