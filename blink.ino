void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(13,HIGH);
  delay(500);
  digitalWrite(13,LOW);
  delay(500);
}


//Arduino_Projects This is my first harware electronics project. Circuit was built on a breadboard used to control the LED light using an arduino. 
// This small project deomstrates the use of hardware/software, circuit design, and writing embedded code.
//Component list:Arduino Uno, Breadboard, 1x red LED, 1x 330-ohm resistor,Jumperwires
//What I Learned. BreadBoard Basics: Understanding how rows and power rails route electricity, Circuit Safety: How to use a current-limitng resistor to protect the LED
// from burning out, Embedded Coding: Writing Arduino functions like 'pinMode()'; digitalWrite()'; and 'delay()'.
