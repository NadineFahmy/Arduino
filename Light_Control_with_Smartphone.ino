#define on 0
#define off 1
int relay=4;
void setup()
{
pinMode(relay,OUTPUT);
Serial.begin(9600);
}
void loop()
{
  if ( Serial.available() > 0) {
    char Reading = Serial.read();
    switch(Reading) {
      case 'F' : digitalWrite(relay,off); break;
      case 'B' : digitalWrite(relay,on); break; }
  }
}
