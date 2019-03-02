#define MQ2_A0_PIN A0
#define MQ2_D0_PIN 7

void setup() {
  Serial.begin(9600);
}

void loop() {
  int data = analogRead(MQ2_A0_PIN);
  int limit = digitalRead(MQ2_D0_PIN);
  Serial.print("Gas intensity: ");
  Serial.println(data);
  Serial.print("Limit State: ");
  Serial.println(limit);
  delay(1000);
}
