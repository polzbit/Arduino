#include <SoftwareSerial.h> // softwareSerial Library


SoftwareSerial BT(2, 3); // bluetooth object
// Connect the HC-05 TX to Arduino pin 2 RX. 
// Connect the HC-05 RX to Arduino pin 3 TX through a voltage divider.

/** input/output pins initialize **/
char data = ' '; // char from terminal
int in1 = 6;  // motorA D6 pin
int in2 = 7;  // motorA D7 pin
int in3 = 8;  // motorB D8 pin
int in4 = 9;  // motorB D9 pin
int fan = 11; // Fan D11 pin
int flameSens = 12; // Flame Sensor D12 pin\

/** data val initialize **/
int detect;
int state;

/** Setup **/
void setup() 
{
    Serial.begin(9600); // Serial bit rate initialize
    pinMode(in1, OUTPUT); // set D6 as Output
    pinMode(in2, OUTPUT);// set D7as Output
    pinMode(in3, OUTPUT);// set D8as Output
    pinMode(in4, OUTPUT);// set D9as Output
    pinMode(flameSens, INPUT); // set D10 as Input
    pinMode(fan, OUTPUT);// set D11 as output
    BT.begin(9600);   // HC-05 default serial speed for communcation mode is 9600
}
 /** infinite Loop **/
void loop() 
{
  /** Get Data **/
    data = BT.read(); // get commend from bluetooth
    detect = digitalRead(flameSens); // get state from flame sensor

    /** if no fire detection **/
    if(detect==1){
      digitalWrite(fan,LOW); // keep fan off

      /** go left **/
      if(data=='a'){
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
        state = data;
      }
      /** go down **/
      else if(data=='s'){
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
        state = data;
      }
    /** go right **/
      else if(data=='d'){
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);
        state = data;
      }
      /** go up **/
      else if(data=='w'){
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);
        state = data;
      }
      /** brake **/
      else if(data =='b'){
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, LOW);
        state = data;
      }
    }
   /** if fire detected **/
   /** motors off and turn on fan **/
    else if(detect==0){
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, LOW);
        digitalWrite(fan,HIGH);
      }
    
    delay(50); 
}
