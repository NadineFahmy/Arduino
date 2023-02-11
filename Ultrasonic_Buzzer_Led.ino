#define trig 11
#define echo 12
int led = 10;
int buzzer = 9;
void setup() {
  pinMode(trig, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(15);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  long duration = pulseIn(echo, HIGH);
  long distance = (duration / 2) * 0.343;
  //Serial.println(distance);
  delay(5);

  if (distance < 20) {
    for (int i = 0; i <= 3; i++) {
      digitalWrite(led,HIGH);
      tone(buzzer, 500);
      delay(50);
      digitalWrite(led,LOW);
      noTone(buzzer);
      delay(50);
    }
     }

  else { 
    digitalWrite(led,LOW);
    noTone(buzzer);}

}
