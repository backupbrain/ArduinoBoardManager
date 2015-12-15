# ArduinoBoardManager


Arduino library to determine the Arduino models and features, as well as the SDK version.

Most features can be accessed via static variables.

You must instantiate if you want to know if the name of the board or if specific features such exist, for example multiple serial connections on the Arduino Mega.

**This list may be neither comprehensive nor up to date**

A full [List of boards and processor names][arduino_wiki] are available on Wikipedia:

For more information, please see my blog article titled [Determine Arduino Board Model and Version Programmatically][blog_article]

## Installation

After downloading, rename folder to 'ArduinoManager' and install in Arduino Libraries folder. Restart Arduino IDE, then open File->Sketchbook->Library->ArduinoManager->featuresniffer sketch.

## Usage
```c
#include <ArduinoBoardManager.h>


ArduinoBoardManager arduino = ArduinoBoardManager();

void setup() {
  unsigned long M = 1000000;
  unsigned int k = 1000;
  Serial.begin(9600);

  while(!Serial); // on Leonardo/Micro, wait for serial
  
  // The Arduino board name
  Serial.print("Board is compatible with Arduino ");
  Serial.println(arduino.BOARD_NAME);
  Serial.println();
  
  // the Arduino SDK version
  Serial.print("SDK Version is: ");
  Serial.println(ArduinoBoardManager::SDK_VERSION);
  Serial.println();
  
  // The processor features (RAM, speed, etc)
  Serial.print("This "); Serial.print(arduino.BOARD_NAME);
  Serial.print(" is an "); Serial.print(ArduinoBoardManager::NUM_BITS);
  Serial.print("-bit, "); Serial.print(ArduinoBoardManager::MAX_MHZ/M);
  Serial.print("Mhz processor with "); Serial.print(ArduinoBoardManager::SRAM_SIZE/k);
  Serial.print("k of SRAM and "); Serial.print(ArduinoBoardManager::FLASH_SIZE/k);
  Serial.println("k of flash.");
  Serial.println();
  
  // Board features (multiple serial ports on Mega, for example)
  if (arduino.featureExists(ArduinoBoardManager::FEATURE_MULTIPLE_SERIAL)) {
    Serial.println("Your board supports multiple serial connections");
  } else {
    Serial.println("Your board only supports one serial connection");
  }

  if (arduino.featureExists(ArduinoBoardManager::FEATURE_ANALOG_OUT)) {
    Serial.println("Your board supports analog out");
  }
  if (arduino.featureExists(ArduinoBoardManager::FEATURE_BLUETOOTH_4)) {
    Serial.println("Your board supports bluetooth 4");
  }
}


void loop() {
}
```

Serial output will resemble this (tested of Arduino UNO)

```
Board is compatible with Arduino UNO

SDK Version is: 10604

This UNO is an 8-bit, 16Mhz processor with 2k of SRAM and 32k of flash.

Your board only supports one serial connection.
```

[arduino_wiki]:	https://en.wikipedia.org/wiki/List_of_Arduino_boards_and_compatible_systems
[blog_article]:	http://tonygaitatzis.tumblr.com/post/134967126657/determine-arduino-board-model-and-version


