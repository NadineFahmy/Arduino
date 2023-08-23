#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <SPI.h>
#include <MFRC522.h>
#define SS_PIN 10
#define RST_PIN 9
#define Buzzer 5
#define lock 7
LiquidCrystal_I2C Lcd(0x27, 16, 2);

MFRC522 rfid(SS_PIN, RST_PIN); // Instance of the class
bool flag=false;
bool flag1=false;
 
void setup() 
{
  Lcd.init();
  Lcd.backlight();
  Serial.begin(9600);
  SPI.begin();      // Initiate  SPI bus
  rfid.PCD_Init(); // Init MFRC522 
  pinMode(Buzzer,OUTPUT);
    pinMode(lock,OUTPUT);

  Serial.println("Approximate your Card to the Reader....");
}
void loop() 
{
  rfid1();
  if(flag)
  {

    digitalWrite(Buzzer,HIGH);
    delay(50);
    digitalWrite(Buzzer,LOW);
    delay(50);
    digitalWrite(Buzzer,HIGH);
    delay(50);
    digitalWrite(Buzzer,LOW);
    delay(1000);
            digitalWrite(lock,HIGH);
    delay(5000);
                digitalWrite(lock,LOW);


    flag=false;
  }
  
} 

void rfid1()
{
  if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()) {
  String UID="";
  for (byte i=0;i<rfid.uid.size;i++) 
  {
     Serial.print(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ");// E8 07 C7 D2
     Serial.print(rfid.uid.uidByte[i], HEX);
     UID.concat(String(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ")); // 0E c2 12 
     UID.concat(String(rfid.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  UID.toUpperCase();
  // E8 07 C7 D2
  if (UID.substring(1) == "EA 5D 1F 3F" || UID.substring(1) == "C4 33 9A 28") //change here the UID of the card/cards that you want to give access
  {
    
    Serial.println("KIMO");
    Serial.println("Authorized access");
    Lcd.print("Authorized access");
    flag=true;
  }else if(UID.substring(1) == "AA E4 25 40")
  {
    Serial.println("karim");
    Serial.println("Authorized access");
    flag=true;
  }else
  {
    Serial.println("Access denied");
    Lcd.print("Access denied");
    digitalWrite(Buzzer,HIGH);
    delay(500);
    digitalWrite(Buzzer,LOW);
    delay(800);
    digitalWrite(lock,LOW);

    flag=false;
  }
  
  rfid.PICC_HaltA();
  // Stop encryption on PCD
  rfid.PCD_StopCrypto1();
  
}
}
