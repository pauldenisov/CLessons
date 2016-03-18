// include the library code:
#include <LiquidCrystal.h>

float maximumRange = 200.0; // Maximum range needed
float minimumRange = 3.0; // Minimum range needed
float duration, distance; // Duration used to calculate distance

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(4, 5, 6, 7, 8, 9);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  //lcd.print("hello, world!");
  
  // Ultrasonic sensor pins
  pinMode(12, OUTPUT);  // TRIG pin
  pinMode(11, INPUT);      // ECHO pin
}

void loop() {
  // Part 1. Ultrasonic sensor

  /* The following trigPin/echoPin cycle is used to determine the
  distance of the nearest object by bouncing soundwaves off of it. */ 
  digitalWrite(12, LOW); 
  delayMicroseconds(2); 

  digitalWrite(12, HIGH);
  delayMicroseconds(10); 
 
  digitalWrite(12, LOW);
  duration = pulseIn(11, HIGH);
 
  //Calculate the distance (in cm) based on the speed of sound.
  distance = duration/58.2;
 

  // Part 2. LCD output

  // set the cursor to column 0, line 0
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.clear();
  lcd.setCursor(0, 1);

 if (distance >= maximumRange || distance <= minimumRange)
 {
    // print the number of seconds since reset:
    lcd.print("Out of range");
 }
 else {
    // print the distance
    lcd.print(distance);
 }

  //Delay 50ms before next reading.
  delay(500);
}
