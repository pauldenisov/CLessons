void setup() {
  // initialize the B register as an output.
  DDRB = DDRB | B00111111;
}

void loop() {
  int a = 5, b=8;
  //int a = 5;
  
  //int a = B00000101;
  //b=B00001000;

  PORTB = B00111111;
  delay(800);              // wait again

  PORTB = a+b;
  //PORTB = B00101010;
  delay(1800);              // wait

  //PORTB = B00010101;
  PORTB = B00000000;
  delay(1500);              // wait again
}
