# Arduino Reaction Time Game

An Arduino-based reaction time game that uses randomized LED patterns, a pushbutton, and a buzzer to measure and track a player's reaction time.

## Features

- Generates a randomized LED sequence before each round
- Uses three LEDs to signal when the player should react
- Measures reaction time in milliseconds
- Tracks the fastest reaction time across multiple rounds
- Sounds a buzzer when the player presses the button
- Displays reaction times through the Arduino Serial Monitor
- Combines standard Arduino functions with low-level register manipulation

## Hardware

- Arduino Uno
- 3 LEDs
- Pushbutton
- Buzzer
- Resistors
- Breadboard
- Jumper wires

## Technologies

- Arduino C/C++
- Arduino IDE
- Digital and analog I/O
- AVR register manipulation
- Serial communication

## How It Works

At the beginning of each round, the program displays "Get Ready..." through the Serial Monitor and generates a randomized sequence in which the three LEDs flash in varying patterns.

After the randomized sequence finishes, all three LEDs turn on simultaneously to signal the player to press the button. The program records the starting time using `millis()` and waits for the button press.

When the player presses the button, the program calculates the elapsed time in milliseconds, turns off the LEDs, and sounds the buzzer. The player's reaction time is then displayed through the Serial Monitor.

The program also compares each result with the current best time and stores the fastest reaction time.

## Low-Level Hardware Control

The project uses direct AVR register manipulation in addition to standard Arduino functions. The `DDRB` register configures the LED pins as outputs, while `PORTB` is used to turn all three LEDs on and off simultaneously.

This demonstrates both higher-level Arduino programming and lower-level control of the Arduino Uno's microcontroller.

## Project Background

Developed as a hands-on Arduino project while studying Computer Engineering at Regent University.
