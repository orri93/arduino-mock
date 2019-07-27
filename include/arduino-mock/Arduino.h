/**
 * Arduino mock header
 */
#ifndef ARDUINO_H
#define ARDUINO_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define HIGH 0x1
#define LOW  0x0

#define INPUT 0x0
#define OUTPUT 0x1
#define INPUT_PULLUP 0x2

#ifdef WIN32
#elif linux
#else
#define true 0x1
#define false 0x0
#endif

/*
 * From Arduino.h starting
 *
 */
// undefine stdlib's abs if encountered
#ifdef abs
#undef abs
#endif

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))
#define round(x)     ((x)>=0?(long)((x)+0.5):(long)((x)-0.5))
#define radians(deg) ((deg)*DEG_TO_RAD)
#define degrees(rad) ((rad)*RAD_TO_DEG)
#define sq(x) ((x)*(x))
/*
 * From Arduino.h end
 *
 */


#define PI 3.1415926535897932384626433832795
#define HALF_PI 1.5707963267948966192313216916398
#define TWO_PI 6.283185307179586476925286766559
#define DEG_TO_RAD 0.017453292519943295769236907684886
#define RAD_TO_DEG 57.295779513082320876798154814105

#define SERIAL  0x0
#define DISPLAY 0x1

#define LSBFIRST 0
#define MSBFIRST 1

#define CHANGE 1
#define FALLING 2
#define RISING 3

typedef bool boolean;
typedef uint8_t byte;

void init(void);

void pinMode(uint8_t, uint8_t);
void digitalWrite(uint8_t, uint8_t);
int digitalRead(uint8_t);
int analogRead(uint8_t);
void analogReference(uint8_t mode);
void analogWrite(uint8_t, int);

unsigned long millis(void);
unsigned long micros(void);
void delay(unsigned long);
void delayMicroseconds(unsigned int us);
unsigned long pulseIn(uint8_t pin, uint8_t state, unsigned long timeout);

void shiftOut(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder, uint8_t val);
uint8_t shiftIn(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder);

void attachInterrupt(uint8_t, void (*)(void), int mode);
void detachInterrupt(uint8_t);

void setup(void);
void loop(void);

#ifdef __cplusplus
} // extern "C"
#endif

#include <gmock/gmock.h>

#define UNUSED(expr) do { (void)(expr); } while (0)
#define F(x) (x)

class ArduinoMock {
  protected:
    unsigned long  currentMillis;

  public:
    ArduinoMock();

    virtual unsigned long getMillis() {
      return currentMillis;
    };

    virtual void setMillisRaw(unsigned long milliseconds) {
      currentMillis = milliseconds;
    };
    virtual void setMillisSecs(unsigned long seconds) {
      setMillisRaw(seconds *      1000);
    };
    virtual void setMillisMins(unsigned long minutes) {
      setMillisRaw(minutes *   60 * 1000);
    };
    virtual void setMillisHrs(float         hours)   {
      setMillisRaw(((unsigned long)hours) * 60 * 60 * 1000);
    };

    virtual void addMillisRaw(unsigned long milliseconds) {
      currentMillis += milliseconds;
    };
    virtual void addMillisSecs(unsigned long seconds) {
      addMillisRaw(seconds *      1000);
    };
    virtual void addMillisMins(unsigned long minutes) {
      addMillisRaw(minutes *   60 * 1000);
    };
    virtual void addMillisHrs(float         hours)   {
      addMillisRaw(((unsigned long)hours) * 60 * 60 * 1000);
    };

    virtual MOCK_METHOD2(pinMode, void(uint8_t, uint8_t));
    virtual MOCK_METHOD2(analogWrite, void(uint8_t, int));
    virtual MOCK_METHOD2(digitalWrite, void(uint8_t, uint8_t));
    virtual MOCK_METHOD1(digitalRead, int(int));
    virtual MOCK_METHOD1(analogRead, int(int));
    virtual MOCK_METHOD1(delay, void(int));
    virtual MOCK_METHOD0(millis, unsigned long());
};
ArduinoMock* arduinoMockInstance();
ArduinoMock* arduinoMockInstance(ArduinoMock*& mock);
void releaseArduinoMock();
void releaseArduinoMock(bool clean);

#endif // ARDUINO_H
