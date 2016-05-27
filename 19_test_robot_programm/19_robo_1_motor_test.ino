/*  First Motor test
 *  Enable pins: 5, 6 
 *  Rotation pins: 4, 7
 */

// constants won't change. Used here to set a pin number :
const int EnRightMotorPin =  5;      // the ENABLE pin
const int EnLeftMotorPin =  6;      // the ENABLE pin

const int RotRightMotorPin =  4;      // the ENABLE pin
const int RotLeftMotorPin =  7;      // the ENABLE pin

// Variables will change :
int EnRightState = LOW;             // Right motor is disabled
int EnLeftState = LOW;             // Left motor is disabled

int RotRight = LOW;             // Right motor rotation is Forward/LOW (Back is 'HIGH')
int RotLeft = LOW;             // Left motor rotation is Forward/LOW (Back is 'HIGH')

// constants won't change :
const long interval = 1000;           // interval (milliseconds)

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;        // will store last changed time was updated

void setup() {
  // set the Arduino's digital pins as output:
  pinMode(EnRightMotorPin, OUTPUT);
  pinMode(EnLeftMotorPin, OUTPUT);
  pinMode(RotRightMotorPin, OUTPUT);
  pinMode(RotRightMotorPin, OUTPUT);
}

void loop() {
  // here is where you'd put code that needs to be running all the time.

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // save the last time
    previousMillis = currentMillis;

    // if the ENABLE pin is off turn it on and vice-versa:
    if ( EnRightState == LOW) {
      EnRightState = HIGH;
      EnLeftState = HIGH;
    } else {
      EnRightState = LOW;
      EnLeftState = LOW;
    }

    // set the Enable Pin with the Pin State of the variable:
    digitalWrite(EnRightMotorPin, EnRightState);
    digitalWrite(EnLeftMotorPin, EnLeftState);
  }
}

