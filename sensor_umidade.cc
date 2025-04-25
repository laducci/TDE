#include <DHT.h>

// Definição dos pinos
#define DHTPIN 4
#define DHTTYPE DHT22 
#define LED_VERDE 2 

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  Serial.println("Iniciando leitura do DHT22...");
  dht.begin();
  pinMode(LED_VERDE, OUTPUT);
}

void loop() {
  delay(2000);

  float h = dht.readHumidity();

  if (isnan(h)) {
    Serial.println("Falha ao ler o sensor DHT!");
    return;
  }

  Serial.print("Umidade: ");
  Serial.print(h);
  Serial.println(" %");

  if (h < 50) {
    digitalWrite(LED_VERDE, HIGH); 
    Serial.println("Umidade abaixo de 50%, LED verde ACESO");
  } else {
    digitalWrite(LED_VERDE, LOW);
    Serial.println("Umidade igual ou acima de 50%, LED verde APAGADO");
  }
}