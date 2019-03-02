#define SENSOR_PIN  2
#define LED_PIN 3

void setup() 
{
  pinMode (SENSOR_PIN, INPUT);
  pinMode (LED_PIN, OUTPUT);
}

void loop()
{
  int statusSensor = digitalRead (SENSOR_PIN);
 
  if (statusSensor == 1)
  {
    digitalWrite(LED_PIN, HIGH);
  }
  else
  {
    digitalWrite(LED_PIN, LOW);
  }
}
