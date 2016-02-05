/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */

void setup() {                
  // initialize the digital pin as an output.
  // Pin 13 has an LED connected on most Arduino boards:
  pinMode(13, OUTPUT);     
  pinMode(12, OUTPUT);     
  pinMode(11, OUTPUT);     
  pinMode(10, OUTPUT);     
  pinMode(9, OUTPUT);     
  pinMode(8, OUTPUT);     
}

void loop() {
  digitalWrite(13, HIGH);   // set the LED on
  digitalWrite(11, HIGH);   // set the LED on
  digitalWrite(9, HIGH);   // set the LED on
  digitalWrite(12, LOW);    // set the LED off
  digitalWrite(10, LOW);    // set the LED off
  digitalWrite(8, LOW);    // set the LED off
  delay(1000);              // wait for a second
  digitalWrite(12, HIGH);   // set the LED on
  digitalWrite(10, HIGH);   // set the LED on
  digitalWrite(8, HIGH);   // set the LED on
  digitalWrite(13, LOW);    // set the LED off
  digitalWrite(11, LOW);    // set the LED off
  digitalWrite(9, LOW);    // set the LED off
  delay(1000);              // wait for a second
}
