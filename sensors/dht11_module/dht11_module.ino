#include <dht.h>

#define DHT11_PIN 10

dht DHT;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  DHT.read11(DHT11_PIN);
  Serial.print("Humidity: ");
  Serial.println(DHT.humidity,1);
  Serial.print("Temperature: ");
  Serial.println(DHT.temperature,1);
  delay(2000);
}
