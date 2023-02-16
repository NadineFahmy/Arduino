const int red = 4;
String reading;
void setup( ) {
pinMode(red, OUTPUT);
Serial.begin(9600); // Adjust speed of serial monitor 
}
void loop( ) {
if(Serial.available()>0) {
reading=Serial.readString();
if (reading=="Turn on"){ digitalWrite(red,1);}
else if (reading=="Turn off"){
digitalWrite(red,0); }
}}
