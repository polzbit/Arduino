/* Made by Bar Polyak */
#include "VirtualWire.h"
#include  <Adafruit_GFX.h>  
#include "SWTFT.h"

#define LCD_CS A3 
#define LCD_CD A2 
#define LCD_WR A1 
#define LCD_RD A0 
#define ledPin 52
#define RX_PIN 51 // reciver recive pin
#define SPEED 2000 // bits per secound

SWTFT tft; // touch screen object

int RX_ID = 3;// Recever ID address 
int TX_ID;
typedef struct rowData //Data Structure 
{
int    TX_ID;      // Initialize a storage place for the incoming TX ID  
int    Sensor1Data;// Initialize a storage place for the first integar that you wish to Receive 
int    Sensor2Data;// Initialize a storage place for the Second integar that you wish to Receive
int    Sensor3Data;// Initialize a storage place for the  Third integar that you wish to Receive
int    Sensor4Data;// Initialize a storage place for the Forth integar that you wish to Receive

};
void setup()
{
  Serial.begin(9600);

  /* initilize radio reciver */
  vw_set_ptt_inverted(true); // Required for DR3100
  vw_set_rx_pin(RX_PIN);
  vw_setup(SPEED); // Bits per sec
  pinMode(ledPin, OUTPUT);
  vw_rx_start(); // Start the receiver PLL running
  /* initilize touch screen */
  Serial.println("TFT LCD Shield Test");
  tft.reset();
  uint16_t identifier = tft.readID();
  Serial.println("------------------------------------------------------");
  Serial.print("Your LCD driver chip name is: ");
  Serial.println(identifier, HEX);
  tft.begin(identifier);
  Serial.println("Working Well");
  Serial.println("------------------------------------------------------");
}
void loop()
{
  uint8_t rotation=2;

  
  //testText();
  delay(2000);
  struct rowData receivedData;
  uint8_t rcvdSize = sizeof(receivedData);//Incoming data size 
  vw_wait_rx();// Start to Receive data now 
  if (vw_get_message((uint8_t *)&receivedData, &rcvdSize)) // Check if data is available 
  {
    Serial.println(receivedData.TX_ID);
    if (receivedData.TX_ID == RX_ID) 
    {
       // If data was Recieved print it to the serial monitor.
         Serial.println("------------------------New MSG-----------------------");
         Serial.print("TX ID:");
         Serial.println(receivedData.TX_ID);
         Serial.print("Humidity:");
         Serial.println(receivedData.Sensor1Data);
         Serial.print("Temperature:");
         Serial.println(receivedData.Sensor2Data);
         Serial.print("Light Intensity:");
         Serial.println(receivedData.Sensor3Data);
         Serial.print("SensorData4:");
         Serial.println(receivedData.Sensor4Data);
         Serial.println("-----------------------End of MSG--------------------");
    } 
    else
    { 
      Serial.println(" ID Does not match waiting for next transmission ");
    } 
  }
  tft.setRotation(rotation);
  tft.fillScreen(0x0000);
  tft.setCursor(0, 0);
  tft.println();
  tft.setTextColor(0x2dff);  
  tft.setTextSize(2);
  tft.print("Humidity: ");
  tft.println(receivedData.Sensor1Data);
  tft.println();
  tft.setTextColor(0xb42d0e);  
  tft.setTextSize(2);
  tft.print("Temperature: ");
  tft.println(receivedData.Sensor2Data);
  tft.println();
  tft.setTextColor(0xf0ab44);  
  tft.setTextSize(2);
  tft.print("Light Intensity: ");
  tft.println(receivedData.Sensor3Data);
  tft.println();
}
  
unsigned long testText() {
  tft.fillScreen(0x0000);
  unsigned long start = micros();
  tft.setCursor(0, 0);
  tft.println();
  tft.setTextColor(0xFFFF);  
  tft.setTextSize(3);
  tft.println("Hello World!");
  tft.println();
  tft.setTextColor(0xFFE0); 
  tft.setTextSize(2);
  tft.println("A Yellow Text Here");
  tft.println();
  tft.setTextColor(0x07E0);
  tft.setTextSize(3);
  tft.println("A Green Text Here");
  return micros() - start;
}
