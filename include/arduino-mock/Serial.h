/**
 * Arduino Serial mock
 */
#ifndef SERIAL_H
#define SERIAL_H

#include <stdint.h>
#include <gmock/gmock.h>

#define DEC 10
#define HEX 16
#define OCT 8
#define BIN 2

class SerialMock {
  public:
    virtual MOCK_METHOD0(getWriteError, int());
    virtual MOCK_METHOD0(clearWriteError, void());
    virtual MOCK_METHOD1(write, size_t(uint8_t));
    virtual MOCK_METHOD1(write, size_t(const char *str));
    virtual MOCK_METHOD2(write, size_t(const uint8_t *buffer, size_t size));

    virtual MOCK_METHOD1(print, size_t(const char[]));
    virtual MOCK_METHOD1(print, size_t(char));
    virtual MOCK_METHOD2(print, size_t(unsigned char, int));
    virtual MOCK_METHOD2(print, size_t(int, int));
    virtual MOCK_METHOD2(print, size_t(unsigned int, int));
    virtual MOCK_METHOD2(print, size_t(long, int));
    virtual MOCK_METHOD2(print, size_t(unsigned long, int));
    virtual MOCK_METHOD2(print, size_t(double, int));

    virtual MOCK_METHOD1(println, size_t(const char[]));
    virtual MOCK_METHOD1(println, size_t(char));
    virtual MOCK_METHOD2(println, size_t(int, int));
    virtual MOCK_METHOD0(println, size_t(void));

    virtual MOCK_METHOD1(begin, uint8_t(uint16_t));

    virtual MOCK_METHOD0(available, uint8_t());
    virtual MOCK_METHOD0(read, uint8_t());

    virtual MOCK_METHOD0(flush, void());

    /* Not implemented yet
    MOCK_METHOD2(println, size_t(unsigned char, int));
    MOCK_METHOD2(println, size_t(unsigned int, int));
    MOCK_METHOD2(println, size_t(long, int));
    MOCK_METHOD2(println, size_t(unsigned long, int));
    MOCK_METHOD2(println, size_t(double, int));
    */
};

class Serial_ {

  private:
    static bool printToCout;

  public:
    static void setPrintToCout(bool flag);

  public:
    static size_t print(const char[]);
    static size_t print(char);
    static size_t print(unsigned char, int = DEC);
    static size_t print(int, int = DEC);
    static size_t print(unsigned int, int = DEC);
    static size_t print(long, int = DEC);
    static size_t print(unsigned long, int = DEC);
    static size_t print(double, int = 2);

    static size_t println(const char[]);
    static size_t println(char);
    static size_t println(unsigned char, int = DEC);
    static size_t println(int, int = DEC);
    static size_t println(unsigned int, int = DEC);
    static size_t println(long, int = DEC);
    static size_t println(unsigned long, int = DEC);
    static size_t println(double, int = 2);
    static size_t println(void);

    size_t write(uint8_t);
    size_t write(const char *str);
    size_t write(const uint8_t *buffer, size_t size);

    uint8_t begin(uint32_t);

    uint8_t available();
    uint8_t read();

    static void flush();

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
};
extern Serial_ Serial;

SerialMock* serialMockInstance();
SerialMock* serialMockInstance(SerialMock*& mock);
void releaseSerialMock();
void releaseSerialMock(bool clean);

#endif // SERIAL_H
