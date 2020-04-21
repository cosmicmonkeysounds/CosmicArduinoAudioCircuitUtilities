# Cosmic Arduino Audio Circuit Utilities

A (hopefully) comprehensive, lightweight Arduino library and interface for developing hybrid audio circuits.

## Prerequisites

Only need the Arduino IDE!

## Structure

### AudioCircuitUtilities.ino (main)

Holds the global variables, set up logic, main loop, and a custom type called "State".
State is the type that you expand upon to handle all the functionality of whatever interface you want to build.

### button_lib.h

A simple "button" type that reads (and debounces) a pushbutton from a digital pin.
The "onOrOff" member variable can be switched on or off, and used by State in main to do whatever you'd like.

### led_lib.h

A stupid simple way of keeping track of LED status's.

### potentiometer_lib.h

Another simple library that reads a 10-bit value from an analog pin and stores it, with a function to map that 10-bit number to an 8-bit number for PWM use.

## Authors

* **John Janigan-Mills** - *Initial work, project head* - [Cosmic Monkey Sounds](http://cosmicmonkeysounds.com)

## License

This project is licensed under the GPLv3 - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments

* Hat tip to anyone whose code was used
* Inspiration
* etc

