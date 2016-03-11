// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(4, 5, 6, 7, 8, 9);
const int buttonPin = 10;
int buttonState = 0;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // set up an input pin for the button
  pinMode(buttonPin, INPUT);
}

void loop() {
  lcd.clear();
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:

  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    lcd.print("Yes");
  } else {
    // turn LED off:
    lcd.print("No");
  }
  delay(100);
}
