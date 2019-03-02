#include <Wire.h>
#include <SFE_BMP180.h>

#define ALTITUDE 35.6

SFE_BMP180 bmp180;

void setup() {
  Serial.begin(9600);
  if(bmp180.begin())
    Serial.println("BMP180 init sucess");
  else{
    Serial.println("BMP180 init fail");
    while(1);
  }
}

void loop() {
  char data;
  double temperature, pressure, relative_pressure;

  Serial.print("Your altitude: ");
  Serial.print(ALTITUDE, 0);
  Serial.println(" meters");

  data = bmp180.getTemperature();
  if(data != 0)
  {
    delay(data);
    data = bmp180.getTemperature(temperature);
    if(data != 0)
    {
      Serial.print("Temperature: ");
      Serial.print(temperature, 1);
      Serial.println(" deg C");
      data = bmp180.startPressure(3);
      if(data != 0)
      {
        delay(data);
        data = bmp180.getPressure(pressure, temperature);
        if(data != 0)
        {
          Serial.print("Pressure: ");
          Serial.print(pressure);
          Serial.println(" hPa");

          relative_pressure = bmp180.sealevel(pressure, ALTITUDE);
          Serial.print("Relative (sea-level) Pressure: ");
          Serial.print(relative_pressure);
          Serial.println("hPa");
        }
      }
    }
  }
  delay(1000);
}
