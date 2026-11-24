// MijnWifi.cpp
#include "MyWifi.h"
#include <WiFi.h>

void MyWifi::verbind(const char* ssid, const char* wachtwoord) {
  WiFi.begin(ssid, wachtwoord);
}

bool MyWifi::isVerbonden() {
  return WiFi.status() == WL_CONNECTED;
}
