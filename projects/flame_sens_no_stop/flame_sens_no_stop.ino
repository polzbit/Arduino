#include <SoftwareSerial.h>
SoftwareSerial BT(2, 3); // RX | TX
// Connect the HC-05 TX to Arduino pin 2 RX. 
// Connect the HC-05 RX to Arduino pin 3 TX through a voltage divider.
// 
 
char data = ' ';
int in1 = 6;
int in2 = 7;
int in3 = 8;
int in4 = 9;
int flameSens = 12;
int detect;
int state;

void setup() 
{
    Serial.begin(9600);
    Serial.println("Enter AT commands:");
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
    pinMode(flameSens, INPUT);
    // HC-06 default serial speed for communcation mode is 9600
    BT.begin(9600);  
}
 
void loop() 
{
    data = BT.read(); 
    detect = digitalRead(flameSens);

    if(detect==1){
      if(data=='a'){
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
        state = data;
      }

      else if(data=='s'){
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
        state = data;
      }

      else if(data=='d'){
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);
        state = data;
      }

      else if(data=='w'){
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);
        state = data;
      }
      else if(data =='b'){
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, LOW);
        state = data;
      }
    }
   
    else if(detect==0){
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, LOW);
      }
    
    delay(50); 
}
