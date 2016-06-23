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
const int TurnInterval = 800;           // interval (milliseconds)
const int TurnAroundInterval = 1500;           // interval (milliseconds)

//float maximumRange = 20.0; // Maximum range needed
float minimumRange = 7.0; // Minimum acceptable range
float distance; // Duration used to calculate distance

// Variables for checking obstacle position
// '0' means 'NO obstacle', '1' means 'Obstacle is present'
int ObstacleFront, ObstacleRight, ObstacleLeft, ObstacleResult;

/*  MEMORY variable, Robot needs it to understand its current state
 *  '0' - means 'I am looking in the front of me' 
 *  '1' - means 'I am looking in the right side' 
 *  '0' - means 'I am looking in the left side' 
*/
int RobotState = 0; 

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
  delay(400);
  roboservo.detach();

  // TEST PIN - REMOVE IT !!!!
  pinMode(13, OUTPUT);
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
  float duration; // Duration used to calculate distance

  /* The following trigPin/echoPin cycle is used to determine the
  distance of the nearest object by bouncing soundwaves off of it. */ 
  digitalWrite(USonicTrigPin, LOW); 
  delayMicroseconds(2); 

  digitalWrite(USonicTrigPin, HIGH);
  delayMicroseconds(10); 
 
  digitalWrite(USonicTrigPin, LOW);
  duration = pulseIn(USonicEchoPin, HIGH);

  delay(50);
 
  //Calculate and return the distance (in cm) based on the speed of sound.
  return duration/58.2;
}

void servo_moving(int ServoMoveTo) {
  /*  Servo moving function
   *   
   *  The 'ServoMoveTo' variable can get the following values:
   *  '0' - Front position (90 grad)
   *  '1' - Right 45 grad turn postion (135 grad)
   *  '2' - Left 45 grad turn postion (45 grad)
   */

  int CurrentPosition;

  if (1 == ServoMoveTo)
  {
      CurrentPosition = 135;    
  }
  else if (2 == ServoMoveTo)
  {
      CurrentPosition = 45;    
  }
  else
  {
      CurrentPosition = 90;
  }
  
  roboservo.attach(ServoPin);
  roboservo.write(CurrentPosition);
  delay(500);
  roboservo.detach();
  //digitalWrite(13, HIGH);
  //delay(1000);
  //digitalWrite(13, LOW);
}

void loop() {
  // here is where you'd put code that needs to be running all the time.

  ObstacleFront = 0;
  ObstacleRight = 0;
  ObstacleLeft = 0;
  ObstacleResult = 0;
  
  distance = 0.0;
  distance = range_meter();

  //delay(50);
  
  if (distance < minimumRange)
  {
    // I got an obstacle, but where is it?
    motors_stop();
    delay(50);

    /* Obstacle checking - Right-Front-Left */
    // Right:
    servo_moving(1);
    distance = range_meter();
    if (distance < minimumRange)
    {
      ObstacleRight = 1;
    }

    // Left:
    servo_moving(2);
    distance = range_meter();
    if (distance < minimumRange)
    {
      ObstacleLeft = 1;
    }
    
    // Front:
    servo_moving(0);
    distance = range_meter();
    if (distance < minimumRange)
    {
      ObstacleFront = 1;
    }

    /* Obstacles have been checked, let's analyse the results */
    ObstacleResult = ObstacleLeft*100 + ObstacleFront*10 + ObstacleRight;

    // Big choice
    if (10 == ObstacleResult)
    {
      // 010 - an obstacle is in the front of me - move right
      right_turn();
      motors_start();
      delay(TurnInterval);
      motors_stop();
    }
    else if (11 == ObstacleResult) {
      // 011 - an obstacle is in the front and right of me - move left
      left_turn();
      motors_start();
      delay(TurnInterval);
      motors_stop();
    }
    else if (110 == ObstacleResult) {
      // 110 - an obstacle is in the left and front of me - move right
      right_turn();
      motors_start();
      delay(TurnInterval);
      motors_stop();
    }
    else if (111 == ObstacleResult) {
      // 111 - an obstacle is in the right-front-left of me - go back, turn left-around
      back();
      motors_start();
      delay(TurnInterval);
      motors_stop();
      left_turn();
      motors_start();
      delay(TurnAroundInterval);
      motors_stop();
    }
    delay(200);
  }
  else
  {
    // Nobody blocks me - move forward
    forward();
  }

  forward();
  motors_start();
  delay(200);

//  motors_stop();
//  delay(2);
}

