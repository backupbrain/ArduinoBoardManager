/*-------------------------------------------------------------------------
  Arduino library to determine the Arduino models and features,
  as well as the SDK version.

  Most features can be accessed via static variables.
  You must instantiate if you want to know if the name of the board
  or if specific features such exist, for example multiple serial 
  connections on the Arduino Mega.

  This list may be neither comprehensive nor up to date
  
  A full list of boards and processor names are available on Wikipedia:
  https://en.wikipedia.org/wiki/List_of_Arduino_boards_and_compatible_systems

  @author Tony Gaitatzis backupbrain@gmail.com
  @date 2015-12-10

  -------------------------------------------------------------------------
  This file is part of the Arduino Board Manager library

  NeoPixel is free software: you can redistribute it and/or modify
  it under the terms of the GNU Lesser General Public License as
  published by the Free Software Foundation, either version 3 of
  the License, or (at your option) any later version.

  NeoPixel is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with NeoPixel.  If not, see
  <http://www.gnu.org/licenses/>.
  -------------------------------------------------------------------------*/
  
#if ARDUINO >= 100
  #include <Arduino.h>
#else
  #include <WProgram.h>
#endif

class ArduinoBoardManager {
 public:
  /**
   * Arduino IDE/SDK Version
   */
  static const uint16_t SDK_VERSION = ARDUINO;        /**< Arduino SDK Version */

  /**
   * Board Name 
   */
  static const uint8_t MAX_BOARD_NAME_LENGTH = 16; 
  static const uint8_t MAX_CPU_NAME_LENGTH = 16;        
  char BOARD_NAME[MAX_BOARD_NAME_LENGTH];                       /**< When instantiated, this is the board name, eg "UNO" */    
  char CPU_NAME[MAX_CPU_NAME_LENGTH];                       /**< When instantiated, this is the cpu name, eg "__AVR_ATmega328P__" */

  /**
   * Known Board Models 
   */
  static const uint8_t BOARD_UNKNOWN = 0x0;
  static const uint8_t BOARD_UNO = 0x01;
  static const uint8_t BOARD_ZERO = 0x02;
  static const uint8_t BOARD_DUE = 0x03;
  static const uint8_t BOARD_MICRO= 0x04;
  static const uint8_t BOARD_YUN_400 = 0x05;
  static const uint8_t BOARD_LEONARDO = 0x06;
  static const uint8_t BOARD_MEGA = 0x07;
  static const uint8_t BOARD_NANO = 0x08;
  static const uint8_t BOARD_NANO_3 = 0x09;
  static const uint8_t BOARD_LILYPAD = 0x0a;
  static const uint8_t BOARD_LILYPAD_2 = 0x0b;
  static const uint8_t BOARD_TRINKET = 0x0c;
  static const uint8_t BOARD_101 = 0x0d;

  /**
   * Known Arduino Features 
   */
  static const uint8_t NUM_FEATURES = 1;
  static const uint8_t FEATURE_MULTIPLE_SERIAL = 0x00;
  static const uint8_t FEATURE_BLUETOOTH_4 = 0x01;
  static const uint8_t FEATURE_ACCELEROMETER = 0x02;
  static const uint8_t FEATURE_GYROSCOPE = 0x03;
  static const uint8_t FEATURE_ANALOG_OUT = 0x04;

  /**
   * CPU speed
   */
  static const unsigned long MAX_MHZ = F_CPU;
  
  boolean FEATURES[NUM_FEATURES];
  
