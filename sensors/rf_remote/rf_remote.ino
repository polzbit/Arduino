#define D0 9
#define D1 10
#define D2 11
#define D3 12
#define ch1 4

void setup(){
Serial.begin(9600); // setting the  baud rate
Serial.println("RF receiver button decode"); // printing
pinMode(ch1,OUTPUT);
delay(500);
}

void loop(){
if (digitalRead(D0) == HIGH) { // Button B pressed
Serial.println("you are pushing the B");
digitalWrite(ch1,LOW);
}
if (digitalRead(D2) == HIGH) { // Button A pressed
Serial.println("you are pushing A");
digitalWrite(ch1,HIGH);
}
}
