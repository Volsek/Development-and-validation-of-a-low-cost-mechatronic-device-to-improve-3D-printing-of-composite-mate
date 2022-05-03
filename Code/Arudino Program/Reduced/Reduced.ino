// Include libraries:
#include <Servo.h>
#include <ezButton.h>

// Create servo objects:
Servo servo;

// create ezButton object that attach to pin 8;
ezButton limitSwitch(8);

// Define servo pins:
#define servoPin 9

// Variables to store the servo's position: (change values depending on set up)
int servoAngle = 0;

void setup() {
  limitSwitch.setDebounceTime(50); // set debounce time to 50 milliseconds

  // Attach the Servo variables to correct pins:
  servo.attach(servoPin);
  servo.write(servoAngle); // move to starting position
}

void loop() {
  limitSwitch.loop();
  int btnState = limitSwitch.getState();
  if (btnState == 0) {
    moveServo();
  }
}

void moveServo() {
  // Used to manage speed of movement
  for (servoAngle = 0; servoAngle <= 110; servoAngle += 1) { // goes from 128 degrees to 0 degrees in steps of 1 degree
    servo.write(servoAngle);        // move servo to position servoAngle
    delay(5);                       // waits 5ms for the servo to reach the position
  }
  for (servoAngle = 110; servoAngle >= 0; servoAngle -= 1) { // goes from 0 degrees to 128 degrees in steps of 1 degree
    servo.write(servoAngle);        // move servo to position servoAngle
    delay(5);                       // waits 5ms for the servo to reach the position
  }
}
