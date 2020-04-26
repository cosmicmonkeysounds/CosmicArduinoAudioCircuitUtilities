# Cosmic Arduino Audio Circuit Utilities

A (hopefully) comprehensive, lightweight Arduino library and interface for developing hybrid audio circuits.

## Prerequisites

Only need the Arduino IDE!

## Structure

### CosmicArduinoAudioCircuitUtilities.ino (main)

Holds basic Arduino setup and loop stuff, and initializes and instance of State.

### State.h

A singleton that holds all references to all hardware components and functions to use those components.

### DigitalDevice.h

Basic implementation for a read/write digital device that is a base class to all other digital components.

### LED.h

A stupid simple DigitalDevice derived class for digital LED outputs.

### PushButton.h

A stupid simple on/off DigitalDevice derived class with debounce.

## Authors

* **John Janigan-Mills** - *Chief-Maniac-in-charge* - [Cosmic Monkey Sounds](http://cosmicmonkeysounds.com)

## License

This project is licensed under the GPLv3 - see the [LICENSE.md](LICENSE.md) file for details

