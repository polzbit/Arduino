#include "LedControlMS.h"
#include <TimeLib.h>

/*
Configuring the LEDMatrix:
Digital 12 is conneted to DIN (Data IN)
Digital 11 is connected to CLK (CLocK)
Digital 10 is connected to CS (LOAD)
5V is connected to VCC
GND is connected to GND
There is only four MAX7219 display module.
*/
#define TIME_HEADER  "T"   // Header tag for serial time sync message
#define TIME_REQUEST  7    // ASCII bell character requests a time sync message 
#define NBR_MTX 4

LedControl lc=LedControl(12,11,10, NBR_MTX);

String device_time= " TIME";

int letterCounter=0;
/* wait time between updates of the display */
unsigned long delaytime=500;

void setup() { // initalizes and sets up the initial values. Declaring function setup.
  /* The display module is in power-saving mode on startup.
  Do a wakeup call */
  Serial.begin(9600); // setting data rate as 9600 bits per second for serial data communication to computer
  Serial.println("Setup"); //prints data to serial port as human-readable text
  letterCounter=0;
  for (int i=0; i< NBR_MTX; i++){
    lc.shutdown(i,false); //keep the screen on
    lc.setIntensity(i,8); // set brightness to medium values
    lc.clearDisplay(i); //clear the display after each letter
  }

  pinMode(13, OUTPUT);
  setSyncProvider( requestSync);  //set function to call when sync required
  Serial.println("Waiting for sync message");
}

void loop() { //declaring function loop
  if (Serial.available()){
    processSyncMessage();
  }
  if (timeStatus()!= timeNotSet) {
    digitalClockDisplay();  
  }
  if (timeStatus() == timeSet) {
    digitalWrite(13, HIGH); // LED on if synced
  } else {
    digitalWrite(13, LOW);  // LED off if needs refresh
  }
  delay(1000);

  lc.clearAll();
  device_time = " TIME";
  
  for(int i=NBR_MTX; i>= 0;i--){
  char ch= device_time[letterCounter]; //define character ch
  letterCounter++;
  
  if (letterCounter>4) letterCounter=0; //sets up loop
  lc.displayChar(i, lc.getCharArrayPosition(ch)); //display each character on the screen
  delay(delaytime);
}

  device_time = getTime();

  for(int i=NBR_MTX; i>= 0;i--){
  char ch= device_time[letterCounter]; //define character ch
  letterCounter++;
  
  if (letterCounter>4) letterCounter=0; //sets up loop
  lc.displayChar(i, lc.getCharArrayPosition(ch)); //display each character on the screen
  delay(delaytime);
  //lc.clearAll();
}

  device_time = " DATE";
  
  for(int i=NBR_MTX; i>= 0;i--){
  char ch= device_time[letterCounter]; //define character ch
  letterCounter++;
  
  if (letterCounter>4) letterCounter=0; //sets up loop
  lc.displayChar(i, lc.getCharArrayPosition(ch)); //display each character on the screen
  delay(delaytime);
}
  device_time = getDate();
  letterCounter=0;
  
  for(int i=NBR_MTX; i>= 0;i--){
  char ch= device_time[letterCounter]; //define character ch
  letterCounter++;
  
  if (letterCounter>4) letterCounter=0; //sets up loop
  lc.displayChar(i, lc.getCharArrayPosition(ch)); //display each character on the screen
  delay(delaytime);
}
  device_time = " YEAR";
  
  for(int i=NBR_MTX; i>= 0;i--){
  char ch= device_time[letterCounter]; //define character ch
  letterCounter++;
  
  if (letterCounter>4) letterCounter=0; //sets up loop
  lc.displayChar(i, lc.getCharArrayPosition(ch)); //display each character on the screen
  delay(delaytime);
}
  device_time = getYear();
  letterCounter=0;
  
  for(int i=NBR_MTX; i>= 0;i--){
  char ch= device_time[letterCounter]; //define character ch
  letterCounter++;
  
  if (letterCounter>4) letterCounter=0; //sets up loop
  lc.displayChar(i, lc.getCharArrayPosition(ch)); //display each character on the screen
  delay(delaytime);
}
}
void digitalClockDisplay(){
  // digital clock display of the time
  Serial.print(hour());
  printDigits(minute());
  printDigits(second());
  Serial.print(" ");
  Serial.print(day());
  Serial.print(" ");
  Serial.print(month());
  Serial.print(" ");
  Serial.print(year()); 
  Serial.println();
}

String getTime(){
  String str;
  if(minute() > 9 && hour() > 9)
    str = " " + String(hour()) + String(minute());
  if(minute() <= 9 && hour() >9)
    str = " " + String(hour()) +"0"+ String(minute());
  if(minute() > 9 && hour() <=9)
    str = " 0" + String(hour()) + String(minute());
  if(minute() <= 9 && hour() <=9)
    str = " 0" + String(hour()) +"0"+ String(minute());
  if(minute() == 0 && hour() >9)
    str = " " + String(hour()) + "00";
  if(minute() == 0 && hour() <=9)
    str = " 0" + String(hour()) +"00";
  if(minute() > 9 && hour() ==0)
    str = " 00" + String(minute());
  if(minute() <= 9 && hour() ==0)
    str = " 000"+ String(minute());
  if(minute()==0 && hour() ==0)
    str = " 0000"; 
  return str;
}

String getDate(){
  String str;
  if(month() > 9 && day() > 9)
    str = " " + String(day()) + String(month());
  if(month() <= 9 && day() >9)
    str = " 0" + String(day()) + String(month());
  if(month() > 9 && day() <=9)
    str = " " + String(day()) +"0"+ String(month());
  if(month() <= 9 && day() <=9)
    str = " 0" + String(day()) +"0"+ String(month());
  return str;
}

String getYear(){
  String str = " " + String(year());
  return str;
}
void printDigits(int digits){
  // utility function for digital clock display: prints preceding colon and leading 0
  Serial.print(":");
  if(digits < 10)
    Serial.print('0');
  Serial.print(digits);
}

void processSyncMessage() {
  unsigned long pctime;
  const unsigned long DEFAULT_TIME = 1357041600; // Jan 1 2013

  if(Serial.find(TIME_HEADER)) {
     pctime = Serial.parseInt();
     if( pctime >= DEFAULT_TIME) { // check the integer is a valid time (greater than Jan 1 2013)
       setTime(pctime); // Sync Arduino clock to the time received on the serial port
     }
  }
}
time_t requestSync()
{
  Serial.write(TIME_REQUEST);  
  return 0; // the time will be sent later in response to serial mesg
}


