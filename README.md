# Cosmic Arduino Audio Circuit Utilities

A (hopefully) comprehensive, lightweight Arduino library and interface for developing hybrid audio circuits.

## Prerequisites

Only need the Arduino IDE!

## CosmicArduinoAudioCircuitUtilities.ino (main)

Holds basic Arduino setup and loop stuff, and initializes and instance of State.

### State.h

A singleton that holds all references to all hardware components and functions to use those components.

### DigitalDevice.h

Basic implementation for a read/write digital device that is a base class to all other digital components.

### LED.h

A stupid simple DigitalDevice derived class for digital LED outputs.

### PushButton.h

A stupid simple on/off DigitalDevice derived class with debounce.

### AnalogDevice.h

Basic implementation of a read/write analog device.

### Potentiometer.h

A simple potentiometer implementation with that stores an average value to avoid jittering, and a few conversion functions for different bit depths.

### PWM.h

Basic PWM pin.

### OptoFET.h

Basic Opto in.

## OptoVoltMeter.ino

A simple volt meter implementation that determines the value of the opto-coupler at every DAC value and prints it the Serial buss.

### SerialToCSV.py

A little helper script that takes those Serial buss messages and parses them to a CSV file.

## Authors

* **John Janigan-Mills** - *Chief-Maniac-in-charge* - [Cosmic Monkey Sounds](http://cosmicmonkeysounds.com)

## License

This project is licensed under the GPLv3 - see the [LICENSE.md](LICENSE.md) file for details

