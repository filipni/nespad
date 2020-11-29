# nespad
Connect an NES-controller to your PC through an Arduino Uno that acts like a keyboard.

<p align="center">
  <img src="nespad.gif" />
</p>

## Requirements
The project is made on an Arduino Uno which normally doesn't have [HID](https://en.wikipedia.org/wiki/Human_interface_devices) support. A workaround for this is to use [HoodLoader2](https://github.com/NicoHood/HoodLoader2) which enables us to directly program the MCU controlling the serial port.

Of course, you will also need to split the cord to an NES controller. This pinout shows how the different colors should be connected.

<p align="center">
  <img src="https://www.igorkromin.net/fp-content/images/snestones/NesSnesPinout.png" />
</p>

Update **nespadIO.ino** to match the digital pins used for **CLOCK**, **LATCH** and **DATA**.

## Installation
Follow [this guide](https://github.com/NicoHood/HoodLoader2/wiki/Uploading-programs) on how to program the different MCUs.
Upload **nespadIO.ino** to the ATMega328 and **nespadUSB.ino** to the ATmega16u2.
