#define speedL 10
#define in1 9
#define in2 8
#define in3 7
#define in4 6
#define speedR 5
#define trig 11
#define echo 4
long duration,distance;

void setup() { 
for(int i=5 ; i<=11 ; i++)
{
pinMode(i, OUTPUT); 
} 
pinMode(echo, INPUT);
}

void Ultrasonic(){
digitalWrite(trig, LOW);
delayMicroseconds(2); 
digitalWrite(trig, HIGH);
delayMicroseconds(10); 
digitalWrite(trig, LOW);
duration = pulseIn(echo, HIGH);
distance = (duration/2) * 0.0343; 
}

void forword()
{
digitalWrite(in1, HIGH);
digitalWrite(in2, LOW); 
digitalWrite(in3, HIGH); 
digitalWrite(in4, LOW);
analogWrite(speedL,150);
analogWrite(speedR,150); 
}

void backword()
{
digitalWrite(in1, LOW);
digitalWrite(in2, HIGH); 
digitalWrite(in3, LOW); 
digitalWrite(in4, HIGH);
analogWrite(speedL,150);
analogWrite(speedR,150); 
}

void left()
{
digitalWrite(in1, LOW);
digitalWrite(in2, LOW); 
digitalWrite(in3, HIGH); 
digitalWrite(in4, LOW); 
analogWrite(speedL,0);
analogWrite(speedR,150); 
}

void right()
{
digitalWrite(in1, HIGH);
digitalWrite(in2, LOW); 
digitalWrite(in3, LOW); 
digitalWrite(in4, LOW);
analogWrite(speedL,150);
analogWrite(speedR,0); 
}

void stopp(){
digitalWrite(speedL, LOW);
digitalWrite(speedR, LOW); 
}
void loop(){
Ultrasonic();
if(distance < 20){ 
stopp(); delay(250);
backword(); delay(500);
right(); delay(1000);
}
else{ forword(); }
}
