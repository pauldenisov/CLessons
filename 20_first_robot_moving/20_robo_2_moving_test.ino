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

void forward() {
  digitalWrite(RotRightMotorPin, ForwardRotRight);
  digitalWrite(RotLeftMotorPin, ForwardRotLeft);
}

void back() {
  digitalWrite(RotRightMotorPin, BackRotRight);
  digitalWrite(RotLeftMotorPin, BackRotLeft);
}

void left_turn() {
  digitalWrite(RotRightMotorPin, BackRotRight);
  digitalWrite(RotLeftMotorPin, ForwardRotLeft);
}

void right_turn() {
  digitalWrite(RotRightMotorPin, ForwardRotRight);
  digitalWrite(RotLeftMotorPin, BackRotLeft);
}

void motors_stop() {
  // set the Enable Pin to stop state:
  digitalWrite(EnRightMotorPin, LOW);
  digitalWrite(EnLeftMotorPin, LOW);
}

void motors_start() {
  // set the Enable Pin to stop state:
  digitalWrite(EnRightMotorPin, HIGH);
  digitalWrite(EnLeftMotorPin, HIGH);
}

void loop() {
  // here is where you'd put code that needs to be running all the time.

  motors_stop();
  delay(interval);
  forward();
  motors_start();
  delay(interval);
  right_turn();
  delay(1900);
  forward();
  delay(interval);
  left_turn();
  delay(1700);
}

