#define LED_PIN 8
#define SW1_PIN 2
#define SW2_PIN 3
int sw1;
int sw2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_PIN,OUTPUT);
  pinMode(SW1_PIN, INPUT);
  pinMode(SW2_PIN, INPUT);
  digitalWrite(LED_PIN, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Switch 1 state is: ");
  Serial.println(sw1);
  Serial.print("Switch 2 state is: ");
  Serial.println(sw2);
  sw1 = digitalRead(SW1_PIN);
  sw2 = digitalRead(SW2_PIN);
  if(sw1 == HIGH && sw2 == HIGH)
    digitalWrite(LED_PIN, HIGH);
  else if (sw1 == HIGH && sw2 == LOW)
    digitalWrite(LED_PIN, LOW);

  else if (sw1 == LOW && sw2 == HIGH)
    digitalWrite(LED_PIN, LOW);
  else if (sw1 == LOW && sw2 == LOW)
    digitalWrite(LED_PIN, LOW);
    
  delay(50);
}
