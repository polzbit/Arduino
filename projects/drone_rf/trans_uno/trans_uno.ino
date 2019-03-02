/* Made by Bar Polyak */
#include <dht.h>
#include "VirtualWire.h"

#define DHT11_PIN 3
#define TX_PIN 12 // transmitter tx pin
#define ledPin 8
#define SPEED 2000 // data baud rate bits per 
#define LDR_PIN A0 // light-diode ressistor pin

dht DHT;
int TX_ID = 3;

typedef struct rowData// Data Structure 
{
int    TX_ID;      // Initialize a storage place for the outgoing TX ID
int    Sensor1Data;// Initialize a storage place for the first integar that you wish to Send 
int    Sensor2Data;// Initialize a storage place for the Second integar that you wish to Send
int    Sensor3Data;// Initialize a storage place for the Third integar that you wish to Send
int    Sensor4Data;// Initialize a storage place for the Forth integar that you wish to Send

};

void setup() {
  //digitalWrite(13,HIGH); //trans vcc
  Serial.begin(9600); // initite Serial
  pinMode(ledPin,OUTPUT); // led pin
  vw_set_ptt_inverted(true);  // must be declared
  vw_set_tx_pin(TX_PIN); // initite TX pin
  vw_setup(SPEED);// speed of data transfer Kbps
}

void loop(){
  struct rowData payload;// In this section is where you would load the data that needs to be sent.
  // Read LDR data
  Serial.print(" LDR Value: ");
  Serial.print(analogRead(LDR_PIN));
  // Read DHT data
  DHT.read11(DHT11_PIN);
  // Display DHT data via Serial
  Serial.print(" Humidity: ");
  Serial.print(DHT.humidity);
  Serial.print(" Temperature: ");
  Serial.print(DHT.temperature,1);
  Serial.println();
  // Send data via radio transmiter
  
  // If you want to read a analog pin and transmit its value you can do it as follows by removing the "//" 
  payload.TX_ID = TX_ID; // Set the Radio Address 
  payload.Sensor1Data = DHT.humidity;// analogRead(Sensor1Pin);
  payload.Sensor2Data =DHT.temperature;// analogRead(Sensor2Pin);
  payload.Sensor3Data =analogRead(LDR_PIN);
  payload.Sensor4Data =1;// analogRead(Sensor4Pin);
 
  
  
  vw_send((uint8_t *)&payload, sizeof(payload)); // Send the data 
  vw_wait_tx();// Wait for all data to be sent 
  delay(1000);
}



