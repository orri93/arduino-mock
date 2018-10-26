// Header for Wifi Mock

#ifndef __Wifi_h__
#define __Wifi_h__

#include <gmock/gmock.h>
#include <stdint.h>

enum wl_status_t {
  WL_NO_SHIELD = 255,   // for compatibility with WiFi Shield library
  WL_IDLE_STATUS = 0,
  WL_NO_SSID_AVAIL = 1,
  WL_SCAN_COMPLETED = 2,
  WL_CONNECTED = 3,
  WL_CONNECT_FAILED = 4,
  WL_CONNECTION_LOST = 5,
  WL_DISCONNECTED = 6
};

class WiFi_ {
  public:
    wl_status_t begin(const char* ssid, const char *passphrase);
    wl_status_t status();
    void on();  // turns on WiFi module
    void off();  // turns off WiFi module
    void connect();  // Attempts to connect to the WiFi network
    void disconnect(); // Disconnect from the Wifi network
    bool connecting(); // Return true once the Core is attempting to connect
    bool ready();  // Return true once Core is connected
    void listen();  // Enter listening mode
    bool listening();  // Return true once listen() has been called
    void setCredentials(); // Allows user to set credentials
    bool clearCredentials(); // Clear all saved credentials
    bool hasCredentials();  // Return true if credentials have been already stored in CC3000's memory
    uint8_t macAddress(); // Return Mac Address of the device
    char* SSID();  // return SSID of the network
    int RSSI();  // return signal strength
    void ping(char*); // ping an IP address
    void ping(char*,
              uint8_t); // ping an IP address with a specified number of times
    char* localIP();  // Return local IP address
    char* subnetMask(); // Return Subnet mask of the network
    char* gatewayIP();  // Return the gateway IP address
};
extern WiFi_ WiFi;

class WiFiMock {
  public:

    virtual MOCK_METHOD2(begin, wl_status_t(const char* ssid, const char *passphrase));
    virtual MOCK_METHOD0(status, wl_status_t());
    virtual MOCK_METHOD0(on, void());
    virtual MOCK_METHOD0(off, void());
    virtual MOCK_METHOD0(connect, void());
    virtual MOCK_METHOD0(disconnect, void());
    virtual MOCK_METHOD0(connecting, bool());
    virtual MOCK_METHOD0(ready, bool());
    virtual MOCK_METHOD0(listen, void());
    virtual MOCK_METHOD0(listening, bool());
    virtual MOCK_METHOD0(setCredentials, void());
    virtual MOCK_METHOD0(clearCredentials, bool());
    virtual MOCK_METHOD0(hasCredentials, bool());
    virtual MOCK_METHOD0(macAddress, uint8_t());
    virtual MOCK_METHOD0(SSID, char * ());
    virtual MOCK_METHOD0(RSSI, int());
    virtual MOCK_METHOD1(ping, void(char*));
    virtual MOCK_METHOD2(ping, void(char*, uint8_t));
    virtual MOCK_METHOD0(localIP, char * ());
    virtual MOCK_METHOD0(subnetMask, char * ());
    virtual MOCK_METHOD0(gatewayIP, char * ());
};

WiFiMock* WiFiMockInstance();
WiFiMock* WiFiMockInstance(WiFiMock*& mock);
void releaseWiFiMock();
void releaseWiFiMock(bool clean);

#endif
