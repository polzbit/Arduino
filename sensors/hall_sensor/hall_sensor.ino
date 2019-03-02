#define HALL_PIN 10
#define BUZZER_PIN 49

int val;

void setup() {
  Serial.begin(9600);
  pinMode(HALL_PIN, INPUT);
}

void loop() {
  val = digitalRead(HALL_PIN);
  if(val == LOW) {
    analogWrite(BUZZER_PIN, 255);
    Serial.println("Magnetic Field Detected");
  }
  else {
    analogWrite(BUZZER_PIN, 0);
  }
}
