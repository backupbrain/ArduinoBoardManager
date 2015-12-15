#include "ArduinoBoardManager.h"


Arduino arduino = Arduino();

void setup() {
  unsigned long M = 1000000;
  unsigned int k = 1000;
  Serial.begin(9600);
  
  // The Arduino board name
  Serial.print("Board is compatible with Arduino ");
  Serial.println(arduino.BOARD_NAME);
  Serial.println();
  
  // the Arduino SDK version
  Serial.print("SDK Version is: ");
  Serial.println(Arduino::SDK_VERSION);
  Serial.println();
  
  // The processor features (RAM, speed, etc)
  Serial.print("This "); Serial.print(arduino.BOARD_NAME);
  Serial.print(" is an "); Serial.print(Arduino::NUM_BITS);
  Serial.print("-bit, "); Serial.print(Arduino::MAX_MHZ/M);
  Serial.print("Mhz processor with "); Serial.print(Arduino::SRAM_SIZE/k);
  Serial.print("k of SRAM and "); Serial.print(Arduino::FLASH_SIZE/k);
  Serial.println("k of flash.");
  Serial.println();
  
  // Board features (multiple serial ports on Mega, for example)
  if (arduino.featureExists(Arduino::FEATURE_MULTIPLE_SERIAL)) {
    Serial.println("Your board supports multiple serial connections");
  } else {
    Serial.println("Your board only supports one serial connection");
  }

  if (arduino.featureExists(Arduino::FEATURE_ANALOG_OUT)) {
    Serial.println("Your board supports analog out");
  }
  if (arduino.featureExists(Arduino::FEATURE_BLUETOOTH_4)) {
    Serial.println("Your board supports bluetooth 4");
  }
}


void loop() {
}
