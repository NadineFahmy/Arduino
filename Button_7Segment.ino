int A = 13;
int B = 12;
int C = 11;
int D = 10;
int E = 9;
int F = 8;
int G = 7;
int button = 6;
int counter = -1;


void setup()
{
  int pins[] = {A, B, C, D, E, F, G};
  for (int i = 0; i < 7; i++) {
    pinMode(pins[i], OUTPUT);
  }
  pinMode(button, INPUT);
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
  int Bread = digitalRead(button);
  delay(1000);
  if ( Bread == HIGH) {
    counter++;
    Serial.println(counter);

    if ( counter == 0) {
      zero();
    }
    else if ( counter == 1) {
      one();
    }
    else if ( counter == 2) {
      two();
    }
    else if ( counter == 3) {
      three();
    }
    else if ( counter == 4) {
      four();
    }
    else if ( counter == 5) {
      five();
    }
    else if ( counter == 6) {
      six();
    }
    else if ( counter == 7) {
      seven();
    }
    else if ( counter == 8) {
      eight();
    }
    else if ( counter == 9) {
      nine();
    }
    else {
      counter = -1;
    }
  }
}
