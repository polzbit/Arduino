#define ECHO_PIN 8 // Arduino pin tied to echo pin on the ultrasonic sensor.
#define TRIGGER_PIN 7 // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define MAX_DISTANCE 500 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
int maximumRange = 400; // Maximum range needed
int minimumRange = 0; // Minimum range needed

long duration,distance;

void setup()
{
  Serial.begin(9600);
  pinMode(TRIGGER_PIN,OUTPUT);
  pinMode(ECHO_PIN ,INPUT);
}

void loop()
{
 /* The following trigPin/echoPin cycle is used to determine the
 distance of the nearest object by bouncing soundwaves off of it. */ 
 digitalWrite(TRIGGER_PIN, LOW); 
 delayMicroseconds(2); 

 digitalWrite(TRIGGER_PIN, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(TRIGGER_PIN, LOW);
 duration = pulseIn(ECHO_PIN, HIGH);
 
 //Calculate the distance (in cm) based on the speed of sound.
 distance = duration/58.2;
 
 if (distance >= maximumRange || distance <= minimumRange){
 /* Send a negative number to computer and Turn LED ON 
 to indicate "out of range" */
 Serial.println("-1");
 digitalWrite(13, HIGH); 
 }
 else {
 /* Send the distance to the computer using Serial protocol, and
 turn LED OFF to indicate successful reading. */
 Serial.println(distance);
 digitalWrite(13, LOW); 
 }
 
 //Delay 100ms before next reading.
 delay(100);
}
