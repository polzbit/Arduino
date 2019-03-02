#define LDR_PIN A0
#define BUZZER_PIN 49

unsigned int LDRvalue;

void setup()
{
  Serial.begin(9600);
  pinMode(LDR_PIN,INPUT);
  pinMode(BUZZER_PIN,OUTPUT);
}

void loop()
{
  LDRvalue = analogRead(LDR_PIN);
  if(LDRvalue > 500) {
    Serial.println("Light is Low");
    digitalWrite(BUZZER_PIN, HIGH);
  }
  else {
    digitalWrite(BUZZER_PIN, LOW);
  }
  delay(50);
}
