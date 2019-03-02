#include  <Adafruit_GFX.h>  
#include "SWTFT.h"
#include <VirtualWire.h>

#define LCD_CS A3 
#define LCD_CD A2 
#define LCD_WR A1 
#define LCD_RD A0 
#define ledPin 52
#define RX_PIN 24 // reciver recive pin
#define SPEED 2000 // bits per secound

/* Create a structure for the packet. 27 Bytes MAX
   The structure below is just an example showing
   27 Bytes split up into various variable lengths.
   The structure could be Strings or you could just
   forget using a structure and use a byte array and
   fill it with whatever you want. Smaller packets
   are less prone to corruption!
*/
struct PacketData{
  uint32_t data0_3;     // some data
  uint32_t data4_7;    // some more data
  uint32_t dummy8_11;   // 4 Byte packet filler
  uint32_t dummy12_15;   // 4 Byte packet filler
  uint32_t dummy16_19;   // 4 Byte packet filler
  uint32_t dummy20_23;   // 4 Byte packet filler
  uint16_t dummy24_25;   // 2 Byte packet filler
  uint8_t packetCount26;   // packet sequence counter
}
payload;

SWTFT tft;

uint8_t RxBuffer[sizeof(payload)];      // set up RX buffer
//uint8_t Buffer_Size = sizeof(payload);  // set the Buffer_Size variable
uint8_t lastCount = 0;                 // create a counter for the packet sequence
uint32_t lostPackets = 0;               // counter for missed packets

void setup(void) {
  Serial.begin(9600);
    // sets the digital pin as output
   pinMode(ledPin, OUTPUT);      
   // VirtualWire 
   vw_set_ptt_inverted(true); // Required for DR3100
   // Setting RX Pin
   vw_set_rx_pin(RX_PIN);  
   // Bits per sec
   vw_setup(SPEED);   
   // Start the receiver PLL running
   vw_rx_start(); 
   
  Serial.println("TFT LCD Shield Test");
  tft.reset();
  uint16_t identifier = tft.readID();
  Serial.print("Your LCD driver chip name is: ");
  Serial.println(identifier, HEX);
  tft.begin(identifier);
  Serial.println("Working Well");
}
void loop(void) {
  uint8_t rotation=1;
  
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;
  // Non-blocking
   if (vw_have_message())  // Is there a packet for us? 
  {
    vw_get_message(RxBuffer, sizeof(RxBuffer));  // get the packet into the buffer
    memcpy(&payload,&RxBuffer,sizeof(RxBuffer));   // copy the buffer to the packet structure
      digitalWrite(ledPin, HIGH);              // turn the LED on
      // print the results
      Serial.print("Payload Size: ");
      Serial.print(sizeof(RxBuffer));
      Serial.print(" Bytes");
      Serial.print("\tData: ");
      Serial.print(payload.data0_3);
      Serial.print("\tSequence Count: ");
      Serial.print(payload.packetCount26);
      Serial.print("\tLost Packets: ");
      Serial.print(lostPackets);
      // check the packet sequence is correct
      if((payload.packetCount26 - lastCount) > 1){
        Serial.print("\t");
        Serial.print("Packet Lost!");
        lostPackets++;
      }
      lastCount = payload.packetCount26;
      Serial.println();
      digitalWrite(ledPin, LOW);  // turn the LED off
  }
  tft.setRotation(rotation);
  //testText();
  delay(2000);
  
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
