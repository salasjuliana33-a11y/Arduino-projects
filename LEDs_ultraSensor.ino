/*
  Ping))) Sensor

  This sketch reads a PING))) ultrasonic rangefinder and returns the distance
  to the closest object in range. To do this, it sends a pulse to the sensor to
  initiate a reading, then listens for a pulse to return. The length of the
  returning pulse is proportional to the distance of the object from the sensor.

  The circuit:
	- +V connection of the PING))) attached to +5V
	- GND connection of the PING))) attached to ground
	- SIG connection of the PING))) attached to digital pin 7

  created 3 Nov 2008
  by David A. Mellis
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  https://docs.arduino.cc/built-in-examples/sensors/Ping/
*/

// this constant won't change. It's the pin number of the sensor's output:
const int trigPin = 7;
const int echoPin = 8;
const int dangerLedPin  = 2; 
const int closeLedPin = 3;
const int midLedPin = 4; 
const int farLedPin = 5; 

void setup() {
  // initialize serial communication:
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(dangerLedPin, OUTPUT);
  pinMode (closeLedPin, OUTPUT);
  pinMode(midLedPin,OUTPUT);
  pinMode (farLedPin, OUTPUT);
}

void loop() {
  // establish variables for duration of the ping, and the distance result
  // in inches and centimeters:
  long duration, cm;

  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // The same pin is used to read the signal from the PING))): a HIGH pulse
  // whose duration is the time (in microseconds) from the sending of the ping
  // to the reception of its echo off of an object.
 
  duration = pulseIn(echoPin, HIGH);

  // convert the time into a distance in cm 
  cm = microsecondsToCentimeters(duration);

  Serial.print("Distance: ");
  Serial.print(cm);
  Serial.println("cm");
  
    if (cm <= 0 || cm > 100) {
    // LEDs will turn off once there is no range
    digitalWrite(dangerLedPin, LOW);
    digitalWrite(closeLedPin, LOW);
    digitalWrite (midLedPin, LOW); 
    digitalWrite (farLedPin, LOW);
  }
  else if (cm < 10) {
    // very close (LEDs ON)
    digitalWrite (dangerLedPin, HIGH);
    digitalWrite (closeLedPin, HIGH);
    digitalWrite (midLedPin,HIGH);
    digitalWrite (farLedPin,HIGH); 
  }
  else if (cm <20) {
    // close (3 LEDs)
    digitalWrite(dangerLedPin, LOW);
    digitalWrite(closeLedPin, HIGH);
    digitalWrite (midLedPin, HIGH); 
    digitalWrite (farLedPin, HIGH); 
  }
  else if (cm < 30) {
    digitalWrite(dangerLedPin, LOW);
    digitalWrite(closeLedPin, LOW);
    digitalWrite (midLedPin, HIGH); 
    digitalWrite (farLedPin, HIGH);
  }
  else {
    // far away 1 led on 
    digitalWrite(dangerLedPin, LOW);
    digitalWrite(closeLedPin, LOW);
    digitalWrite (midLedPin, LOW); 
    digitalWrite (farLedPin, HIGH);
  }

  delay(100); // small pause before sensor takes next reading 

}



long microsecondsToCentimeters(long microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the object we
  // take half of the distance travelled.
  return microseconds / 29 / 2;
}
