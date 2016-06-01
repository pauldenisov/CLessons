/*  First Motor test
 *  Enable pins: 5, 6 
 *  Rotation pins: 4, 7
 */

// constants won't change. Used here to set a pin number :
const int EnRightMotorPin =  5;      // the ENABLE pin
const int EnLeftMotorPin =  6;      // the ENABLE pin

const int RotRightMotorPin =  4;      // the ENABLE pin
const int RotLeftMotorPin =  7;      // the ENABLE pin

/* Back and Forward Right/Left motor rotation constants */
const int BackRotRight = LOW;
const int BackRotLeft = HIGH;
const int ForwardRotRight = HIGH;
const int ForwardRotLeft = LOW;

// constants won't change :
const long interval = 1500;           // interval (milliseconds)

void setup() {
  // set the Arduino's digital pins as output:
  pinMode(EnRightMotorPin, OUTPUT);
  pinMode(EnLeftMotorPin, OUTPUT);
  pinMode(RotRightMotorPin, OUTPUT);
  pinMode(RotRightMotorPin, OUTPUT);
}

void loop() {
  // here is where you'd put code that needs to be running all the time.

  // Stop motors
  // set the Enable Pin to stop state:
  digitalWrite(EnRightMotorPin, LOW);
  digitalWrite(EnLeftMotorPin, LOW);
  delay(interval);

  // Forward moving
  digitalWrite(RotRightMotorPin, HIGH);
  digitalWrite(RotLeftMotorPin, LOW);

  // Start motors
  // set the Enable Pin to start state:
  digitalWrite(EnRightMotorPin, HIGH);
  digitalWrite(EnLeftMotorPin, HIGH);
  delay(interval);

  // Back moving
  digitalWrite(RotRightMotorPin, LOW);
  digitalWrite(RotLeftMotorPin, HIGH);
  delay(interval);


/*
  // Forward moving
  digitalWrite(RotRightMotorPin, ForwardRotRight);
  digitalWrite(RotLeftMotorPin, ForwardRotLeft);

  // Start motors
  // set the Enable Pin to start state:
  digitalWrite(EnRightMotorPin, HIGH);
  digitalWrite(EnLeftMotorPin, HIGH);
  delay(interval);

  // Right turn
  digitalWrite(RotRightMotorPin, ForwardRotRight);
  digitalWrite(RotLeftMotorPin, BackRotLeft);
  delay(1900);

  // Forward moving
  digitalWrite(RotRightMotorPin, ForwardRotRight);
  digitalWrite(RotLeftMotorPin, ForwardRotLeft);
  delay(interval);

  // Left turn
  digitalWrite(RotRightMotorPin, BackRotRight);
  digitalWrite(RotLeftMotorPin, ForwardRotLeft);
  delay(1700);
*/
}

