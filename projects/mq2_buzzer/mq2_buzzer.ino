
#define MQ2_PIN A0 
#define LED_PIN 11
#define BUZZER_PIN 12

void setup()
{
Serial.begin(9600);
pinMode(BUZZER_PIN, OUTPUT);
pinMode(LED_PIN, OUTPUT);
}

void loop()
{
int data = analogRead(MQ2_PIN);
Serial.print("Gas Intensity: "); 
Serial.println(data);
if(data > 900)
{
  digitalWrite(LED_PIN,HIGH);
  tone(BUZZER_PIN,1000);
}
else
{
  digitalWrite(LED_PIN, LOW);
  noTone(BUZZER_PIN);
}
delay(500); 
}
