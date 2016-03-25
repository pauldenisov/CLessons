// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(0, 1, 2, 3, 4, 5);

byte rocket[8] = {
  0b00000,
  0b00000,
  0b11000,
  0b00110,
  0b00101,
  0b00110,
  0b11000
};

byte target[8] = {
  0b00000,
  0b00000,
  0b01110,
  0b10001,
  0b10101,
  0b10001,
  0b01110
};

byte explosion[8] = {
  0b10101,
  0b10001,
  0b01010,
  0b11111,
  0b01010,
  0b10001,
  0b10101
};

int i=0, tr_pos=10;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);

  // set up our special symbols 
  //lcd.createChar(0, smiley);
  lcd.createChar(0, rocket);
  lcd.createChar(1, target);
  lcd.createChar(2, explosion);

  // just a smile
  //lcd.write(byte(0));
}

// empty loop for a smile
//void loop() {}

void loop() {
  //lcd.clear();

  i=0;
  while (i < tr_pos) {

    lcd.setCursor(i, 0);
    lcd.write(byte(0));

    lcd.setCursor(tr_pos, 0);
    lcd.write(byte(1));

    i=i+1;
    delay(400);
    lcd.clear();
  }

  lcd.setCursor(tr_pos, 0);
  lcd.write(byte(2));   

  delay(700);
}


