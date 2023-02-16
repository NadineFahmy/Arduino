#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
lcd.init();
lcd.backlight();
pinMode(A0, INPUT);
pinMode(5, INPUT);
pinMode(4, OUTPUT);
Serial.begin(9600);}

void loop() {
  int gas = analogRead(A0);
  int flame = digitalRead(5);
  lcd.setCursor(0,0);
  lcd.println(gas);
  lcd.setCursor(5,0);
  lcd.print(flame);
  
  if (gas > 500 || flame == HIGH){
    digitalWrite(4, HIGH); }
    
  else { digitalWrite(4, LOW); }

}
