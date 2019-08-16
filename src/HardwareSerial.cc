// Copyright 2014 http://switchdevice.com

#include "HardwareSerial.h"

//static SerialMock* gSerialMock = NULL;

static HardwareSerialMock* gHardwareSerialMock[ARDUINO_MOCK_HARDWARE_SERIAL_COUNT_] = {
  nullptr, nullptr, nullptr, nullptr
};

HardwareSerialMock* hardwareSerialMockInstance(const unsigned char& no) {
  if (no >= 0 && no < ARDUINO_MOCK_HARDWARE_SERIAL_COUNT_) {
    if (!(gHardwareSerialMock[no])) {
      gHardwareSerialMock[no] = new HardwareSerialMock(no);
    }
    else {
      std::cout << "Warning: Hardware Serial Mock Instance no " << no
        << " requested multiple times" << std::endl;
    }
    return gHardwareSerialMock[no];
  }
  else {
    return nullptr;
  }
}

void releaseHardwareSerialMock(const unsigned char& no) {
  if (no >= 0 && no < ARDUINO_MOCK_HARDWARE_SERIAL_COUNT_) {
    if (gHardwareSerialMock[no]) {
      delete gHardwareSerialMock[no];
      gHardwareSerialMock[no] = nullptr;
    }
    else {
      std::cout << "Warning: Trying to release undefined Hardware Serial Mock Instance no "
        << no << std::endl;
    }
  }
}

HardwareSerialMock* serialMockInstance() {
  return hardwareSerialMockInstance(0);
}

void releaseSerialMock() {
  releaseHardwareSerialMock(0);
}

HardwareSerial_::HardwareSerial_(const unsigned char& no) : no_(no) {}

size_t HardwareSerial_::print(const char *s) {
  return (gHardwareSerialMock[no_])->print(s);
}

size_t HardwareSerial_::print(char c) {
  return (gHardwareSerialMock[no_])->print(c);
}

size_t HardwareSerial_::print(unsigned char c, int base) {
  return (gHardwareSerialMock[no_])->print(c, base);
}

size_t HardwareSerial_::print(int num, int base) {
  return (gHardwareSerialMock[no_])->print(num, base);
}

size_t HardwareSerial_::print(unsigned int num, int base) {
  return (gHardwareSerialMock[no_])->print(num, base);
}

size_t HardwareSerial_::print(long num, int base) {
  return (gHardwareSerialMock[no_])->print(num, base);
}

size_t HardwareSerial_::print(unsigned long num, int base) {
  return (gHardwareSerialMock[no_])->print(num, base);
}

size_t HardwareSerial_::print(double num, int digits) {
  return (gHardwareSerialMock[no_])->print(num, digits);
}

size_t HardwareSerial_::println(const char *s) {
  return (gHardwareSerialMock[no_])->println(s);
}

size_t HardwareSerial_::println(char c) {
  return (gHardwareSerialMock[no_])->println(c);
}

size_t HardwareSerial_::println(unsigned char c, int base) {
  return (gHardwareSerialMock[no_])->println(c, base);
}

size_t HardwareSerial_::println(int num, int base) {
  return (gHardwareSerialMock[no_])->println(num, base);
}

size_t HardwareSerial_::println(unsigned int num, int base) {
  return (gHardwareSerialMock[no_])->println(num, base);
}

size_t HardwareSerial_::println(long num, int base) {
  return (gHardwareSerialMock[no_])->println(num, base);
}

size_t HardwareSerial_::println(unsigned long num, int base) {
  return (gHardwareSerialMock[no_])->println(num, base);
}

size_t HardwareSerial_::println(double num, int digits) {
  return (gHardwareSerialMock[no_])->println(static_cast<int>(num), digits);
}

size_t HardwareSerial_::println(void) {
  return (gHardwareSerialMock[no_])->println();
}

size_t HardwareSerial_::readBytes(char *buffer, size_t length) {
  return (gHardwareSerialMock[no_])->readBytes(buffer, length);
}

size_t HardwareSerial_::readBytes(uint8_t *buffer, size_t length) {
  return (gHardwareSerialMock[no_])->readBytes(buffer, length);
}

size_t HardwareSerial_::write(uint8_t val) {
  return (gHardwareSerialMock[no_])->write(val);
}

size_t HardwareSerial_::write(const char *str) {
  return (gHardwareSerialMock[no_])->write(str);
}

size_t HardwareSerial_::write(const uint8_t *buffer, size_t size) {
  return (gHardwareSerialMock[no_])->write(buffer, size);
}

int HardwareSerial_::availableForWrite() {
  return (gHardwareSerialMock[no_])->availableForWrite();
}

uint8_t HardwareSerial_::begin(uint32_t port) {
  return (gHardwareSerialMock[no_])->begin(port);
}

int HardwareSerial_::peek() {
  return (gHardwareSerialMock[no_])->peek();
}

void HardwareSerial_::flush() {
  return (gHardwareSerialMock[no_])->flush();
}

int HardwareSerial_::available() {
  return (gHardwareSerialMock[no_])->available();
}

int HardwareSerial_::read() {
  return (gHardwareSerialMock[no_])->read();
}

HardwareSerial_::operator bool() const {
  return (gHardwareSerialMock[no_])->available();
}

void HardwareSerial_::setTimeout(unsigned long timeout) {
  (gHardwareSerialMock[no_])->setTimeout(timeout);
}

unsigned long HardwareSerial_::getTimeout() {
  return (gHardwareSerialMock[no_])->getTimeout();
}

bool HardwareSerial_::find(char *target) {
  return (gHardwareSerialMock[no_])->find(target);
}

bool HardwareSerial_::find(uint8_t *target) {
  return (gHardwareSerialMock[no_])->find(target);
}

bool HardwareSerial_::find(char *target, size_t length) {
  return (gHardwareSerialMock[no_])->find(target, length);
}

bool HardwareSerial_::find(uint8_t *target, size_t length) {
  return (gHardwareSerialMock[no_])->find(target, length);
}

// Preinstantiate Objects
HardwareSerial_ Serial(0);
HardwareSerial_ Serial1(1);
HardwareSerial_ Serial2(2);
HardwareSerial_ Serial3(3);