  /**
   * CPU Specifications
   */
#if defined(__AVR_ATmega328P__) // uno, fio
  static const uint8_t BOARD = 0x01;           /**< UNO board */
  static const uint8_t NUM_BITS = 8;            /**< 8-bit processor */
  static const uint16_t CPU = __AVR_ATmega328P__;     /**< 16Mhz */
  static const unsigned long SRAM_SIZE = 2000;       /**< 2kb of sram */
  static const unsigned long EEPROM_SIZE = 1000;     /**< 1kb eeprom */
  static const unsigned long FLASH_SIZE = 32000;     /**< 32k flash storage */
#elif defined(__AVR_ATSAMD21G18A__) // zero
  static const uint8_t BOARD = 0x02
  static const uint8_t NUM_BITS = 8;
  static const uint16_t CPU = __AVR_ATSAMD21G18A__;
  static const unsigned long SRAM_SIZE = 32000;
  static const unsigned long EEPROM_SIZE = 16000;
  static const unsigned long FLASH_SIZE = 256000;
#elif defined(__AVR_ATSAM3X8E__) // Due
  static const uint8_t BOARD = 0x03;
  static const uint8_t NUM_BITS = 8;
  static const uint16_t CPU = __AVR_ATSAMD21G18A__;
  static const unsigned long SRAM_SIZE = 96000;
  static const unsigned long EEPROM_SIZE = 0;
  static const unsigned long FLASH_SIZE = 512000;
#elif defined(__AVR_ATmega32U4__) // Yun 16Mhz, Micro, Leonardo, Esplora
  static const uint8_t BOARD = 0x04;
  static const uint8_t NUM_BITS = 8;
  static const uint16_t CPU = __AVR_Atmega32U4__;
  static const unsigned long SRAM_SIZE = 2500;
  static const unsigned long EEPROM_SIZE = 1000;
  static const unsigned long FLASH_SIZE = 32000;
#elif defined(_AVR_AR9331__) // Yun 400Mhz
  static const uint8_t BOARD = 0x05;
  static const uint8_t NUM_BITS = 8;
  static const uint16_t CPU = _AVR_AR9331__;
  static const unsigned long SRAM_SIZE = 64000000;
  static const unsigned long EEPROM_SIZE = 0;
  static const unsigned long FLASH_SIZE = 16000000;
#elif defined(__AVR_ATmega16U4__) // leonardo
  static const uint8_t BOARD = 0x06;
  static const uint8_t NUM_BITS = 8;
  static const uint16_t CPU = __AVR_ATmega16U4__;
  static const unsigned long SRAM_SIZE = 2560;
  static const unsigned long EEPROM_SIZE = 1000;
  static const unsigned long FLASH_SIZE = 32000;
#elif defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__) // mega, Mega ADK
  static const uint8_t BOARD = 0x07;
  static const uint8_t NUM_BITS = 8;
  static const uint16_t CPU = __AVR_ATmega1280__;
  static const unsigned long SRAM_SIZE = 8000;
  static const unsigned long EEPROM_SIZE = 4000;
  static const unsigned long FLASH_SIZE = 256000;
#elif defined(_AVR_ATmega328__) // Nano >= v3.0 or Arduino Pro, pro328, ethernet
  static const uint8_t BOARD = 0x08;
  static const uint8_t NUM_BITS = 8;
  static const uint16_t CPU = _AVR_ATmega328__;
  static const unsigned long SRAM_SIZE = 2000;
  static const unsigned long EEPROM_SIZE = 1000;
  static const unsigned long FLASH_SIZE = 32000;
#elif defined(_AVR_ATmega168__) // Nano < v3.0 or uno, pro
  static const uint8_t BOARD = 0x09;
  static const uint8_t NUM_BITS = 8;
  static const uint16_t CPU = _AVR_ATmega168;
  static const unsigned long SRAM_SIZE = 1000;
  static const unsigned long EEPROM_SIZE = 500;
  static const unsigned long FLASH_SIZE = 16000;
#elif defined(_AVR_ATmega168V__) // LilyPad
  static const uint8_t BOARD = 0x0a;
  static const uint8_t CPU = _AVR_ATmega168V__;
  static const unsigned int NUM_BITS = 8;
  static const unsigned long SRAM_SIZE = 1000;
  static const unsigned long EEPROM_SIZE = 500;
  static const unsigned long FLASH_SIZE = 14000
#elif defined(_AVR_ATmega328V__) // LilyPad 2
  static const uint8_t BOARD = 0x0b;
  static const uint8_t CPU = _AVR_ATmega328V__;
  static const unsigned int NUM_BITS = 8;
  static const unsigned long SRAM_SIZE = 1000;
  static const unsigned long EEPROM_SIZE = 500;
  static const unsigned long FLASH_SIZE = 14000
#elif defined(_AVR_ATTiny85__) // trinket
  static const uint8_t BOARD = 0x0c;
  static const uint8_t NUM_BITS = 8;
  static const uint16_t CPU = _AVR_ATTiny85__;
  static const unsigned long SRAM_SIZE = 500;
  static const unsigned long EEPROM_SIZE = 500;
  static const unsigned long FLASH_SIZE = 2500;
#elif  defined(__AVR_ARCv2EM__) || (__CURIE_FACTORY_DATA_H_) // Intel Curie/101
  static const uint8_t BOARD = 0x0d;
  static const uint8_t NUM_BITS = 32;
  static const uint16_t CPU = __AVR_ARCv2EM__;
  static const unsigned long SRAM_SIZE = 24000; // might be 80k?
  static const unsigned long EEPROM_SIZE = 0;
  static const unsigned long FLASH_SIZE = 384000;
#else
  static const uint8_t BOARD = 0x00;
  static const uint8_t NUM_BITS = 0;
  static const uint16_t CPU = 0;
  static const unsigned long SRAM_SIZE = 0;
  static const unsigned long EEPROM_SIZE = 0;
  static const unsigned long FLASH_SIZE = 0;
#endif

  /**
   * Instantiate board Manager
   */
  ArduinoBoardManager();
  
  /**
   * Ask if a specific feature exists, e.g. Arduino::FEATURE_MULTIPLE_SERIAL
   * 
   * @param feature  an unsigned int, e.g. FEATURE_MULTIPLE_SERIAL
   * @return true if feature exists, false if feature does not exist
   */
  bool featureExists(uint8_t feature);
  
};

