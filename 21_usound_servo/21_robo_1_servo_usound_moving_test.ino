/*  Ultrasonic sensor with Servo test
 *  
 *  Enable pins: 5, 6 
 *  Rotation pins: 4, 7
 *  
 *  UltraSonic Echo pin: 9
 *  UltraSonic Trigger pin: 10
 *  
 *  Servo Control pin: 2
 */
#include <Servo.h>

Servo roboservo;  // create servo object to control a servo

int ServoPosition = 90;  // Servo position variable

// constants won't change. Used here to set a pin number :
const int EnRightMotorPin =  5;      // Right ENABLE pin
const int EnLeftMotorPin =  6;      // Left ENABLE pin

const int RotRightMotorPin =  4;      // Right Rotation pin
const int RotLeftMotorPin =  7;      // Left Rotaion pin

const int USonicEchoPin =  9;      // UltraSonic Sensor Echo pin
const int USonicTrigPin =  10;      // UltraSonic Sensor Trig pin

const int ServoPin =  2;      // Servo Motor Control pin

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
  pinMode(USonicTrigPin, OUTPUT);  // TRIG pin
  pinMode(USonicEchoPin, INPUT);      // ECHO pin

  // Servo Motor setup
  roboservo.attach(ServoPin);
  roboservo.write(ServoPosition);
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

float range_meter() {
  // Ultrasonic sensor function

  /* The following trigPin/echoPin cycle is used to determine the
  distance of the nearest object by bouncing soundwaves off of it. */ 
  digitalWrite(USonicTrigPin, LOW); 
  delayMicroseconds(2); 

  digitalWrite(USonicTrigPin, HIGH);
  delayMicroseconds(10); 
 
  digitalWrite(USonicTrigPin, LOW);
  duration = pulseIn(USonicEchoPin, HIGH);
 
  //Calculate and return the distance (in cm) based on the speed of sound.
  return duration/58.2;
}

void loop() {
  // here is where you'd put code that needs to be running all the time.

  distance = range_meter();

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

