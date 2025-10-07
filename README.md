# 28BYJ-48 Stepper Motor Experimentation

A minimal Arduino sketch and notes for experimenting with the 28BYJ-48 stepper motor and ULN2003 driver.

## Overview

This repository contains a small sketch, `stepperMotor-testing.ino`, which listens to the serial port and rotates a 28BYJ-48 stepper motor by a user-provided angle in degrees.

The sketch uses the built-in Arduino `Stepper` library and is intended for learning and experimentation.

## Hardware

- 28BYJ-48 stepper motor
- ULN2003 driver board (commonly packaged with the motor)
- Arduino Uno / Nano / compatible
- Jumper wires

## Wiring (example for Arduino Uno)

- ULN2003 VCC -> 5V
- ULN2003 GND -> GND
- ULN2003 IN1 -> digital pin 8
- ULN2003 IN2 -> digital pin 9
- ULN2003 IN3 -> digital pin 10
- ULN2003 IN4 -> digital pin 11

Double-check the pin labels on your ULN2003 board — some boards label them IN1..IN4, others may differ. Always connect GND between the Arduino and the driver board.

## Sketch behaviour and parameters

- `stepsPerRevolution = 2048` — recommended for 28BYJ-48 in half-step mode.
- `stepsPerDegree = stepsPerRevolution / 360.0` — used to convert degrees to steps.
- Speed is set by `myStepper.setSpeed(10)` (RPM). Increase or decrease to change motion speed.

## Serial commands

Open the Arduino Serial Monitor (or any serial terminal) at 9600 baud. Send commands terminated with a newline.

- `rotate <angle>` — rotate by `<angle>` degrees. Positive = clockwise, negative = counter-clockwise.

Examples:

- `rotate 90`  — rotate 90 degrees clockwise
- `rotate -30` — rotate 30 degrees counter-clockwise

## Usage

1. Wire the motor and driver as shown above.
2. Open `stepperMotor-testing.ino` in the Arduino IDE.
3. Select the correct board and port.
4. Upload the sketch to your Arduino.
5. Open Serial Monitor at 9600 baud and type `rotate 90` (or another angle) and press send.

## Troubleshooting

- Motor doesn't move:
  - Check wiring and that the ULN2003 board has 5V power.
  - Ensure GND is connected between Arduino and driver board.
  - Try a lower speed (reduce RPM).

- Motor stutters or is weak:
  - Increase power supply current if using external supply.
  - Verify correct stepper type and stepsPerRevolution value.

## Extending this project

- Track absolute position by maintaining a position variable in the sketch.
- Add acceleration/deceleration profiles for smoother motion.
- Replace `Stepper` with `AccelStepper` library for more features.

## License

MIT
