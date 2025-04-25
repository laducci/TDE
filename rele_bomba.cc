#define RELE_PIN 2
#define BOMBA_LED_PIN 16

void setup() {
  Serial.begin(115200);
  Serial.println("Testando Relé e Bomba (Simulada)");
  pinMode(RELE_PIN, OUTPUT);   
  pinMode(BOMBA_LED_PIN, OUTPUT); 
  digitalWrite(RELE_PIN, LOW);    
  digitalWrite(BOMBA_LED_PIN, LOW); 
  Serial.println("Relé DESLIGADO, Bomba DESLIGADA");
}

void loop() {
  Serial.println("Ligando Relé e Bomba...");
  digitalWrite(RELE_PIN, HIGH);    
  digitalWrite(BOMBA_LED_PIN, HIGH); 
  Serial.println("Relé LIGADO, Bomba LIGADA");
  delay(3000); // Espera 3 segundos

  Serial.println("Desligando Relé e Bomba...");
  digitalWrite(RELE_PIN, LOW);     
  digitalWrite(BOMBA_LED_PIN, LOW);  
  Serial.println("Relé DESLIGADO, Bomba DESLIGADA");
  delay(3000); 
}