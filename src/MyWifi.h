#pragma once
#include <Arduino.h>

class MyWifi {
public:
  void verbind(const char* ssid, const char* wachtwoord);
  bool isVerbonden();
};