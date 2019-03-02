
#include "LiquidCrystal_I2C.h"

#define MOIST_SENSOR_PIN A0 

LiquidCrystal_I2C lcd(0x3F,2,1,0,4,5,6,7, 3, POSITIVE);

void setup()
{
Serial.begin(9600);
lcd.begin(16,2);
lcd.backlight();
}

void loop()
{
int data = analogRead(MOIST_SENSOR_PIN);
lcd.setCursor(0,0);
lcd.print("Moisture Data: "); 
lcd.println(data);

delay(500); 
}
