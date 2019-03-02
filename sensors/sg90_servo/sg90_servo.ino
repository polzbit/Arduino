#include <Servo.h>

#define SG90_PIN 9
#define ROTATION_PIN A0

Servo servo;

void setup() {
  Serial.begin(9600);
  servo.attach(SG90_PIN);
}

void loop() {
  int data = analogRead(ROTATION_PIN);
  data = map(data,0,1023,0,180);
  Serial.print("Rotation at: ");
  Serial.println(data);
  servo.write(data);
  delay(15);
}
