/*
 * This module adjusts a servo based on the resistance
 * of a potentiometer.
 * Created by: James Couse
*/

#include <Servo.h>

Servo servoOne;  // create servo object to control a servo

int potPin = 0;  // analog pin used to connect the potentiometer
int value;    // variable to read the value from the analog pin

void setup() {
  servoOne.attach(7);  // attaches the servo on pin 7 to the servo object
}

void loop() {
  value = analogRead(potPin);        // reads the value of the potentiometer (value between 0 and 1023)
  value = map(value, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  servoOne.write(value);                  // sets the servo position according to the scaled value
  delay(15);                           // waits for the servo to get there
}