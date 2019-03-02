#define ttlPin 7
#define btn1_pin 2
#define btn2_pin 3


const int in1=11;
const int in2=10;
const int in3=9;
const int in4=8;

const int in10=7;
const int in20=6;
const int in30=5;
const int in40=4;

const int stepsPerRevolution = 512;   // change this to fit the number of steps per revolution of motor
int btn1_state = 0;
int btn2_state = 0;
int btn3_state = 0;
int flag1 = 0;
int flag2 = 0;
int flag3 = 0;

int pulseTime;
double frq;
int stepper_speed;



void setup() {
  pinMode(in1, OUTPUT); 
  pinMode(in2, OUTPUT); 
  pinMode(in3, OUTPUT); 
  pinMode(in4, OUTPUT); 

   pinMode(in10, OUTPUT); 
  pinMode(in20, OUTPUT); 
  pinMode(in30, OUTPUT); 
  pinMode(in40, OUTPUT); 


  pinMode(btn1_pin, INPUT);
  pinMode(btn2_pin, INPUT);

  
  stepper_speed = 1;

  // initialize the serial port:
  Serial.begin(9600);
  
}


void loop() {    
  flag1 = digitalRead(btn1_pin);
  flag2 = digitalRead(btn2_pin);
  int val=map(analogRead(5),0,1023, 500,2300);
  int val_a=val/400;
 Serial.println(val_a);
 if (flag1 == HIGH)
  {
  digitalWrite( in1, HIGH ); 
  digitalWrite( in10, HIGH ); 
  digitalWrite( in2, LOW ); 
  digitalWrite( in20, LOW ); 
  digitalWrite( in3, LOW ); 
  digitalWrite( in30, LOW ); 
  digitalWrite( in4, HIGH );
  digitalWrite( in40, HIGH );
  delay(val_a);


  digitalWrite( in1, LOW ); 
  digitalWrite( in2, LOW ); 
  digitalWrite( in3, LOW ); 
  digitalWrite( in4, HIGH );
  
  digitalWrite( in10, LOW ); 
  digitalWrite( in20, LOW ); 
  digitalWrite( in30, LOW ); 
  digitalWrite( in40, HIGH );
  delay(val_a);


  digitalWrite( in1, LOW ); 
  digitalWrite( in2, LOW ); 
  digitalWrite( in3, HIGH ); 
  digitalWrite( in4, HIGH );

  digitalWrite( in10, LOW ); 
  digitalWrite( in20, LOW ); 
  digitalWrite( in30, HIGH ); 
  digitalWrite( in40, HIGH );
  
  delay(val_a);

  digitalWrite( in1, LOW ); 
  digitalWrite( in2, LOW ); 
  digitalWrite( in3, HIGH ); 
  digitalWrite( in4, LOW );

  digitalWrite( in10, LOW ); 
  digitalWrite( in20, LOW ); 
  digitalWrite( in30, HIGH ); 
  digitalWrite( in40, LOW );
  
  delay(val_a);


  digitalWrite( in1, LOW ); 
  digitalWrite( in2, HIGH ); 
  digitalWrite( in3, HIGH ); 
  digitalWrite( in4, LOW );

  digitalWrite( in10, LOW ); 
  digitalWrite( in20, HIGH ); 
  digitalWrite( in30, HIGH ); 
  digitalWrite( in40, LOW );
  
  delay(val_a);

  digitalWrite( in1, LOW ); 
  digitalWrite( in2, HIGH ); 
  digitalWrite( in3, LOW ); 
  digitalWrite( in4, LOW );

  digitalWrite( in10, LOW ); 
  digitalWrite( in20, HIGH ); 
  digitalWrite( in30, LOW ); 
  digitalWrite( in40, LOW );
  
  delay(val_a);

  digitalWrite( in1, LOW ); 
  digitalWrite( in2, HIGH ); 
  digitalWrite( in3, LOW ); 
  digitalWrite( in4, LOW );

  digitalWrite( in10, LOW ); 
  digitalWrite( in20, HIGH ); 
  digitalWrite( in30, LOW ); 
  digitalWrite( in40, LOW );
  
  delay(val_a);

  digitalWrite( in1, HIGH ); 
  digitalWrite( in2, LOW ); 
  digitalWrite( in3, LOW ); 
  digitalWrite( in4, LOW );

  digitalWrite( in10, HIGH ); 
  digitalWrite( in20, LOW ); 
  digitalWrite( in30, LOW ); 
  digitalWrite( in40, LOW );
  
  delay(val_a);
  }
 
 else if ( flag2 == HIGH)
 {
  digitalWrite( in1, HIGH ); 
  digitalWrite( in2, LOW ); 
  digitalWrite( in3, LOW ); 
  digitalWrite( in4, LOW );

  digitalWrite( in10, HIGH ); 
  digitalWrite( in20, LOW ); 
  digitalWrite( in30, LOW ); 
  digitalWrite( in40, LOW );
  
  delay(val_a);

  digitalWrite( in1, HIGH ); 
  digitalWrite( in2, HIGH ); 
  digitalWrite( in3, LOW ); 
  digitalWrite( in4, LOW );
  
  digitalWrite( in10, HIGH ); 
  digitalWrite( in20, HIGH ); 
  digitalWrite( in30, LOW ); 
  digitalWrite( in40, LOW );
  
  delay(val_a);

  digitalWrite( in1, LOW ); 
  digitalWrite( in2, HIGH ); 
  digitalWrite( in3, LOW ); 
  digitalWrite( in4, LOW );

  digitalWrite( in10, LOW ); 
  digitalWrite( in20, HIGH ); 
  digitalWrite( in30, LOW ); 
  digitalWrite( in40, LOW );
  
  delay(val_a);

  digitalWrite( in1, LOW ); 
  digitalWrite( in2, HIGH ); 
  digitalWrite( in3, HIGH ); 
  digitalWrite( in4, LOW );

  digitalWrite( in10, LOW ); 
  digitalWrite( in20, HIGH ); 
  digitalWrite( in30, HIGH ); 
  digitalWrite( in40, LOW );
  
  delay(val_a);

  digitalWrite( in1, LOW ); 
  digitalWrite( in2, LOW ); 
  digitalWrite( in3, HIGH ); 
  digitalWrite( in4, LOW );

  digitalWrite( in10, LOW ); 
  digitalWrite( in20, LOW ); 
  digitalWrite( in30, HIGH ); 
  digitalWrite( in40, LOW );
  
  delay(val_a);

  digitalWrite( in1, LOW ); 
  digitalWrite( in2, LOW ); 
  digitalWrite( in3, HIGH ); 
  digitalWrite( in4, HIGH );

  digitalWrite( in10, LOW ); 
  digitalWrite( in20, LOW ); 
  digitalWrite( in30, HIGH ); 
  digitalWrite( in40, HIGH );
  
  delay(val_a);

  digitalWrite( in1, LOW ); 
  digitalWrite( in2, LOW ); 
  digitalWrite( in3, LOW ); 
  digitalWrite( in4, HIGH );

  digitalWrite( in10, LOW ); 
  digitalWrite( in20, LOW ); 
  digitalWrite( in30, LOW ); 
  digitalWrite( in40, HIGH );
  
  delay(val_a);

  
  digitalWrite( in1, HIGH ); 
  digitalWrite( in2, LOW ); 
  digitalWrite( in3, LOW ); 
  digitalWrite( in4, HIGH );

  digitalWrite( in10, HIGH ); 
  digitalWrite( in20, LOW ); 
  digitalWrite( in30, LOW ); 
  digitalWrite( in40, HIGH );
  
  delay(val_a);
 }
  
 }
   



  
