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

float maximumRange = 20.0; // Maximum range needed
float minimumRange = 7.0; // Minimum acceptable range
float duration, distance; // Duration used to calculate distance

void setup() {
  // set the Arduino's digital pins as output:
  pinMode(EnRightMotorPin, OUTPUT);
  pinMode(EnLeftMotorPin, OUTPUT);
  pinMode(RotRightMotorPin, OUTPUT);
  pinMode(RotRightMotorPin, OUTPUT);

  // Ultrasonic sensor pins
  pinMode(10, OUTPUT);  // TRIG pin
  pinMode(9, INPUT);      // ECHO pin
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

  // Part 1. Ultrasonic sensor

  /* The following trigPin/echoPin cycle is used to determine the
  distance of the nearest object by bouncing soundwaves off of it. */ 
  digitalWrite(10, LOW); 
  delayMicroseconds(2); 

  digitalWrite(10, HIGH);
  delayMicroseconds(10); 
 
  digitalWrite(10, LOW);
  duration = pulseIn(9, HIGH);
 
  //Calculate the distance (in cm) based on the speed of sound.
  distance = duration/58.2;


  if (distance < minimumRange)
  {
    // go back
    back();
    motors_start();
    delay(50);
  }
  else if (distance > maximumRange)
  {
    // go forward
    forward();
    motors_start();
    delay(50);
  }
  else
  {
    // stop
    motors_stop();
    delay(5);
  }
  

  motors_stop();
  delay(2);
}

