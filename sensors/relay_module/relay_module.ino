#define CH1 12   
#define CH3 11   
#define led_blue 7 
#define led_white 6 
 
 void setup(){
   //Setup all the Arduino Pins
   pinMode(CH1, OUTPUT);
   pinMode(CH3, OUTPUT);
   pinMode(led_blue, OUTPUT);
   pinMode(led_white, OUTPUT);
   
   //Provide power to both LEDs
   digitalWrite(led_blue, HIGH);
   digitalWrite(led_white, HIGH);
   
   //Turn OFF any power to the Relay channels
   digitalWrite(CH1,LOW);
   digitalWrite(CH3,LOW);
   delay(2000); //Wait 2 seconds before starting sequence
 }
 
 void loop(){
   digitalWrite(CH1, HIGH);  //Green LED on, Yellow LED off
   delay(1000);
   digitalWrite(CH1, LOW);   //Yellow LED on, Green LED off
   delay(1000);
   digitalWrite(CH3, HIGH);  //Relay 3 switches to NO
   delay(1000);
   digitalWrite(CH3,LOW);    //Relay 3 switches to NC
   delay(1000);
 }
    
