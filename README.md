# Cosmic Arduino Audio Circuit Utilities

A (hopefully) comprehensive, lightweight Arduino library and interface for developing hybrid audio circuits.

## Installation 

Only need the Arduino IDE and this repo!

## CosmicArduinoAudioCircuitUtilities.ino (main)

Holds basic Arduino setup and loop stuff, and initializes and instance of State.

### State.h

A singleton class that holds all references to all hardware components and (eventually) a smathering a different "states" that
the user selects with different pushbuttons and switches that effect everything from the amount of gain in the circuit (through some digital-to-analog part like an optocoupler), to making the LEDs blink crazy colours while ramping the filter frequencies. 

Potentiometers are used to set the "range" of these possible modulations 

### ModMatrix.h

A class that is composed of an array of 10-bit inputs to be used as modulation for all ExternalParts.

## external_parts/ExternalPart.h

A virtual class; all real world parts modeled in some sub-class of ExternalPart, like optocouplers and digital potentiometers. The purpose is to take all the modulation and State data, perform some sort of transfer function to take that data and convert it to the desired parameter change in the analog circuit.

### OptoFET.h

A basic interface for the H11Fx series of OptoFETs.

## input_devices/InputDevice.h

The base class for all components that will have their state read by the MCU, digital or analog. 

### PushButton.h

A stupid simple on/off pushbutton with debounce.

### Potentiometer.h

A simple class that takes the average of values read from the pin an assigns that average to it's currentValue member variable.

## output_devices/OutputDevice.h

The base-class for all analog and digital pin output devices. All ExternalParts own a unique OutputDevice which they use to convert their custom range/transfer/modulation functions to actual values to be outputted by the MCU.

### DacOut.h

A simple n-bit DAC output device.

### PWM.h

A simple 10-bit PWM output device.

### LED.h

A 1-bit, on or off LED output device.

## test_suite/OptoVoltMeter.ino

A simple volt meter implementation that determines the value of the opto-coupler at every DAC value and prints it the Serial buss.

## Authors

* **John Janigan-Mills** - *Chief-Maniac-in-charge* - [Cosmic Monkey Sounds](http://cosmicmonkeysounds.com)

## License

This project is licensed under the GPLv3 - see the [LICENSE.md](LICENSE.md) file for details

