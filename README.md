# TTKIOT-SB-DM

This is a sample firmware to explore a few functions of the embedded RGB LED strip of the prototype board TTKIOT-SB-DM.

![TTKIOT-SB-DM](https://github.com/TTKLabs/TTKIOT-SB-DM/blob/main/doc/ttkiot-sb-dm.gif)

## Installation
If you are not familiar with Arduino coding, below you will find the steps to load this demo code in your board.

 1. You will need to install the Arduino IDE (download [here](https://www.arduino.cc/en/software)). The newer version of the IDE may run too slow in some computers, so you are good to go with version 1.8.19.
 2.  Follow this [tutorial](https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-windows-instructions/) to add the ESP32 core to your Arduino IDE
 3. Clone this repository using Git or download the [zip file](https://github.com/TTKLabs/TTKIOT-SB-DM/archive/refs/heads/main.zip) containing the code.
 4. On ArduinoIDE, open the folder containing the code and select the file TTKIOT-SB-DM.ino
 5. On this file, update your Wifi credentials (SSID and Password)
 6. Go to Tools>Board and select ESP32-PICO-D4
 7. Go to Tools>Manage Libraries and search for the [FastLED](https://github.com/FastLED/FastLED) Library (this is the one that drives the LEDs)
 8. Plug your TTKIOT-SB-DM board to your computer using an USB-C cable (make sure you are using a cable that is able to transmit data)
 9. Select the Port that will show up in the menu Tools>Port
 10. Press the button with a Green arrow or go to menu Sketch>Upload
 11. The code will be compiled and uploaded to your board.

Feel free to play around with this code and explore the board capabilities. This board can do anything that can be done with any ESP board. 
