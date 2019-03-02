#define potPin A5
#define ttlPin 7
#define btn1_pin 2
#define btn2_pin 3

const int IN1=11; //stepper motor driver module pin IN1 attached to digital pin 11
const int IN2=10; //stepper motor driver module pin IN2 attached to digital pin 10
const int IN3=9;  //stepper motor driver module pin IN3 attached to digital pin 9
const int IN4=8;  //stepper motor driver module pin IN4 attached to digital pin 8

const char tab1[] = {0x01, 0x03, 0x02, 0x06, 0x04, 0x0c, 0x08, 0x09}; //array for turning CW
const char tab2[] = {0x01, 0x09, 0x08, 0x0c, 0x04, 0x06, 0x02, 0x03}; //array for turning CCW

const int stepsPerRevolution = 512;   // change this to fit the number of steps per revolution of motor

int btn1_state = 0;
int btn2_state = 0;
int flag1 = 0;
int flag2 = 0;

int pot_val;
double frq;
int potVal;
int stepper_speed;
int signal_data;

void setup() {
  pinMode(IN1, OUTPUT); 
  pinMode(IN2, OUTPUT); 
  pinMode(IN3, OUTPUT); 
  pinMode(IN4, OUTPUT); 

  pinMode(potPin,INPUT);
  pinMode(ttlPin,OUTPUT);
  pinMode(btn1_pin, INPUT);
  pinMode(btn2_pin, INPUT);
  
  stepper_speed = 1;

  // initialize the serial port:
  Serial.begin(9600);

  digitalWrite(ttlPin, LOW);
}

void loop() {    
  btn1_state = digitalRead(btn1_pin);
  btn2_state = digitalRead(btn2_pin);
  pot_val = analogRead(potPin);
  
  Serial.print("BTN1 STATE: ");
  Serial.print(flag1);
  Serial.print(" BTN2 STATE: ");
  Serial.println(flag2);
      
  if(btn1_state == HIGH){
    if(flag1 == 0) {
      stepper_speed = 1;
      flag1 = 1;
      flag2 = 0;
    }
    else if(flag1 == 1){
      flag1 = 0;
    }
  }
  if(btn2_state == HIGH){
      if(flag2 == 0) {
        stepper_speed = 4;
        flag2=1;
        flag1=0;
      }
      else if(flag2 == 1){
      flag2 = 0;
    }
  }
  
  
  if(flag1 == 0 && flag2 ==0) {
  if(pot_val < 50){
    stepper_speed = 5;
  }
  if(pot_val < 50 && pot_val > 50){
    stepper_speed = 5; 
  }
  if(pot_val < 100 && pot_val > 50){
    stepper_speed = 5;
  }
  if(pot_val < 150 && pot_val > 100){
    stepper_speed = 5;
  }
  if(pot_val < 200 && pot_val > 150){
    stepper_speed = 4;
  }
  if(pot_val < 250 && pot_val > 200){
    stepper_speed = 4;
  }
  if(pot_val < 300 && pot_val > 250) {
    stepper_speed = 4;
  }
  if(pot_val < 350 && pot_val > 300) {
    stepper_speed = 3;
  }
  if(pot_val < 400 && pot_val > 350) {
    stepper_speed = 3;
  }
  if(pot_val < 450 && pot_val > 400) {
    stepper_speed = 3;
  }
  if(pot_val < 500 && pot_val > 450) {
    stepper_speed = 2;
  }
  if(pot_val < 550 && pot_val > 500) {
    stepper_speed = 2;
  }
  if(pot_val < 600 && pot_val > 550) {
    stepper_speed = 2;
  }
  if(pot_val > 600) {
    stepper_speed = 1;
  }
 }

  Serial.println(pot_val);
  
  signal_data = digitalRead(ttlPin);  // read digital value of frq
  Serial.println(signal_data);

  if(signal_data == 1){
    ctlStepMotor(30, stepper_speed);//step motor turns CW 180 degrees
    digitalWrite(ttlPin,LOW);
  }
  else if(signal_data == 0) {
    ctlStepMotor(-30, stepper_speed);//step motor turns CW 180 degrees
    digitalWrite(ttlPin,HIGH);
  }
}
//************************************************************************************************************
void ctlStepMotor( int angle, char timedelay )
{
  for (int j = 0; j < abs(angle) ; j++)//abs computes the absolute value of a angle (180). Loop from 0 to 180
  {
    if (angle > 0)
    {
      for (int i = 0; i < 8; i++)//Loop from 0 to 8. Step motor turns 180 degrees CW
      {
        digitalWrite(IN1, ((tab1[i] & 0x01) == 0x01 ? true : false));
        digitalWrite(IN2, ((tab1[i] & 0x02) == 0x02 ? true : false));
        digitalWrite(IN3, ((tab1[i] & 0x04) == 0x04 ? true : false));
        digitalWrite(IN4, ((tab1[i] & 0x08) == 0x08 ? true : false));
        delay(timedelay);
      }
    }
    else
    {
      for (int i = 0; i < 8 ; i++)//Loop from 0 to 8. Step motor turns 180 degrees CCW
      {
        digitalWrite(IN1, ((tab2[i] & 0x01) == 0x01 ? true : false));
        digitalWrite(IN2, ((tab2[i] & 0x02) == 0x02 ? true : false));
        digitalWrite(IN3, ((tab2[i] & 0x04) == 0x04 ? true : false));
        digitalWrite(IN4, ((tab2[i] & 0x08) == 0x08 ? true : false));
        delay(timedelay);
      }
    }
  }
}
//************************************************************************************************************
void StepMotorStop()//Step motor stops
{
  digitalWrite(IN1, 0);
  digitalWrite(IN2, 0);
  digitalWrite(IN3, 0);
  digitalWrite(IN4, 0);
}
