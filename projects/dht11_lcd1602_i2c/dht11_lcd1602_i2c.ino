#include "Wire.h"
#include "LCD.h"
#include "LiquidCrystal_I2C.h"
#include <dht.h>

dht DHT;

#define DHT11_PIN 12
#define I2C_ADDR 0x3f  // Add your address here.
#define Rs_pin 0
#define Rw_pin 1
#define En_pin 2
#define BACKLIGHT_PIN 3
#define D4_pin 4
#define D5_pin 5
#define D6_pin 6
#define D7_pin 7
LiquidCrystal_I2C lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin); 
void setup()
{
  pinMode(13,OUTPUT);
  digitalWrite(13,HIGH);
  lcd.begin (16,2); //  our LCD is a 20x4, change for your LCD if needed
  pinMode(DHT11_PIN,INPUT);
  // LCD Backlight ON
  lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
  lcd.setBacklight(HIGH);

  lcd.home ();
  Serial.begin(9600);
}
 
void loop()
{
// set cursor to first line
  lcd.setCursor(0, 0);

// Print a message to the LCD.

  // READ DATA
  Serial.print("DHT11, \t");
  int chk = DHT.read11(DHT11_PIN);
  switch (chk)
  {
    case DHTLIB_OK:  
    Serial.print("OK,\t"); 
    break;
    case DHTLIB_ERROR_CHECKSUM: 
    Serial.print("Checksum error,\t"); 
    break;
    case DHTLIB_ERROR_TIMEOUT: 
    Serial.print("Time out error,\t"); 
    break;
    default: 
    Serial.print("Unknown error,\t"); 
    break;
  }
 // DISPLAY DATA
  lcd.print("Humidity:");
  lcd.print(DHT.humidity,1);
  lcd.setCursor(0, 1);
  lcd.print("Temperature:");
  lcd.print(DHT.temperature,1);

  delay(1000);
}
