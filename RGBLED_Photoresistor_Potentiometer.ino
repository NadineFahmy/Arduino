int r1 = 11; //red
int b1 = 10; //blue
int g1 = 9; //green
int r2 = 6; 
int b2 = 5; 
int g2 = 3; 

void setup() {
  pinMode(r1, OUTPUT);
  pinMode(b1, OUTPUT);
  pinMode(g1, OUTPUT);
  pinMode(r2, OUTPUT);
  pinMode(b2, OUTPUT);
  pinMode(g2, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
}
void loop() {
  int read1 = analogRead(A0);
  int read2 = analogRead(A1);
  int read3 = analogRead(A2);
  int mread1 = map(read1, 0, 1023, 0, 255);
  int mread2 = map(read2, 0, 1023, 0, 255);
  int mread3 = map(read3, 0, 1023, 0, 255);
  analogWrite(r1, mread1);
  analogWrite(b1, mread2);
  analogWrite(r2, mread1);
  analogWrite(g2, mread3);
}
