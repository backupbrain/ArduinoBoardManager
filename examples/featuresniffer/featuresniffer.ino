#include <ArduinoBoardManager.h>


Arduino arduino = Arduino();

void setup() {
  unsigned long M = 1000000;
  unsigned int k = 1000;
  Serial.begin(9600);
  
  Serial.print("Board is an Arduino ");
  Serial.println(arduino.BOARD_NAME);
  Serial.println();
  
  Serial.print("SDK Version is: ");
  Serial.println(Arduino::SDK_VERSION);
  Serial.println();
  
  Serial.print("This "); Serial.print(arduino.BOARD_NAME);
  Serial.print(" is an "); Serial.print(Arduino::NUM_BITS);
  Serial.print("-bit, "); Serial.print(Arduino::MAX_MHZ/M);
  Serial.print("Mhz processor with "); Serial.print(Arduino::SRAM_SIZE/k);
  Serial.print("k of SRAM and "); Serial.print(Arduino::FLASH_SIZE/k);
  Serial.println("k of flash.");
  Serial.println();
  
  if (arduino.featureExists(Arduino::FEATURE_MULTIPLE_SERIAL)) {
    Serial.println("Your board supports multiple serial connections");
  } else {
    Serial.println("Your board only supports one serial connection");
  }
}

void loop() {
}
