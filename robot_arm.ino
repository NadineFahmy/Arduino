#include <Servo.h>
Servo myservo;
 Servo myservo2;

int pos = 0;
void setup() {
myservo.attach(9); 
myservo2.attach(5);
}
void loop() {
for (pos = 0; pos <= 180; pos += 1) {
// in steps of 1 degree
myservo.write(pos); 
delay(15); 
}
for (pos = 180; pos >= 0; pos -= 1) {
myservo.write(pos); 
delay(15); 
}
delay(3000);
for (pos = 0; pos <= 90; pos += 1) {
// in steps of 1 degree
myservo2.write(pos); 
delay(15); 
}
for (pos = 90; pos >= 0; pos -= 1) {
myservo2.write(pos); 
delay(15); 
} }
