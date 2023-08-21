#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(32, 16, 2);

const int ROW_NUM = 4;
const int COLUMN_NUM = 4;

char keys[ROW_NUM][COLUMN_NUM] = {
{'1' , '2' , '3' , 'A'},
{'4' , '5' , '6' , 'B'},
{'7' , '8' , '9' , 'C'},
{'*' , '0' , '#' , 'D'} };

byte pin_rows[ROW_NUM] = {2,3,4,5};
byte pin_column[COLUMN_NUM] = {6,7,8,9};

Keypad keypad(makeKeymap(keys),pin_rows,pin_column,ROW_NUM, COLUMN_NUM);

byte Heart[8] = {
0b00000,
0b01010,
0b11111,
0b11111,
0b01110,
0b00100,
0b00000,
0b00000
};

byte Bell[8] = {
0b00100,
0b01110,
0b01110,
0b01110,
0b11111,
0b00000,
0b00100,
0b00000
};

byte Alien[8] = {
0b11111,
0b10101,
0b11111,
0b11111,
0b01110,
0b01010,
0b11011,
0b00000
};

byte Check[8] = {
0b00000,
0b00001,
0b00011,
0b10110,
0b11100,
0b01000,
0b00000,
0b00000
};

byte Speaker[8] = {
0b00001,
0b00011,
0b01111,
0b01111,
0b01111,
0b00011,
0b00001,
0b00000
};

byte Sound[8] = {
0b00001,
0b00011,
0b00101,
0b01001,
0b01001,
0b01011,
0b11011,
0b11000
};

byte Skull[8] = {
B00000,
0b01110,
0b10101,
0b11011,
0b01110,
0b01110,
0b00000,
0b00000
};

byte Lock[8] = {
0b01110,
0b10001,
0b10001,
0b11111,
0b11011,
0b11011,
0b11111,
0b00000
};


void setup() {
lcd.init();
lcd.backlight();
lcd.createChar(0, Heart);
lcd.createChar(1, Bell);
lcd.createChar(2, Alien);
lcd.createChar(3, Check);
lcd.createChar(4, Speaker);
lcd.createChar(5, Sound);
lcd.createChar(6, Skull);
lcd.createChar(7, Lock);
lcd.clear();
}

void loop() {
char key = keypad.getKey();
if (key)
{
switch (key) {
  case '1':
    lcd.write(0);
    break;
  case '2':
    lcd.write(1);
    break;
  case '3':
    lcd.write(2);
    break;
  case '4':
    lcd.write(3);
    break;
  case '5':
    lcd.write(4);
    break;
  case '6':
    lcd.write(5);
    break;
  case '7':
    lcd.write(6);
    break;
  case '8':
    lcd.write(7);
    break;
  case '#':
    lcd.clear();
    break;
}
}
}
