#include <DHT.h>

// Definição dos pinos
#define DHTPIN 4  
#define DHTTYPE DHT22 
#define RELE_PIN 2    

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  Serial.println("Iniciando controle de bomba com DHT22");
  dht.begin();
  pinMode(RELE_PIN, OUTPUT); 
  digitalWrite(RELE_PIN, LOW);
  Serial.println("Relé DESLIGADO");
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
    digitalWrite(RELE_PIN, HIGH); 
    Serial.println("Umidade abaixo de 50%, Bomba LIGADA (Relé ATIVADO)");
  } else {
    digitalWrite(RELE_PIN, LOW); 
    Serial.println("Umidade igual ou acima de 50%, Bomba DESLIGADA (Relé DESATIVADO)");
  }
}