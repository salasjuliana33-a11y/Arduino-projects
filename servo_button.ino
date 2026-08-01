/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 https://www.arduino.cc/en/Tutorial/LibraryExamples/Sweep
 */


#include <Servo.h>

Servo myservo;  // create Servo object to control a servo
// twelve Servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
const int buttonPin = 2; 


void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the Servo object
  pinMode(buttonPin, INPUT_PULLUP);
  myservo.write(0);
}

void loop() {
int buttonState = digitalRead(buttonPin);
 
if (buttonState == LOW) {
  myservo.write (180); //Will turn 180 deg when pressed
}
else {
  myservo.write(0); // Returns to 0 deg when released
}
}
 