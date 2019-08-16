/**
 * Arduino Hardware Serial mock
 */
#ifndef HARDWARE_SERIAL_H
#define HARDWARE_SERIAL_H

#include <stdint.h>
#include <gmock/gmock.h>

#include "Stream.h"

#define ARDUINO_MOCK_HARDWARE_SERIAL_COUNT_ 4
 // Define constants and variables for buffering incoming serial data.  We're
 // using a ring buffer (I think), in which head is the index of the location
 // to which to write the next incoming character and tail is the index of the
 // location from which to read.
 // NOTE: a "power of 2" buffer size is reccomended to dramatically
 //       optimize all the modulo operations for ring buffers.
 // WARNING: When buffer sizes are increased to > 256, the buffer index
 // variables are automatically increased in size, but the extra
 // atomicity guards needed for that are not implemented. This will
 // often work, but occasionally a race condition can occur that makes
 // Serial behave erratically. See https://github.com/arduino/Arduino/issues/2405
#if !defined(SERIAL_TX_BUFFER_SIZE)
#if ((RAMEND - RAMSTART) < 1023)
#define SERIAL_TX_BUFFER_SIZE 16
#else
#define SERIAL_TX_BUFFER_SIZE 64
#endif
#endif
#if !defined(SERIAL_RX_BUFFER_SIZE)
#if ((RAMEND - RAMSTART) < 1023)
#define SERIAL_RX_BUFFER_SIZE 16
#else
#define SERIAL_RX_BUFFER_SIZE 64
#endif
#endif
#if (SERIAL_TX_BUFFER_SIZE>256)
typedef uint16_t tx_buffer_index_t;
#else
typedef uint8_t tx_buffer_index_t;
#endif
#if  (SERIAL_RX_BUFFER_SIZE>256)
typedef uint16_t rx_buffer_index_t;
#else
typedef uint8_t rx_buffer_index_t;
#endif

// Define config for Serial.begin(baud, config);
#define SERIAL_5N1 0x00
#define SERIAL_6N1 0x02
#define SERIAL_7N1 0x04
#define SERIAL_8N1 0x06
#define SERIAL_5N2 0x08
#define SERIAL_6N2 0x0A
#define SERIAL_7N2 0x0C
#define SERIAL_8N2 0x0E
#define SERIAL_5E1 0x20
#define SERIAL_6E1 0x22
#define SERIAL_7E1 0x24
#define SERIAL_8E1 0x26
#define SERIAL_5E2 0x28
#define SERIAL_6E2 0x2A
#define SERIAL_7E2 0x2C
#define SERIAL_8E2 0x2E
#define SERIAL_5O1 0x30
#define SERIAL_6O1 0x32
#define SERIAL_7O1 0x34
#define SERIAL_8O1 0x36
#define SERIAL_5O2 0x38
#define SERIAL_6O2 0x3A
#define SERIAL_7O2 0x3C
#define SERIAL_8O2 0x3E

#define DEC 10
#define HEX 16
#define OCT 8
#define BIN 2

class HardwareSerialMock : public StreamMock {
public:
  HardwareSerialMock() : No(0) {}
  HardwareSerialMock(const unsigned char& no) : No(no) {}

  MOCK_METHOD0(getWriteError, int());
  MOCK_METHOD0(clearWriteError, void());
  MOCK_METHOD1(write, size_t(uint8_t));
  MOCK_METHOD1(write, size_t(const char *str));
  MOCK_METHOD2(write, size_t(const uint8_t *buffer, size_t size));

  MOCK_METHOD1(print, size_t(const char[]));
  MOCK_METHOD1(print, size_t(char));
  MOCK_METHOD2(print, size_t(unsigned char, int));
  MOCK_METHOD2(print, size_t(int, int));
  MOCK_METHOD2(print, size_t(unsigned int, int));
  MOCK_METHOD2(print, size_t(long, int));
  MOCK_METHOD2(print, size_t(unsigned long, int));
  MOCK_METHOD2(print, size_t(double, int));

  MOCK_METHOD1(println, size_t(const char[]));
  MOCK_METHOD1(println, size_t(char));
  MOCK_METHOD2(println, size_t(int, int));
  MOCK_METHOD0(println, size_t(void));

  MOCK_METHOD1(begin, uint8_t(uint16_t));
  MOCK_METHOD2(begin, void(unsigned long, uint8_t));
  MOCK_METHOD0(end, void(void));

  MOCK_METHOD0(availableForWrite, int());
  MOCK_METHOD0(available, int());
  MOCK_METHOD0(read, int());
  MOCK_METHOD0(peek, int());
  MOCK_METHOD0(flush, void());

  MOCK_METHOD1(setTimeout, void(unsigned long timeout));
  MOCK_METHOD0(getTimeout, unsigned long());

  /* Not implemented yet
  MOCK_METHOD2(println, size_t(unsigned char, int));
  MOCK_METHOD2(println, size_t(unsigned int, int));
  MOCK_METHOD2(println, size_t(long, int));
  MOCK_METHOD2(println, size_t(unsigned long, int));
  MOCK_METHOD2(println, size_t(double, int));
  */

  unsigned char No;
};

typedef HardwareSerialMock SerialMock;

class HardwareSerial_ : public Stream {
public:
  HardwareSerial_(const unsigned char& no);
  size_t print(const char[]);
  size_t print(char);
  size_t print(unsigned char, int = DEC);
  size_t print(int, int = DEC);
  size_t print(unsigned int, int = DEC);
  size_t print(long, int = DEC);
  size_t print(unsigned long, int = DEC);
  size_t print(double, int = 2);

  size_t println(const char[]);
  size_t println(char);
  size_t println(unsigned char, int = DEC);
  size_t println(int, int = DEC);
  size_t println(unsigned int, int = DEC);
  size_t println(long, int = DEC);
  size_t println(unsigned long, int = DEC);
  size_t println(double, int = 2);
  size_t println(void);

  size_t readBytes(char *buffer, size_t length);
  size_t readBytes(uint8_t *buffer, size_t length);

  size_t write(uint8_t);
  size_t write(const char *str);
  size_t write(const uint8_t *buffer, size_t size);

  uint8_t begin(uint32_t);
  void begin(unsigned long, uint8_t);
  void end();

  int availableForWrite();
  int available();
  int read();
  int peek();
  void flush();

  void setTimeout(unsigned long timeout);  // sets maximum milliseconds to wait for stream data, default is 1 second
  unsigned long getTimeout(void);

  bool find(char *target);
  bool find(uint8_t *target);
  bool find(char *target, size_t length);
  bool find(uint8_t *target, size_t length);

  operator bool() const;
  operator Stream&();

  /*
  TODO: Not implemented yet.
  int getWriteError();
  void clearWriteError();
  static size_t print(const __FlashStringHelper *);
  static size_t print(const String &);
  static size_t print(const Printable&);
  static size_t println(const __FlashStringHelper *);
  static size_t println(const String &s);
  static size_t println(const Printable&);
  */

private:
  unsigned char no_;
};

extern HardwareSerial_ Serial;
extern HardwareSerial_ Serial1;
extern HardwareSerial_ Serial2;
extern HardwareSerial_ Serial3;

HardwareSerialMock* serialMockInstance();
void releaseSerialMock();

HardwareSerialMock* hardwareSerialMockInstance(const unsigned char& no);
void releaseHardwareSerialMock(const unsigned char& no);


#endif // HARDWARE_SERIAL_H
