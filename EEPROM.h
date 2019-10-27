/**
EEPROM mock
**/

#ifndef __EEPROM_h__
#define __EEPROM_h__

#include <stdint.h>

#ifdef ARDUINO_MOCK_EEPROM
#include <memory>
#endif

#include <gmock/gmock.h>

class EEPROM_ {
  public:
    uint8_t read(int a);
    void write(int a,  uint8_t b);
};
extern EEPROM_ EEPROM;

#ifdef ARDUINO_MOCK_EEPROM

class EEPROMMock {
  public:
    MOCK_METHOD1(read, uint8_t(int));
    MOCK_METHOD2(write, void(int, uint8_t));
};

#else

class EEPROMMock {
public:
  EEPROMMock();

  uint8_t read(int a);
  void write(int a, uint8_t b);

  const size_t Size = 0xffff;
  std::unique_ptr<uint8_t[]> Buffer;
};

#endif

EEPROMMock* EEPROMMockInstance();
void releaseEEPROMMock();
#endif
