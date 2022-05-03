// Include libraries:
#include <Servo.h>
#include <ezButton.h>

// Create servo objects:
Servo leftServo;
Servo rightServo;

// create ezButton object that attach to pin 8;
ezButton limitSwitch(8);  

// Define servo pins:
#define leftServoPin 9
#define rightServoPin 10


// Variables to store the servo's position: (change values depending on set up)
int leftServoAngle = 135;
int rightServoAngle = 92;

int leftServoPowerOnAngle;

void setup() {
  limitSwitch.setDebounceTime(50); // set debounce time to 50 milliseconds

  // Attach the Servo variables to correct pins:
  leftServo.attach(leftServoPin);
  rightServo.attach(rightServoPin);
  leftServo.write(leftServoAngle);
  rightServo.write(rightServoAngle);
}

void loop() {
  limitSwitch.loop();
  int btnState = limitSwitch.getState();
  if (btnState == 0) {
    moveLeftServo();
    moveRightServo();
  }

  
}

void moveLeftServo() {
  // Used to manage speed of movement
  for (leftServoAngle = 135; leftServoAngle >= 100; leftServoAngle -= 1) { 
    leftServo.write(leftServoAngle);   // move left servo to position leftServoAngle
    delay(10);                       // waits 10ms for the servo to reach the position
  }
  for (leftServoAngle = 100; leftServoAngle <= 135; leftServoAngle += 1) { 
    leftServo.write(leftServoAngle);   // move left servo to position leftServoAngle
    delay(10);                       // waits 10ms for the servo to reach the position
  }
}

void moveRightServo() {
  // Used to manage speed of movement
  for (rightServoAngle = 92; rightServoAngle >= 60; rightServoAngle -= 1) {
    rightServo.write(rightServoAngle);   // move right servo to position rightServoAngle
    delay(10);                       // waits 10ms for the servo to reach the position
  }
  for (rightServoAngle = 60; rightServoAngle <= 92; rightServoAngle += 1) { 
    rightServo.write(rightServoAngle);   // move right servo to position rightServoAngle
    delay(10);                       // waits 10ms for the servo to reach the position
  }
}
