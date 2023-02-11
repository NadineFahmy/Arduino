#include <Keypad.h>

int A = 13;
int B = 12;
int C = 11;
int D = 10;
int E = 9;
int F = 18;
int G = 19;

const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {A0, A1, 6, 5};
byte colPins[COLS] = {2, 8, 7, 3};

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup()
{
  int pins[] = {A, B, C, D, E, F, G};
  for (int i = 0; i < 7; i++) {
    pinMode(pins[i], OUTPUT);
  }
  Serial.begin(9600);
}

void zero() {

  int arrayH[] = {B, C, D, E, F, G};

  for (int i = 0; i < 6; i ++) {
    digitalWrite(arrayH[i], HIGH);
  }

  digitalWrite(A, LOW);
}

void one() {

  int arrayH[] = {D, G};
  int arrayL[] = {A, B, C, E, F};

  for (int i = 0; i < 2; i ++) {
    digitalWrite(arrayH[i], HIGH);
  }

  for (int i = 0; i < 5; i ++) {
    digitalWrite(arrayL[i], LOW);
  }
}

void two() {

  int arrayH[] = {A, C, D, E, F};
  int arrayL[] = {B, G};

  for (int i = 0; i < 5; i ++) {
    digitalWrite(arrayH[i], HIGH);
  }

  for (int i = 0; i < 2; i ++) {
    digitalWrite(arrayL[i], LOW);
  }
}

void three() {

  int arrayH[] = {A, C, D, F, G};
  int arrayL[] = {B, E};

  for (int i = 0; i < 5; i ++) {
    digitalWrite(arrayH[i], HIGH);
  }

  for (int i = 0; i < 2; i ++) {
    digitalWrite(arrayL[i], LOW);
  }
}

void four() {

  int arrayH[] = {A, B, C, D, G};
  int arrayL[] = {C, E, F};

  for (int i = 0; i < 4; i ++) {
    digitalWrite(arrayH[i], HIGH);
  }

  for (int i = 0; i < 3; i ++) {
    digitalWrite(arrayL[i], LOW);
  }
}

void five() {

  int arrayH[] = {A, B, C, F, G};
  int arrayL[] = {D, E};

  for (int i = 0; i < 5; i ++) {
    digitalWrite(arrayH[i], HIGH);
  }

  for (int i = 0; i < 2; i ++) {
    digitalWrite(arrayL[i], LOW);
  }
}

void six() {

  int arrayH[] = {A, B, C, E, F, G};

  for (int i = 0; i < 6; i ++) {
    digitalWrite(arrayH[i], HIGH);
  }

  digitalWrite(D, LOW);
}

void seven() {

  int arrayH[] = {C, D, G};
  int arrayL[] = {A, B, E, F};

  for (int i = 0; i < 3; i ++) {
    digitalWrite(arrayH[i], HIGH);
  }

  for (int i = 0; i < 4; i ++) {
    digitalWrite(arrayL[i], LOW);
  }
}

void eight() {


  int arrayH[] = {A, B, C, D, E, F, G};
  for (int i = 0; i < 7; i ++) {
    digitalWrite(arrayH[i], HIGH);
  }
}

void nine() {

  int arrayH[] = {A, B, C, D, F, G};

  for (int i = 0; i < 6; i ++) {
    digitalWrite(arrayH[i], HIGH);
  }

  digitalWrite(E, LOW);
}

void loop()
{
  char key = keypad.getKey();
  if ( key == '0') {
    zero();
  }
  else if ( key == '1') {
    one();
  }
  else if ( key == '2') {
    two();
  }
  else if ( key == '3') {
    three();
  }
  else if ( key == '4') {
    four();
  }
  else if ( key == '5') {
    five();
  }
  else if ( key =='6') {
    six();
  }
  else if ( key == '7') {
    seven();
  }
  else if ( key =='8') {
    eight();
  }
  else if ( key =='9') {
    nine();
  }
  else {
    Serial.print("ERROR!");
  }
}
