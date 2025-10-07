#
/*
  stepperMotor-testing.ino

  Simple controller for a 28BYJ-48 stepper motor using the built-in
  Arduino Stepper library. This sketch accepts simple serial commands to
  rotate the motor a given angle (degrees).

  Hardware:
    - Stepper: 28BYJ-48 (commonly used with ULN2003 driver board)
    - Driver: ULN2003 board
    - MCU: Arduino Uno / Nano / compatible

  Wiring (example for Arduino Uno):
    ULN2003 VCC  -> 5V
    ULN2003 GND  -> GND
    ULN2003 IN1  -> digital pin 8
    ULN2003 IN2  -> digital pin 9
    ULN2003 IN3  -> digital pin 10
    ULN2003 IN4  -> digital pin 11

  Serial usage:
    - Open Serial Monitor at 9600 baud.
    - Send commands like:
        rotate 90    -> rotate +90 degrees (clockwise)
        rotate -45   -> rotate -45 degrees (counter-clockwise)

  Notes:
    - The sketch uses stepsPerRevolution = 2048 which works for the
      28BYJ-48 in half-step mode. stepsPerDegree is computed from this.
    - Adjust myStepper.setSpeed(RPM) to change rotation speed.

  License: MIT
*/

#include <Stepper.h>
const int stepsPerRevolution = 2048; // for 28BYJ-48 (half-step mode)
const int in1Pin = 8;
const int in2Pin = 9;
const int in3Pin = 10;
const int in4Pin = 11;
Stepper myStepper(stepsPerRevolution, in1Pin, in3Pin, in2Pin, in4Pin);
float stepsPerDegree = stepsPerRevolution / 360.0;
void setup()
{
  Serial.begin(9600);
  myStepper.setSpeed(10); // RPM
  Serial.println("Enter command like: rotate 90 (positive = CW, negative = CCW)");
}
void loop()
{
  if (Serial.available() > 0)
  {
    String input = Serial.readStringUntil('\n');
    input.trim();
    if (input.startsWith("rotate"))
    {
      // Extract angle after "rotate"
      int angle = input.substring(6).toInt();
      // Convert to steps
      long stepsToMove = angle * stepsPerDegree;
      // Move motor relative to current position
      myStepper.step(stepsToMove);
      // Debug info
      Serial.print("Rotated ");
      Serial.print(angle);
      Serial.println(" degrees");
    }
  }
}
