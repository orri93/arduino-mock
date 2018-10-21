#include "arduino-mock/WiFi.h"

static WiFiMock* p_WiFiMock = NULL;

WiFiMock* WiFiMockInstance() {
  if (!p_WiFiMock) {
    p_WiFiMock = new WiFiMock();
  }
  return p_WiFiMock;
}

WiFiMock* WiFiMockInstance(WiFiMock*& mock) {
  if (mock) {
    p_WiFiMock = mock;
  }
  return p_WiFiMock;
}

void releaseWiFiMock() {
  if (p_WiFiMock) {
    delete p_WiFiMock;
    p_WiFiMock = NULL;
  }
}

void releaseWiFiMock(bool clean) {
  if (p_WiFiMock) {
    if (clean)
      delete p_WiFiMock;
    p_WiFiMock = NULL;
  }
}

wl_status_t begin(const char* ssid, const char *passphrase) {
  return p_WiFiMock->begin(ssid, passphrase);
}

uint8_t status() {
  return p_WiFiMock->status();
}

void WiFi_::on() {
  p_WiFiMock->on();
}

void WiFi_::off() {
  p_WiFiMock->off();
}

void WiFi_::connect() {
  p_WiFiMock->connect();
}

void WiFi_::disconnect() {
  p_WiFiMock->disconnect();
}

bool WiFi_::connecting() {
  return p_WiFiMock->connecting();
}

bool WiFi_::ready() {
  return p_WiFiMock->ready();
}

void WiFi_::listen() {
  p_WiFiMock->listen();
}

bool WiFi_::listening() {
  return p_WiFiMock->listening();
}

void WiFi_::setCredentials() {
  p_WiFiMock->setCredentials();
}

bool WiFi_::clearCredentials() {
  return p_WiFiMock->clearCredentials();
}

bool WiFi_::hasCredentials() {
  return p_WiFiMock->hasCredentials();
}

uint8_t WiFi_::macAddress() {
  return p_WiFiMock->macAddress();
}

char* WiFi_::SSID() {
  return p_WiFiMock->SSID();
}

int WiFi_::RSSI() {
  return p_WiFiMock->RSSI();
}

void WiFi_::ping(char* a) {
  p_WiFiMock->ping(a);
}

void WiFi_::ping(char* a, uint8_t b) {
  p_WiFiMock->ping(a, b);
}

char* WiFi_::localIP() {
  return p_WiFiMock->localIP();
}

char* WiFi_::subnetMask() {
  return p_WiFiMock->subnetMask();
}

char* WiFi_::gatewayIP() {
  return p_WiFiMock->gatewayIP();
}

// Preinstantiate Objects
WiFi_ WiFi;
