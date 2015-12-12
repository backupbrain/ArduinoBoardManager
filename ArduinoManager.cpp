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

Arduino::Arduino() {
  // clear the features
  memset(FEATURES, false, NUM_FEATURES);


#if defined(__AVR_ATmega328P__) || defined(__AVR_ATmega168__)
  char* boardName = "UNO";
#elif defined(__AVR_ATmega32U4__) || defined(__AVR_ATmega16U4__)
  char* boardName = "Leonardo";
#elif defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
  char* boardName = "Mega";
  FEATURES[Arduino::FEATURE_MULTIPLE_SERIAL] = true;
#else
  const char* boardName = "UNKNOWN";
#endif

  strcpy(BOARD_NAME, boardName);
}


bool Arduino::featureExists(unsigned int feature) {
  if ((feature < Arduino::NUM_FEATURES) &&
     (Arduino::FEATURES[feature]))
      return true;
  return false;
}

