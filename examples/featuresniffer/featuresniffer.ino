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
  Serial.print("k of SRAM, "); Serial.print(ArduinoBoardManager::EEPROM_SIZE/k);
  Serial.print("k of EEPROM and "); Serial.print(ArduinoBoardManager::FLASH_SIZE/k);
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
