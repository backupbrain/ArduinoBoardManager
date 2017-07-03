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
  
#include "ArduinoBoardManager.h"

ArduinoBoardManager::ArduinoBoardManager() {
  // clear the features
    m_features = 0;

  switch (ArduinoBoardManager::BOARD) {
    case ArduinoBoardManager::BOARD_UNO:
      strcpy(BOARD_NAME, "UNO");
      strcpy(CPU_NAME, "ATmega328P");
    break;
    case ArduinoBoardManager::BOARD_ZERO:
      strcpy(BOARD_NAME, "Zero");
      strcpy(CPU_NAME, "ATSAMD21G18A");
      m_features = FEATURE_ANALOG_OUT;
    break;
    case ArduinoBoardManager::BOARD_DUE:
      strcpy(BOARD_NAME, "Due");
      strcpy(CPU_NAME, "ATSAM3X8E");
      m_features = FEATURE_ANALOG_OUT;
    break;
    case ArduinoBoardManager::BOARD_MICRO:
      strcpy(BOARD_NAME, "Micro");
      strcpy(CPU_NAME, "Atmega32U4");
    break;
    case ArduinoBoardManager::BOARD_YUN_400:
      strcpy(BOARD_NAME, "Yun");
      strcpy(CPU_NAME, "AR9331");
    break;
    case ArduinoBoardManager::BOARD_LEONARDO:
      strcpy(BOARD_NAME, "Leonardo");
      strcpy(CPU_NAME, "ATmega16U4");
    break;
    case ArduinoBoardManager::BOARD_MEGA:
      strcpy(BOARD_NAME, "Mega");
      strcpy(CPU_NAME, "ATmega1280");
      m_features = FEATURE_MULTIPLE_SERIAL;
    break;
    case ArduinoBoardManager::BOARD_NANO:
      strcpy(BOARD_NAME, "Nano");
      strcpy(CPU_NAME, "ATmega168");
    break;
    case ArduinoBoardManager::BOARD_NANO_3:
      strcpy(BOARD_NAME, "Nano");
      strcpy(CPU_NAME, "ATmega328");
    break;
    case ArduinoBoardManager::BOARD_LILYPAD:
      strcpy(BOARD_NAME, "Lilypad");
      strcpy(CPU_NAME, "ATmega168V");
    break;
    case ArduinoBoardManager::BOARD_LILYPAD_2:
      strcpy(BOARD_NAME, "Lilypad");
      strcpy(CPU_NAME, "ATmega328V");
    break;
    case ArduinoBoardManager::BOARD_TRINKET:
      strcpy(BOARD_NAME, "Trinket");
      strcpy(CPU_NAME, "ATTiny85");
    break;
    case ArduinoBoardManager::BOARD_101:
      strcpy(BOARD_NAME, "101");
      strcpy(CPU_NAME, "ARCv2EM");
      m_features = FEATURE_BLUETOOTH_4 | FEATURE_ACCELEROMETER | FEATURE_GYROSCOPE;
    break;
    default:
      strcpy(BOARD_NAME, "Unknown");
      strcpy(CPU_NAME, "Unknown");
    break;
  }
}

bool ArduinoBoardManager::featureExists(uint8_t feature) {
    return m_features & feature;
}

