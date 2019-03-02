
#define LDR_PIN A0 
#define LED_PIN 11
#define BUZZER_PIN 12

unsigned int LDR_value; 

void setup()
{
  Serial.begin(9600);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop()
{
  LDR_value = analogRead(LDR_PIN); 
  Serial.print("Light Voltage: "); 
  Serial.println(LDR_value);
  if(LDR_value > 800)
    digitalWrite(LED_PIN,HIGH);
  else
    digitalWrite(LED_PIN, LOW);
  if(LDR_value < 400)
    tone(BUZZER_PIN,1000);
  else
    noTone(BUZZER_PIN);
  delay(500); 
}
