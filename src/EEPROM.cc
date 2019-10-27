/** Implementation of EEPROM mock **/

#include "EEPROM.h"

#ifndef ARDUINO_MOCK_EEPROM
EEPROMMock::EEPROMMock() {
  Buffer = std::make_unique<uint8_t[]>(Size);
}

uint8_t EEPROMMock::read(int a) {
  return Buffer[a];
}
void EEPROMMock::write(int a, uint8_t b) {
  Buffer[a] = b;
}
#endif

static EEPROMMock* p_EEPROMMock = NULL;
EEPROMMock* EEPROMMockInstance() {
  if (!p_EEPROMMock) {
    p_EEPROMMock = new EEPROMMock();
  }
  return p_EEPROMMock;
}

void releaseEEPROMMock() {
  if (p_EEPROMMock) {
    delete p_EEPROMMock;
    p_EEPROMMock = NULL;
  }
}

uint8_t EEPROM_::read(int a) {
  return p_EEPROMMock->read(a);
}

void EEPROM_::write(int a, uint8_t b) {
  p_EEPROMMock->write(a, b);
}

// Preinstantiate Objects
EEPROM_ EEPROM;
